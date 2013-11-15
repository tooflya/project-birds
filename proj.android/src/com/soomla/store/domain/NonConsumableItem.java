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
import com.soomla.store.data.StorageManager;
import com.soomla.store.purchaseTypes.PurchaseWithMarket;
import org.json.JSONException;
import org.json.JSONObject;

/**
 * A representation of a non-consumable item in Google Play. These kinds of items are bought by the user once and kept for him forever.
 * 
 * Don't get confused... this is not a Lifetime VirtualGood. It's just a MANAGED item in Google Play.
 * This item will be retrieved when you "restoreTransactions"
 */
public class NonConsumableItem extends PurchasableVirtualItem {

    /** Constructor
     *
     * @param mName see parent
     * @param mDescription see parent
     * @param mItemId see parent
     * @param purchaseType see parent
     */
    public NonConsumableItem(String mName, String mDescription, String mItemId, PurchaseWithMarket purchaseType) {
        super(mName, mDescription, mItemId, purchaseType);
    }

    /** Constructor
     *
     * see parent
     */
    public NonConsumableItem(JSONObject jsonObject) throws JSONException {
        super(jsonObject);
    }

    /**
     * see parent
     */
    @Override
    public JSONObject toJSONObject(){
        return super.toJSONObject();
    }

    /**
     * see parent
     * @param amount the amount of the specific item to be given.
     * @return balance after the giving process, can be either 0 or 1
     */
    @Override
    public int give(int amount, boolean notify) {
        return StorageManager.getNonConsumableItemsStorage().add(this) ? 1 : 0;
    }

    /**
     * see parent
     * @param amount the amount of the specific item to be taken.
     * @return balance after the taking process, can be either 0 or 1
     */
    @Override
    public int take(int amount, boolean notify) {
        return StorageManager.getNonConsumableItemsStorage().remove(this) ? 1 : 0;
    }

    /**
     * see parent
     */
    @Override
    protected boolean canBuy() {
        if (StorageManager.getNonConsumableItemsStorage().nonConsumableItemExists(this)) {
            StoreUtils.LogDebug(TAG, "You can't buy a NonConsumableItem that was already given to the user.");
            return false;
        }
        return true;
    }

    /**
     * see parent
     * @param balance see parent
     * @return balance after the resetting process, can be either 0 or 1
     */
    @Override
    public int resetBalance(int balance, boolean notify) {
        if (balance > 0) {
            return StorageManager.getNonConsumableItemsStorage().add(this) ? 1 : 0;
        } else {
            return StorageManager.getNonConsumableItemsStorage().remove(this) ? 1 : 0;
        }
    }

    /** Private members **/

    private static final String TAG = "SOOMLA NonConsumableItem";
}
