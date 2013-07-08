#ifndef CONST_SETTINGS
#define CONST_SETTINGS

#include "Settings.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Settings* Settings::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Settings::Settings()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_SETTINGS_BACK, onTouchButtonsCallback);
    this->mRateButton = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_SETTINGS_RATE, onTouchButtonsCallback);
    this->mCreditsButton = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_SETTINGS_CREDITS, onTouchButtonsCallback);
    this->mSoundButton = new Button("btn_mfx_sprite@2x.png", 2, 2, this, Options::BUTTONS_ID_SETTINGS_SOUND, onTouchButtonsCallback);
    this->mMusicButton = new Button("btn_mfx_sprite@2x.png", 2, 2, this, Options::BUTTONS_ID_SETTINGS_MUSIC, onTouchButtonsCallback);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

    this->mBackButton->create()->setCurrentFrameIndex(1);
    this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));

    this->mSoundButton->create()->setCurrentFrameIndex(1);
    this->mSoundButton->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(300));

    this->mMusicButton->create()->setCurrentFrameIndex(0);
    this->mMusicButton->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(300));
       
    this->mRateButton->create()->setCurrentFrameIndex(1);
    this->mRateButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mRateButton->setText("rate", 64);

    this->mCreditsButton->create()->setCurrentFrameIndex(1);
    this->mCreditsButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));
    this->mCreditsButton->setText("credits", 64);

    m_Instance = this;
}

// ===========================================================
// Methods
// ===========================================================

void Settings::onTouchButtonsCallback(const int pAction, const int pID)
{
    Settings* pSender = (Settings*) Settings::m_Instance;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_SETTINGS_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);

                break;
                case Options::BUTTONS_ID_SETTINGS_RATE:

                    // TODO: Open rate splash screen.

                break;
                case Options::BUTTONS_ID_SETTINGS_MUSIC:

                    Options::MUSIC_ENABLE = !Options::MUSIC_ENABLE;
                    
                    if(Options::MUSIC_ENABLE)
                    {
                        pSender->mMusicButton->setCurrentFrameIndex(0);
                    }
                    else
                    {
                        pSender->mMusicButton->setCurrentFrameIndex(2);
                    }

                break;
                case Options::BUTTONS_ID_SETTINGS_SOUND:
        
                    Options::SOUND_ENABLE = !Options::SOUND_ENABLE;
                    
                    if(Options::SOUND_ENABLE)
                    {
                        pSender->mSoundButton->setCurrentFrameIndex(1);
                    }
                    else
                    {
                        pSender->mSoundButton->setCurrentFrameIndex(3);
                    }

                break;
                case Options::BUTTONS_ID_SETTINGS_CREDITS:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_CREDITS);

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
// Virtual Methods
// ===========================================================

#endif