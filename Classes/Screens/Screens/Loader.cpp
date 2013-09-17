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

const char* Loader::WEAPON_TEXTURE[11] =
{
    "wep_1@2x.png",
    "wep_2@2x.png",
    "wep_3@2x.png",
    "wep_4@2x.png",
    "wep_5@2x.png",
    "wep_6@2x.png",
    "wep_7@2x.png",
    "wep_8@2x.png",
    "wep_9@2x.png",
    "wep_10@2x.png",
    "wep_11@2x.png"
};

TextureStructure Loader::TEXTURE_LIBRARY[7] =
{
    {"TextureAtlas6.png", "TextureAtlas6.plist"},
    {"TextureAtlas7.png", "TextureAtlas7.plist"},
    {"TextureAtlas8.png", "TextureAtlas8.plist"},
    {"TextureAtlas10.png", "TextureAtlas10.plist"},
    {"TextureAtlas11.png", "TextureAtlas11.plist"},
    {"TextureAtlas12.png", "TextureAtlas12.plist"},
    {WEAPON_TEXTURE[Options::SELECTED_WEAPON_ID], NULL}
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Loader::~Loader()
{
    this->mCircles->release();
}

Loader::Loader()
{
    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas3.png");
    this->addChild(spriteBatch);

    this->mBackground = Entity::create("preload-lvl-bg@2x.png", spriteBatch);
    this->mCircles = EntityManager::create(15, Entity::create("preload-lvl-wave@2x.png"), spriteBatch);
    this->mBird = Entity::create("preload-lvl-bird@2x.png", spriteBatch);
    
    this->mLoadingText = Text::create(Options::TEXT_LOADING_1, this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBird->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(150));
    this->mLoadingText->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(160), Utils::coord(50));
    
    this->mTipText = Text::create(Options::TEXT_TIP[0], ccp(Options::CAMERA_WIDTH - Utils::coord(50), 0), this);

    for(int i = 0; i < 5; i++)
    {
            
            Entity* circle = (Entity*) this->mCircles->create();
            
            circle->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(150));
            circle->setRotation(0.0);
            circle->setScale(0.0);
            circle->setOpacity(255.0);
        
        for(int i = 0; i < this->mCircles->getCount(); i++)
        {
            Entity* circle = static_cast<Entity*>(this->mCircles->objectAtIndex(i));
            
            circle->setRotation(circle->getRotation() + 1.0 * 30.0);
            circle->setScale(circle->getScaleX() + 0.01 * 30.0);
            circle->setOpacity(circle->getOpacity() - 1.0 * 30.0);
            
            if(circle->getOpacity() <= 0.0)
            {
                circle->destroy();
            }
        }
    }
    
    this->mCircleAnimationTime = 0.5;
    this->mCircleAnimationTimeElapsed = 0;

    this->mLoadingTime = 0.5;
    this->mLoadingTimeElapsed = 0;

    this->mLoading = false;
    
    this->setRegisterAsTouchable(true);
}

Loader* Loader::create()
{
    Loader* screen = new Loader();
    screen->autorelease();
    screen->retain();
    
    return screen;
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
        AppDelegate::screens->load(ACTION, 1);
        
        this->mLoadingText->setOpacity(0.0);
        this->mLoadingText->setString(Options::TEXT_TAP_TO_CONTINUE.string);
        this->mLoadingText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(450));
        
        this->mTapToContinueAnimation = true;
        
        this->mIsWorkDone = true;

        if(ACTION > 2)
        {
        }
        else
        {
            AppDelegate::IS_ALREADY_PLAYED = true;
        }
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
        CCTextureCache::sharedTextureCache()->removeUnusedTextures();

        CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
    }
    else
    {
        
    }
}

void Loader::startLoading()
{
    AppDelegate::screens->load(ACTION, 0);
        
    CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    
    this->mNumberOfLoadedSprites = -1;

    switch(ACTION)
    {
        default:
            this->mNumberOfSprites = sizeof(TEXTURE_LIBRARY) / sizeof(TextureStructure) - 1;
    
            for(int i = 0; i < this->mNumberOfSprites + 1; i++)
            {
                if(TEXTURE_LIBRARY[i].frames == NULL)
                {
                    CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[i].texture, this, callfuncO_selector(Loader::loadingCallBack));
                }
                else
                {
                    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TEXTURE_LIBRARY[i].frames);

                    CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[i].texture, this, callfuncO_selector(Loader::loadingCallBack));
                }
            }

        break;
        case 3:
            this->mNumberOfSprites = sizeof(Loading::TEXTURE_LIBRARY) / sizeof(TextureStructure) - 1;
            
            for(int i = 0; i < this->mNumberOfSprites + 1; i++)
            {
                if(Loading::TEXTURE_LIBRARY[i].frames == NULL)
                {
                    CCTextureCache::sharedTextureCache()->addImageAsync(Loading::TEXTURE_LIBRARY[i].texture, this, callfuncO_selector(Loader::loadingCallBack));
                }
                else
                {
                    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(Loading::TEXTURE_LIBRARY[i].frames);

                    CCTextureCache::sharedTextureCache()->addImageAsync(Loading::TEXTURE_LIBRARY[i].texture, this, callfuncO_selector(Loader::loadingCallBack));
                }
            }

        break;
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
    
    for(int i = 0; i < this->mCircles->getCount(); i++)
    {
        Entity* circle = static_cast<Entity*>(this->mCircles->objectAtIndex(i));
        
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

    if(!this->mLoading)
    {
        this->mLoadingTimeElapsed += pDeltaTime;

        if(this->mLoadingTimeElapsed >= this->mLoadingTime)
        {
            this->mLoadingTimeElapsed = 0;
            this->mLoading = true;

            this->startLoading();
        }
    }
}

void Loader::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
}

void Loader::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
    
    ACTION = -1;
}

void Loader::onEnter()
{
    this->mLoading = false;

    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    Screen::onEnter();
    
    this->mTapToContinueAnimation = false;
    this->mIsWorkDone = false;
    
    this->mTipText->setString(Options::TEXT_TIP[Utils::random(0, 4)].string);
    this->mTipText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(250));
    
    this->mLoadingText->setString(Options::TEXT_LOADING_1.string);
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