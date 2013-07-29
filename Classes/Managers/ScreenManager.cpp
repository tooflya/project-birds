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
#include "Classic.h"
#include "Arcade.h"
#include "Progresses.h"
#include "More.h"

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
    this->mScreens[Screen::SCREEN_MORE] = new More();
    this->mScreens[Screen::SCREEN_SHOP] = new Shop();
    this->mScreens[Screen::SCREEN_MODE] = new Mode();
    this->mScreens[Screen::SCREEN_LEVELS] = new Levels();
    this->mScreens[Screen::SCREEN_CREDITS] = new Credits();
    this->mScreens[Screen::SCREEN_LOADER] = new Loader();
    this->mScreens[Screen::SCREEN_PROGRESS] = new Progress();
    this->mScreens[Screen::SCREEN_LANGUAGE] = new Language();

    this->mScreens[Screen::SCREEN_CLASSIC_GAME] = NULL;
    this->mScreens[Screen::SCREEN_ARCADE_GAME] = NULL;
    this->mScreens[Screen::SCREEN_PROGRESS_GAME] = NULL;
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

            /*this->mScreens[Screen::SCREEN_MENU] = new Menu();
            this->mScreens[Screen::SCREEN_SETTINGS] = new Settings();
            this->mScreens[Screen::SCREEN_SHOP] = new Shop();
            this->mScreens[Screen::SCREEN_MODE] = new Mode();
            this->mScreens[Screen::SCREEN_LEVELS] = new Levels();
            this->mScreens[Screen::SCREEN_CREDITS] = new Credits();
            this->mScreens[Screen::SCREEN_LANGUAGE] = new Language();
            
            delete this->mScreens[Screen::SCREEN_CLASSIC_GAME];*/
            //CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_ARCADE_GAME]);
            //CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_PROGRESS_GAME]);

        break;
        default:

            if(this->mScreens[Screen::SCREEN_CLASSIC_GAME] == NULL) // TODO: Temp solution :(
            this->mScreens[Screen::SCREEN_CLASSIC_GAME] = new Classic();
            this->mScreens[Screen::SCREEN_ARCADE_GAME] = new Arcade();
            this->mScreens[Screen::SCREEN_PROGRESS_GAME] = new Progresses();
            /*delete this->mScreens[Screen::SCREEN_MENU];
           delete  this->mScreens[Screen::SCREEN_SETTINGS];
            delete this->mScreens[Screen::SCREEN_SHOP];
            delete this->mScreens[Screen::SCREEN_MODE];
           delete  this->mScreens[Screen::SCREEN_LEVELS];
          delete   this->mScreens[Screen::SCREEN_CREDITS];
          delete   this->mScreens[Screen::SCREEN_PROGRESS];
         delete    this->mScreens[Screen::SCREEN_LANGUAGE];

            this->mScreens[Screen::SCREEN_CLASSIC_GAME] = new Classic();
            //this->mScreens[Screen::SCREEN_ARCADE_GAME] = new Level();
            //this->mScreens[Screen::SCREEN_PROGRESS_GAME] = new Level();*/

        break;
    }       

    //CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
    //CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    //CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
}

// ===========================================================
// Override Methods
// ===========================================================

#endif