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
    
    int loadingTextureNumber = -1;

    this->mTexturesLibrary[++loadingTextureNumber] = "main_menu_bg@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "main_menu_bg_back@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "main_menu_btn_shop@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "play_btn_animation@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "main_menu_btn_bg_play@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "btn_sprite@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "settings_bg@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "settings_btn_big@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "btn_mfx_sprite@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "choose_box_name@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "shop_money_bg@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "shop_wheel@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "shop_shelf_sprite@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "shop_item_icon_test@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "choose_box_navi_sprite@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "choose_box_lvl_sprite@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "game_gui_bg_summer@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "game_gui_btn_sprite@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "end_lvl_bg_popup@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "end_lvl_bg_sprite@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "end_lvl_btn_sprite@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "popup_bg@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "popup_darkness@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "popup_btn@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "popup_getcoins_picture@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "get_coins_light@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "end_lvl_star_sprite@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "confety_sprite@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "flag_sprite_small@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "flag_sprite_big@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "settings_lang_check@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "about_scroll_border@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "about_scroll_fill@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "popup_quit_picture@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "popup_quit_picture_light_main@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "popup_quit_picture_light_2@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "popup_rate_picture@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "about_scroll_border_small@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "about_scroll_fill_small@2x.png";
    this->mTexturesLibrary[++loadingTextureNumber] = "popup_progress_picture@2x.png";
    
    this->mLoadingText = new Text(Options::TEXT_LOADING_1, this);
    this->mLoadingText->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(160), Utils::coord(50)));
    
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
	
	this->mLoadingText->setString((Options::TEXT_LOADING_2.string + Utils::intToString(percent) + "%").c_str());
    
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
// Override Methods
// ===========================================================

#endif