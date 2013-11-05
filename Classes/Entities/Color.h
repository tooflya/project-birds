#ifndef CONST_COLOR_H
#define CONST_COLOR_H

#include "Entity.h"

#include "Text.h"

class Color : public Entity
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
    
        int position;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Color();

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
    
        static int SOUND_INDEX;
    
        static bool ANIMATION_RUNNING;

        // ===========================================================
        // Fields
        // ===========================================================
    
        int mType;
    
        bool mGoingToDestroy;
        bool d;
    
        float mDestroyTime;
        float mDestroyTimeElapsed;
    
        int position_in_matrtix_x;
        int position_in_matrtix_y;
    
        int mPower;
    
        bool mc;
    
        float mct;
        float mcte;
    
        float mBlinkTime;
        float mBlinkTimeElapsed;
    
        bool mBlinking;
    
        Entity* mBlink;
    
        Text* mPowerText;

        // ===========================================================
        // Constructors
        // ===========================================================

        static Color* create();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void setCenterPositionWithCorrection(float pCenterX, float pCenterY);
    
        void runDestroy();
    
		void down();
    
        // ===========================================================
        // Override Methods
        // ===========================================================

        void onCreate();
        void onDestroy();
    
        void update(float pDeltaTime);
    
        Color* deepCopy();
};

#endif