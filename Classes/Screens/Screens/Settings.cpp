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
    this->mBackgroundDecorations[0] = new Entity("bg_detail_stripe@2x.png", this);
    this->mBackgroundDecorations[1] = new Entity("bg_detail_settings@2x.png", this);
    this->mBackButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, this, Options::BUTTONS_ID_SETTINGS_BACK, onTouchButtonsCallback);
    this->mCreditsButton = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_SETTINGS_CREDITS, onTouchButtonsCallback);
    this->mProgressButton = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_SETTINGS_RATE, onTouchButtonsCallback);
    this->mMoreButton = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_SETTINGS_MORE, onTouchButtonsCallback);
    this->mLanguageButton = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_SETTINGS_LANGUAGE, onTouchButtonsCallback);
    this->mSoundButton = new Button("btn_sfx_mfx_ach_lead_sprite@2x.png", 3, 2, this, Options::BUTTONS_ID_SETTINGS_SOUND, onTouchButtonsCallback);
    this->mMusicButton = new Button("btn_sfx_mfx_ach_lead_sprite@2x.png", 3, 2, this, Options::BUTTONS_ID_SETTINGS_MUSIC, onTouchButtonsCallback);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

    this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));

    this->mSoundButton->create()->setCurrentFrameIndex(1);
    this->mSoundButton->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(310));

    this->mMusicButton->create()->setCurrentFrameIndex(0);
    this->mMusicButton->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(310));
    
    this->mCreditsButton->create()->setCurrentFrameIndex(1);
    this->mCreditsButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(500));
    this->mCreditsButton->setText(Options::TEXT_SETTINGS_CREDITS);
       
    this->mProgressButton->create()->setCurrentFrameIndex(1);
    this->mProgressButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));
    this->mProgressButton->setText(Options::TEXT_SETTINGS_PROGRESS);
    
    this->mMoreButton->create()->setCurrentFrameIndex(1);
    this->mMoreButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100));
    this->mMoreButton->setText(Options::TEXT_SETTINGS_MORE);
    
    this->mLanguageButton->create()->setCurrentFrameIndex(1);
    this->mLanguageButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(100));
    this->mLanguageButton->setText(Options::TEXT_SETTINGS_LANGUAGE);
    
    this->mLanguage = new Entity("flag_sprite_small@2x.png", 1, 2, this->mLanguageButton);
    this->mLanguage->setCurrentFrameIndex(Options::CURRENT_LANGUAGE);
    this->mLanguage->create()->setCenterPosition(this->mLanguageButton->getWidth(), this->mLanguageButton->getHeight() / 2);
    
    this->mBackgroundDecorations[0]->create()->setCenterPosition(Utils::coord(192), Options::CAMERA_HEIGHT - Utils::coord(103));
    this->mBackgroundDecorations[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(165), Utils::coord(128));

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

                    AppDelegate::screens->set(0.5, Screen::SCREEN_PROGRESS);

                break;
                case Options::BUTTONS_ID_SETTINGS_MUSIC:

                    Options::MUSIC_ENABLE = !Options::MUSIC_ENABLE;
                    
                    if(Options::MUSIC_ENABLE)
                    {
                        pSender->mMusicButton->setCurrentFrameIndex(0);
                    }
                    else
                    {
                        pSender->mMusicButton->setCurrentFrameIndex(3);
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
                        pSender->mSoundButton->setCurrentFrameIndex(4);
                    }

                break;
                case Options::BUTTONS_ID_SETTINGS_CREDITS:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_CREDITS);

                break;
                case Options::BUTTONS_ID_SETTINGS_MORE:
                    
                    AppDelegate::screens->set(0.5, Screen::SCREEN_MORE);
                    
                break;
                case Options::BUTTONS_ID_SETTINGS_LANGUAGE:
                    
                    AppDelegate::screens->set(0.5, Screen::SCREEN_LANGUAGE);
                    
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

void Settings::onEnter()
{
    Screen::onEnter();
    
    this->mLanguage->setCurrentFrameIndex(Options::CURRENT_LANGUAGE);
}

void Settings::onExit()
{
    Screen::onExit();
}

#endif