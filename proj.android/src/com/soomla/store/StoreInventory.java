package com.soomla.store;

import android.text.TextUtils;
import com.soomla.store.data.StorageManager;
import com.soomla.store.data.StoreInfo;
import com.soomla.store.domain.NonConsumableItem;
import com.soomla.store.domain.PurchasableVirtualItem;
import com.soomla.store.domain.VirtualItem;
import com.soomla.store.domain.virtualGoods.EquippableVG;
import com.soomla.store.domain.virtualGoods.UpgradeVG;
import com.soomla.store.domain.virtualGoods.VirtualGood;
import com.soomla.store.exceptions.InsufficientFundsException;
import com.soomla.store.exceptions.NotEnoughGoodsException;
import com.soomla.store.exceptions.VirtualItemNotFoundException;

import java.util.List;

public class StoreInventory {

    public static void buy(String itemId) throws InsufficientFundsException, VirtualItemNotFoundException {
        PurchasableVirtualItem pvi = (PurchasableVirtualItem) StoreInfo.getVirtualItem(itemId);
        pvi.buy();
    }

    /** Virtual Items **/

    // The itemId must be of a VirtualCurrency or SingleUseVG or LifetimeVG or EquippableVG
    public static int getVirtualItemBalance(String itemId) throws VirtualItemNotFoundException {
        VirtualItem item = StoreInfo.getVirtualItem(itemId);
        return StorageManager.getVirtualItemStorage(item).getBalance(item);
    }

    public static void giveVirtualItem(String itemId, int amount) throws VirtualItemNotFoundException  {
        VirtualItem item = StoreInfo.getVirtualItem(itemId);
        item.give(amount);
    }

    public static void takeVirtualItem(String itemId, int amount) throws VirtualItemNotFoundException  {
        VirtualItem item = StoreInfo.getVirtualItem(itemId);
        item.take(amount);
    }

    /** Virtual Goods **/

    public static void equipVirtualGood(String goodItemId) throws VirtualItemNotFoundException, ClassCastException, NotEnoughGoodsException{
        EquippableVG good = (EquippableVG) StoreInfo.getVirtualItem(goodItemId);

        try {
            good.equip();
        } catch (NotEnoughGoodsException e) {
            StoreUtils.LogError("StoreInventory", "UNEXPECTED! couldn't equip something");
            throw e;
        }
    }

    public static void unEquipVirtualGood(String goodItemId) throws VirtualItemNotFoundException, ClassCastException{
        EquippableVG good = (EquippableVG) StoreInfo.getVirtualItem(goodItemId);

        good.unequip();
    }

    public static boolean isVirtualGoodEquipped(String goodItemId) throws VirtualItemNotFoundException, ClassCastException{
        EquippableVG good = (EquippableVG) StoreInfo.getVirtualItem(goodItemId);

        return StorageManager.getVirtualGoodsStorage().isEquipped(good);
    }

    public static int getGoodUpgradeLevel(String goodItemId) throws VirtualItemNotFoundException {
        VirtualGood good = (VirtualGood) StoreInfo.getVirtualItem(goodItemId);
        UpgradeVG upgradeVG = StorageManager.getVirtualGoodsStorage().getCurrentUpgrade(good);
        if (upgradeVG == null) {
            return 0;
        }

        UpgradeVG first = StoreInfo.getGoodFirstUpgrade(goodItemId);
        int level = 1;
        while (!first.equals(upgradeVG)) {
            first = (UpgradeVG) StoreInfo.getVirtualItem(first.getNextItemId());
            level++;
        }

        return level;
    }

    public static String getGoodCurrentUpgrade(String goodItemId) throws VirtualItemNotFoundException {
        VirtualGood good = (VirtualGood) StoreInfo.getVirtualItem(goodItemId);
        UpgradeVG upgradeVG = StorageManager.getVirtualGoodsStorage().getCurrentUpgrade(good);
        if (upgradeVG == null) {
            return "";
        }
        return upgradeVG.getItemId();
    }

    // Just upgrading the given VirtualGood (the 'buy' process will be applied)
    public static void upgradeVirtualGood(String goodItemId) throws VirtualItemNotFoundException, InsufficientFundsException {
        VirtualGood good = (VirtualGood) StoreInfo.getVirtualItem(goodItemId);
        UpgradeVG upgradeVG = StorageManager.getVirtualGoodsStorage().getCurrentUpgrade(good);
        if (upgradeVG != null) {
            String nextItemId = upgradeVG.getNextItemId();
            if (TextUtils.isEmpty(nextItemId)) {
                return;
            }
            UpgradeVG vgu = (UpgradeVG) StoreInfo.getVirtualItem(nextItemId);
            vgu.buy();
        } else {
            UpgradeVG first = StoreInfo.getGoodFirstUpgrade(goodItemId);
            if (first != null) {
                first.buy();
            }
        }
    }

    public static void forceUpgrade(String upgradeItemId) throws VirtualItemNotFoundException {
        try {
            UpgradeVG upgradeVG = (UpgradeVG) StoreInfo.getVirtualItem(upgradeItemId);
            upgradeVG.give(1);
        } catch (ClassCastException ex) {
            StoreUtils.LogError("SOOMLA StoreInventory", "The given itemId was of a non UpgradeVG VirtualItem. Can't force it.");
        }
    }

    public static void removeUpgrades(String goodItemId) throws VirtualItemNotFoundException {
        List<UpgradeVG> upgrades = StoreInfo.getGoodUpgrades(goodItemId);
        for (UpgradeVG upgrade : upgrades) {
            StorageManager.getVirtualGoodsStorage().remove(upgrade, 1, true);
        }
        VirtualGood good = (VirtualGood) StoreInfo.getVirtualItem(goodItemId);
        StorageManager.getVirtualGoodsStorage().removeUpgrades(good);
    }

    /** NonConsumables **/

    public static boolean nonConsumableItemExists(String nonConsItemId) throws VirtualItemNotFoundException, ClassCastException {
        NonConsumableItem nonConsumableItem = (NonConsumableItem) StoreInfo.getVirtualItem(nonConsItemId);

        return StorageManager.getNonConsumableItemsStorage().nonConsumableItemExists(nonConsumableItem);
    }

    public static void addNonConsumableItem(String nonConsItemId) throws VirtualItemNotFoundException, ClassCastException {
        NonConsumableItem nonConsumableItem = (NonConsumableItem) StoreInfo.getVirtualItem(nonConsItemId);

        StorageManager.getNonConsumableItemsStorage().add(nonConsumableItem);
    }

    public static void removeNonConsumableItem(String nonConsItemId) throws VirtualItemNotFoundException, ClassCastException {
        NonConsumableItem nonConsumableItem = (NonConsumableItem) StoreInfo.getVirtualItem(nonConsItemId);

        StorageManager.getNonConsumableItemsStorage().remove(nonConsumableItem);
    }
}
