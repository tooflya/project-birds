#ifndef CONST_IMPULSEENTITY
#define CONST_IMPULSEENTITY

#include "ImpulseEntity.h"

#include "Game.h"

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
    
    pDeltaTime *= Game::TIME_SLOW;
    
    if(this->mImpulsePower >= 0.0f)
    {
        this->setCenterPosition(this->getCenterX(), this->getCenterY() + this->mImpulsePower * pDeltaTime);
        
        this->mImpulsePower -= this->mWeight * pDeltaTime;
    }
    else
    {
        this->setCenterPosition(this->getCenterX(), this->getCenterY() - abs(this->mImpulsePower) * pDeltaTime);
        
        this->mImpulsePower -= this->mWeight * pDeltaTime;
    }
    
    this->setCenterPosition(this->getCenterX() - this->mSideImpulse * pDeltaTime, this->getCenterY());
    this->setRotation(this->getRotation() - this->mRotateImpulse * pDeltaTime);

    if(this->getCenterY() < -this->getHeight() / 2 || this->getCenterX() < -Options::CAMERA_WIDTH || this->getCenterX() > Options::CAMERA_WIDTH * 2)
    {
        this->destroy();
    }
}

bool ImpulseEntity::isCollideWithPoint(CCTouchInformation pInformation)
{
    if(pInformation.position.x < 0 || pInformation.position.y < 0) return false;
    if(!this->isVisible()) return false;
    
    float x = pInformation.position.x - this->getCenterX();
    float y = pInformation.position.y - this->getCenterY();
    
    return x * x + y * y <= Utils::coord(500.0f) + Utils::coord(10.0f) * Utils::coord(500.0f) + Utils::coord(10.0f);
}

// ===========================================================
// Override Methods
// ===========================================================

#endif