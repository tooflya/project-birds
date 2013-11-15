package com.soomla.cocos2dx.store;

import android.app.Activity;

import com.soomla.store.*;
import com.soomla.store.data.StoreInfo;
import com.soomla.store.domain.PurchasableVirtualItem;
import com.soomla.store.exceptions.VirtualItemNotFoundException;
import com.soomla.store.purchaseTypes.PurchaseWithMarket;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

/**
 * This bridge is used to let cocos2dx functions perform actions on StoreController (through JNI).
 *
 * You can see the documentation of every function in {@link StoreController}
 */
public class StoreControllerBridge {
    private static Activity mActivity          = null;
    private static IStoreAssets mStoreAssets   = null;
    private static String mPublicKey           = "";
    private static EventHandlerBridge mEventHandler = null;
    private static Cocos2dxGLSurfaceView mGLView = null;

    /* Possible legacy code, TODO: remove */
    @Deprecated
    public static void initialize(Cocos2dxGLSurfaceView glView,
                                  IStoreAssets storeAssets,
                                  String publicKey,
                                  Activity activity) {
        mStoreAssets = storeAssets;
        mPublicKey   = publicKey;
        mActivity    = activity;

        mGLView = glView;


        mEventHandler = new EventHandlerBridge(glView);
    }

    public static void setGLView(Cocos2dxGLSurfaceView glView) {
        mGLView = glView;
    }

    public static void setActivity(Activity activity) {
        mActivity = activity;
    }

    public static void initialize(String customSecret) {
        StoreUtils.LogDebug("SOOMLA", "initialize is called from java!");
        mEventHandler = new EventHandlerBridge(mGLView);
        StoreController.getInstance().initialize(mStoreAssets, mPublicKey, customSecret);
    }

    public static void storeOpening() {
        StoreUtils.LogDebug("SOOMLA", "storeOpening is called from java!");
        StoreController.getInstance().storeOpening(mActivity);
    }

    public static void storeClosing() {
        StoreUtils.LogDebug("SOOMLA", "storeClosing is called from java!");
        StoreController.getInstance().storeClosing();
    }

    public static void buyWithGooglePlay(String productId) throws VirtualItemNotFoundException {
        StoreUtils.LogDebug("SOOMLA", "buyWithGooglePlay is called from java with productId: " + productId + "!");
        PurchasableVirtualItem pvi = StoreInfo.getPurchasableItem(productId);
        if(pvi.getPurchaseType() instanceof PurchaseWithMarket) {
            StoreController.getInstance().buyWithGooglePlay(((PurchaseWithMarket)pvi.getPurchaseType()).getGoogleMarketItem(), "");
        } else {
            throw new VirtualItemNotFoundException("productId", productId);
        }
    }

    public static void restoreTransactions() {
        StoreUtils.LogDebug("SOOMLA", "restoreTransactions is called from java!");
        StoreController.getInstance().restoreTransactions();
    }

    public static boolean transactionsAlreadyRestored() {
        StoreUtils.LogDebug("SOOMLA", "transactionsAlreadyRestored is called from java!");
        return StoreController.getInstance().transactionsAlreadyRestored();
    }

    public static void setAndroidTestMode(boolean testMode) {
        StoreUtils.LogDebug("SOOMLA", "setAndroidTestMode is called from java!");
        StoreController.getInstance().setTestMode(testMode);
    }

    public static void setStoreAssetsBridge(StoreAssetsBridge storeAssetsBridge) {
        StoreControllerBridge.mStoreAssets = storeAssetsBridge;
    }

    public static void setSoomSec(String soomSec) {
        StoreUtils.LogDebug("SOOMLA", "setSoomSec is called from java!");
        StoreConfig.SOOM_SEC = soomSec;
    }

    public static void setAndroidPublicKey(String publicKey) {
        StoreUtils.LogDebug("SOOMLA", "setAndroidPublicKey is called from java!");
        mPublicKey = publicKey;
    }

    private static String TAG = "StoreControllerBridge";
}
