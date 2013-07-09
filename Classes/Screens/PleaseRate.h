#ifndef CONST_PLEASERATE_H
#define CONST_PLEASERATE_H

#include "cocos2d.h"

#include "Popup.h"
#include "Text.h"

using namespace cocos2d;

class PleaseRate : public Popup
{
	protected:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
        // ===========================================================
    
        static PleaseRate* m_Instance;

		// ===========================================================
		// Fields
		// ===========================================================
    
        Button* mRateButton;

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
    
        PleaseRate(Screen* pScreen);

		// ===========================================================
		// Methods
		// ===========================================================
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================
};

#endif