#ifndef CONST_END
#define CONST_END

#include "End.h"

#include "Game.h"
#include "Loader.h"
#include "Shop.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int End::ACTION = -1;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

End::~End()
{
    CC_SAFE_RELEASE(this->mConfetti);
    CC_SAFE_RELEASE(this->mStarsSplashes);
    CC_SAFE_RELEASE(this->mStars);
    CC_SAFE_RELEASE(this->mPanelLayer);
    CC_SAFE_RELEASE(this->mSpriteBatch7);
}

End::End(int pType, Screen* pParent) :
    Splash(pParent),
	mShopButton(0),
	mMenuButton(0),
	mRestartButton(0),
	mContinueButton(0),
	mStars(0),
	mConfetti(0),
	mAnimationCounter(0),
	mCoinsAnimationCounter(0),
	mCurrentCount(0),
	mBestCurrentCount(0),
	mFlayerCount(0),
	mComboCount(0),
	mCriticalCount(0),
	mEarnedCoins(0),
	mTotalEarnedCoins(0),
	mAnimationTime(0),
	mAnimationtimeElapsed(0),
	mCoinsAnimationTime(0),
	mCoinsAnimationTimeElapsed(0),
	mCoinsAnimationCurrentTime(0),
	mCoinsAnimationCurrentTimeElapsed(0),
	mIsAnimationRunning(0),
	mIsCoinsAnimationRunning(0),
    mSpriteBatch7(0),
	mIsCoinsAnimationCurrentRunning(0)
    {
        ACTION = 1;

        this->mType = pType;
        
        this->mScaleLayer = CCLayer::create();
        this->mScaleLayer->retain();
        
        this->mPanelLayer = CCLayer::create();
        this->mPanelLayer->retain();
        
        SpriteBatch* spriteBatch1 = SpriteBatch::create("TextureAtlas8");
        SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas7");
        SpriteBatch* spriteBatch3 = SpriteBatch::create("TextureAtlas8");
        SpriteBatch* spriteBatch4 = SpriteBatch::create("TextureAtlas7");
        SpriteBatch* spriteBatch5 = SpriteBatch::create("TextureAtlas6");
        this->mSpriteBatch7 = SpriteBatch::create("TextureAtlas7");
        this->mSpriteBatch7->retain();
        
        this->addChild(spriteBatch1);
        this->mScaleLayer->addChild(spriteBatch3);
        this->mScaleLayer->addChild(spriteBatch2, 2);
        this->mScaleLayer->addChild(spriteBatch4, 3);
        this->mPanelLayer->addChild(spriteBatch5, 4);
        this->mPanelLayer->addChild(this->mSpriteBatch7, 4);
        
        /////////////////////////
        
        this->mGamePanel = Entity::create("game_panel@2x.png", spriteBatch5);
        
		this->mTextBackgrounds[0] = Entity::create("shop_panel_textbox@2x.png", spriteBatch5);
		this->mTextBackgrounds[1] = Entity::create("shop_panel_textbox@2x.png", spriteBatch5);
		this->mTextBackgrounds[2] = Entity::create("shop_panel_textbox@2x.png", spriteBatch5);
		this->mTextBackgrounds[3] = Entity::create("shop_panel_textbox@2x.png", spriteBatch5);
        
		this->mTextBackgrounds[1]->setScaleX(0.9);
		this->mTextBackgrounds[2]->setScaleX(1.0);
		this->mTextBackgrounds[3]->setScaleX(0.8);
        
		if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPHONE4 || Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPOD4)
		{
			this->mTextBackgrounds[0]->setScaleX(this->mTextBackgrounds[0]->getScaleX() + 0.2);
			this->mTextBackgrounds[1]->setScaleX(this->mTextBackgrounds[1]->getScaleX() + 0.2);
			this->mTextBackgrounds[2]->setScaleX(this->mTextBackgrounds[2]->getScaleX() + 0.2);
			this->mTextBackgrounds[3]->setScaleX(this->mTextBackgrounds[3]->getScaleX() + 0.2);
		}
        
		if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_NEXUS3)
		{
			this->mTextBackgrounds[1]->setScaleX(this->mTextBackgrounds[1]->getScaleX() + 0.2);
			this->mTextBackgrounds[3]->setScaleX(this->mTextBackgrounds[3]->getScaleX() + 0.2);
		}
        
		EntityStructure structure1 = {"game_panel_plus@2x.png", 1, 1, 0, 0, 78, 72};
        
		this->mTextPluses[0] = Button::create(structure1, spriteBatch5, Options::BUTTONS_ID_SHOP_GET_SILVER_COINS, this);
		this->mTextPluses[1] = Button::create(structure1, spriteBatch5, Options::BUTTONS_ID_SHOP_GET_LIVES, this);
		this->mTextPluses[2] = Button::create(structure1, spriteBatch5, Options::BUTTONS_ID_SHOP_GET_GOLD_COINS, this);
		this->mTextPluses[3] = Button::create(structure1, spriteBatch5, Options::BUTTONS_ID_SHOP_GET_KEYS, this);
        
		this->mIcons[0] = Entity::create("coins_silver@2x.png", 5, 4, this->mSpriteBatch7);
		this->mIcons[1] = Entity::create("coins@2x.png", 5, 4, this->mSpriteBatch7);
		this->mIcons[2] = Icon8::create("game_panel_goldlife@2x.png", spriteBatch5);
		this->mIcons[3] = Icon8::create("popup_key_ico@2x.png", spriteBatch5);
        
		Textes textes2 = {"", Options::FONT, 32, -1};
        
		this->mTextText[0] = Text::create(textes2, this->mPanelLayer);
		this->mTextText[1] = Text::create(textes2, this->mPanelLayer);
		this->mTextText[2] = Text::create(textes2, this->mPanelLayer);
		this->mTextText[3] = Text::create(textes2, this->mPanelLayer);
        
		this->mTextText[0]->setZOrder(5);
		this->mTextText[1]->setZOrder(5);
		this->mTextText[2]->setZOrder(5);
		this->mTextText[3]->setZOrder(5);
        
		this->mGamePanel->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
		this->mTextBackgrounds[0]->create()->setCenterPosition(this->mTextBackgrounds[0]->getWidthScaled() / 2 + Utils::coord(15), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextBackgrounds[1]->create()->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + this->mTextBackgrounds[0]->getWidthScaled() + Utils::coord(25), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextBackgrounds[2]->create()->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + this->mTextBackgrounds[1]->getWidthScaled() + Utils::coord(55), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextBackgrounds[3]->create()->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() + Utils::coord(35), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
		this->mTextBackgrounds[2]->setCenterPosition(this->mTextBackgrounds[2]->getCenterX(), this->mTextBackgrounds[2]->getCenterY());
		this->mTextBackgrounds[3]->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() - Utils::coord(10), this->mTextBackgrounds[3]->getCenterY());
        
		if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_NEXUS3)
		{
            this->mTextBackgrounds[1]->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + Utils::coord(15), this->mTextBackgrounds[1]->getCenterY());
            this->mTextBackgrounds[3]->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() + Utils::coord(10), this->mTextBackgrounds[3]->getCenterY());
		}
        
		this->mTextPluses[0]->create()->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + this->mTextBackgrounds[0]->getWidthScaled() / 2, this->mTextBackgrounds[0]->getCenterY());
		this->mTextPluses[2]->create()->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + this->mTextBackgrounds[1]->getWidthScaled() / 2, this->mTextBackgrounds[1]->getCenterY());
		this->mTextPluses[1]->create()->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() / 2, this->mTextBackgrounds[2]->getCenterY());
		this->mTextPluses[3]->create()->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() + this->mTextBackgrounds[3]->getWidthScaled() / 2, this->mTextBackgrounds[3]->getCenterY());
        
		this->mIcons[0]->create()->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() - this->mTextBackgrounds[0]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[0]->getCenterY());
		this->mIcons[1]->create()->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() - this->mTextBackgrounds[1]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[1]->getCenterY());
		this->mIcons[2]->create()->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() - this->mTextBackgrounds[2]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[2]->getCenterY());
		this->mIcons[3]->create()->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() - this->mTextBackgrounds[3]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[3]->getCenterY());
        
        this->mIcons[2]->setCenterPosition(this->mIcons[2]->getCenterX(), this->mIcons[2]->getCenterY() + Utils::coord(2));
        this->mIcons[3]->setCenterPosition(this->mIcons[3]->getCenterX(), this->mIcons[3]->getCenterY() + Utils::coord(2));
        
        this->mTextPluses[0]->setCenterPosition(this->mTextPluses[0]->getCenterX(), this->mTextPluses[0]->getCenterY() + Utils::coord(1));
        this->mTextPluses[1]->setCenterPosition(this->mTextPluses[1]->getCenterX(), this->mTextPluses[1]->getCenterY() + Utils::coord(1));
        this->mTextPluses[2]->setCenterPosition(this->mTextPluses[2]->getCenterX(), this->mTextPluses[2]->getCenterY() + Utils::coord(1));
        this->mTextPluses[3]->setCenterPosition(this->mTextPluses[3]->getCenterX(), this->mTextPluses[3]->getCenterY() + Utils::coord(1));
        
		this->mIcons[0]->setRotation(-45);
		this->mIcons[0]->setScale(0.75);
		this->mIcons[0]->animate(0.05);
        
		this->mIcons[1]->setRotation(-45);
		this->mIcons[1]->setScale(0.75);
		this->mIcons[1]->animate(0.05);
        ////////////////
        
        spriteBatch1->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
        
        this->addChild(this->mScaleLayer);
        
        this->mScaleLayer->setVisible(false);
        
		Textes textes1 = {"", Options::FONT, 64, -1};
        
		if (AppDelegate::isGetWindeScreen())
        {
            this->mParts = EntityManager::create(2, Entity::create("end_lvl_bg_sprite@2x.png", 1, 2), spriteBatch1);
        }
        else
        {
            this->mParts = EntityManager::create(2, Entity::create("end_lvl_bg_sprite@2x.png", 2, 1), spriteBatch1);
        }

        Entity* part;
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(0, Options::CAMERA_HEIGHT + part->getHeight() / 2 - Options::CAMERA_CENTER_Y);
		part->setCurrentFrameIndex(0);

		if(AppDelegate::isGetWindeScreen())
		{
			part->setScale(MAX(Options::CAMERA_HEIGHT / Options::designResolutionSize.height, Options::designResolutionSize.height / Options::CAMERA_HEIGHT));
		}
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(0, -part->getHeight() / 2 - Options::CAMERA_CENTER_Y);
		part->setCurrentFrameIndex(1);

		if(AppDelegate::isGetWindeScreen())
		{
			part->setScale(MAX(Options::CAMERA_HEIGHT / Options::designResolutionSize.height, Options::designResolutionSize.height / Options::CAMERA_HEIGHT));
		}
        
        this->mBackground = Entity::create("end_lvl_bg_popup@2x.png", spriteBatch3);
        this->mPrize = Entity::create("end_lvl_kybok_sprite@2x.png", 1, 2, spriteBatch3);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mPrize->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(220));
        
        this->mShopButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_SHOP, this);
        this->mMenuButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_MENU, this);
        this->mRestartButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_RESTART, this);
        this->mContinueButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_CONTINUE, this);
        
        this->mStarsParticles = EntityManager::create(50, ImpulseEntity::create("end_star_particle@2x.png"), spriteBatch3);
        this->mStars = EntityManager::create(3, Star::create(), spriteBatch3);
        this->mStarsSplashes = EntityManager::create(3, Entity::create("end_star_glow@2x.png"), spriteBatch3);

        if(this->mType == Splash::TYPE_PROGRESS)
        {
            for(int i = 0; i < 3; i++)
            {
                Entity* star = this->mStars->create();
                
                star->setCurrentFrameIndex(i + 3);
                star->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(180) * (i - 1), this->mBackground->getHeight() - Utils::coord(100) - Utils::coord(40) * abs(i - 1));
            }
        }
        
        this->setVisible(false);
        
        this->mIsAnimationRunning = false;
        this->mIsCoinsAnimationRunning = false;
        this->mIsCoinsAnimationCurrentRunning = false;
        
        this->mCoinsAnimationTime = 0.3;
        this->mCoinsAnimationCurrentTime = 0.05;
        
        this->mTextLevel = Text::create(Options::TEXT_END[0], this->mScaleLayer);
        this->mTextName = Text::create(textes1, this->mScaleLayer);
        this->mTextValue = Text::create(textes1, this->mScaleLayer);
        this->mTextCountValue = Text::create(textes1, this->mScaleLayer);
        
        this->mTextName->setDimensions(CCSize(Utils::coord(500), 0));
        this->mTextCountValue->setDimensions(CCSize(Utils::coord(200), 0));
        
        this->mTextName->setHorizontalAlignment(kCCTextAlignmentLeft);
        this->mTextCountValue->setHorizontalAlignment(kCCTextAlignmentRight);
        
        this->mConfetti = EntityManager::create(600, Confetti::create(), this->mSpriteBatch7);
    }

