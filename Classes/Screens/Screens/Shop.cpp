#ifndef CONST_SHOP
#define CONST_SHOP

#include "Shop.h"

// ===========================================================
// Inner Classes
// ===========================================================

class TouchLayer : public CCLayer
{
    protected:
    int mId;

    int mItemsCount;

    float mMaxWidth;
    
    float mStartCoordinateX;
    float mStartPositionCoordinateX;

    float mStartTime; // ?

    float mPostUpdatePower;

    bool mPostUpdate;
    
    public:
    TouchLayer(const int pId, int pItemsCount)
    {
        this->init();
        
        this->scheduleUpdate();

        this->mId = pId;
        this->mItemsCount = pItemsCount;

        this->mMaxWidth = Utils::coord(230) * (this->mItemsCount - 3);

        this->mPostUpdate = false;
    }
    
    static TouchLayer* create(const int pId, int pItemsCount)
    {
        TouchLayer* layer = new TouchLayer(pId, pItemsCount);
        //layer->autorelease();
        
        return layer;
    }
    
    bool ccTouchBegan(CCTouch* touch, CCEvent* event)
    {
        this->mPostUpdate = false;

        this->mStartCoordinateX = touch->getLocation().x;
        this->mStartPositionCoordinateX = this->getPosition().x;
        
        return this->containsTouchLocation(touch);
    }
    
    void ccTouchMoved(CCTouch* touch, CCEvent* event)
    {
        if(this->containsTouchLocation(touch))
        {
            float x = this->mStartPositionCoordinateX + touch->getLocation().x - this->mStartCoordinateX;

            if(x > 0)
            {
            }
            else if(x < -this->mMaxWidth)
            {
            }
            else
            {
                this->setPosition(ccp(x, this->getPosition().y));
            }
        }
    }
    
    void ccTouchEnded(CCTouch* touch, CCEvent* event)
    {
        float x = this->getPosition().x;

        if(x > 0)
        {
            this->runAction(CCMoveTo::create(0.3, ccp(0, this->getPosition().y)));
        }
        else if(x < -this->mMaxWidth)
        {
            this->runAction(CCMoveTo::create(0.3, ccp(-this->mMaxWidth, this->getPosition().y)));
        }
        else
        {
            float distance = (this->mStartCoordinateX - touch->getLocation().x) / 10.0;
            
            //if(abs(distance) < Utils::coord(10.0)) return;
                
            int t = distance > 0 ? 1 : -1;

            this->mPostUpdatePower = abs(floor(distance)) > Utils::coord(30.0) ? Utils::coord(30.0) * t : floor(distance);

            this->mPostUpdate = true;
        }
    }
    
    bool containsTouchLocation(CCTouch* touch)
    {
        float y = touch->getLocation().y;
        
        switch(this->mId)
        {
            case 0:
                if(
                   y < Options::CAMERA_CENTER_Y + Utils::coord(300) + Utils::coord(150) &&
                   y > Options::CAMERA_CENTER_Y + Utils::coord(300) - Utils::coord(100))
                    {
                        return true;
                    }
                break;
            case 1:
                if(
                   y < Options::CAMERA_CENTER_Y + Utils::coord(150) &&
                   y > Options::CAMERA_CENTER_Y - Utils::coord(100))
                    {
                        return true;
                    }
                break;
            case 2:
                if(
                   y < Options::CAMERA_CENTER_Y - Utils::coord(300) + Utils::coord(150) &&
                   y > Options::CAMERA_CENTER_Y - Utils::coord(300) - Utils::coord(100))
                    {
                        return true;
                    }
                break;
        }
        
        return false;
    }

