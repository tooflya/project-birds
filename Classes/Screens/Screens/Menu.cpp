#ifndef CONST_MENU
#define CONST_MENU

#include "Menu.h"

#include "Shop.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Menu* Menu::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Menu::~Menu()
{
    this->mRatePopup->release();
    this->mMapPopup->release();
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    this->mExitPopup->release();
    
    #endif
}

Menu::Menu()
{
    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas2.png");

    this->mBackground = Entity::create("main_menu_bg@2x.png", spriteBatch);
    this->mPlayDecoration = Entity::create("main_menu_btn_bg_play@2x.png", spriteBatch);
    this->mPlayButton = PlayButton::create("play_btn_animation@2x.png", 6, 2, spriteBatch, Options::BUTTONS_ID_MENU_PLAY, onTouchButtonsCallback);
    this->mShopButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 324, 0, 162, 162}, spriteBatch, Options::BUTTONS_ID_MENU_SHOP, onTouchButtonsCallback);
    this->mTwitterButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 0, 0, 162, 162}, spriteBatch, Options::BUTTONS_ID_MENU_TWITTER, onTouchButtonsCallback);
    this->mFacebookButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 0, 162, 162, 162}, spriteBatch, Options::BUTTONS_ID_MENU_FACEBOOK, onTouchButtonsCallback);
    this->mVkButton = Button::create("vk@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MENU_VK, onTouchButtonsCallback);
    this->mSettingsButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 0, 324, 162, 162}, spriteBatch, Options::BUTTONS_ID_MENU_SETTINGS, onTouchButtonsCallback);
    
    this->addChild(spriteBatch);

    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    this->mExitPopup = new Exit(this);

    #endif

    this->mRatePopup = PleaseRate::create(this);
    this->mMapPopup = Map::create(this);

    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mShopButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(270));
    this->mSettingsButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
    this->mTwitterButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(270), Utils::coord(100));
    this->mFacebookButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));
    this->mVkButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));
    this->mPlayDecoration->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(20), Options::CAMERA_CENTER_Y - Utils::coord(80));
    this->mPlayButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(20), Options::CAMERA_CENTER_Y - Utils::coord(80));
    
    this->mPlayDecoration->setColor(ccc3(255.0, 0.0, 0.0));
    
    this->mPlayDecorationColorUpdateTimeElapsed = 0;

    SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Options::MUSIC_1, true); 

    if(!Options::MUSIC_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    }
    
    m_Instance = this;
}

Menu* Menu::create()
{
    Menu* screen = new Menu();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Menu::onTouchButtonsCallback(const int pAction, const int pID)
{
    Menu* pSender = static_cast<Menu*>(Menu::m_Instance);

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MENU_SHOP:

                    Shop::ACTION = 0;
                    
                    AppDelegate::screens->set(0.5, Screen::SCREEN_SHOP);

                break;
                case Options::BUTTONS_ID_MENU_PLAY:
                    pSender->mMapPopup->show();
                    //AppDelegate::screens->set(0.5, Screen::SCREEN_MODE);

                break;
                case Options::BUTTONS_ID_MENU_SETTINGS:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);

                break;
                case Options::BUTTONS_ID_MENU_TWITTER:

                    // TODO: Call JNI

                break;
                case Options::BUTTONS_ID_MENU_FACEBOOK:

                    // TODO: Call JNI

                break;
                case Options::BUTTONS_ID_MENU_VK:
                    
                    // TODO: Call JNI
                    
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

void Menu::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    this->mPlayDecoration->setRotation(this->mPlayDecoration->getRotation() + 1.0);

    this->mPlayDecorationColorUpdateTimeElapsed += pDeltaTime;

    if(this->mPlayDecorationColorUpdateTimeElapsed >= 1.0)
    {
        this->mPlayDecorationColorUpdateTimeElapsed = 0;
    }
}

void Menu::onEnter()
{
    Screen::onEnter();
    
    if(Options::CURRENT_LANGUAGE == 1)
    {
        this->mVkButton->setVisible(true);
        this->mFacebookButton->setVisible(false);
    }
    else
    {
        this->mVkButton->setVisible(false);
        this->mFacebookButton->setVisible(true);
    }
}

void Menu::onExit()
{
    Screen::onExit();
}

void Menu::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();

    if(!AppDelegate::isRate() && AppDelegate::IS_ALREADY_PLAYED)
    {
        this->mRatePopup->show();

        AppDelegate::IS_ALREADY_PLAYED = false;
    }

    this->mMapPopup->show();
}

void Menu::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

#endif