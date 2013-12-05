#ifndef CONST_STARPARTICLE2
#define CONST_STARPARTICLE2

#include "StarParticle2.h"

#include "AppDelegate.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ccColor3B StarParticle2::COLORS[3] =
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

StarParticle2::StarParticle2() :
    Entity("star_particle@2x.png"),
	mVectorX(0),
    mVectorY(0)
    {
    }

StarParticle2* StarParticle2::create()
{
    StarParticle2* entity = new StarParticle2();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void StarParticle2::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    this->setCenterPosition(this->getCenterX() + this->mVectorX, this->getCenterY() + this->mVectorY);
    
    if(this->getCenterX() < -this->getWidth() / 2 || this->getCenterX() > Options::CAMERA_WIDTH || this->getCenterY() < -this->getHeight() / 2 || this->getCenterY() > Options::CAMERA_HEIGHT)
    {
        this->destroy();
    }
}

void StarParticle2::onCreate()
{
    Entity::onCreate();
    
    float s = Utils::randomf(2, 5);
    
    this->mVectorX = Utils::randomf(1.0, 10.0) * s;
    this->mVectorY = Utils::randomf(1.0, 10.0) * s;
    
    this->mVectorX = Utils::probably(50) ? -this->mVectorX : this->mVectorX;
    this->mVectorY = Utils::probably(50) ? -this->mVectorY : this->mVectorY;
    
    this->setColor(COLORS[Utils::random(0, 3)]);
    
    this->setRotation(Utils::randomf(0.0, 720.0));
}

StarParticle2* StarParticle2::deepCopy()
{
    return StarParticle2::create();
}

#endif