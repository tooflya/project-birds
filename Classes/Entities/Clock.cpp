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
    Entity("game_time_clock@2x.png", 3, 1, pParent)
    {
        this->mArea = CCProgressTimer::create(Entity::create("game_time_mask@2x.png"));
        this->addChild(this->mArea);
        this->mArrow = Entity::create("game_time_arrow@2x.png", this);

        this->mArea->setType(kCCProgressTimerTypeRadial);
        this->mArea->setReverseProgress(true);

        this->mArrow->setAnchorPoint(ccp(0.5, 0.18));

        this->mArrow->create()->setCenterPosition(this->getWidth() / 2 - Utils::coord(6), this->getHeight() / 2 - Utils::coord(15));
        this->mArea->setPosition(ccp(this->getWidth() / 2 - Utils::coord(6), this->getHeight() / 2 - Utils::coord(15)));
        
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
    this->stopAnimation();

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

        this->mArrow->setRotation(this->mTimeElapsed * 6.0);
        this->mArea->setPercentage(100.0 - (this->mTimeElapsed / 60.0 * 100.0));

        if(this->mTimeElapsed >= 50.0 && !this->isAnimationRunning())
        {
            this->animate(0.02, 1, 2);
        }
    }
}

// ===========================================================
// Override Methods
// ===========================================================

#endif