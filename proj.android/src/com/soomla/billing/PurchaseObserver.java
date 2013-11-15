/*
 * Partially Copyright (C) 2012 Soomla, Inc.
 *
 * This code was originally written by Google Inc. as a part of the in-app purchases sample.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.soomla.billing;

import android.app.Activity;
import android.app.PendingIntent;
import android.app.PendingIntent.CanceledException;
import android.content.Intent;
import android.content.IntentSender;
import android.os.Handler;
import android.os.Looper;
import com.soomla.billing.BillingService.RequestPurchase;
import com.soomla.billing.BillingService.RestoreTransactions;
import com.soomla.billing.Consts.PurchaseState;
import com.soomla.billing.Consts.ResponseCode;
import com.soomla.store.StoreUtils;

import java.lang.reflect.Method;

/**
 * An interface for observing changes related to purchases. {@link com.soomla.store.StoreController}
 * extends this class and registers an instance of that derived class with
 * {@link ResponseHandler}.
 *
 * Soomla implements this class in order to make UI changes according to the various purchase events.
 *
 */
public abstract class PurchaseObserver {

    /**
     * This is the callback that is invoked when Android Market responds to the
     * {@link BillingService#checkBillingSupported(String)} request.
     * @param supported true if in-app billing is supported.
     */
    public abstract void onBillingSupported(boolean supported, String type);

    /**
     * This is the callback that is invoked when an item is purchased,
     * refunded, or canceled.  It is the callback invoked in response to
     * calling {@link BillingService#requestPurchase(String, String, String)}. It may also
     * be invoked asynchronously when a purchase is made on another device
     * (if the purchase was for a Market-managed item), or if the purchase
     * was refunded, or the charge was canceled. This handles the UI
     * update.
     * @param purchaseState the purchase state of the item
     * @param productId a string identifying the item (the "SKU")
     * @param purchaseTime the time the product was purchased, in
     * milliseconds since the epoch (Jan 1, 1970)
     */
    public abstract void onPurchaseStateChange(PurchaseState purchaseState,
            String productId, long purchaseTime, String developerPayload);

    /**
     * This is called when we receive a response code from Market for a
     * RequestPurchase request that we made.  This is NOT used for any
     * purchase state changes.  All purchase state changes are received in
     * {@link #onPurchaseStateChange(Consts.PurchaseState, String, long, String)}.
     * This is used for reporting various errors, or if the user backed out
     * and didn't purchase the item. The possible response codes are:
     *   RESULT_OK means that the order was sent successfully to the server.
     *       The onPurchaseStateChange() will be invoked later (with a
     *       purchase state of PURCHASED or CANCELED) when the order is
     *       charged or canceled.  This response code can also happen if an
     *       order for a Market-managed item was already sent to the server.
     *   RESULT_USER_CANCELED means that the user didn't buy the item.
     *   RESULT_SERVICE_UNAVAILABLE means that we couldn't connect to the
     *       Android Market server (for example if the data connection is down).
     *   RESULT_BILLING_UNAVAILABLE means that in-app billing is not
     *       supported yet.
     *   RESULT_ITEM_UNAVAILABLE means that the item this app offered for
     *       sale does not exist (or is not published) in the server-side
     *       catalog.
     *   RESULT_ERROR is used for any other errors (such as a server error).
     */
    public abstract void onRequestPurchaseResponse(RequestPurchase request,
            ResponseCode responseCode);

    /**
     * This is called when we receive a response code from Android Market for a
     * RestoreTransactions request that we made.  A response code of
     * RESULT_OK means that the request was successfully sent to the server.
     */
    public abstract void onRestoreTransactionsResponse(RestoreTransactions request,
            ResponseCode responseCode);



    /** -----------------------    PURCHASE INTENT FUNCTIONS    --------------------------- **/

    public void startBuyPageActivity(PendingIntent pendingIntent, Intent intent) {
        if (mStartIntentSender != null) {
            // This is on Android 2.0 and beyond.  The in-app buy page activity
            // must be on the activity stack of the application.
            try {
                // This implements the method call:
                // mActivity.startIntentSender(pendingIntent.getIntentSender(),
                //     intent, 0, 0, 0);
                mStartIntentSenderArgs[0] = pendingIntent.getIntentSender();
                mStartIntentSenderArgs[1] = intent;
                mStartIntentSenderArgs[2] = Integer.valueOf(0);
                mStartIntentSenderArgs[3] = Integer.valueOf(0);
                mStartIntentSenderArgs[4] = Integer.valueOf(0);
                mStartIntentSender.invoke(mActivity, mStartIntentSenderArgs);
            } catch (Exception e) {
                StoreUtils.LogError(TAG, "error starting activity" + e.getMessage());
            }
        } else {
            // This is on Android version 1.6. The in-app buy page activity must be on its
            // own separate activity stack instead of on the activity stack of
            // the application.
            try {
                StoreUtils.LogDebug(TAG, "333"); //
                pendingIntent.send(mActivity, 0 /* code */, intent);
            } catch (CanceledException e) {
                StoreUtils.LogError(TAG, "error starting activity" + e.getMessage());
            } catch (Exception e) {
                StoreUtils.LogError(TAG, "error starting activity" + e.getMessage());
            }
        }
    }

    /**
     * Updates the UI after the database has been updated.  This method runs
     * in a background thread so it has to post a Runnable to run on the UI
     * thread.
     * @param purchaseState the purchase state of the item
     * @param itemId a string identifying the item
     */
    public void postPurchaseStateChange(final PurchaseState purchaseState, final String itemId,
                                 final long purchaseTime, final String developerPayload) {
        if (Looper.myLooper() == Looper.getMainLooper()) {
            onPurchaseStateChange(
                    purchaseState, itemId, purchaseTime, developerPayload);
        } else {
            mMainThread.post(new Runnable() {
                @Override
                public void run() {
                    onPurchaseStateChange(
                            purchaseState, itemId, purchaseTime, developerPayload);
                }
            });
        }
    }

    /** Private functions **/

    private static final Class[] START_INTENT_SENDER_SIG = new Class[] {
            IntentSender.class, Intent.class, int.class, int.class, int.class
    };

    /** -------------------------------------------------- **/

    /** Protected Functions **/

    protected void initCompatibilityLayer(Activity activity){
        mActivity = activity;
        try {
            mStartIntentSender = mActivity.getClass().getMethod("startIntentSender",
                    START_INTENT_SENDER_SIG);
        } catch (SecurityException e) {
            mStartIntentSender = null;
        } catch (NoSuchMethodException e) {
            mStartIntentSender = null;
        }
    }


    /** Private members **/

    private static final String TAG = "SOOMLA PurchaseObserver";
    private Activity mActivity;
    private final Handler mMainThread = new Handler(Looper.getMainLooper());
    private Method mStartIntentSender;
    private Object[] mStartIntentSenderArgs = new Object[5];
}
