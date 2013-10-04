#ifndef CONST_PROGRESSEND
#define CONST_PROGRESSEND

#include "ProgressEnd.h"

#include "Loader.h"
#include "Progresses.h"

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
    Progresses* pGame = static_cast<Progresses*>(pSender->getParent());

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
                    
                    pGame->onShow();

                break;
                case Options::BUTTONS_ID_END_CONTINUE:
                    
                    Game::LEVEL++;
                    
                    pSender->hide();
                    
                    pGame->onShow();

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