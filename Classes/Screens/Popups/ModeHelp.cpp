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

ModeHelp::~ModeHelp()
{
    this->mList->release();
}

ModeHelp::ModeHelp(CCNode* pParent) :
    Popup(pParent)
    {
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        
        this->mOkButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        
        this->mListBorders[0] = Entity::create("about_scroll_border_small@2x.png", this->mSpriteBatch);
        this->mListBorders[1] = Entity::create("about_scroll_border_small@2x.png", this->mSpriteBatch);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        this->mOkButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mOkButton->setText(Options::TEXT_MODEHELP_OK);
        
        this->mListBorders[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(325));
        this->mListBorders[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(325));
        
        this->mListBorders[0]->setScaleY(1);
        this->mListBorders[1]->setScaleY(-1);
        
        this->mList = new ModeHelpList(this);
        
        m_Instance = this;
    }

ModeHelp* ModeHelp::create(CCNode* pParent)
{
    ModeHelp* popup = new ModeHelp(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
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
    Popup::onHide();
    
    this->mList->setPosition(ccp(0, 0));
}

// ===========================================================
// Override Methods
// ===========================================================

#endif