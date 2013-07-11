#ifndef CONST_CREDITS
#define CONST_CREDITS

#include "Credits.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Credits* Credits::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Credits::Credits()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_CREDITS_BACK, onTouchButtonsCallback);
    
    this->mListBorders = new BatchEntityManager(2, new Entity("about_scroll_border@2x.png"), this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mBackButton->create()->setCurrentFrameIndex(1);
    this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));
    
    this->mListBorders->create();
    this->mListBorders->create();
    
    ((Entity*) this->mListBorders->objectAtIndex(0))->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(500));
    ((Entity*) this->mListBorders->objectAtIndex(1))->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(400));
    
    ((Entity*) this->mListBorders->objectAtIndex(0))->setScaleY(1);
    ((Entity*) this->mListBorders->objectAtIndex(1))->setScaleY(-1);
    
    this->mList = new CreditsList(this);
    
    m_Instance = this;
}

// ===========================================================
// Methods
// ===========================================================

void Credits::onTouchButtonsCallback(const int pAction, const int pID)
{
    Credits* pSender = (Credits*) Credits::m_Instance;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_CREDITS_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);

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
// Virtual Methods
// ===========================================================

void Credits::onEnter()
{
    Screen::onEnter();
    
    this->mList->setPosition(ccp(0, 0));
    this->mList->runAction(CCMoveTo::create(10.0, ccp(this->mList->getPosition().x, this->mList->getPosition().y + Utils::coord(750))));
}

void Credits::onExit()
{
    Screen::onExit();
}

#endif