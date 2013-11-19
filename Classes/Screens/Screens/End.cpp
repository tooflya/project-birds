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
	mIsCoinsAnimationCurrentRunning(0)
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
        
        spriteBatch1->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
        
        this->addChild(this->mScaleLayer);
        this->mScaleLayer->setVisible(false);
        
		Textes textes1 = {"", Options::FONT, 64, -1};
        
        this->mParts = EntityManager::create(2, Entity::create("end_lvl_bg_sprite@2x.png", 2, 1), spriteBatch1);
        
        Entity* part;
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(0, Options::CAMERA_HEIGHT + part->getHeight() / 2 - Options::CAMERA_CENTER_Y);
        part->setCurrentFrameIndex(0);
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(0, -part->getHeight() / 2 - Options::CAMERA_CENTER_Y);
        part->setCurrentFrameIndex(1);
        
        this->mBackground = Entity::create("end_lvl_bg_popup@2x.png", spriteBatch3);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        
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
        
        this->mTextName->mShadow->setDimensions(CCSize(Utils::coord(500), 0));
        this->mTextCountValue->mShadow->setDimensions(CCSize(Utils::coord(200), 0));
        
        this->mTextName->mShadow->setHorizontalAlignment(kCCTextAlignmentLeft);
        this->mTextCountValue->mShadow->setHorizontalAlignment(kCCTextAlignmentRight);
        
        this->mConfetti = EntityManager::create(300, Confetti::create(), spriteBatch2);
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
                    
            Game::LEVEL++;
                
            this->hide();
                
            break;
            case Options::BUTTONS_ID_END_SHOP:
                
            this->hide();
                    
            Loader::ACTION = 5;
            Shop::ACTION = 0;
                    
            AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
                
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
    this->mCoinsAnimationCurrentTime = 0.2;
    this->mCoinsAnimationCurrentTimeElapsed = 0;
    
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
        }
        
        if(Game::STARS <= 0)
        {
            if(Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LEVEL_LOSE);
            }
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
    
    this->mTextName->setOpacity(0);
    this->mTextValue->setOpacity(0);
    
    this->mTextLevel->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(330));
    this->mTextName->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(80), Options::CAMERA_CENTER_Y - Utils::coord(20));
    this->mTextCountValue->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(80), Options::CAMERA_CENTER_Y - Utils::coord(20));
    this->mTextValue->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(120));
    
    this->mIsCoinsAnimationCurrentRunning = true;
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
}

void End::onStartShow()
{
    Splash::onStartShow();
    
    if(Game::STARS > 0) this->throwConfetti();
    
    int coins = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_SILVER);
    
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.2);
    
    //
    
    this->mParts->mParent->runAction(CCSequence::create(
                                   CCFadeTo::create(0.2, 255),
                                   CCScaleTo::create(0.1, 1.2, 1.0),
                                   CCScaleTo::create(0.1, 1.0, 1.2),
                                   CCScaleTo::create(0.1, 1.0, 1.0),
                                   NULL
                                   ));
}

void End::onStartHide()
{
    Splash::onStartHide();
    
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.0);
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
                }
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
                        
                        this->mTextName->runAction(CCFadeIn::create(this->mCoinsAnimationCurrentTime));
                        this->mTextCountValue->runAction(CCFadeIn::create(this->mCoinsAnimationCurrentTime));
                        this->mTextValue->runAction(CCFadeIn::create(this->mCoinsAnimationCurrentTime));
                        
                        this->mCoinsAnimationCurrentTime = 0;
                        this->mCoinsAnimationCounter++;
                    case 1:
                        if(this->mComboCount < Game::COMBO_COUNT+80) this->mComboCount++;
                        this->mTextCountValue->setString(ccsf("%d", this->mComboCount));
                        
                        if(this->mComboCount >= Game::COMBO_COUNT+80 && this->mTextName->numberOfRunningActions() <= 0)
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
                        
                        this->mCoinsAnimationCurrentTime = 0;
                        this->mCoinsAnimationCounter++;
                    case 3:
                        if(this->mFlayerCount < Game::FLAYER_COUNT+80) this->mFlayerCount++;
                        this->mTextCountValue->setString(ccsf("%d", this->mFlayerCount));
                        
                        if(this->mFlayerCount >= Game::FLAYER_COUNT+80 && this->mTextName->numberOfRunningActions() <= 0)
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
                        this->mTextName->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(60), Options::CAMERA_CENTER_Y - Utils::coord(20));
                        this->mTextName->setText(Options::TEXT_END[6]);
                        this->mTextName->runAction(CCFadeIn::create(this->mCoinsAnimationCurrentTime));
                        
                        this->mTextName->animate(0);
                        
                        this->mIsCoinsAnimationCurrentRunning = false;
                        break;
                }
                
                if(this->mEarnedCoins < this->mTotalEarnedCoins+200) this->mEarnedCoins++;
                this->mTextValue->setString(ccsf("%d", this->mEarnedCoins));
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
    }
}

#endif