    void update(float pDeltaTime)
    {
        CCLayer::update(pDeltaTime);
        
        this->updateWheels();

        if(this->mPostUpdate)
        {
            float x = this->getPosition().x - this->mPostUpdatePower;
            
            if(x >= 0) x = 0;
            if(x <= -this->mMaxWidth) x = -this->mMaxWidth;


            this->setPosition(ccp(x, this->getPosition().y));

            this->mPostUpdatePower = this->mPostUpdatePower > 0 ? this->mPostUpdatePower - 1.0 : this->mPostUpdatePower + 1.0;

            if(abs(this->mPostUpdatePower) < Utils::coord(2.0))
            {
                int x = floor(this->getPosition().x);

                if(abs(x) % (int) floor(Utils::coord(230)) >= 5.0)
                {
                    this->mPostUpdatePower = this->mPostUpdatePower < 0 ? this->mPostUpdatePower - 1.0 : this->mPostUpdatePower + 1.0;
                }
                else
                {
                    this->mPostUpdatePower = 0;
                }
            }

            if(this->mPostUpdatePower == 0)
            {
                this->mPostUpdate = false;
            }
        }
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
        
        CCLayer::onEnter();
    }
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        CCLayer::onExit();
    }

    void updateWheels()
    {
        for(int i = this->mId * 3; i < this->mId * 3 + 3; i++)
        {
            Entity* wheel = (Entity*) ((Shop*) this->getParent())->mWheels[i];
                
            wheel->setRotation(this->getPosition().x);
        }
    }

    void setPosition(CCPoint pPosition)
    {
        float x = pPosition.x - this->getPosition().x;
        float y = 0;//pPosition.y - this->getPosition().y;

        CCLayer::setPosition(pPosition);

        Shop* shop = static_cast<Shop*>(this->getParent());
        
        for(int i = 0; i < 5; i++)
        {
            Entity* en = shop->mShelfs[5 * this->mId + i];

            en->setCenterPosition(en->getPosition().x + x, en->getPosition().y + y);
        }

        int t = 0;
        if(this->mId == 1)
            t = Shop::ITEMS_COUNT[0];
        if(this->mId == 2)
            t = Shop::ITEMS_COUNT[0] + Shop::ITEMS_COUNT[1];
        
        int l = t;
        
        for(int i = t; i < l + Shop::ITEMS_COUNT[this->mId]; i++)
        {
            Entity* en = shop->mItems[t++];
            
            en->setCenterPosition(en->getPosition().x + x, en->getPosition().y + y);
        }
    }
};

// ===========================================================
// Constants
// ===========================================================

Shop* Shop::m_Instance = NULL;

int Shop::CLICKED_ITEM_ID = -1;
int Shop::ITEMS_COUNT[3] = { 11, 9, 5 };
int Shop::ACTION = -1;
int Shop::PURCHASE_ID = -1;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Shop::~Shop()
{
    this->mBuyItemPopup->release();
    this->mGetCoinsPopup->release();
    this->mBoughtItem->release();
    this->mPaymentProceed->release();
    
    this->mPurchaseCoins->release();
    
    this->mWeaponChecker->release();
}

