#ifndef CONST_CLASSIC
#define CONST_CLASSIC

#include "Classic.h"

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Classic* Classic::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Classic::~Classic()
{
    CC_SAFE_RELEASE_NULL(this->mConfetti);
}

Classic::Classic() :
    Game()
    {
        Loader::TYPE = 1;
        
        this->mEventLayer = CCLayer::create();
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas3.plist");
        
        SpriteBatch* spriteBatch1 = SpriteBatch::create("TextureAtlas3");
        SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas7");
        SpriteBatch* spriteBatch3 = SpriteBatch::create("TextureAtlas8");
        SpriteBatch* spriteBatch4 = SpriteBatch::create("TextureAtlas10");
        SpriteBatch* spriteBatch5 = SpriteBatch::create("TextureAtlas11");
        SpriteBatch* spriteBatch6 = SpriteBatch::create("TextureAtlas6");
        SpriteBatch* spriteBatch7 = SpriteBatch::create("TextureAtlas14");
        SpriteBatch* spriteBatch8 = SpriteBatch::create("TextureAtlas6");
        SpriteBatch* spriteBatch9 = SpriteBatch::create("TextureAtlas12");
        
        this->mGameLayer->addChild(spriteBatch6);
        
        this->e2 = Effect::create();
        this->mGameLayer->addChild(this->e2);
        
        this->mGameLayer->addChild(spriteBatch7);
        this->mGameLayer->addChild(spriteBatch1);
        this->mGameLayer->addChild(spriteBatch2);
        this->mGameLayer->addChild(spriteBatch3);
        this->mGameLayer->addChild(spriteBatch4);
        this->mGameLayer->addChild(spriteBatch5);
        this->mGameLayer->addChild(spriteBatch9);
        this->mMenuLayer->addChild(spriteBatch8);
        
        this->mBackground = Entity::create("temp_level_bg@2x.png", spriteBatch6);
        
        #if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
        if(Options::DEVICE_TYPE != Options::DEVICE_TYPE_IPOD4)
        {
            this->mBackgroundLights[0] = Entity::create("bg_light_main@2x.png", spriteBatch6);
            this->mBackgroundLights[0]->setAnchorPoint(ccp(0.0, 0.5));
            for(int i = 1; i < 4; i++)
            {
                this->mBackgroundLights[i] = Entity::create("bg_light_1.png", spriteBatch6);
                this->mBackgroundLights[i]->setAnchorPoint(ccp(0.0, 0.5));
            }
            for(int i = 4; i < 7; i++)
            {
                this->mBackgroundLights[i] = Entity::create("bg_light_1.png", spriteBatch6);
                this->mBackgroundLights[i]->setAnchorPoint(ccp(0.0, 0.5));
            }
        }
        #endif
        
        this->mGamePanel = Entity::create("game_panel@2x.png", spriteBatch8);
        this->mTextAreas[0] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextAreas[1] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextAreas[2] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextIcons[0] = Entity::create("game_panel_counter@2x.png", spriteBatch8);
        this->mTextIcons[1] = Entity::create("game_panel_counter_best@2x.png", spriteBatch8);
        this->mTextIcons[2] = Entity::create("game_panel_goldlife@2x.png", spriteBatch8);
        this->mHearts[0] = Entity::create("game_panel_game_life@2x.png", 2, 1, spriteBatch8);
        this->mHearts[1] = Entity::create("game_panel_game_life@2x.png", 2, 1, spriteBatch8);
        this->mHearts[2] = Entity::create("game_panel_game_life@2x.png", 2, 1, spriteBatch8);
        this->mGoldLifeButton = Button::create((EntityStructure) {"game_panel_plus@2x.png", 1, 1, 0, 0, 78, 72}, spriteBatch8, Options::BUTTONS_ID_GAME_PAUSE, this);
        
        this->mGamePanel->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextAreas[0]->create()->setCenterPosition(this->mTextAreas[0]->getWidth() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextAreas[1]->create()->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidth() + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->mTextIcons[0]->create()->setCenterPosition(this->mTextAreas[0]->getCenterX() - this->mTextAreas[0]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextIcons[1]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() - this->mTextAreas[1]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->mHearts[0]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidth() - Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mHearts[1]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidth() + Utils::coord(20), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mHearts[2]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidth() + Utils::coord(70), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->mTextAreas[2]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidth() * 2 + Utils::coord(65), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->mTextIcons[2]->create()->setCenterPosition(this->mTextAreas[2]->getCenterX() - this->mTextAreas[2]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->mGoldLifeButton->create()->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidth() / 2 - this->mGoldLifeButton->getWidth() / 4, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);

        this->mConfetti = EntityManager::create(300, Confetti::create(), spriteBatch2);
        this->mStars = EntityManager::create(1000, StarParticle::create(), spriteBatch2);

        this->mCountText = Text::create((Textes) {"0", Options::FONT, 32, -1}, this);
        this->mBestCountText = Text::create(Options::TEXT_GAME_BEST, this);
        this->mGoldLifesCount = Text::create((Textes) {"5", Options::FONT, 32, -1}, this);

        this->mGameStartText = Text::create(Options::TEXT_GAME_START_STRING_1, this);

        this->mPauseButton = Button::create((EntityStructure) {"game_panel_pause@2x.png", 1, 1, 0, 0, 78, 72}, spriteBatch8, Options::BUTTONS_ID_GAME_PAUSE, this);

        this->mDust = EntityManager::create(100, Dust::create(), spriteBatch2);
        this->mMarks = EntityManager::create(300, Mark::create(), spriteBatch2);
        this->mFeathers = EntityManager::create(300, Feather::create(), spriteBatch2);
        this->mBirds = EntityManager::create(20, Bird::create(false), spriteBatch4);
        this->mSpecialBirds = EntityManager::create(10, SpecialBird::create(), spriteBatch5);
        this->mPirateBox = PirateBox::create(spriteBatch5);
        this->mExplosions = EntityManager::create(20, Explosion::create(), spriteBatch2);
        this->mExplosionsBasic = EntityManager::create(20, ExplosionBasic::create(), spriteBatch2);
        this->mCoins = EntityManager::create(50, AnimatedCoin::create("coins@2x.png", 0.7), spriteBatch2);
        this->mSilverCoins = EntityManager::create(50, AnimatedCoin::create("coins_silver@2x.png", 0.7), spriteBatch2);
        this->mArrows = EntityManager::create(5, Entity::create("bomb_arrow.png"), spriteBatch2);
        this->mPredictionIcons = EntityManager::create(5, Entity::create("bomb_ico.png"), spriteBatch2);
        this->mZombieExplosions = EntityManager::create(300, ZombieExplosion::create(), spriteBatch7);
        this->mGeneralExplosions = EntityManager::create(100, GeneralExplosion::create(), spriteBatch9);
        
        this->mBonusCircles = EntityManager::create(200, Entity::create("bonus-animation@2x.png"), spriteBatch6);

        this->mLevelUpText = Text::create(Options::TEXT_GAME_CLASSIC_LEVEL_UP, this);
        this->mBonusTimeText = Text::create(Options::TEXT_GAME_CLASSIC_BONUS_TIME, this);

        this->mEventPanel = EventPanel::create(this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        
        #if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
        if(Options::DEVICE_TYPE != Options::DEVICE_TYPE_IPOD4)
        {
            this->mBackgroundLights[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(480), Options::CAMERA_CENTER_Y - Utils::coord(50));
            
            for(int i = 1; i < 4; i++)
            {
                this->mBackgroundLights[i]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(480), Options::CAMERA_CENTER_Y + Utils::coord(50) * (i - 1));
            }
            for(int i = 1; i < 4; i++)
            {
                this->mBackgroundLights[i + 3]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(480), Options::CAMERA_CENTER_Y + Utils::coord(50) * (i - 1));
            }
        }
        #endif
        
        ((Entity*) this->mEventPanel)->create()->setCenterPosition(Options::CAMERA_CENTER_X, -Utils::coord(100));

        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(32), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);

        this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mBestCountText->setCenterPosition(Utils::coord(10) + this->mBestCountText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mLevelUpText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(400));
        this->mLevelUpText->setOpacity(0);
        this->mBonusTimeText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(400));
        this->mBonusTimeText->setOpacity(0);
        
        this->mGoldLifesCount->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidth() / 2 - Utils::coord(50), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->e4[0] = Entity::create("box_laser_green@2x.png", spriteBatch7);
        this->e4[1] = Entity::create("box_laser_red@2x.png", spriteBatch7);
        this->e4[2] = Entity::create("box_laser_green@2x.png", spriteBatch7);
        this->e4[3] = Entity::create("box_laser_red@2x.png", spriteBatch7);
        this->e4[4] = Entity::create("box_laser_green@2x.png", spriteBatch7);
        this->e4[5] = Entity::create("box_laser_red@2x.png", spriteBatch7);
        this->e4[6] = Entity::create("box_laser_green@2x.png", spriteBatch7);
        this->e4[7] = Entity::create("box_laser_red@2x.png", spriteBatch7);
        
        this->e4[0]->setAnchorPoint(ccp(0.5, 0));
        this->e4[1]->setAnchorPoint(ccp(0.5, 1));
        this->e4[2]->setAnchorPoint(ccp(0.5, 1));
        this->e4[3]->setAnchorPoint(ccp(0.5, 0));
        this->e4[4]->setAnchorPoint(ccp(0.5, 0));
        this->e4[5]->setAnchorPoint(ccp(0.5, 1));
        this->e4[6]->setAnchorPoint(ccp(0.5, 1));
        this->e4[7]->setAnchorPoint(ccp(0.5, 0));
        
        this->e1 = Entity::create("freeze_bg.png", spriteBatch7);
        this->e3[0] = Entity::create("box@2x.png", spriteBatch7);
        this->e3[1] = Entity::create("box@2x.png", spriteBatch7);
        this->e3[2] = Entity::create("box@2x.png", spriteBatch7);
        this->e3[3] = Entity::create("box@2x.png", spriteBatch7);
        
        this->e4[4]->setRotation(-90);
        this->e4[5]->setRotation(-90);
        this->e4[6]->setRotation(-90);
        this->e4[7]->setRotation(-90);
        
        this->e3[1]->setScaleY(-1);
        this->e3[2]->setScaleX(-1);
        this->e3[2]->setScaleY(-1);
        this->e3[3]->setScaleX(-1);
        
        this->mRobotParts = EntityManager::create(8, RobotoPart::create(0), spriteBatch7);
        this->mGunLaser = Entity::create("gun_laser.png", 4, 1, spriteBatch7);
        this->mGun = RobotoGun::create(spriteBatch7);
        
        this->mGunLaser->setAnchorPoint(ccp(0.5, 1));
        this->mGunLaser->animate(0.04);
        
        this->mRains = EntityManager::create(300, Rain::create(), spriteBatch7);
        this->mRainsCircles = EntityManager::create(300, RainCircle::create(), spriteBatch7);

        this->mPausePopup = Pause::create(this);
        this->mEndScreen = End::create(Splash::TYPE_CLASSIC, this);

        this->mLevelUpTime = 30.0;
        this->mLevelUpTimeElapsed = 0;

        this->mLevelUpAnimationTime = 4.0;
        this->mLevelUpAnimationTimeElapsed = 0;

        this->mChalangeTime = 90.0 - 1.0;
        this->mChalangeTimeElapsed = 0;

        this->mAlgorithmBirdsRemainig = 6;
        this->mAlgorithmBirdsTime = 1.5;

        this->mAlgorithmBirdsTime1 = 2.0;
        this->mAlgorithmBirdsTime2 = 7.0;

        this->mIsLevelUpAnimation = false;

        this->addChild(this->mEventLayer);
        
        /** Correction of text areas position */
        
        if(Options::CAMERA_WIDTH == 960)
        {
            // TODO : Maybe some fixes of panel textareas?
        }
        else
        {
        }

        m_Instance = this;
    }

