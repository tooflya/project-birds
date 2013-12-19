#ifndef CONST_APPDELEGATE
#define CONST_APPDELEGATE

#include "AppDelegate.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "CCStoreController.h"
#include "CCStoreInventory.h"
#include "CCStoreInfo.h"
#include "CCSoomla.h"
#include "InAppPurchasesList.h"
#endif

#include "SplashScreen.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ScreenManager* AppDelegate::screens = NULL;

bool AppDelegate::IS_ALREADY_PLAYED = false;
bool AppDelegate::IS_IPOD = true;

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
GameCenter* AppDelegate::mGameCenter = new GameCenter();
#endif

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

AppDelegate::AppDelegate()
{
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    handler = new InAppPurchaseEventHandler();
    #endif
}

AppDelegate::~AppDelegate()
{
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    soomla::CCSoomla::sharedSoomla()->removeEventHandler(handler);
    #endif
}

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
    
    if(pType == Options::SAVE_DATA_COINS_TYPE_LIVES)
    {
        int index = 4;
        
        while(index >= 0)
        {
            if(AppDelegate::isLiveRestoring(index))
            {
                index--;
            }
            else
            {
                AppDelegate::setLivesMustRestore(index, true);
                
                index = -1;
            }
        }
    }
}

int AppDelegate::getCoins(int pType)
{
    if(pType == Options::SAVE_DATA_COINS_TYPE_LIVES)
    {
        int index = 4;
        
        while(index > -1)
        {
            if(AppDelegate::isLiveRestoring(index))
            {
                if(Utils::millisecondNow() - AppDelegate::getLivesRestoreTime(index) >= (30 * 60 * 1000))
                {
                    AppDelegate::setLivesMustRestore(index, false);
                    
                    AppDelegate::addCoins(1, pType);
                }
            }
            
            index--;
        }
    }
    
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

void AppDelegate::install(bool soft)
{
    AppDelegate::changeLanguage(AppDelegate::getSelectedLanguage());
    
    CCUserDefault::sharedUserDefault()->setStringForKey("last_version", Options::STRING_VERSION);
    
    CCUserDefault::sharedUserDefault()->setBoolForKey("temp_inapp_inf", false);

    CCUserDefault::sharedUserDefault()->setIntegerForKey("music_enable", AppDelegate::isInstalled() ? Options::MUSIC_ENABLE : 1);
    CCUserDefault::sharedUserDefault()->setIntegerForKey("sound_enable", AppDelegate::isInstalled() ? Options::SOUND_ENABLE : 1);
    
    CCUserDefault::sharedUserDefault()->setIntegerForKey("installed", 1);

    CCUserDefault::sharedUserDefault()->setIntegerForKey("rate", 0);
    
    if(AppDelegate::getLastVisitDaysCount() != 0)
    {
        CCUserDefault::sharedUserDefault()->setIntegerForKey("last_visit_days_count", 0);
    } else if(!soft) CCUserDefault::sharedUserDefault()->setIntegerForKey("last_visit_days_count", -1);

    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_COINS_ID[0], 0);
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_COINS_ID[1], 0);
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_COINS_ID[2], 5);
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_COINS_ID[3], 0);

    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_BEST_RESULT[0], 0);
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_BEST_RESULT[1], 0);

    if(!soft) CCUserDefault::sharedUserDefault()->setBoolForKey("google_plus_entered", false);
    if(!soft) CCUserDefault::sharedUserDefault()->setBoolForKey("ads", true);
    if(!soft) CCUserDefault::sharedUserDefault()->setBoolForKey("is_video_showed", false);
    
    if(soft)
    {
        AppDelegate::mGameCenter->clearAllAchievements();
        AppDelegate::mGameCenter->clearAllScores();
    }
    
    AppDelegate::setTotalBirdsKilled();
    AppDelegate::setTotalLevelsUnlocked();

    CCUserDefault::sharedUserDefault()->setBoolForKey("mode_0_unlocked", false);
    CCUserDefault::sharedUserDefault()->setBoolForKey("mode_1_unlocked", false);
    
    CCUserDefault::sharedUserDefault()->setBoolForKey("live_0_restoring", false);
    CCUserDefault::sharedUserDefault()->setBoolForKey("live_1_restoring", false);
    CCUserDefault::sharedUserDefault()->setBoolForKey("live_2_restoring", false);
    CCUserDefault::sharedUserDefault()->setBoolForKey("live_3_restoring", false);
    CCUserDefault::sharedUserDefault()->setBoolForKey("live_4_restoring", false);
    
    CCUserDefault::sharedUserDefault()->setBoolForKey("live_0_restore_time", 0);
    CCUserDefault::sharedUserDefault()->setBoolForKey("live_1_restore_time", 0);
    CCUserDefault::sharedUserDefault()->setBoolForKey("live_2_restore_time", 0);
    CCUserDefault::sharedUserDefault()->setBoolForKey("live_3_restore_time", 0);
    CCUserDefault::sharedUserDefault()->setBoolForKey("live_4_restore_time", 0);
    
    for(int i = 0; i < 7; i++)
    {
        char text[64];
        
        sprintf(text, "leader_board_birds_killed_%d", i);
        
        CCUserDefault::sharedUserDefault()->setIntegerForKey(text, 0);
    }
    
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

    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    callStaticVoidMethodWithInt("com/tooflya/projectbirds/notify/NotifyService", "setLastVisitDaysCount", pCount);
    #endif
}

