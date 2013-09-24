#ifndef CONST_MAP_H
#define CONST_MAP_H

#include "cocos2d.h"

#include "Screen.h"

#include "Entity.h"
#include "Button.h"
#include "Ripple.h"

#include "Utils.h"
#include "Options.h"

#include "BatchEntityManager.h"

using namespace cocos2d;

class BackgroundEntity;

class Map : public CCLayer, public Touchable
{
        protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================
    
        static Map* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================
    
        CCNode* mParent;
        Entity* mDarkness;
        BackgroundEntity* mBackground;
    Entity* mScroll;
    CCNodeRGBA* mSquare;
    
    Entity* mName;
        Entity* mDay[5];
    EntityManager* mRipples;
    EntityManager* mWays;
    
        Button* mCloseButton;
    
        int mShowAnimationCount;
        int mHideAnimationCount;
    
        float mShowAnimationTime;
        float mShowAnimationTimeElapsed;
        
        float mHideAnimationTime;
        float mHideAnimationTimeElapsed;
    
        bool mShowAnimationRunning;
        bool mHideAnimationRunning;
    
        bool mShowed;
    
    bool mAnimation;
    
    float mAnimationTime;
    float mAnimationTimeElapsed;
    
    int mAnimationCount;
    int mAnimationCount2;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Map(CCNode* pParent);

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

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Map* create(CCNode* pParent);
    
        ~Map();

        // ===========================================================
        // Methods
        // ===========================================================
    
        virtual void show();
        virtual void hide();
    
        bool isShowed();
    
        virtual void onShow();
        virtual void onHide();
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void draw();
    
        void onEnter();
        void onExit();
    
        bool ccTouchBegan(CCTouch* touch, CCEvent* event);
};

#endif