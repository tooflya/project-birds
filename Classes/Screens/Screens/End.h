#ifndef CONST_END_H
#define CONST_END_H

#include "Screen.h"
#include "Splash.h"
#include "Star.h"
#include "Confetti.h"
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

        Button* mShopButton;
        Button* mMenuButton;
        Button* mRestartButton;
        Button* mContinueButton;
    
        BatchEntityManager* mStars;
        BatchEntityManager* mConfetti;
    
        int mAnimationCounter;
    
        float mAnimationTime;
        float mAnimationtimeElapsed;
    
        bool mIsAnimationRunning;

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

        void (*mOnTouchCallback)(int, int);

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

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        End(int pType, Screen* pParent, void (*pOnTouchCallback)(int, int));

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
};

#endif