#ifndef CONST_INAPPPURCHASEEVENTHANDLER_H
#define CONST_INAPPPURCHASEEVENTHANDLER_H

#include <string>
#include "CCEventHandler.h"

#include "Options.h"

#define EVENT_ON_CURRENCY_BALANCE_CHANGED "onCurrencyBalanceChanged"
#define EVENT_ON_GOOD_BALANCE_CHANGED "onGoodBalanceChanged"
#define EVENT_ON_GOOD_EQUIPPED "onGoodEquipped"
#define EVENT_ON_GOOD_UNEQUIPPED "onGoodUnEquipped"
#define EVENT_ON_GOOD_UPGRADE "onGoodUpgrade"

using namespace std;

class InAppPurchaseEventHandler : public soomla::CCEventHandler {
    public:
    
    virtual void onBillingNotSupported();
    virtual void onBillingSupported();
    virtual void onOpeningStore();
    virtual void onClosingStore();
    virtual void onCurrencyBalanceChanged(soomla::CCVirtualCurrency *virtualCurrency, int balance, int amountAdded);
    virtual void onGoodBalanceChanged(soomla::CCVirtualGood *virtualGood, int balance, int amountAdded);
    virtual void onGoodEquipped(soomla::CCEquippableVG *equippableVG);
    virtual void onGoodUnEquipped(soomla::CCEquippableVG *equippableVG);
    virtual void onGoodUpgrade(soomla::CCVirtualGood *virtualGood, soomla::CCUpgradeVG *upgradeVG);
    virtual void onItemPurchased(soomla::CCPurchasableVirtualItem *purchasableVirtualItem);
    virtual void onItemPurchaseStarted(soomla::CCPurchasableVirtualItem *purchasableVirtualItem);
    virtual void onMarketPurchaseCancelled(soomla::CCPurchasableVirtualItem *purchasableVirtualItem);
    virtual void onMarketPurchase(soomla::CCPurchasableVirtualItem *purchasableVirtualItem);
    virtual void onMarketPurchaseStarted(soomla::CCPurchasableVirtualItem *purchasableVirtualItem);
    virtual void onMarketRefund(soomla::CCPurchasableVirtualItem *purchasableVirtualItem);
    virtual void onRestoreTransactions(bool success);
    virtual void onRestoreTransactionsStarted();
    virtual void onUnexpectedErrorInStore();
    virtual void onStoreControllerInitialized();
};

#endif