int AppDelegate::getLastVisitDaysCount()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("last_visit_days_count");
}

string AppDelegate::lastVersion()
{
    return CCUserDefault::sharedUserDefault()->getStringForKey("last_version");
}

bool AppDelegate::tempPublisherInAppInformationShowed()
{
    return CCUserDefault::sharedUserDefault()->getBoolForKey("temp_inapp_inf");
}

bool AppDelegate::isModeUnlocked(int pId)
{
    char text[64];
    
    sprintf(text, "mode_%d_unlocked", pId);
    
    return CCUserDefault::sharedUserDefault()->getBoolForKey(text);
}

void AppDelegate::setModeUnlocked(int pId)
{
    char text[64];
    
    sprintf(text, "mode_%d_unlocked", pId);
    
    CCUserDefault::sharedUserDefault()->setBoolForKey(text, true);
    CCUserDefault::sharedUserDefault()->flush();
}

void AppDelegate::setLivesMustRestore(int pIndex, bool pMust)
{
    char text[64];
    
    sprintf(text, "live_%d_restore_time", pIndex);
    
    if(pMust)
    {
        CCUserDefault::sharedUserDefault()->setIntegerForKey(text, Utils::millisecondNow());
        sprintf(text, "live_%d_restoring", pIndex);
        CCUserDefault::sharedUserDefault()->setBoolForKey(text, true);

        #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        callStaticVoidMethod("com/tooflya/projectbirds/notify/NotifyService", "setLivesMustRestore");
        #endif
    }
    else
    {
        CCUserDefault::sharedUserDefault()->setIntegerForKey(text, 0);
        sprintf(text, "live_%d_restoring", pIndex);
        CCUserDefault::sharedUserDefault()->setBoolForKey(text, false);
    }
    
    CCUserDefault::sharedUserDefault()->flush();
}

int AppDelegate::getLivesRestoreTime(int pIndex)
{
    char text[64];

    sprintf(text, "live_%d_restore_time", pIndex);

    int t = CCUserDefault::sharedUserDefault()->getIntegerForKey(text);
    /**sprintf(text, "live_%d_restoring", pIndex);
    CCUserDefault::sharedUserDefault()->setBoolForKey(text, false);*/
    return t;
}

bool AppDelegate::isLiveRestoring(int pIndex)
{
    char text[64];
    
    sprintf(text, "live_%d_restoring", pIndex);
    
    return CCUserDefault::sharedUserDefault()->getBoolForKey(text);
}

int AppDelegate::getLiveNearestReleaseTime(int pIndex)
{
    int index = 4;
    int time = INT_MAX;
    
    while(index >= 0)
    {
        if(AppDelegate::isLiveRestoring(index))
        {
            if(getLivesRestoreTime(index) < time)
            {
                time = getLivesRestoreTime(index);
            }
        }
        
        index--;
    }
    
    return time;
}

void AppDelegate::nativeOnGooglePlusSignInSucceeded()
{
    if(screens == NULL) return;

    CCUserDefault::sharedUserDefault()->setBoolForKey("google_plus_entered", true);
    
    screens->mScreens[screens->mCurrentScreenIndex]->onGooglePlusSignInSucceeded();
}

