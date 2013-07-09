#ifndef CONST_CONFETTIMANAGER
#define CONST_CONFETTIMANAGER

#include "ConfettiManager.h"

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

ConfettiManager::ConfettiManager(int pCreateCount, Entity* pEntity, CCNode* pScreen) :
    BatchEntityManager(pCreateCount, pEntity, pScreen)
    {
    
    }

// ===========================================================
// Methods
// ===========================================================

void ConfettiManager::init(float pX, float pY)
{
    for(int i = 0; i < 10; i++)
    {
        Entity* particle = (Entity*) this->create();
        
        particle->setCenterPosition(pX, pY);
        particle->setCurrentFrameIndex(Utils::random(0, 20));
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif