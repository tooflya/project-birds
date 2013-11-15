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

package com.soomla.store.domain.virtualGoods;

import com.soomla.store.StoreUtils;
import com.soomla.store.data.StorageManager;
import com.soomla.store.purchaseTypes.PurchaseType;
import org.json.JSONException;
import org.json.JSONObject;


/**
 * A Lifetime virtual good is a special time that allows you to offer virtual goods that are bought only once.
 *
 * The LifetimeVG's characteristics are:
 *  1. Can only be purchased once.
 *  2. Your users can't have more than one of this item. In other words, (0 <= [LifetimeVG's balance] <= 1) == true.
 *
 * - Example usage: 'No Ads', 'Double Coins'
 *
 * This VirtualItem is purchasable.
 * In case you purchase this item in Google Play (PurchaseWithMarket), You need to define the google item in Google
 * Play Developer Console. (https://play.google.com/apps/publish)
 */
    public class LifetimeVG extends VirtualGood{

    /** Constructor
     *
     * @param mName see parent
     * @param mDescription see parent
     * @param mItemId see parent
     * @param purchaseType see parent
     */
    public LifetimeVG(String mName, String mDescription,
                      String mItemId,
                      PurchaseType purchaseType) {
        super(mName, mDescription, mItemId, purchaseType);
    }

    /** Constructor
     *
     * see parent
     */
    public LifetimeVG(JSONObject jsonObject) throws JSONException {
        super(jsonObject);
    }

    /**
     * see parent
     */
    @Override
    public JSONObject toJSONObject() {
        return super.toJSONObject();
    }

    /**
     * see parent
     * @param amount the amount of the specific item to be given.
     * @return 1 if the user was given the good, 0 otherwise
     */
    @Override
    public int give(int amount, boolean notify) {
        if(amount > 1) {
            StoreUtils.LogDebug(TAG, "You tried to give more than one LifetimeVG. Will try to give one anyway.");
            amount = 1;
        }

        int balance = StorageManager.getVirtualGoodsStorage().getBalance(this);

        if (balance < 1) {
            return StorageManager.getVirtualGoodsStorage().add(this, amount, notify);
        }
        return 1;
    }

    /**
     * see parent
     * @param amount the amount of the specific item to be taken.
     * @return balance after taking process, should be 0
     */
    @Override
    public int take(int amount, boolean notify) {
        if (amount > 1) {
            amount = 1;
        }

        int balance = StorageManager.getVirtualGoodsStorage().getBalance(this);

        if (balance > 0) {
            return StorageManager.getVirtualGoodsStorage().remove(this, amount, notify);
        }
        return 0;
    }

    /**
     * see parent
     */
    @Override
    protected boolean canBuy() {
        int balance = StorageManager.getVirtualGoodsStorage().getBalance(this);

        return balance < 1;
    }

    private static String TAG = "SOOMLA LifetimeVG";
}