bool AppDelegate::isAdvertisiment()
{
    #if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
    return false;
    #endif

    return CCUserDefault::sharedUserDefault()->getBoolForKey("ads");
}

int AppDelegate::getTotalBirdsKilled()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("leader_board_birds_killed");
}

int AppDelegate::getTotalLevelsUnlocked()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("leader_board_levels_unlocked");
}

void AppDelegate::setTotalBirdsKilled()
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey("leader_board_birds_killed", 0);
    CCUserDefault::sharedUserDefault()->flush();
}

void AppDelegate::setTotalLevelsUnlocked()
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey("leader_board_levels_unlocked", 0);
    CCUserDefault::sharedUserDefault()->flush();
}

void AppDelegate::addTotalBirdsKilled(int add, int color)
{
    char text[64];
    
    sprintf(text, "leader_board_birds_killed_%d", color);
    
    if(AppDelegate::getTotalBirdsKilled() >= 5000)
    {
        mGameCenter->postAchievement(Options::ACHIEVEMENTS_UNLOCK_LORD_OF_BIRDS, 100);
    }
    else if(AppDelegate::getTotalBirdsKilled() >= 1000)
    {
        mGameCenter->postAchievement(Options::ACHIEVEMENTS_UNLOCK_KILLER, 100);
    }
    else if(AppDelegate::getTotalBirdsKilled() >= 500)
    {
        mGameCenter->postAchievement(Options::ACHIEVEMENTS_UNLOCK_AVIARIST, 100);
    }
    else if(AppDelegate::getTotalBirdsKilled() >= 100)
    {
        mGameCenter->postAchievement(Options::ACHIEVEMENTS_UNLOCK_JUNIOR, 100);
    }
    
    for(int i = 0; i < 7; i++)
    {
        char text2[64];
        
        sprintf(text2, "leader_board_birds_killed_%d", i);
        
        if(CCUserDefault::sharedUserDefault()->getIntegerForKey(text2) >= 5000)
        {
            const char* id = "";
            
            switch(i)
            {
                case 0:
                    id = Options::ACHIEVEMENTS_UNLOCK_LORD_OF_GREEN_BIRDS;
                break;
                case 1:
                    id = Options::ACHIEVEMENTS_UNLOCK_LORD_OF_YELLOW_BIRDS;
                break;
                case 2:
                    id = Options::ACHIEVEMENTS_UNLOCK_LORD_OF_AZURE_BIRDS;
                break;
                case 3:
                    id = Options::ACHIEVEMENTS_UNLOCK_LORD_OF_PURPLE_BIRDS;
                break;
                case 4:
                    id = Options::ACHIEVEMENTS_UNLOCK_LORD_OF_RED_BIRDS;
                break;
                case 5:
                    id = Options::ACHIEVEMENTS_UNLOCK_LORD_OF_ORANGE_BIRDS;
                break;
                case 6:
                    id = Options::ACHIEVEMENTS_UNLOCK_LORD_OF_BLUE_BIRDS;
                break;
            }
            
            mGameCenter->postAchievement(id, 100);
        }
        else if(CCUserDefault::sharedUserDefault()->getIntegerForKey(text2) >= 1000)
        {
            const char* id = "";
            
            switch(i)
            {
                case 0:
                    id = Options::ACHIEVEMENTS_UNLOCK_HUNTER_OF_GREEN_BIRDS;
                break;
                case 1:
                    id = Options::ACHIEVEMENTS_UNLOCK_HUNTER_OF_YELLOW_BIRDS;
                break;
                case 2:
                    id = Options::ACHIEVEMENTS_UNLOCK_HUNTER_OF_AZURE_BIRDS;
                break;
                case 3:
                    id = Options::ACHIEVEMENTS_UNLOCK_HUNTER_OF_PURPLE_BIRDS;
                break;
                case 4:
                    id = Options::ACHIEVEMENTS_UNLOCK_HUNTER_OF_RED_BIRDS;
                break;
                case 5:
                    id = Options::ACHIEVEMENTS_UNLOCK_HUNTER_OF_ORANGE_BIRDS;
                break;
                case 6:
                    id = Options::ACHIEVEMENTS_UNLOCK_HUNTER_OF_BLUE_BIRDS;
                break;
            }
            
            mGameCenter->postAchievement(id, 100);
        }
        else if(CCUserDefault::sharedUserDefault()->getIntegerForKey(text2) >= 500)
        {
            const char* id = "";
            
            switch(i)
            {
                case 0:
                    id = Options::ACHIEVEMENTS_UNLOCK_KILLER_OF_GREEN_BIRDS;
                    break;
                case 1:
                    id = Options::ACHIEVEMENTS_UNLOCK_KILLER_OF_YELLOW_BIRDS;
                    break;
                case 2:
                    id = Options::ACHIEVEMENTS_UNLOCK_KILLER_OF_AZURE_BIRDS;
                    break;
                case 3:
                    id = Options::ACHIEVEMENTS_UNLOCK_KILLER_OF_PURPLE_BIRDS;
                    break;
                case 4:
                    id = Options::ACHIEVEMENTS_UNLOCK_KILLER_OF_RED_BIRDS;
                    break;
                case 5:
                    id = Options::ACHIEVEMENTS_UNLOCK_KILLER_OF_ORANGE_BIRDS;
                    break;
                case 6:
                    id = Options::ACHIEVEMENTS_UNLOCK_KILLER_OF_BLUE_BIRDS;
                    break;
            }
            
            mGameCenter->postAchievement(id, 100);
        }
        else if(CCUserDefault::sharedUserDefault()->getIntegerForKey(text2) >= 100)
        {
            const char* id = "";
            
            switch(i)
            {
                case 0:
                    id = Options::ACHIEVEMENTS_UNLOCK_FAN_OF_GREEN_BIRDS;
                    break;
                case 1:
                    id = Options::ACHIEVEMENTS_UNLOCK_FAN_OF_YELLOW_BIRDS;
                    break;
                case 2:
                    id = Options::ACHIEVEMENTS_UNLOCK_FAN_OF_AZURE_BIRDS;
                    break;
                case 3:
                    id = Options::ACHIEVEMENTS_UNLOCK_FAN_OF_PURPLE_BIRDS;
                    break;
                case 4:
                    id = Options::ACHIEVEMENTS_UNLOCK_FAN_OF_RED_BIRDS;
                    break;
                case 5:
                    id = Options::ACHIEVEMENTS_UNLOCK_FAN_OF_ORANGE_BIRDS;
                    break;
                case 6:
                    id = Options::ACHIEVEMENTS_UNLOCK_FAN_OF_BLUE_BIRDS;
                    break;
            }
            
            mGameCenter->postAchievement(id, 100);
        }
    }

    CCUserDefault::sharedUserDefault()->setIntegerForKey("leader_board_birds_killed", AppDelegate::getTotalBirdsKilled() + add);
    CCUserDefault::sharedUserDefault()->setIntegerForKey(text, CCUserDefault::sharedUserDefault()->getIntegerForKey(text) + add);

    CCUserDefault::sharedUserDefault()->flush();
    
    AppDelegate::mGameCenter->postScore(Options::LEADERBOARD_BIRDS, AppDelegate::getTotalBirdsKilled());
}

