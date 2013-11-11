#ifndef CONST_PROGRESSES_H
#define CONST_PROGRESSES_H

#include "Game.h"
#include "End.h"

#include "Pause.h"

#include "AppDelegate.h"

#include "Color.h"
#include "ColorParticle.h"

class TaskPanel;

class Progresses : public Game
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
    
        Text* mBestCountText;
        Text* mGoldLifesCount;
        Text* mTimeText;
        Text* mStarTimeText;
        Text* mTaskText[5];
        Text* mAwesomeText;
    
        EntityManager* mColorsSmall;
        EntityManager* mTasksBackground;
    
        float mNewColorsTime;
        float mNewColorsTimeElapsed;
    
        float mAwesoneAnimationTimeElapsed;
    
        bool mAwesoneAnimation;
    
        TaskPanel* mTaskPanel;
    
        // ===========================================================
        // Constructors
        // ===========================================================
    
        Progresses();

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
    
        static int TASK[80][10];

        // ===========================================================
        // Fields
        // ===========================================================
    
        static Progresses* create();
    
        ~Progresses();
    
        EntityManager* mColorsParticles;
        EntityManager* mColorEffectClearHorizontal;
        EntityManager* mColorEffectClearVertical;

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================
    
        void onShow();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void draw();

        void onEnter();
        void onExit();

        void onGameStarted();
        void onGameEnd();

        void onBirBlow(int pType, float pX, float pY, bool pBonus);
    
        void onTaskComplete();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        void removeLife();
    
        void onBonus(int pId, float pX, float pY);
    
        void onMatch(int count, float a, float b);
    
        void startGame();
};

#endif