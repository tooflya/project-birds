#ifndef CONST_LOADING
#define CONST_LOADING

#include "Loading.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

TextureStructure Loading::TEXTURE_LIBRARY[9] =
{
    {"TextureAtlas1.pvr.ccz", "TextureAtlas1.plist"},
    {"TextureAtlas2.pvr.ccz", "TextureAtlas2.plist"},
    {"TextureAtlas3.pvr.ccz", "TextureAtlas3.plist"},
    {"TextureAtlas4.pvr.ccz", "TextureAtlas4.plist"},
    {"TextureAtlas5.pvr.ccz", "TextureAtlas5.plist"},
    {"TextureAtlas9.pvr.ccz", "TextureAtlas9.plist"},
    {"more_games_list@2x.png", NULL},
    {"about_scroll_fill@2x.png", NULL},
    {"about_scroll_fill_small@2x.png", NULL}
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Loading::~Loading()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
}

Loading::Loading()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas1.plist");

    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas1.pvr.ccz");

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

    this->mLoadingPauseTime = 0.3;
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
    for(int i = 0; i < this->mNumberOfSprites + 1; i++)
    {
        if(TEXTURE_LIBRARY[i].frames == NULL)
        {
            CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[i].texture, this, callfuncO_selector(Loading::loadingCallBack));
        }
        else
        {
            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TEXTURE_LIBRARY[i].frames);
            
            CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[i].texture, this, callfuncO_selector(Loading::loadingCallBack));
        }
    }
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