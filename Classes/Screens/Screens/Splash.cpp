#ifndef CONST_SPLASH
#define CONST_SPLASH

#include "Splash.h"

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

Splash::~Splash()
{
    CC_SAFE_RELEASE(this->mParts);
    CC_SAFE_RELEASE(this->mScaleLayer);
    
    this->removeAllChildrenWithCleanup(true);
}

Splash::Splash(Screen* pParent) :
	mType(0),
	mShowBackgroundTime(0),
	mShowBackgroundTimeElapsed(0),
	mHideBackgroundTime(0),
	mHideBackgroundTimeElapsed(0),
	mShowBackground(0),
	mHideBackground(0),
	mShowed(0),
	mParent(0),
	mBackground(0),
	mParts(0),
	mScaleLayer(0)
	{
		this->mParent = pParent;
    
		this->mShowBackground = false;
		this->mHideBackground = false;
		this->mShowed = false;
        this->mShowedCompleted = false;
        
        this->setRegisterAsTouchable(true);
	}

// ===========================================================
// Methods
// ===========================================================

void Splash::show()
{
    this->mParent->addChild(this, 500);

    Entity* part;
    part = (Entity*) this->mParts->objectAtIndex(0);
    part->runAction(CCMoveTo::create(0.2, ccp(part->getPosition().x, Options::CAMERA_HEIGHT - part->getContentSize().height / 2 - Options::CAMERA_CENTER_Y)));
    
    part = (Entity*) this->mParts->objectAtIndex(1);
    part->runAction(CCMoveTo::create(0.2, ccp(part->getPosition().x, part->getContentSize().height / 2 - Options::CAMERA_CENTER_Y)));
                                              
    this->mScaleLayer->setScale(3.0);
    
    this->mShowBackground = true;
    this->mShowBackgroundTime = 0.5;
    this->mShowBackgroundTimeElapsed = 0;
    
    this->setVisible(true);

    this->onStartShow();
}

void Splash::hide()
{
    Entity* part;
    part = (Entity*) this->mParts->objectAtIndex(0);
    part->runAction(CCMoveTo::create(0.2, ccp(part->getPosition().x, Options::CAMERA_HEIGHT + part->getContentSize().height / 2 - Options::CAMERA_CENTER_Y)));
    
    part = (Entity*) this->mParts->objectAtIndex(1);
    part->runAction(CCMoveTo::create(0.2, ccp(part->getPosition().x, -part->getContentSize().height / 2 - Options::CAMERA_CENTER_Y)));
    
    this->mScaleLayer->runAction(CCScaleTo::create(0.1, 0.0));
    
    this->mHideBackground = true;
    this->mHideBackgroundTime = 0.3;
    this->mHideBackgroundTimeElapsed = 0;

    this->onStartHide();
}

void Splash::onShow()
{
    this->mShowedCompleted = true;
}

void Splash::onHide()
{
    this->removeFromParentAndCleanup(false);
}

void Splash::onStartShow()
{
    this->mShowed = true;
}

void Splash::onStartHide()
{
    this->mShowed = false;
    this->mShowedCompleted = false;
}

void Splash::setType(int pType)
{
    this->mType = pType;
}

bool Splash::isShowed()
{
    return this->mShowed;
}

bool Splash::isShowedCompleted()
{
    return this->mShowedCompleted;
}

// ===========================================================
// Override Methods
// ===========================================================

void Splash::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
    
    if(this->mShowBackground)
    {
        this->mShowBackgroundTimeElapsed += pDeltaTime;
    
        if(this->mShowBackgroundTimeElapsed >= this->mShowBackgroundTime)
        {
            this->mShowBackgroundTimeElapsed = 0;
            
            this->mScaleLayer->setVisible(true);
            this->mScaleLayer->runAction(CCScaleTo::create(0.3, 1.0));
            
            this->mShowBackground = false;
            
            this->onShow();
        }
    }
    
    if(this->mHideBackground)
    {
        this->mHideBackgroundTimeElapsed += pDeltaTime;
        
        if(this->mHideBackgroundTimeElapsed >= this->mHideBackgroundTime)
        {
            this->mHideBackgroundTimeElapsed = 0;
            
            this->mScaleLayer->setVisible(false);
            
            this->mHideBackground = false;
            
            this->onHide();
        }
    }
}

void Splash::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate((Touchable*) this, 0, true);
    
    CCLayer::onEnter();
    
    this->scheduleUpdate();
}

void Splash::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate((Touchable*) this);
    
    CCLayer::onExit();
    
    this->stopAllActions();
    this->unscheduleAllSelectors();
}

#endif