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

import com.soomla.store.data.StorageManager;
import com.soomla.store.purchaseTypes.PurchaseType;
import org.json.JSONException;
import org.json.JSONObject;

/**
 * SingleUse virtual goods are the most common type of VirtualGood.
 *
 * The SingleUseVG's characteristics are:
 *  1. Can be purchased unlimited number of times.
 *  2. Has a balance and saved in the database. Its balance goes up when you "give" it or "buy" it. The balance goes
 *      down when it's taken or refunded (in case of an unfriendly refund).
 *
 * - Usage Examples: 'Hat', 'Sword'
 *
 * This VirtualItem is purchasable.
 * In case you purchase this item in Google Play (PurchaseWithMarket), You need to define the google item in Google
 * Play Developer Console. (https://play.google.com/apps/publish)
 */
public class SingleUseVG extends VirtualGood{

    /** Constructor
     *
     * @param mName see parent
     * @param mDescription see parent
     * @param mItemId see parent
     * @param purchaseType see parent
     */
    public SingleUseVG(String mName, String mDescription, String mItemId, PurchaseType purchaseType) {
        super(mName, mDescription, mItemId, purchaseType);
    }

    /** Constructor
     *
     * see parent
     */
    public SingleUseVG(JSONObject jsonObject) throws JSONException {
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
     * @return balance after the giving process
     */
    @Override
    public int give(int amount, boolean notify) {
        return StorageManager.getVirtualGoodsStorage().add(this, amount, notify);
    }

    /**
     * see parent
     * @param amount the amount of the specific item to be taken.
     * @return balance after the taking process
     */
    @Override
    public int take(int amount, boolean notify) {
        return StorageManager.getVirtualGoodsStorage().remove(this, amount, notify);
    }

    /**
     * see parent
     */
    @Override
    protected boolean canBuy() {
        return true;
    }
}
