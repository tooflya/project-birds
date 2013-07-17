#ifndef CONST_CONFETTI
#define CONST_CONFETTI

#include "Confetti.h"

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

Confetti::Confetti() :
    Entity("confety_sprite@2x.png", 5, 4)
    {
        
    }

// ===========================================================
// Methods
// ===========================================================

void Confetti::onCreate()
{
    Entity::onCreate();
    
    this->setOpacity(255.0);
    this->setRotation(0.0);
    
    this->animate(0.05);
    
    this->mSpeedX = Utils::coord(Utils::randomf(-300.0, 300.0));
    this->mSpeedY = Utils::coord(Utils::randomf(10.0, 50.0));
    
    this->mWeight = Utils::coord(Utils::randomf(1.0, 10.0));
    
    this->mRotationSpeed = Utils::coord(Utils::randomf(-10.0, 10.0));
    this->mAlphaSpeed = Utils::coord(Utils::randomf(0.1, 1.0));
    
    this->setColor(ccc3(Utils::randomf(0.0, 255.0), Utils::randomf(0.0, 255.0), Utils::randomf(0.0, 255.0)));
}

// ===========================================================
// Override Methods
// ===========================================================

void Confetti::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    float x = this->getCenterX();
    float y = this->getCenterY();
    
    x -= this->mSpeedX * pDeltaTime;
    y += this->mSpeedY * pDeltaTime;
    
    this->mSpeedY -= this->mWeight;
    
    this->setCenterPosition(x, y);
    this->setRotation(this->getRotationX() + this->mRotationSpeed);
    this->setOpacity(this->getOpacity() - this->mAlphaSpeed);
}

Confetti* Confetti::deepCopy()
{
    return new Confetti();
}

#endif