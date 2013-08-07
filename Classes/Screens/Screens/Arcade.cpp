#ifndef CONST_ARCADE
#define CONST_ARCADE

#include "Arcade.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Arcade* Arcade::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Arcade::Arcade() :
    Game()
    {
        this->mEventLayer = CCLayer::create();

        this->mBackground = new Entity("game_gui_bg_summer@2x.png", this);
        this->mCountIcon = new Entity("game_gui_count_pic@2x.png", this);
        this->mTimeIcon = new Clock(this->mEventLayer);

        this->mCountText = new Text((Textes) {"0", Options::FONT, 80, -1}, this);
        this->mBestCountText = new Text(Options::TEXT_GAME_BEST, this);
        this->mTimeText[0] = new Text(Options::TEXT_GAME_ARCADE_TIME_REMAINING, this->mEventLayer);
        this->mTimeText[1] = new Text((Textes) {"0:00", Options::FONT, 64, -1}, this->mEventLayer);
        this->mTimeText[2] = new Text((Textes) {".0000", Options::FONT, 28, -1}, this->mEventLayer);

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
        this->mCountIcon->create()->setCenterPosition(Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(64));
        this->mTimeIcon->create()->setCenterPosition(Utils::coord(64), Utils::coord(80));

        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(48));

        this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mTimeText[1]->setCenterPosition(Utils::coord(120) + this->mTimeText[1]->getWidth() / 2, Utils::coord(45));
        this->mTimeText[2]->setCenterPosition(Utils::coord(255) + this->mTimeText[2]->getWidth() / 2, Utils::coord(28));

        this->mPausePopup = new Pause(this);
        this->mEndScreen = new End(Splash::TYPE_ARCADE, this);

        this->addChild(this->mEventLayer);

        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void Arcade::onTouchButtonsCallback(const int pAction, const int pID)
{
    Arcade* pSender = static_cast<Arcade*>(Arcade::m_Instance);

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

void Arcade::startGame()
{
    Game::startGame();

    this->mTimeIcon->start();
}

// ===========================================================
// Override Methods
// ===========================================================

void Arcade::update(float pDeltaTime)
{
    Game::update(pDeltaTime);

    if(this->mGamePaused)
    {
        if(!this->mEndScreen->isShowed())
        {
            this->startGame();
        }
    }
    else
    {
        this->mCountText->setString(Utils::intToString(CURRENT_COUNT).c_str());
        this->mCountText->setCenterPosition(Utils::coord(120) + this->mCountText->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(64));

        if(this->mTimeIcon->getTimeElapsed() >= 60.0)
        {
            this->mGamePaused = true;

            this->mEndScreen->show();
        }
        else
        {
            int timer = 60.0 - this->mTimeIcon->getTimeElapsed();
            int last_timer = 1000.0 - (this->mTimeIcon->getTimeElapsed() - floor(this->mTimeIcon->getTimeElapsed())) * 1000.0;

            this->mTimeText[1]->setString(((timer >= 10 ? "0:" : "0:0") + Utils::intToString(timer)).c_str());
            this->mTimeText[2]->setString(("." + Utils::intToString(last_timer)).c_str());
    
            this->mTimeText[1]->setCenterPosition(Utils::coord(120) + this->mTimeText[1]->getWidth() / 2, Utils::coord(45));
            this->mTimeText[2]->setCenterPosition(this->mTimeText[1]->getCenterX() +  this->mTimeText[1]->getWidth() / 2 + this->mTimeText[2]->getWidth() / 2 - Utils::coord(5), Utils::coord(30));
        }
    }
}

void Arcade::onGameStarted()
{
    this->mEventPanel->setEvent(1)->show();
}

void Arcade::onEnter()
{
    Game::onEnter();

    this->mTimeText[0]->setCenterPosition(Utils::coord(120) + this->mTimeText[0]->getWidth() / 2, Utils::coord(100));
    this->mBestCountText->setCenterPosition(Utils::coord(10) + this->mBestCountText->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(128));
}

void Arcade::onExit()
{
    Game::onExit();
}

#endif