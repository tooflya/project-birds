#ifndef CONST_LEVELS_H
#define CONST_LEVELS_H

#include "Screen.h"

#include "GetLives.h"
#include "UnlockLevel.h"
#include "SurpriseLevel.h"

class MainList;
class UnlockPanel;

class Levels : public Screen
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
    
        bool mIsUnlockAnimationRunning;
        bool mIsUnlockAnimationSound;
    
        float mUnlockAnimationTime;
        float mUnlockAnimationTimeElapsed;
    
        Entity* mBackground;
        Entity* mTablet;
        Entity* mLigts[2];
        Entity* mStarsCountIcon;
        Button* mBackButton;
        Button* mShopButton;

        Text* mStarsCountText;

        MainList* mMainList;
    
        CCSpriteBatchNode* spriteBatch2;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Levels();

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

        static const int LEVEL_PACKS_COUNT = 5;
    
        static bool SHOULD_START_AFTER_UNLOCK;
    
        static int PRICES[80];
        static int PRIZES[80];
        static int STARS[5];

        // ===========================================================
        // Fields
        // ===========================================================
    
        UnlockPanel* mUnlockPanel;

        Entity* mSlides[6];
        Entity* mSlidesArrows[2];
        Entity* mBackgroundDecorations[4];
    
        Popup* mGetLivesPopup;
        Popup* mUnlockLevelPopup;
        Popup* mSurpriseLevelPopup;
    
        CCNodeRGBA* mDarkness;
    
        Entity* mLevels[80]; // TODO: return 6.
    
        Text* tt[5];

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Levels* create();

        ~Levels();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void updateIcons();
        void unlock();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void onEnter();
        void onExit();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        void keyBackClicked(bool pSound);
};

#endif