Classic* Classic::create()
{
    Classic* screen = new Classic();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Classic::onTouchButtonsCallback(const int pAction, const int pID)
{
    Classic* pSender = static_cast<Classic*>(Classic::m_Instance);

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_GAME_PAUSE:

                    pSender->mPausePopup->show();

                break;
                case Options::BUTTONS_ID_GAME_RESTART:

                    // TODO: Restart level.

                break;
            }
        break;

        case Options::BUTTONS_ACTION_ONBEGIN:
        break;

        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void Classic::startGame()
{
    Game::startGame();
    
    this->mLevelUpTimeElapsed = 0;
    this->mChalangeTimeElapsed = 0;

    this->mConfetti->clear();

    this->mLevelUpText->setOpacity(0);
    this->mBonusTimeText->setOpacity(0);

    for(int i = 0; i < 3; i++)
    {
        this->mHearts[i]->setCurrentFrameIndex(1);
    }
    
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.0);
}

void Classic::levelUp()
{
    this->throwConfetti();

    this->mLevelUpText->runAction(CCFadeIn::create(3.0));

    this->mIsLevelUpAnimation = true;

    if(Options::SOUND_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_BONUS_GONG);
    }

    Game::HEALTH += 10;
}

void Classic::throwConfetti()
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

void Classic::runChalange()
{
    this->mChalange = true;

    this->mSoundChalangeTimeElapsed = 2.95;

    this->mBonusTimeText->runAction(CCFadeIn::create(1.0));
            
    if(Options::SOUND_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_BONUS_TIME[0]);
    }
    
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.3);
}

