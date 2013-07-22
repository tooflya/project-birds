#ifndef CONST_EXPLOSION
#define CONST_EXPLOSION

#include "Explosion.h"

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

Explosion::Explosion() :
    Entity("explosion@2x.png", 3, 4)
    {
        
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Explosion::onAnimationEnd()
{
    this->destroy();
}

void Explosion::onCreate()
{
    Entity::onCreate();
    
    this->animate(0.05, 1);
}
    
Explosion* Explosion::deepCopy()
{
    return new Explosion();
}
    
void Explosion::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
}

#endif