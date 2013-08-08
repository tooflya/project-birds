#ifndef CONST_CLASSIC
#define CONST_CLASSIC

#include "Classic.h"

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

Classic::Classic() :
    Game()
    {
        this->mEventLayer = CCLayer::create();

        this->mBackground = new Entity("game_gui_bg_summer@2x.png", this);
        this->mCountIcon = new Entity("game_gui_count_pic@2x.png", this);

        this->mConfetti = new BatchEntityManager(300, new Confetti(), this);
        this->mStars = new BatchEntityManager(1000, new StarParticle(), this);

        this->mCountText = new Text((Textes) {"0", Options::FONT, 80, -1}, this);
        this->mBestCountText = new Text(Options::TEXT_GAME_BEST, this);
        this->mLevelUpText = new Text(Options::TEXT_GAME_CLASSIC_LEVEL_UP, this);

        this->mGameStartText = new Text(Options::TEXT_GAME_START_STRING_1, this);

        this->mPauseButton = new Button((EntityStructure) {"game_gui_btn_sprite@2x.png", 1, 1, 116, 0, 116, 78}, this, Options::BUTTONS_ID_GAME_PAUSE, onTouchButtonsCallback);

        this->mDust = new BatchEntityManager(100, new Dust(), this);
        this->mMarks = new BatchEntityManager(200, new Mark(), this);
        this->mFeathers = new BatchEntityManager(100, new Feather(), this);
        this->mBirds = new BatchEntityManager(10, new Bird(), this);
        this->mExplosions = new BatchEntityManager(10, new Explosion(), this);
        this->mExplosionsBasic = new BatchEntityManager(10, new ExplosionBasic(), this);
        this->mLifes = new BatchEntityManager(3, new Entity("lifes@2x.png", 1, 2), this->mEventLayer);

        this->mEventPanel = new EventPanel(this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mEventPanel->create()->setCenterPosition(Options::CAMERA_CENTER_X, -Utils::coord(100));
        this->mCountIcon->create()->setCenterPosition(Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(64));

        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(48));

        this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mBestCountText->setCenterPosition(Utils::coord(10) + this->mBestCountText->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(128));
        this->mLevelUpText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(400));
        this->mLevelUpText->setOpacity(0);

        this->mPausePopup = new ClassicPause(this);
        this->mEndScreen = new ClassicEnd(Splash::TYPE_CLASSIC, this);

        this->mLevelUpTime = 30.0;
        this->mLevelUpTimeElaspsed = 0;

        this->mLevelUpAnimationTime = 4.0;
        this->mLevelUpAnimationTimeElapsed = 0;

        this->mChalangeTime = 110.0;
        this->mChalangeTimeElapsed = 0;

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

    this->mLevelUpTimeElaspsed = 0;
    this->mChalangeTimeElapsed = 0;

    this->mConfetti->clear();

    for(int i = 0; i < 3; i++)
    {
        Entity* entity = static_cast<Entity*>(this->mLifes->objectAtIndex(i));

        entity->setCurrentFrameIndex(0);
    }
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
}

void Classic::stopChalange()
{
    this->mChalange = false;

    this->mLevelUpTime = 0;
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

            if(this->mChalangeTimeElapsed >= 10.0) // TODO: Adjust chalange time.
            {
                this->mChalangeTimeElapsed = 0;

                this->stopChalange();
            }

            for(int i = 0; i < 2; i++)
            {
                this->mStars->create();
            }
        }
        else
        {
            this->mLevelUpTimeElaspsed += pDeltaTime;
            this->mChalangeTimeElapsed += pDeltaTime;

            if(this->mLevelUpTimeElaspsed >= this->mLevelUpTime)
            {
                this->mLevelUpTimeElaspsed = 0;

                this->levelUp();
            }

            if(this->mChalangeTimeElapsed >= this->mChalangeTime)
            {
                this->mChalangeTimeElapsed = 0;

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

    this->mLevelUpTimeElaspsed = 0;
    this->mChalangeTimeElapsed = 0;
}

void Classic::onGameEnd()
{
    this->mGamePaused = true;
    this->mChalange = false;

    this->mLevelUpTimeElaspsed = 0;
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