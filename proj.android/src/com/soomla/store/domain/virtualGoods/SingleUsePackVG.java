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
import com.soomla.store.data.JSONConsts;
import com.soomla.store.data.StorageManager;
import com.soomla.store.data.StoreInfo;
import com.soomla.store.exceptions.VirtualItemNotFoundException;
import com.soomla.store.purchaseTypes.PurchaseType;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.Iterator;

/**
 * SingleUsePacks are just bundles of SingleUse virtual goods.
 * This kind of virtual good can be used to let your users buy more than one SingleUseVG at once.
 *
 * The SingleUsePackVG's characteristics are:
 *  1. Can be purchased unlimited number of times.
 *  2. Doesn't Have a balance in the database. The SingleUseVG there's associated with this pack has its own balance. When
 *      your users buy a SingleUsePackVG, the balance of the associated SingleUseVG goes up in the amount that this pack
 *      represents (mGoodAmount).
 *
 *  - Usage Examples: 'Box Of Chocolates', '10 Swords'
 *
 * This VirtualItem is purchasable.
 * In case you purchase this item in Google Play (PurchaseWithMarket), You need to define the google item in Google
 * Play Developer Console. (https://play.google.com/apps/publish)
 */
public class SingleUsePackVG extends VirtualGood {

    /** Constructor
     *
     * @param goodItemId is the itemId of the SingleUseVG associated with this pack.
     * @param amount is the number of SingleUseVGs in the pack.
     * @param name see parent
     * @param description see parent
     * @param itemId see parent
     * @param purchaseType see parent
     */
    public SingleUsePackVG(String goodItemId, int amount,
                           String name, String description,
                           String itemId, PurchaseType purchaseType) {
        super(name, description, itemId, purchaseType);

        mGoodItemId = goodItemId;
        mGoodAmount = amount;
    }

    /** Constructor
     *
     * see parent
     */
    public SingleUsePackVG(JSONObject jsonObject) throws JSONException {
        super(jsonObject);

        mGoodItemId = jsonObject.getString(JSONConsts.VGP_GOOD_ITEMID);
        mGoodAmount = jsonObject.getInt(JSONConsts.VGP_GOOD_AMOUNT);
    }

    /**
     * see parent
     */
    @Override
    public JSONObject toJSONObject() {
        JSONObject parentJsonObject = super.toJSONObject();
        JSONObject jsonObject = new JSONObject();
        try {
            Iterator<?> keys = parentJsonObject.keys();
            while(keys.hasNext())
            {
                String key = (String)keys.next();
                jsonObject.put(key, parentJsonObject.get(key));
            }

            jsonObject.put(JSONConsts.VGP_GOOD_ITEMID, mGoodItemId);
            jsonObject.put(JSONConsts.VGP_GOOD_AMOUNT, mGoodAmount);
        } catch (JSONException e) {
            StoreUtils.LogError(TAG, "An error occurred while generating JSON object.");
        }

        return jsonObject;
    }

    /**
     * see parent
     * @param amount the amount of the specific item to be given.
     * @return balance after the giving process
     */
    @Override
    public int give(int amount, boolean notify) {
        SingleUseVG good = null;
        try {
            good = (SingleUseVG)StoreInfo.getVirtualItem(mGoodItemId);
        } catch (VirtualItemNotFoundException e) {
            StoreUtils.LogError(TAG, "SingleUseVG with itemId: " + mGoodItemId + " doesn't exist! Can't give this pack.");
            return 0;
        }
        return StorageManager.getVirtualGoodsStorage().add(good, mGoodAmount*amount, notify);
    }

    /**
     * see parent
     * @param amount the amount of the specific item to be taken.
     * @return balance after the taking process
     */
    @Override
    public int take(int amount, boolean notify) {
        SingleUseVG good = null;
        try {
            good = (SingleUseVG)StoreInfo.getVirtualItem(mGoodItemId);
        } catch (VirtualItemNotFoundException e) {
            StoreUtils.LogError(TAG, "SingleUseVG with itemId: " + mGoodItemId + " doesn't exist! Can't take this pack.");
            return 0;
        }
        return StorageManager.getVirtualGoodsStorage().remove(good, mGoodAmount*amount, notify);
    }

    /**
     * see parent
     */
    @Override
    protected boolean canBuy() {
        return true;
    }

    public String getGoodItemId() {
        return mGoodItemId;
    }

    public int getGoodAmount() {
        return mGoodAmount;
    }

    private static final String TAG = "SOOMLA SingleUsePackVG";

    private String      mGoodItemId;
    private int         mGoodAmount;
}
