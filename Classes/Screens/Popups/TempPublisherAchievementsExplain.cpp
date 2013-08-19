#ifndef CONST_TEMPPUBLISHERACHIEVEMENTSEXPLAIN
#define CONST_TEMPPUBLISHERACHIEVEMENTSEXPLAIN

#include "TempPublisherAchievementsExplain.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

TempPublisherAchievementsExplain* TempPublisherAchievementsExplain::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

TempPublisherAchievementsExplain::~TempPublisherAchievementsExplain()
{
}

TempPublisherAchievementsExplain::TempPublisherAchievementsExplain(CCNode* pParent) :
    Popup(pParent)
    {
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        this->mOkButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_BUYITEM_BUY, onTouchButtonsCallback);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        this->mOkButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mOkButton->setText(Options::TEXT_MODEHELP_OK);

        Text* text1 = Text::create(Options::TEXT_PUBLISHER_STRING_1, ccp(Utils::coord(500), 0), this);
        Text* text2 = Text::create(Options::TEXT_PUBLISHER_STRING_3, ccp(Utils::coord(500), 0), this);

        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(250));
        text2->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(100));
        
        m_Instance = this;
    }

TempPublisherAchievementsExplain* TempPublisherAchievementsExplain::create(CCNode* pParent)
{
    TempPublisherAchievementsExplain* popup = new TempPublisherAchievementsExplain(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void TempPublisherAchievementsExplain::onTouchButtonsCallback(const int pAction, const int pID)
{
    TempPublisherAchievementsExplain* pSender = (TempPublisherAchievementsExplain*) TempPublisherAchievementsExplain::m_Instance;
    
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