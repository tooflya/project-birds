#ifndef CONST_PROGRESS
#define CONST_PROGRESS

#include "Progress.h"

#include "Settings.h"
#include "Levels.h"
#include "Menu.h"

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

Progress::~Progress()
{
    CC_SAFE_RELEASE(this->mResetPopup);
}

Progress::Progress() :
	mBackground(0),
	mBackButton(0),
	mResetButton(0),
	mResetPopup(0)
	{
		SpriteBatch* spriteBatch1 = SpriteBatch::create("TextureAtlas2");
		SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas2");
    
		ccBlendFunc function1 = {GL_ONE, GL_ZERO};
		ccBlendFunc function2 = {GL_ONE, GL_ONE_MINUS_SRC_ALPHA};

		spriteBatch1->setBlendFunc(function1);
		spriteBatch2->setBlendFunc(function2);
    
		this->addChild(spriteBatch1);
		this->addChild(spriteBatch2);

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};

		this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch1);
        this->mBackButton = Button::create(structure1, spriteBatch2, Options::BUTTONS_ID_PROGRESS_BACK, this);
        
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        
        if(!AppDelegate::isAdvertisiment())
        {
            this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
        }
    
		this->mResetButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch2, Options::BUTTONS_ID_PROGRESS_RESET, this);

		this->mResetButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(200));
		this->mResetButton->setText(Options::TEXT_PROGRESS_RESET);

		Text* text1 = Text::create(Options::TEXT_PROGRESS_STRING_1, CCSize(Utils::coord(700), 0), this);

		text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));

		this->mResetPopup = ResetProgress::create(this);
        
        this->mDark = Dark::create();
        this->mDark->setCascadeOpacityEnabled(true);
        
        this->addChild(this->mDark, 5);
        
        Text* text2 = Text::create(Options::TEXT_LOADING_RESET, this->mDark);
        text2->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        
        this->mDark->setOpacity(0);
        
        this->mResetAnimationRunning = false;

		if (AppDelegate::isGetWindeScreen())
		{
			this->mBackground->setScale(MAX(Options::CAMERA_HEIGHT / Options::designResolutionSize.height, Options::designResolutionSize.height / Options::CAMERA_HEIGHT));
		}
        
        AppDelegate::clearCache();
	}

Progress* Progress::create()
{
    Progress* screen = new Progress();
	screen->autorelease();

	#if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
	screen->retain();
	#endif
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Progress::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_PROGRESS_BACK:
                
                this->keyBackClicked(false);
                
            break;
            case Options::BUTTONS_ID_PROGRESS_RESET:
                
                this->mResetPopup->show();
                
            break;
        }
        break;
            
        case Options::BUTTONS_ACTION_ONBEGIN:
        break;
            
        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void Progress::reset()
{
    this->mDark->runAction(CCFadeTo::create(1.0, 230));
    
    this->mResetAnimationRunning = true;
    this->mResetAnimationTimeElapsed = 0;
}

// ===========================================================
// Override Methods
// ===========================================================

void Progress::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    if(this->mResetAnimationRunning)
    {
        this->mResetAnimationTimeElapsed += pDeltaTime;
        
        if(this->mResetAnimationTimeElapsed >= 3.0)
        {
            this->mResetAnimationRunning = false;
            
            this->onReset();
        }
    }
}

void Progress::onReset()
{
    AppDelegate::install(true);
    
    #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
    AppDelegate::screens->set(Menu::create());
    #else
    static_cast<Levels*>(AppDelegate::screens->mScreens[Screen::SCREEN_LEVELS])->updateIcons();
    AppDelegate::screens->set(Screen::SCREEN_MENU);
    #endif
}

void Progress::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    if(this->mResetPopup->getParent())
    {
        this->mResetPopup->hide();
    }
    else
	{
		#if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
		AppDelegate::screens->set(Screen::SCREEN_SETTINGS);
		#else
		AppDelegate::screens->set(Settings::create());
		#endif
    }
}

void Progress::onEnter()
{
    Screen::onEnter();
    
    if(!AppDelegate::isAdvertisiment())
    {
        if(!this->mBackButton->isVisible()) this->mBackButton->create();
        this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));
    }
}

void Progress::onExit()
{
    Screen::onExit();
    
    this->mDark->setOpacity(0);
}

#endif