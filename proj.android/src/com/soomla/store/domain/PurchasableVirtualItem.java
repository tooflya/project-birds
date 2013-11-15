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
import com.soomla.store.exceptions.InsufficientFundsException;
import com.soomla.store.purchaseTypes.PurchaseType;
import com.soomla.store.purchaseTypes.PurchaseWithMarket;
import com.soomla.store.purchaseTypes.PurchaseWithVirtualItem;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.Iterator;

/**
 * A representation of an VirtualItem you can actually purchase.
 */
public abstract class PurchasableVirtualItem extends VirtualItem {

    /** Constructor
     *
     * @param mName see parent
     * @param mDescription see parent
     * @param mItemId see parent
     * @param purchaseType is the way this item is purchased.
     */
    public PurchasableVirtualItem(String mName, String mDescription, String mItemId, PurchaseType purchaseType) {
        super(mName, mDescription, mItemId);

        mPurchaseType = purchaseType;

        mPurchaseType.setAssociatedItem(this);
    }

    /**
     * see parent
     */
    public PurchasableVirtualItem(JSONObject jsonObject) throws JSONException {
        super(jsonObject);

        JSONObject purchasableObj = jsonObject.getJSONObject(JSONConsts.PURCHASABLE_ITEM);
        String purchaseType = purchasableObj.getString(JSONConsts.PURCHASE_TYPE);

        if (purchaseType.equals(JSONConsts.PURCHASE_TYPE_MARKET)) {
            JSONObject marketItemObj = purchasableObj.getJSONObject(JSONConsts.PURCHASE_MARKET_ITEM);

            mPurchaseType = new PurchaseWithMarket(new GoogleMarketItem(marketItemObj));
        } else if (purchaseType.equals(JSONConsts.PURCHASE_TYPE_VI)) {
            String itemId = purchasableObj.getString(JSONConsts.PURCHASE_VI_ITEMID);
            int amount = purchasableObj.getInt(JSONConsts.PURCHASE_VI_AMOUNT);

            mPurchaseType = new PurchaseWithVirtualItem(itemId, amount);
        } else {
            StoreUtils.LogError(TAG, "Purchase type not recognized !");
        }

        if (mPurchaseType != null) {
            mPurchaseType.setAssociatedItem(this);
        }
    }

    /**
     * see parent
     */
    @Override
    public JSONObject toJSONObject(){
        JSONObject parentJsonObject = super.toJSONObject();
        JSONObject jsonObject = new JSONObject();
        try {
            Iterator<?> keys = parentJsonObject.keys();
            while(keys.hasNext())
            {
                String key = (String)keys.next();
                jsonObject.put(key, parentJsonObject.get(key));
            }

            JSONObject purchasableObj = new JSONObject();

            if(mPurchaseType instanceof PurchaseWithMarket) {
                purchasableObj.put(JSONConsts.PURCHASE_TYPE, JSONConsts.PURCHASE_TYPE_MARKET);

                GoogleMarketItem  mi = ((PurchaseWithMarket) mPurchaseType).getGoogleMarketItem();
                purchasableObj.put(JSONConsts.PURCHASE_MARKET_ITEM, mi.toJSONObject());
            } else if(mPurchaseType instanceof PurchaseWithVirtualItem) {
                purchasableObj.put(JSONConsts.PURCHASE_TYPE, JSONConsts.PURCHASE_TYPE_VI);

                purchasableObj.put(JSONConsts.PURCHASE_VI_ITEMID, ((PurchaseWithVirtualItem) mPurchaseType).getTargetItemId());
                purchasableObj.put(JSONConsts.PURCHASE_VI_AMOUNT, ((PurchaseWithVirtualItem) mPurchaseType).getAmount());
            }

            jsonObject.put(JSONConsts.PURCHASABLE_ITEM, purchasableObj);
        } catch (JSONException e) {
            StoreUtils.LogError(TAG, "An error occurred while generating JSON object.");
        }

        return jsonObject;
    }

    /**
     * Use this function to buy a Virtual Item. This action uses the associated PurchaseType to perform the purchase.
     *
     * @throws InsufficientFundsException
     */
    public void buy() throws InsufficientFundsException {
        if (!canBuy()) return;

        mPurchaseType.buy();
    }

    public PurchaseType getPurchaseType() {
        return mPurchaseType;
    }

    /**
     * Determines if you are in a state that allows you to buy a specific VirtualItem.
     */
    protected abstract boolean canBuy();

    private static final String TAG = "SOOMLA PurchasableVirtualItem";

    private PurchaseType mPurchaseType;
}
