package com.soomla.cocos2dx.store;

import android.util.Log;

import com.soomla.store.StoreUtils;
import com.soomla.store.exceptions.InsufficientFundsException;
import com.soomla.store.exceptions.NotEnoughGoodsException;
import com.soomla.store.exceptions.VirtualItemNotFoundException;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/**
 * @author vedi
 *         date 5/24/13
 *         time 8:36 PM
 */
public class SoomlaNDKGlue {

    private static native void cppNativeCallHandler(String json);

    public static void sendMessageWithParameters(JSONObject paramList) {
        cppNativeCallHandler(paramList.toString());
    }

    public static String receiveCppMessage(String json) {
        if (json != null) {
            try {
                JSONObject params = new JSONObject(json);
                JSONObject retParamsJson = dispatchNDKCall(params);
                if (retParamsJson == null) {
                    retParamsJson = new JSONObject();
                }
                StoreUtils.LogDebug("SoomlaNDKGlue", "retParamsJson: " + retParamsJson.toString());
                return retParamsJson.toString();
            } catch (JSONException e) {
                StoreUtils.LogError("SoomlaNDKGlue", "receiveCppMessage raised exception" + e);
            }
        }
        return null;
    }


    public static JSONObject dispatchNDKCall(JSONObject params) {
        JSONObject retParams = new JSONObject();
        try {
            try {
                String methodName = params.getString("method");
            	Log.d("SOOMLA", methodName);
                if (methodName.equals("CCStoreAssets::init")) {
                    int version = params.getInt("version");
                    JSONObject storeAssetsJson = params.getJSONObject("storeAssets");
                    StoreControllerBridge.setStoreAssetsBridge(new StoreAssetsBridge(version, storeAssetsJson));
                } else if (methodName.equals("CCStoreController::init")) {
                    String customSecret = params.getString("customSecret");
                    StoreControllerBridge.initialize(customSecret);
                } else if (methodName.equals("CCStoreController::buyMarketItem")) {
                    String productId = params.getString("productId");
                    StoreControllerBridge.buyWithGooglePlay(productId);
                } else if (methodName.equals("CCStoreController::storeOpening")) {
                    StoreControllerBridge.storeOpening();
                } else if (methodName.equals("CCStoreController::storeClosing")) {
                    StoreControllerBridge.storeClosing();
                } else if (methodName.equals("CCStoreController::restoreTransactions")) {
                    StoreControllerBridge.restoreTransactions();
                } else if (methodName.equals("CCStoreController::transactionsAlreadyRestored")) {
                    boolean retValue = StoreControllerBridge.transactionsAlreadyRestored();
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreController::setAndroidTestMode")) {
                    Boolean testMode = params.getBoolean("testMode");
                    StoreControllerBridge.setAndroidTestMode(testMode);
                } else if (methodName.equals("CCStoreController::setSoomSec")) {
                    String soomSec = params.getString("soomSec");
                    StoreControllerBridge.setSoomSec(soomSec);
                } else if (methodName.equals("CCStoreController::setAndroidPublicKey")) {
                    String androidPublicKey = params.getString("androidPublicKey");
                    StoreControllerBridge.setAndroidPublicKey(androidPublicKey);
                } else if (methodName.equals("CCStoreInventory::buyItem")) {
                    String itemId = params.getString("itemId");
                    StoreInventoryBridge.buy(itemId);
                } else if (methodName.equals("CCStoreInventory::getItemBalance")) {
                    String itemId = params.getString("itemId");
                    int retValue = StoreInventoryBridge.getItemBalance(itemId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInventory::giveItem")) {
                    String itemId = params.getString("itemId");
                    Integer amount = params.getInt("amount");
                    StoreInventoryBridge.giveItem(itemId, amount);
                } else if (methodName.equals("CCStoreInventory::takeItem")) {
                    String itemId = params.getString("itemId");
                    Integer amount = params.getInt("amount");
                    StoreInventoryBridge.takeItem(itemId, amount);
                } else if (methodName.equals("CCStoreInventory::equipVirtualGood")) {
                    String itemId = params.getString("itemId");
                    StoreInventoryBridge.equipVirtualGood(itemId);
                } else if (methodName.equals("CCStoreInventory::unEquipVirtualGood")) {
                    String itemId = params.getString("itemId");
                    StoreInventoryBridge.unEquipVirtualGood(itemId);
                } else if (methodName.equals("CCStoreInventory::isVirtualGoodEquipped")) {
                    String itemId = params.getString("itemId");
                    boolean retValue = StoreInventoryBridge.isVirtualGoodEquipped(itemId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInventory::getGoodUpgradeLevel")) {
                    String goodItemId = params.getString("goodItemId");
                    Integer retValue = StoreInventoryBridge.getGoodUpgradeLevel(goodItemId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInventory::getGoodCurrentUpgrade")) {
                    String goodItemId = params.getString("goodItemId");
                    String retValue = StoreInventoryBridge.getGoodCurrentUpgrade(goodItemId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInventory::upgradeGood")) {
                    String itemId = params.getString("goodItemId");
                    StoreInventoryBridge.upgradeVirtualGood(itemId);
                } else if (methodName.equals("CCStoreInventory::removeGoodUpgrades")) {
                    String itemId = params.getString("goodItemId");
                    StoreInventoryBridge.upgradeVirtualGood(itemId);
                } else if (methodName.equals("CCStoreInventory::nonConsumableItemExists")) {
                    String nonConsItemId = params.getString("nonConsItemId");
                    boolean retValue = StoreInventoryBridge.nonConsumableItemExists(nonConsItemId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInventory::addNonConsumableItem")) {
                    String nonConsItemId = params.getString("nonConsItemId");
                    StoreInventoryBridge.addNonConsumableItem(nonConsItemId);
                } else if (methodName.equals("CCStoreInventory::removeNonConsumableItem")) {
                    String nonConsItemId = params.getString("nonConsItemId");
                    StoreInventoryBridge.removeNonConsumableItem(nonConsItemId);
                } else if (methodName.equals("CCStoreInfo::getItemByItemId")) {
                    String itemId = params.getString("itemId");
                    JSONObject retValue = StoreInfoBridge.getItemByItemId(itemId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInfo::getPurchasableItemWithProductId")) {
                    String productId = params.getString("productId");
                    JSONObject retValue = StoreInfoBridge.getPurchasableItemWithProductId(productId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInfo::getCategoryForVirtualGood")) {
                    String goodItemId = params.getString("goodItemId");
                    JSONObject retValue = StoreInfoBridge.getCategoryForVirtualGood(goodItemId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInfo::getFirstUpgradeForVirtualGood")) {
                    String goodItemId = params.getString("goodItemId");
                    JSONObject retValue = StoreInfoBridge.getFirstUpgradeForVirtualGood(goodItemId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInfo::getLastUpgradeForVirtualGood")) {
                    String goodItemId = params.getString("goodItemId");
                    JSONObject retValue = StoreInfoBridge.getLastUpgradeForVirtualGood(goodItemId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInfo::getUpgradesForVirtualGood")) {
                    String goodItemId = params.getString("goodItemId");
                    JSONArray retValue = StoreInfoBridge.getUpgradesForVirtualGood(goodItemId);
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInfo::getVirtualCurrencies")) {
                    JSONArray retValue = StoreInfoBridge.getVirtualCurrencies();
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInfo::getVirtualGoods")) {
                    JSONArray retValue = StoreInfoBridge.getVirtualGoods();
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInfo::getVirtualCurrencyPacks")) {
                    JSONArray retValue = StoreInfoBridge.getVirtualCurrencyPacks();
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInfo::getNonConsumableItems")) {
                    JSONArray retValue = StoreInfoBridge.getNonConsumableItems();
                    retParams.put("return", retValue);
                } else if (methodName.equals("CCStoreInfo::getVirtualCategories")) {
                    JSONArray retValue = StoreInfoBridge.getVirtualCategories();
                    retParams.put("return", retValue);
                } else {
                    throw new UnsupportedOperationException();
                }
            } catch (VirtualItemNotFoundException e) {
                retParams.put("errorCode", -11);
            } catch (InsufficientFundsException e) {
                retParams.put("errorCode", -2);
            } catch (NotEnoughGoodsException  e) {
                retParams.put("errorCode", -3);
            }
        } catch (JSONException e) {
            throw new IllegalArgumentException(e);
        }

        return retParams;
    }
}