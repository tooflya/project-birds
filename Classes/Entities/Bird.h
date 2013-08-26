#ifndef CONST_BIRD_H
#define CONST_BIRD_H

#include "ImpulseEntity.h"

class Bird : public ImpulseEntity
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

        int mType;
        int mSoundEffect;
        
        int mDestroyAnimationFrames;

        float mLifeCount;
        float mInitLifeCount;

        float mMarkTime;
        float mMarkTimeElapsed;

        float mDestroyAnimationTime;
        float mDestroyAnimationTimeElapsed;

        bool mIsGoingToDestroy;
        bool mSpecialAnimation;
        bool mChalange;
        bool mSpecial;
        bool mBonus;

        CCProgressTimer* mLife;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Bird();
        Bird(bool pSpecial);

        // ===========================================================
        // Methods
        // ===========================================================

        // ===========================================================
        // Virtual Methods
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
        // Virtual Methods
        // ===========================================================

    public:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static const int COUNT = 8;
        static const int SPECIAL_COUNT = 9;

        static const int TYPE_ORANGE = 0;
        static const int TYPE_RED = 1;
        static const int TYPE_PURPLE = 2;
        static const int TYPE_BLUE = 3;
        static const int TYPE_CYAN = 4;
        static const int TYPE_YELLOW = 5;
        static const int TYPE_GREEN = 6;
        static const int TYPE_DANGER = 7;
        static const int TYPE_GENERAL = 8;
        static const int TYPE_FREEZEE = 9;
        static const int TYPE_ZOMBIE = 10;
        static const int TYPE_INDIE = 11;
        static const int TYPE_ROBOTO = 12;
        static const int TYPE_MEXICAN = 13;
        static const int TYPE_PIRATE = 14;
        static const int TYPE_FLAYER = 15;
        static const int TYPE_NINJA = 16;

        static ccColor3B COLORS[COUNT];

        // ===========================================================
        // Fields
        // ===========================================================
    
        int count;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Bird* create();
        static Bird* create(bool pSpecial);
    
        ~Bird();

        // ===========================================================
        // Methods
        // ===========================================================

        int getType();
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        void onAnimationEnd();
    
        void onCreate();
        void onDestroy();
    
        void update(float pDelta);

        Bird* deepCopy();
};

#endif