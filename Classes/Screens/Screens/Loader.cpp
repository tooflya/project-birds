#ifndef CONST_LOADER
#define CONST_LOADER

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

const char* Loader::TEXTURE_LIBRARY[8] =
{
    "game_gui_bg_summer@2x.png",
    "birds_sprite@2x.png",
    "game_gui_btn_sprite@2x.png",
    "popup_bg@2x.png",
    "popup_darkness@2x.png",
    "btn_sprite@2x.png",
    "end_lvl_btn_sprite@2x.png",
    "settings_btn_big@2x.png"
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
    this->mLoadingText = new Text(Options::TEXT_LOADING_1, this);
    this->mLoadingText->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(140), Utils::coord(50));
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
        AppDelegate::screens->load();
        
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