End* End::create(int pType, Screen* pParent)
{
    End* screen = new End(pType, pParent);
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void End::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
            case Options::BUTTONS_ID_END_MENU:
                
            this->hide();
                
            Loader::ACTION = 3;
                    
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Loader::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LOADER);
            #endif
                
            break;
            case Options::BUTTONS_ID_END_RESTART:
                
            this->hide();
                    
            ACTION = 1;
                
            break;
            case Options::BUTTONS_ID_END_CONTINUE:
                    
            Game::LEVEL++;
                
            this->hide();
                    
            ACTION = 1;
                
            break;
            case Options::BUTTONS_ID_END_SHOP:
                
            this->hide();
                    
            Loader::ACTION = 5;
            Shop::ACTION = 0;
                    
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Loader::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LOADER);
            #endif
                
            break;
            case Options::BUTTONS_ID_MENU_SHOP:
                    
            Shop::ACTION = 1;
            Loader::ACTION = 5;
                    
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Loader::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LOADER);
            #endif
                    
            break;
            case Options::BUTTONS_ID_SHOP_GET_SILVER_COINS:
            case Options::BUTTONS_ID_SHOP_GET_GOLD_COINS:
                    
            Shop::ACTION = 10;
            Loader::ACTION = 5;
                    
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Loader::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LOADER);
            #endif
                    
            break;
            case Options::BUTTONS_ID_SHOP_GET_LIVES:
                    
            Shop::ACTION = 11;
            Loader::ACTION = 5;
                    
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Loader::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LOADER);
            #endif
                    
            break;
            case Options::BUTTONS_ID_SHOP_GET_KEYS:
                    
            Shop::ACTION = 12;
            Loader::ACTION = 5;
                    
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Shop::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LOADER);
            #endif
                    
            break;
            }
        break;
            
        case Options::BUTTONS_ACTION_ONBEGIN:
            break;
            
        case Options::BUTTONS_ACTION_ONEND:
            break;
    }
}

