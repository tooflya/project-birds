#ifndef CONST_APPDELEGATE
#define CONST_APPDELEGATE

#include "AppDelegate.h"

#include "Loading.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ScreenManager* AppDelegate::screens = NULL;

bool AppDelegate::IS_ALREADY_PLAYED = false;
bool AppDelegate::IS_IPOD = true;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

void AppDelegate::addCoins(int pCount, int pType)
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_COINS_ID[pType], AppDelegate::getCoins(pType) + pCount);

    CCUserDefault::sharedUserDefault()->flush();
}

void AppDelegate::removeCoins(int pCount, int pType)
{
    int newCoinsCount = AppDelegate::getCoins(pType) - pCount;

    if(newCoinsCount < 0)
    {
        newCoinsCount = 0;
    }
    
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_COINS_ID[pType], newCoinsCount);

    CCUserDefault::sharedUserDefault()->flush();
}

int AppDelegate::getCoins(int pType)
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey(Options::SAVE_DATA_COINS_ID[pType]);
} 

void AppDelegate::changeLanguage(int pId)
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_LANGUAGE_ID, pId);

    CCUserDefault::sharedUserDefault()->flush();
}

int AppDelegate::getSelectedLanguage()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey(Options::SAVE_DATA_LANGUAGE_ID);
}

bool AppDelegate::isInstalled()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("installed") == 1;
}

void AppDelegate::install()
{
    AppDelegate::changeLanguage(AppDelegate::getSelectedLanguage());

    CCUserDefault::sharedUserDefault()->setIntegerForKey("music_enable", AppDelegate::isInstalled() ? Options::MUSIC_ENABLE : 1);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("sound_enable", AppDelegate::isInstalled() ? Options::SOUND_ENABLE : 1);
    
    CCUserDefault::sharedUserDefault()->setIntegerForKey("installed", 1);

    CCUserDefault::sharedUserDefault()->setIntegerForKey("rate", 0);
    
    if(AppDelegate::getLastVisitDaysCount() != 0)
    {
        CCUserDefault::sharedUserDefault()->setIntegerForKey("last_visit_days_count", 0);
    } else CCUserDefault::sharedUserDefault()->setIntegerForKey("last_visit_days_count", -1);

    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_COINS_ID[0], 0);
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_COINS_ID[1], 0);
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_COINS_ID[2], 5);
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_COINS_ID[3], 0);

    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_BEST_RESULT[0], 0);
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_BEST_RESULT[1], 0);

    int id = -1;
    for(int i = 1; i < 4; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            char text[64];

            sprintf(text, "item_%d_bought", ++id);

            CCUserDefault::sharedUserDefault()->setIntegerForKey(text, 0);

            if(i == 1)
            {
                char text[64];

                sprintf(text, "weapon_%d_selected", i * j);

                if(j == 0)
                {
                    CCUserDefault::sharedUserDefault()->setIntegerForKey(text, 1);
                }
                else
                {
                    CCUserDefault::sharedUserDefault()->setIntegerForKey(text, 0);
                }
            }
        }
    }
    
    CCUserDefault::sharedUserDefault()->setIntegerForKey("item_0_bought", 1);

    for(int i = 0; i < 80; i++)
    {
        char text[64];

        sprintf(text, "level_%d_stars", i);

        CCUserDefault::sharedUserDefault()->setIntegerForKey(text, -1);
    }

    CCUserDefault::sharedUserDefault()->setIntegerForKey("level_0_stars", 0);

    CCUserDefault::sharedUserDefault()->flush();
}

bool AppDelegate::isItemBought(int pItem)
{
    char text[64];

    sprintf(text, "item_%d_bought", pItem);

    return CCUserDefault::sharedUserDefault()->getIntegerForKey(text) == 1;
}

bool AppDelegate::isItemSelected(int pItem)
{
    char text[64];

    sprintf(text, "weapon_%d_selected", pItem);

    return CCUserDefault::sharedUserDefault()->getIntegerForKey(text) == 1;
}

void AppDelegate::selectItem(int pItem)
{
    char text[64];

    for(int i = 0; i < 20; i++)
    {
        sprintf(text, "weapon_%d_selected", i);

        CCUserDefault::sharedUserDefault()->setIntegerForKey(text, 0);
    }

    sprintf(text, "weapon_%d_selected", pItem);

    CCUserDefault::sharedUserDefault()->setIntegerForKey(text, 1);
}

int AppDelegate::getSelectedWeaponId()
{
    char text[64];
    
    for(int i = 0; i < 20; i++)
    {
        sprintf(text, "weapon_%d_selected", i);
        
        if(CCUserDefault::sharedUserDefault()->getIntegerForKey(text) == 1)
        {
            return i;
        }
    }
    
    return 0;
}

void AppDelegate::buyItem(int pItem)
{
    char text[64];

    sprintf(text, "item_%d_bought", pItem);

    CCUserDefault::sharedUserDefault()->setIntegerForKey(text, 1);

    CCUserDefault::sharedUserDefault()->flush();
}

