#ifndef CONST_MARK
#define CONST_MARK

#include "Mark.h"

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

Mark::Mark() :
    Entity("mark@2x.png")
    {
        
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Mark::onCreate()
{
    Entity::onCreate();
    
    this->setOpacity(255.0);
    this->setScale(0.7);
    
    this->runAction(CCFadeTo::create(0.5, 0.0));
    this->runAction(CCScaleTo::create(0.5, 0.3));
}
    
Mark* Mark::deepCopy()
{
    return new Mark();
}
    
void Mark::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
    
    if(this->getOpacity() <= 0.0 || this->getScaleX() <= 0.0)
    {
        this->destroy();
    }
}

#endif