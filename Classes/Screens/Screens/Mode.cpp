#ifndef CONST_MODE
#define CONST_MODE

#include "Mode.h"

#include "Loader.h"
#include "Shop.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Mode::UNLOCK_ACTION = -1;
int Mode::PRICES[2] = {25, 40};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Mode::~Mode()
{
    CC_SAFE_RELEASE(this->mHelpPopup);
    CC_SAFE_RELEASE(this->mLivesPopup);
    CC_SAFE_RELEASE(this->mModesUnlockPopup);
    CC_SAFE_RELEASE(this->mTempPublisherRatingExplain);
    CC_SAFE_RELEASE(this->mTempPublisherAchievementsExplain);
}

Mode::Mode() :
	mBackground(0),
	mBackgroundDecorations(),
	mBackButton(0),
	mHelpButton(0),
	mClassicMode(0),
	mArcadeMode(0),
	mProgressMode(0),
	mAchievementsButton(0),
	mLeaderboardButton(0),
	mShopButton(0),
	mHelpPopup(0),
	mLivesPopup(0),
    mModesUnlockPopup(0),
    mLockes(),
	mTempPublisherRatingExplain(0),
	mTempPublisherAchievementsExplain(0)
	{
		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas2");
		SpriteBatch* mSpriteBatch2 = SpriteBatch::create("TextureAtlas5");

		this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
		this->mBackgroundDecorations[0] = Entity::create("bg_detail_stripe@2x.png", spriteBatch);
		this->mBackgroundDecorations[1] = Entity::create("bg_detail_choose_bird@2x.png", spriteBatch);

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};
		EntityStructure structure2 = {"btn_sprite@2x.png", 1, 1, 162, 324, 162, 162};
		EntityStructure structure3 = {"btn_sprite@2x.png", 1, 1, 324, 324, 162, 162};
		EntityStructure structure4 = {"btn_sfx_mfx_ach_lead_sprite@2x.png", 1, 1, 400, 0, 200, 200};
		EntityStructure structure5 = {"btn_sfx_mfx_ach_lead_sprite@2x.png", 1, 1, 400, 200, 200, 200};

		this->mBackButton = Button::create(structure1, spriteBatch, Options::BUTTONS_ID_MODE_BACK, this);
		this->mHelpButton = Button::create(structure2, spriteBatch, Options::BUTTONS_ID_MODE_HELP, this);
		this->mShopButton = Button::create(structure3, spriteBatch, Options::BUTTONS_ID_MENU_SHOP, this);

		this->addChild(spriteBatch);
		this->addChild(mSpriteBatch2);

		this->mClassicMode = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MODE_CLASSIC, this);
		this->mArcadeMode = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MODE_ARCADE, this);
		this->mProgressMode = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MODE_PROGRESS, this);
        
        
        {
            this->mUnlockStripe = Entity::create("unlock_mode_effect@2x.png", this);
            this->mUnlockStripe->setZOrder(10);
            
            this->mLockes[0] = Entity::create("lock@2x.png", this->mClassicMode);
            this->mLockes[1] = Entity::create("lock@2x.png", this->mArcadeMode);
        }

		this->mAchievementsButton = Button::create(structure4, spriteBatch, Options::BUTTONS_ID_MODE_ACHIEVEMENTS, this);
		this->mLeaderboardButton = Button::create(structure5, spriteBatch, Options::BUTTONS_ID_MODE_LEADERBOARD, this);

		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
		this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
		this->mHelpButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(65), Options::CAMERA_HEIGHT - Utils::coord(140));
		this->mShopButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(185), Options::CAMERA_HEIGHT - Utils::coord(140));

		this->mClassicMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(120));
		this->mArcadeMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(90));
		this->mProgressMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(330));

		this->mAchievementsButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(320));
		this->mLeaderboardButton->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(320));

		this->mClassicMode->setText(Options::TEXT_MODE_CLASSIC);
		this->mArcadeMode->setText(Options::TEXT_MODE_ARCADE);
		this->mProgressMode->setText(Options::TEXT_MODE_PROGRESS);

		this->mBackgroundDecorations[0]->create()->setCenterPosition(Utils::coord(192), Options::CAMERA_HEIGHT - Utils::coord(103));
		this->mBackgroundDecorations[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(155), Utils::coord(138));

		this->mHelpPopup = ModeHelp::create(this);
		this->mLivesPopup = GetLives::create(this, true);
        this->mModesUnlockPopup = UnlockMode::create(this);
		this->mTempPublisherRatingExplain = TempPublisherRatingExplain::create(this);
		this->mTempPublisherAchievementsExplain = TempPublisherAchievementsExplain::create(this);
        
        this->mUnlockAnimationTimeElapsed = 0;
        
        this->mUnlockAnimationRunning = false;
        
        /** PANEL */
        
        this->mGamePanel = Entity::create("shop_panel@2x.png", mSpriteBatch2);
        
		this->mTextBackgrounds[0] = Entity::create("shop_panel_textbox@2x.png", mSpriteBatch2);
		this->mTextBackgrounds[1] = Entity::create("shop_panel_textbox@2x.png", mSpriteBatch2);
		this->mTextBackgrounds[2] = Entity::create("shop_panel_textbox@2x.png", mSpriteBatch2);
		this->mTextBackgrounds[3] = Entity::create("shop_panel_textbox@2x.png", mSpriteBatch2);
        
		this->mTextBackgrounds[1]->setScaleX(0.9);
		this->mTextBackgrounds[2]->setScaleX(1.0);
		this->mTextBackgrounds[3]->setScaleX(0.8);
        
		if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPHONE4 || Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPOD4)
		{
			this->mTextBackgrounds[0]->setScaleX(this->mTextBackgrounds[0]->getScaleX() + 0.2);
			this->mTextBackgrounds[1]->setScaleX(this->mTextBackgrounds[1]->getScaleX() + 0.2);
			this->mTextBackgrounds[2]->setScaleX(this->mTextBackgrounds[2]->getScaleX() + 0.2);
			this->mTextBackgrounds[3]->setScaleX(this->mTextBackgrounds[3]->getScaleX() + 0.2);
		}
        
		EntityStructure structure = {"game_panel_plus@2x.png", 1, 1, 0, 0, 78, 72};
        
		this->mTextPluses[0] = Button::create(structure, mSpriteBatch2, Options::BUTTONS_ID_SHOP_GET_SILVER_COINS, this);
		this->mTextPluses[1] = Button::create(structure, mSpriteBatch2, Options::BUTTONS_ID_SHOP_GET_LIVES, this);
		this->mTextPluses[2] = Button::create(structure, mSpriteBatch2, Options::BUTTONS_ID_SHOP_GET_GOLD_COINS, this);
		this->mTextPluses[3] = Button::create(structure, mSpriteBatch2, Options::BUTTONS_ID_SHOP_GET_KEYS, this);
        
		this->mIcons[0] = Entity::create("coins_silver@2x.png", 5, 4, mSpriteBatch2);
		this->mIcons[1] = Entity::create("coins@2x.png", 5, 4, mSpriteBatch2);
		this->mIcons[2] = Icon8::create("game_panel_goldlife@2x.png", mSpriteBatch2);
		this->mIcons[3] = Icon8::create("popup_key_ico@2x.png", mSpriteBatch2);
        
		Textes textes1 = {"0", Options::FONT, 32, -1};
        
		this->mTextText[0] = Text::create(textes1, this);
		this->mTextText[1] = Text::create(textes1, this);
		this->mTextText[2] = Text::create(textes1, this);
		this->mTextText[3] = Text::create(textes1, this);
        
		this->mGamePanel->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
		this->mTextBackgrounds[0]->create()->setCenterPosition(this->mTextBackgrounds[0]->getWidthScaled() / 2 + Utils::coord(15), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextBackgrounds[1]->create()->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + this->mTextBackgrounds[0]->getWidthScaled() + Utils::coord(25), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextBackgrounds[2]->create()->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + this->mTextBackgrounds[1]->getWidthScaled() + Utils::coord(55), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextBackgrounds[3]->create()->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() + Utils::coord(35), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
		this->mTextBackgrounds[2]->setCenterPosition(this->mTextBackgrounds[2]->getCenterX(), this->mTextBackgrounds[2]->getCenterY());
		this->mTextBackgrounds[3]->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() - Utils::coord(10), this->mTextBackgrounds[3]->getCenterY());

		this->mTextPluses[0]->create()->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + this->mTextBackgrounds[0]->getWidthScaled() / 2, this->mTextBackgrounds[0]->getCenterY());
		this->mTextPluses[2]->create()->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + this->mTextBackgrounds[1]->getWidthScaled() / 2, this->mTextBackgrounds[1]->getCenterY());
		this->mTextPluses[1]->create()->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() / 2, this->mTextBackgrounds[2]->getCenterY());
		this->mTextPluses[3]->create()->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() + this->mTextBackgrounds[3]->getWidthScaled() / 2, this->mTextBackgrounds[3]->getCenterY());
        
		this->mIcons[0]->create()->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() - this->mTextBackgrounds[0]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[0]->getCenterY());
		this->mIcons[1]->create()->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() - this->mTextBackgrounds[1]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[1]->getCenterY());
		this->mIcons[2]->create()->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() - this->mTextBackgrounds[2]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[2]->getCenterY());
		this->mIcons[3]->create()->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() - this->mTextBackgrounds[3]->getWidthScaled() / 2 + Utils::coord(5), this->mTextBackgrounds[3]->getCenterY());
        
        this->mIcons[2]->setCenterPosition(this->mIcons[2]->getCenterX(), this->mIcons[2]->getCenterY() + Utils::coord(2));
        this->mIcons[3]->setCenterPosition(this->mIcons[3]->getCenterX(), this->mIcons[3]->getCenterY() + Utils::coord(2));
        
        this->mTextPluses[0]->setCenterPosition(this->mTextPluses[0]->getCenterX(), this->mTextPluses[0]->getCenterY() + Utils::coord(1));
        this->mTextPluses[1]->setCenterPosition(this->mTextPluses[1]->getCenterX(), this->mTextPluses[1]->getCenterY() + Utils::coord(1));
        this->mTextPluses[2]->setCenterPosition(this->mTextPluses[2]->getCenterX(), this->mTextPluses[2]->getCenterY() + Utils::coord(1));
        this->mTextPluses[3]->setCenterPosition(this->mTextPluses[3]->getCenterX(), this->mTextPluses[3]->getCenterY() + Utils::coord(1));
        
		this->mIcons[0]->setRotation(-45);
		this->mIcons[0]->setScale(0.75);
		this->mIcons[0]->animate(0.05);
        
		this->mIcons[1]->setRotation(-45);
		this->mIcons[1]->setScale(0.75);
		this->mIcons[1]->animate(0.05);
	}

