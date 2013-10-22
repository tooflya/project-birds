#ifndef CONST_RIPPLE
#define CONST_RIPPLE

#include "Ripple.h"

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

Ripple::Ripple() :
    Entity("wave.png"),
	mAlphaSpeed(0),
	mScaleXSpeed(0),
	mScaleYSpeed(0),
	mMinXScale(0),
	mMinYScale(0),
	mMaxXScale(0),
	mMaxYScale(0),
	mAlphaReverse(0),
	mScaleXReverse(0),
	mScaleYReverse(0)
    {
    }

Ripple* Ripple::create()
{
    Ripple* entity = new Ripple();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Ripple::onCreate()
{
    Entity::onCreate();
    
    this->setScaleX(Utils::randomf(0.7, 1.2));
    this->setScaleY(Utils::randomf(0.7, 1.2));
    
    this->setOpacity(Utils::randomf(10.0, 245.0));
    
    this->mAlphaSpeed = Utils::random(1, 5);
    this->mScaleXSpeed = Utils::randomf(0.001, 0.01);
    this->mScaleYSpeed = Utils::randomf(0.001, 0.01);
    
    this->mMaxXScale = Utils::randomf(0.7, 1.4);
    this->mMaxYScale = Utils::randomf(0.7, 1.4);
    
    this->mMinXScale = Utils::randomf(0.4, 0.7);
    this->mMinYScale = Utils::randomf(0.4, 0.7);
    
    this->mAlphaReverse = Utils::probably(50);
    this->mScaleXReverse = Utils::probably(50);
    this->mScaleYReverse = Utils::probably(50);
}
    
Ripple* Ripple::deepCopy()
{
    return Ripple::create();
}
    
void Ripple::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(this->mAlphaReverse)
    {
        this->setOpacity(this->getOpacity() - this->mAlphaSpeed);
        
        if(this->getOpacity() <= 10.0)
        {
            this->mAlphaReverse = false;
        }
    }
    else
    {
        this->setOpacity(this->getOpacity() + this->mAlphaSpeed);

        if(this->getOpacity() >= 250.0)
        {
            this->mAlphaReverse = true;
        }
    }
    
    if(this->mScaleXReverse)
    {
        this->setScaleX(this->getScaleX() - this->mScaleXSpeed);
        
        if(this->getScaleX() <= this->mMinXScale)
        {
            this->mScaleXReverse = false;
        }
    }
    else
    {
        this->setScaleX(this->getScaleX() + this->mScaleXSpeed);
        
        if(this->getScaleX() >= this->mMaxXScale)
        {
            this->mScaleXReverse = true;
        }
    }
    
    if(this->mScaleYReverse)
    {
        this->setScaleY(this->getScaleY() - this->mScaleYSpeed);
        
        if(this->getScaleY() <= this->mMinYScale)
        {
            this->mScaleYReverse = false;
        }
    }
    else
    {
        this->setScaleY(this->getScaleY() + this->mScaleYSpeed);
        
        if(this->getScaleY() >= this->mMaxYScale)
        {
            this->mScaleYReverse = true;
        }
    }
}

#endif