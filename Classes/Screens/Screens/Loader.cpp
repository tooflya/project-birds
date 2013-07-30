#ifndef CONST_LOADER
#define CONST_LOADER

#include "Loader.h"

#include "Loading.h"
#include "Shop.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Loader::ACTION = -1;

const char* Loader::TEXTURE_LIBRARY[21] =
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
    "mark@2x.png",
    "birds_feather_sprite@2x.png",
    "explosion@2x.png",
    "dust@2x.png",
    "end_lvl_star_sprite@2x.png",
    "wep_1@2x.png",
    "pause_birds_sprite@2x.png",
    "btn_sfx_mfx_ach_lead_sprite_pause@2x.png",
    "pause_btn@2x.png",
    "pause_btn_sprite@2x.png"
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Loader::Loader()
{
    this->mBackground = new Entity("preload-lvl-bg@2x.png", this);
    this->mCircles = new BatchEntityManager(10, new Entity("preload-lvl-wave@2x.png"), this);
    this->bird = new Entity("preload-lvl-bird@2x.png", this);
    
    this->mLoadingText = new Text(Options::TEXT_LOADING_1, this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->bird->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(150));
    this->mLoadingText->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(160), Utils::coord(50));
    
    this->mTipText = new Text(Options::TEXT_TIP[0], ccp(Options::CAMERA_WIDTH - Utils::coord(50), 0), this);
    
    this->mCircleAnimationTime = 0.5;
    this->mCircleAnimationTimeElapsed = 0;
    
    this->setRegisterAsTouchable(true);
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
        
        this->mLoadingText->setOpacity(0.0);
        this->mLoadingText->setString(Options::TEXT_TAP_TO_CONTINUE.string);
        this->mLoadingText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(450));
        
        this->mTapToContinueAnimation = true;
        
        this->mIsWorkDone = true;

        if(ACTION > 2)
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music-1.mp3", true); 

            if(!Options::MUSIC_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
            }
        }
        else
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music-2.mp3", true); 

            if(!Options::MUSIC_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
            }
        }
    }
    else
    {
        
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Loader::onTouch(CCTouch* touch, CCEvent* event)
{
    if(this->mIsWorkDone)
    {
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
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);
                
            break;
            case 4:
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_MODE);
                
            break;
            case 5:

                Shop::ACTION = 0;

                AppDelegate::screens->set(0.5, Screen::SCREEN_SHOP);
                
            break;
        }
    }
}

void Loader::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    this->mCircleAnimationTimeElapsed += pDeltaTime;
    
    if(this->mCircleAnimationTimeElapsed >= this->mCircleAnimationTime)
    {
        this->mCircleAnimationTimeElapsed = 0;
        
        Entity* circle = (Entity*) this->mCircles->create();
        
        circle->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(150));
        circle->setRotation(0.0);
        circle->setScale(0.0);
        circle->setOpacity(255.0);
    }
    
    for(int i = 0; i < this->mCircles->getChildrenCount(); i++)
    {
        Entity* circle = (Entity*) this->mCircles->getChildren()->objectAtIndex(i);
        
        circle->setRotation(circle->getRotation() + 1.0);
        circle->setScale(circle->getScaleX() + 0.01);
        circle->setOpacity(circle->getOpacity() - 1.0);
        
        if(circle->getOpacity() <= 0.0)
        {
            circle->destroy();
        }
    }
    
    if(this->mTapToContinueAnimation)
    {
        if(this->mTapToContinueAnimationReverse)
        {
            this->mLoadingText->setOpacity(this->mLoadingText->getOpacity() - 5.0);
            
            if(this->mLoadingText->getOpacity() <= 20.0)
            {
                this->mTapToContinueAnimationReverse = !this->mTapToContinueAnimationReverse;
            }
        }
        else
        {
            this->mLoadingText->setOpacity(this->mLoadingText->getOpacity() + 5.0);
            
            if(this->mLoadingText->getOpacity() >= 245.0)
            {
                this->mTapToContinueAnimationReverse = !this->mTapToContinueAnimationReverse;
            }
        }
    }
}

void Loader::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
    
    this->mNumberOfLoadedSprites = -1;

    CCTextureCache::sharedTextureCache()->removeAllTextures();
    CCDirector::sharedDirector()->purgeCachedData();

    switch(ACTION)
    {
        default:
            
            this->mNumberOfSprites = sizeof(TEXTURE_LIBRARY) / sizeof(const char*) - 1;
    
            for(int i = 0; i < this->mNumberOfSprites + 1; i++)
            {
                CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[i], this, callfuncO_selector(Loader::loadingCallBack));
            }

        break;
        case 3:
            this->mNumberOfSprites = sizeof(Loading::TEXTURE_LIBRARY) / sizeof(const char*) - 1;
            
            for(int i = 0; i < this->mNumberOfSprites + 1; i++)
            {
                CCTextureCache::sharedTextureCache()->addImageAsync(Loading::TEXTURE_LIBRARY[i], this, callfuncO_selector(Loader::loadingCallBack));
            }

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
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    Screen::onEnter();
    
    this->mTapToContinueAnimation = false;
    this->mIsWorkDone = false;
    
    this->mTipText->setString(Options::TEXT_TIP[Utils::random(0, 4)].string);
    this->mTipText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(250));
    
    this->mLoadingText->setString("");
    this->mLoadingText->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(160), Utils::coord(50));
    this->mLoadingText->setOpacity(255.0);

    SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

void Loader::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    
    Screen::onExit();
}

#endif