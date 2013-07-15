#ifndef CONST_POPUP_H
#define CONST_POPUP_H

#include "cocos2d.h"

#include "Screen.h"

#include "Entity.h"
#include "Button.h"

#include "Utils.h"
#include "Options.h"

#include "BatchEntityManager.h"

using namespace cocos2d;

class Popup : public CCLayer
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

        Entity* mBackground;
        Entity* mDarkness;
        Entity* mIllustration;
    
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
    
        Popup(CCNode* pParent);

        // ===========================================================
        // Methods
        // ===========================================================
    
        void show();
        void hide();

        bool isShowed();
    
        virtual void onShow();
        virtual void onHide();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void onEnter();
        void onExit();
    
        bool ccTouchBegan(CCTouch* touch, CCEvent* event);
};

#endif