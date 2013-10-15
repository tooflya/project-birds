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
#include "Game.h"
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

ScreenManager* ScreenManager::create()
{
    ScreenManager* manager = new ScreenManager();
    manager->autorelease();
    manager->retain();
    
    return manager;
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
    this->load(3, 1);
    this->mScreens[Screen::SCREEN_LOADER] = Loader::create();
}

void ScreenManager::set(float pAnimationTime, int pIndex)
{
    pAnimationTime = 0.3;
    this->mCurrentScreenIndex = pIndex;
    
    CCTransitionScene* transition = CCTransitionFade::create(pAnimationTime, this->mScreens[pIndex]);

    CCDirector::sharedDirector()->pushScene(transition);
}

void ScreenManager::load(int pAction, int pDo)
{
    switch(pAction)
    {
        case 3:
        case 5:
            
            switch(pDo)
            {
                case 0:
                    
                CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_CLASSIC_GAME]);
                //CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_ARCADE_GAME]);
                //CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_PROGRESS_GAME]);
                
                break;
                
                default:
                
                this->mScreens[Screen::SCREEN_MENU] = Menu::create();
                this->mScreens[Screen::SCREEN_SETTINGS] = Settings::create();
                this->mScreens[Screen::SCREEN_CREDITS] = Credits::create();
                this->mScreens[Screen::SCREEN_PROGRESS] = Progress::create();
                this->mScreens[Screen::SCREEN_MORE] = More::create();
                this->mScreens[Screen::SCREEN_LANGUAGE] = Language::create();
                this->mScreens[Screen::SCREEN_MODE] = Mode::create();
                this->mScreens[Screen::SCREEN_SHOP] = Shop::create();
                //this->mScreens[Screen::SCREEN_LEVELS] = Levels::create();
                
                break;
            }
            
        break;
            
        default:
            
            switch(pDo)
            {
                case 0:
                    
                CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_MENU]);
                CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_SETTINGS]);
                CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_CREDITS]);
                CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_PROGRESS]);
                CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_MORE]);
                CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_LANGUAGE]);
                CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_MODE]);
                CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_SHOP]);
                //CC_SAFE_RELEASE_NULL(this->mScreens[Screen::SCREEN_LEVELS]);
                    
                break;
                    
                default:

                this->mScreens[Screen::SCREEN_CLASSIC_GAME] = Classic::create();
                //this->mScreens[Screen::SCREEN_ARCADE_GAME] = Arcade::create();
                //this->mScreens[Screen::SCREEN_PROGRESS_GAME] = Progresses::create();
                
                break;
            }

        break;
    }
}

// ===========================================================
// Override Methods
// ===========================================================

#endif