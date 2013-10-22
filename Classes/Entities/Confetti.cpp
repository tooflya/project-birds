#ifndef CONST_CONFETTI
#define CONST_CONFETTI

#include "Confetti.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ccColor3B Confetti::COLORS[3] =
{
    ccc3(255.0, 0.0, 0.0),
    ccc3(0.0, 255.0, 0.0),
    ccc3(0.0, 0.0, 255.0)
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Confetti::Confetti() :
    Entity("confety_sprite@2x.png", 5, 4),
	mSpeedX(0),
	mSpeedY(0),
	mWeight(0),
	mRotationSpeed(0),
	mAlphaSpeed(0),
	mMoveUp(0),
	mAppear(0)
    {
        this->mAppear = false;
    }

Confetti* Confetti::create()
{
    Confetti* entity = new Confetti();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void Confetti::onCreate()
{
    Entity::onCreate();
    
    this->setColor(COLORS[Utils::random(0, 2)]);

    this->setOpacity(255.0);
    this->setRotation(0.0);
    
    this->animate(Utils::randomf(0.02, 0.1));
    
    this->mSpeedX = Utils::coord(Utils::randomf(-300.0, 300.0));
    this->mSpeedY = -Utils::coord(Utils::randomf(10.0, 150.0));
    
    this->mWeight = Utils::coord(Utils::randomf(1.0, 2.0));
    
    this->mRotationSpeed = Utils::coord(Utils::randomf(-10.0, 10.0));
    this->mAlphaSpeed = Utils::coord(Utils::random(0.1, 1.0));

    this->mAppear = true;
}

// ===========================================================
// Override Methods
// ===========================================================

void Confetti::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    float x = this->getCenterX();
    float y = this->getCenterY();
    
    //x -= this->mSpeedX * pDeltaTime;
    y += this->mSpeedY * pDeltaTime;
    
    this->mSpeedY -= this->mWeight;
    
    this->setCenterPosition(x, y);
    this->setRotation(this->getRotationX() + this->mRotationSpeed);

    if(this->mAppear)
    {
        this->setOpacity(this->getOpacity() - this->mAlphaSpeed);

        if(this->getOpacity() <= 0.0)
        {
            this->setOpacity(0.0);
            
            this->destroy();
        }
    }
    else
    {
        this->setOpacity(this->getOpacity() + this->mAlphaSpeed);

        if(this->getOpacity() >= 250.0)
        {
            this->setOpacity(250.0);

            this->mAppear = true;
        }
    }
}

Confetti* Confetti::deepCopy()
{
    return Confetti::create();
}

#endif