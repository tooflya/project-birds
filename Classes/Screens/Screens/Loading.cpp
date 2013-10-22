#ifndef CONST_LOADING
#define CONST_LOADING

#include "Loading.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

<<<<<<< HEAD
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT
TextureStructure Loading::TEXTURE_LIBRARY[11] =
=======
#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
TextureStructure Loading::TEXTURE_LIBRARY[10] =
>>>>>>> c1a258939ab4a35d1458de5df385aaa2f1e96f6a
{
    {"TextureAtlas2.png", "TextureAtlas2.plist"},
    {"TextureAtlas3.png", "TextureAtlas3.plist"},
    {"TextureAtlas4.png", "TextureAtlas4.plist"},
    {"TextureAtlas5.png", "TextureAtlas5.plist"},
    {"TextureAtlas9.png", "TextureAtlas9.plist"},
    {"TextureAtlas13.png", "TextureAtlas13.plist"},
    {"TextureAtlas15.png", "TextureAtlas15.plist"},
    {"more_games_list@2x.png", NULL},
    {"about_scroll_fill@2x.png", NULL},
    {"about_scroll_fill_small@2x.png", NULL}
};
#else
TextureStructure Loading::TEXTURE_LIBRARY[10] =
{
    {"TextureAtlas2.pvr.ccz", "TextureAtlas2.plist"},
    {"TextureAtlas3.pvr.ccz", "TextureAtlas3.plist"},
    {"TextureAtlas4.pvr.ccz", "TextureAtlas4.plist"},
    {"TextureAtlas5.pvr.ccz", "TextureAtlas5.plist"},
    {"TextureAtlas9.pvr.ccz", "TextureAtlas9.plist"},
    {"TextureAtlas13.pvr.ccz", "TextureAtlas13.plist"},
    {"TextureAtlas15.png", "TextureAtlas15.plist"},
    {"more_games_list@2x.png", NULL},
    {"about_scroll_fill@2x.png", NULL},
    {"about_scroll_fill_small@2x.png", NULL}
};
#endif

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Loading::~Loading()
{
}

Loading::Loading()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas1.plist");

    SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas1");

    this->mBackground = Entity::create("start_preloader_bg@2x.png", spriteBatch);
    this->mBarBackground = Entity::create("start_preload_bar@2x.png", spriteBatch);
    this->mBar = Entity::create("start_preload_bar_fill@2x.png", spriteBatch);

    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBarBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Utils::coord(100));
    this->mBar->create()->setCenterPosition(Options::CAMERA_CENTER_X, Utils::coord(100));
    this->mBar->showPercentage(0);
    
    this->mNumberOfLoadedSprites = -1;
    this->mNumberOfSprites = sizeof(TEXTURE_LIBRARY) / sizeof(TextureStructure) - 1;
    
    this->addChild(spriteBatch);

    this->mLoadingText = Text::create(Options::TEXT_LOADING_1, this);
    this->mLoadingText->setCenterPosition(this->mBar->getCenterX(), this->mBar->getCenterY());

    this->mLoading = false;
    this->mLoadingProgress = false;

    this->mLoadingPauseTime = 0;
    this->mLoadingPauseTimeElapsed = 0.0;
}

Loading* Loading::create()
{
    Loading* screen = new Loading();
    screen->autorelease();

    return screen;
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
        this->mLoadingProgress = false;
        
        AppDelegate::screens = ScreenManager::create();
        
        {
            Options::changeLanguage();
    
            this->mLoadingText->setString((Options::TEXT_LOADING_2.string + Utils::intToString(percent) + "%").c_str());
        }
        
        AppDelegate::screens->set(0.5f, Screen::SCREEN_MENU);
    }
    else
    {
    }
}

void Loading::startLoading()
{
    this->mLoadingProgress = true;
    
    this->mLoadingProgressTime = 0.3;
    this->mLoadingProgressTimeElapsed = 0;
}

// ===========================================================
// Override Methods
// ===========================================================

void Loading::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);

    if(!this->mLoading)
    {
        this->mLoadingPauseTimeElapsed += pDeltaTime;

        if(this->mLoadingPauseTimeElapsed >= this->mLoadingPauseTime)
        {
            this->mLoading = true;

            this->startLoading();
        }
    }
    
    if(this->mLoadingProgress)
    {
        this->mLoadingProgressTimeElapsed += pDeltaTime;
        
        if(this->mLoadingProgressTimeElapsed >= this->mLoadingProgressTime)
        {
            this->mLoadingProgressTimeElapsed = 0;
            
            if(TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].frames == NULL)
            {
                CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].texture, this, callfuncO_selector(Loading::loadingCallBack));
            }
            else
            {
                CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].frames);
                
                #if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
                CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].texture, this, callfuncO_selector(Loading::loadingCallBack));
                #else
                //CCTextureCache::sharedTextureCache()->addPVRImage(TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].texture);
                
                this->loadingCallBack(NULL);
                #endif
            }
        }
    }
}

void Loading::onEnter()
{
    Screen::onEnter();
}

void Loading::onExit()
{
    Screen::onExit();
}

#endif