#ifndef CONST_CREDITS
#define CONST_CREDITS

#include "Credits.h"

// ===========================================================
// Inner Classes
// ===========================================================

class CreditsBackButton : public Entity
{
public:
    CreditsBackButton(CCNode* pParent) :
    Entity("btn_sprite@2x.png", 2, 3, pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Utils::coord(100), Utils::coord(100));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        Entity::onExit();
    }
};

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Credits::Credits()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new CreditsBackButton(this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

#endif