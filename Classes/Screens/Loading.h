#ifndef CONST_LOADING_H
#define CONST_LOADING_H

#include "cocos2d.h"

#include "Screen.h"

#include "AppDelegate.h"
#include "ScreenManager.h"

using namespace cocos2d;

class Loading : public Screen
{
	protected:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================
    
        static const int TEXTURES_COUNT = 24;

		// ===========================================================
		// Fields
        // ===========================================================
    
        int mNumberOfSprites;
        int mNumberOfLoadedSprites;
    
        CCLabelTTF* mLoadingText;
    
        const char* mTexturesLibrary[TEXTURES_COUNT];

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
        // ===========================================================
    
        void loadingCallBack(CCObject *obj);

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
    
        Loading();

		// ===========================================================
		// Methods
		// ===========================================================
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
};

#endif