void Classic::stopChalange()
{
    this->mChalange = false;
            
    if(Options::SOUND_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_BONUS_TIME[2]);
    }
    
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1.0);
}

// ===========================================================
// Override Methods
// ===========================================================

void Classic::update(float pDeltaTime)
{
    Game::update(pDeltaTime);

    if(this->mIsLevelUpAnimation)
    {
        this->mLevelUpAnimationTimeElapsed += pDeltaTime;

        if(this->mLevelUpAnimationTimeElapsed >= this->mLevelUpAnimationTime)
        {
            this->mLevelUpAnimationTimeElapsed = 0;
            this->mIsLevelUpAnimation = false;

            this->mLevelUpText->runAction(CCFadeOut::create(1.0));
        }
    }

    if(this->mGamePaused)
    {
        if(!this->mEndScreen->isShowed())
        {
            this->startGame();
        }
    }
    else if(this->mGameRunning && !this->mGamePaused)
    {
        if(this->mChalange)
        {
            this->mChalangeTimeElapsed += pDeltaTime;

            if(this->mChalangeTimeElapsed >= 13.6) // TODO: Adjust chalange time.
            {
                this->mChalangeTimeElapsed = 0;
                this->mLevelUpTimeElapsed = 0;

                this->stopChalange();
            }

            for(int i = 0; i < 2; i++)
            {
                static_cast<StarParticle*>(this->mStars->create())->setType(1)->onCreate();
            }

            if(this->mChalangeTimeElapsed >= 3.0) // TODO: Adjust chalange time.
            {
                this->mSoundChalangeTimeElapsed += pDeltaTime;

                if(this->mBonusTimeText->getOpacity() == 255.0)
                {
                    this->mBonusTimeText->setOpacity(250.0);
                    this->mBonusTimeText->runAction(CCFadeTo::create(1.0, 0.0));
                }

                if(this->mSoundChalangeTimeElapsed >= 3.39)
                {
                    this->mSoundChalangeTimeElapsed = 0;

                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_BONUS_TIME[1]);
                    }
                }
            }
        }
        else if(!this->mChalange)
        {
            this->mLevelUpTimeElapsed += pDeltaTime;
            this->mChalangeTimeElapsed += pDeltaTime;

            if(this->mLevelUpTimeElapsed >= this->mLevelUpTime)
            {
                this->mLevelUpTimeElapsed = 0;

                this->levelUp();
            }

            if(this->mChalangeTimeElapsed >= this->mChalangeTime)
            {
                this->mChalangeTimeElapsed = 0;
                this->mLevelUpTimeElapsed = 0;

                this->runChalange();
            }
        }
    }

    this->mBestCountText->setString((Options::TEXT_GAME_BEST.string + Utils::intToString(BEST_COUNT)).c_str());
    this->mBestCountText->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidth() / 2 - this->mBestCountText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mCountText->setString(Utils::intToString(CURRENT_COUNT).c_str());
    this->mCountText->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidth() / 2 - this->mCountText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
}