Mode* Mode::create()
{
    Mode* screen = new Mode();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Mode::onTouchButtonsCallback(const int pAction, const int pID)
{
    if(this->mUnlockAnimationRunning) return;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MODE_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);

                break;
                case Options::BUTTONS_ID_MODE_CLASSIC:

                    if(!AppDelegate::isModeUnlocked(0))
                    {
                        UNLOCK_ACTION = 0;
                        
                        this->mModesUnlockPopup->show();
                    }
                    else if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) <= 0)
                    {
                        this->mLivesPopup->show();
                    }
                    else
                    {
                        Loader::ACTION = 0;
                        Loader::T = 1;
                        Loader::TYPE = -1;

                        AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
                    }

                break;
                case Options::BUTTONS_ID_MODE_ARCADE:
                    
                    if(!AppDelegate::isModeUnlocked(1))
                    {
                        UNLOCK_ACTION = 1;
                        
                        this->mModesUnlockPopup->show();
                    }
                    else if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) <= 0)
                    {
                        this->mLivesPopup->show();
                    }
                    else
                    {
                        Loader::ACTION = 1;
                        Loader::T = 2;
                        Loader::TYPE = -1;
                        
                        AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
                    }

                break;
                case Options::BUTTONS_ID_MODE_PROGRESS:

                    Loader::ACTION = 2;
                    Loader::T = 3;
                    Loader::TYPE = -1;

                    AppDelegate::screens->set(0.5, Screen::SCREEN_EPISODES);

                break;
                case Options::BUTTONS_ID_MODE_HELP:

                    this->mHelpPopup->show();

                break;
                case Options::BUTTONS_ID_MODE_ACHIEVEMENTS:

                    this->mTempPublisherAchievementsExplain->show();

                break;
                case Options::BUTTONS_ID_MODE_LEADERBOARD:

                    this->mTempPublisherRatingExplain->show();

                break;
                case Options::BUTTONS_ID_MENU_SHOP:

                    Shop::ACTION = 1;

                    AppDelegate::screens->set(0.5, Screen::SCREEN_SHOP);

                break;
                case Options::BUTTONS_ID_SHOP_GET_SILVER_COINS:
                case Options::BUTTONS_ID_SHOP_GET_GOLD_COINS:
                    
                    Shop::ACTION = 10;
                    
                    AppDelegate::screens->set(0.5, Screen::SCREEN_SHOP);
                    
                break;
                case Options::BUTTONS_ID_SHOP_GET_LIVES:
                    
                    Shop::ACTION = 11;
                    
                    AppDelegate::screens->set(0.5, Screen::SCREEN_SHOP);
                    
                break;
                case Options::BUTTONS_ID_SHOP_GET_KEYS:
                    
                    Shop::ACTION = 12;
                    
                    AppDelegate::screens->set(0.5, Screen::SCREEN_SHOP);
                    
                break;

            }
        break;

        case Options::BUTTONS_ACTION_ONBEGIN:
        break;

        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void Mode::unlock()
{
    if(UNLOCK_ACTION == 0)
    this->mUnlockStripe->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(140));
    else
    this->mUnlockStripe->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(70));
    
    this->mUnlockStripe->setOpacity(255);
    this->mUnlockStripe->setScale(1.0);
    
    this->mUnlockStripe->runAction(CCScaleTo::create(1.0, 1.0, 10.0));
    this->mUnlockStripe->runAction(CCFadeTo::create(2.0, 0));
    
    this->mLockes[UNLOCK_ACTION]->runAction(CCScaleTo::create(1.0, 3.0));
    this->mLockes[UNLOCK_ACTION]->runAction(CCFadeTo::create(1.0, 0));
    
    this->mUnlockAnimationRunning = true;
    
    AppDelegate::removeCoins(PRICES[UNLOCK_ACTION], Options::SAVE_DATA_COINS_TYPE_KEYS);
    AppDelegate::setModeUnlocked(UNLOCK_ACTION);
    
    if(Options::SOUND_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LEVEL_UNLOCK);
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Mode::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    if(this->mUnlockAnimationRunning)
    {
        this->mUnlockAnimationTimeElapsed += pDeltaTime;
        
        if(this->mUnlockAnimationTimeElapsed >= 2.0)
        {
            this->mUnlockStripe->destroy();
            this->mLockes[UNLOCK_ACTION]->destroy();
            
            this->mUnlockAnimationTimeElapsed = 0;
            this->mUnlockAnimationRunning = false;
        }
    }
    
    if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) <= 0)
    {
        long time = (AppDelegate::getLiveNearestReleaseTime(0) + (30 * 60 * 1000) - Utils::millisecondNow());

        int minutes = floor((time / 1000) / 60);
        long seconds = (time / 1000) - (minutes * 60);

        char text[256];

        sprintf(text, "%d:%lu", minutes, seconds);

        if(minutes < 10)
        {
            sprintf(text, "0%d:%lu", minutes, seconds);
        }
        if(seconds < 10)
        {
            sprintf(text, "%d:0%lu", minutes, seconds);
        }
        if(minutes < 10 && seconds < 10)
        {
            sprintf(text, "0%d:0%lu", minutes, seconds);
        }

        this->mTextText[2]->setString(text);
        this->mTextText[2]->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() / 2 - this->mTextText[2]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[2]->getCenterY());
    }
}

