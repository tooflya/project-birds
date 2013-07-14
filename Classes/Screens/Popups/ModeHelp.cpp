#ifndef CONST_MODEHELP
#define CONST_MODEHELP

#include "ModeHelp.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ModeHelp* ModeHelp::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

ModeHelp::ModeHelp(CCNode* pParent) :
    Popup(pParent)
    {
        this->mCloseButton = new Button("btn_sprite@2x.png", 2, 3, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        
        this->mOkButton = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        
        this->mListBorders = new BatchEntityManager(2, new Entity("about_scroll_border_small@2x.png"), this->mBackground);
        
        this->mCloseButton->create();
        this->mCloseButton->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mCloseButton->setCurrentFrameIndex(3);
        
        this->mOkButton->create()->setCenterPosition(this->mBackground->getWidth() / 2, Utils::coord(40));
        this->mOkButton->setText(Options::TEXT_MODEHELP_OK);
        
        this->mListBorders->create();
        this->mListBorders->create();
        
        ((Entity*) this->mListBorders->objectAtIndex(0))->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(325));
        ((Entity*) this->mListBorders->objectAtIndex(1))->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(325));
        
        ((Entity*) this->mListBorders->objectAtIndex(0))->setScaleY(1);
        ((Entity*) this->mListBorders->objectAtIndex(1))->setScaleY(-1);
        
        this->mList = new ModeHelpList(this->mBackground);
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void ModeHelp::onTouchButtonsCallback(const int pAction, const int pID)
{
    ModeHelp* pSender = (ModeHelp*) ModeHelp::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            default:
                
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

void ModeHelp::onHide()
{
    this->mList->setPosition(ccp(0, 0));
}

// ===========================================================
// Override Methods
// ===========================================================

#endif