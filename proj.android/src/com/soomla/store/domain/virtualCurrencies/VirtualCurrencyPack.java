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
package com.soomla.store.domain.virtualCurrencies;

import com.soomla.store.StoreUtils;
import com.soomla.store.data.JSONConsts;
import com.soomla.store.data.StorageManager;
import com.soomla.store.data.StoreInfo;
import com.soomla.store.domain.PurchasableVirtualItem;
import com.soomla.store.exceptions.VirtualItemNotFoundException;
import com.soomla.store.purchaseTypes.PurchaseType;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.Iterator;

/**
 * Every game has its virtualCurrencies. Here you represent a pack of a specific VirtualCurrency.
 * For example: If you have a "Coin" as a virtual currency, you will
 * sell packs of "Coins". e.g. "10 Coins Set" or "Super Saver Pack".
 *
 * This VirtualItem is purchasable.
 * In case you purchase this item in Google Play (PurchaseWithMarket), You need to define the google item in Google
 * Play Developer Console. (https://play.google.com/apps/publish)
 */
public class VirtualCurrencyPack extends PurchasableVirtualItem {

    /** Constructor
     *
     * @param mName see parent
     * @param mDescription see parent
     * @param mItemId see parent
     * @param mCurrencyAmount is the amount of currency in the pack.
     * @param mCurrencyItemId is the itemId of the currency associated with this pack.
     * @param purchaseType see parent
     */
    public VirtualCurrencyPack(String mName, String mDescription, String mItemId,
                               int mCurrencyAmount,
                               String mCurrencyItemId, PurchaseType purchaseType) {
        super(mName, mDescription, mItemId, purchaseType);
        this.mCurrencyItemId = mCurrencyItemId;
        this.mCurrencyAmount = mCurrencyAmount;
    }

    /** Constructor
     *
     * see parent
     */
    public VirtualCurrencyPack(JSONObject jsonObject) throws JSONException {
        super(jsonObject);
        this.mCurrencyAmount = jsonObject.getInt(JSONConsts.CURRENCYPACK_CURRENCYAMOUNT);

        this.mCurrencyItemId = jsonObject.getString(JSONConsts.CURRENCYPACK_CURRENCYITEMID);
    }

    /**
     * see parent
     */
    public JSONObject toJSONObject(){
        JSONObject parentJsonObject = super.toJSONObject();
        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(JSONConsts.CURRENCYPACK_CURRENCYAMOUNT, mCurrencyAmount);
            jsonObject.put(JSONConsts.CURRENCYPACK_CURRENCYITEMID, mCurrencyItemId);

            Iterator<?> keys = parentJsonObject.keys();
            while(keys.hasNext())
            {
                String key = (String)keys.next();
                jsonObject.put(key, parentJsonObject.get(key));
            }

        } catch (JSONException e) {
            StoreUtils.LogError(TAG, "An error occured while generating JSON object.");
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
        VirtualCurrency currency = null;
        try {
            currency = (VirtualCurrency)StoreInfo.getVirtualItem(mCurrencyItemId);
        } catch (VirtualItemNotFoundException e) {
            StoreUtils.LogError(TAG, "VirtualCurrency with itemId: " + mCurrencyItemId + " doesn't exist! Can't give this pack.");
            return 0;
        }
        return StorageManager.getVirtualCurrencyStorage().add(currency, mCurrencyAmount*amount, notify);
    }

    /**
     * see parent
     * @param amount the amount of the specific item to be taken.
     * @return balance after the taking process
     */
    @Override
    public int take(int amount, boolean notify) {
        VirtualCurrency currency = null;
        try {
            currency = (VirtualCurrency)StoreInfo.getVirtualItem(mCurrencyItemId);
        } catch (VirtualItemNotFoundException e) {
            StoreUtils.LogError(TAG, "VirtualCurrency with itemId: " + mCurrencyItemId + " doesn't exist! Can't take this pack.");
            return 0;
        }
        return StorageManager.getVirtualCurrencyStorage().remove(currency, mCurrencyAmount * amount, notify);
    }

    /**
     * see parent
     * @param balance see parent
     */
    @Override
    public int resetBalance(int balance, boolean notify) {
        // Not supported for VirtualCurrencyPacks !
        StoreUtils.LogError(TAG, "Someone tried to reset balance of CurrencyPack. That's not right.");
        return 0;
    }

    /**
     * see parent
     */
    @Override
    protected boolean canBuy() {
        return true;
    }

    /** Getters **/

    public int getCurrencyAmount() {
        return mCurrencyAmount;
    }

    public String getCurrencyItemId() {
        return mCurrencyItemId;
    }

    /** Private members **/

    private static final String TAG = "SOOMLA VirtualCurrencyPack";

    private int              mCurrencyAmount;
    private String           mCurrencyItemId;
}
