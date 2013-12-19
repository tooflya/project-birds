#ifndef CONST_LOADER
#define CONST_LOADER

#include "Loader.h"

#include "Loading.h"
#include "Shop.h"
#include "Menu.h"
#include "Mode.h"
#include "Classic.h"
#include "Arcade.h"
#include "Progresses.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Loader::ACTION = -1;
int Loader::TYPE = -1;
int Loader::T = -1;

const char* Loader::WEAPON_TEXTURE[11] =
{
    "wep_1@2x.png",
    "wep_2@2x.png",
    "wep_3@2x.png",
    "wep_4@2x.png",
    "wep_5@2x.png",
    "wep_6@2x.png",
    "wep_7@2x.png",
    "wep_11@2x.png",
    "wep_9@2x.png",
    "wep_10@2x.png",
    "wep_8@2x.png"
};

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
TextureStructure Loader::TEXTURE_LIBRARY[11] =
{
	{"TextureAtlas19.png", "TextureAtlas19.plist"},
    {"TextureAtlas6.png", "TextureAtlas6.plist"},
    {"TextureAtlas7.png", "TextureAtlas7.plist"},
    {"TextureAtlas8.png", "TextureAtlas8.plist"},
    {"TextureAtlas9.png", "TextureAtlas9.plist"},
    {"TextureAtlas10.png", "TextureAtlas10.plist"},
    {"TextureAtlas11.png", "TextureAtlas11.plist"},
    {"TextureAtlas12.png", "TextureAtlas12.plist"},
    {"TextureAtlas14.png", "TextureAtlas14.plist"},
	{"TextureAtlas17.png", "TextureAtlas17.plist"},
    {WEAPON_TEXTURE[Options::SELECTED_WEAPON_ID], NULL}
};
#else
TextureStructure Loader::TEXTURE_LIBRARY[11] =
{
	{"TextureAtlas19.pvr.ccz", "TextureAtlas19.plist"},
    {"TextureAtlas6.pvr.ccz", "TextureAtlas6.plist"},
    {"TextureAtlas7.pvr.ccz", "TextureAtlas7.plist"},
    {"TextureAtlas8.pvr.ccz", "TextureAtlas8.plist"},
    {"TextureAtlas9.pvr.ccz", "TextureAtlas9.plist"},
    {"TextureAtlas10.pvr.ccz", "TextureAtlas10.plist"},
    {"TextureAtlas11.pvr.ccz", "TextureAtlas11.plist"},
    {"TextureAtlas12.pvr.ccz", "TextureAtlas12.plist"},
    {"TextureAtlas14.pvr.ccz", "TextureAtlas14.plist"},
    {"TextureAtlas17.pvr.ccz", "TextureAtlas17.plist"},
    {WEAPON_TEXTURE[Options::SELECTED_WEAPON_ID], NULL}
};
#endif

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Loader::~Loader()
{
    CC_SAFE_RELEASE(this->mCircles);
}

Loader::Loader() :
	mNumberOfSprites(0),
	mNumberOfLoadedSprites(0),
	mCircleAnimationTime(0),
	mCircleAnimationTimeElapsed(0),
	mLoadingProgressTime(0),
	mLoadingProgressTimeElapsed(0),
	mLoadingTime(0),
	mLoadingTimeElapsed(0),
	mTapToContinueAnimation(0),
	mTapToContinueAnimationReverse(0),
	mIsWorkDone(0),
	mLoading(0),
	mLoadingProgress(0),
	mBackground(0),
	mBird(0),
	mLoadingText(0),
	mTipText(0),
	mCircles(0)
	{
		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas3");
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

		this->mLoadingTime = 1.5;
		this->mLoadingTimeElapsed = 0;

		this->mLoading = false;
		this->mLoadingProgress = false;
    
		this->setRegisterAsTouchable(true);

		if (AppDelegate::isGetWindeScreen())
		{
			this->mBackground->setScale(MAX(Options::CAMERA_HEIGHT / Options::designResolutionSize.height, Options::designResolutionSize.height / Options::CAMERA_HEIGHT));
		}
	}

Loader* Loader::create()
{
    Loader* screen = new Loader();
    screen->autorelease();
    
    #if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
	screen->retain();
    #endif
    
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
        this->mLoadingProgress = false;
        
        #if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
        AppDelegate::screens->load(ACTION, T);
        #endif
        
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
        
        AppDelegate::clearCache();
    }
    else
    {
    }
}

void Loader::startLoading()
{
    #if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
    AppDelegate::screens->load(ACTION, TYPE);
    #endif
    
	CCSpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
	CCSpriteFrameCache::sharedSpriteFrameCache()->purgeSharedSpriteFrameCache();
    
    CCTextureCache::sharedTextureCache()->removeUnusedTextures();
    CCTextureCache::sharedTextureCache()->purgeSharedTextureCache();
    
    CCDirector::sharedDirector()->purgeCachedData();
    
    CCTextureCache::sharedTextureCache()->dumpCachedTextureInfo();
    
    this->mNumberOfLoadedSprites = -1;
    
    this->mLoadingProgress = true;
    
    this->mLoadingProgressTime = 0.3;
    this->mLoadingProgressTimeElapsed = 0;
}

