#ifndef CONST_PLAYBUTTON
#define CONST_PLAYBUTTON

#include "PlayButton.h"

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

PlayButton::PlayButton(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int)) :
	Button(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount, pParent, pButtonID, pOnTouchCallback)
	{
	}

PlayButton* PlayButton::create(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int))
{
    PlayButton* button = new PlayButton(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount, pParent, pButtonID, pOnTouchCallback);
    button->autorelease();
    
    return button;
}

// ===========================================================
// Methods
// ===========================================================

void PlayButton::onCreate()
{
	Button::onCreate();

    this->mAnimationTime = Utils::randomf(1.5, 5.0);
    this->mAnimationTimeElapsed = 0;
}

// ===========================================================
// Override Methods
// ===========================================================

void PlayButton::update(float pDeltaTime)
{
	Button::update(pDeltaTime);
  
    this->mAnimationTimeElapsed += pDeltaTime;
        
    if(this->mAnimationTimeElapsed >= this->mAnimationTime)
    {
        this->mAnimationTime = Utils::randomf(1.5, 5.0);
        this->mAnimationTimeElapsed = 0;
            
        this->animate(0.08, 1);
    }
}

#endif