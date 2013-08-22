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
    ImpulseEntity("birds_feather_sprite@2x.png", 4, 2)
    {
        this->mWaitingTimeElapsed = 0.0;
        this->mWaitingTime = 0.02;
    }

Feather* Feather::create()
{
    Feather* entity = new Feather();
    entity->autorelease();
    
    return entity;
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
    this->mImpulsePower = 0;
    this->mSideImpulse = Utils::coord(Utils::randomf(-100.0f, 100.0f));
    this->mRotateImpulse = Utils::coord(Utils::randomf(-1000.0f, 1000.0f));

    this->setRotation(Utils::randomf(0.0, 720.0));
    this->setOpacity(255.0);

    this->bWaitingTime = false;
}

void Feather::init(int pIndex, float pSpeed)
{
    this->mPower = Utils::coord(1.0);

    float t = Utils::randomf(0.0, 20.0);

    float x = pSpeed * sin(pIndex * 2 * Utils::Pi / t);
    float y = pSpeed * cos(pIndex * 2 * Utils::Pi / t);

    this->mVectorX = x;
    this->mVectorY = y;
}
    
Feather* Feather::deepCopy()
{
    return Feather::create();
}
    
void Feather::update(float pDeltaTime)
{
    if(!this->isVisible()) return;

    if(this->bWaitingTime)
    {
        this->mWaitingTimeElapsed += pDeltaTime;

        if(this->mWaitingTimeElapsed >= this->mWaitingTime)
        {
            this->mWaitingTimeElapsed = 0.0;

            this->bWaitingTime = false;

            this->runAction(CCFadeOut::create(2.0));
        }

        return;
    }

    if(this->mPower > 0)
    {
        float x = this->getCenterX();
        float y = this->getCenterY();

        x += this->mVectorX;
        y += this->mVectorY;

        this->setCenterPosition(x, y);

        this->mPower -= 0.1;

        if(this->mPower <= 0)
        {
            this->mSideImpulse = this->mVectorX > 0 ? -abs(this->mSideImpulse) : abs(this->mSideImpulse);

            this->bWaitingTime = true;
        }
    }
    else
    {
        ImpulseEntity::update(pDeltaTime);
    }
}

#endif