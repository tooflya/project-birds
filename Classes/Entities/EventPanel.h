#ifndef CONST_EVENTPANEL_H
#define CONST_EVENTPANEL_H

#include "Screen.h"

class EventPanel : public Entity
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

        float mShowAnimationTime;
        float mHideAnimationTime;

        float mShowAnimationTimeElapsed;
        float mHideAnimationTimeElapsed;

        float mLiveTime;
        float mLiveTimeElapsed;

        bool mShowed;

        bool mIsShowAnimationRunning;
        bool mIsHideAnimationRunning;

        bool mLive;

        Entity* mIcon;

        Screen* mParent;

        Text* mText;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        EventPanel(Screen* pParent);

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

        static EventPanel* create(Screen* pParent);

        // ===========================================================
        // Methods
        // ===========================================================

        void show();
        void hide();

        void onShow();
        void onHide();

        EventPanel* setEvent(int pEvent);
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        void update(float pDeltaTime);
};

#endif