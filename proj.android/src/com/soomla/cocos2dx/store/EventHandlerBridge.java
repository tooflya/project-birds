package com.soomla.cocos2dx.store;

import com.soomla.store.BusProvider;
import com.soomla.store.events.*;
import com.squareup.otto.Subscribe;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;
import org.json.JSONException;
import org.json.JSONObject;

/**
 * This bridge is used to populate events from the store to cocos2dx (through JNI).
 */
public class EventHandlerBridge {

    private Cocos2dxGLSurfaceView mGLThread;

    public EventHandlerBridge(Cocos2dxGLSurfaceView glThread) {
        mGLThread = glThread;

        BusProvider.getInstance().register(this);
    }

    @Subscribe
    public void onBillingNotSupported(BillingNotSupportedEvent billingNotSupportedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onBillingNotSupported");
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onBillingSupported(BillingSupportedEvent billingSupportedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onBillingSupported");
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onOpeningStore(OpeningStoreEvent openingStoreEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onOpeningStore");
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onClosingStore(ClosingStoreEvent closingStoreEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onClosingStore");
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onCurrencyBalanceChanged(final CurrencyBalanceChangedEvent currencyBalanceChangedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onCurrencyBalanceChanged");
                    parameters.put("itemId", currencyBalanceChangedEvent.getCurrency().getItemId());
                    parameters.put("balance", currencyBalanceChangedEvent.getBalance());
                    parameters.put("amountAdded", currencyBalanceChangedEvent.getAmountAdded());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onGoodBalanceChanged(final GoodBalanceChangedEvent goodBalanceChangedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onGoodBalanceChanged");
                    parameters.put("itemId", goodBalanceChangedEvent.getGood().getItemId());
                    parameters.put("balance", goodBalanceChangedEvent.getBalance());
                    parameters.put("amountAdded", goodBalanceChangedEvent.getAmountAdded());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onGoodEquipped(final GoodEquippedEvent goodEquippedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onGoodEquipped");
                    parameters.put("itemId", goodEquippedEvent.getGood().getItemId());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onGoodUnequipped(final GoodUnEquippedEvent goodUnEquippedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onGoodUnEquipped");
                    parameters.put("itemId", goodUnEquippedEvent.getGood().getItemId());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onGoodUpgrade(final GoodUpgradeEvent goodUpgradeEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onGoodUpgrade");
                    parameters.put("itemId", goodUpgradeEvent.getGood().getItemId());
                    parameters.put("vguItemId", goodUpgradeEvent.getCurrentUpgrade().getItemId());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onItemPurchased(final ItemPurchasedEvent itemPurchasedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onItemPurchased");
                    parameters.put("itemId", itemPurchasedEvent.getPurchasableVirtualItem().getItemId());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onItemPurchaseStarted(final ItemPurchaseStartedEvent itemPurchaseStartedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onItemPurchaseStarted");
                    parameters.put("itemId", itemPurchaseStartedEvent.getPurchasableVirtualItem().getItemId());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onPlayPurchaseCancelled(final PlayPurchaseCancelledEvent playPurchaseCancelledEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onMarketPurchaseCancelled");
                    parameters.put("itemId", playPurchaseCancelledEvent.getPurchasableVirtualItem().getItemId());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onPlayPurchase(final PlayPurchaseEvent playPurchaseEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onMarketPurchase");
                    parameters.put("itemId", playPurchaseEvent.getPurchasableVirtualItem().getItemId());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onPlayPurchaseStarted(final PlayPurchaseStartedEvent playPurchaseStartedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onMarketPurchaseStarted");
                    parameters.put("itemId", playPurchaseStartedEvent.getPurchasableVirtualItem().getItemId());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onPlayRefund(final PlayRefundEvent playRefundEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onMarketRefund");
                    parameters.put("itemId", playRefundEvent.getPurchasableVirtualItem().getItemId());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onRestoreTransactions(final RestoreTransactionsEvent restoreTransactionsEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onRestoreTransactions");
                    parameters.put("success", restoreTransactionsEvent.isSuccess());
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onRestoreTransactionsStarted(final RestoreTransactionsStartedEvent restoreTransactionsStartedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onRestoreTransactionsStarted");
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onUnexpectedErrorInStore(UnexpectedStoreErrorEvent unexpectedStoreErrorEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onUnexpectedErrorInStore");
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }

    @Subscribe
    public void onStoreControllerInitialized(StoreControllerInitializedEvent storeControllerInitializedEvent) {
        mGLThread.queueEvent(new Runnable() {
            @Override
            public void run() {
                try {
                    JSONObject parameters = new JSONObject();
                    parameters.put("method", "CCEventHandler::onStoreControllerInitialized");
                    SoomlaNDKGlue.sendMessageWithParameters(parameters);
                } catch (JSONException e) {
                    throw new IllegalStateException(e);
                }
            }
        });
    }
}