Shop::Shop()
{
    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas2.png");
    CCSpriteBatchNode* spriteBatch2 = CCSpriteBatchNode::create("TextureAtlas5.png");

    this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
    this->mBackgroundDecorations[0] = Entity::create("bg_detail_stripe@2x.png", spriteBatch);
    this->mBackgroundDecorations[1] = Entity::create("bg_detail_stripe@2x.png", spriteBatch);

    this->addChild(spriteBatch);
    this->addChild(spriteBatch2);
    
    this->mPurchaseCoins = EntityManager::create(50, AnimatedCoin::create(), spriteBatch2, 3);

    this->mTablet = Button::create("shop_money_bg@2x.png", 1, 1, spriteBatch2, Options::BUTTONS_ID_SHOP_TABLET, onTouchButtonsCallback);
    this->mCoin = Entity::create("coins@2x.png", 5, 4, spriteBatch2);
    this->mBackButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, spriteBatch, Options::BUTTONS_ID_SHOP_BACK, onTouchButtonsCallback);

    this->mCoinsCountText = Text::create((Textes) {"0", Options::FONT, 64, -1}, this);
    
    for(int i = 0; i < 9; i++)
    {
        this->mWheels[i] = Entity::create("shop_wheel@2x.png", spriteBatch2);
    }
    
    float x = Options::CAMERA_CENTER_X;
    float y = Options::CAMERA_CENTER_Y - Utils::coord(100) + Utils::coord(330);
    
    this->mWeaponChecker = NULL;
    
    int t = 0;
    for(int i = 0; i < 3; i++)
    {
        int itemID = 20 * i - 1;

        this->mLayersA[i + 1] = TouchLayer::create(i, ITEMS_COUNT[i]);
        
        this->addChild(this->mLayersA[i + 1], 2);
        
        for(int j = -1; j < 5; j++)
        {
            Entity* shelf = Entity::create("shop_shelf_sprite@2x.png", 1, 2, spriteBatch2);
            
            this->mShelfs[5 * i + (j + 1)] = shelf;
            shelf->create()->setCenterPosition(x + shelf->getWidth() * j - Utils::coord(42) * j, y);
            
            if(j == 0)
            {
                Text* text = Text::create(Options::TEXT_SHOP_DESCRIPTION[i], this->mLayersA[i + 1]);
                text->setCenterPosition(shelf->getCenterX() - shelf->getWidth() / 2 + Utils::coord(180), shelf->getCenterY());
                
                shelf->setCurrentFrameIndex(0);
            }
            else
            {
                shelf->setCurrentFrameIndex(1);
            }
        }
        
        for(int j = 0; j < ITEMS_COUNT[i]; j++)
        {
            Entity* item = Item::create(onTouchButtonsCallback);
            this->mItems[t++] = item;
            spriteBatch2->addChild(item);
            
            item->create()->setCenterPosition(Utils::coord(130) + Utils::coord(230) * j, y + Utils::coord(115));
            item->setCurrentFrameIndex(++itemID);

            if(i == 0)
            {
                if(AppDelegate::isItemSelected(j) && this->mWeaponChecker == NULL)
                {
                    this->mWeaponChecker = Entity::create("shop_weapon_check@2x.png", item);this->mWeaponChecker->retain();
                    this->mWeaponChecker->create()->setCenterPosition(item->getWidth() / 2 + Utils::coord(64), item->getHeight() / 2 - Utils::coord(64));
                    
                    Options::SELECTED_WEAPON_ID = itemID;
                }
            }
        }
        
        y -= Utils::coord(300);
    }
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));

    this->mTablet->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(110));

    this->mCoin->create()->setCenterPosition(this->mTablet->getCenterX() - Utils::coord(105), this->mTablet->getCenterY());
    this->mCoin->setRotation(-45);
    this->mCoin->setScale(1.3);
    this->mCoin->animate(0.05);
    
    this->mCoinsCountText->setCenterPosition(this->mTablet->getCenterX() - Utils::coord(70) + this->mCoinsCountText->getWidth() / 2, this->mTablet->getCenterY());
    
    x = Options::CAMERA_CENTER_X - Utils::coord(500);
    y = Options::CAMERA_CENTER_Y - Utils::coord(100) + Utils::coord(300);
    
    for(int i = 0; i < 9; i++)
    {
        if(i % 3 == 0 && i != 0)
        {
            x = Options::CAMERA_CENTER_X - Utils::coord(250);
            y -= Utils::coord(300);
        }
        else
        {
            x += Utils::coord(250);
        }
        
        this->mWheels[i]->create()->setCenterPosition(x, y);
    }
    
    this->mBackgroundDecorations[0]->create()->setCenterPosition(Utils::coord(192), Options::CAMERA_HEIGHT - Utils::coord(103));
    this->mBackgroundDecorations[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(192), Utils::coord(103));
    
    this->mBackgroundDecorations[1]->setScale(-1);

    this->mBuyItemPopup = BuyItem::create(this);
    this->mGetCoinsPopup = GetCoins::create(this);
    this->mBoughtItem = BoughtItem::create(this);
    this->mPaymentProceed = PaymentProceed::create(this);
    
    this->mIsAnimationOnItemBoughtRunning = false;
    this->mIsAnimationPurchaseRunning = false;

    m_Instance = this;
}

