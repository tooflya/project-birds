#ifndef CONST_PAUSE
#define CONST_PAUSE

#include "Pause.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Pause* Pause::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Pause::Pause(CCNode* pParent) :
    Popup(pParent)
    {
        this->mCloseButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 162, 162, 162}, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        this->mMenuButton = new Button("settings_btn_big@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_MENU, onTouchButtonsCallback);
        this->mRestartButton = new Button("settings_btn_big@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_RESTART, onTouchButtonsCallback);
        this->mContinueButton = new Button("settings_btn_big@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_CONTINUE, onTouchButtonsCallback);

        this->mCloseButton->create()->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mMenuButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2, this->mBackground->getHeight()  / 2 + Utils::coord(150));
        this->mRestartButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2, this->mBackground->getHeight()  / 2);
        this->mContinueButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2, this->mBackground->getHeight()  / 2 - Utils::coord(150));
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void Pause::onTouchButtonsCallback(const int pAction, const int pID)
{
    Pause* pSender = (Pause*) Pause::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_PAUSE_MENU:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_PAUSE_RESTART:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_PAUSE_CONTINUE:
                
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
// Override Methods
// ===========================================================

void Pause::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
}

void Pause::show()
{
    Popup::show();
}

void Pause::hide()
{
    Popup::hide();
}

void Pause::onShow()
{
    Popup::onShow();
}

void Pause::onHide()
{
    Popup::onHide();
}

#endif