#ifndef CONST_MENU
#define CONST_MENU

#include "Menu.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Menu* Menu::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Menu::Menu()
{
    this->mBackgroundDecoration = new Entity("main_menu_bg_back@2x.png", this);
    this->mBackground = new Entity("main_menu_bg@2x.png", this);
    this->mPlayDecoration = new Entity("main_menu_btn_bg_play@2x.png", this);
    this->mPlayButton = new PlayButton("play_btn_animation@2x.png", 6, 2, this, Options::BUTTONS_ID_MENU_PLAY, onTouchButtonsCallback);
    this->mShopButton = new Button("main_menu_btn_shop@2x.png", 1, 1, this, Options::BUTTONS_ID_MENU_SHOP, onTouchButtonsCallback);
    this->mTwitterButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_MENU_TWITTER, onTouchButtonsCallback);
    this->mFacebookButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_MENU_FACEBOOK, onTouchButtonsCallback);
    this->mSettingsButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_MENU_SETTINGS, onTouchButtonsCallback);
    
    this->mExitPopup = new Exit(this);
    this->mRatePopup = new PleaseRate(this);
    
    this->mBackgroundDecoration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50));
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mShopButton->create()->setCenterPosition(Utils::coord(170), Utils::coord(270));
    this->mShopButton->setRotation(10);
    this->mSettingsButton->create()->setCurrentFrameIndex(4);
    this->mSettingsButton->setCenterPosition(Utils::coord(100), Utils::coord(100));
    this->mTwitterButton->create()->setCurrentFrameIndex(0);
    this->mTwitterButton->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(270), Utils::coord(100));
    this->mFacebookButton->create()->setCurrentFrameIndex(2);
    this->mFacebookButton->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));
    this->mPlayDecoration->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(40), Options::CAMERA_CENTER_Y - Utils::coord(40));
    this->mPlayButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(40), Options::CAMERA_CENTER_Y - Utils::coord(40));
    
    //SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music-1.mp3");
    
    m_Instance = this;
}

// ===========================================================
// Methods
// ===========================================================

void Menu::onTouchButtonsCallback(const int pAction, const int pID)
{
    Menu* pSender = (Menu*) Menu::m_Instance;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MENU_SHOP:
                    
                    AppDelegate::screens->set(0.5, Screen::SCREEN_SHOP);

                break;
                case Options::BUTTONS_ID_MENU_PLAY:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MODE);

                break;
                case Options::BUTTONS_ID_MENU_SETTINGS:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);

                break;
                case Options::BUTTONS_ID_MENU_TWITTER:

                    // TODO: Call JNI
                    pSender->mExitPopup->show();

                break;
                case Options::BUTTONS_ID_MENU_FACEBOOK:

                    // TODO: Call JNI
                    pSender->mRatePopup->show();

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

void Menu::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    this->mPlayDecoration->setRotation(this->mPlayDecoration->getRotation() + 1.0);
}

#endif