#ifndef CONST_MENU
#define CONST_MENU

#include "Menu.h"

#include "Shop.h"
#include "Settings.h"
#include "Mode.h"

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

Menu::~Menu()
{
    CC_SAFE_RELEASE(this->mRatePopup);
    CC_SAFE_RELEASE(this->mMapPopup);
	CC_SAFE_RELEASE(this->mMapDescription);
    CC_SAFE_RELEASE(this->mTempPublisherInAppExplainPopup);
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    
    CC_SAFE_RELEASE(this->mExitPopup);
    
    #endif
}

Menu::Menu() :
	mBackground(0),
	mPlayDecoration(),
	mPlayButton(0),
	mShopButton(0),
	mTwitterButton(0),
	mFacebookButton(0),
	mVkButton(0),
	mSettingsButton(0),
	mExitPopup(0),
	mRatePopup(0),
    mMapDescription(0),
	mTempPublisherInAppExplainPopup(0),
	mMapPopup(0),
    mTutorial(0),
	mPlayDecorationColorUpdateTimeElapsed(0)
	{
		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas2");

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 324, 0, 162, 162};
		EntityStructure structure2 = {"btn_sprite@2x.png", 1, 1, 0, 0, 162, 162};
		EntityStructure structure3 = {"btn_sprite@2x.png", 1, 1, 0, 162, 162, 162};
		EntityStructure structure4 = {"btn_sprite@2x.png", 1, 1, 0, 324, 162, 162};

		this->mBackground = Entity::create("main_menu_bg@2x.png", spriteBatch);
		this->mPlayDecoration[0] = Entity::create("main_menu_btn_bg_play@2x.png", spriteBatch);
		this->mPlayDecoration[1] = Entity::create("main_menu_btn_bg_play@2x.png", spriteBatch);
		this->mPlayButton = PlayButton::create("play_btn_animation@2x.png", 6, 2, spriteBatch, Options::BUTTONS_ID_MENU_PLAY, this);
		this->mShopButton = Button::create(structure1, spriteBatch, Options::BUTTONS_ID_MENU_SHOP, this);
		this->mTwitterButton = Button::create(structure2, spriteBatch, Options::BUTTONS_ID_MENU_TWITTER, this);
		this->mFacebookButton = Button::create(structure3, spriteBatch, Options::BUTTONS_ID_MENU_FACEBOOK, this);
		this->mVkButton = Button::create("vk@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MENU_VK, this);
		this->mSettingsButton = Button::create(structure4, spriteBatch, Options::BUTTONS_ID_MENU_SETTINGS, this);
    
		this->addChild(spriteBatch);
    
		ccBlendFunc bf = {GL_ONE, GL_ZERO};
		this->mBackground->setBlendFunc(bf);

		#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

		this->mExitPopup = new Exit(this);

		#endif

		this->mRatePopup = PleaseRate::create(this);
		this->mMapPopup = Map::create(this);
        this->mMapDescription = MapDescription::create(this);
		this->mTempPublisherInAppExplainPopup = TempPublisherInAppExplain::create(this);

		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
		this->mShopButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(270));
		this->mSettingsButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
		this->mTwitterButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(270), Utils::coord(100));
		this->mFacebookButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));
		this->mVkButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));
		this->mPlayDecoration[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(5), Options::CAMERA_CENTER_Y - Utils::coord(80));
		this->mPlayDecoration[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(5), Options::CAMERA_CENTER_Y - Utils::coord(80));
		this->mPlayButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(20), Options::CAMERA_CENTER_Y - Utils::coord(80));
    
		this->mPlayDecoration[0]->setColor(ccc3(255.0, 0.0, 0.0));
		this->mPlayDecoration[1]->setColor(ccc3(255.0, 0.0, 0.0));
    
		this->mPlayDecoration[1]->setScale(0.9);
    
		this->mPlayDecorationColorUpdateTimeElapsed = 0;

		SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Options::MUSIC_1, true);

		if(!Options::MUSIC_ENABLE)
		{
			SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		}
        
        /** TUTORIAL **/
        
        /*this->mTutorial = Entity::create("tutorial.png", this);
        this->mTutorial->setZOrder(10);
        this->mTutorial->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mTutorial->setRotation(-45);
        this->mTutorial->setScale(0.5);
         this->mTutorial->setCenterPosition(this->mShopButton->getCenterX() + Utils::coord(40), this->mShopButton->getCenterY() - Utils::coord(50));*/
        
        if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPAD_RETINA)
        {
            this->mBackground->setScale(1.185);
        }
        
        AppDelegate::clearCache();
	}

Menu* Menu::create()
{
    Menu* screen = new Menu();
    screen->autorelease();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Menu::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MENU_SHOP:

                    Shop::ACTION = 0;
                    
                    AppDelegate::screens->set(Shop::create());

                break;
                case Options::BUTTONS_ID_MENU_PLAY:
                    
                    AppDelegate::screens->set(Mode::create());

                break;
                case Options::BUTTONS_ID_MENU_SETTINGS:
                    
                    AppDelegate::screens->set(Settings::create());

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
    
    this->mPlayDecoration[0]->setRotation(this->mPlayDecoration[0]->getRotation() + 0.5);
    this->mPlayDecoration[1]->setRotation(this->mPlayDecoration[1]->getRotation() - 0.5);

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
    
    this->onShow();
}

void Menu::onShow()
{
    int dn = Utils::millisecondNow() / 1000 / 86400000;
    int dl = AppDelegate::getLastVisitDaysCount();
    
    if(!AppDelegate::isRate() && AppDelegate::IS_ALREADY_PLAYED)
    {
        this->mRatePopup->show();
        
        AppDelegate::IS_ALREADY_PLAYED = false;
    } else if(dn - dl > 0 && dl != 0)
    {
        this->mMapPopup->day = (dn - dl) > 5 ? 1 : (dn - dl);
        this->mMapPopup->show();
    } else if(!AppDelegate::tempPublisherInAppInformationShowed())
    {
        #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        this->mTempPublisherInAppExplainPopup->show();
        #endif
        
        CCUserDefault::sharedUserDefault()->setBoolForKey("temp_inapp_inf", true);
        CCUserDefault::sharedUserDefault()->flush();
    }
}

void Menu::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
void Menu::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    if(this->mMapPopup->getParent())
    {
        if(this->mMapDescription->getParent())
        {
            this->mMapDescription->hide();
        }
    }
    else if(this->mRatePopup->getParent())
    {
        this->mRatePopup->hide();
    }
    else
    {
        if(this->mExitPopup->getParent())
        {
            this->mExitPopup->hide();
        }
        else
        {
            this->mExitPopup->show();
        }
    }
}
#endif

#endif