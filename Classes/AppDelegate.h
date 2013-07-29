#ifndef CONST_APPDELEGATE_H
#define CONST_APPDELEGATE_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include <vector>

#include "Options.h"
#include "ScreenManager.h"

using namespace std;
using namespace cocos2d;
using namespace CocosDenshion;

class ScreenManager;

typedef struct tagResource {
    CCSize size;
    char directory[100];
} Resource;

static Resource resources480x320 = { CCSizeMake(320, 480),  "Graphics/480x320" };
static Resource resources1280x720 = { CCSizeMake(720, 1280),  "Graphics/1280x720" };
static CCSize designResolutionSize = CCSizeMake(720, 1280);

class AppDelegate : private CCApplication
{
    protected:
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

    private:
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

    public:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static ScreenManager* screens;

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================

        static void addCoins(int pCount, int pType);
        static void removeCoins(int pCount, int pType);

        static int getCoins(int pType);

        static void changeLanguage(int pId);
        static int getSelectedLanguage();

        static bool isInstalled();
        static void install();

        static bool isItemBought(int pItem);
        static void buyItem(int pItem);

        static bool isItemSelected(int pItem);
        static void selectItem(int pItem);

        static int getLevelStars(int pLevel);
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        bool applicationDidFinishLaunching();

        void applicationDidEnterBackground();
        void applicationWillEnterForeground();
};

#endif