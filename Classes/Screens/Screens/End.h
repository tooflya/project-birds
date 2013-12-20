#ifndef CONST_END_H
#define CONST_END_H

#include "Screen.h"
#include "Splash.h"
#include "Star.h"
#include "Confetti.h"
#include "AnimatedCoin.h"
#include "BatchEntityManager.h"

#include "AppDelegate.h"

class End : public Splash
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
    
        CCLayer* mPanelLayer;

        Button* mShopButton;
        Button* mMenuButton;
        Button* mRestartButton;
        Button* mContinueButton;
    
        EntityManager* mStars;
        EntityManager* mStarsSplashes;
        EntityManager* mConfetti;
        EntityManager* mStarsParticles;
    
        Text* mTextLevel;
        Text* mTextName;
        Text* mTextValue;
        Text* mTextCountValue;
    
        Entity* mGamePanel;
        Entity* mBackground;
        Entity* mIcons[4];
        Entity* mTextBackgrounds[4];
        Entity* mPrize;
    
        SpriteBatch* mSpriteBatch7;
    
        Text* mTextText[4];
    
        Button* mTextPluses[4];
    
        int mAnimationCounter;
        int mCoinsAnimationCounter;
    
        int mCurrentCount;
        int mBestCurrentCount;
        int mFlayerCount;
        int mComboCount;
        int mCriticalCount;
        int mEarnedCoins;
        int mTotalEarnedCoinsSilver;
        int mTotalEarnedCoinsGold;
        int mStarsCount;
    
        float mAnimationTime;
        float mAnimationtimeElapsed;
    
        float mCoinsAnimationTime;
        float mCoinsAnimationTimeElapsed;
    
        float mCoinsAnimationCurrentTime;
        float mCoinsAnimationCurrentTimeElapsed;
    
        bool mIsAnimationRunning;
        bool mIsCoinsAnimationRunning;
        bool mIsCoinsAnimationCurrentRunning;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        End(int pType, Screen* pParent);

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
    
        static int ACTION;

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static End* create(int pType, Screen* pParent);
        ~End();

        // ===========================================================
        // Methods
        // ===========================================================

        void onShow();
        void onHide();

        void onStartShow();
        void onStartHide();

        void throwConfetti();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void onTouchButtonsCallback(const int pAction, const int pID);
};

#endif