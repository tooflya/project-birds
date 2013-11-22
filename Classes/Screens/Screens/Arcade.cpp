#ifndef CONST_ARCADE
#define CONST_ARCADE

#include "Arcade.h"

#include "Loader.h"

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

Arcade::~Arcade()
{
}

Arcade::Arcade() :
    Game(),
	mTimeIcon(0),
	mCountText(0),
	mBestCountText(0),
	mTimeText(0),
	mGoldLifesCount(0)
    {
        Loader::TYPE = 2;
    
        this->mEventLayer = CCLayer::create();
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas3.plist");

		SpriteBatch* spriteBatch0 = SpriteBatch::create("TextureAtlas16");
        SpriteBatch* spriteBatch1 = SpriteBatch::create("TextureAtlas3");
        SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas7");
        SpriteBatch* spriteBatch3 = SpriteBatch::create("TextureAtlas8");
        SpriteBatch* spriteBatch4 = SpriteBatch::create("TextureAtlas10");
        SpriteBatch* spriteBatch5 = SpriteBatch::create("TextureAtlas11");
        SpriteBatch* spriteBatch6 = SpriteBatch::create("TextureAtlas6");
        SpriteBatch* spriteBatch7 = SpriteBatch::create("TextureAtlas14");
        SpriteBatch* spriteBatch8 = SpriteBatch::create("TextureAtlas6");
        SpriteBatch* spriteBatch9 = SpriteBatch::create("TextureAtlas12");
        SpriteBatch* spriteBatch17 = SpriteBatch::create("TextureAtlas17");
        this->spriteBatch99 = SpriteBatch::create("TextureAtlas9");
        this->spriteBatch99->retain();

		this->mGameLayer->addChild(spriteBatch0);
        this->mGameLayer->addChild(spriteBatch6);
        
        this->e2 = Effect::create();
        this->mGameLayer->addChild(this->e2);
        
        this->mGameLayer->addChild(spriteBatch7);
        this->mGameLayer->addChild(spriteBatch1);
        this->mGameLayer->addChild(spriteBatch2);
        this->mGameLayer->addChild(spriteBatch3);
        this->mGameLayer->addChild(this->spriteBatch99);
        this->mGameLayer->addChild(spriteBatch4);
        this->mGameLayer->addChild(spriteBatch5);
        this->mGameLayer->addChild(spriteBatch9);
        this->mMenuLayer->addChild(spriteBatch8);
        this->mMenuLayer->addChild(spriteBatch17);

        this->mBackground = Entity::create("temp_level_bg@2x.png", spriteBatch0);
        this->mTimeIcon = Clock::create(this->mEventLayer);
        this->mStars = EntityManager::create(1000, StarParticle::create(), spriteBatch2);
        
        #if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
        if(Options::DEVICE_TYPE != Options::DEVICE_TYPE_IPOD4)
        {
            this->mBackgroundLights[0] = Entity::create("bg_light_main@2x.png", spriteBatch6);
            this->mBackgroundLights[0]->setAnchorPoint(ccp(0.0, 0.5));
            for(int i = 1; i < 4; i++)
            {
                this->mBackgroundLights[i] = Entity::create("bg_light_1.png", spriteBatch6);
                this->mBackgroundLights[i]->setAnchorPoint(ccp(0.0, 0.5));
            }
            for(int i = 4; i < 7; i++)
            {
                this->mBackgroundLights[i] = Entity::create("bg_light_1.png", spriteBatch6);
                this->mBackgroundLights[i]->setAnchorPoint(ccp(0.0, 0.5));
            }
        }
        #endif
        
        this->mGamePanel = Entity::create("game_panel@2x.png", spriteBatch8);
        this->mTextAreas[0] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextAreas[1] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextAreas[2] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextAreas[3] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextIcons[0] = Icon8::create("game_panel_counter@2x.png", 7, 1, spriteBatch8);
		this->mTextIcons[1] = Icon8::create("game_panel_counter_best@2x.png", spriteBatch8);
        this->mTextIcons[2] = Entity::create("game_panel_time@2x.png", spriteBatch8);
		this->mTextIcons[3] = Icon8::create("game_panel_goldlife@2x.png", spriteBatch8);

		EntityStructure structure1 = {"game_panel_plus@2x.png", 1, 1, 0, 0, 78, 72};

        this->mGoldLifeButton = Button::create(structure1, spriteBatch8, Options::BUTTONS_ID_GAME_PAUSE, this);
        
        this->mGamePanel->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextAreas[0]->create()->setCenterPosition(this->mTextAreas[0]->getWidth() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextAreas[1]->create()->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidth() + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextAreas[2]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidth() + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextAreas[3]->create()->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidth() + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->mTextIcons[0]->create()->setCenterPosition(this->mTextAreas[0]->getCenterX() - this->mTextAreas[0]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextIcons[1]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() - this->mTextAreas[1]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextIcons[2]->create()->setCenterPosition(this->mTextAreas[2]->getCenterX() - this->mTextAreas[2]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextIcons[3]->create()->setCenterPosition(this->mTextAreas[3]->getCenterX() - this->mTextAreas[3]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->mTextIcons[3]->setCenterPosition(this->mTextIcons[3]->getCenterX(), this->mTextIcons[3]->getCenterY() + Utils::coord(3));
        
        this->mGoldLifeButton->create()->setCenterPosition(this->mTextAreas[3]->getCenterX() + this->mTextAreas[3]->getWidth() / 2 - this->mGoldLifeButton->getWidth() / 4, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);

		Textes textes1 = {"0", Options::FONT, 32, -1};

        this->mCountText = Text::create(textes1, this);
        this->mBestCountText = Text::create(Options::TEXT_GAME_BEST, this);
        this->mTimeText = Text::create(textes1, this);
        this->mGoldLifesCount = Text::create(textes1, this);

        this->mGameStartText = Text::create(Options::TEXT_GAME_START_STRING_1, this);
        
		EntityStructure structure2 = {"game_panel_pause@2x.png", 1, 1, 0, 0, 78, 72};

        this->mPauseButton = Button::create(structure2, spriteBatch8, Options::BUTTONS_ID_GAME_PAUSE, this);
        
        this->mDust = EntityManager::create(100, Dust::create(), spriteBatch2);
        this->mMarks = EntityManager::create(300, Mark::create(), spriteBatch2);
        this->mFeathers = EntityManager::create(300, Feather::create(), spriteBatch2);
        this->mBirds = EntityManager::create(20, Bird::create(false), spriteBatch4);
        this->mSpecialBirds = EntityManager::create(10, SpecialBird::create(), spriteBatch5);
        this->mExplosions = EntityManager::create(10, Explosion::create(), spriteBatch2);
        this->mExplosionsBasic = EntityManager::create(10, ExplosionBasic::create(), spriteBatch2);
        this->mCoins = EntityManager::create(50, AnimatedCoin::create("coins@2x.png", 0.7), spriteBatch2);
        this->mSilverCoins = EntityManager::create(50, AnimatedCoin::create("coins_silver@2x.png", 0.7), spriteBatch2);
        this->mArrows = EntityManager::create(5, Entity::create("bomb_arrow.png"), spriteBatch2);
        this->mPredictionIcons = EntityManager::create(5, Entity::create("bomb_ico.png"), spriteBatch2);
        this->mZombieExplosions = EntityManager::create(300, ZombieExplosion::create(), spriteBatch7);
        this->mGeneralExplosions = EntityManager::create(100, GeneralExplosion::create(), spriteBatch9);
        this->mRobotParts = EntityManager::create(8, RobotoPart::create(0), spriteBatch7);
        this->mGunLaser = Entity::create("gun_laser.png", 4, 1, spriteBatch7);
        this->mGun = RobotoGun::create(spriteBatch7);
        this->mKeys = EntityManager::create(5, KeyDisplay::create(), spriteBatch4);
        this->mKeysLights = EntityManager::create(10, Entity::create("get_coins_light@2x.png"), spriteBatch99);
        
        this->mGunLaser->setAnchorPoint(ccp(0.5, 1));
        this->mGunLaser->animate(0.04);
        
        this->e5 = Entity::create("board_migalka@2x.png", spriteBatch17);
        
        #if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID && CC_TARGET_PLATFORM != CC_PLATFORM_MAC
        if(Options::DEVICE_TYPE != Options::DEVICE_TYPE_IPOD4)
        {
            this->mBackgroundLights[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(480), Options::CAMERA_CENTER_Y - Utils::coord(50));
            
            for(int i = 1; i < 4; i++)
            {
                this->mBackgroundLights[i]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(480), Options::CAMERA_CENTER_Y + Utils::coord(50) * (i - 1));
            }
            for(int i = 1; i < 4; i++)
            {
                this->mBackgroundLights[i + 3]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(480), Options::CAMERA_CENTER_Y + Utils::coord(50) * (i - 1));
            }
        }
        #endif

        this->mEventPanel = EventPanel::create(this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        ((Entity*) this->mEventPanel)->create()->setCenterPosition(Options::CAMERA_CENTER_X, -Utils::coord(100));
        
        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(32), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->e1 = Entity::create("freeze_bg.png", spriteBatch7);
        
        this->mRains = EntityManager::create(300, Rain::create(), spriteBatch7);
        this->mRainsCircles = EntityManager::create(300, RainCircle::create(), spriteBatch7);

        this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mTimeText->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidth() / 2 - this->mTimeText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);

        this->mPausePopup = Pause::create(this);
        this->mEndScreen = End::create(Splash::TYPE_ARCADE, this);
        this->mGetLivesPopup = GetLives::create(this, false);

        this->mAlgorithmBirdsRemainig = 6;
        this->mAlgorithmBirdsTime = 1.5;

        this->mAlgorithmBirdsTime1 = 2.0;
        this->mAlgorithmBirdsTime2 = 7.0;

        this->addChild(this->mEventLayer);
        
        if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPAD_RETINA)
        {
            this->mBackground->setScale(1.185);
        }
    }

Arcade* Arcade::create()
{
    Arcade* screen = new Arcade();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Arcade::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_GAME_PAUSE:

                    this->mPausePopup->show();

                break;
                case Options::BUTTONS_ID_GAME_GET_LIVES:
                    
                    this->mGetLivesPopup->show();
                    
                break;
                case Options::BUTTONS_ID_GAME_RESTART:

                    // TODO: Restart level.

                break;
            }
        break;

        case Options::BUTTONS_ACTION_ONBEGIN:
        break;

        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void Arcade::startGame()
{
    this->mGoldLifesCount->setString(ccsf("%d", AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES)));
    
    if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) <= 0)
    {
        this->mGetLivesPopup->show();
        
        return;
    }
    
    Game::startGame();

    this->mTimeIcon->start();
    
    Game::HEALTH = 1;
}

