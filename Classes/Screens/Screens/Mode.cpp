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

Mode* Mode::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Mode::~Mode()
{
    this->mHelpPopup->release();
    this->mLivesPopup->release();
    this->mTempPublisherRatingExplain->release();
    this->mTempPublisherAchievementsExplain->release();
}

Mode::Mode()
{
    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas2.png");

    this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
    this->mBackgroundDecorations[0] = Entity::create("bg_detail_stripe@2x.png", spriteBatch);
    this->mBackgroundDecorations[1] = Entity::create("bg_detail_choose_bird@2x.png", spriteBatch);

    this->mBackButton = Button::create((EntityStructure){"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, spriteBatch, Options::BUTTONS_ID_MODE_BACK, this);
    this->mHelpButton = Button::create((EntityStructure){"btn_sprite@2x.png", 1, 1, 162, 324, 162, 162}, spriteBatch, Options::BUTTONS_ID_MODE_HELP, this);
    this->mShopButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 324, 324, 162, 162}, spriteBatch, Options::BUTTONS_ID_MENU_SHOP, this);

    this->addChild(spriteBatch);

    this->mClassicMode = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MODE_CLASSIC, this);
    this->mArcadeMode = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MODE_ARCADE, this);
    this->mProgressMode = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch, Options::BUTTONS_ID_MODE_PROGRESS, this);

    this->mAchievementsButton = Button::create((EntityStructure){"btn_sfx_mfx_ach_lead_sprite@2x.png", 1, 1, 400, 0, 200, 200}, spriteBatch, Options::BUTTONS_ID_MODE_ACHIEVEMENTS, this);
    this->mLeaderboardButton = Button::create((EntityStructure){"btn_sfx_mfx_ach_lead_sprite@2x.png", 1, 1, 400, 200, 200, 200}, spriteBatch, Options::BUTTONS_ID_MODE_LEADERBOARD, this);
    
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
    
    this->mHelpPopup = ModeHelp::create(this);
    this->mLivesPopup = GetLives::create(this);
    this->mTempPublisherRatingExplain = TempPublisherRatingExplain::create(this);
    this->mTempPublisherAchievementsExplain = TempPublisherAchievementsExplain::create(this);

    m_Instance = this;
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
    Mode* pSender = static_cast<Mode*>(Mode::m_Instance);

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
                        
                        AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
                    }

                break;
                case Options::BUTTONS_ID_MODE_PROGRESS:

                    Loader::ACTION = 2;

                    AppDelegate::screens->set(0.5, Screen::SCREEN_LEVELS);

                break;
                case Options::BUTTONS_ID_MODE_HELP:

                    pSender->mHelpPopup->show();

                break;
                case Options::BUTTONS_ID_MODE_ACHIEVEMENTS:

                    pSender->mTempPublisherAchievementsExplain->show();

                break;
                case Options::BUTTONS_ID_MODE_LEADERBOARD:

                    pSender->mTempPublisherRatingExplain->show();

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