// ===========================================================
// Override Methods
// ===========================================================

void Loader::onTouch(CCTouch* touch, CCEvent* event)
{
    if(this->mIsWorkDone)
    {
        T = -1;
        
        switch(ACTION)
        {
            case 0:
                
                #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
                AppDelegate::screens->set(Classic::create());
                #else
                AppDelegate::screens->set(Screen::SCREEN_CLASSIC_GAME);
                #endif
                
            break;
            case 1:
                
                #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
                AppDelegate::screens->set(Arcade::create());
                #else
                AppDelegate::screens->set(Screen::SCREEN_ARCADE_GAME);
                #endif
                
            break;
            case 2:
                
                #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
                AppDelegate::screens->set(Progresses::create());
                #else
                AppDelegate::screens->set(Screen::SCREEN_PROGRESS_GAME);
                #endif
                
            break;
            case 3:
                
                #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
                AppDelegate::screens->set(Menu::create());
                #else
                AppDelegate::screens->set(Screen::SCREEN_MENU);
                #endif
                
            break;
            case 4:
                
                #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
                AppDelegate::screens->set(Mode::create());
                #else
                AppDelegate::screens->set(Screen::SCREEN_MODE);
                #endif
                
            break;
            case 5:

                //Shop::ACTION = 0;
                
                #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
                AppDelegate::screens->set(Shop::create());
                #else
                AppDelegate::screens->set(Screen::SCREEN_SHOP);
                #endif
                
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
        
        if(circle != NULL)
        {
            circle->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(150));
            circle->setRotation(0.0);
            circle->setScale(0.0);
            circle->setOpacity(255.0);
        }
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
    
    if(this->mLoadingProgress)
    {
        this->mLoadingProgressTimeElapsed += pDeltaTime;
        
        if(this->mLoadingProgressTimeElapsed >= this->mLoadingProgressTime)
        {
            this->mLoadingProgressTimeElapsed = 0;
            
            switch(ACTION)
            {
                default:
                    this->mNumberOfSprites = sizeof(TEXTURE_LIBRARY) / sizeof(TextureStructure) - 1;
                
                    {
                        if(TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].frames == NULL)
                        {
                            CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].texture, this, callfuncO_selector(Loader::loadingCallBack));
                        }
                        else
                        {
                            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].frames);
                        
                            #if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
                            CCTextureCache::sharedTextureCache()->addImageAsync(TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].texture, this, callfuncO_selector(Loader::loadingCallBack));
                            #else
                            //CCTextureCache::sharedTextureCache()->addPVRImage(TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].texture);
                        
                            this->loadingCallBack(NULL);
                            #endif
                        }
                    }
                
                    break;
                case 3:
                case 4:
                case 5:
                    this->mNumberOfSprites = sizeof(Loading::TEXTURE_LIBRARY) / sizeof(TextureStructure) - 1;
                
                    {
                        if(Loading::TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].frames == NULL)
                        {
                            CCTextureCache::sharedTextureCache()->addImageAsync(Loading::TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].texture, this, callfuncO_selector(Loader::loadingCallBack));
                        }
                        else
                        {
                            CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(Loading::TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].frames);
                        
                            #if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
                            CCTextureCache::sharedTextureCache()->addImageAsync(Loading::TEXTURE_LIBRARY[this->mNumberOfLoadedSprites + 1].texture, this, callfuncO_selector(Loader::loadingCallBack));
                            #else
                            //CCTextureCache::sharedTextureCache()->addPVRImage(Loading::TEXTURE_LIBRARY[i].texture);
                        
                            this->loadingCallBack(NULL);
                            #endif
                        }
                    }
                
                break;
            }
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
    
    if(Game::LEVEL <= 15)
    {
        Loader::TEXTURE_LIBRARY[1] = (TextureStructure) {"TextureAtlas16.pvr.ccz", "TextureAtlas16.plist"};
    }
    else if(Game::LEVEL <= 31)
    {
        Loader::TEXTURE_LIBRARY[1] = (TextureStructure) {"TextureAtlas23.pvr.ccz", "TextureAtlas23.plist"};
    }
    else if(Game::LEVEL <= 47)
    {
        Loader::TEXTURE_LIBRARY[1] = (TextureStructure) {"TextureAtlas24.pvr.ccz", "TextureAtlas24.plist"};
    }
    else if(Game::LEVEL <= 63)
    {
        Loader::TEXTURE_LIBRARY[1] = (TextureStructure) {"TextureAtlas25.pvr.ccz", "TextureAtlas25.plist"};
    }
    else if(Game::LEVEL <= 79)
    {
        Loader::TEXTURE_LIBRARY[1] = (TextureStructure) {"TextureAtlas26.pvr.ccz", "TextureAtlas26.plist"};
    }
}

void Loader::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    
    Screen::onExit();
}

#endif