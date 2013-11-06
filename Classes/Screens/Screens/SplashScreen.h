#ifndef CONST_SPLASHSCREEN2_H
#define CONST_SPLASHSCREEN2_H

#include "Screen.h"

#include "AppDelegate.h"

class SplashScreen : public Screen
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
    
        int mAnimationCounter;
    
        bool mAnimation;
    
        float mAnimationTime;
        float mAnimationTimeElapsed;
    
        Entity* mLogos[2];
    
        Screen* mNextScreen;
    
        // ===========================================================
        // Constructors
        // ===========================================================
    
        SplashScreen();

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

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static SplashScreen* create();
    
        ~SplashScreen();

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void onEnter();
        void onExit();
    
        void update(float pDeltaTime);
};

#endif