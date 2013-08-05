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
    Entity("game_time_clock@2x.png", 1, 1, pParent)
    {
        this->mArea = CCProgressTimer::create(CCSprite::create("game_time_mask@2x.png"));
        this->addChild(this->mArea);
        this->mArrow = new Entity("game_time_arrow@2x.png", this);

        this->mArea->setType(kCCProgressTimerTypeRadial);
        this->mArea->setReverseProgress (true);
        this->mArea->getSprite()->setScaleX(-1);

        this->mArrow->setAnchorPoint(ccp(0.5, 0.18));

        this->mArrow->create()->setCenterPosition(this->getWidth() / 2 - Utils::coord(3), this->getHeight() / 2 - Utils::coord(0));
        this->mArea->setPosition(ccp(this->getWidth() / 2, this->getHeight() / 2));
        
        this->mTimeElapsed = 1;
    }

// ===========================================================
// Methods
// ===========================================================

void Clock::start()
{
    this->mTimeElapsed = 0;
}

// ===========================================================
// Override Methods
// ===========================================================

void Clock::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);

    if(this->mTimeElapsed >= 0)
    {
        this->mTimeElapsed += pDeltaTime;

        this->mArrow->setRotation(this->mTimeElapsed * 6.0);
        this->mArea->setPercentage(100.0 - (this->mTimeElapsed / 60.0 * 100.0));
    }
}

#endif