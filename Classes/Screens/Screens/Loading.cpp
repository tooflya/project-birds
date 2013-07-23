#ifndef CONST_LOADING
#define CONST_LOADING

#include "Loading.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

const char* Loading::TEXTURE_LIBRARY[41] =
{
    "main_menu_bg@2x.png",
    "main_menu_bg_back@2x.png",
    "main_menu_btn_shop@2x.png",
    "play_btn_animation@2x.png",
    "main_menu_btn_bg_play@2x.png",
    "btn_sprite@2x.png",
    "settings_bg@2x.png",
    "settings_btn_big@2x.png",
    "btn_mfx_sprite@2x.png",
    "choose_box_name@2x.png",
    "shop_money_bg@2x.png",
    "shop_wheel@2x.png",
    "shop_shelf_sprite@2x.png",
    "shop_item_icon@2x.png",
    "choose_box_navi_sprite@2x.png",
    "choose_box_lvl_sprite@2x.png",
    "popup_bg@2x.png",
    "popup_darkness@2x.png",
    "popup_btn@2x.png",
    "popup_getcoins_picture@2x.png",
    "get_coins_light@2x.png",
    "end_lvl_star_sprite@2x.png",
    "flag_sprite_small@2x.png",
    "flag_sprite_big@2x.png",
    "settings_lang_check@2x.png",
    "about_scroll_border@2x.png",
    "about_scroll_fill@2x.png",
    "popup_quit_picture@2x.png",
    "popup_quit_picture_light_main@2x.png",
    "popup_quit_picture_light_2@2x.png",
    "popup_rate_picture@2x.png",
    "about_scroll_border_small@2x.png",
    "popup_progress_picture@2x.png",
    "about_scroll_fill_small@2x.png",
    "coins@2x.png",
    "popup_buy_coins_btn_sprite@2x.png",
    "preload-lvl-bg@2x.png",
    "preload-lvl-wave@2x.png",
    "preload-lvl-bird@2x.png",
    "popup_item_rate_stars@2x.png",
    "icon_properties@2x.png"
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Loading::Loading()
{
    CCTextureCache::sharedTextureCache()->addImage("start_preloader_bg@2x.png");
    CCTextureCache::sharedTextureCache()->addImage("start_preloader_bar@2x.png");

    this->mBackground = new Entity("start_preloader_bg@2x.png", this);
    this->mBar = new Entity("start_preloader_bar@2x.png", this);

    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBar->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));

    this->mNumberOfLoadedSprites = -1;
    this->mNumberOfSprites = sizeof(TEXTURE_LIBRARY) / sizeof(const char*) - 1;
    
    this->mLoadingText = new Text(Options::TEXT_LOADING_1, this);
    this->mLoadingText->setCenterPosition(this->mBar->getCenterX(), this->mBar->getCenterY());
    
    for(int i = 0; i < this->mNumberOfSprites + 1; i++)
    {
        CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[i], this, callfuncO_selector(Loading::loadingCallBack));
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
    
    if(this->mNumberOfLoadedSprites == this->mNumberOfSprites)
    {
        AppDelegate::screens = new ScreenManager();
        
        AppDelegate::screens->set(0.5f, Screen::SCREEN_MENU);
    }
    else
    {
        
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Loading::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);

    this->mBar->setRotation(this->mBar->getRotation() + 10.0);
}

#endif