void Mode::onEnter()
{
    Screen::onEnter();
    
    if(!AppDelegate::isModeUnlocked(0) && !this->mLockes[0]->isVisible())
    {
        this->mLockes[0]->create()->setCenterPosition(Utils::coord(10), this->mClassicMode->getHeight() / 2);
        this->mLockes[0]->setOpacity(255);
        this->mLockes[0]->setScale(1);
    }
    
    if(!AppDelegate::isModeUnlocked(1) && !this->mLockes[1]->isVisible())
    {
        this->mLockes[1]->create()->setCenterPosition(Utils::coord(10), this->mArcadeMode->getHeight() / 2);
        this->mLockes[1]->setOpacity(255);
        this->mLockes[1]->setScale(1);
    }
    
    this->mPanelItems[0] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_SILVER);
    this->mPanelItems[1] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_GOLD);
    this->mPanelItems[2] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES);
    this->mPanelItems[3] = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_KEYS);
    
    this->mTextText[0]->setString(Utils::intToString(this->mPanelItems[0]).c_str());
    this->mTextText[0]->setCenterPosition(this->mTextBackgrounds[0]->getCenterX() + this->mTextBackgrounds[0]->getWidthScaled() / 2 - this->mTextText[0]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[0]->getCenterY());
    
    this->mTextText[1]->setString(Utils::intToString(this->mPanelItems[1]).c_str());
    this->mTextText[1]->setCenterPosition(this->mTextBackgrounds[1]->getCenterX() + this->mTextBackgrounds[1]->getWidthScaled() / 2 - this->mTextText[1]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[1]->getCenterY());
    
    this->mTextText[2]->setString(Utils::intToString(this->mPanelItems[2]).c_str());
    this->mTextText[2]->setCenterPosition(this->mTextBackgrounds[2]->getCenterX() + this->mTextBackgrounds[2]->getWidthScaled() / 2 - this->mTextText[2]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[2]->getCenterY());
    
    this->mTextText[3]->setString(Utils::intToString(this->mPanelItems[3]).c_str());
    this->mTextText[3]->setCenterPosition(this->mTextBackgrounds[3]->getCenterX() + this->mTextBackgrounds[3]->getWidthScaled() / 2 - this->mTextText[3]->getWidth() / 2 - Utils::coord(20), this->mTextBackgrounds[3]->getCenterY());

}

#endif