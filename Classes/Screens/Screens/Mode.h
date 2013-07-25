#ifndef CONST_MODE_H
#define CONST_MODE_H

#include "Screen.h"

#include "ModeHelp.h"

#include "AppDelegate.h"

class Mode : public Screen
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static Mode* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================
    
        Entity* mBackground;

        Button* mBackButton;
        Button* mHelpButton;
        Button* mClassicMode;
        Button* mArcadeMode;
        Button* mProgressMode;
        Button* mAchievementsButton;
        Button* mLeaderboardButton;

        ModeHelp* mHelpPopup;

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

        // ===========================================================
        // Fields
        // ===========================================================
    
        Mode();

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================
};

#endif