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

void ScreenManager::load(int pAction)
{
    switch(pAction)
    {
        case 3:

            // TODO: Return the world!

        break;
        default:

            CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_MENU]);
            CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_SETTINGS]);
            CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_SHOP]);
            CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_MODE]);
            CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_LEVELS]);
            CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_CREDITS]);
            CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_PROGRESS]);
            CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_LANGUAGE]);

            this->mScreens[Screen::SCREEN_CLASSIC_GAME] = new Classic();
            //this->mScreens[Screen::SCREEN_ARCADE_GAME] = new Level();
            //this->mScreens[Screen::SCREEN_PROGRESS_GAME] = new Level();

        break;
    }
}

// ===========================================================
// Override Methods
// ===========================================================

#endif