#ifndef CONST_LOADER_H
#define CONST_LOADER_H

#include "cocos2d.h"

#include "Screen.h"

#include "AppDelegate.h"
#include "ScreenManager.h"

using namespace cocos2d;

class Loader : public Screen
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
    
        float mLoadingTime;
    
        int mLoadingPercentrage;
    
        CCLabelTTF* mLoadingText;

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
    
        Loader();

		// ===========================================================
		// Methods
		// ===========================================================
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
    
        void update(float pDeltaTime);
    
        void onEnter();
};

#endif