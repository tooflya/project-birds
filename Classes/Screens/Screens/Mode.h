#ifndef CONST_MODE_H
#define CONST_MODE_H

#include "Screen.h"

#include "ModeHelp.h"
#include "Episodes.h"
#include "UnlockMode.h"
#include "TempPublisherRatingExplain.h"
#include "TempPublisherAchievementsExplain.h"

#include "AppDelegate.h"

class Mode : public Screen
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
    
        int mPanelItems[4];
    
        float mUnlockAnimationTimeElapsed;
    
        bool mUnlockAnimationRunning;
    
        Entity* mGamePanel;
        Entity* mBackground;
        Entity* mBackgroundDecorations[2];
        Entity* mLockes[2];
        Entity* mUnlockStripe;
        Entity* mTextBackgrounds[4];
        Entity* mIcons[4];
        Button* mTextPluses[4];

        Button* mBackButton;
        Button* mHelpButton;
        Button* mClassicMode;
        Button* mArcadeMode;
        Button* mProgressMode;
        Button* mAchievementsButton;
        Button* mLeaderboardButton;
        Button* mShopButton;

        Popup* mHelpPopup;
        Popup* mLivesPopup;
        Popup* mModesUnlockPopup;
        Popup* mTempPublisherRatingExplain;
        Popup* mTempPublisherAchievementsExplain;
    
        Episodes* mEpisodesMap;
    
        Text* mTextText[4];

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Mode();

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
    
        static int UNLOCK_ACTION;
    
        static int PRICES[2];

        // ===========================================================
        // Fields
        // ===========================================================
    
        static Mode* create();
    
        ~Mode();

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================
    
        void unlock();
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        void update(float pDeltaTime);
    
        void onEnter();
    
        void keyBackClicked(bool pSound);
};

#endif