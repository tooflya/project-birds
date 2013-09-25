#ifndef CONST_RAINCIRCLE
#define CONST_RAINCIRCLE

#include "RainCircle.h"

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

RainCircle::RainCircle() :
Entity("rain_circle.png")
{
}

RainCircle* RainCircle::create()
{
    RainCircle* entity = new RainCircle();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void RainCircle::onCreate()
{
    Entity::onCreate();
    
    this->setScale(0.0);
    this->setOpacity(255.0);
    
    this->setCenterPosition(Utils::randomf(0.0, Options::CAMERA_WIDTH), Utils::randomf(0.0, Options::CAMERA_HEIGHT));
    
    this->runAction(CCScaleTo::create(0.5, 1.0));
    this->runAction(CCFadeTo::create(0.8, 0.0));
}

void RainCircle::onDestroy()
{
    Entity::onDestroy();
}

void RainCircle::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(this->getScaleX() >= 1)
    {
        this->destroy();
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

RainCircle* RainCircle::deepCopy()
{
    return RainCircle::create();
}

#endif