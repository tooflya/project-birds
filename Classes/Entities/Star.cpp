#ifndef CONST_STAR
#define CONST_STAR

#include "Star.h"

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

Star::Star() :
    Entity("end_lvl_star_sprite@2x.png", 3, 2)
    {
        
    }

// ===========================================================
// Methods
// ===========================================================

void Star::animate()
{
    this->mIsAnimationRunning = true;
    
    this->mAnimationTimeElapsed = 0;
    
    this->runAction(CCScaleTo::create(0.15, 1.2));
}

// ===========================================================
// Override Methods
// ===========================================================

void Star::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(this->mIsAnimationRunning)
    {
        this->mAnimationTimeElapsed += pDeltaTime;
    
        if(this->mAnimationTimeElapsed > 0.15)
        {
            this->mIsAnimationRunning = false;
            
            this->runAction(CCScaleTo::create(0.15, 1.0));
        }
    }
}

Star* Star::deepCopy()
{
    return new Star();
}

#endif