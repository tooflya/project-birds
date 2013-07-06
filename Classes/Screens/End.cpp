#ifndef CONST_END
#define CONST_END

#include "End.h"

// ===========================================================
// Inner Classes
// ===========================================================

class EndMenuButton : public Entity
{
    public:
    EndMenuButton(CCNode* pParent) :
    Entity("end_lvl_btn_sprite@2x.png", 3, 1, pParent)
    {
        this->create()->setCurrentFrameIndex(0);
        this->setCenterPosition(this->getParent()->getContentSize().width / 2 - Utils::coord(200), this->getParent()->getContentSize().height / 2 - Utils::coord(300));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
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

class EndRestartButton : public Entity
{
    public:
    EndRestartButton(CCNode* pParent) :
    Entity("end_lvl_btn_sprite@2x.png", 3, 1, pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(this->getParent()->getContentSize().width / 2, this->getParent()->getContentSize().height / 2 - Utils::coord(340));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
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

class EndContinueButton : public Entity
{
    public:
    EndContinueButton(CCNode* pParent) :
    Entity("end_lvl_btn_sprite@2x.png", 3, 1, pParent)
    {
        this->create()->setCurrentFrameIndex(2);
        this->setCenterPosition(this->getParent()->getContentSize().width / 2 + Utils::coord(200), this->getParent()->getContentSize().height / 2 - Utils::coord(320));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
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

End::End(CCNode* pParent) :
Splash(pParent)
{
    this->mParts = new BatchEntityManager(2, new Entity("end_lvl_bg_sprite@2x.png", 2, 1), this);
    
    Entity* part;
    
    part = (Entity*) this->mParts->create();
    part->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT + part->getHeight() / 2);
    part->setCurrentFrameIndex(0);
    
    part = (Entity*) this->mParts->create();
    part->setCenterPosition(Options::CAMERA_CENTER_X, -part->getHeight() / 2);
    part->setCurrentFrameIndex(1);
    
    this->mBackground = new Entity("end_lvl_bg_popup@2x.png", this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackground->setVisible(false);
    
    this->mMenuButton = new EndMenuButton(this->mBackground);
    this->mRestartButton = new EndRestartButton(this->mBackground);
    this->mContinueButton = new EndContinueButton(this->mBackground);
    
    this->setVisible(false);
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

#endif