Shop* Shop::create()
{
    Shop* screen = new Shop();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Shop::onTouchButtonsCallback(const int pAction, const int pID)
{
    Shop* pSender = static_cast<Shop*>(Shop::m_Instance);

    if(pSender->mIsAnimationOnItemBoughtRunning) return;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_SHOP_BACK:

                    if(ACTION == 0)
                    {
                        AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);
                    }
                    else if(ACTION == 1)
                    {
                        AppDelegate::screens->set(0.5, Screen::SCREEN_MODE);
                    }

                    ACTION = -1;

                break;
                case Options::BUTTONS_ID_SHOP_ITEM:
                    
                    pSender->mBuyItemPopup->show();
                    
                break;
                case Options::BUTTONS_ID_SHOP_TABLET:
                    
                    pSender->mGetCoinsPopup->show();
                    
                break;
            }
        break;

        case Options::BUTTONS_ACTION_ONBEGIN:
        break;

        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void Shop::onItemBought(int pItemId)
{  
    if(pItemId < 20)
    {
        if(AppDelegate::isItemBought(pItemId))
        {
            AppDelegate::selectItem(pItemId);
            
            if(Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_EQUIP_SWORD);
            }

            this->mWeaponChecker->removeFromParentAndCleanup(false);

            this->mItems[pItemId]->addChild(this->mWeaponChecker);
            this->mWeaponChecker->setCenterPosition(this->mItems[pItemId]->getWidth() / 2 + Utils::coord(72), this->mItems[pItemId]->getHeight() / 2 - Utils::coord(72));
            
            Options::SELECTED_WEAPON_ID = pItemId;
        }
        else
        {
            this->mIsAnimationOnItemBoughtRunning = true;

            this->mAnimationOnItemBoughtTime = 3.0;
            this->mAnimationOnItemBoughtTimeElapsed = 0;

            this->mBoughtItem->show(pItemId);

            AppDelegate::removeCoins(Options::SHOP_ITEMS_PRICES[pItemId], Options::SAVE_DATA_COINS_TYPE_GOLD);
            AppDelegate::buyItem(pItemId);
            
            if(pItemId < 30)
            {
                this->onItemBought(pItemId);
            }
            
            if(Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_UNLOCKED);
            }
        }
    }
    else
    {
        this->mIsAnimationOnItemBoughtRunning = true;

        this->mAnimationOnItemBoughtTime = 3.0;
        this->mAnimationOnItemBoughtTimeElapsed = 0;

        this->mBoughtItem->show(pItemId);

        AppDelegate::removeCoins(Options::SHOP_ITEMS_PRICES[pItemId], Options::SAVE_DATA_COINS_TYPE_GOLD);
        AppDelegate::buyItem(pItemId);
        
        if(Options::SOUND_ENABLE)
        {
            SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_UNLOCKED);
        }
    }
}

