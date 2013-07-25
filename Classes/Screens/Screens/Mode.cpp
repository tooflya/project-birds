#ifndef CONST_MODE
#define CONST_MODE

#include "Mode.h"

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Mode* Mode::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Mode::Mode()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new Button((EntityStructure){"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, this, Options::BUTTONS_ID_MODE_BACK, onTouchButtonsCallback);
    this->mHelpButton = new Button((EntityStructure){"btn_sprite@2x.png", 1, 1, 162, 324, 162, 162}, this, Options::BUTTONS_ID_MODE_HELP, onTouchButtonsCallback);

    this->mClassicMode = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_MODE_CLASSIC, onTouchButtonsCallback);
    this->mArcadeMode = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_MODE_ARCADE, onTouchButtonsCallback);
    this->mProgressMode = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_MODE_PROGRESS, onTouchButtonsCallback);

    this->mAchievementsButton = new Button((EntityStructure){"btn_sprite@2x.png", 1, 1, 324, 0, 162, 162}, this, Options::BUTTONS_ID_MODE_ACHIEVEMENTS, onTouchButtonsCallback);
    this->mLeaderboardButton = new Button((EntityStructure){"btn_sprite@2x.png", 1, 1, 324, 162, 162, 162}, this, Options::BUTTONS_ID_MODE_LEADERBOARD, onTouchButtonsCallback);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
    this->mHelpButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(65), Options::CAMERA_HEIGHT - Utils::coord(65));
    
    this->mClassicMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(350));
    this->mArcadeMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(150));
    this->mProgressMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50));
    
    this->mAchievementsButton->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(100), Options::CAMERA_CENTER_Y - Utils::coord(250));
    this->mLeaderboardButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(100), Options::CAMERA_CENTER_Y - Utils::coord(250));

    this->mClassicMode->setText(Options::TEXT_MODE_CLASSIC);
    this->mArcadeMode->setText(Options::TEXT_MODE_ARCADE);
    this->mProgressMode->setText(Options::TEXT_MODE_PROGRESS);
    
    this->mHelpPopup = new ModeHelp(this);

    m_Instance = this;
}

// ===========================================================
// Methods
// ===========================================================

void Mode::onTouchButtonsCallback(const int pAction, const int pID)
{
    Mode* pSender = (Mode*) Mode::m_Instance;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MODE_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);

                break;
                case Options::BUTTONS_ID_MODE_CLASSIC:

                    Loader::ACTION = 0;

                    AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);

                break;
                case Options::BUTTONS_ID_MODE_ARCADE:

                    Loader::ACTION = 1;

                    AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);

                break;
                case Options::BUTTONS_ID_MODE_PROGRESS:

                    Loader::ACTION = 2;

                    AppDelegate::screens->set(0.5, Screen::SCREEN_LEVELS);

                break;
                case Options::BUTTONS_ID_MODE_HELP:

                    pSender->mHelpPopup->show();

                break;
                case Options::BUTTONS_ID_MODE_ACHIEVEMENTS:

                    //

                break;
                case Options::BUTTONS_ID_MODE_LEADERBOARD:

                    //

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

#endif