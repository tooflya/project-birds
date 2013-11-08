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
}

void Screen::onExit()
{
    CCScene::onExit();

    this->stopAllActions();
    this->unscheduleAllSelectors();

    this->release();
}

void Screen::visit()
{
    CCScene::visit();
}

#endif