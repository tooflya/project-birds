#ifndef CONST_SPECIALBIRD
#define CONST_SPECIALBIRD

#include "SpecialBird.h"

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

SpecialBird::SpecialBird() :
    Bird(true)
    {
        this->mMarkTime = 0.02;
        this->mMarkTimeElapsed = 0;
        
        this->mLife = new CCProgressTimer();
        this->mLife->initWithSprite(CCSprite::create("birds_life@2x.png"));
        this->mLife->setType(kCCProgressTimerTypeRadial);
        this->mLife->setReverseProgress(true);

        this->mSoundEffect = 0;

        this->mChalange = false;
    }

SpecialBird* SpecialBird::create()
{
    SpecialBird* entity = new SpecialBird();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

SpecialBird* SpecialBird::deepCopy()
{
    return SpecialBird::create();
}

#endif