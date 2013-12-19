#ifndef CONST_SHIELDDISPLAY
#define CONST_SHIELDDISPLAY

#include "ShieldDisplay.h"

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

ShieldDisplay::ShieldDisplay() :
    Entity("bonus-shield@2x.png"),
	mLights()
    {
        this->mLights[0] = 0;
        this->mLights[1] = 0;
    }

ShieldDisplay* ShieldDisplay::create()
{
    ShieldDisplay* entity = new ShieldDisplay();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void ShieldDisplay::onAnimationsEnd()
{
    this->destroy();
}

// ===========================================================
// Virtual Methods
// ===========================================================

void ShieldDisplay::onCreate()
{
    Entity::onCreate();

    this->setOpacity(0);
    
    this->mLights[0] = static_cast<Game*>(this->getParent()->getParent()->getParent())->mKeysLights->create();
    this->mLights[1] = static_cast<Game*>(this->getParent()->getParent()->getParent())->mKeysLights->create();
    
    this->mLights[0]->setOpacity(0);
    this->mLights[1]->setOpacity(0);
}

void ShieldDisplay::setCenterPosition(float pCenterX, float pCenterY)
{
    Entity::setCenterPosition(pCenterX, pCenterY);
    
    this->mLights[0]->setCenterPosition(pCenterX, pCenterY);
    this->mLights[1]->setCenterPosition(pCenterX, pCenterY);

    if(this->numberOfRunningActions() > 0) return;

    this->runAction(CCSequence::create(CCFadeIn::create(0.2), CCFadeOut::create(0.2), NULL));

    this->mLights[0]->runAction(CCSequence::create(CCFadeIn::create(0.2), CCFadeOut::create(0.2), CCCallFunc::create(this, callfunc_selector(ShieldDisplay::onAnimationsEnd)), NULL));
    this->mLights[1]->runAction(CCSequence::create(CCFadeIn::create(0.2), CCFadeOut::create(0.2), CCCallFunc::create(this, callfunc_selector(ShieldDisplay::onAnimationsEnd)), NULL));

    if(Options::SOUND_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LEVEL_UNLOCK);
    }
}

void ShieldDisplay::onDestroy()
{
    Entity::onDestroy();
    
    if(this->mLights[0] != 0)
    {
        this->mLights[0]->destroy();
        this->mLights[1]->destroy();
    
        this->mLights[0] = 0;
        this->mLights[1] = 0;
    }
}

void ShieldDisplay::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(this->mLights[0] != 0)
    {
        this->mLights[0]->setRotation(this->mLights[0]->getRotation() - 1);
        this->mLights[1]->setRotation(this->mLights[1]->getRotation() + 1);
    }
}

ShieldDisplay* ShieldDisplay::deepCopy()
{
    return ShieldDisplay::create();
}

#endif