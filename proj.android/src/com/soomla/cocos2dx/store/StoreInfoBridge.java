package com.soomla.cocos2dx.store;

import com.soomla.store.data.StoreInfo;
import com.soomla.store.domain.NonConsumableItem;
import com.soomla.store.domain.PurchasableVirtualItem;
import com.soomla.store.domain.VirtualCategory;
import com.soomla.store.domain.VirtualItem;
import com.soomla.store.domain.virtualCurrencies.VirtualCurrency;
import com.soomla.store.domain.virtualCurrencies.VirtualCurrencyPack;
import com.soomla.store.domain.virtualGoods.UpgradeVG;
import com.soomla.store.domain.virtualGoods.VirtualGood;
import com.soomla.store.exceptions.VirtualItemNotFoundException;
import com.soomla.store.purchaseTypes.PurchaseWithMarket;
import com.soomla.store.purchaseTypes.PurchaseWithVirtualItem;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

/**
 * This bridge is used to let cocos2dx functions retrieve data from StoreInfo (through JNI).
 *
 * You can see the documentation of every function in {@link StoreInfo}
 */
public class StoreInfoBridge {

    public static JSONObject getItemByItemId(String itemId) throws VirtualItemNotFoundException {
        VirtualItem virtualItem = StoreInfo.getVirtualItem(itemId);

        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put("item", virtualItem.toJSONObject());
            jsonObject.put("className", virtualItem.getClass().getSimpleName());
        } catch (JSONException e) {
            throw new IllegalStateException(e);
        }

        return jsonObject;
    }

    public static JSONObject getPurchasableItemWithProductId(String productId) throws VirtualItemNotFoundException {
        PurchasableVirtualItem purchasableVirtualItem = StoreInfo.getPurchasableItem(productId);

        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put("item", purchasableVirtualItem.toJSONObject());
            jsonObject.put("className", purchasableVirtualItem.getClass().getSimpleName());
        } catch (JSONException e) {
            //   TODO: Implement error handling
            throw new IllegalStateException(e);
        }

        return jsonObject;
    }

    public static JSONObject getCategoryForVirtualGood(String goodItemId) throws VirtualItemNotFoundException {
        return StoreInfo.getCategory(goodItemId).toJSONObject();
    }

    public static JSONObject getFirstUpgradeForVirtualGood(String goodItemId) {
        UpgradeVG upgradeVG = StoreInfo.getGoodFirstUpgrade(goodItemId);
        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put("item", upgradeVG.toJSONObject());
            jsonObject.put("className", upgradeVG.getClass().getSimpleName());
        } catch (JSONException e) {
            //   TODO: Implement error handling
            throw new IllegalStateException(e);
        }

        return jsonObject;
    }

    public static JSONObject getLastUpgradeForVirtualGood(String goodItemId) {
        UpgradeVG upgradeVG = StoreInfo.getGoodLastUpgrade(goodItemId);
        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put("item", upgradeVG.toJSONObject());
            jsonObject.put("className", upgradeVG.getClass().getSimpleName());
        } catch (JSONException e) {
            //   TODO: Implement error handling
            throw new IllegalStateException(e);
        }

        return jsonObject;
    }

    public static JSONArray getUpgradesForVirtualGood(String goodItemId) {
        List<JSONObject> ret = new ArrayList<JSONObject>();
        List<UpgradeVG> upgradeVGs = StoreInfo.getGoodUpgrades(goodItemId);
        for (UpgradeVG upgradeVG : upgradeVGs) {
            JSONObject jsonObject = new JSONObject();
            try {
                jsonObject.put("item", upgradeVG.toJSONObject());
                jsonObject.put("className", upgradeVG.getClass().getSimpleName());
                ret.add(jsonObject);
            } catch (JSONException e) {
                //   TODO: Implement error handling
                throw new IllegalStateException(e);
            }
        }
        return new JSONArray(ret);
    }

    public static JSONArray getVirtualCurrencies() {
        List<JSONObject> ret = new ArrayList<JSONObject>();
        List<VirtualCurrency> virtualCurrencies = StoreInfo.getCurrencies();
        for (VirtualCurrency virtualCurrency : virtualCurrencies) {
            JSONObject jsonObject = new JSONObject();
            try {
                jsonObject.put("item", virtualCurrency.toJSONObject());
                jsonObject.put("className", virtualCurrency.getClass().getSimpleName());
                ret.add(jsonObject);
            } catch (JSONException e) {
                //   TODO: Implement error handling
                throw new IllegalStateException(e);
            }
        }
        return new JSONArray(ret);
    }

    public static JSONArray getVirtualGoods() {
        List<JSONObject> ret = new ArrayList<JSONObject>();
        List<VirtualGood> virtualGoods = StoreInfo.getGoods();
        for (VirtualGood virtualGood : virtualGoods) {
            JSONObject jsonObject = new JSONObject();
            try {
                jsonObject.put("item", virtualGood.toJSONObject());
                jsonObject.put("className", virtualGood.getClass().getSimpleName());
                ret.add(jsonObject);
            } catch (JSONException e) {
                //   TODO: Implement error handling
                throw new IllegalStateException(e);
            }
        }
        return new JSONArray(ret);
    }

    public static JSONArray getVirtualCurrencyPacks() {
        List<JSONObject> ret = new ArrayList<JSONObject>();
        List<VirtualCurrencyPack> virtualCurrencyPacks = StoreInfo.getCurrencyPacks();
        for (VirtualCurrencyPack virtualCurrencyPack : virtualCurrencyPacks) {
            JSONObject jsonObject = new JSONObject();
            try {
                jsonObject.put("item", virtualCurrencyPack.toJSONObject());
                jsonObject.put("className", virtualCurrencyPack.getClass().getSimpleName());
                ret.add(jsonObject);
            } catch (JSONException e) {
                //   TODO: Implement error handling
                throw new IllegalStateException(e);
            }
        }
        return new JSONArray(ret);
    }

    public static JSONArray getNonConsumableItems() {
        List<JSONObject> ret = new ArrayList<JSONObject>();
        List<NonConsumableItem> nonConsumableItems = StoreInfo.getNonConsumableItems();
        for (NonConsumableItem nonConsumableItem : nonConsumableItems) {
            JSONObject jsonObject = new JSONObject();
            try {
                jsonObject.put("item", nonConsumableItem.toJSONObject());
                jsonObject.put("className", nonConsumableItem.getClass().getSimpleName());
                ret.add(jsonObject);
            } catch (JSONException e) {
                //   TODO: Implement error handling
                throw new IllegalStateException(e);
            }
        }
        return new JSONArray(ret);
    }

    public static JSONArray getVirtualCategories() {
        List<JSONObject> ret = new ArrayList<JSONObject>();
        List<VirtualCategory> virtualCategories = StoreInfo.getCategories();
        for (VirtualCategory virtualCategory : virtualCategories) {
            JSONObject jsonObject = new JSONObject();
            try {
                jsonObject.put("item", virtualCategory.toJSONObject());
                jsonObject.put("className", virtualCategory.getClass().getSimpleName());
                ret.add(jsonObject);
            } catch (JSONException e) {
                //   TODO: Implement error handling
                throw new IllegalStateException(e);
            }
        }
        return new JSONArray(ret);
    }
}
