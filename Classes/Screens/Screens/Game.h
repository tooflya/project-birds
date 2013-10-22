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
#include "AnimatedCoin.h"
#include "Rain.h"
#include "RainCircle.h"
#include "RobotoPart.h"
#include "RobotoGun.h"
#include "PirateBox.h"
#include "ZombieExplosion.h"
#include "GeneralExplosion.h"
#include "Color.h"
#include "KeyDisplay.h"

#include "Pause.h"
#include "GetLives.h"

#include "TouchTrailLayer.h"

#include "AppDelegate.h"

class Game : public Screen
{
    protected:
        // ===========================================================
        // Inner Classes
    // ===========================================================
    
    class Effect : public CCNodeRGBA
    {
    public:
        Effect()
        {
            this->setColor(ccc3(0, 0, 0));
            this->setOpacity(0);
        }
        
        static Effect* create()
        {
            Effect* background = new Effect();
            background->autorelease();
            
            return background;
        }
        
        void draw()
        {
            if(this->getOpacity() <= 0) return;
            
			#if CC_TARGET_PLATFORM != CC_PLATFORM_WINRT
            glLineWidth(1);
			#endif
            CCPoint filledVertices[] = { ccp(0,0), ccp(0,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH, 0)};
            ccDrawSolidPoly(filledVertices, 4, ccc4f(this->getColor().r, this->getColor().g, this->getColor().b, this->getOpacity() / 255.0) );
        }
    };

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
    
        int mLastKillType;
        int mLastKillCount;

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
    
        float mBonusAnimationTime;
        float mBonusAnimationTimeElapsed;
    
        float mBonusAnimationFrameTime;
        float mBonusAnimationFrameTimeElapsed;
    
        bool mBonusSomeTimeUpdate;
        int mBonusSomeTimeUpdateCount;
        float mBonusSomeTime;
        float mBonusSomeTimeElapsed;
    
        int mGunLaserFrame;
    
        float mGunLaserFrameTime;
        float mGunLaserFrameTimeElapsed;
    
        bool mZombieAnimation;
    
        float mZombieAnimationTime;
        float mZombieAnimationTimeElapsed;
    
        float mZombieAnimationX;
        float mZombieAnimationY;
    
        int mZombieAnimationCount;
    
        long mLastKillTime;
        int mIsBonusAnimationRunningCount;
    
        bool mBackgroundLightsAnimationsReverse[7];
        bool mIsBonusAnimationRunning;
        bool mPirateBoxAnimation;
    
        float mPirateBoxAnimationTime;
        float mPirateBoxAnimationTimeElapsed;
    
        CCLayer* mMenuLayer;
        CCLayer* mGameLayer;

        Entity* mBackground;
        Entity* mGamePanel;
        Entity* mTextAreas[4];
        Entity* mTextIcons[4];
        Entity* mHearts[4];
        Button* mGoldLifeButton;
        Entity* e3[4];
        Entity* e4[8];
    
        PirateBox* mPirateBox;
    
        Entity* mBackgroundLights[8];
        EntityManager* mBonusCircles;

        EventPanel* mEventPanel;

        Button* mPauseButton;

        Text* mGameStartText;

        Popup* mPausePopup;
        Popup* mGetLivesPopup;

        End* mEndScreen;

        CCLayer* mEventLayer;
    
        CCNodeRGBA* e2;
    
    
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
    
        static int** MATRIX;
    
        static int MATRIX_SIZE_X;
        static int MATRIX_SIZE_Y;
    
        static float TIME_SLOW;
        static bool PREDICTION;
        static bool LASERGUN;
        static bool ZOMBIE_AREA;

        static int CURRENT_COUNT;
        static int BEST_COUNT;
        static int LIFES;
        static int HEALTH;
        static int RECORD_BEATEAN;
        static int COMBO_COUNT;
        static int FLAYER_COUNT;
        static int CRITICAL_COUNT;
    
        static int STARS;

        // ===========================================================
        // Fields
        // ===========================================================

        bool mChalange;
        bool mTaskDone;
    
        bool mGameRunning;
        bool mGamePaused;
    
        bool mPause;
    
        int mRunningBonusId;
    
        float mTime;
        float mStarTime;

        EntityManager* mBirds;
        EntityManager* mSpecialBirds;
        EntityManager* mMarks;
        EntityManager* mFeathers;
        EntityManager* mExplosionsBasic;
        EntityManager* mExplosions;
        EntityManager* mZombieExplosions;
        EntityManager* mGeneralExplosions;
        EntityManager* mDust;
        EntityManager* mStars;
        EntityManager* mCoins;
        EntityManager* mSilverCoins;
        EntityManager* mArrows;
        EntityManager* mPredictionIcons;
        EntityManager* mSchematicBig;
        EntityManager* mSchematicSmall;
        EntityManager* mColorsBlink;
        EntityManager* mKeys;
        EntityManager* mKeysLights;
    
        EntityManager* mColors;
    
        Entity* e1;
        EntityManager* mRains;
        EntityManager* mRainsCircles;
        EntityManager* mRobotParts;
        RobotoGun* mGun;
        Entity* mGunLaser;
    
        CCArray* array;
        static int BURNED[10];
    
        static int LEVEL;
        static int LEVEL_TYPE[80];
        static int LEVEL_HEIGHT[80];
        static int LEVEL_COLORS[80];
        static int LEVEL_HEALTH[80];
    
        static int GAME_TYPE;
    
        static const int GAME_TYPE_CLASSIC = 0;
        static const int GAME_TYPE_ARCADE = 1;
        static const int GAME_TYPE_PROGRESS = 2;
    
        SpriteBatch* spriteBatch99;

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
        virtual void onBirBlow(int pType, float pX, float pY);
        virtual void pause();
        virtual void onBonus(int pId, float pX, float pY);
        void startBoxAnimation();
        void stopBoxAnimation();
    
        bool deepFind(int x, int y, int index, bool recursive);
    
        void addTime(float pTime);
    
        void onTaskComplete();
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
        
        void onEnter();
        void onExit();
};

#endif