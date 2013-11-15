/*
 * Copyright (C) 2012 Soomla Inc.
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
package com.soomla.store.domain;

import com.soomla.store.StoreUtils;
import com.soomla.store.data.JSONConsts;
import org.json.JSONException;
import org.json.JSONObject;

/**
 * This class represents an item in Google Play.
 * Every PurchasableVirtualItem with PurchaseType of PurchaseWithMarket has an instance of this class which is a
 * representation of the same currency pack as an item on Google Play.
 */
public class GoogleMarketItem {

    /** Constructor
     *
     * @param mProductId is the Id of the current item in Google Play.
     * @param mManaged is the Managed type of the current item in Google Play.
     * @param mPrice is the actual $$ cost of the current item in Google Play.
     */
    public GoogleMarketItem(String mProductId, Managed mManaged, double mPrice) {
        this.mProductId = mProductId;
        this.mManaged = mManaged;
        this.mPrice = mPrice;
    }

    /** Constructor
     *
     * Generates an instance of {@link GoogleMarketItem} from a JSONObject.
     * @param jsonObject is a JSONObject representation of the wanted {@link GoogleMarketItem}.
     * @throws JSONException
     */
    public GoogleMarketItem(JSONObject jsonObject) throws JSONException {
        if (jsonObject.has(JSONConsts.MARKETITEM_MANAGED)) {
            this.mManaged = Managed.values()[jsonObject.getInt(JSONConsts.MARKETITEM_MANAGED)];
        } else {
            this.mManaged = Managed.UNMANAGED;
        }
        if (jsonObject.has(JSONConsts.MARKETITEM_ANDROID_ID)) {
            this.mProductId = jsonObject.getString(JSONConsts.MARKETITEM_ANDROID_ID);
        } else {
            this.mProductId = jsonObject.getString(JSONConsts.MARKETITEM_PRODUCT_ID);
        }
        this.mPrice = jsonObject.getDouble(JSONConsts.MARKETITEM_PRICE);
    }

    public JSONObject toJSONObject(){
        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(JSONConsts.MARKETITEM_MANAGED, mManaged.ordinal());
            jsonObject.put(JSONConsts.MARKETITEM_ANDROID_ID, mProductId);
            jsonObject.put(JSONConsts.MARKETITEM_PRICE, new Double(mPrice));
        } catch (JSONException e) {
            StoreUtils.LogError(TAG, "An error occured while generating JSON object.");
        }

        return jsonObject;
    }

    /** Getters **/

    public String getProductId() {
        return mProductId;
    }

    public Managed getManaged() {
        return mManaged;
    }

    public void setManaged(Managed managed) {
        this.mManaged = managed;
    }

    public double getPrice() {
        return mPrice;
    }

    /** Private members **/

    /**
     * Each product in the catalog can be MANAGED, UNMANAGED, or SUBSCRIPTION.  MANAGED
     * means that the product can be purchased only once per user (such as a new
     * level in a game). The purchase is remembered by Android Market and
     * can be restored if this application is uninstalled and then
     * re-installed. UNMANAGED is used for products that can be used up and
     * purchased multiple times (such as poker chips). It is up to the
     * application to keep track of UNMANAGED products for the user.
     * SUBSCRIPTION is just like MANAGED except that the user gets charged monthly
     * or yearly.
     */
    public static enum Managed { MANAGED, UNMANAGED, SUBSCRIPTION }

    private Managed mManaged;
    /**
     *  The Id of this VirtualGood in Google Market
    */

    private static final String TAG = "SOOMLA GoogleMarketItem";

    private String mProductId;
    private double mPrice;
}
