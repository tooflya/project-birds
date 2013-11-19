#ifndef CONST_LIVEPARTICLE
#define CONST_LIVEPARTICLE

#include "LiveParticle.h"

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

LiveParticle::LiveParticle() :
    Entity("popup_glife_pic_fall@2x.png"),
	mMoveSpeed(0)
    {
    }

LiveParticle* LiveParticle::create()
{
    LiveParticle* entity = new LiveParticle();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void LiveParticle::onCreate()
{
    Entity::onCreate();
    
    this->setScale(0);
    
    this->mMoveSpeed = Utils::randomf(1.0, 5.0);
    
    this->runAction(CCScaleTo::create(Utils::randomf(0.1, 0.5), 1.3));
    
    this->setCenterPosition(Utils::randomf(0, Options::CAMERA_WIDTH), Utils::randomf(0, Options::CAMERA_HEIGHT));
    
    if(Options::SOUND_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_COINS[Utils::random(0, 3)]);
    }
}

void LiveParticle::onDestroy()
{
    Entity::onDestroy();
}

void LiveParticle::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(this->getScaleX() >= 1)
    {
        this->setCenterPosition(this->getCenterX(), this->getCenterY() - this->mMoveSpeed++);
        
        if(this->getCenterY() < -this->getHeight() / 2)
        {
            this->destroy();
        }
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

LiveParticle* LiveParticle::deepCopy()
{
    return LiveParticle::create();
}

#endif