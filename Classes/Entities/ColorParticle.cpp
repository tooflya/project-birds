#ifndef CONST_COLORPARTICLE
#define CONST_COLORPARTICLE

#include "ColorParticle.h"

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

ColorParticle::ColorParticle() :
    Entity("dust@2x.png")
    {
    }

ColorParticle* ColorParticle::create()
{
    ColorParticle* entity = new ColorParticle();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void ColorParticle::onCreate()
{
    Entity::onCreate();
    
    this->setScale(0);
    this->setOpacity(255);
    
    this->mSpeedX = Utils::randomf(-1.0, 1.0);
    this->mSpeedY = Utils::randomf(-1.0, 1.0);
    
    this->mTime = Utils::randomf(1.0, 2.0);
    this->mTimeElapsed = 0;
    
    this->runAction(CCScaleTo::create(Utils::randomf(0.0, 3.0), Utils::randomf(0.5, 1.5)));
    this->runAction(CCFadeTo::create(Utils::randomf(1.0, 3.0), 0));
}

void ColorParticle::onDestroy()
{
    Entity::onDestroy();
}

void ColorParticle::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    this->setCenterPosition(this->getCenterX() + this->mSpeedX, this->getCenterY() + this->mSpeedY);
    
    this->mTimeElapsed += pDeltaTime;
    
    if(this->mTimeElapsed >= this->mTime)
    {
        this->mTimeElapsed = 0;
        
        this->mSpeedX = Utils::randomf(-1.0, 1.0);
        this->mSpeedY = Utils::randomf(-1.0, 1.0);
    }
    
    if(this->getOpacity() <= 0)
    {
        this->destroy();
    }
}

ColorParticle* ColorParticle::deepCopy()
{
    return ColorParticle::create();
}

#endif