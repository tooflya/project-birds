#ifndef CONST_SCREEN_H
#define CONST_SCREEN_H

#include "cocos2d.h"

#include "Touchable.h"

#include "Entity.h"
#include "Button.h"

#include "EntityManager.h"
#include "BatchEntityManager.h"

#include "Utils.h"
#include "Options.h"

#include "AppDelegate.h"

using namespace cocos2d;

class Screen : public CCScene, public Touchable
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
        
        bool containsTouchLocation(CCTouch* touch);

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
    
        static const int SCREEN_MENU = 0;
        static const int SCREEN_SETTINGS = 1;
        static const int SCREEN_SHOP = 2;
        static const int SCREEN_MODE = 3;
        static const int SCREEN_LEVELS = 4;
        static const int SCREEN_CREDITS = 5;
        static const int SCREEN_LOADER = 6;
        static const int SCREEN_PROGRESS = 7;
        static const int SCREEN_LANGUAGE = 8;
        static const int SCREEN_CLASSIC_GAME = 9;
        static const int SCREEN_ARCADE_GAME = 10;
        static const int SCREEN_PROGRESS_GAME = 11;

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================

        Screen();

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        virtual void onEnter();
        virtual void onExit();
};

#endif