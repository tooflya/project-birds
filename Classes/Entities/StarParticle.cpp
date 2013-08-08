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
    ImpulseEntity("star_particle@2x.png")
    {

    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void StarParticle::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime);

    //
}

void StarParticle::onCreate()
{
    ImpulseEntity::onCreate();

    this->setColor(COLORS[Utils::random(0, 2)]);

    this->setCenterPosition(Utils::probably(50) ? 0 : Options::CAMERA_WIDTH, Options::CAMERA_CENTER_Y + Utils::coord(300));

    this->mSideImpulse = Utils::randomf(100.0, 220.0);
    this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ?  -this->mSideImpulse : this->mSideImpulse;
    this->mRotateImpulse = Utils::randomf(-160.0, 160.0);
    this->mWeight = Utils::coord(500.0);
    this->mImpulsePower = Utils::randomf(100.0, 300.0);
}

StarParticle* StarParticle::deepCopy()
{
    return new StarParticle();
}

#endif