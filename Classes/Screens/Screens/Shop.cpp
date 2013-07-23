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
        this->scheduleUpdate();

        this->mId = pId;
        this->mItemsCount = pItemsCount;

        this->mMaxWidth = Utils::coord(230) * (this->mItemsCount - 3);

        this->mPostUpdate = false;
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
            
            this->setPosition(ccp(x, this->getPosition().y));
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

                if(abs(x) % (int) floor(Utils::coord(230)) >= 1.0)
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
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
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
            Entity* wheel = (Entity*) ((Shop*) this->getParent())->mWheels->objectAtIndex(i);
                
            wheel->setRotation(this->getPosition().x);
        }
    }
};

// ===========================================================
// Constants
// ===========================================================

Shop* Shop::m_Instance = NULL;

int Shop::CLICKED_ITEM_ID = -1;

 int Shop::ITEMS_COUNT[3] = { 11, 4, 8 };

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Shop::Shop()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mTablet = new Button("shop_money_bg@2x.png", 1, 1, this, Options::BUTTONS_ID_SHOP_TABLET, onTouchButtonsCallback);
    this->mCoin = new Entity("coins@2x.png", 5, 4, this->mTablet);
    this->mBackButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_SHOP_BACK, onTouchButtonsCallback);

    this->mCoinsCountText = new Text((Textes) {"0", Options::FONT, Utils::coord(64), -1}, this->mTablet);
    
    this->mWheels = new BatchEntityManager(9, new Entity("shop_wheel@2x.png"), this);
    
    float x = Options::CAMERA_CENTER_X;
    float y = Options::CAMERA_CENTER_Y - Utils::coord(100) + Utils::coord(330);
    
    int itemID = -1;

    for(int i = 0; i < 3; i++)
    {
        this->mLayers[i] = new TouchLayer(i, ITEMS_COUNT[i]);
        
        this->addChild(this->mLayers[i], 2);
        
        this->mShelfs[i] = new EntityManager(2, new Entity("shop_shelf_sprite@2x.png", 1, 2), this->mLayers[i]);
        this->mItems[i] = new BatchEntityManager(10, new Item(onTouchButtonsCallback), this->mLayers[i]);
        
        for(int j = -1; j < 3; j++)
        {
            Entity* shelf = (Entity*) this->mShelfs[i]->create();
            
            shelf->setCenterPosition(x + shelf->getWidth() * j - Utils::coord(42) * j, y);
            
            if(j == 0)
            {
                Text* text = new Text(Options::TEXT_SHOP_DESCRIPTION[i], shelf);
                text->setCenterPosition(Utils::coord(180), shelf->getHeight() / 2);
                
                shelf->setCurrentFrameIndex(0);
            }
            else
            {
                shelf->setCurrentFrameIndex(1);
            }
        }
        
        for(int j = 0; j < ITEMS_COUNT[i]; j++)
        {
            Entity* item = (Entity*) this->mItems[i]->create();
            
            item->setCenterPosition(Utils::coord(130) + Utils::coord(230) * j, y + Utils::coord(115));
            item->setCurrentFrameIndex(++itemID);
        }
        
        y -= Utils::coord(300);
    }
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mBackButton->create()->setCurrentFrameIndex(1);
    this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));

    this->mTablet->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(110));

    this->mCoin->create()->setCenterPosition(this->mTablet->getWidth() / 2 - Utils::coord(100), this->mTablet->getHeight() / 2);
    this->mCoin->setRotation(-45);
    this->mCoin->setScale(1.3);
    this->mCoin->animate(0.05);

    this->mCoinsCountText->setCenterPosition(this->mTablet->getWidth() / 2 - Utils::coord(70) + this->mCoinsCountText->getWidth(), this->mTablet->getHeight() / 2);
    
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
        
        this->mWheels->create()->setCenterPosition(x, y);
    }
    
    /** Bought item animation **/

    this->mDarkness = new Entity("popup_darkness@2x.png");
    this->mLights = new EntityManager(2, new Entity("get_coins_light@2x.png"), this->mDarkness);
    this->mBoughtItemIcon = new Entity("shop_item_icon@2x.png", 10, 10, this->mDarkness);
    this->mBoughtText[0] = new Text(Options::TEXT_SHOP_BOUGHT, this->mDarkness);
    this->mBoughtText[1] = new Text(Options::TEXT_SHOP_BOUGHT, this->mDarkness);

    this->mDarkness->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBoughtItemIcon->create()->setCenterPosition(this->mDarkness->getWidth() / 2, this->mDarkness->getHeight() / 2);

    this->mBoughtText[0]->setCenterPosition(this->mDarkness->getWidth() / 2, this->mDarkness->getHeight() / 2 - Utils::coord(300));
    this->mBoughtText[1]->setCenterPosition(this->mDarkness->getWidth() / 2, this->mDarkness->getHeight() / 2 - Utils::coord(380));

    this->addChild(this->mDarkness, 10);
        
    for(int i = 0; i < 2; i++)
     {
        this->mLights->create()->setCenterPosition(this->mDarkness->getWidth() / 2, this->mDarkness->getHeight() / 2);
        ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
    }

    this->mDarkness->setAlphaParent(true);
    this->mDarkness->setOpacity(0.0);

    /** **/

    this->mBuyItemPopup = new BuyItem(this);
    this->mGetCoinsPopup = new GetCoins(this);
    
    this->mIsAnimationOnItemBoughtRunning = false;

    m_Instance = this;
}

