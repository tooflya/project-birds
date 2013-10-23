#ifndef CONST_SETTINGS
#define CONST_SETTINGS

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

Settings::~Settings()
{
    this->removeAllChildrenWithCleanup(true);
    
    delete this->mSpriteBatch;
    
    delete this->mBackground;
    delete this->mLanguage;
    delete this->mBackgroundDecorations[0];
    delete this->mBackgroundDecorations[1];
    
    delete this->mBackButton;
    delete this->mCreditsButton;
    delete this->mProgressButton;
    delete this->mMoreButton;
    delete this->mLanguageButton;
    delete this->mSoundButton;
    delete this->mMusicButton;
}

Settings::Settings() :
    mSpriteBatch(NULL),
	mBackground(0),
	mLanguage(0),
	mBackgroundDecorations(),
	mBackButton(0),
	mCreditsButton(0),
	mProgressButton(0),
	mMoreButton(0),
	mLanguageButton(0),
	mSoundButton(0),
	mMusicButton(0)
	{
		this->mSpriteBatch = SpriteBatch::create("TextureAtlas2");

		this->mBackground = Entity::create("settings_bg@2x.png", this->mSpriteBatch);
		this->mBackgroundDecorations[0] = Entity::create("bg_detail_stripe@2x.png", this->mSpriteBatch);
		this->mBackgroundDecorations[1] = Entity::create("bg_detail_settings@2x.png", this->mSpriteBatch);

		this->addChild(this->mSpriteBatch);

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};

		this->mBackButton = Button::create(structure1, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_BACK, this);
		this->mCreditsButton = Button::create("settings_btn_big@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_CREDITS, this);
		this->mProgressButton = Button::create("settings_btn_big@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_RATE, this);
		this->mMoreButton = Button::create("settings_btn_big@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_MORE, this);
		this->mLanguageButton = Button::create("settings_btn_big@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_LANGUAGE, this);
		this->mSoundButton = Button::create("btn_sfx_mfx_ach_lead_sprite@2x.png", 3, 2, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_SOUND, this);
		this->mMusicButton = Button::create("btn_sfx_mfx_ach_lead_sprite@2x.png", 3, 2, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_MUSIC, this);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

		this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));

		this->mSoundButton->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(310));
		this->mMusicButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(310));
    
		this->mCreditsButton->create()->setCurrentFrameIndex(1);
		this->mCreditsButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(500));
		this->mCreditsButton->setText(Options::TEXT_SETTINGS_CREDITS);
       
		this->mProgressButton->create()->setCurrentFrameIndex(1);
		this->mProgressButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));
		this->mProgressButton->setText(Options::TEXT_SETTINGS_PROGRESS);
    
		this->mMoreButton->create()->setCurrentFrameIndex(1);
		this->mMoreButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100));
		this->mMoreButton->setText(Options::TEXT_SETTINGS_MORE);
    
		this->mLanguageButton->create()->setCurrentFrameIndex(1);
		this->mLanguageButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(100));
		this->mLanguageButton->setText(Options::TEXT_SETTINGS_LANGUAGE);
    
		this->mLanguage = Entity::create("flag_sprite_small@2x.png", 2, 5, this);
		this->mLanguage->setCurrentFrameIndex(Options::CURRENT_LANGUAGE);
		this->mLanguage->setAnchorPoint(ccp(0.0, 0.5));
    
		this->mBackgroundDecorations[0]->create()->setCenterPosition(Utils::coord(192), Options::CAMERA_HEIGHT - Utils::coord(103));
		this->mBackgroundDecorations[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(165), Utils::coord(128));
    
		this->mLanguage->create();
	}

Settings* Settings::create()
{
    Settings* screen = new Settings();
    /*screen->autorelease();
    screen->retain();*/
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Settings::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_SETTINGS_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);

                break;
                case Options::BUTTONS_ID_SETTINGS_RATE:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_PROGRESS);

                break;
                case Options::BUTTONS_ID_SETTINGS_MUSIC:

                    Options::MUSIC_ENABLE = !Options::MUSIC_ENABLE;
                    
                    if(Options::MUSIC_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();

                        this->mMusicButton->setCurrentFrameIndex(0);
                    }
                    else
                    {
                        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();

                        this->mMusicButton->setCurrentFrameIndex(3);
                    }

                    AppDelegate::setMusicEnable(Options::MUSIC_ENABLE);

                break;
                case Options::BUTTONS_ID_SETTINGS_SOUND:
        
                    Options::SOUND_ENABLE = !Options::SOUND_ENABLE;
                    
                    if(Options::SOUND_ENABLE)
                    {
                        this->mSoundButton->setCurrentFrameIndex(1);
                    }
                    else
                    {
                        this->mSoundButton->setCurrentFrameIndex(4);
                    }

                    AppDelegate::setSoundEnable(Options::SOUND_ENABLE);

                break;
                case Options::BUTTONS_ID_SETTINGS_CREDITS:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_CREDITS);

                break;
                case Options::BUTTONS_ID_SETTINGS_MORE:
                    
                    AppDelegate::screens->set(0.5, Screen::SCREEN_MORE);
                    
                break;
                case Options::BUTTONS_ID_SETTINGS_LANGUAGE:
                    
                    AppDelegate::screens->set(0.5, Screen::SCREEN_LANGUAGE);
                    
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

void Settings::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);

    this->mLanguage->setScale(this->mLanguageButton->getScaleX());
    this->mLanguage->setCenterPosition(this->mLanguageButton->getCenterX() + this->mLanguageButton->getWidthScaled() / 2 - this->mLanguage->getWidthScaled() / 2, this->mLanguageButton->getCenterY());
}

void Settings::onEnter()
{
    Screen::onEnter();
    
    this->mLanguage->setCurrentFrameIndex(Options::CURRENT_LANGUAGE);

    this->mSoundButton->setCurrentFrameIndex(Options::SOUND_ENABLE ? 1 : 4);
    this->mMusicButton->setCurrentFrameIndex(Options::MUSIC_ENABLE ? 0 : 3);
}

void Settings::onExit()
{
    Screen::onExit();
}

#endif