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
        this->mBackground = new Entity("game_gui_bg_summer@2x.png", this);
        this->mRestartButton = new Button((EntityStructure) {"game_gui_btn_sprite@2x.png", 1, 1, 0, 0, 117, 78}, this, Options::BUTTONS_ID_GAME_RESTART, Classic::onTouchButtonsCallback);
        this->mPauseButton = new Button((EntityStructure) {"game_gui_btn_sprite@2x.png", 1, 1, 117, 0, 117, 78}, this, Options::BUTTONS_ID_GAME_PAUSE, Classic::onTouchButtonsCallback);

        this->mBirds = new BatchEntityManager(10, new Bird(), this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(70), Options::CAMERA_HEIGHT - Utils::coord(50));
        this->mRestartButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(50));

        this->mPausePopup = new Pause(this);

        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void Classic::onTouchButtonsCallback(const int pAction, const int pID)
{
    Classic* pSender = (Classic*) Classic::m_Instance;

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

void Classic::onEnter()
{
    Screen::onEnter();

    this->mBirds->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
}

void Classic::onExit()
{
    Screen::onExit();
}

#endif