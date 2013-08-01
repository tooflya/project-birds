#ifndef CONST_LEVELS_H
#define CONST_LEVELS_H

#include "Screen.h"

class MainList;

class Levels : public Screen
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static Levels* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================
    
        Entity* mBackground;
        Entity* mTablet;
        Entity* mStarsCountIcon;
        Button* mBackButton;
        Button* mShopButton;
    
        EntityManager* mLevels[5]; // TODO: return 6.

        Text* mStarsCountText;

        MainList* mMainList;

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

        static void onTouchButtonsCallback(const int pAction, const int pID);
        
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

        static const int LEVEL_PACKS_COUNT = 6;

        // ===========================================================
        // Fields
        // ===========================================================

        BatchEntityManager* mSlides;
        BatchEntityManager* mSlidesArrows;
    
        Entity* mBackgroundDecorations[5];

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
    
        void onEnter();
        void onExit();
};

#endif