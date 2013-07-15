#ifndef CONST_BIRD
#define CONST_BIRD

#include "Bird.h"

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

Bird::Bird() :
    ImpulseEntity("birds_sprite@2x.png", 4, 4)
    {

    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void Bird::onCreate()
{
    ImpulseEntity::onCreate();

    this->setCurrentFrameIndex(Utils::random(0, 3) * 4);

    this->animate(0.1, this->getCurrentFrameIndex(), this->getCurrentFrameIndex() + 3, true);
}

void Bird::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
}

Bird* Bird::deepCopy()
{
    return new Bird();
}

#endif