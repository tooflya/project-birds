#ifndef CONST_EXPLOSIONBASIC
#define CONST_EXPLOSIONBASIC

#include "ExplosionBasic.h"

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

ExplosionBasic::ExplosionBasic() :
    Entity("explosion_basic@2x.png", 3, 4)
    {
        
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void ExplosionBasic::onAnimationEnd()
{
    this->destroy();
}

void ExplosionBasic::onCreate()
{
    Entity::onCreate();
    
    this->animate(0.05, 1);
}
    
ExplosionBasic* ExplosionBasic::deepCopy()
{
    return new ExplosionBasic();
}
    
void ExplosionBasic::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
}

#endif