void End::onShow()
{
    Splash::onShow();
    
    ACTION = -1;

    this->mIsAnimationRunning = Game::STARS > 0;
    
    this->mAnimationTime = 0.6;
    this->mAnimationtimeElapsed = 0;
    
    this->mAnimationCounter = 0;
    this->mCoinsAnimationTimeElapsed = 0;
    this->mCoinsAnimationCounter = 0;
    this->mCoinsAnimationCurrentTime = 0.2;
    this->mCoinsAnimationCurrentTimeElapsed = -0.8;
    
    this->mCurrentCount = 0;
    this->mBestCurrentCount = 0;
    this->mFlayerCount = 0;
    this->mComboCount = 0;
    this->mCriticalCount = 0;
    this->mTotalEarnedCoins = 0;
    this->mEarnedCoins = 0;
    
    this->mIsCoinsAnimationRunning = false;
    this->mIsCoinsAnimationCurrentRunning = false;
    
    this->mTotalEarnedCoins += Game::CURRENT_COUNT;
    this->mTotalEarnedCoins += Game::FLAYER_COUNT * 10;
    this->mTotalEarnedCoins += Game::CRITICAL_COUNT * 2;
    this->mTotalEarnedCoins += Game::COMBO_COUNT * 5;
    
    if(this->mType == TYPE_PROGRESS)
    {
        if(AppDelegate::getLevelStars(Game::LEVEL) < Game::STARS)
        {
            AppDelegate::setLevelStars(Game::LEVEL, Game::STARS);
            AppDelegate::setLevelStars(Game::LEVEL + 1, 0);
            
            AppDelegate::addTotalLevelsUnlocked(1);
        }
        
        switch(Game::STARS)
        {
            case 0:
                if(Options::SOUND_ENABLE)
                {
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LEVEL_LOSE);
                }
                
                this->mTextLevel->setText(Options::TEXT_END[3]);
                break;
            case 1:
                this->mTextLevel->setText(Options::TEXT_END[1]);
                break;
            case 2:
                this->mTextLevel->setText(Options::TEXT_END[2]);
                break;
            case 3:
                this->mTextLevel->setText(Options::TEXT_END[0]);
                break;
        }
        
        if(AppDelegate::getLevelStars(Game::LEVEL + 1) >= 0)
        {
            this->mContinueButton->create()->setCurrentFrameIndex(2);
            this->mContinueButton->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
        
            this->mRestartButton->create()->setCurrentFrameIndex(1);
            this->mRestartButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(340));
        
            this->mMenuButton->create()->setCurrentFrameIndex(0);
            this->mMenuButton->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
        }
        else
        {
            this->mShopButton->create()->setCurrentFrameIndex(3);
            this->mShopButton->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
            
            this->mRestartButton->create()->setCurrentFrameIndex(1);
            this->mRestartButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(340));
            
            this->mMenuButton->create()->setCurrentFrameIndex(0);
            this->mMenuButton->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
        }
        
        this->mPrize->setVisible(false);
        this->mTextLevel->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(330));
    }
    else
    {
        this->mIsAnimationRunning = true;
        
        this->mShopButton->create()->setCurrentFrameIndex(3);
        this->mShopButton->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
        
        this->mMenuButton->create()->setCurrentFrameIndex(0);
        this->mMenuButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(340));
        
        this->mContinueButton->create()->setCurrentFrameIndex(2);
        this->mContinueButton->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));

        this->mPrize->setVisible(true);
        this->mPrize->setCurrentFrameIndex(0);
        
        if(Game::CURRENT_COUNT >= Game::BEST_COUNT && Game::CURRENT_COUNT > 10)
        {
            this->mTextLevel->setText(Options::TEXT_END[0]);
            
            this->throwConfetti();
        }
        else
        {
            this->mTextLevel->setText(Options::TEXT_END[3]);
            
            if(Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LEVEL_LOSE);
            }
        }
        
        this->mTextLevel->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(530));
    }
    
    this->mTextName->setOpacity(0);
    this->mTextValue->setOpacity(0);
    
    this->mTextName->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(80), Options::CAMERA_CENTER_Y - Utils::coord(20));
    this->mTextCountValue->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(80), Options::CAMERA_CENTER_Y - Utils::coord(20));
    this->mTextValue->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(120));
    
    this->mIsCoinsAnimationCurrentRunning = true;
    
    this->addChild(this->mPanelLayer);
    this->mPanelLayer->setPosition(ccp(0, this->mGamePanel->getHeightScaled()));
    this->mPanelLayer->runAction(CCMoveTo::create(1.0, ccp(0, 0)));
    
    if(this->mType == TYPE_CLASSIC)
    {
        AppDelegate::mGameCenter->postScore(Options::LEADERBOARD_CLASSIC, Game::BEST_COUNT);
    }
    else if(this->mType == TYPE_ARCADE)
    {
        AppDelegate::mGameCenter->postScore(Options::LEADERBOARD_ARCADE, Game::BEST_COUNT);
    }
}

