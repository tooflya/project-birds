#ifndef CONST_ZOMBIEEXPLOSION
#define CONST_ZOMBIEEXPLOSION

#include "ZombieExplosion.h"

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

ZombieExplosion::ZombieExplosion() :
    Entity("explosion-zombi@2x.png", 3, 4),
	mFollowEntity(0),
	mFX(0),
	mFY(0)
    {   
    }

ZombieExplosion* ZombieExplosion::create()
{
    ZombieExplosion* entity = new ZombieExplosion();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void ZombieExplosion::setFollowEntity(Entity* pEntity)
{
    this->setScale(0.5);
    
    this->mFX = Utils::randomf(-50, 50);
    this->mFY = Utils::randomf(-50, 50);
    
    this->mFollowEntity = pEntity;
}

// ===========================================================
// Virtual Methods
// ===========================================================

void ZombieExplosion::onAnimationEnd()
{
    this->destroy();
}

void ZombieExplosion::onCreate()
{
    Entity::onCreate();
    
    this->setCurrentFrameIndex(0);
    this->setScale(1);
    
    this->mFollowEntity = NULL;
    
    this->animate(0.08, 1);
}
    
ZombieExplosion* ZombieExplosion::deepCopy()
{
    return ZombieExplosion::create();
}
    
void ZombieExplosion::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(this->mFollowEntity != NULL)
    {
        this->setCenterPosition(this->mFollowEntity->getCenterX() + this->mFX, this->mFollowEntity->getCenterY() + this->mFY);
    }
}

#endif