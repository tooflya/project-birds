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

import android.text.TextUtils;
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
 * An upgrade virtual good is one VG in a series of VGs that define an upgrade scale of an associated VirtualGood.
 *
 * This type of virtual good is best explained with an example:
 * Lets say you have a strength attribute to your character in the game and that strength is on the scale 1-5.
 * You want to provide your users with the ability to upgrade that strength. This is what you'll need to create:
 *  1. SingleUseVG for 'strength'
 *  2. UpgradeVG for strength 'level 1'
 *  3. UpgradeVG for strength 'level 2'
 *  4. UpgradeVG for strength 'level 3'
 *  5. UpgradeVG for strength 'level 4'
 *  6. UpgradeVG for strength 'level 5'
 *
 * Now, when the user buys this UpgradeVG, we check and make sure the appropriate conditions are met and buy it for you
 * (which actually means we upgrade the associated VirtualGood).
 *
 * This VirtualItem is purchasable.
 * In case you purchase this item in Google Play (PurchaseWithMarket), You need to define the google item in Google
 * Play Developer Console. (https://play.google.com/apps/publish)
 */
public class UpgradeVG extends LifetimeVG {

    /** Constructor
     *
     * @param goodItemId is the itemId of the VirtualGood associated with this upgrade.
     * @param prevItemId is the itemId of the UpgradeVG before or if this is the first UpgradeVG in the scale then the value is null.
     * @param nextItemId is the itemId of the UpgradeVG after or if this is the last UpgradeVG in the scale then the value is null.
     * @param mName see parent
     * @param mDescription see parent
     * @param mItemId see parent
     * @param purchaseType see parent
     */
    public UpgradeVG(String goodItemId,
                     String prevItemId, String nextItemId,
                     String mName, String mDescription,
                     String mItemId,
                     PurchaseType purchaseType) {
        super(mName, mDescription, mItemId, purchaseType);

        mGoodItemId = goodItemId;
        mPrevItemId = prevItemId;
        mNextItemId = nextItemId;
    }

    /** Constructor
     * see parent
     */
    public UpgradeVG(JSONObject jsonObject) throws JSONException {
        super(jsonObject);

        mGoodItemId = jsonObject.getString(JSONConsts.VGU_GOOD_ITEMID);
        mPrevItemId = jsonObject.getString(JSONConsts.VGU_PREV_ITEMID);
        mNextItemId = jsonObject.getString(JSONConsts.VGU_NEXT_ITEMID);
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

            jsonObject.put(JSONConsts.VGU_GOOD_ITEMID, mGoodItemId);
            jsonObject.put(JSONConsts.VGU_PREV_ITEMID, TextUtils.isEmpty(mPrevItemId) ? "" : mPrevItemId);
            jsonObject.put(JSONConsts.VGU_NEXT_ITEMID, TextUtils.isEmpty(mNextItemId) ? "" : mNextItemId);
        } catch (JSONException e) {
            StoreUtils.LogError(TAG, "An error occurred while generating JSON object.");
        }

        return jsonObject;
    }

    /** Getters **/

    public String getGoodItemId() {
        return mGoodItemId;
    }

    public String getPrevItemId() {
        return mPrevItemId;
    }

    public String getNextItemId() {
        return mNextItemId;
    }

    /**
     * Assigning the current upgrade to the associated VirtualGood (mGood).
     *
     * This action doesn't check nothing!! It just assigns the current UpgradeVG to the associated mGood.
     * @param amount is NOT USED HERE !
     * @return 1 if the user was given the good, 0 otherwise
     */
    @Override
    public int give(int amount, boolean notify) {
        StoreUtils.LogDebug(TAG, "Assigning " + getName() + " to: " + mGoodItemId);

        VirtualGood good = null;
        try {
            good = (VirtualGood)StoreInfo.getVirtualItem(mGoodItemId);
        } catch (VirtualItemNotFoundException e) {
            StoreUtils.LogError(TAG, "VirtualGood with itemId: " + mGoodItemId + " doesn't exist! Can't upgrade.");
            return 0;
        }

        StorageManager.getVirtualGoodsStorage().assignCurrentUpgrade(good, this, notify);

        return super.give(amount, notify);
    }

     /**
     * This is actually a downgrade of the associated VirtualGood (mGood).
     * We check if the current Upgrade is really associated with the VirtualGood and:
     *  if YES we downgrade to the previous upgrade (or removing upgrades in case of null).
     *  if NO we return (do nothing).
     *
     * @param amount is NOT USED HERE !
     */
    @Override
    public int take(int amount, boolean notify) {
        VirtualGood good = null;
        try {
            good = (VirtualGood)StoreInfo.getVirtualItem(mGoodItemId);
        } catch (VirtualItemNotFoundException e) {
            StoreUtils.LogError(TAG, "VirtualGood with itemId: " + mGoodItemId + " doesn't exist! Can't downgrade.");
            return 0;
        }

        UpgradeVG upgradeVG = StorageManager.getVirtualGoodsStorage().getCurrentUpgrade(good);
        if (upgradeVG != this) {
            StoreUtils.LogError(TAG, "You can't take an upgrade that's not currently assigned. The UpgradeVG " + getName() + " is not assigned to " +
                    "the VirtualGood: " + good.getName());
            return 0;
        }


        if (!TextUtils.isEmpty(mPrevItemId)) {
            UpgradeVG prevUpgradeVG = null;

            try {
                prevUpgradeVG = (UpgradeVG)StoreInfo.getVirtualItem(mPrevItemId);
            } catch (VirtualItemNotFoundException e) {
                StoreUtils.LogError(TAG, "Previous UpgradeVG with itemId: " + mPrevItemId + " doesn't exist! Can't downgrade.");
                return 0;
            }

            StoreUtils.LogDebug(TAG, "Downgrading " + good.getName() + " to: " + prevUpgradeVG.getName());
            StorageManager.getVirtualGoodsStorage().assignCurrentUpgrade(good, prevUpgradeVG, notify);
        } else {
            StoreUtils.LogDebug(TAG, "Downgrading " + good.getName() + " to NO-UPGRADE");
            StorageManager.getVirtualGoodsStorage().removeUpgrades(good, notify);
        }

        return super.take(amount, notify);
    }

    /**
     * We want to enforce the logic of allowing/rejecting upgrades here so users won't buy when they are not supposed to.
     * If you want to give your users upgrades for free, use the "give" function.
     */
    @Override
    protected boolean canBuy() {
        VirtualGood good = null;
        try {
            good = (VirtualGood)StoreInfo.getVirtualItem(mGoodItemId);
        } catch (VirtualItemNotFoundException e) {
            StoreUtils.LogError(TAG, "VirtualGood with itemId: " + mGoodItemId + " doesn't exist! Returning NO (can't buy).");
            return false;
        }

        UpgradeVG upgradeVG = StorageManager.getVirtualGoodsStorage().getCurrentUpgrade(good);
        return ((upgradeVG == null && TextUtils.isEmpty(mPrevItemId)) ||
               (upgradeVG != null && ((upgradeVG.getNextItemId().equals(getItemId())) || (upgradeVG.getPrevItemId().equals(getItemId())))))
                && super.canBuy();
    }

    private static final String TAG = "SOOMLA UpgradeVG";

    private String   mGoodItemId;
    private String   mPrevItemId;
    private String   mNextItemId;
}