void Shop::onPurchase(bool pProceed)
{
    if(pProceed)
    {
        this->mPaymentProceed->hide();

        switch(PURCHASE_ID)
        {
            case 0:
                this->mIsAnimationPurchaseTime = 5.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.2;
                
                AppDelegate::addCoins(1000, Options::SAVE_DATA_COINS_TYPE_GOLD);
            break;
            case 1:
                this->mIsAnimationPurchaseTime = 7.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.15;
                
                AppDelegate::addCoins(5000, Options::SAVE_DATA_COINS_TYPE_GOLD);
            break;
            case 2:
                this->mIsAnimationPurchaseTime = 10.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.1;
                
                AppDelegate::addCoins(15000, Options::SAVE_DATA_COINS_TYPE_GOLD);
            break;
            case 3:
                this->mIsAnimationPurchaseTime = 15.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.05;
                
                AppDelegate::addCoins(50000, Options::SAVE_DATA_COINS_TYPE_GOLD);
            break;
        }

        this->mIsAnimationPurchaseRunning = true;
        this->mIsAnimationPurchaseTimeElapsed = 0;
    }
    else
    {
        this->mPaymentProceed->show();
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Shop::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);

    if(this->mIsAnimationOnItemBoughtRunning)
    {
        this->mAnimationOnItemBoughtTimeElapsed += pDeltaTime;

        if(this->mAnimationOnItemBoughtTimeElapsed >= this->mAnimationOnItemBoughtTime)
        {
            this->mAnimationOnItemBoughtTimeElapsed = 0;
            this->mIsAnimationOnItemBoughtRunning = false;

            //this->mBoughtItem->hide();
        }
    }

    /** Coins animation */

    int realCoinsCount = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_GOLD);

    if(realCoinsCount != this->mCoins)
    {
        int c = 1;

        if(abs(realCoinsCount - this->mCoins) > 1111)
        {
            c = 111;
        }
        else if(abs(realCoinsCount - this->mCoins) > 111)
        {
            c = 11;
        }
        else if(abs(realCoinsCount - this->mCoins) > 1111)
        {
            c = 111;
        }
        else if(abs(realCoinsCount - this->mCoins) > 11111)
        {
            c = 1111;
        }
        else if(abs(realCoinsCount - this->mCoins) > 111111)
        {
            c = 11111;
        }

        this->mCoins += realCoinsCount < this->mCoins ? -c : c;

        this->mCoinsCountText->setString(Utils::intToString(this->mCoins).c_str());
        this->mCoinsCountText->setCenterPosition(this->mTablet->getCenterX() - Utils::coord(70) + this->mCoinsCountText->getWidth() / 2, this->mTablet->getCenterY());
    }

    /** Purchase animation **/

    if(this->mIsAnimationPurchaseRunning)
    {
        this->mIsAnimationPurchaseTimeElapsed += pDeltaTime;
        this->mIsAnimationPurchaseTimeEpisodeElapsed += pDeltaTime;

        if(this->mIsAnimationPurchaseTimeElapsed >= this->mIsAnimationPurchaseTime)
        {
            this->mIsAnimationPurchaseTimeElapsed = 0;

            this->mIsAnimationPurchaseRunning = false;
        }

        if(this->mIsAnimationPurchaseTimeEpisodeElapsed >= this->mIsAnimationPurchaseTimeEpisode)
        {
            this->mIsAnimationPurchaseTimeEpisodeElapsed = 0;

            this->mPurchaseCoins->create();
        }
    }

    this->mCoinsCountText->setScale(this->mTablet->getScaleX());
    this->mCoin->setScale(this->mTablet->getScaleX() + 0.3);
}

void Shop::onEnter()
{
    Screen::onEnter();
    
    int t = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < ITEMS_COUNT[i]; j++)
        {
            Entity* item = this->mItems[t++];
            
            item->runAction(CCMoveTo::create(0.0, ccp(item->getPosition().x + Utils::coord(1000), item->getPosition().y)));
            item->runAction(CCMoveTo::create(0.8 - 0.1 * i, ccp(item->getPosition().x - Utils::coord(1000), item->getPosition().y)));
        }
    }

    this->mCoins = 0;
    this->mCoins = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_GOLD);
    
    this->mWeaponChecker->removeFromParentAndCleanup(false);
    
    int id = AppDelegate::getSelectedWeaponId();
    this->mItems[id]->addChild(this->mWeaponChecker);
    this->mWeaponChecker->setCenterPosition(this->mItems[id]->getWidth() / 2 + Utils::coord(72), this->mItems[id]->getHeight() / 2 - Utils::coord(72));
    
    this->mCoinsCountText->setString(Utils::intToString(this->mCoins).c_str());
    this->mCoinsCountText->setCenterPosition(this->mTablet->getCenterX() - Utils::coord(70) + this->mCoinsCountText->getWidth() / 2, this->mTablet->getCenterY());
    
}

void Shop::onExit()
{
    Screen::onExit();
    
    for(int i = 1; i < 4; i++)
    {
        this->mLayersA[i]->setPosition(ccp(0, this->mLayersA[i]->getPosition().y));
    }
    
    this->mIsAnimationPurchaseRunning = false;
    this->mPurchaseCoins->clear();
}

#endif