#ifndef CONST_LANGUAGE
#define CONST_LANGUAGE

#include "Language.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Language* Language::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Language::Language()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_LANGUAGE_BACK, onTouchButtonsCallback);
    
    this->mLanguages[0] = new Button("flag_sprite_big@2x.png", 1, 2, this, Options::BUTTONS_ID_LANGUAGE_L_EN, onTouchButtonsCallback);
    this->mLanguages[1] = new Button("flag_sprite_big@2x.png", 1, 2, this, Options::BUTTONS_ID_LANGUAGE_L_RU, onTouchButtonsCallback);
    
    this->mLanguageIndicator = new Entity("settings_lang_check@2x.png", this);
    
    this->mLanguages[0]->setCurrentFrameIndex(0);
    this->mLanguages[1]->setCurrentFrameIndex(1);
    
    this->mLanguages[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(120));
    this->mLanguages[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(120));
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mBackButton->create()->setCurrentFrameIndex(1);
    this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));
    
    this->mLanguageIndicator->create();
    
    m_Instance = this;
}

// ===========================================================
// Methods
// ===========================================================

void Language::onTouchButtonsCallback(const int pAction, const int pID)
{
    Language* pSender = (Language*) Language::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_LANGUAGE_BACK:
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_RU:
                
                Options::CURRENT_LANGUAGE = 1;
                
                Options::changeLanguage();
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_EN:
                
                Options::CURRENT_LANGUAGE = 0;
                
                Options::changeLanguage();
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
                
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

void Language::onEnter()
{
    Screen::onEnter();
    
    this->mLanguageIndicator->setCenterPosition(this->mLanguages[Options::CURRENT_LANGUAGE]->getCenterX() + this->mLanguages[Options::CURRENT_LANGUAGE]->getWidth() / 2 - Utils::coord(32), this->mLanguages[Options::CURRENT_LANGUAGE]->getCenterY() - this->mLanguages[Options::CURRENT_LANGUAGE]->getHeight() / 2 + Utils::coord(48));
}

void Language::onExit()
{
    Screen::onExit();
}

#endif