void Classic::onGameStarted()
{
    LIFES = -1;
    BEST_COUNT = AppDelegate::getBestResult(0);

    this->mLevelUpTimeElapsed = 0;
    this->mChalangeTimeElapsed = 0;
}

void Classic::onGameEnd()
{
    this->mGamePaused = true;
    this->mChalange = false;

    this->mLevelUpTimeElapsed = 0;
    this->mChalangeTimeElapsed = 0;

    this->mEndScreen->show();

    if(BEST_COUNT > AppDelegate::getBestResult(0))
    {
        AppDelegate::setBestResult(BEST_COUNT, 0);
    }
    else
    {
        AppDelegate::removeCoins(1, Options::SAVE_DATA_COINS_TYPE_LIVES);
    }
}

void Classic::onEnter()
{
    Game::onEnter();

    LIFES = -1;
    BEST_COUNT = AppDelegate::getBestResult(0);

    for(int i = 0; i < 3; i++)
    {
        this->mHearts[i]->setCurrentFrameIndex(1);
    }
    
    GAME_TYPE = GAME_TYPE_CLASSIC;
}

void Classic::onEnterTransitionDidFinish()
{
    Game::onEnterTransitionDidFinish();
}

void Classic::removeLife()
{
    if(LIFES < 3 && !this->mGamePaused && this->mGameRunning)
    {
        Game::removeLife();
        
        this->mHearts[++LIFES]->setCurrentFrameIndex(0);

        if(LIFES >= 2)
        {
            this->onGameEnd();
        }
    }
}

void Classic::onExit()
{
    Game::onExit();
}

#endif