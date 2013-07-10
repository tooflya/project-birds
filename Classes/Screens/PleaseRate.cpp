#ifndef CONST_PLEASERATE
#define CONST_PLEASERATE

#include "PleaseRate.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

PleaseRate* PleaseRate::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

PleaseRate::PleaseRate(Screen* pScreen) :
    Popup(pScreen)
    {
        this->mCloseButton = new Button("btn_sprite@2x.png", 2, 3, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
    
        this->mRateButton = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_RATE_RATE, onTouchButtonsCallback);
        
        this->mCloseButton->create();
        this->mCloseButton->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mCloseButton->setCurrentFrameIndex(3);
        
        Text* text1 = new Text(Options::TEXT_RATE_STRING_1, this->mBackground);
        Text* text2 = new Text(Options::TEXT_RATE_STRING_2, this->mBackground);
        Text* text3 = new Text(Options::TEXT_RATE_STRING_3, this->mBackground);
        Text* text4 = new Text(Options::TEXT_RATE_STRING_4, this->mBackground);
        
        text1->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(50)));
        text2->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(50)));
        text3->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(150)));
        text4->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(250)));
        
        this->mRateButton->create()->setCenterPosition(this->mBackground->getWidth() / 2, Utils::coord(40));
        this->mRateButton->setText(Options::TEXT_RATE_NOW);
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void PleaseRate::onTouchButtonsCallback(const int pAction, const int pID)
{
    PleaseRate* pSender = (PleaseRate*) PleaseRate::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_RATE_RATE:
                
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

#endif