// ===========================================================
// Methods
// ===========================================================

void Shop::onTouchButtonsCallback(const int pAction, const int pID)
{
    Shop* pSender = (Shop*) Shop::m_Instance;

    if(pSender->mIsAnimationOnItemBoughtRunning) return;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_SHOP_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);

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
    this->mIsAnimationOnItemBoughtRunning = true;

    this->mAnimationOnItemBoughtTime = 3.0;
    this->mAnimationOnItemBoughtTimeElapsed = 0;

    this->mBoughtText[0]->setString(Options::TEXT_SHOP_ITEMS[pItemId].string);

    this->mBoughtText[0]->setCenterPosition(this->mDarkness->getWidth() / 2, this->mDarkness->getHeight() / 2 - Utils::coord(300));
    this->mBoughtText[1]->setCenterPosition(this->mDarkness->getWidth() / 2, this->mDarkness->getHeight() / 2 - Utils::coord(380));

    this->mDarkness->runAction(CCFadeTo::create(0.5, 230));

    AppDelegate::removeCoins(Options::SHOP_ITEMS_PRICES[pItemId], Options::SAVE_DATA_COINS_TYPE_GOLD);
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

            this->mDarkness->runAction(CCFadeTo::create(0.5, 0.0));
        }
        
        for(int i = 0; i < 2; i++)
        {
            Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
            
            light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
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

        this->mCoins += realCoinsCount < this->mCoins ? -c : c;

        this->mCoinsCountText->setString(Utils::intToString(this->mCoins).c_str());
        this->mCoinsCountText->setCenterPosition(this->mTablet->getWidth() / 2 - Utils::coord(70) + this->mCoinsCountText->getWidth() / 2, this->mTablet->getHeight() / 2);
    }
}

void Shop::onEnter()
{
    Screen::onEnter();
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < this->mItems[i]->getCount(); j++)
        {
            Entity* item = (Entity*) this->mItems[i]->objectAtIndex(j);
            
            item->runAction(CCMoveTo::create(0.0, ccp(item->getPosition().x + Utils::coord(1000), item->getPosition().y)));
            item->runAction(CCMoveTo::create(0.8 - 0.1 * i, ccp(item->getPosition().x - Utils::coord(1000), item->getPosition().y)));
        }
    }

    this->mCoins = 0;
}

void Shop::onExit()
{
    Screen::onExit();
    
    for(int i = 0; i < 3; i++)
    {
        this->mLayers[i]->setPosition(ccp(0, this->mLayers[i]->getPosition().y));
    }
}

#endif