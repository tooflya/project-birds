#ifndef CONST_LOADING
#define CONST_LOADING

#include "Loading.h"

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

Loading::Loading()
{
	this->mNumberOfLoadedSprites = 0;
	this->mNumberOfSprites = TEXTURES_COUNT;
    
    this->mTexturesLibrary[0] = "main_menu_bg@2x.png";
    this->mTexturesLibrary[1] = "main_menu_bg_back@2x.png";
    this->mTexturesLibrary[2] = "main_menu_btn_shop@2x.png";
    this->mTexturesLibrary[3] = "main_menu_btn_play@2x.png";
    this->mTexturesLibrary[4] = "main_menu_btn_bg_play@2x.png";
    
    this->mLoadingText = CCLabelTTF::create("Loading... 0%", "Apple Casual", Utils::coord(32));
    this->mLoadingText->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(140), Utils::coord(50)));
    
    this->addChild(this->mLoadingText);
    
    for(int i = 0; i < TEXTURES_COUNT; i++)
    {
        CCTextureCache::sharedTextureCache()->addImageAsync(this->mTexturesLibrary[i], this, callfuncO_selector(Loading::loadingCallBack));
    }
}

// ===========================================================
// Methods
// ===========================================================

void Loading::loadingCallBack(CCObject *obj)
{
	++this->mNumberOfLoadedSprites;
	
	int percent = (int) (((float) mNumberOfLoadedSprites / mNumberOfSprites) * 100);
	
	this->mLoadingText->setString(("Loading... " + Utils::intToString(percent) + "%").c_str());
    
	if(mNumberOfLoadedSprites == mNumberOfSprites)
	{
		AppDelegate::screens = new ScreenManager();
        
		AppDelegate::screens->set(1.0f, 0);
	}
	else
	{
        
	}
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif