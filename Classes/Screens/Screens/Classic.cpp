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
    this->mConfetti->release();
    this->mLifes->release();
    this->mStars->release();
}

Classic::Classic() :
    Game()
    {
        this->mEventLayer = CCLayer::create();
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas3.plist");
        
        CCSpriteBatchNode* spriteBatch1 = CCSpriteBatchNode::create("TextureAtlas3.pvr.ccz");
        CCSpriteBatchNode* spriteBatch2 = CCSpriteBatchNode::create("TextureAtlas7.pvr.ccz");
        CCSpriteBatchNode* spriteBatch3 = CCSpriteBatchNode::create("TextureAtlas8.pvr.ccz");
        CCSpriteBatchNode* spriteBatch4 = CCSpriteBatchNode::create("TextureAtlas10.pvr.ccz");
        CCSpriteBatchNode* spriteBatch5 = CCSpriteBatchNode::create("TextureAtlas11.pvr.ccz");
        CCSpriteBatchNode* spriteBatch6 = CCSpriteBatchNode::create("TextureAtlas6.pvr.ccz");
        
        this->addChild(spriteBatch6);
        this->addChild(spriteBatch1);
        this->addChild(spriteBatch2);
        this->addChild(spriteBatch3);
        this->addChild(spriteBatch4);
        this->addChild(spriteBatch5);
        
        this->mBackground = Entity::create("temp_level_bg@2x.png", spriteBatch6);
        this->mCountIcon = Entity::create("game_gui_count_pic@2x.png", spriteBatch2);

        this->mConfetti = EntityManager::create(300, Confetti::create(), spriteBatch2);
        this->mStars = EntityManager::create(1000, StarParticle::create(), spriteBatch2);

        this->mCountText = Text::create((Textes) {"0", Options::FONT, 80, -1}, this);
        this->mBestCountText = Text::create(Options::TEXT_GAME_BEST, this);

        this->mGameStartText = Text::create(Options::TEXT_GAME_START_STRING_1, this);

        this->mPauseButton = Button::create((EntityStructure) {"game_gui_btn_sprite@2x.png", 1, 1, 116, 0, 116, 78}, spriteBatch2, Options::BUTTONS_ID_GAME_PAUSE, onTouchButtonsCallback);

        this->mDust = EntityManager::create(100, Dust::create(), spriteBatch2);
        this->mMarks = EntityManager::create(200, Mark::create(), spriteBatch2);
        this->mFeathers = EntityManager::create(100, Feather::create(), spriteBatch2);
        this->mBirds = EntityManager::create(20, Bird::create(), spriteBatch4);
        this->mSpecialBirds = EntityManager::create(10, SpecialBird::create(), spriteBatch5);
        this->mExplosions = EntityManager::create(10, Explosion::create(), spriteBatch2);
        this->mExplosionsBasic = EntityManager::create(10, ExplosionBasic::create(), spriteBatch2);
        this->mLifes = EntityManager::create(3, Entity::create("lifes@2x.png", 1, 2), spriteBatch2);

        this->mLevelUpText = Text::create(Options::TEXT_GAME_CLASSIC_LEVEL_UP, this);
        this->mBonusTimeText = Text::create(Options::TEXT_GAME_CLASSIC_BONUS_TIME, this);

        this->mEventPanel = EventPanel::create(this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        ((Entity*) this->mEventPanel)->create()->setCenterPosition(Options::CAMERA_CENTER_X, -Utils::coord(100));
        this->mCountIcon->create()->setCenterPosition(Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(64));

        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(48));

        this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mBestCountText->setCenterPosition(Utils::coord(10) + this->mBestCountText->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(128));
        this->mLevelUpText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(400));
        this->mLevelUpText->setOpacity(0);
        this->mBonusTimeText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(400));
        this->mBonusTimeText->setOpacity(0);

        //this->mPausePopup = new ClassicPause(this);
        this->mEndScreen = ClassicEnd::create(Splash::TYPE_CLASSIC, this);

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

        for(int i = 0; i < 3; i++)
        {
            Entity* entity = static_cast<Entity*>(this->mLifes->create());

            float x, y;

            switch(i)
            {
                default:
                    x = 80;
                    y = 45;
                break;
                case 1:
                    x = 80;
                    y = 41;
                break;
                case 2:
                    x = 75;
                    y = 36;
                break;
            }

            entity->setScale(1.0 - Utils::coord(0.15) * i);
            entity->setCenterPosition(Utils::coord(45) + Utils::coord(x) * i, Utils::coord(y));
        }

        this->addChild(this->mEventLayer);

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
        Entity* entity = static_cast<Entity*>(this->mLifes->objectAtIndex(i));

        entity->setCurrentFrameIndex(0);
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
    
    this->mCountText->setString(Utils::intToString(CURRENT_COUNT).c_str());
    this->mCountText->setCenterPosition(Utils::coord(120) + this->mCountText->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(64));

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
    this->mBestCountText->setCenterPosition(Utils::coord(10) + this->mBestCountText->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(128));
    
    this->mCountText->setString(Utils::intToString(CURRENT_COUNT).c_str());
    this->mCountText->setCenterPosition(Utils::coord(120) + this->mCountText->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(64));
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
}

void Classic::onEnter()
{
    Game::onEnter();

    LIFES = -1;
    BEST_COUNT = AppDelegate::getBestResult(0);

    for(int i = 0; i < 3; i++)
    {
        Entity* entity = static_cast<Entity*>(this->mLifes->objectAtIndex(i));

        entity->setCurrentFrameIndex(0);
    }
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

        Entity* entity = static_cast<Entity*>(this->mLifes->objectAtIndex(++LIFES));

        float scale = entity->getScale();

        entity->setCurrentFrameIndex(1);
        entity->setScale(1.3);
        entity->runAction(CCScaleTo::create(0.5, scale));

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