#ifndef CONST_ROBOTOPART
#define CONST_ROBOTOPART

#include "RobotoPart.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int RobotoPart::FRAME = 0;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

RobotoPart::RobotoPart() :
    Entity("bonus_bird_parts.png", 4, 2)
    {
    }

RobotoPart* RobotoPart::create(int pFrameIndex)
{
    RobotoPart* entity = new RobotoPart();
    entity->autorelease();
    
    entity->mFrameIndex = pFrameIndex;
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void RobotoPart::onCreate()
{
    Entity::onCreate();
    
    this->setCurrentFrameIndex(this->mFrameIndex);
    
    this->setRotation(Utils::randomf(0.0, 720.0));
    
    this->mRotationSpeed = Utils::random(1, 10);
    
    float s = Utils::randomf(2, 3);
    
    this->mVectorX = Utils::randomf(1.0, 10.0) * s;
    this->mVectorY = Utils::randomf(1.0, 10.0) * s;
    
    this->mVectorX = Utils::probably(50) ? -this->mVectorX : this->mVectorX;
    this->mVectorY = Utils::probably(50) ? -this->mVectorY : this->mVectorY;
    
    this->mBlowTime = 0.2;
    this->mBlowTimeElapsed = 0;
    
    this->mVectorReference = false;
}

void RobotoPart::onDestroy()
{
    Entity::onDestroy();
}

void RobotoPart::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    this->setRotation(this->getRotation() + this->mRotationSpeed);
    
    this->mBlowTimeElapsed += pDeltaTime;
    
    if(this->mBlowTimeElapsed < this->mBlowTime)
    {
        this->mVectorX -= this->mVectorX > 0 ? 0.5 : -0.5;
        this->mVectorY -= this->mVectorY > 0 ? 0.5 : -0.5;
        
        this->setCenterPosition(this->getCenterX() + this->mVectorX, this->getCenterY() + this->mVectorY);
    }
    else
    {
        if(this->numberOfRunningActions() == 0 && this->mBlowTimeElapsed > 0.5)
        {
            this->runAction(CCEaseOut::create(CCMoveTo::create(0.4, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(100))), 1.0));
        }
        else
        {
            if(this->mBlowTimeElapsed < 0.5)
            {
                if(!this->mVectorReference)
                {
                    this->mVectorX *= 0.2;
                    this->mVectorY *= 0.2;
                    
                    this->mVectorReference = true;
                }
                
                this->setCenterPosition(this->getCenterX() + this->mVectorX, this->getCenterY() + this->mVectorY);
            }
        }
    }
    
    if(this->mBlowTimeElapsed >= 0.9)
    {
        this->destroy();
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

RobotoPart* RobotoPart::deepCopy()
{
    FRAME++;
    
    return RobotoPart::create(this->mFrameIndex + FRAME);
}

#endif