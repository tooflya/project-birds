#ifndef CONST_INAPPPURCHASESLIST
#define CONST_INAPPPURCHASESLIST

#include "InAppPurchasesList.h"

#include "CCVirtualCurrency.h"
#include "CCVirtualCurrencyPack.h"
#include "CCVirtualGood.h"
#include "CCSingleUseVG.h"
#include "CCPurchaseWithMarket.h"
#include "CCPurchaseWithVirtualItem.h"
#include "CCVirtualCategory.h"
#include "CCNonConsumableItem.h"
#include "CCUpgradeVG.h"
#include "CCSingleUsePackVG.h"
#include "CCEquippableVG.h"

USING_NS_CC;
using namespace soomla;


InAppPurchasesList* InAppPurchasesList::create() {
    InAppPurchasesList *ret = new InAppPurchasesList();
    ret->autorelease();
    ret->init();
    
    return ret;
}

bool InAppPurchasesList::init() {
    this->mCurrencyPacks = CCArray::create();
    this->mCurrencyPacks->retain();
    
    this->mCurrencyPacks->addObject(CCVirtualCurrencyPack::create(
                                                                  CCString::create(""),
                                                                  CCString::create(""),
                                                                  CCString::create(Options::IN_APP_COINS_PACK_1_ID),
                                                                  CCInteger::create(0),
                                                                  CCString::create(""),
                                                                  CCPurchaseWithMarket::create(CCString::create(Options::IN_APP_COINS_PACK_1_ID), CCDouble::create(0.99))
                                                                  )
                                    );
    
    #if COCOS2D_DEBUG <= 0
    this->mCurrencyPacks->addObject(CCVirtualCurrencyPack::create(
                                                                  CCString::create(""),
                                                                  CCString::create(""),
                                                                  CCString::create(Options::IN_APP_COINS_PACK_2_ID),
                                                                  CCInteger::create(0),
                                                                  CCString::create(""),
                                                                  CCPurchaseWithMarket::create(CCString::create(Options::IN_APP_COINS_PACK_2_ID), CCDouble::create(1.99))
                                                                  )
                                    );
    this->mCurrencyPacks->addObject(CCVirtualCurrencyPack::create(
                                                                  CCString::create(""),
                                                                  CCString::create(""),
                                                                  CCString::create(Options::IN_APP_COINS_PACK_3_ID),
                                                                  CCInteger::create(0),
                                                                  CCString::create(""),
                                                                  CCPurchaseWithMarket::create(CCString::create(Options::IN_APP_COINS_PACK_3_ID), CCDouble::create(4.99))
                                                                  )
                                    );
    this->mCurrencyPacks->addObject(CCVirtualCurrencyPack::create(
                                                                  CCString::create(""),
                                                                  CCString::create(""),
                                                                  CCString::create(Options::IN_APP_COINS_PACK_4_ID),
                                                                  CCInteger::create(0),
                                                                  CCString::create(""),
                                                                  CCPurchaseWithMarket::create(CCString::create(Options::IN_APP_COINS_PACK_4_ID), CCDouble::create(7.99))
                                                                  )
                                    );
    this->mCurrencyPacks->addObject(CCVirtualCurrencyPack::create(
                                                                  CCString::create(""),
                                                                  CCString::create(""),
                                                                  CCString::create(Options::IN_APP_KEYS_PACK_1_ID),
                                                                  CCInteger::create(0),
                                                                  CCString::create(""),
                                                                  CCPurchaseWithMarket::create(CCString::create(Options::IN_APP_KEYS_PACK_1_ID), CCDouble::create(0.99))
                                                                  )
                                    );
    this->mCurrencyPacks->addObject(CCVirtualCurrencyPack::create(
                                                                  CCString::create(""),
                                                                  CCString::create(""),
                                                                  CCString::create(Options::IN_APP_KEYS_PACK_2_ID),
                                                                  CCInteger::create(0),
                                                                  CCString::create(""),
                                                                  CCPurchaseWithMarket::create(CCString::create(Options::IN_APP_KEYS_PACK_2_ID), CCDouble::create(3.99))
                                                                  )
                                    );
    this->mCurrencyPacks->addObject(CCVirtualCurrencyPack::create(
                                                                  CCString::create(""),
                                                                  CCString::create(""),
                                                                  CCString::create(Options::IN_APP_RESTORE_LIVES_ID),
                                                                  CCInteger::create(0),
                                                                  CCString::create(""),
                                                                  CCPurchaseWithMarket::create(CCString::create(Options::IN_APP_RESTORE_LIVES_ID), CCDouble::create(0.99))
                                                                  )
                                    );
    #endif
    
    
    return true;
}

InAppPurchasesList::~InAppPurchasesList() {
    CC_SAFE_RELEASE(mCurrencies);
    CC_SAFE_RELEASE(mGoods);
    CC_SAFE_RELEASE(mCurrencyPacks);
    CC_SAFE_RELEASE(mCategories);
    CC_SAFE_RELEASE(mNonConsumableItems);
}

int InAppPurchasesList::getVersion() {
    return 0;
}

cocos2d::CCArray *InAppPurchasesList::getCurrencies() {
    return mCurrencies;
}

cocos2d::CCArray *InAppPurchasesList::getGoods() {
    return mGoods;
}

cocos2d::CCArray *InAppPurchasesList::getCurrencyPacks() {
    return mCurrencyPacks;
}

cocos2d::CCArray *InAppPurchasesList::getCategories() {
    return mCategories;
}

cocos2d::CCArray *InAppPurchasesList::getNonConsumableItems() {
    return mNonConsumableItems;
}

#endif