void End::onHide()
{
    Splash::onHide();

    if(this->mType == Splash::TYPE_PROGRESS)
    {
        for(int i = 0; i < 3; i++)
        {
            Entity* star = static_cast<Entity*>(this->mStars->objectAtIndex(i));
            
            star->setCurrentFrameIndex(i + 3);
        }
    }
    
    this->mShopButton->isVisible() ? this->mShopButton->destroy() : false;
    this->mMenuButton->isVisible() ? this->mMenuButton->destroy() : false;
    this->mRestartButton->isVisible() ? this->mRestartButton->destroy() : false;
    this->mContinueButton->isVisible() ? this->mContinueButton->destroy() : false;
    
    this->mIsAnimationRunning = false;
    this->mIsCoinsAnimationRunning = false;
    
    this->mPanelLayer->removeFromParentAndCleanup(false);
    
    this->mConfetti->clear();
    this->mStarsSplashes->clear();
    this->mStarsParticles->clear();
}

void End::onStartShow()
{
    Splash::onStartShow();
    
    for(int i = 0; i < this->mConfetti->getCapacity(); i++)
    {
        static_cast<Entity*>(this->mConfetti->objectAtIndex(i))->setOpacity(255);
    }

    if(Game::STARS > 0) this->throwConfetti();
    
    //int coins = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_SILVER);
    
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.2);
    
    //
    
    this->mParts->mParent->runAction(CCSequence::create(
                                   CCFadeTo::create(0.2, 255),
                                   CCScaleTo::create(0.1, 1.2, 1.0),
                                   CCScaleTo::create(0.1, 1.0, 1.2),
                                   CCScaleTo::create(0.1, 1.0, 1.0),
                                   NULL
                                                        ));
    
    this->mPanelItems[0] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_SILVER);
    this->mPanelItems[1] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_GOLD);
    this->mPanelItems[2] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES);
    this->mPanelItems[3] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_KEYS);
    
    this->mTextText[0]->setString(Utils::intToString(this->mPanelItems[0]).c_str());
    this->mTextText[0]->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + this->mTextBackgrounds[0]->getWidthScaled() / 2 - this->mTextText[0]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[0]->getCenterY());
    
    this->mTextText[1]->setString(Utils::intToString(this->mPanelItems[1]).c_str());
    this->mTextText[1]->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + this->mTextBackgrounds[1]->getWidthScaled() / 2 - this->mTextText[1]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[1]->getCenterY());
    
    this->mTextText[2]->setString(Utils::intToString(this->mPanelItems[2]).c_str());
    this->mTextText[2]->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() / 2 - this->mTextText[2]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[2]->getCenterY());
    
    this->mTextText[3]->setString(Utils::intToString(this->mPanelItems[3]).c_str());
    this->mTextText[3]->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() + this->mTextBackgrounds[3]->getWidthScaled() / 2 - this->mTextText[3]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[3]->getCenterY());
}

