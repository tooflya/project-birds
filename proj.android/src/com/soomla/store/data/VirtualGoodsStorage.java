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
package com.soomla.store.data;

import com.soomla.billing.util.AESObfuscator;
import com.soomla.store.BusProvider;
import com.soomla.store.StoreUtils;
import com.soomla.store.domain.VirtualItem;
import com.soomla.store.domain.virtualGoods.EquippableVG;
import com.soomla.store.domain.virtualGoods.UpgradeVG;
import com.soomla.store.domain.virtualGoods.VirtualGood;
import com.soomla.store.events.GoodBalanceChangedEvent;
import com.soomla.store.events.GoodEquippedEvent;
import com.soomla.store.events.GoodUnEquippedEvent;
import com.soomla.store.events.GoodUpgradeEvent;
import com.soomla.store.exceptions.VirtualItemNotFoundException;

/**
 * This class provide basic storage operations on VirtualGoods.
 */
public class VirtualGoodsStorage extends VirtualItemStorage{

    /** Constructor
     *
     */
    public VirtualGoodsStorage() {
        mTag = "SOOMLA VirtualGoodsStorage";
    }


    /** Public functions **/

    /**
     * This function removes any upgrade associated with the given VirtualGood.
     * @param good the VirtualGood to remove upgrade from.
     */
    public void removeUpgrades(VirtualGood good) {
        removeUpgrades(good, true);
    }

    public void removeUpgrades(VirtualGood good, boolean notify) {
        StoreUtils.LogDebug(mTag, "Removing upgrade information from virtual good: " + good.getName());

        String itemId = good.getItemId();
        String key = KeyValDatabase.keyGoodUpgrade(itemId);
        key = StorageManager.getAESObfuscator().obfuscateString(key);

        StorageManager.getDatabase().deleteKeyVal(key);

        if (notify) {
            BusProvider.getInstance().post(new GoodUpgradeEvent(good, null));
        }
    }

    /**
     * Assigns a specific upgrade to the given VirtualGood.
     * @param good the VirtualGood to upgrade.
     * @param upgradeVG the upgrade to assign.
     */
    public void assignCurrentUpgrade(VirtualGood good, UpgradeVG upgradeVG) {
        assignCurrentUpgrade(good, upgradeVG, true);
    }
    public void assignCurrentUpgrade(VirtualGood good, UpgradeVG upgradeVG, boolean notify) {
        if (getCurrentUpgrade(good) != null && getCurrentUpgrade(good).getItemId().equals(upgradeVG.getItemId())) {
            return;
        }

        StoreUtils.LogDebug(mTag, "Assigning upgrade " + upgradeVG.getName() + " to virtual good: " + good.getName());

        String itemId = good.getItemId();
        String key = KeyValDatabase.keyGoodUpgrade(itemId);
        key = StorageManager.getAESObfuscator().obfuscateString(key);

        String upItemId =  StorageManager.getAESObfuscator().obfuscateString(upgradeVG.getItemId());
        StorageManager.getDatabase().setKeyVal(key, upItemId);

        if (notify) {
            BusProvider.getInstance().post(new GoodUpgradeEvent(good, upgradeVG));
        }
    }



    /**
     * Retrieves the current upgrade for the given VirtualGood.
     * @param good the VirtualGood to retrieve upgrade for.
     * @return the current upgrade for the given VirtualGood.
     */
    public UpgradeVG getCurrentUpgrade(VirtualGood good) {
        StoreUtils.LogDebug(mTag, "Fetching upgrade to virtual good: " + good.getName());

        String itemId = good.getItemId();
        String key = KeyValDatabase.keyGoodUpgrade(itemId);
        key = StorageManager.getAESObfuscator().obfuscateString(key);

        String upItemId = StorageManager.getDatabase().getKeyVal(key);

        if (upItemId == null) {
            StoreUtils.LogDebug(mTag, "You tried to fetch the current upgrade of " + good.getName() + " but there's not upgrade to it.");
            return null;
        }

        try {
            upItemId = StorageManager.getAESObfuscator().unobfuscateToString(upItemId);
            return (UpgradeVG) StoreInfo.getVirtualItem(upItemId);
        } catch (AESObfuscator.ValidationException e) {
            StoreUtils.LogError(mTag, e.getMessage());
        } catch (VirtualItemNotFoundException e) {
            StoreUtils.LogError(mTag, "The current upgrade's itemId from the DB is not found in StoreInfo.");
        } catch (ClassCastException e) {
            StoreUtils.LogError(mTag, "The current upgrade's itemId from the DB is not an UpgradeVG.");
        }

        return null;
    }

    /**
     * Check the equipping status of the given EquippableVG.
     * @param good the EquippableVG to check the status for.
     * @return the equipping status of the given EquippableVG.
     */
    public boolean isEquipped(EquippableVG good){
        StoreUtils.LogDebug(mTag, "checking if virtual good with itemId: " + good.getItemId() + " is equipped.");

        String itemId = good.getItemId();
        String key = KeyValDatabase.keyGoodEquipped(itemId);
        key = StorageManager.getAESObfuscator().obfuscateString(key);
        String val = StorageManager.getDatabase().getKeyVal(key);

        return val != null;
    }

    /**
     * Equip the given EquippableVG.
     * @param good the EquippableVG to equip.
     */
    public void equip(EquippableVG good) {
        equip(good, true);
    }
    public void equip(EquippableVG good, boolean notify) {
        if (isEquipped(good)) {
            return;
        }

        equipPriv(good, true, notify);
    }

    /**
     * UnEquip the given EquippableVG.
     * @param good the EquippableVG to unequip.
     */
    public void unequip(EquippableVG good) {
        unequip(good, true);
    }
    public void unequip(EquippableVG good, boolean notify) {
        if (!isEquipped(good)) {
            return;
        }

        equipPriv(good, false, notify);
    }

    private void equipPriv(EquippableVG good, boolean equip, boolean notify){
        StoreUtils.LogDebug(mTag, (!equip ? "unequipping " : "equipping ") + good.getName() + ".");

        String itemId = good.getItemId();
        String key = KeyValDatabase.keyGoodEquipped(itemId);
        key = StorageManager.getAESObfuscator().obfuscateString(key);

        if (equip) {
            StorageManager.getDatabase().setKeyVal(key, "");
            if (notify) {
                BusProvider.getInstance().post(new GoodEquippedEvent(good));
            }
        } else {
            StorageManager.getDatabase().deleteKeyVal(key);
            if (notify) {
                BusProvider.getInstance().post(new GoodUnEquippedEvent(good));
            }
        }
    }

    @Override
    protected String keyBalance(String itemId) {
        return KeyValDatabase.keyGoodBalance(itemId);
    }

    @Override
    protected void postBalanceChangeEvent(VirtualItem item, int balance, int amountAdded) {
        BusProvider.getInstance().post(new GoodBalanceChangedEvent((VirtualGood) item, balance, amountAdded));
    }

}
