#ifndef CONST_ARCADEEND
#define CONST_ARCADEEND

#include "ArcadeEnd.h"

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ArcadeEnd* ArcadeEnd::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

ArcadeEnd::ArcadeEnd(int pType, Screen* pParent) :
    End(pType, pParent, onTouchButtonsCallback)
    {
        m_Instance = this;
    }

ArcadeEnd* ArcadeEnd::create(int pType, Screen* pParent)
{
    ArcadeEnd* screen = new ArcadeEnd(pType, pParent);
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void ArcadeEnd::onTouchButtonsCallback(const int pAction, const int pID)
{
    ArcadeEnd* pSender = static_cast<ArcadeEnd*>(ArcadeEnd::m_Instance);

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_END_MENU:
                    
                    pSender->hide();
                    
                    Loader::ACTION = 3;

                    AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);

                break;
                case Options::BUTTONS_ID_END_RESTART:

                    pSender->hide();

                break;
                case Options::BUTTONS_ID_END_CONTINUE:
                    
                    pSender->hide();

                break;
                case Options::BUTTONS_ID_END_SHOP:
                    
                    pSender->hide(); // TODO: Open shop screen.

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