#ifndef CONST_EPISODES_H
#define CONST_EPISODES_H

#include "cocos2d.h"

#include "Screen.h"

#include "Entity.h"
#include "Button.h"
#include "Ripple.h"
#include "Confetti.h"
#include "AnimatedCoin.h"
#include "StarParticle2.h"

#include "Utils.h"
#include "Options.h"

#include "BatchEntityManager.h"

using namespace cocos2d;

class BackgroundEntity2;

class Episodes : public CCLayer, public Touchable, public ButtonReceiver
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
    
        CCNode* mParent;
        Entity* mDarkness;
        Entity* mScroll;
        BackgroundEntity2* mBackground;
		CCNodeRGBA* mSquare;

        float mShowAnimationTime;
        float mShowAnimationTimeElapsed;
        
        float mHideAnimationTime;
        float mHideAnimationTimeElapsed;
    
        bool mShowAnimationRunning;
        bool mHideAnimationRunning;
    
        float mAnimatedCoinsAnimationTime;
        float mAnimatedCoinsAnimationTimeElpased;
    
        bool mShowed;
    
        Entity* mPointLight;
        Entity* mLocks[5];
        Entity* mPoints[5];
        Entity* mWays[15];
    
        Text* mTextes[5];

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Episodes(CCNode* pParent);

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
    
        static Episodes* create(CCNode* pParent);
    
        ~Episodes();

        // ===========================================================
        // Methods
        // ===========================================================
    
        virtual void show();
        virtual void hide();
    
        bool isShowed();
    
        virtual void onShow();
        virtual void onHide();
    
        void onAnimationEnd();
    
        void fastHide();
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void draw();
    
        void onEnter();
        void onExit();
    
		bool ccTouchBegan(CCTouch* touch, CCEvent* event);
    
		void onTouchButtonsCallback(const int pAction, const int pID);
};

#endif