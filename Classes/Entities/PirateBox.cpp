#ifndef CONST_PIRATEBOX
#define CONST_PIRATEBOX

#include "PirateBox.h"

#include "Game.h"

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

PirateBox::PirateBox(CCNode* pParent) :
    ImpulseEntity("pirate_box@2x.png", pParent)
    {
        this->mGoingToDestroy = false;
    }

PirateBox* PirateBox::create(CCNode* pParent)
{
    PirateBox* entity = new PirateBox(pParent);
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

Entity* PirateBox::create()
{
    return Entity::create();
}

void PirateBox::onCreate()
{
    ImpulseEntity::onCreate();
    
    this->mGoingToDestroy = false;
    
    this->mWeight = Utils::coord(1500.0);
    this->mImpulsePower = Utils::coord(Utils::randomf(400.0, 1000.0));
    this->mRotateImpulse = Utils::coord(Utils::randomf(0.0, 10.0));
    this->mSideImpulse = Utils::coord(Utils::randomf(10.0, 100.0));
    this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ? -this->mSideImpulse : this->mSideImpulse;
    
    this->mTime = 5;
    this->mTimeElapsed = 0;
    
    this->mHitCount = 0;
}

void PirateBox::onDestroy()
{
    ImpulseEntity::onDestroy();
    
    static_cast<Game*>(this->getParent()->getParent()->getParent())->stopBoxAnimation();
}

void PirateBox::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime);
    
    /** Collisions and destroy animation **/
    
    if(true)
    {
        for(int i = 0; i < 10; i++)
        {
            if(this->isCollideWithPoint(Options::TOUCH_INFORMATION[i]))
            {
                if(this->getScaleX() == 1.0)
                {
                    if(!this->mGoingToDestroy)
                    {
                        static_cast<Game*>(this->getParent()->getParent()->getParent())->startBoxAnimation();
                    }
                    else
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_COMBO[this->mHitCount > 7 ? 7 : this->mHitCount]);
                    }
                
                    this->mGoingToDestroy = true;
                
                    this->mHitCount++;
                    
                    this->setScale(1.2);
                    this->runAction(CCScaleTo::create(0.2, 1));
                }
            }
        }
    }

    if(this->mGoingToDestroy)
    {
        this->mTimeElapsed += pDeltaTime;
        
        if(this->mTimeElapsed >= this->mTime)
        {
            this->destroy();
        }
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif