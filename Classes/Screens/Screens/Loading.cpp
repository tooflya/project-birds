#ifndef CONST_LOADING
#define CONST_LOADING

#include "Loading.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

const char* Loading::TEXTURE_LIBRARY[8] =
{
    "more_games_list@2x.png",
    "about_scroll_fill@2x.png",
    "about_scroll_fill_small@2x.png",
    "TextureAtlas1.pvr.ccz",
    "TextureAtlas2.pvr.ccz",
    "TextureAtlas3.pvr.ccz",
    "TextureAtlas4.pvr.ccz",
    "TextureAtlas5.pvr.ccz"
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Loading::~Loading()
{
    this->removeAllChildrenWithCleanup(true);
    
    this->release();
    
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
    this->mNumberOfSprites = sizeof(TEXTURE_LIBRARY) / sizeof(const char*) - 1;
    
    this->addChild(spriteBatch);

    this->mLoadingText = new Text(Options::TEXT_LOADING_1, this);
    this->mLoadingText->setCenterPosition(this->mBar->getCenterX(), this->mBar->getCenterY());
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

// ===========================================================
// Override Methods
// ===========================================================

void Loading::onEnter()
{
    Screen::onEnter();
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas2.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas3.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas4.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas5.plist");
    
    for(int i = 0; i < this->mNumberOfSprites + 1; i++)
    {
        CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[i], this, callfuncO_selector(Loading::loadingCallBack));
    }
}

void Loading::onExit()
{
    Screen::onExit();
    
    delete this;
}

#endif