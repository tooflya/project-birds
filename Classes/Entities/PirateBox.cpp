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
        this->mLight = Entity::create("get_coins_light@2x.png", static_cast<Game*>(pParent->getParent()->getParent())->spriteBatch99);
        
        this->setZOrder(2);
        
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
    
    this->setOpacity(255);
    this->setScale(1.0);
    
    this->mLight->create();
    this->mLight->setRotation(0);
    this->mLight->setScale(0.5);
    
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
    
    this->mLight->destroy();
}

void PirateBox::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime);
    
    this->mLight->setCenterPosition(this->getCenterX(), this->getCenterY());
    this->mLight->setRotation(this->mLight->getRotation() + 1);
    this->mLight->setOpacity(this->getOpacity());
    
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
                    
                    this->mLight->setScale(this->mLight->getScaleX() + 0.05);
                    
                    static_cast<Game*>(this->getParent()->getParent()->getParent())->mCoins->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
                }
            }
        }
    }

    if(this->mGoingToDestroy)
    {
        this->mTimeElapsed += pDeltaTime;
        
        if(this->mTimeElapsed >= this->mTime)
        {
            this->mTimeElapsed = 0;
            
            static_cast<Game*>(this->getParent()->getParent()->getParent())->stopBoxAnimation();
        }
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif