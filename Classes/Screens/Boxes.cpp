#ifndef CONST_BOXES
#define CONST_BOXES

#include "Boxes.h"

// ===========================================================
// Inner Classes
// ===========================================================

class BackButton : public Entity
{
public:
    BackButton(CCNode* pParent) :
    Entity("btn_sprite@2x.png", 2, 3, pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Utils::coord(100), Utils::coord(100));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
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

Boxes::Boxes()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new BackButton(this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

#endif