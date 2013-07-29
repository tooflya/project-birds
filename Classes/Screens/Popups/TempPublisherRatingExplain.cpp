#ifndef CONST_TEMPPUBLISHERRATINGEXPLAIN
#define CONST_TEMPPUBLISHERRATINGEXPLAIN

#include "TempPublisherRatingExplain.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

TempPublisherRatingExplain* TempPublisherRatingExplain::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

TempPublisherRatingExplain::TempPublisherRatingExplain(CCNode* pParent) :
    Popup(pParent)
    {
        this->mCloseButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 162, 162, 162}, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        this->mOkButton = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_BUYITEM_BUY, onTouchButtonsCallback);
        
        this->mCloseButton->create()->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        
        this->mOkButton->create()->setCenterPosition(this->mBackground->getWidth() / 2, Utils::coord(40));
        this->mOkButton->setText(Options::TEXT_MODEHELP_OK);

        Text* text1 = new Text(Options::TEXT_PUBLISHER_STRING_1, ccp(Utils::coord(500), 0), this->mBackground);
        Text* text2 = new Text(Options::TEXT_PUBLISHER_STRING_2, ccp(Utils::coord(500), 0), this->mBackground);

        text1->setCenterPosition(this->mBackground->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(100));
        text2->setCenterPosition(this->mBackground->getWidth() / 2, Options::CAMERA_CENTER_Y - Utils::coord(250));
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void TempPublisherRatingExplain::onTouchButtonsCallback(const int pAction, const int pID)
{
    TempPublisherRatingExplain* pSender = (TempPublisherRatingExplain*) TempPublisherRatingExplain::m_Instance;
    
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

// ===========================================================
// Override Methods
// ===========================================================

#endif