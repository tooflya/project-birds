#ifndef CONST_PROGRESS
#define CONST_PROGRESS

#include "Progress.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Progress* Progress::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Progress::Progress()
{
    this->mResetPopup = new ResetProgress(this);
    
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_PROGRESS_BACK, onTouchButtonsCallback);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mBackButton->create()->setCurrentFrameIndex(1);
    this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));
    
    this->mResetButton = new Button("settings_btn_big@2x.png", 1, 1, this, Options::BUTTONS_ID_PROGRESS_RESET, onTouchButtonsCallback);
    
    this->mResetButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(200));
    this->mResetButton->setText(Options::TEXT_PROGRESS_RESET);
    
    Text* text1 = new Text(Options::TEXT_PROGRESS_STRING_1, CCSize(Utils::coord(700), 0), this);
    
    text1->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300)));
    
    m_Instance = this;
}

// ===========================================================
// Methods
// ===========================================================

void Progress::onTouchButtonsCallback(const int pAction, const int pID)
{
    Progress* pSender = static_cast<Progress*>(Progress::m_Instance);
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_PROGRESS_BACK:
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
                
            break;
            case Options::BUTTONS_ID_PROGRESS_RESET:
                
                pSender->mResetPopup->show();
                
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