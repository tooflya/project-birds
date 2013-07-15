#ifndef CONST_SCREENMANAGER
#define CONST_SCREENMANAGER

#include "ScreenManager.h"

#include "Screen.h"

#include "Menu.h"
#include "Settings.h"
#include "Shop.h"
#include "Mode.h"
#include "Levels.h"
#include "Credits.h"
#include "Loader.h"
#include "Progress.h"
#include "Language.h"
#include "Level.h"
#include "Classic.h"

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

ScreenManager::ScreenManager()
{
    this->generate();
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Getters
// ===========================================================

// ===========================================================
// Setters
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

void ScreenManager::generate()
{
    this->mScreens[Screen::SCREEN_MENU] = new Menu();
    this->mScreens[Screen::SCREEN_SETTINGS] = new Settings();
    this->mScreens[Screen::SCREEN_SHOP] = new Shop();
    this->mScreens[Screen::SCREEN_MODE] = new Mode();
    this->mScreens[Screen::SCREEN_LEVELS] = new Levels();
    this->mScreens[Screen::SCREEN_CREDITS] = new Credits();
    this->mScreens[Screen::SCREEN_LOADER] = new Loader();
    this->mScreens[Screen::SCREEN_PROGRESS] = new Progress();
    this->mScreens[Screen::SCREEN_LANGUAGE] = new Language();
}

void ScreenManager::set(float pAnimationTime, int pIndex)
{
    this->mCurrentScreenIndex = pIndex;
    
    CCTransitionScene* transition = CCTransitionFade::create(pAnimationTime, this->mScreens[pIndex]);

    CCDirector::sharedDirector()->pushScene(transition);
}

void ScreenManager::load()
{
    this->mScreens[Screen::SCREEN_CLASSIC_GAME] = new Classic();
    //this->mScreens[Screen::SCREEN_ARCADE_GAME] = new Level();
    //this->mScreens[Screen::SCREEN_PROGRESS_GAME] = new Level();
}

// ===========================================================
// Override Methods
// ===========================================================

#endif