void AppDelegate::addTotalLevelsUnlocked(int add)
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey("leader_board_levels_unlocked", AppDelegate::getTotalLevelsUnlocked() + add);
    CCUserDefault::sharedUserDefault()->flush();
    
    AppDelegate::mGameCenter->postScore(Options::LEADERBOARD_LEVELS, AppDelegate::getTotalLevelsUnlocked());
}

bool AppDelegate::isVideoShowed()
{
    return CCUserDefault::sharedUserDefault()->getBoolForKey("is_video_showed");
}

// ===========================================================
// Override Methods
// ===========================================================

bool AppDelegate::applicationDidFinishLaunching()
{
    CCDirector* director = CCDirector::sharedDirector();
    CCEGLView*  EGLView = CCEGLView::sharedOpenGLView();
    CCSize  screenSize = EGLView->getFrameSize();
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    soomla::CCSoomla::sharedSoomla()->addEventHandler(handler);
    
    InAppPurchasesList *assets = InAppPurchasesList::create();
    CCDictionary *storeParams = CCDictionary::create();
    
    storeParams->setObject(CCString::create(Options::SOOMLA_BASE_64_KEY), "soomSec");
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    storeParams->setObject(CCString::create(Options::GOOGLE_PLAY_BASE_64_KEY), "androidPublicKey");
    #endif
    storeParams->setObject(CCString::create(Options::SOOMLA_CUSTOM_BASE_64_KEY), "customSecret");
    
    #if COCOS2D_DEBUG >= 1 && CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    storeParams->setObject(CCBool::create(true), "androidTestMode");
    #endif
    
    soomla::CCStoreController::createShared(assets, storeParams);
    #endif
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    if(screenSize.width >= 2048)
    {
        Options::designResolutionSize = CCSizeMake(1920, 1280);
    }
    else
    {
        Options::designResolutionSize = CCSizeMake(720, 1280);
    }
	#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	//Options::designResolutionSize = CCSizeMake(270, 480);
    Options::designResolutionSize = CCSizeMake(720, 1280);
    #elif CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
	Options::designResolutionSize = CCSizeMake(1920, 1280);
    #else
	Options::designResolutionSize = CCSizeMake(720, 1280);
    #endif

	director->setOpenGLView(EGLView);
	director->setContentScaleFactor(Options::designResolutionSize.height / screenSize.height);
    
	Options::SCREEN_WIDTH = Options::designResolutionSize.width;
	Options::SCREEN_HEIGHT = Options::designResolutionSize.height;
    
	Options::SCREEN_CENTER_X = Options::designResolutionSize.width / 2;
	Options::SCREEN_CENTER_Y = Options::designResolutionSize.height / 2;
    
    Options::CAMERA_WIDTH  = screenSize.width;
    Options::CAMERA_HEIGHT = screenSize.height;
    
    Options::CAMERA_CENTER_X  = screenSize.width / 2;
    Options::CAMERA_CENTER_Y = screenSize.height / 2;

    vector <string> searchPath;
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    {
        if(Options::CAMERA_WIDTH >= 2048)
        {
            searchPath.push_back(resources2048x1536.directory);
            
            Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPAD_RETINA;
        }
        else
        {
            
            if(Options::CAMERA_HEIGHT == 960)
            {
                searchPath.push_back(resources1280x720xPVRTC2.directory);
                
                Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPHONE4;
            
                if(AppDelegate::IS_IPOD)
                {
                    Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPOD4;
                }
            }
            else
            {
                searchPath.push_back(resources1280x720.directory);
                
                Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPHONE5;
            }
        }
    }
    
    #elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    
	searchPath.push_back(resources1920x1080.directory);
    
    Options::DEVICE_TYPE = Options::DEVICE_TYPE_MAC;

    #elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    if(Options::CAMERA_HEIGHT == 1184)
    {
        Options::DEVICE_TYPE = Options::DEVICE_TYPE_NEXUS3;
        
        searchPath.push_back(resources1280x720.directory);
    }
    else if(Options::CAMERA_HEIGHT < 720)
    {
        Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPHONE5;
        
        searchPath.push_back(resources480x320.directory);
    }
    else
    {
        Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPHONE5;
        
        searchPath.push_back(resources1280x720.directory);
    }
    
    #elif CC_TARGET_PLATFORM == CC_PLATFORM_WP8
    
    searchPath.push_back(resources1280x720.directory);
    
    Options::DEVICE_TYPE = Options::DEVICE_TYPE_MAC;
    
    #else

	Options::DEVICE_TYPE = Options::DEVICE_TYPE_WINDOWS;

	searchPath.push_back(resources1920x1080.directory);

    #endif

    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

    director->setDisplayStats(false);
    
    director->setProjection(kCCDirectorProjection2D);

    director->setAnimationInterval(1.0f / 60.0f);

    if(!AppDelegate::isInstalled() || AppDelegate::lastVersion() != Options::VERSION)
    {
        AppDelegate::install(false); // NOT SOFT INSTALLATION
    }

    Options::init();

    Screen* pScene = SplashScreen::create();

    director->runWithScene(pScene);

    return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();

    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();

    if(Options::MUSIC_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    }
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    AppDelegate::mGameCenter->login();
    #endif
}

bool AppDelegate::isGetWindeScreen()
{
	return Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPAD_RETINA || Options::DEVICE_TYPE == Options::DEVICE_TYPE_WINDOWS;
}

void AppDelegate::clearCache()
{
	#if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
	CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    
    CCDirector::sharedDirector()->purgeCachedData();
    
    CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
	#endif
}

#endif