#ifndef CONST_DISPLAY
#define CONST_DISPLAY

#include "KeyDisplay.h"

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

KeyDisplay::KeyDisplay() :
    Entity("popup_key_ico_fall@2x.png")
    {
        this->mLights[0] = 0;
        this->mLights[1] = 0;
    }

KeyDisplay* KeyDisplay::create()
{
    KeyDisplay* entity = new KeyDisplay();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void KeyDisplay::onCreate()
{
    Entity::onCreate();
    
    this->setScale(1);
    this->setOpacity(255);
    
    this->mLights[0] = static_cast<Game*>(this->getParent()->getParent()->getParent())->mKeysLights->create();
    this->mLights[1] = static_cast<Game*>(this->getParent()->getParent()->getParent())->mKeysLights->create();
    
    this->mLights[0]->setOpacity(0);
    this->mLights[1]->setOpacity(0);
    
    this->mTime = 1;
    this->mTimeElapsed = 0;
    this->mActionCount = 0;
}

void KeyDisplay::setCenterPosition(float pCenterX, float pCenterY)
{
    Entity::setCenterPosition(pCenterX, pCenterY);
    
    this->runAction(CCMoveTo::create(1.0, ccp(Options::CAMERA_CENTER_X + Utils::coord(Utils::random(-150, 150)), Options::CAMERA_CENTER_Y + Utils::coord(Utils::random(-150, 150)))));
    this->runAction(CCRotateTo::create(1.0, Utils::random(360, 3000)));
}

void KeyDisplay::onDestroy()
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

void KeyDisplay::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    this->mTimeElapsed += pDeltaTime;
    
    if(this->mTimeElapsed >= this->mTime)
    {
        this->mTimeElapsed = 0;
        
        if(this->mActionCount == 1)
        {
        }
        else if(mActionCount == 2)
        {
            this->runAction(CCFadeTo::create(1.0, 0));
            
            this->mLights[0]->runAction(CCFadeTo::create(1.0, 0));
            this->mLights[1]->runAction(CCFadeTo::create(1.0, 0));
            
            this->mTime = 2;
        }
        else
        {
            this->mLights[0]->setCenterPosition(this->getCenterX(), this->getCenterY());
            this->mLights[1]->setCenterPosition(this->getCenterX(), this->getCenterY());
            
            this->mLights[0]->runAction(CCFadeTo::create(0.5, 255));
            this->mLights[1]->runAction(CCFadeTo::create(0.5, 255));
            
            if(Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LEVEL_UNLOCK);
            }
            
            this->mTime = 0.5;
        }
        
        this->mActionCount++;
    }
    
    if(this->getOpacity() <= 0)
    {
        this->destroy();
    }
    
    if(this->mLights[0] != 0)
    {
        this->mLights[0]->setRotation(this->mLights[0]->getRotation() - 1);
        this->mLights[1]->setRotation(this->mLights[1]->getRotation() + 1);
    }
}

KeyDisplay* KeyDisplay::deepCopy()
{
    return KeyDisplay::create();
}

#endif