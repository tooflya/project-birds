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
    this->mTexturesLibrary[3] = "play_btn_animation@2x.png";
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
    this->mTexturesLibrary[19] = "game_gui_bg_summer@2x.png";
    this->mTexturesLibrary[20] = "game_gui_btn_sprite@2x.png";
    this->mTexturesLibrary[21] = "end_lvl_bg_popup@2x.png";
    this->mTexturesLibrary[22] = "end_lvl_bg_sprite@2x.png";
    this->mTexturesLibrary[23] = "end_lvl_btn_sprite@2x.png";
    this->mTexturesLibrary[24] = "popup_bg@2x.png";
    this->mTexturesLibrary[25] = "popup_darkness@2x.png";
    this->mTexturesLibrary[26] = "popup_btn@2x.png";
    this->mTexturesLibrary[27] = "popup_getcoins_picture@2x.png";
    this->mTexturesLibrary[28] = "get_coins_light@2x.png";
    this->mTexturesLibrary[29] = "choose_box_locked@2x.png";
    this->mTexturesLibrary[30] = "end_lvl_star_sprite@2x.png";
    this->mTexturesLibrary[31] = "confety_sprite@2x.png";
    this->mTexturesLibrary[32] = "flag_sprite_small@2x.png";
    this->mTexturesLibrary[33] = "flag_sprite_big@2x.png";
    this->mTexturesLibrary[34] = "settings_lang_check@2x.png";
    this->mTexturesLibrary[35] = "about_scroll_border@2x.png";
    this->mTexturesLibrary[36] = "about_scroll_fill@2x.png";
    this->mTexturesLibrary[37] = "popup_quit_picture@2x.png";
    this->mTexturesLibrary[38] = "popup_quit_picture_light_main@2x.png";
    this->mTexturesLibrary[39] = "popup_quit_picture_light_2@2x.png";
    this->mTexturesLibrary[40] = "popup_rate_picture@2x.png";
    this->mTexturesLibrary[41] = "about_scroll_border_small@2x.png";
    this->mTexturesLibrary[42] = "about_scroll_fill_small@2x.png";
    this->mTexturesLibrary[43] = "popup_progress_picture@2x.png";
    
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
// Virtual Methods
// ===========================================================

#endif