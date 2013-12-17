#ifndef CONST_MORE
#define CONST_MORE

#include "More.h"

#include "Settings.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

More::More() :
	mBackground(0),
	mBackButton(0)
	{
		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas2");
		SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas2");
        
		this->addChild(spriteBatch);
		this->addChild(spriteBatch2);

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};

		this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
		this->mBackgroundDecorations[0] = Entity::create("bg_detail_stripe@2x.png", spriteBatch2);
		this->mBackgroundDecorations[1] = Entity::create("bg_detail_settings@2x.png", spriteBatch2);

        this->mBackButton = Button::create(structure1, spriteBatch2, Options::BUTTONS_ID_MORE_BACK, this);
		this->mVideoButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch2, Options::BUTTONS_ID_MORE_VIDEO, this);
		this->mMoreGamesButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch2, Options::BUTTONS_ID_MORE_MORE_GAMES, this);
		this->mPrivacyPolicyButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch2, Options::BUTTONS_ID_MORE_PRIVACY_POLICY, this);
        
		this->mVideoButton->create()->setCurrentFrameIndex(1);
		this->mVideoButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(350));
		this->mVideoButton->setText(Options::TEXT_MORE[0]);
        
		this->mMoreGamesButton->create()->setCurrentFrameIndex(1);
		this->mMoreGamesButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(120));
		this->mMoreGamesButton->setText(Options::TEXT_MORE[1]);
        
		this->mPrivacyPolicyButton->create()->setCurrentFrameIndex(1);
		this->mPrivacyPolicyButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(110));
		this->mPrivacyPolicyButton->setText(Options::TEXT_MORE[2]);
        
		ccBlendFunc bf = {GL_ONE, GL_ZERO};
		spriteBatch->setBlendFunc(bf);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        
		this->mBackgroundDecorations[0]->create()->setCenterPosition(Utils::coord(192), Options::CAMERA_HEIGHT - Utils::coord(103));
		this->mBackgroundDecorations[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(165), Utils::coord(128));
        
        if(!AppDelegate::isAdvertisiment())
        {
            this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
        }
        
		if (AppDelegate::isGetWindeScreen())
		{
			this->mBackground->setScale(MAX(Options::CAMERA_HEIGHT / Options::designResolutionSize.height, Options::designResolutionSize.height / Options::CAMERA_HEIGHT));
		}
        
        AppDelegate::clearCache();
	}

More* More::create()
{
    More* screen = new More();
	screen->autorelease();

	#if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
	screen->retain();
	#endif
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void More::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MORE_BACK:

                    this->keyBackClicked(false);

                break;
                case Options::BUTTONS_ID_MORE_VIDEO:
                    
                    #if CC_TARGET_LATFORM == CC_PLATFORM_ANDROID
                    callStaticVoidMethod("intro");
                    
                    CCUserDefault::sharedUserDefault()->setBoolForKey("is_video_showed", true);
                    CCUserDefault::sharedUserDefault()->flush();
                    #endif
                    
                break;
                case Options::BUTTONS_ID_MORE_MORE_GAMES:

                    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
                    callStaticVoidMethodWithString("open", "more");
                    #elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
                    AppDelegate::mGameCenter->open(4);
                    #endif
                    
                break;
                case Options::BUTTONS_ID_MORE_PRIVACY_POLICY:
                    
                    //
                    
                break;
            }
        break;

        case Options::BUTTONS_ACTION_ONBEGIN:
        break;

        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void More::onEnter()
{
    Screen::onEnter();
    
    if(!AppDelegate::isAdvertisiment())
    {
        if(!this->mBackButton->isVisible()) this->mBackButton->create();
        this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));
    }
}

void More::onExit()
{
    Screen::onExit();
}

void More::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);

	#if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
	AppDelegate::screens->set(Screen::SCREEN_SETTINGS);
	#else
	AppDelegate::screens->set(Settings::create());
	#endif
}

#endif