void End::onStartHide()
{
    Splash::onStartHide();
    
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.0);
    
    this->mPanelLayer->runAction(CCMoveTo::create(0.2, ccp(0, this->mGamePanel->getHeightScaled())));
    
    for(int i = 0; i < this->mConfetti->getCapacity(); i++)
    {
        static_cast<Entity*>(this->mConfetti->objectAtIndex(i))->runAction(CCFadeTo::create(0.15, 0));
    }
}

void End::throwConfetti()
{
    this->mConfetti->clear();

    float x = 0;
    float y = Utils::coord(200);

    for(int i = 0; i < 10; i++)
    {
        for(int j = -(Options::CAMERA_CENTER_X / Utils::coord(40)); j <= (Options::CAMERA_CENTER_X / Utils::coord(40)); j++)
        {
            x = Utils::coord(Utils::randomf(40.0, 40.0)) * j;

            this->mConfetti->create()->setCenterPosition(Options::CAMERA_CENTER_X + x, Options::CAMERA_HEIGHT + y);
        }

        y -= Utils::coord(Utils::randomf(5.0, 10.0));
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void End::update(float pDeltaTime)
{
    Splash::update(pDeltaTime);

    if(this->mIsAnimationRunning)
    {
        this->mAnimationtimeElapsed += pDeltaTime;
        
        if(this->mAnimationtimeElapsed >= this->mAnimationTime)
        {
            this->mAnimationtimeElapsed = 0;

            if(this->mType == Splash::TYPE_PROGRESS)
            {
                Star* star = static_cast<Star*>(this->mStars->objectAtIndex(this->mAnimationCounter));
                Entity* splash = static_cast<Entity*>(this->mStarsSplashes->create());
                
                star->setCurrentFrameIndex(star->getCurrentFrameIndex() - 3);
                //star->animate();
                
                splash->setScale(1.5);
                splash->setOpacity(255);
                splash->setCenterPosition(star->getCenterX(), star->getCenterY());
                splash->runAction(CCFadeTo::create(0.3, 0));
                splash->runAction(CCScaleTo::create(0.3, 1.2, 3.0));
                
                if(Options::SOUND_ENABLE)
                {
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LEVEL_STARS[this->mAnimationCounter]);
                }
                
                this->mAnimationCounter++;
                
                if(this->mAnimationCounter >= Game::STARS || (this->mAnimationCounter >= 3))
                {
                    this->mIsAnimationRunning = false;
                }
                
                for(int i = 0; i < 15; i++)
                {
                    ImpulseEntity* particle = static_cast<ImpulseEntity*>(this->mStarsParticles->create());
                    
                    particle->setRotation(Utils::random(0, 720));
                    particle->setScale(Utils::randomf(0.7, 1.2));
                    particle->setOpacity(150);
                    
                    particle->mImpulsePower = Utils::randomf(0.0, 800.0);
                    particle->mWeight = Utils::randomf(100.0, 1000.0);
                    particle->mSideImpulse = Utils::randomf(-400.0, 400.0);
                    particle->mRotateImpulse = Utils::randomf(-100.0, 100.0);
                    
                    particle->setCenterPosition(star->getCenterX(), star->getCenterY());
                    
                    particle->runAction(CCSequence::create(CCFadeTo::create(Utils::randomf(1.0, 2.0), particle->getOpacity()), CCFadeTo::create(0.2, 0), NULL));
                    
                    if(AppDelegate::isGetWindeScreen())
                    {
                        particle->mSideImpulse *= 1.4;
                    }
                }
            }
            else
            {
                if(Game::CURRENT_COUNT >= Game::BEST_COUNT && Game::BEST_COUNT > 10)
                {
                    this->mPrize->setCurrentFrameIndex(1);
                    Entity* splash = static_cast<Entity*>(this->mStarsSplashes->create());
                    
                    splash->setScale(1.5);
                    splash->setOpacity(255);
                    splash->setCenterPosition(this->mPrize->getCenterX(), this->mPrize->getCenterY());
                    splash->runAction(CCFadeTo::create(0.3, 0));
                    splash->runAction(CCScaleTo::create(0.3, 1.2, 3.0));
                    
                    for(int i = 0; i < 15; i++)
                    {
                        ImpulseEntity* particle = static_cast<ImpulseEntity*>(this->mStarsParticles->create());
                        
                        particle->setRotation(Utils::random(0, 720));
                        particle->setScale(Utils::randomf(0.7, 1.2));
                        particle->setOpacity(150);
                        
                        particle->mImpulsePower = Utils::randomf(0.0, 800.0);
                        particle->mWeight = Utils::randomf(100.0, 1000.0);
                        particle->mSideImpulse = Utils::randomf(-400.0, 400.0);
                        particle->mRotateImpulse = Utils::randomf(-100.0, 100.0);
                        
                        particle->setCenterPosition(this->mPrize->getCenterX(), this->mPrize->getCenterY());
                        
                        particle->runAction(CCSequence::create(CCFadeTo::create(Utils::randomf(1.0, 2.0), particle->getOpacity()), CCFadeTo::create(0.2, 0), NULL));
                        
						if (AppDelegate::isGetWindeScreen())
                        {
                            particle->mSideImpulse *= 1.4;
                        }
                    }
                }
                else
                {
                    this->mPrize->setCurrentFrameIndex(0);
                }
                
                this->mIsAnimationRunning = false;
            }
        }
    }
    
    if(this->mIsCoinsAnimationRunning)
    {
        /*this->mCoinsAnimationTimeElapsed += pDeltaTime;
        
        if(this->mCoinsAnimationTimeElapsed >= this->mCoinsAnimationTime)
        {
            this->mCoinsAnimationTimeElapsed = 0;
            this->mCoinsAnimationCounter++;
            
            this->mIsCoinsAnimationRunning = false;
            this->mIsCoinsAnimationCurrentRunning = true;
        }*/
    }
    else
    {
        if(this->mIsCoinsAnimationCurrentRunning)
        {
            this->mCoinsAnimationCurrentTimeElapsed += pDeltaTime;
        
            if(this->mCoinsAnimationCurrentTimeElapsed >= this->mCoinsAnimationCurrentTime)
            {
                //int coins = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_SILVER);
                
                switch(this->mCoinsAnimationCounter)
                {
                    case 0:
                        this->mTextName->setText(Options::TEXT_END[4]);
                        this->mTextCountValue->setText(Options::TEXT_END[4]);
                        
                        this->mTextName->animate(0);
                        this->mTextValue->animate(0);
                        this->mTextCountValue->animate(0);
                        
                        this->mTextName->setHorizontalAlignment(kCCTextAlignmentLeft);
                        
                        this->mTextName->runAction(CCFadeIn::create(this->mCoinsAnimationCurrentTime));
                        this->mTextCountValue->runAction(CCFadeIn::create(this->mCoinsAnimationCurrentTime));
                        this->mTextValue->runAction(CCFadeIn::create(this->mCoinsAnimationCurrentTime));
                        
                        this->mCoinsAnimationCurrentTime = 0.2;
                        this->mCoinsAnimationCurrentTimeElapsed = 0;
                        this->mCoinsAnimationCounter++;
                    case 1:
                        if(this->mComboCount < Game::COMBO_COUNT) this->mComboCount++;
                        this->mTextCountValue->setString(ccsf("%d", this->mComboCount));
                        
                        if(this->mComboCount >= Game::COMBO_COUNT && this->mTextName->numberOfRunningActions() <= 0)
                        {
                            this->mCoinsAnimationCurrentTime = 0.6;
                            this->mCoinsAnimationCurrentTimeElapsed = 0;
                            
                            this->mCoinsAnimationCounter++;
                            
                            this->mTextName->runAction(CCFadeOut::create(this->mCoinsAnimationCurrentTime));
                            this->mTextCountValue->runAction(CCFadeOut::create(this->mCoinsAnimationCurrentTime));
                            
                            this->mTextName->animate(1);
                            this->mTextCountValue->animate(1);
                        }
                        break;
                    case 2:
                        this->mTextName->setText(Options::TEXT_END[5]);
                        this->mTextName->runAction(CCFadeIn::create(this->mCoinsAnimationCurrentTime));
                        this->mTextCountValue->runAction(CCFadeIn::create(this->mCoinsAnimationCurrentTime));
                        
                        this->mTextName->animate(0);
                        this->mTextCountValue->animate(0);
                        
                        this->mCoinsAnimationCurrentTime = 0.2;
                        this->mCoinsAnimationCurrentTimeElapsed = 0;
                        this->mCoinsAnimationCounter++;
                    case 3:
                        if(this->mFlayerCount < Game::FLAYER_COUNT) this->mFlayerCount++;
                        this->mTextCountValue->setString(ccsf("%d", this->mFlayerCount));
                        
                        if(this->mFlayerCount >= Game::FLAYER_COUNT && this->mTextName->numberOfRunningActions() <= 0)
                        {
                            this->mCoinsAnimationCurrentTime = 0.6;
                            this->mCoinsAnimationCurrentTimeElapsed = 0;
                            
                            this->mCoinsAnimationCounter++;
                            
                            this->mTextName->runAction(CCFadeOut::create(this->mCoinsAnimationCurrentTime));
                            this->mTextCountValue->runAction(CCFadeOut::create(this->mCoinsAnimationCurrentTime));
                            
                            this->mTextName->animate(1);
                            this->mTextCountValue->animate(1);
                        }
                        break;
                    case 4:
                        this->mTextName->setHorizontalAlignment(kCCTextAlignmentCenter);
                        
                        this->mTextName->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(20));
                        this->mTextName->setText(Options::TEXT_END[6]);
                        this->mTextName->runAction(CCFadeIn::create(this->mCoinsAnimationCurrentTime));
                        
                        this->mTextName->animate(0);
                        
                        this->mIsCoinsAnimationCurrentRunning = false;
                        break;
                }
                
                if(this->mEarnedCoins < this->mTotalEarnedCoins)
                {
                    this->mEarnedCoins++;
                    this->mTextValue->setString(ccsf("%d", this->mEarnedCoins));
                    this->mTextValue->animate(1); // ?
                }
            }
        }
    }
    
    for(int i = 0; i < this->mStarsSplashes->getCount(); i++)
    {
        Entity* splash = static_cast<Entity*>(this->mStarsSplashes->objectAtIndex(i));
        
        if(splash->getOpacity() <= 0)
        {
            splash->destroy();
        }
    }
    
    for(int i = 0; i < this->mStarsParticles->getCount(); i++)
    {
        Entity* particle = static_cast<Entity*>(this->mStarsParticles->objectAtIndex(i));
        
        if(particle->getOpacity() <= 0)
        {
            particle->destroy();
        }
    }/** Coins animation */
    
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
    
    if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) <= 0)
    {
        long time = (AppDelegate::getLiveNearestReleaseTime(0) + (30 * 60 * 1000) - Utils::millisecondNow());
        
        int minutes = floor((time / 1000) / 60);
        long seconds = (time / 1000) - (minutes * 60);
        
        char text[256];
        
        sprintf(text, "%d:%lu", minutes, seconds);
        
        if(minutes < 10)
        {
            sprintf(text, "0%d:%lu", minutes, seconds);
        }
        if(seconds < 10)
        {
            sprintf(text, "%d:0%lu", minutes, seconds);
        }
        if(minutes < 10 && seconds < 10)
        {
            sprintf(text, "0%d:0%lu", minutes, seconds);
        }
        
        this->mTextText[2]->setString(text);
        this->mTextText[2]->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() / 2 - this->mTextText[2]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[2]->getCenterY());
    }
}

#endif