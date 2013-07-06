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
    this->mTexturesLibrary[5] = "btn_sprite@2x.png";
    this->mTexturesLibrary[6] = "settings_bg@2x.png";
    this->mTexturesLibrary[7] = "settings_btn_big@2x.png";
    this->mTexturesLibrary[8] = "btn_mfx_sprite@2x.png";
    this->mTexturesLibrary[9] = "choose_box_name@2x.png";
    this->mTexturesLibrary[10] = "shop_money_bg@2x.png";
    this->mTexturesLibrary[11] = "shop_wheel@2x.png";
    this->mTexturesLibrary[12] = "shop_shelf_sprite@2x.png";
    this->mTexturesLibrary[13] = "shop_item_icon_test@2x.png";
    this->mTexturesLibrary[14] = "choose_box_navi_sprite@2x.png";
    this->mTexturesLibrary[15] = "choose_box_summer@2x.png";
    this->mTexturesLibrary[16] = "choose_box_winter@2x.png";
    this->mTexturesLibrary[17] = "choose_box_space@2x.png";
    this->mTexturesLibrary[18] = "choose_box_lvl_sprite@2x.png";
    
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
        
		AppDelegate::screens->set(1.0f, Screen::SCREEN_MENU);
	}
	else
	{
        
	}
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif