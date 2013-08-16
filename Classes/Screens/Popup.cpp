#ifndef CONST_POPUP
#define CONST_POPUP

#include "Popup.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Popup::~Popup()
{
    this->removeAllChildrenWithCleanup(true);
}

Popup::Popup(CCNode* pParent)
{
    this->init();
    
    this->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
    
    this->mParent = pParent;

    this->mSpriteBatch = CCSpriteBatchNode::create("TextureAtlas4.pvr.ccz");
    
    this->mBackground = Entity::create("popup_bg@2x.png", this->mSpriteBatch);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mShowed = false;

    this->mShowAnimationRunning = false;
    this->mHideAnimationRunning = false;
    
    this->ignoreAnchorPointForPosition(false);
    this->setAnchorPoint(ccp(0.5, 0.5));
    this->setScale(0.0);
    
    this->addChild(this->mSpriteBatch);

    this->scheduleUpdate();
}

// ===========================================================
// Methods
// ===========================================================

void Popup::show()
{
    if(this->mShowed) return;
    
    this->mParent->addChild(this, 1000);

    this->mShowed = true;
    this->mShowAnimationRunning = true;
    
    this->mShowAnimationCount = 0;
    this->mShowAnimationTimeElapsed = 0;
    
    this->mShowAnimationTime = 0.3;
    this->runAction(CCScaleTo::create(this->mShowAnimationTime, 1.2));
}

void Popup::hide()
{
    if(!this->mShowed) return;
    
    this->mHideAnimationRunning = true;
    
    this->mHideAnimationCount = 0;
    this->mHideAnimationTimeElapsed = 0;
    
    this->mHideAnimationTime = 0.1;
    this->runAction(CCScaleTo::create(this->mHideAnimationTime, 1.2));
}

bool Popup::isShowed()
{
    return this->mShowed;
}

void Popup::onShow()
{
}

void Popup::onHide()
{
    this->removeFromParentAndCleanup(false);

    this->mShowed = false;
}

// ===========================================================
// Override Methods
// ===========================================================

void Popup::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
    
    if(this->mShowAnimationRunning)
    {
        this->mShowAnimationTimeElapsed += pDeltaTime;
        
        if(this->mShowAnimationTimeElapsed >= this->mShowAnimationTime)
        {
            this->mShowAnimationTimeElapsed = 0;
            
            switch(this->mShowAnimationCount)
            {
                case 0:
                    this->mShowAnimationTime = 0.2;
                    this->runAction(CCScaleTo::create(this->mShowAnimationTime, 0.8));
                break;
                case 1:
                    this->mShowAnimationTime = 0.2;
                    this->runAction(CCScaleTo::create(this->mShowAnimationTime, 1.0));
                break;
                case 2:
                    this->mShowAnimationRunning = false;
                    
                    this->onShow();
                break;
            }
            
            this->mShowAnimationCount++;
        }
    }
    
    if(this->mHideAnimationRunning)
    {
        this->mHideAnimationTimeElapsed += pDeltaTime;
        
        if(this->mHideAnimationTimeElapsed >= this->mHideAnimationTime)
        {
            this->mHideAnimationTimeElapsed = 0;
            
            switch(this->mHideAnimationCount)
            {
                case 0:
                    this->mHideAnimationTime = 0.2;
                    this->runAction(CCScaleTo::create(this->mHideAnimationTime, 0.0));
                break;
                case 1:
                    this->mHideAnimationRunning = false;
                    
                    this->onHide();
                break;
            }
            
            this->mHideAnimationCount++;
        }
    }
}

void Popup::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    CCLayer::onEnter();
}

void Popup::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    
    CCLayer::onExit();
}

bool Popup::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    return this->mShowed;
}

#endif