int AppDelegate::getLevelStars(int pLevel)
{
    char text[64];

    sprintf(text, "level_%d_stars", pLevel);

    return CCUserDefault::sharedUserDefault()->getIntegerForKey(text);
}

int AppDelegate::getLevelStarsTotalCount()
{
    int count = 0;
    
    for(int i = 0; i < 80; i++)
    {
        int next = getLevelStars(i);
        
        if(next > 0) count += next;
    }
    
    return count;
}
void AppDelegate::setLevelStars(int pLevel, int pStars)
{
    char text[64];
    
    sprintf(text, "level_%d_stars", pLevel);
    
    CCUserDefault::sharedUserDefault()->setIntegerForKey(text, pStars);
    
    CCUserDefault::sharedUserDefault()->flush();
}

void AppDelegate::setMusicEnable(bool pValue)
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey("music_enable", pValue ? 1 : 0);

    CCUserDefault::sharedUserDefault()->flush();
}

void AppDelegate::setSoundEnable(bool pValue)
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey("sound_enable", pValue ? 1 : 0);

    CCUserDefault::sharedUserDefault()->flush();
}

bool AppDelegate::isMusicEnable()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("music_enable") == 1;
}

bool AppDelegate::isSoundEnable()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("sound_enable") == 1;
}

void AppDelegate::setRate()
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey("rate", 1);
}

bool AppDelegate::isRate()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("rate") == 1;
}

void AppDelegate::setBestResult(int pResult, int pType)
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_BEST_RESULT[pType], pResult);

    CCUserDefault::sharedUserDefault()->flush();
}

int AppDelegate::getBestResult(int pType)
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey(Options::SAVE_DATA_BEST_RESULT[pType]);
}

CCArray* AppDelegate::getArrayOfBoughtBirds()
{
    CCArray* array = CCArray::create();
    
    for(int i = 0; i < 20; i++)
    {
        if(AppDelegate::isItemBought(i + 20))
        {
            array->addObject(CCInteger::create(i));
        }
    }
    
    return array;
}

int AppDelegate::getRandomBonusBird()
{
    CCArray* array = AppDelegate::getArrayOfBoughtBirds();
    
    return static_cast<CCInteger*>(array->objectAtIndex(Utils::random(0, array->count() - 1)))->getValue();
}

bool AppDelegate::isSomeBonusBirdBought()
{
    return AppDelegate::getArrayOfBoughtBirds()->count() > 0;
}

void AppDelegate::setLastVisitDaysCount(int pCount)
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey("last_visit_days_count", pCount);
    
    CCUserDefault::sharedUserDefault()->flush();
}

int AppDelegate::getLastVisitDaysCount()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("last_visit_days_count");
}

// ===========================================================
// Override Methods
// ===========================================================

bool AppDelegate::applicationDidFinishLaunching()
{
    CCDirector* director = CCDirector::sharedDirector();
    CCEGLView*  EGLView = CCEGLView::sharedOpenGLView();
    CCSize  screenSize = EGLView->getFrameSize();
    
    director->setOpenGLView(EGLView);
    director->setContentScaleFactor(designResolutionSize.height / screenSize.height);
    
    Options::SCREEN_WIDTH  = designResolutionSize.width;
    Options::SCREEN_HEIGHT = designResolutionSize.height;
    
    Options::SCREEN_CENTER_X = designResolutionSize.width / 2;
    Options::SCREEN_CENTER_Y = designResolutionSize.height / 2;
    
    Options::CAMERA_WIDTH  = screenSize.width;
    Options::CAMERA_HEIGHT = screenSize.height;
    
    Options::CAMERA_CENTER_X  = screenSize.width / 2;
    Options::CAMERA_CENTER_Y = screenSize.height / 2;

    vector <string> searchPath;
    
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    
    /*if(AppDelegate::IS_IPOD)
    {
        searchPath.push_back(resources1280x720.directory);
        
        Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPOD4;
    }
    else*/
    {
        searchPath.push_back(resources1280x720.directory);
        
        if(Options::CAMERA_HEIGHT == 960)
        {
            Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPHONE4;
        }
        else
        {
            Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPHONE5;
        }
    }
    
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    
    searchPath.push_back(resources1280x720xPNG.directory);
    
    Options::DEVICE_TYPE = Options::DEVICE_TYPE_MAC;

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    if(Options::CAMERA_WIDTH == 720)
    {
        Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPHONE4;
        
        searchPath.push_back(resources1280x720.directory);
    }
    else
    {
        Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPHONE5;
        
        searchPath.push_back(resources1280x720.directory);
    }
    
#else

    searchPath.push_back(resources1280x720xPNG.directory);

#endif

    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

    director->setDisplayStats(false);
    
    director->setProjection(kCCDirectorProjection2D);

    director->setAnimationInterval(1.0f / 60.0f);

    if(!AppDelegate::isInstalled())
    {
        AppDelegate::install();
    }

    Options::init();

    Screen* pScene = Loading::create();

    director->runWithScene(pScene);

    return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    CCDirector::sharedDirector()->pause();

    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    CCDirector::sharedDirector()->resume();

    if(Options::MUSIC_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    }
}

#endif