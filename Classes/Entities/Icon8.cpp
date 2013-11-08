#ifndef CONST_ICON8
#define CONST_ICON8

#include "Icon8.h"

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

Icon8::Icon8(const char* pTextureFileName, CCNode* pParent) :
    Entity(pTextureFileName, 3, 3, pParent)
    {
        this->mAnimationTime = Utils::randomf(0, 5.0);
        this->mAnimationTimeElapsed = 0;
        
        this->setStartFrame(0);
        this->setFinishFrame(7);
    }

Icon8::Icon8(const char* pTextureFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent) :
Entity(pTextureFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent)
{
    this->mAnimationTime = Utils::randomf(0, 5.0);
    this->mAnimationTimeElapsed = 0;
}

Icon8* Icon8::create(const char* pTextureFileName, CCNode* pParent)
{
	Icon8* entity = new Icon8(pTextureFileName, pParent);
    entity->autorelease();

    return entity;
}

Icon8* Icon8::create(const char* pTextureFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent)
{
	Icon8* entity = new Icon8(pTextureFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent);
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void Icon8::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    this->mAnimationTimeElapsed += pDeltaTime;
    
    if(this->mAnimationTimeElapsed >= this->mAnimationTime)
    {
        this->animate(0.06, 1);
        
        this->mAnimationTime = Utils::randomf(0, 5.0);
        this->mAnimationTimeElapsed = 0;
    }
}

void Icon8::onAnimationEnd()
{
    Entity::onAnimationEnd();
    
    this->setCurrentFrameIndex(0);
}

void Icon8::onCreate()
{
    Entity::onCreate();
}

void Icon8::onDestroy()
{
    Entity::onDestroy();
}

#endif