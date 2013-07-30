#ifndef CONST_MENU
#define CONST_MENU

#include "Menu.h"

#include "Shop.h"

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
    this->mBackground = new Entity("main_menu_bg@2x.png", this);
    this->mPlayDecoration = new Entity("main_menu_btn_bg_play@2x.png", this);
    this->mPlayButton = new PlayButton("play_btn_animation@2x.png", 6, 2, this, Options::BUTTONS_ID_MENU_PLAY, onTouchButtonsCallback);
    this->mShopButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 324, 0, 162, 162}, this, Options::BUTTONS_ID_MENU_SHOP, onTouchButtonsCallback);
    this->mTwitterButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 0, 0, 162, 162}, this, Options::BUTTONS_ID_MENU_TWITTER, onTouchButtonsCallback);
    this->mFacebookButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 0, 162, 162, 162}, this, Options::BUTTONS_ID_MENU_FACEBOOK, onTouchButtonsCallback);
    this->mSettingsButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 0, 324, 162, 162}, this, Options::BUTTONS_ID_MENU_SETTINGS, onTouchButtonsCallback);
    
    this->mExitPopup = new Exit(this);
    this->mRatePopup = new PleaseRate(this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mShopButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(270));
    this->mSettingsButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
    this->mTwitterButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(270), Utils::coord(100));
    this->mFacebookButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));
    this->mPlayDecoration->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(20), Options::CAMERA_CENTER_Y - Utils::coord(80));
    this->mPlayButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(20), Options::CAMERA_CENTER_Y - Utils::coord(80));
    
    this->mPlayDecorationColorUpdateTimeElapsed = 0;

    SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music-1.mp3", true); 

    if(!Options::MUSIC_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    }
    
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

                    Shop::ACTION = 0;
                    
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

                break;
                case Options::BUTTONS_ID_MENU_FACEBOOK:

                    // TODO: Call JNI

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

    this->mPlayDecorationColorUpdateTimeElapsed += pDeltaTime;

    if(this->mPlayDecorationColorUpdateTimeElapsed >= 1.0)
    {
        this->mPlayDecorationColorUpdateTimeElapsed = 0;

        this->mPlayDecoration->runAction(CCTintTo::create(1.0, Utils::randomf(0.0, 255.0), Utils::randomf(0.0, 255.0), Utils::randomf(0.0, 255.0)));
    }
}

void Menu::onEnter()
{
    Screen::onEnter();

    // TODO: Open rate window.
}

void Menu::onExit()
{
    Screen::onExit();
}

#endif