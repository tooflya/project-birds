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
int Shop::ITEMS_COUNT[3] = { 11, 8, 5 };
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
    CC_SAFE_RELEASE_NULL(this->mBuyItemPopup);
    CC_SAFE_RELEASE_NULL(this->mGetCoinsPopup);
    CC_SAFE_RELEASE_NULL(this->mGetLivesPopup);
    CC_SAFE_RELEASE_NULL(this->mGetKeysPopup);
    CC_SAFE_RELEASE_NULL(this->mBoughtItem);
    CC_SAFE_RELEASE_NULL(this->mPaymentProceed);
    CC_SAFE_RELEASE_NULL(this->mPurchaseCoins);
    CC_SAFE_RELEASE_NULL(this->mPurchaseSilverCoins);
    CC_SAFE_RELEASE_NULL(this->mPurchaseLives);
    CC_SAFE_RELEASE_NULL(this->mPurchaseKeys);
    
    CC_SAFE_RELEASE_NULL(this->mWeaponChecker);
}

Shop::Shop()
{
    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas2");
    this->mSpriteBatch2 = SpriteBatch::create("TextureAtlas5");
    
    this->addChild(this->mSpriteBatch1);
    this->addChild(this->mSpriteBatch2);

    this->mBackground = Entity::create("settings_bg@2x.png", this->mSpriteBatch1);
    this->mBackgroundDecorations[0] = Entity::create("bg_detail_stripe@2x.png", this->mSpriteBatch1);
    this->mBackgroundDecorations[1] = Entity::create("bg_detail_stripe@2x.png", this->mSpriteBatch1);
    
    this->mBackground->setBlendFunc((ccBlendFunc){GL_ONE, GL_ZERO});
    
    this->mPurchaseCoins = EntityManager::create(50, AnimatedCoin::create("coins@2x.png", 1.6), this->mSpriteBatch2, 3);
    this->mPurchaseSilverCoins = EntityManager::create(50, AnimatedCoin::create("coins_silver@2x.png", 1.6), this->mSpriteBatch2, 3);
    this->mPurchaseLives = EntityManager::create(50, LiveParticle::create(), this->mSpriteBatch2, 3);
    this->mPurchaseKeys = EntityManager::create(50, KeyParticle::create(), this->mSpriteBatch2, 3);

    this->mGamePanel = Entity::create("shop_panel@2x.png", this->mSpriteBatch2);

    this->mTextBackgrounds[0] = Entity::create("shop_panel_textbox@2x.png", this->mSpriteBatch2);
    this->mTextBackgrounds[1] = Entity::create("shop_panel_textbox@2x.png", this->mSpriteBatch2);
    this->mTextBackgrounds[2] = Entity::create("shop_panel_textbox@2x.png", this->mSpriteBatch2);
    this->mTextBackgrounds[3] = Entity::create("shop_panel_textbox@2x.png", this->mSpriteBatch2);
    
    this->mTextBackgrounds[1]->setScaleX(0.9);
    this->mTextBackgrounds[2]->setScaleX(0.8);
    this->mTextBackgrounds[3]->setScaleX(0.8);
    
    if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPHONE4)
    {
        this->mTextBackgrounds[0]->setScaleX(this->mTextBackgrounds[0]->getScaleX() + 0.2);
        this->mTextBackgrounds[1]->setScaleX(this->mTextBackgrounds[1]->getScaleX() + 0.2);
        this->mTextBackgrounds[2]->setScaleX(this->mTextBackgrounds[2]->getScaleX() + 0.2);
        this->mTextBackgrounds[3]->setScaleX(this->mTextBackgrounds[3]->getScaleX() + 0.2);
    }
    
    this->mTextPluses[0] = Button::create((EntityStructure) {"game_panel_plus@2x.png", 1, 1, 0, 0, 78, 72}, this->mSpriteBatch2, Options::BUTTONS_ID_SHOP_GET_SILVER_COINS, this);
    this->mTextPluses[1] = Button::create((EntityStructure) {"game_panel_plus@2x.png", 1, 1, 0, 0, 78, 72}, this->mSpriteBatch2, Options::BUTTONS_ID_SHOP_GET_LIVES, this);
    this->mTextPluses[2] = Button::create((EntityStructure) {"game_panel_plus@2x.png", 1, 1, 0, 0, 78, 72}, this->mSpriteBatch2, Options::BUTTONS_ID_SHOP_GET_GOLD_COINS, this);
    this->mTextPluses[3] = Button::create((EntityStructure) {"game_panel_plus@2x.png", 1, 1, 0, 0, 78, 72}, this->mSpriteBatch2, Options::BUTTONS_ID_SHOP_GET_KEYS, this);
    
    this->mIcons[0] = Entity::create("coins_silver@2x.png", 5, 4, this->mSpriteBatch2);
    this->mIcons[1] = Entity::create("coins@2x.png", 5, 4, this->mSpriteBatch2);
    this->mIcons[2] = Entity::create("game_panel_goldlife@2x.png", this->mSpriteBatch2);
    this->mIcons[3] = Entity::create("popup_key_ico@2x.png", this->mSpriteBatch2);
    
    this->mTextText[0] = Text::create((Textes) {"0", Options::FONT, 32, -1}, this);
    this->mTextText[1] = Text::create((Textes) {"0", Options::FONT, 32, -1}, this);
    this->mTextText[2] = Text::create((Textes) {"0", Options::FONT, 32, -1}, this);
    this->mTextText[3] = Text::create((Textes) {"0", Options::FONT, 32, -1}, this);
    
    this->mGamePanel->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mTextBackgrounds[0]->create()->setCenterPosition(this->mTextBackgrounds[0]->getWidth() / 2 + Utils::coord(25), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    this->mTextBackgrounds[1]->create()->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + this->mTextBackgrounds[0]->getWidth() + Utils::coord(25), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    this->mTextBackgrounds[2]->create()->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + this->mTextBackgrounds[1]->getWidth() + Utils::coord(25), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    this->mTextBackgrounds[3]->create()->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidth() + Utils::coord(25), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mTextBackgrounds[2]->setCenterPosition(this->mTextBackgrounds[2]->getCenterX(), this->mTextBackgrounds[2]->getCenterY());
    this->mTextBackgrounds[3]->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() - Utils::coord(10), this->mTextBackgrounds[3]->getCenterY());
    
    if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPHONE4)
    {
        this->mTextBackgrounds[0]->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + Utils::coord(30), this->mTextBackgrounds[0]->getCenterY());
        this->mTextBackgrounds[1]->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + Utils::coord(60), this->mTextBackgrounds[1]->getCenterY());
        this->mTextBackgrounds[2]->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + Utils::coord(95), this->mTextBackgrounds[2]->getCenterY());
        this->mTextBackgrounds[3]->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() + Utils::coord(120), this->mTextBackgrounds[3]->getCenterY());
    }
    
    this->mTextPluses[0]->create()->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + this->mTextBackgrounds[0]->getWidthScaled() / 2, this->mTextBackgrounds[0]->getCenterY());
    this->mTextPluses[2]->create()->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + this->mTextBackgrounds[1]->getWidthScaled() / 2, this->mTextBackgrounds[1]->getCenterY());
    this->mTextPluses[1]->create()->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() / 2, this->mTextBackgrounds[2]->getCenterY());
    this->mTextPluses[3]->create()->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() + this->mTextBackgrounds[3]->getWidthScaled() / 2, this->mTextBackgrounds[3]->getCenterY());
    
    this->mIcons[0]->create()->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() - this->mTextBackgrounds[0]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[0]->getCenterY());
    this->mIcons[1]->create()->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() - this->mTextBackgrounds[1]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[1]->getCenterY());
    this->mIcons[2]->create()->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() - this->mTextBackgrounds[2]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[2]->getCenterY());
    this->mIcons[3]->create()->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() - this->mTextBackgrounds[3]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[3]->getCenterY());
    
    //this->mCoin = Entity::create("coins@2x.png", 5, 4, spriteBatch2);
    this->mBackButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, this->mSpriteBatch1, Options::BUTTONS_ID_SHOP_BACK, this);
    
    for(int i = 0; i < 9; i++)
    {
        this->mWheels[i] = Entity::create("shop_wheel@2x.png", this->mSpriteBatch2);
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
            Entity* shelf = Entity::create("shop_shelf_sprite@2x.png", 1, 2, this->mSpriteBatch2);
            
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
            Entity* item = Item::create(this);
            this->mItems[t++] = item;
            this->mSpriteBatch2->addChild(item);
            
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

    this->mIcons[0]->setRotation(-45);
    this->mIcons[0]->setScale(0.75);
    this->mIcons[0]->animate(0.05);
    
    this->mIcons[1]->setRotation(-45);
    this->mIcons[1]->setScale(0.75);
    this->mIcons[1]->animate(0.05);
    
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
    this->mGetLivesPopup = GetLives::create(this);
    this->mGetKeysPopup = GetKeys::create(this);
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
                    else if(ACTION == 2)
                    {
                        AppDelegate::screens->set(0.5, Screen::SCREEN_LEVELS);
                    }
                    else if(ACTION == 3)
                    {
                        AppDelegate::screens->set(0.5, Screen::SCREEN_MODE);
                    }
                    else if(ACTION == 4)
                    {
                        AppDelegate::screens->set(0.5, Screen::SCREEN_LEVELS);
                    }

                    ACTION = -1;

                break;
                case Options::BUTTONS_ID_SHOP_ITEM:
                    
                    pSender->mBuyItemPopup->show();
                    
                break;
                case Options::BUTTONS_ID_SHOP_GET_SILVER_COINS:
                case Options::BUTTONS_ID_SHOP_GET_GOLD_COINS:
                    
                    pSender->mGetCoinsPopup->show();
                    
                break;
                case Options::BUTTONS_ID_SHOP_GET_LIVES:
                    
                    //if(pSender->mTextPluses[1]->getOpacity() == 255)
                    {
                        pSender->mGetLivesPopup->show();
                    }
                    break;
                case Options::BUTTONS_ID_SHOP_GET_KEYS:
                    
                     pSender->mGetKeysPopup->show();
                    
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

            AppDelegate::removeCoins(Options::SHOP_ITEMS_PRICES[pItemId], Options::SAVE_DATA_COINS_TYPE_SILVER);
            AppDelegate::removeCoins(Options::SHOP_ITEMS_PRICES_GOLD[pItemId], Options::SAVE_DATA_COINS_TYPE_GOLD);
            
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
                
                AppDelegate::addCoins(1000, Options::SAVE_DATA_COINS_TYPE_SILVER);
                AppDelegate::addCoins(25, Options::SAVE_DATA_COINS_TYPE_GOLD);
            break;
            case 1:
                this->mIsAnimationPurchaseTime = 7.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.15;
                
                AppDelegate::addCoins(5000, Options::SAVE_DATA_COINS_TYPE_SILVER);
                AppDelegate::addCoins(150, Options::SAVE_DATA_COINS_TYPE_GOLD);
            break;
            case 2:
                this->mIsAnimationPurchaseTime = 10.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.1;
                
                AppDelegate::addCoins(15000, Options::SAVE_DATA_COINS_TYPE_SILVER);
                AppDelegate::addCoins(500, Options::SAVE_DATA_COINS_TYPE_GOLD);
            break;
            case 3:
                this->mIsAnimationPurchaseTime = 15.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.05;
                
                AppDelegate::addCoins(50000, Options::SAVE_DATA_COINS_TYPE_SILVER);
                AppDelegate::addCoins(2000, Options::SAVE_DATA_COINS_TYPE_GOLD);
            break;
            case 4:
                this->mIsAnimationPurchaseTime = 3.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.1;
                
                AppDelegate::addCoins(10, Options::SAVE_DATA_COINS_TYPE_LIVES);
            break;
            case 5:
                this->mIsAnimationPurchaseTime = 5.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.05;
                
                AppDelegate::addCoins(25, Options::SAVE_DATA_COINS_TYPE_LIVES);
            break;
            case 6:
                this->mIsAnimationPurchaseTime = 3.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.1;
                
                AppDelegate::addCoins(50, Options::SAVE_DATA_COINS_TYPE_KEYS);
            break;
            case 7:
                this->mIsAnimationPurchaseTime = 5.0;
                this->mIsAnimationPurchaseTimeEpisode = 0.05;
                
                AppDelegate::addCoins(200, Options::SAVE_DATA_COINS_TYPE_KEYS);
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

    int realGoldCoinsCount = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_GOLD);
    int realSilverCoinsCount = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_SILVER);
    int realLivesCoinsCount = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES);
    int realKeysCoinsCount = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_KEYS);

    if(realSilverCoinsCount != this->mPanelItems[0])
    {
        int c = 1;

        if(abs(realSilverCoinsCount - this->mPanelItems[0]) > 1111)
        {
            c = 111;
        }
        else if(abs(realSilverCoinsCount - this->mPanelItems[0]) > 111)
        {
            c = 11;
        }
        else if(abs(realSilverCoinsCount - this->mPanelItems[0]) > 1111)
        {
            c = 111;
        }
        else if(abs(realSilverCoinsCount - this->mPanelItems[0]) > 11111)
        {
            c = 1111;
        }
        else if(abs(realSilverCoinsCount - this->mPanelItems[0]) > 111111)
        {
            c = 11111;
        }

        this->mPanelItems[0] += realSilverCoinsCount < this->mPanelItems[0] ? -c : c;

        this->mTextText[0]->setString(Utils::intToString(this->mPanelItems[0]).c_str());
        this->mTextText[0]->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + this->mTextBackgrounds[0]->getWidth() / 2 - this->mTextText[0]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[0]->getCenterY());
    }
    
    if(realGoldCoinsCount != this->mPanelItems[1])
    {
        int c = 1;
        
        if(abs(realGoldCoinsCount - this->mPanelItems[1]) > 111)
        {
            c = 11;
        }
        
        this->mPanelItems[1] += realGoldCoinsCount < this->mPanelItems[1] ? -c : c;
        
        this->mTextText[1]->setString(Utils::intToString(this->mPanelItems[1]).c_str());
        this->mTextText[1]->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + this->mTextBackgrounds[1]->getWidthScaled() / 2 - this->mTextText[1]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[1]->getCenterY());
    }
    
    if(realLivesCoinsCount != this->mPanelItems[2])
    {
        int c = 1;
        
        this->mPanelItems[2] += realLivesCoinsCount < this->mPanelItems[2] ? -c : c;
        
        this->mTextText[2]->setString(Utils::intToString(this->mPanelItems[2]).c_str());
        this->mTextText[2]->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() / 2 - this->mTextText[2]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[2]->getCenterY());
    }
    
    if(realKeysCoinsCount != this->mPanelItems[3])
    {
        int c = 1;
        
        this->mPanelItems[3] += realKeysCoinsCount < this->mPanelItems[3] ? -c : c;
        
        this->mTextText[3]->setString(Utils::intToString(this->mPanelItems[3]).c_str());
        this->mTextText[3]->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() + this->mTextBackgrounds[3]->getWidthScaled() / 2 - this->mTextText[3]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[3]->getCenterY());
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

            switch(PURCHASE_ID)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                    // Coins
                    if(Utils::probably(10 * (PURCHASE_ID + 1)))
                    {
                        this->mPurchaseCoins->create();
                    }
                    else
                    {
                        this->mPurchaseSilverCoins->create();
                    }
                break;
                case 4:
                case 5:
                    // Hearts
                    this->mPurchaseLives->create();
                break;
                case 6:
                case 7:
                    // Keys
                    this->mPurchaseKeys->create();
                break;
            }
        }
    }

    //this->mCoinsCountText->setScale(this->mTablet->getScaleX());
    //this->mCoin->setScale(this->mTablet->getScaleX() + 0.3);
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

    this->mPanelItems[0] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_SILVER);
    this->mPanelItems[1] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_GOLD);
    this->mPanelItems[2] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES);
    this->mPanelItems[3] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_KEYS);
    
    this->mWeaponChecker->removeFromParentAndCleanup(false);
    
    int id = AppDelegate::getSelectedWeaponId();
    this->mItems[id]->addChild(this->mWeaponChecker);
    this->mWeaponChecker->setCenterPosition(this->mItems[id]->getWidth() / 2 + Utils::coord(72), this->mItems[id]->getHeight() / 2 - Utils::coord(72));
    
    this->mTextText[0]->setString(Utils::intToString(this->mPanelItems[0]).c_str());
    this->mTextText[0]->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + this->mTextBackgrounds[0]->getWidthScaled() / 2 - this->mTextText[0]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[0]->getCenterY());
    
    this->mTextText[1]->setString(Utils::intToString(this->mPanelItems[1]).c_str());
    this->mTextText[1]->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + this->mTextBackgrounds[1]->getWidthScaled() / 2 - this->mTextText[1]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[1]->getCenterY());
    
    this->mTextText[2]->setString(Utils::intToString(this->mPanelItems[2]).c_str());
    this->mTextText[2]->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() / 2 - this->mTextText[2]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[2]->getCenterY());
    
    this->mTextText[3]->setString(Utils::intToString(this->mPanelItems[3]).c_str());
    this->mTextText[3]->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() + this->mTextBackgrounds[3]->getWidthScaled() / 2 - this->mTextText[3]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[3]->getCenterY());
    
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
    this->mPurchaseSilverCoins->clear();
    this->mPurchaseLives->clear();
    this->mPurchaseKeys->clear();
}

void Shop::draw()
{
    Screen::draw();
}

void Shop::visit()
{
    
    Screen::visit();
}

void Shop::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
    
    if(ACTION == 2)
    {
        this->mGetKeysPopup->show();
    }
    else if(ACTION == 3 || ACTION == 4)
    {
        this->mPaymentProceed->show();
    }
}

#endif