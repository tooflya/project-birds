#ifndef CONST_CLOCK
#define CONST_CLOCK

#include "Clock.h"

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

Clock::Clock(CCNode* pParent) :
    CCNode(),
	mTimeElapsed(0),
	mPause(0)
    {
        pParent->addChild(this);
        
        this->mPause = false;
        
        this->mTimeElapsed = 1;
    }

Clock* Clock::create(CCNode *pParent)
{
    Clock* entity = new Clock(pParent);
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void Clock::start()
{
    this->mTimeElapsed = 0;
}

float Clock::getTimeElapsed()
{
    return this->mTimeElapsed <= 0 ? 0 : this->mTimeElapsed;
}

void Clock::pause()
{
    this->mPause = !this->mPause;
}

void Clock::updateTime(float pDeltaTime)
{
    if(this->mTimeElapsed >= 0 && this->mTimeElapsed <= 61.0 &&!this->mPause)
    {
        this->mTimeElapsed += pDeltaTime;
    }
}

// ===========================================================
// Override Methods
// ===========================================================

#endif