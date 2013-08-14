#ifndef CONST_LOADING
#define CONST_LOADING

#include "Loading.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

const char* Loading::TEXTURE_LIBRARY[24] =
{
    "TextureAtlas2.pvr",
    "TextureAtlas3.pvr",
    "TextureAtlas4.pvr",
    "flag_not_avaliable_bg@2x.png",
    "about_name_logo@2x.png",
    "flag_sprite_small@2x.png",
    "about_logo@2x.png",
    "more_games_list@2x.png",
    "settings_btn_big@2x.png",
    "shop_money_bg@2x.png",
    "flag_sprite_big@2x.png",
    "shop_wheel@2x.png",
    "shop_shelf_sprite@2x.png",
    "choose_box_lvl_sprite@2x.png",
    "popup_btn@2x.png",
    "end_lvl_star_sprite@2x.png",
    "settings_lang_check@2x.png",
    "about_scroll_fill@2x.png",
    "popup_rate_picture@2x.png",
    "popup_progress_picture@2x.png",
    "about_scroll_fill_small@2x.png",
    "coins@2x.png",
    "icon_properties@2x.png",
    "shop_item_icon@2x.png"
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Loading::Loading()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas1.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas2.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas3.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas4.plist");

    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas1.pvr");

    this->mBackground = new Entity("start_preloader_bg@2x.png", spriteBatch);
    this->mBarBackground = new Entity("start_preload_bar@2x.png", spriteBatch);
    this->mBar = new Entity("start_preload_bar_fill@2x.png", spriteBatch);

    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBarBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Utils::coord(100));
    this->mBar->create()->setCenterPosition(Options::CAMERA_CENTER_X, Utils::coord(100));
    this->mBar->showPercentage(0);
    
    this->mNumberOfLoadedSprites = -1;
    this->mNumberOfSprites = sizeof(TEXTURE_LIBRARY) / sizeof(const char*) - 1;
    
    this->addChild(spriteBatch);

    this->mLoadingText = new Text(Options::TEXT_LOADING_1, this);
    this->mLoadingText->setCenterPosition(this->mBar->getCenterX(), this->mBar->getCenterY());
    
    for(int i = 0; i < this->mNumberOfSprites + 0; i++)
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