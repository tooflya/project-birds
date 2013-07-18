#ifndef CONST_FEATHER
#define CONST_FEATHER

#include "Feather.h"

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

Feather::Feather() :
    ImpulseEntity("birds_feather_sprite@2x.png", 2, 2)
    {
        
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Feather::onCreate()
{
    ImpulseEntity::onCreate();

    this->mWeight = Utils::coord(500.0f);
    this->mImpulsePower = Utils::coord(Utils::randomf(120.0f, 500.0f));
    this->mSideImpulse = Utils::coord(Utils::randomf(-200.0f, 200.0f));
    this->mRotateImpulse = Utils::coord(Utils::randomf(-1000.0f, 1000.0f));
}
    
Feather* Feather::deepCopy()
{
    return new Feather();
}
    
void Feather::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
}

#endif