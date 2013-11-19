#ifndef CONST_INAPPPURCHASESLIST_H
#define CONST_INAPPPURCHASESLIST_H

#include "CCIStoreAssets.h"
#include "cocos2d.h"

#include "Options.h"

class InAppPurchasesList: public soomla::CCIStoreAssets {
    cocos2d::CCArray *mCurrencies;
    cocos2d::CCArray *mGoods;
    cocos2d::CCArray *mCurrencyPacks;
    cocos2d::CCArray *mCategories;
    cocos2d::CCArray *mNonConsumableItems;
public:
    InAppPurchasesList():
    mCurrencies(NULL),
    mGoods(NULL),
    mCurrencyPacks(NULL),
    mCategories(NULL),
    mNonConsumableItems(NULL)
    {}
    
    virtual ~InAppPurchasesList();
    
    static InAppPurchasesList *create();
    bool init();
    
    virtual int getVersion();
    
    virtual cocos2d::CCArray *getCurrencies();
    
    virtual cocos2d::CCArray *getGoods();
    
    virtual cocos2d::CCArray *getCurrencyPacks();
    
    virtual cocos2d::CCArray *getCategories();
    
    virtual cocos2d::CCArray *getNonConsumableItems();
};

#endif