#ifndef CONST_WEAPONPARTICLE
#define CONST_WEAPONPARTICLE

#include "WeaponParticle.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

long WeaponParticle::LAST_TIME = 0;

// ===========================================================
// Fields
// ===========================================================

WeaponParticle::WeaponParticle() :
    Entity("weapon_strike_sprite@2x.png", 6, 6)
    {
        this->mAlphaSpeed = 0;
        this->mScaleSpeed = 0;
        this->mRotationSpeed = 0;
    }

WeaponParticle* WeaponParticle::create()
{
    WeaponParticle* entity = new WeaponParticle();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

void WeaponParticle::setType(int pType)
{
    if(this->mType == 2)
    {
        if(Utils::millisecondNow() - LAST_TIME >= 100)
        {
        }
        else
        {
            this->destroy();

            return;
        }
    }
    
    this->mType = pType;

    this->mAlphaSpeed = 0;//Utils::randomf(10.0, 20.0);
    this->mScaleSpeed = Utils::randomf(0.01, 0.05);
    this->mRotationSpeed = Utils::randomf(-10.0, 10.0);

    if(this->mType < 2)
    {
        this->mVectorX = Utils::coord(Utils::randomf(-3.0, 3.0));
        this->mVectorY = Utils::coord(Utils::randomf(-3.0, 3.0));
    }
    else
    {
        this->mVectorX = 0;
        this->mVectorY = 0;

        LAST_TIME = Utils::millisecondNow();
    }

    this->setCurrentFrameIndex(Options::SELECTED_WEAPON_ID * 3 + pType);
}

// ===========================================================
// Override Methods
// ===========================================================

void WeaponParticle::onCreate()
{
    Entity::onCreate();

    this->setOpacity(255.0);
    this->setScale(1.0);
}

void WeaponParticle::onDestroy()
{
    Entity::onDestroy();
}

void WeaponParticle::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);

    if(!this->isVisible()) return;

    float x = this->getCenterX();
    float y = this->getCenterY();

    this->setRotation(this->getRotation() + this->mRotationSpeed);
    this->setOpacity(this->getOpacity() - this->mAlphaSpeed);
    this->setScale(this->getScaleX() - this->mScaleSpeed);

    x += this->mVectorX;
    y += this->mVectorY;

    this->setCenterPosition(x, y);

    if(this->getOpacity() <= this->mAlphaSpeed || this->getScaleX() <= 0)
    {
        this->destroy();
    }
}

WeaponParticle* WeaponParticle::deepCopy()
{
    return WeaponParticle::create();
}

#endif