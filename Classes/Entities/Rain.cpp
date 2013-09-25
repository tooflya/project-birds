#ifndef CONST_RAIN
#define CONST_RAIN

#include "Rain.h"

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

Rain::Rain() :
    Entity("rain.png")
    {
    }

Rain* Rain::create()
{
    Rain* entity = new Rain();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void Rain::onCreate()
{
    Entity::onCreate();
    
    this->setOpacity(10);
    this->setCenterPosition(Utils::randomf(-Utils::coord(300), Options::CAMERA_WIDTH), Utils::randomf(0.0, Options::CAMERA_HEIGHT + Utils::coord(300)));
    
    this->runAction(CCFadeTo::create(0.3, 255.0));
}

void Rain::onDestroy()
{
    Entity::onDestroy();
}

void Rain::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    this->setCenterPosition(this->getCenterX() + 500 * pDeltaTime, this->getCenterY() - 1000 * pDeltaTime);
    
    if(this->getOpacity() >= 255)
    {
        this->setOpacity(250);
        this->runAction(CCFadeTo::create(0.5, 0.0));
    }
    
    if(this->getOpacity() <= 0)
    {
        this->destroy();
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

Rain* Rain::deepCopy()
{
    return Rain::create();
}

#endif