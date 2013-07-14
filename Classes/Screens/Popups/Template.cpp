#ifndef CONST_TEMPLATE
#define CONST_TEMPLATE

#include "Template.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Template* Template::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Template::Template(CCNode* pParent) :
    Popup(pParent)
    {
    }

// ===========================================================
// Methods
// ===========================================================

void Template::onTouchButtonsCallback(const int pAction, const int pID)
{
    Template* pSender = (Template*) Template::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
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

void Template::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
}

void Template::show()
{
    Popup::show();
}

void Template::hide()
{
    Popup::hide();
}

void Template::onShow()
{
}

void Template::onHide()
{
}

#endif