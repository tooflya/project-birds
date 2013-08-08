#ifndef CONST_PROGRESSES
#define CONST_PROGRESSES

#include "Progresses.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Progresses* Progresses::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Progresses::Progresses() :
    Game()
    {
        this->mEventLayer = CCLayer::create();

        this->mBackground = new Entity("game_gui_bg_summer@2x.png", this);

        this->mGameStartText = new Text(Options::TEXT_GAME_START_STRING_1, this);

        this->mPauseButton = new Button((EntityStructure) {"game_gui_btn_sprite@2x.png", 1, 1, 116, 0, 116, 78}, this, Options::BUTTONS_ID_GAME_PAUSE, onTouchButtonsCallback);

        this->mDust = new BatchEntityManager(100, new Dust(), this);
        this->mMarks = new BatchEntityManager(200, new Mark(), this);
        this->mFeathers = new BatchEntityManager(100, new Feather(), this);
        this->mBirds = new BatchEntityManager(10, new Bird(), this);
        this->mExplosions = new BatchEntityManager(10, new Explosion(), this);
        this->mExplosionsBasic = new BatchEntityManager(10, new ExplosionBasic(), this);

        this->mEventPanel = new EventPanel(this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mEventPanel->create()->setCenterPosition(Options::CAMERA_CENTER_X, -Utils::coord(100));

        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(48));

        this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

        this->mPausePopup = new ProgressPause(this);
        this->mEndScreen = new ProgressEnd(Splash::TYPE_PROGRESS, this);

        this->addChild(this->mEventLayer);

        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void Progresses::onTouchButtonsCallback(const int pAction, const int pID)
{
    Progresses* pSender = static_cast<Progresses*>(Progresses::m_Instance);

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

// ===========================================================
// Override Methods
// ===========================================================

void Progresses::update(float pDeltaTime)
{
    Game::update(pDeltaTime);
}

void Progresses::onGameStarted()
{
    BEST_COUNT = AppDelegate::getBestResult(0);
}

void Progresses::onGameEnd()
{
    this->mGamePaused = true;

    this->mEndScreen->show();

    if(BEST_COUNT > AppDelegate::getBestResult(0))
    {
        AppDelegate::setBestResult(BEST_COUNT, 0);
    }
}

void Progresses::onEnter()
{
    Screen::onEnter();
}

void Progresses::onExit()
{
    Screen::onExit();
}

#endif