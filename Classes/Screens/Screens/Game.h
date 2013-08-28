#ifndef CONST_GAME_H
#define CONST_GAME_H

#include "Screen.h"

#include "End.h"

#include "Bird.h"
#include "SpecialBird.h"
#include "Mark.h"
#include "Feather.h"
#include "Explosion.h"
#include "ExplosionBasic.h"
#include "StarParticle.h"
#include "Dust.h"
#include "EventPanel.h"

#include "Pause.h"

#include "TouchTrailLayer.h"

#include "AppDelegate.h"

class Game : public Screen
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
    
        int mBirdsRemaning;
        int mStartGameAnimationIndex;

        int mAlgorithmBirdsRemainig;
    
        int mCoinsBirdsCount;

        float mBirdsTime;
        float mBirdsTimeElapsed;

        float mStartGameAnimation;
        float mStartGameAnimationElapsed;

        float mAlgorithmBirdsTime;

        float mAlgorithmBirdsTime1;
        float mAlgorithmBirdsTime2;
    
        float mSpecialBirdsTime;
        float mSpecialBirdsTimeElapsed;
    
        float mCoinsBirdTime;
        float mCoinsBirdTimeElapsed;

        Entity* mBackground;
        Entity* mCountIcon;

        EventPanel* mEventPanel;

        Button* mPauseButton;

        Text* mGameStartText;

        Popup* mPausePopup;

        End* mEndScreen;

        CCLayer* mEventLayer;
    
        // ===========================================================
        // Constructors
        // ===========================================================
    
        Game();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void generateCoinsBirds();

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

        static int CURRENT_COUNT;
        static int BEST_COUNT;
        static int LIFES;
        static int HEALTH;
        static int RECORD_BEATEAN;

        // ===========================================================
        // Fields
        // ===========================================================

        bool mChalange;
    
        bool mGameRunning;
        bool mGamePaused;
    
        bool mPause;

        EntityManager* mBirds;
        EntityManager* mSpecialBirds;
        EntityManager* mMarks;
        EntityManager* mFeathers;
        EntityManager* mExplosionsBasic;
        EntityManager* mExplosions;
        EntityManager* mDust;
        EntityManager* mStars;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Game* create();
    
        ~Game();

        // ===========================================================
        // Methods
        // ===========================================================

        virtual void startGame();
        virtual void onGameStarted();
        virtual void onGameEnd();
        virtual void removeLife();
        virtual void onBirBlow(int pType);
        virtual void pause();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
        
        void onEnter();
        void onExit();
};

#endif