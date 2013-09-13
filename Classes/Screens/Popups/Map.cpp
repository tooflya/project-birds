#ifndef CONST_MAP
#define CONST_MAP

#include "Map.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Map* Map::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Map::~Map()
{
}

Map::Map(CCNode* pParent) :
    Popup(pParent)
    {
        m_Instance = this;
    }

Map* Map::create(CCNode* pParent)
{
    Map* popup = new Map(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void Map::onTouchButtonsCallback(const int pAction, const int pID)
{
    Map* pSender = static_cast<Map*>(Map::m_Instance);
    
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

void Map::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
}

void Map::onShow()
{
    Popup::onShow();
}

void Map::onHide()
{
    Popup::onHide();
}

void Map::show()
{
    Popup::show();
}

void Map::hide()
{
    Popup::hide();
}

#endif