#ifndef CONST_STARPARTICLE
#define CONST_STARPARTICLE

#include "StarParticle.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ccColor3B StarParticle::COLORS[3] =
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

StarParticle::StarParticle() :
    ImpulseEntity("star_particle@2x.png"),
	mType(0),
	mScaleSpeed(0),
	mRotationSpeed(0),
	mAlphaSpeed(0),
	mIsParticle(0)
    {
        this->mIsParticle = false;
        this->mType = -1;
    }

StarParticle* StarParticle::create()
{
    StarParticle* entity = new StarParticle();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

StarParticle* StarParticle::setType(int pType)
{
    this->mType = pType;
    
    return this;
}

void StarParticle::initAsParticle()
{
    this->mIsParticle = true;
    
    this->mScaleSpeed = Utils::randomf(0.01, 0.1);
    this->mRotationSpeed = Utils::randomf(1.0, 10.0);
    this->mAlphaSpeed = Utils::randomf(0.1, 10.0);
}

// ===========================================================
// Override Methods
// ===========================================================

void StarParticle::update(float pDeltaTime)
{
    if(this->mIsParticle)
    {
        Entity::update(pDeltaTime);
        
        this->setOpacity(this->getOpacity() - this->mAlphaSpeed);
        this->setScale(this->getScaleX() - this->mScaleSpeed);
        this->setRotation(this->getRotation() - this->mRotationSpeed);
        
        if(this->getOpacity() <= 0.0 || this->getScaleX() <= 0.0)
        {
            this->destroy();
        }
    }
    else
    {
        ImpulseEntity::update(pDeltaTime);
    }
}

void StarParticle::onCreate()
{
    ImpulseEntity::onCreate();

    this->mIsParticle = false;
    
    this->setOpacity(255.0);
    this->setScale(1.0);
    this->setRotation(0.0);
    
    switch(this->mType)
    {
        default:

            this->setColor(COLORS[Utils::random(0, 2)]);

            this->setCenterPosition(Utils::probably(50) ? 0 : Options::CAMERA_WIDTH, Options::CAMERA_CENTER_Y + Utils::coord(300));

            this->mSideImpulse = Utils::randomf(100.0, 220.0);
            this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ?  -this->mSideImpulse : this->mSideImpulse;
            this->mRotateImpulse = Utils::randomf(-160.0, 160.0);
            this->mWeight = Utils::coord(500.0);
            this->mImpulsePower = Utils::randomf(100.0, 300.0);

        break;
        case 2:

            this->setColor(ccc3(255.0, 200.0, 0.0));

            this->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(250), Utils::coord(0));

            this->mSideImpulse = Utils::randomf(-200.0, 200.0);
            this->mRotateImpulse = Utils::randomf(-160.0, 160.0);
            this->mWeight = Utils::coord(2500.0);
            this->mImpulsePower = Utils::randomf(500.0, 1200.0);

        break;
    }
}

StarParticle* StarParticle::deepCopy()
{
    return StarParticle::create();
}

#endif