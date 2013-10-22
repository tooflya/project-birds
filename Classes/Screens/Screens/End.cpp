#ifndef CONST_END
#define CONST_END

#include "End.h"

#include "Game.h"
#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

End::~End()
{
    CC_SAFE_RELEASE_NULL(this->mConfetti);
    CC_SAFE_RELEASE_NULL(this->mCoins);
    
    CC_SAFE_RELEASE_NULL(this->mStars);
}

End::End(int pType, Screen* pParent) :
    Splash(pParent)
    {
        this->mType = pType;
        
        this->mScaleLayer = CCLayer::create();
        this->mScaleLayer->retain();
        
        SpriteBatch* spriteBatch1 = SpriteBatch::create("TextureAtlas8");
        SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas7");
        SpriteBatch* spriteBatch3 = SpriteBatch::create("TextureAtlas8");
        SpriteBatch* spriteBatch4 = SpriteBatch::create("TextureAtlas7");
        
        this->addChild(spriteBatch1);
        this->mScaleLayer->addChild(spriteBatch3);
        this->mScaleLayer->addChild(spriteBatch2, 2);
        this->mScaleLayer->addChild(spriteBatch4, 3);
        
        this->addChild(this->mScaleLayer);
        this->mScaleLayer->setVisible(false);
        
		Textes textes1 = {"0", Options::FONT, 64, -1};

        this->mCoinsCountText = Text::create(textes1, this->mScaleLayer);
        
        this->mParts = EntityManager::create(2, Entity::create("end_lvl_bg_sprite@2x.png", 2, 1), spriteBatch1);
        
        Entity* part;
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT + part->getHeight() / 2);
        part->setCurrentFrameIndex(0);
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(Options::CAMERA_CENTER_X, -part->getHeight() / 2);
        part->setCurrentFrameIndex(1);
        
        this->mBackground = Entity::create("end_lvl_bg_popup@2x.png", spriteBatch3);
        
        this->mCoinsPanel = Entity::create("shop_money_bg@2x.png", spriteBatch3);
        this->mCoin = Entity::create("coins@2x.png", 5, 4, spriteBatch4);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mCoinsPanel->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(90));
        
        this->mCoin->create()->setCenterPosition(this->mCoinsPanel->getCenterX() - Utils::coord(105), this->mCoinsPanel->getCenterY());
        this->mCoin->setRotation(-45);
        this->mCoin->setScale(1.3);
        this->mCoin->animate(0.05);
        
        this->mCoinsCountText->setCenterPosition(this->mCoinsPanel->getCenterX() - Utils::coord(70) + this->mCoinsCountText->getWidth() / 2, this->mCoinsPanel->getCenterY());
        
        this->mShopButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_SHOP, this);
        this->mMenuButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_MENU, this);
        this->mRestartButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_RESTART, this);
        this->mContinueButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_CONTINUE, this);
        
        this->mStars = EntityManager::create(3, Star::create(), spriteBatch3);

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

        this->mTextes[0] = Text::create(Options::TEXT_END[0], this->mScaleLayer);
        this->mTextes[1] = Text::create(Options::TEXT_END[1], this->mScaleLayer);
        this->mTextes[2] = Text::create(Options::TEXT_END[2], this->mScaleLayer);
        this->mTextes[3] = Text::create(Options::TEXT_END[3], this->mScaleLayer);
        this->mTextes[4] = Text::create(Options::TEXT_END[4], this->mScaleLayer);
        this->mTextes[5] = Text::create(Options::TEXT_END[5], this->mScaleLayer);
        this->mTextes[6] = Text::create(Options::TEXT_END[6], this->mScaleLayer);

        this->mTextes[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));
        this->mTextes[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));
        this->mTextes[2]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(150));
        this->mTextes[3]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100));
        this->mTextes[4]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(50));
        this->mTextes[5]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(0));
        this->mTextes[6]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50));
        
        this->mConfetti = EntityManager::create(300, Confetti::create(), spriteBatch2);
        this->mCoins = EntityManager::create(50, AnimatedCoin::create("coins_silver@2x.png", 1.5), spriteBatch4);
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
                
            AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
                
            break;
            case Options::BUTTONS_ID_END_RESTART:
                
            this->hide();
                
            break;
            case Options::BUTTONS_ID_END_CONTINUE:
                
            this->hide();
                
            break;
            case Options::BUTTONS_ID_END_SHOP:
                
            this->hide(); // TODO: Open shop screen.
                
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

    this->mIsAnimationRunning = Game::STARS > 0;
    
    this->mAnimationTime = 0.6;
    this->mAnimationtimeElapsed = 0;
    
    this->mAnimationCounter = 0;
    this->mCoinsAnimationTimeElapsed = 0;
    this->mCoinsAnimationCounter = 0;
    this->mCoinsAnimationCurrentTimeElapsed = 0;
    
    this->mCurrentCount = 0;
    this->mBestCurrentCount = 0;
    this->mFlayerCount = 0;
    this->mComboCount = 0;
    this->mCriticalCount = 0;
    this->mTotalEarnedCoins = 0;
    this->mEarnedCoins = 0;
    
    this->mIsCoinsAnimationRunning = true;
    this->mIsCoinsAnimationCurrentRunning = false;
    
    this->mTotalEarnedCoins += Game::CURRENT_COUNT;
    this->mTotalEarnedCoins += Game::FLAYER_COUNT * 10;
    this->mTotalEarnedCoins += Game::CRITICAL_COUNT * 2;
    this->mTotalEarnedCoins += Game::COMBO_COUNT * 5;
    
    if(this->mType == TYPE_PROGRESS)
    {
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
    }
    else
    {
        this->mShopButton->create()->setCurrentFrameIndex(3);
        this->mShopButton->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
        
        this->mMenuButton->create()->setCurrentFrameIndex(0);
        this->mMenuButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(340));
        
        this->mContinueButton->create()->setCurrentFrameIndex(2);
        this->mContinueButton->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
    }

    if(AppDelegate::getLevelStars(Game::LEVEL) < Game::STARS)
    {
        AppDelegate::setLevelStars(Game::LEVEL, Game::STARS);
        AppDelegate::setLevelStars(Game::LEVEL + 1, 0);
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
}

