#ifndef CONST_KEYPARTICLE
#define CONST_KEYPARTICLE

#include "KeyParticle.h"

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

KeyParticle::KeyParticle() :
    Entity("popup_key_ico_fall@2x.png")
    {
    }

KeyParticle* KeyParticle::create()
{
    KeyParticle* entity = new KeyParticle();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void KeyParticle::onCreate()
{
    Entity::onCreate();
    
    this->setRotation(0);
    this->setOpacity(255);
    
    this->mMoveSpeed = Utils::randomf(30, 40);
    this->mRotationSpeed = Utils::randomf(10, 20);
    this->mAlphaSpeed = Utils::randomf(1, 10);
    
    this->mMoveTime = 1;
    this->mMoveTimeElapsed = 0;
    
    this->setCenterPosition(Utils::random(0, Options::CAMERA_WIDTH), 0);
    
    if(Options::SOUND_ENABLE)
    {
        const char* a[] = {"berry_count_ind_a.mp3", "berry_count_ind_b.mp3", "berry_count_ind_c.mp3", "berry_count_ind_d.mp3"};
        SimpleAudioEngine::sharedEngine()->playEffect(a[Utils::random(0, 3)]);
    }
}

void KeyParticle::onDestroy()
{
    Entity::onDestroy();
}

void KeyParticle::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    this->mMoveTimeElapsed += pDeltaTime;
    
    if(this->mMoveTimeElapsed >= this->mMoveTime)
    {
        this->setRotation(this->getRotation() + this->mRotationSpeed);
        this->setOpacity(this->getOpacity() - this->mAlphaSpeed);
    }
    else
    {
        this->setCenterPosition(this->getCenterX(), this->getCenterY() + this->mMoveSpeed);
        
        this->mMoveSpeed -= Utils::coord(1);
    }
    
    if(this->getOpacity() <= 10)
    {
        this->destroy();
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

KeyParticle* KeyParticle::deepCopy()
{
    return KeyParticle::create();
}

#endif