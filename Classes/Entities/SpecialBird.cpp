#ifndef CONST_SPECIALBIRD
#define CONST_SPECIALBIRD

#include "SpecialBird.h"

#include "AppDelegate.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ccColor3B SpecialBird::COLORS[10] =
{
    ccc3(0, 200, 255),
    ccc3(255, 120, 30),
    ccc3(0, 100, 255),
    ccc3(36, 178, 27),
    ccc3(224, 117, 118),
    ccc3(205, 0, 15),
    ccc3(123, 171, 55),
    ccc3(62, 49, 176),
    ccc3(189.0, 249.0, 255.0),
    ccc3(189.0, 249.0, 255.0)
};

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
        this->mLife->initWithSprite(Entity::create("birds_life@2x.png"));
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

void SpecialBird::onCreate()
{
    Bird::onCreate();
}

#endif