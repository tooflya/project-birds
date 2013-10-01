#ifndef CONST_ROBOTOGUN
#define CONST_ROBOTOGUN

#include "RobotoGun.h"

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

RobotoGun::RobotoGun(CCNode* pParent) :
    Entity("gun.png", 5, 1, pParent)
    {
    }

RobotoGun* RobotoGun::create(CCNode* pParent)
{
    RobotoGun* entity = new RobotoGun(pParent);
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

Entity* RobotoGun::create()
{
    return Entity::create();
}

void RobotoGun::onCreate()
{
    Entity::onCreate();
}

void RobotoGun::onDestroy()
{
    Entity::onDestroy();
}

void RobotoGun::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif