#ifndef CONST_LOADING
#define CONST_LOADING

#include "Loading.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

const char* Loading::TEXTURE_LIBRARY[48] =
{
    "main_menu_bg@2x.png",
    "bg_detail_stripe@2x.png",
    "bg_detail_settings@2x.png",
    "bg_detail_lamp@2x.png",
    "flag_not_avaliable_bg@2x.png",
    "about_name_logo@2x.png",
    "about_logo@2x.png",
    "bg_detail_dark@2x.png",
    "more_games_list@2x.png",
    "play_btn_animation@2x.png",
    "bg_detail_choose_bird@2x.png",
    "main_menu_btn_bg_play@2x.png",
    "btn_sprite@2x.png",
    "settings_bg@2x.png",
    "settings_btn_big@2x.png",
    "btn_sfx_mfx_ach_lead_sprite@2x.png",
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
    CCTextureCache::sharedTextureCache()->addImage("start_preloader_atlas@2x.png");

    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("start_preloader_atlas@2x.png");

    this->mBackground = new Entity((EntityStructure) {"start_preloader_atlas@2x.png", 1, 1, 0, 0, 1000, 1280}, spriteBatch);
    this->mBarBackground = new Entity((EntityStructure) {"start_preloader_atlas@2x.png", 1, 1, 2, 1287, 631, 88}, spriteBatch);
    this->mBar = new Entity((EntityStructure) {"start_preloader_atlas@2x.png", 1, 1, 2, 1394, 577, 38}, spriteBatch);

    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBarBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Utils::coord(100));
    this->mBar->create()->setCenterPosition(Options::CAMERA_CENTER_X, Utils::coord(100));
    this->mBar->showPercentage(0);
    
    this->mNumberOfLoadedSprites = -1;
    this->mNumberOfSprites = sizeof(TEXTURE_LIBRARY) / sizeof(const char*) - 1;
    
    this->addChild(spriteBatch);

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
    
    this->mBar->showPercentage(percent);
    this->mBar->setCenterPosition(Options::CAMERA_CENTER_X + this->mBar->getWidth() / 2 - Utils::coord(577.0) / 2, Utils::coord(100));
    
    if(this->mNumberOfLoadedSprites == this->mNumberOfSprites)
    {
        AppDelegate::screens = new ScreenManager();
        
        { // TODO: Something goes wrong.
            Options::changeLanguage(); 
    
            this->mLoadingText->setString((Options::TEXT_LOADING_2.string + Utils::intToString(percent) + "%").c_str());
        }
        
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
}

#endif