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

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Mode::~Mode()
{
    this->removeAllChildrenWithCleanup(true);
    
    delete this->spriteBatch;
    
    delete this->mBackground;
    delete this->mBackgroundDecorations[0];
    delete this->mBackgroundDecorations[1];
    
    delete this->mBackButton;
    delete this->mHelpButton;
    delete this->mClassicMode;
    delete this->mArcadeMode;
    delete this->mProgressMode;
    delete this->mAchievementsButton;
    delete this->mLeaderboardButton;
    delete this->mShopButton;
    
    //delete this->mHelpPopup;
    //delete this->mLivesPopup;
    //delete this->mTempPublisherRatingExplain;
    //delete this->mTempPublisherAchievementsExplain;
}

Mode::Mode() :
    spriteBatch(0),
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
	mTempPublisherRatingExplain(0),
	mTempPublisherAchievementsExplain(0)
	{
		spriteBatch = SpriteBatch::create("TextureAtlas2");

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

		this->mClassicMode = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MODE_CLASSIC, this);
		this->mArcadeMode = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MODE_ARCADE, this);
		this->mProgressMode = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MODE_PROGRESS, this);

		this->mAchievementsButton = Button::create(structure4, spriteBatch, Options::BUTTONS_ID_MODE_ACHIEVEMENTS, this);
		this->mLeaderboardButton = Button::create(structure5, spriteBatch, Options::BUTTONS_ID_MODE_LEADERBOARD, this);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
		this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
		this->mHelpButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(65), Options::CAMERA_HEIGHT - Utils::coord(65));
		this->mShopButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(185), Options::CAMERA_HEIGHT - Utils::coord(65));
    
		this->mClassicMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(350));
		this->mArcadeMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(140));
		this->mProgressMode->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(70));
    
		this->mAchievementsButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(300));
		this->mLeaderboardButton->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(300));

		this->mClassicMode->setText(Options::TEXT_MODE_CLASSIC);
		this->mArcadeMode->setText(Options::TEXT_MODE_ARCADE);
		this->mProgressMode->setText(Options::TEXT_MODE_PROGRESS);
    
		this->mBackgroundDecorations[0]->create()->setCenterPosition(Utils::coord(192), Options::CAMERA_HEIGHT - Utils::coord(103));
		this->mBackgroundDecorations[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(155), Utils::coord(138));
    
		//this->mHelpPopup = ModeHelp::create(this);
		//this->mLivesPopup = GetLives::create(this, true);
		//this->mTempPublisherRatingExplain = TempPublisherRatingExplain::create(this);
		//this->mTempPublisherAchievementsExplain = TempPublisherAchievementsExplain::create(this);
	}

Mode* Mode::create()
{
    Mode* screen = new Mode();
    /*screen->autorelease();
    screen->retain();*/
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Mode::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MODE_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);

                break;
                case Options::BUTTONS_ID_MODE_CLASSIC:

                    if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) <= 0)
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
                    
                    if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) <= 0)
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

                    AppDelegate::screens->set(0.5, Screen::SCREEN_LEVELS);

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

#endif