#ifndef CONST_GENERALEXPLOSION
#define CONST_GENERALEXPLOSION

#include "GeneralExplosion.h"

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

GeneralExplosion::GeneralExplosion() :
Entity("explosion-war@2x.png", 3, 4)
{
    
}

GeneralExplosion* GeneralExplosion::create()
{
    GeneralExplosion* entity = new GeneralExplosion();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void GeneralExplosion::onAnimationEnd()
{
    this->destroy();
}

void GeneralExplosion::onCreate()
{
    Entity::onCreate();
    
    this->setCurrentFrameIndex(0);
    this->setScale(1.6);
    
    this->animate(0.04, 1);
}
    
GeneralExplosion* GeneralExplosion::deepCopy()
{
    return GeneralExplosion::create();
}
    
void GeneralExplosion::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
}

#endif