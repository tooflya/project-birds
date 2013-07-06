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

Splash::Splash(CCNode* pParent)
{
    pParent->addChild(this, 500);
    
    this->scheduleUpdate();
    
    this->mShowBackground = false;
}

// ===========================================================
// Methods
// ===========================================================

void Splash::show()
{
    Entity* part;
    part = (Entity*) this->mParts->objectAtIndex(0);
    part->runAction(CCMoveTo::create(0.2, ccp(part->getPosition().x, Options::CAMERA_HEIGHT - part->getContentSize().height / 2)));
    
    part = (Entity*) this->mParts->objectAtIndex(1);
    part->runAction(CCMoveTo::create(0.2, ccp(part->getPosition().x, part->getContentSize().height / 2)));
                                              
    this->mBackground->setScale(5.0);
    
    this->mShowBackground = true;
    this->mBackgroundTime = 0.3;
    this->mBackgroundTimeElapsed = 0;
    
    this->setVisible(true);
}

void Splash::hide()
{
    
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Splash::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
    
    if(this->mShowBackground)
    {
        this->mBackgroundTimeElapsed += pDeltaTime;
    
        if(this->mBackgroundTimeElapsed >= this->mBackgroundTime)
        {
            this->mBackgroundTimeElapsed = 0;
            
            this->mBackground->setVisible(true);
            this->mBackground->runAction(CCScaleTo::create(0.1, 1.0));
            
            this->mShowBackground = false;
        }
    }
}

#endif