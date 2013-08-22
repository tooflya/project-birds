#ifndef CONST_CLASSICEND
#define CONST_CLASSICEND

#include "ClassicEnd.h"

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ClassicEnd* ClassicEnd::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

ClassicEnd::ClassicEnd(int pType, Screen* pParent) :
    End(pType, pParent, onTouchButtonsCallback)
    {
        m_Instance = this;
    }

ClassicEnd* ClassicEnd::create(int pType, Screen* pParent)
{
    ClassicEnd* screen = new ClassicEnd(pType, pParent);
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void ClassicEnd::onTouchButtonsCallback(const int pAction, const int pID)
{
    ClassicEnd* pSender = static_cast<ClassicEnd*>(ClassicEnd::m_Instance);

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