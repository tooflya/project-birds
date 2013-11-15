package com.soomla.cocos2dx.store;

import com.soomla.store.IStoreAssets;
import com.soomla.store.data.JSONConsts;
import com.soomla.store.domain.NonConsumableItem;
import com.soomla.store.domain.VirtualCategory;
import com.soomla.store.domain.virtualCurrencies.VirtualCurrency;
import com.soomla.store.domain.virtualCurrencies.VirtualCurrencyPack;
import com.soomla.store.domain.virtualGoods.*;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;

/**
 * @author vedi
 *         date 5/21/13
 *         time 11:23 PM
 */
public class StoreAssetsBridge implements IStoreAssets {

    private int version;
    private VirtualCurrency[] currencies;
    private VirtualGood[] goods;
    private VirtualCurrencyPack[] currencyPacks;
    private VirtualCategory[] categories;
    private NonConsumableItem[] nonConsumableItems;

    public StoreAssetsBridge(int version, JSONObject jsonObject) {
        this.version = version;

        try {
            List<VirtualCurrency> currencies = new ArrayList<VirtualCurrency>();
            JSONArray currenciesDicts = jsonObject.getJSONArray(JSONConsts.STORE_CURRENCIES);
            for (int i = 0; i < currenciesDicts.length(); i++) {
                VirtualCurrency o = new VirtualCurrency(currenciesDicts.getJSONObject(i));
                currencies.add(o);
            }
            this.currencies = currencies.toArray(new VirtualCurrency[currencies.size()]);

            List<VirtualCurrencyPack> currencyPacks = new ArrayList<VirtualCurrencyPack>();
            JSONArray currencyPacksDicts = jsonObject.getJSONArray(JSONConsts.STORE_CURRENCYPACKS);
            for (int i = 0; i < currencyPacksDicts.length(); i++) {
                VirtualCurrencyPack o = new VirtualCurrencyPack(currencyPacksDicts.getJSONObject(i));
                currencyPacks.add(o);
            }
            this.currencyPacks = currencyPacks.toArray(new VirtualCurrencyPack[currencyPacks.size()]);

            JSONObject goodsDict = jsonObject.getJSONObject(JSONConsts.STORE_GOODS);

            JSONArray suGoods = goodsDict.getJSONArray(JSONConsts.STORE_GOODS_SU);
            JSONArray ltGoods = goodsDict.getJSONArray(JSONConsts.STORE_GOODS_LT);
            JSONArray eqGoods = goodsDict.getJSONArray(JSONConsts.STORE_GOODS_EQ);
            JSONArray upGoods = goodsDict.getJSONArray(JSONConsts.STORE_GOODS_UP);
            JSONArray paGoods = goodsDict.getJSONArray(JSONConsts.STORE_GOODS_PA);
            List<VirtualGood> goods = new ArrayList<VirtualGood>();
            for (int i = 0; i < suGoods.length(); i++) {
                SingleUseVG o = new SingleUseVG(suGoods.getJSONObject(i));
                goods.add(o);
            }
            for (int i = 0; i < ltGoods.length(); i++) {
                LifetimeVG o = new LifetimeVG(ltGoods.getJSONObject(i));
                goods.add(o);
            }
            for (int i = 0; i < eqGoods.length(); i++) {
                EquippableVG o = new EquippableVG(eqGoods.getJSONObject(i));
                goods.add(o);
            }
            for (int i = 0; i < upGoods.length(); i++) {
                UpgradeVG o = new UpgradeVG(upGoods.getJSONObject(i));
                goods.add(o);
            }
            for (int i = 0; i < paGoods.length(); i++) {
                SingleUsePackVG o = new SingleUsePackVG(paGoods.getJSONObject(i));
                goods.add(o);
            }
            this.goods = goods.toArray(new VirtualGood[goods.size()]);

            List<VirtualCategory> categories = new ArrayList<VirtualCategory>();
            JSONArray categoriesDicts = jsonObject.getJSONArray(JSONConsts.STORE_CATEGORIES);
            for (int i = 0; i < categoriesDicts.length(); i++) {
                VirtualCategory o = new VirtualCategory(categoriesDicts.getJSONObject(i));
                categories.add(o);
            }
            this.categories = categories.toArray(new VirtualCategory[categories.size()]);

            List<NonConsumableItem> nonConsumables = new ArrayList<NonConsumableItem>();
            JSONArray nonConsumableItemsDict = jsonObject.getJSONArray(JSONConsts.STORE_NONCONSUMABLES);
            for (int i = 0; i < nonConsumableItemsDict.length(); i++) {
                NonConsumableItem o = new NonConsumableItem(nonConsumableItemsDict.getJSONObject(i));
                nonConsumables.add(o);
            }
            this.nonConsumableItems = nonConsumables.toArray(new NonConsumableItem[nonConsumables.size()]);
        } catch (JSONException e) {
            // TODO: Implement error handling
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }

    }

    @Override
    public int getVersion() {
        return version;
    }

    @Override
    public VirtualCurrency[] getCurrencies() {
        return currencies;
    }

    @Override
    public VirtualGood[] getGoods() {
        return goods;
    }

    @Override
    public VirtualCurrencyPack[] getCurrencyPacks() {
        return currencyPacks;
    }

    @Override
    public VirtualCategory[] getCategories() {
        return categories;
    }

    @Override
    public NonConsumableItem[] getNonConsumableItems() {
        return nonConsumableItems;
    }
}
