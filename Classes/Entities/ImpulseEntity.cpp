#ifndef CONST_IMPULSEENTITY
#define CONST_IMPULSEENTITY

#include "ImpulseEntity.h"

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

ImpulseEntity::ImpulseEntity(const char* pTextureFileName) :
    Entity(pTextureFileName)
    {
        this->mWeight = 0;
        this->mSideImpulse = 0;
        this->mImpulsePower = 0;
        this->mRotateImpulse = 0;
    }

ImpulseEntity::ImpulseEntity(const char* pTextureFileName, int pHorizontalFramesCount, int pVerticalFramesCount) :
    Entity(pTextureFileName, pHorizontalFramesCount, pVerticalFramesCount)
    {
        this->mWeight = 0;
        this->mSideImpulse = 0;
        this->mImpulsePower = 0;
        this->mRotateImpulse = 0;
    }

// ===========================================================
// Methods
// ===========================================================

void ImpulseEntity::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
    
    if(this->mImpulsePower >= 0.0f)
    {
        this->setCenterPosition(this->getCenterX(), this->getCenterY() + this->mImpulsePower * pDeltaTime);
        
        this->mImpulsePower -= this->mWeight * pDeltaTime;
    }
    else
    {
        this->setCenterPosition(this->getCenterX(), this->getCenterY() - abs(this->mImpulsePower) * pDeltaTime);
        
        this->mImpulsePower -= Utils::coord(500.0f) * pDeltaTime;
    }
    
    this->setCenterPosition(this->getCenterX() - this->mSideImpulse * pDeltaTime, this->getCenterY());
    this->setRotation(this->getRotation() - this->mRotateImpulse * pDeltaTime);
}

bool ImpulseEntity::isCollideWithPoint(float pX, float pY)
{
    if(pX < 0 || pY < 0) return false;
    if(!this->isVisible()) return false;
    
    float x = pX - this->getCenterX();
    float y = pY - this->getCenterY();
    
    return x * x + y * y <= Utils::coord(500.0f) + Utils::coord(10.0f) * Utils::coord(500.0f) + Utils::coord(10.0f);
}

// ===========================================================
// Override Methods
// ===========================================================

#endif