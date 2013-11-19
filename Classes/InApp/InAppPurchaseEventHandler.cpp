#ifndef CONST_INAPPPURCHASEEVENTHANDLER
#define CONST_INAPPPURCHASEEVENTHANDLER

#include "InAppPurchaseEventHandler.h"
#include "CCStoreUtils.h"
#include "cocos2d.h"
#include "PaymentProceed.h"

#define TAG "InAppPurchaseEventHandler"

USING_NS_CC;

void InAppPurchaseEventHandler::onBillingNotSupported() {
    soomla::CCStoreUtils::logDebug(TAG, "BillingNotSupported");
}

void InAppPurchaseEventHandler::onBillingSupported() {
    soomla::CCStoreUtils::logDebug(TAG, "BillingSupported");
}

void InAppPurchaseEventHandler::onOpeningStore() {
    soomla::CCStoreUtils::logDebug(TAG, "OpeningStore");
}

void InAppPurchaseEventHandler::onClosingStore() {
    soomla::CCStoreUtils::logDebug(TAG, "ClosingStore");
}

void InAppPurchaseEventHandler::onCurrencyBalanceChanged(soomla::CCVirtualCurrency *virtualCurrency, int balance, int amountAdded) {
    soomla::CCStoreUtils::logDebug(TAG, "CurrencyBalanceChanged");
    CCNotificationCenter::sharedNotificationCenter()->postNotification
    (EVENT_ON_CURRENCY_BALANCE_CHANGED, CCInteger::create(balance));
}

void InAppPurchaseEventHandler::onGoodBalanceChanged(soomla::CCVirtualGood *virtualGood, int balance, int amountAdded) {
    soomla::CCStoreUtils::logDebug(TAG, "GoodBalanceChanged");
    CCNotificationCenter::sharedNotificationCenter()->postNotification
    (EVENT_ON_GOOD_BALANCE_CHANGED, CCArray::create(virtualGood, CCInteger::create(balance), NULL));
}

void InAppPurchaseEventHandler::onGoodEquipped(soomla::CCEquippableVG *equippableVG) {
    soomla::CCStoreUtils::logDebug(TAG, "GoodEquipped");
    CCNotificationCenter::sharedNotificationCenter()->postNotification(EVENT_ON_GOOD_EQUIPPED, equippableVG);
}

void InAppPurchaseEventHandler::onGoodUnEquipped(soomla::CCEquippableVG *equippableVG) {
    soomla::CCStoreUtils::logDebug(TAG, "GoodUnEquipped");
    CCNotificationCenter::sharedNotificationCenter()->postNotification(EVENT_ON_GOOD_UNEQUIPPED, equippableVG);
}

void InAppPurchaseEventHandler::onGoodUpgrade(soomla::CCVirtualGood *virtualGood, soomla::CCUpgradeVG *upgradeVG) {
    soomla::CCStoreUtils::logDebug(TAG, "GoodUpgrade");
    CCNotificationCenter::sharedNotificationCenter()->postNotification(EVENT_ON_GOOD_UPGRADE, virtualGood);
}

void InAppPurchaseEventHandler::onItemPurchased(soomla::CCPurchasableVirtualItem *purchasableVirtualItem) {
    soomla::CCStoreUtils::logDebug(TAG, "ItemPurchased");
    
    int id = -1;
    
    if(purchasableVirtualItem->getItemId()->compare(Options::IN_APP_COINS_PACK_1_ID) == 0)  id = 1;
    if(purchasableVirtualItem->getItemId()->compare(Options::IN_APP_COINS_PACK_2_ID) == 0)  id = 2;
    if(purchasableVirtualItem->getItemId()->compare(Options::IN_APP_COINS_PACK_3_ID) == 0)  id = 3;
    if(purchasableVirtualItem->getItemId()->compare(Options::IN_APP_COINS_PACK_4_ID) == 0)  id = 4;
    if(purchasableVirtualItem->getItemId()->compare(Options::IN_APP_KEYS_PACK_1_ID) == 0)   id = 5;
    if(purchasableVirtualItem->getItemId()->compare(Options::IN_APP_KEYS_PACK_2_ID) == 0)   id = 6;
    if(purchasableVirtualItem->getItemId()->compare(Options::IN_APP_RESTORE_LIVES_ID) == 0) id = 7;
    if(purchasableVirtualItem->getItemId()->compare(Options::IN_APP_RESTORE_HITS_ID) == 0)  id = 8;

    switch(id)
    {
        default:
        soomla::CCStoreUtils::logDebug(TAG, "ItemPurchased but id is not identificated.");
        break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        if(Options::PAYMENT_PROCEED_HANDLER != NULL)
        {
            static_cast<PaymentProceed*>(Options::PAYMENT_PROCEED_HANDLER)->onItemPurchased();
        }
        break;
    }
}

void InAppPurchaseEventHandler::onItemPurchaseStarted(soomla::CCPurchasableVirtualItem *purchasableVirtualItem) {
    soomla::CCStoreUtils::logDebug(TAG, "ItemPurchaseStarted");
}

void InAppPurchaseEventHandler::onMarketPurchaseCancelled(soomla::CCPurchasableVirtualItem *purchasableVirtualItem) {
    soomla::CCStoreUtils::logDebug(TAG, "MarketPurchaseCancelled");
    
    if(Options::PAYMENT_PROCEED_HANDLER != NULL)
    {
        static_cast<PaymentProceed*>(Options::PAYMENT_PROCEED_HANDLER)->hide();
    }
}

void InAppPurchaseEventHandler::onMarketPurchase(soomla::CCPurchasableVirtualItem *purchasableVirtualItem) {
    soomla::CCStoreUtils::logDebug(TAG, "MarketPurchase");
}

void InAppPurchaseEventHandler::onMarketPurchaseStarted(soomla::CCPurchasableVirtualItem *purchasableVirtualItem) {
    soomla::CCStoreUtils::logDebug(TAG, "MarketPurchaseStarted");
}

void InAppPurchaseEventHandler::onMarketRefund(soomla::CCPurchasableVirtualItem *purchasableVirtualItem) {
    soomla::CCStoreUtils::logDebug(TAG, "MarketRefund");
}

void InAppPurchaseEventHandler::onRestoreTransactions(bool success) {
    soomla::CCStoreUtils::logDebug(TAG, "RestoreTransactions");
}

void InAppPurchaseEventHandler::onRestoreTransactionsStarted() {
    soomla::CCStoreUtils::logDebug(TAG, "RestoreTransactionsStarted");
}

void InAppPurchaseEventHandler::onUnexpectedErrorInStore() {
    soomla::CCStoreUtils::logDebug(TAG, "UnexpectedErrorInStore");
    
    if(Options::PAYMENT_PROCEED_HANDLER != NULL)
    {
        static_cast<PaymentProceed*>(Options::PAYMENT_PROCEED_HANDLER)->hide();
    }
}

void InAppPurchaseEventHandler::onStoreControllerInitialized() {
    soomla::CCStoreUtils::logDebug(TAG, "StoreContorllerInitialized");
}

#endif