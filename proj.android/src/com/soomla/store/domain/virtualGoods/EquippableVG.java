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
import com.soomla.store.domain.VirtualCategory;
import com.soomla.store.exceptions.NotEnoughGoodsException;
import com.soomla.store.exceptions.VirtualItemNotFoundException;
import com.soomla.store.purchaseTypes.PurchaseType;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.EnumSet;
import java.util.Iterator;

/**
 * An Equippable virtual good is a special type of Lifetime Virtual good.
 * In addition to the fact that this virtual good can be purchased once, it can be equipped by your users.
 * - Equipping means that the user decides to currently use a specific virtual good.
 *
 * The EquippableVG's characteristics are:
 *  1. Can be purchased only once.
 *  2. Can be equipped by the user.
 *  3. Inherits the definition of LifetimeVG.
 *
 * There are 3 ways to equip an EquippableVG:
 *  1. LOCAL    - The current EquippableVG's equipping status doesn't affect any other EquippableVG.
 *  2. CATEGORY - In the containing category, if this EquippableVG is equipped, all other EquippableVGs are unequipped.
 *  3. GLOBAL   - In the whole game, if this EquippableVG is equipped, all other EquippableVGs are unequipped.
 *
 * - Example Usage: different characters (play with a specific character),
 *                  'binoculars' (users might only want to take them at night)
 *
 * This VirtualItem is purchasable.
 * In case you purchase this item in Google Play (PurchaseWithMarket), You need to define the google item in Google
 * Play Developer Console. (https://play.google.com/apps/publish)
 */
public class EquippableVG extends LifetimeVG{

    /** Constructor
     *
     * @param equippingModel is the way this EquippableVG is equipped.
     * @param mName see parent
     * @param mDescription see parent
     * @param mItemId see parent
     * @param purchaseType see parent
     */
    public EquippableVG(EquippingModel equippingModel,
                        String mName, String mDescription,
                        String mItemId,
                        PurchaseType purchaseType) {
        super(mName, mDescription, mItemId, purchaseType);

        mEquippingModel = equippingModel;
    }

    /**
     *
     * see parent
     */
    public EquippableVG(JSONObject jsonObject) throws JSONException {
        super(jsonObject);

        String equipping = jsonObject.getString(JSONConsts.EQUIPPABLE_EQUIPPING);
        if (equipping.equals(EquippingModel.LOCAL.toString())) {
            mEquippingModel = EquippingModel.LOCAL;
        } else if (equipping.equals(EquippingModel.CATEGORY.toString())) {
            mEquippingModel = EquippingModel.CATEGORY;
        } else if (equipping.equals(EquippingModel.GLOBAL.toString())) {
            mEquippingModel = EquippingModel.GLOBAL;
        }
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

            jsonObject.put(JSONConsts.EQUIPPABLE_EQUIPPING, mEquippingModel.toString());
        } catch (JSONException e) {
            StoreUtils.LogError(TAG, "An error occurred while generating JSON object.");
        }

        return jsonObject;
    }

    /**
     * This function equips the current EquippableVG
     * @throws NotEnoughGoodsException
     */
    public void equip() throws NotEnoughGoodsException {
        equip(true);
    }
    public void equip(boolean notify) throws NotEnoughGoodsException {
        // only if the user has bought this EquippableVG, the EquippableVG is equipped.
        if (StorageManager.getVirtualGoodsStorage().getBalance(this) > 0){

            if (mEquippingModel == EquippingModel.CATEGORY) {
                VirtualCategory category = null;
                try {
                    category = StoreInfo.getCategory(getItemId());
                } catch (VirtualItemNotFoundException e) {
                    StoreUtils.LogError(TAG, "Tried to unequip all other category VirtualGoods but there was no " +
                            "associated category. virtual good itemId: " + getItemId());
                    return;
                }

                for(String goodItemId : category.getGoodsItemIds()) {
                    EquippableVG equippableVG = null;
                    try {
                        equippableVG = (EquippableVG) StoreInfo.getVirtualItem(goodItemId);

                        if (equippableVG != null && equippableVG != this) {
                            equippableVG.unequip(notify);
                        }
                    } catch (VirtualItemNotFoundException e) {
                        StoreUtils.LogError(TAG, "On equip, couldn't find one of the itemIds in the category. Continuing to the next one. itemId: " + goodItemId);
                    } catch (ClassCastException ex) {
                        StoreUtils.LogDebug(TAG, "On equip, an error occurred. It's a debug message b/c the VirtualGood may just not be an EquippableVG. itemId: " + goodItemId);
                    }
                }
            } else if (mEquippingModel == EquippingModel.GLOBAL) {
                for(VirtualGood good : StoreInfo.getGoods()) {
                    if (good != this &&
                        good instanceof EquippableVG) {
                        ((EquippableVG)good).unequip(notify);
                    }
                }
            }

            StorageManager.getVirtualGoodsStorage().equip(this, notify);
        }
        else {
            throw new NotEnoughGoodsException(getItemId());
        }
    }

    /**
     * This function unequips the current EquippableVG
     */
    public void unequip() {
        unequip(true);
    }
    public void unequip(boolean notify) {
        StorageManager.getVirtualGoodsStorage().unequip(this, notify);
    }

    /**
     * EquippingModel is the way EquippableVG is equipped.
     * LOCAL    - The current EquippableVG's equipping status doesn't affect any other EquippableVG.
     * CATEGORY - In the containing category, if this EquippableVG is equipped, all other EquippableVGs are unequipped.
     * GLOBAL   - In the whole game, if this EquippableVG is equipped, all other EquippableVGs are unequipped.
     */
    public static enum EquippingModel {
        LOCAL("local"), CATEGORY("category"), GLOBAL("global");

        private EquippingModel(final String em) {
            this.mEm = em;
        }

        private final String mEm;

        public String toString() {
            return mEm;
        }

        public static EquippingModel fromString(String em) {
            for (final EquippingModel element : EnumSet.allOf(EquippingModel.class)) {
                if (element.toString().equals(em)) {
                    return element;
                }
            }
            return null;
        }
    }

    public EquippingModel getEquippingModel() {
        return mEquippingModel;
    }

    private static final String TAG = "SOOMLA EquippableVG";

    private EquippingModel mEquippingModel;
}
