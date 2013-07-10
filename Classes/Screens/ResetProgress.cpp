#ifndef CONST_RESETPROGRESS
#define CONST_RESETPROGRESS

#include "ResetProgress.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ResetProgress* ResetProgress::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

ResetProgress::ResetProgress(Screen* pScreen) :
    Popup(pScreen)
    {
        this->mCloseButton = new Button("btn_sprite@2x.png", 2, 3, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
    
        this->mResetButton = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_RESET_RESET, onTouchButtonsCallback);
        
        this->mCloseButton->create();
        this->mCloseButton->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mCloseButton->setCurrentFrameIndex(3);
        
        Text* text1 = new Text(Options::TEXT_RESET_STRING_1, this->mBackground);
        Text* text2 = new Text(Options::TEXT_RESET_STRING_2, this->mBackground);
        Text* text3 = new Text(Options::TEXT_RESET_STRING_3, this->mBackground);
        Text* text4 = new Text(Options::TEXT_RESET_STRING_4, this->mBackground);
        
        text1->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(50)));
        text2->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(50)));
        text3->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(150)));
        text4->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(250)));
        
        this->mResetButton->create()->setCenterPosition(this->mBackground->getWidth() / 2, Utils::coord(40));
        this->mResetButton->setText(Options::TEXT_RESET_RESET);
        
        this->mAction = false;
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void ResetProgress::onTouchButtonsCallback(const int pAction, const int pID)
{
    ResetProgress* pSender = (ResetProgress*) ResetProgress::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_RESET_RESET:
                
                pSender->mAction = true;
                
                pSender->hide();
                
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

void ResetProgress::onShow()
{
    
}

void ResetProgress::onHide()
{
    if(this->mAction)
    {
        AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);
    }
    
    this->mAction = false;
}

#endif