#ifndef CONST_ARCADE
#define CONST_ARCADE

#include "Arcade.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Arcade* Arcade::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Arcade::~Arcade()
{
    this->mStars->release();
}

Arcade::Arcade() :
    Game()
    {
        this->mEventLayer = CCLayer::create();
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas3.plist");
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas3.plist");
        
        CCSpriteBatchNode* spriteBatch1 = CCSpriteBatchNode::create("TextureAtlas3.pvr.ccz");
        CCSpriteBatchNode* spriteBatch2 = CCSpriteBatchNode::create("TextureAtlas7.pvr.ccz");
        CCSpriteBatchNode* spriteBatch3 = CCSpriteBatchNode::create("TextureAtlas8.pvr.ccz");
        CCSpriteBatchNode* spriteBatch4 = CCSpriteBatchNode::create("TextureAtlas10.pvr.ccz");
        CCSpriteBatchNode* spriteBatch5 = CCSpriteBatchNode::create("TextureAtlas11.pvr.ccz");
        CCSpriteBatchNode* spriteBatch6 = CCSpriteBatchNode::create("TextureAtlas6.pvr.ccz");
        
        this->addChild(spriteBatch6);
        this->addChild(spriteBatch1);
        this->addChild(spriteBatch2);
        this->addChild(spriteBatch3);
        this->addChild(spriteBatch4);
        this->addChild(spriteBatch5);

        this->mBackground = Entity::create("temp_level_bg@2x.png", spriteBatch6);
        this->mCountIcon = Entity::create("game_gui_count_pic@2x.png", spriteBatch2);
        this->mTimeIcon = Clock::create(this->mEventLayer);
        this->mStars = EntityManager::create(1000, StarParticle::create(), spriteBatch2);

        this->mCountText = Text::create((Textes) {"0", Options::FONT, 80, -1}, this);
        this->mBestCountText = Text::create(Options::TEXT_GAME_BEST, this);
        this->mTimeText[0] = Text::create(Options::TEXT_GAME_ARCADE_TIME_REMAINING, this->mEventLayer);
        this->mTimeText[1] = Text::create((Textes) {"0:00", Options::FONT, 64, -1}, this->mEventLayer);
        this->mTimeText[2] = Text::create((Textes) {".0000", Options::FONT, 28, -1}, this->mEventLayer);

        this->mGameStartText = Text::create(Options::TEXT_GAME_START_STRING_1, this);

        this->mPauseButton = Button::create((EntityStructure) {"game_gui_btn_sprite@2x.png", 1, 1, 116, 0, 116, 78}, spriteBatch2, Options::BUTTONS_ID_GAME_PAUSE, onTouchButtonsCallback);
        
        this->mDust = EntityManager::create(100, Dust::create(), spriteBatch2);
        this->mMarks = EntityManager::create(200, Mark::create(), spriteBatch2);
        this->mFeathers = EntityManager::create(100, Feather::create(), spriteBatch2);
        this->mBirds = EntityManager::create(20, Bird::create(), spriteBatch4);
        this->mSpecialBirds = EntityManager::create(10, SpecialBird::create(), spriteBatch5);
        this->mExplosions = EntityManager::create(10, Explosion::create(), spriteBatch2);
        this->mExplosionsBasic = EntityManager::create(10, ExplosionBasic::create(), spriteBatch2);

        this->mEventPanel = EventPanel::create(this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        ((Entity*) this->mEventPanel)->create()->setCenterPosition(Options::CAMERA_CENTER_X, -Utils::coord(100));
        this->mCountIcon->create()->setCenterPosition(Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(64));
        ((Entity*) this->mTimeIcon)->create()->setCenterPosition(Utils::coord(64), Utils::coord(80));

        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(48));

        this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mTimeText[1]->setCenterPosition(Utils::coord(120) + this->mTimeText[1]->getWidth() / 2, Utils::coord(45));
        this->mTimeText[2]->setCenterPosition(Utils::coord(255) + this->mTimeText[2]->getWidth() / 2, Utils::coord(28));

        //this->mPausePopup = new ArcadePause(this);
        this->mEndScreen = ArcadeEnd::create(Splash::TYPE_ARCADE, this);

        this->mAlgorithmBirdsRemainig = 6;
        this->mAlgorithmBirdsTime = 1.5;

        this->mAlgorithmBirdsTime1 = 2.0;
        this->mAlgorithmBirdsTime2 = 7.0;

        this->addChild(this->mEventLayer);

        m_Instance = this;
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
    Arcade* pSender = static_cast<Arcade*>(Arcade::m_Instance);

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_GAME_PAUSE:

                    pSender->mPausePopup->show();

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
    Game::startGame();

    this->mTimeIcon->start();
}

// ===========================================================
// Override Methods
// ===========================================================

void Arcade::update(float pDeltaTime)
{
    Game::update(pDeltaTime);

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
    int last_timer = 1000.0 - (this->mTimeIcon->getTimeElapsed() - floor(this->mTimeIcon->getTimeElapsed())) * 1000.0;

    this->mTimeText[1]->setString(((timer >= 10 ? "0:" : "0:0") + Utils::intToString(timer)).c_str());
    this->mTimeText[2]->setString(("." + Utils::intToString(last_timer)).c_str());
    
    this->mTimeText[1]->setCenterPosition(Utils::coord(120) + this->mTimeText[1]->getWidth() / 2, Utils::coord(45));
    this->mTimeText[2]->setCenterPosition(this->mTimeText[1]->getCenterX() +  this->mTimeText[1]->getWidth() / 2 + this->mTimeText[2]->getWidth() / 2 - Utils::coord(5), Utils::coord(30));

    this->mBestCountText->setString((Options::TEXT_GAME_BEST.string + Utils::intToString(BEST_COUNT)).c_str());
    this->mBestCountText->setCenterPosition(Utils::coord(10) + this->mBestCountText->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(128));
    
    this->mCountText->setString(Utils::intToString(CURRENT_COUNT).c_str());
    this->mCountText->setCenterPosition(Utils::coord(120) + this->mCountText->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(64));
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
}

void Arcade::onEnter()
{
    Game::onEnter();

    this->mTimeText[0]->setCenterPosition(Utils::coord(120) + this->mTimeText[0]->getWidth() / 2, Utils::coord(100));

    BEST_COUNT = AppDelegate::getBestResult(1);

    this->mTimeIcon->start();
}

void Arcade::onExit()
{
    Game::onExit();
}

#endif