// ===========================================================
// Override Methods
// ===========================================================

void Arcade::update(float pDeltaTime)
{
    Game::update(pDeltaTime);
    
    if(this->mPause)
    {
        return;
    }

    if(this->mGamePaused)
    {
        if(!this->mEndScreen->isShowed())
        {
            this->startGame();
        }
    }
    else if(this->mGameRunning && !this->mGamePaused)
    {
        this->mTimeIcon->updateTime(pDeltaTime);

        if(this->mTimeIcon->getTimeElapsed() >= 60.0)
        {
            this->onGameEnd();
        }
    }
        
    int timer = 60.0 - this->mTimeIcon->getTimeElapsed();

    this->mTimeText->setString(((timer >= 10 ? "0:" : "0:0") + Utils::intToString(timer)).c_str());
    this->mTimeText->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidth() / 2 - this->mTimeText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mBestCountText->setString((Options::TEXT_GAME_BEST.string + Utils::intToString(BEST_COUNT)).c_str());
    this->mBestCountText->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidth() / 2 - this->mBestCountText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mCountText->setString(Utils::intToString(CURRENT_COUNT).c_str());
    this->mCountText->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidth() / 2 - this->mCountText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mGoldLifesCount->setCenterPosition(this->mTextAreas[3]->getCenterX() + this->mTextAreas[3]->getWidth() / 2 - this->mGoldLifesCount->getWidth() / 2 - Utils::coord(37), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
}

void Arcade::onGameStarted()
{
    this->mEventPanel->setEvent(30)->show();

    BEST_COUNT = AppDelegate::getBestResult(1);
}

void Arcade::onGameEnd()
{
    this->mGamePaused = true;

    this->mEndScreen->show();

    if(BEST_COUNT > AppDelegate::getBestResult(1))
    {
        AppDelegate::setBestResult(BEST_COUNT, 1);
    }
    else
    {
        AppDelegate::removeCoins(1, Options::SAVE_DATA_COINS_TYPE_LIVES);
    }
}

void Arcade::onEnter()
{
    Game::onEnter();

    this->mTimeText->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidth() / 2 - this->mTimeText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);

    BEST_COUNT = AppDelegate::getBestResult(1);

    this->mTimeIcon->start();
    
    GAME_TYPE = GAME_TYPE_ARCADE;
}

void Arcade::onExit()
{
    Game::onExit();
}

void Arcade::pause()
{
    Game::pause();
    
    this->mTimeIcon->pause();
}

void Arcade::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    if(this->mGetLivesPopup->getParent())
    {
        this->mGetLivesPopup->hide();
    }
    else
    {
        if(this->mPausePopup->getParent())
        {
            this->mPausePopup->hide();
        }
        else
        {
            this->mPausePopup->show();
        }
    }
}

#endif