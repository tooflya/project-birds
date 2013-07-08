#ifndef CONST_MENU_H
#define CONST_MENU_H

#include "cocos2d.h"

#include "Screen.h"

#include "AppDelegate.h"

#include "PlayButton.h"

using namespace cocos2d;

class Menu : public Screen
{
	protected:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

        static Menu* m_Instance;

		// ===========================================================
		// Fields
		// ===========================================================
    
        Entity* mBackground;
        Entity* mBackgroundDecoration;
        Entity* mPlayDecoration;
        Entity* mPlayButton;
        Entity* mShopButton;
        Entity* mTwitterButton;
        Entity* mFacebookButton;
        Entity* mSettingsButton;

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
		// ===========================================================

		// ===========================================================
		// Virtual Methods
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
		// Virtual Methods
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
    
        Menu();

		// ===========================================================
		// Methods
		// ===========================================================
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
    
        void update(float pDeltaTime);
};

#endif