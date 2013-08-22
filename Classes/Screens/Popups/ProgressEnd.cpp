#ifndef CONST_PROGRESSEND
#define CONST_PROGRESSEND

#include "ProgressEnd.h"

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ProgressEnd* ProgressEnd::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

ProgressEnd::ProgressEnd(int pType, Screen* pParent) :
    End(pType, pParent, onTouchButtonsCallback)
    {
        m_Instance = this;
    }

ProgressEnd* ProgressEnd::create(int pType, Screen* pParent)
{
    ProgressEnd* screen = new ProgressEnd(pType, pParent);
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void ProgressEnd::onTouchButtonsCallback(const int pAction, const int pID)
{
    ProgressEnd* pSender = static_cast<ProgressEnd*>(ProgressEnd::m_Instance);

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