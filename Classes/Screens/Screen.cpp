#ifndef CONST_SCREEN
#define CONST_SCREEN

#include "Screen.h"

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

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Screen::~Screen()
{
    this->removeAllChildrenWithCleanup(true);
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    
    CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
}

Screen::Screen()
{
}

// ===========================================================
// Getters
// ===========================================================

// ===========================================================
// Setters
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

void Screen::onTouchButtonsCallback(const int pAction, const int pID)
{
}

// ===========================================================
// Override Methods
// ===========================================================

bool Screen::containsTouchLocation(CCTouch* touch)
{
    return true;
}

void Screen::onEnter()
{
    CCScene::onEnter();
    
    this->scheduleUpdate();

    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    CCDirector::sharedDirector()->getKeypadDispatcher()->addDelegate(this);
    #endif
}

void Screen::onExit()
{
    CCScene::onExit();

    this->stopAllActions();
    this->unscheduleAllSelectors();

    this->release();
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    CCDirector::sharedDirector()->getKeypadDispatcher()->removeDelegate(this);
    #endif
}

void Screen::visit()
{
    CCScene::visit();
}

void Screen::keyBackClicked()
{
    this->keyBackClicked(true);
}

void Screen::keyBackClicked(bool pSound)
{
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    if(Options::SOUND_ENABLE && pSound)
    {
        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_TAP);
    }
    #endif
}

#endif