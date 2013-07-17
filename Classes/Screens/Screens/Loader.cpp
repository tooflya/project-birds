#ifndef CONST_LOADER
#define CONST_LOADER

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

const char* Loader::TEXTURE_LIBRARY[12] =
{
    "game_gui_bg_summer@2x.png",
    "birds_sprite@2x.png",
    "game_gui_btn_sprite@2x.png",
    "popup_bg@2x.png",
    "popup_darkness@2x.png",
    "btn_sprite@2x.png",
    "end_lvl_btn_sprite@2x.png",
    "settings_btn_big@2x.png",
    "end_lvl_bg_sprite@2x.png",
    "end_lvl_bg_popup@2x.png",
    "confety_sprite@2x.png",
    "end_lvl_star_sprite@2x.png"
};

// ===========================================================
// Constants
// ===========================================================

int Loader::ACTION = -1;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Loader::Loader()
{
    this->mBackground = new Entity("preload-lvl-bg@2x.png", this);
    this->mAnimationSpiral = new Entity("preload-lvl-spiral@2x.png", this);
    this->bird = new Entity("preload-lvl-bird@2x.png", this);
    this->mLoadingText = new Text(Options::TEXT_LOADING_1, this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mAnimationSpiral->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(50), Options::CAMERA_CENTER_Y - Utils::coord(50));
    this->bird->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mLoadingText->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(160), Utils::coord(50));
    
    this->mAnimationSpiral->setAnchorPoint(ccp(0.55, 0.321));
}

// ===========================================================
// Methods
// ===========================================================

void Loader::loadingCallBack(CCObject *obj)
{
    ++this->mNumberOfLoadedSprites;
    
    int percent = (int) (((float) mNumberOfLoadedSprites / mNumberOfSprites) * 100);
    
    this->mLoadingText->setString((Options::TEXT_LOADING_2.string + Utils::intToString(percent) + "%").c_str());
    
    if(this->mNumberOfLoadedSprites == this->mNumberOfSprites)
    {
        AppDelegate::screens->load(ACTION);
        
        switch(ACTION)
        {
            case 0:
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_CLASSIC_GAME);

            break;
            case 1:
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_ARCADE_GAME);

            break;
            case 2:
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_PROGRESS_GAME);

            break;
            case 3:


            break;
        }
    }
    else
    {
        
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Loader::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    this->mAnimationSpiral->setRotation(this->mAnimationSpiral->getRotation() - 30.0 * pDeltaTime);
}

void Loader::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
    
    this->mNumberOfLoadedSprites = -1;
    this->mNumberOfSprites = sizeof(TEXTURE_LIBRARY) / sizeof(const char*) - 1;

    CCTextureCache::sharedTextureCache()->removeAllTextures();

    switch(ACTION)
    {
         default:
    
            for(int i = 0; i < this->mNumberOfSprites + 1; i++)
            {
                CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[i], this, callfuncO_selector(Loader::loadingCallBack));
            }

        break;
        case 3:

            //

        break;
    }
}

void Loader::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
    
    ACTION = -1;
}

void Loader::onEnter()
{
    Screen::onEnter();
}

void Loader::onExit()
{
    Screen::onExit();
}

#endif