void End::onStartShow()
{
    Splash::onStartShow();
    
    if(Game::STARS > 0) this->throwConfetti();
    
    int coins = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_SILVER);
    
    this->mCoinsCountText->setString(Utils::intToString(coins).c_str());
    this->mCoinsCountText->setCenterPosition(this->mCoinsPanel->getCenterX() - Utils::coord(70) + this->mCoinsCountText->getWidth() / 2, this->mCoinsPanel->getCenterY());
    
    this->mTextes[1]->setString(ccsf(Options::TEXT_END[1].string, 0));
    this->mTextes[2]->setString(ccsf(Options::TEXT_END[2].string, 0));
    this->mTextes[3]->setString(ccsf(Options::TEXT_END[3].string, 0));
    this->mTextes[4]->setString(ccsf(Options::TEXT_END[4].string, 0));
    this->mTextes[5]->setString(ccsf(Options::TEXT_END[5].string, 0));
    this->mTextes[6]->setString(ccsf(Options::TEXT_END[6].string, 0));
}

void End::onStartHide()
{
    Splash::onStartHide();
}

void End::throwConfetti()
{
    this->mConfetti->clear();

    float x = 0;
    float y = Utils::coord(200);

    for(int i = 0; i < 10; i++)
    {
        for(int j = -10; j <= 10; j++)
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
                
                star->setCurrentFrameIndex(star->getCurrentFrameIndex() - 3);
                star->animate();
                
                this->mAnimationCounter++;
                
                if(this->mAnimationCounter >= Game::STARS)
                {
                    this->mIsAnimationRunning = false;
                }
            }
        }
    }
    
    if(this->mIsCoinsAnimationRunning)
    {
        this->mCoinsAnimationTimeElapsed += pDeltaTime;
        
        if(this->mCoinsAnimationTimeElapsed >= this->mCoinsAnimationTime)
        {
            this->mCoinsAnimationTimeElapsed = 0;
            this->mCoinsAnimationCounter++;
            
            this->mIsCoinsAnimationRunning = false;
            this->mIsCoinsAnimationCurrentRunning = true;
        }
    }
    else
    {
        if(this->mIsCoinsAnimationCurrentRunning)
        {
            this->mCoinsAnimationCurrentTimeElapsed += pDeltaTime;
        
            if(this->mCoinsAnimationCurrentTimeElapsed >= this->mCoinsAnimationCurrentTime)
            {
                this->mCoinsAnimationCurrentTimeElapsed = 0;
                
                int coins = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_SILVER);
                
                this->mCoinsCountText->setString(Utils::intToString(coins).c_str());
                this->mCoinsCountText->setCenterPosition(this->mCoinsPanel->getCenterX() - Utils::coord(70) + this->mCoinsCountText->getWidth() / 2, this->mCoinsPanel->getCenterY());
                
                switch(this->mCoinsAnimationCounter)
                {
                    case 1:
                        
                    if(Game::CURRENT_COUNT > this->mCurrentCount)
                    {
                        this->mCurrentCount++;
                        
                        AppDelegate::addCoins(1, Options::SAVE_DATA_COINS_TYPE_SILVER);
                        
                        this->mCoins->create()->setCenterPosition(this->mTextes[this->mCoinsAnimationCounter]->getCenterX(), this->mTextes[this->mCoinsAnimationCounter]->getCenterY());
                    }
                    else
                    {
                        this->mIsCoinsAnimationRunning = true;
                        this->mIsCoinsAnimationCurrentRunning = false;
                    }
                        
                    this->mTextes[this->mCoinsAnimationCounter]->setString(ccsf(Options::TEXT_END[this->mCoinsAnimationCounter].string, this->mCurrentCount));
                        
                    break;
                        
                    //
                        
                    case 2:
                    
                    this->mBestCurrentCount = Game::BEST_COUNT;
                        
                    this->mIsCoinsAnimationRunning = true;
                    this->mIsCoinsAnimationCurrentRunning = false;
                    
                    this->mTextes[this->mCoinsAnimationCounter]->setString(ccsf(Options::TEXT_END[this->mCoinsAnimationCounter].string, this->mBestCurrentCount));
                        
                    break;
                        
                    //
                        
                    case 3:
                        
                    if(Game::FLAYER_COUNT > this->mFlayerCount)
                    {
                        this->mFlayerCount++;
                        
                        AppDelegate::addCoins(10, Options::SAVE_DATA_COINS_TYPE_SILVER);
                        
                        this->mCoins->create()->setCenterPosition(this->mTextes[this->mCoinsAnimationCounter]->getCenterX(), this->mTextes[this->mCoinsAnimationCounter]->getCenterY());
                    }
                    else
                    {
                        this->mIsCoinsAnimationRunning = true;
                        this->mIsCoinsAnimationCurrentRunning = false;
                    }
                        
                    this->mTextes[this->mCoinsAnimationCounter]->setString(ccsf(Options::TEXT_END[this->mCoinsAnimationCounter].string, this->mFlayerCount));
                        
                    break;
                        
                    //
                        
                    case 4:
                        
                    if(Game::COMBO_COUNT > this->mComboCount)
                    {
                        this->mComboCount++;
                        
                        AppDelegate::addCoins(2, Options::SAVE_DATA_COINS_TYPE_SILVER);
                        
                        this->mCoins->create()->setCenterPosition(this->mTextes[this->mCoinsAnimationCounter]->getCenterX(), this->mTextes[this->mCoinsAnimationCounter]->getCenterY());
                    }
                    else
                    {
                        this->mIsCoinsAnimationRunning = true;
                        this->mIsCoinsAnimationCurrentRunning = false;
                    }
                        
                    this->mTextes[this->mCoinsAnimationCounter]->setString(ccsf(Options::TEXT_END[this->mCoinsAnimationCounter].string, this->mComboCount));
                        
                    break;
                        
                    //
                    
                    case 5:
                        
                    if(Game::CRITICAL_COUNT > this->mCriticalCount)
                    {
                        this->mCriticalCount++;
                        
                        AppDelegate::addCoins(5, Options::SAVE_DATA_COINS_TYPE_SILVER);
                        
                        this->mCoins->create()->setCenterPosition(this->mTextes[this->mCoinsAnimationCounter]->getCenterX(), this->mTextes[this->mCoinsAnimationCounter]->getCenterY());
                    }
                    else
                    {
                        this->mIsCoinsAnimationRunning = true;
                        this->mIsCoinsAnimationCurrentRunning = false;
                    }
                        
                    this->mTextes[this->mCoinsAnimationCounter]->setString(ccsf(Options::TEXT_END[this->mCoinsAnimationCounter].string, this->mCriticalCount));
                        
                    break;
                        
                    //
                        
                    case 6:
                        
                    if(this->mTotalEarnedCoins > this->mEarnedCoins)
                    {
                        this->mEarnedCoins++;
                    }
                    else
                    {
                        this->mIsCoinsAnimationRunning = false;
                        this->mIsCoinsAnimationCurrentRunning = false;
                    }
                        
                    this->mTextes[this->mCoinsAnimationCounter]->setString(ccsf(Options::TEXT_END[this->mCoinsAnimationCounter].string, this->mEarnedCoins));
                        
                    break;
                }
            }
        }
    }
}

#endif