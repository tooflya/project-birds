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
#include "Episodes.h"

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

ScreenManager::ScreenManager() :
	mScreens(),
	mCurrentScreenIndex(0)
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
    #if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
    this->load(3, -1);
    
	this->mScreens[Screen::SCREEN_LOADER] = Loader::create();
	#endif
}

void ScreenManager::set(int pIndex)
{
	#if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
	CCAssert(false, "This build is compiled without preload instructions so need to use new objects.");
	#endif
    
    this->mCurrentScreenIndex = pIndex;
    
    CCTransitionScene* transition = CCTransitionFade::create(0.3, this->mScreens[pIndex]);

    CCDirector::sharedDirector()->replaceScene(transition);
}

void ScreenManager::set(Screen* pScreen)
{
	#if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
	CCAssert(false, "This build is compiled with preload instructions so need to use exist arrays.");
	#endif

    float pAnimationTime = 0.3;
    this->mCurrentScreenIndex = -1;
    
    CCTransitionScene* transition = CCTransitionFade::create(pAnimationTime, pScreen);
    
    CCDirector::sharedDirector()->replaceScene(transition);
}

void ScreenManager::load(int pAction, int pDo)
{
	#if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
	CCAssert(false, "This build is compiled without preload instructions so need to use new objects.");
	#endif
    
    switch(pAction)
    {
        case 3:
        case 4:
        case 5:
            
            switch(pDo)
            {
                case 1:
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_CLASSIC_GAME]);
                break;
                case 2:
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_ARCADE_GAME]);
                break;
                case 3:
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_PROGRESS_GAME]);
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
                this->mScreens[Screen::SCREEN_LEVELS] = Levels::create();
                break;
            }
			break;
            
        default:
            switch(pDo)
            {
                default:
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_MENU]);
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_SETTINGS]);
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_CREDITS]);
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_PROGRESS]);
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_MORE]);
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_LANGUAGE]);
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_MODE]);
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_SHOP]);
                CC_SAFE_RELEASE(this->mScreens[Screen::SCREEN_LEVELS]);
                break;
                    
                case 1:
                this->mScreens[Screen::SCREEN_CLASSIC_GAME] = Classic::create();
                break;
                case 2:
                this->mScreens[Screen::SCREEN_ARCADE_GAME] = Arcade::create();
                break;
                case 3:
                this->mScreens[Screen::SCREEN_PROGRESS_GAME] = Progresses::create();
                break;
            }
        break;
    }
}

// ===========================================================
// Override Methods
// ===========================================================

#endif