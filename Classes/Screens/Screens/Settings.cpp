#ifndef CONST_SETTINGS
#define CONST_SETTINGS

#include "Settings.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Settings* Settings::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Settings::~Settings()
{
}

Settings::Settings()
{
    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas2.png");

    this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
    this->mBackgroundDecorations[0] = Entity::create("bg_detail_stripe@2x.png", spriteBatch);
    this->mBackgroundDecorations[1] = Entity::create("bg_detail_settings@2x.png", spriteBatch);

    this->addChild(spriteBatch);

    this->mBackButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, spriteBatch, Options::BUTTONS_ID_SETTINGS_BACK, onTouchButtonsCallback);
    this->mCreditsButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_SETTINGS_CREDITS, onTouchButtonsCallback);
    this->mProgressButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_SETTINGS_RATE, onTouchButtonsCallback);
    this->mMoreButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_SETTINGS_MORE, onTouchButtonsCallback);
    this->mLanguageButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_SETTINGS_LANGUAGE, onTouchButtonsCallback);
    this->mSoundButton = Button::create("btn_sfx_mfx_ach_lead_sprite@2x.png", 3, 2, spriteBatch, Options::BUTTONS_ID_SETTINGS_SOUND, onTouchButtonsCallback);
    this->mMusicButton = Button::create("btn_sfx_mfx_ach_lead_sprite@2x.png", 3, 2, spriteBatch, Options::BUTTONS_ID_SETTINGS_MUSIC, onTouchButtonsCallback);
    
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
    
    m_Instance = this;
}

Settings* Settings::create()
{
    Settings* screen = new Settings();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Settings::onTouchButtonsCallback(const int pAction, const int pID)
{
    Settings* pSender = (Settings*) Settings::m_Instance;

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

                        pSender->mMusicButton->setCurrentFrameIndex(0);
                    }
                    else
                    {
                        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();

                        pSender->mMusicButton->setCurrentFrameIndex(3);
                    }

                    AppDelegate::setMusicEnable(Options::MUSIC_ENABLE);

                break;
                case Options::BUTTONS_ID_SETTINGS_SOUND:
        
                    Options::SOUND_ENABLE = !Options::SOUND_ENABLE;
                    
                    if(Options::SOUND_ENABLE)
                    {
                        pSender->mSoundButton->setCurrentFrameIndex(1);
                    }
                    else
                    {
                        pSender->mSoundButton->setCurrentFrameIndex(4);
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