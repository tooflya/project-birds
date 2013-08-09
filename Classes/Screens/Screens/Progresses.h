#ifndef CONST_PROGRESSES_H
#define CONST_PROGRESSES_H

#include "Game.h"
#include "ProgressPause.h"
#include "ProgressEnd.h"

#include "Pause.h"

#include "AppDelegate.h"

#include "Color.h"

class Progresses : public Game
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static Progresses* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================

        BatchEntityManager* mColors;
    
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

        static int TASK[10][50];

        // ===========================================================
        // Fields
        // ===========================================================
    
        Progresses();

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);

        void onEnter();
        void onExit();

        void onGameStarted();
        void onGameEnd();

        void onBirBlow(int pType);
};

#endif