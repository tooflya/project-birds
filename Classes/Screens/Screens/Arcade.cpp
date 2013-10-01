#ifndef CONST_ARCADE
#define CONST_ARCADE

#include "Arcade.h"

// ===========================================================
// Inner Classes
// ===========================================================

class Effect : public CCNodeRGBA
{
public:
    Effect()
    {
        this->setColor(ccc3(0, 0, 0));
        this->setOpacity(0);
    }
    
    static Effect* create()
    {
        Effect* background = new Effect();
        background->autorelease();
        
        return background;
    }
    
    void draw()
    {
        if(this->getOpacity() <= 0) return;
        
        glLineWidth(1);
        CCPoint filledVertices[] = { ccp(0,0), ccp(0,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH, 0)};
        ccDrawSolidPoly(filledVertices, 4, ccc4f(this->getColor().r, this->getColor().g, this->getColor().b, this->getOpacity() / 255.0) );
    }
};

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
        
        CCSpriteBatchNode* spriteBatch1 = CCSpriteBatchNode::create("TextureAtlas3.png");
        CCSpriteBatchNode* spriteBatch2 = CCSpriteBatchNode::create("TextureAtlas7.png");
        CCSpriteBatchNode* spriteBatch3 = CCSpriteBatchNode::create("TextureAtlas8.png");
        CCSpriteBatchNode* spriteBatch4 = CCSpriteBatchNode::create("TextureAtlas10.png");
        CCSpriteBatchNode* spriteBatch5 = CCSpriteBatchNode::create("TextureAtlas11.png");
        CCSpriteBatchNode* spriteBatch6 = CCSpriteBatchNode::create("TextureAtlas6.png");
        CCSpriteBatchNode* spriteBatch7 = CCSpriteBatchNode::create("TextureAtlas14.png");
        CCSpriteBatchNode* spriteBatch8 = CCSpriteBatchNode::create("TextureAtlas6.png");
        
        this->mGameLayer->addChild(spriteBatch6);
        
        this->e2 = Effect::create();
        this->mGameLayer->addChild(this->e2);
        
        this->mGameLayer->addChild(spriteBatch7);
        this->mGameLayer->addChild(spriteBatch1);
        this->mGameLayer->addChild(spriteBatch2);
        this->mGameLayer->addChild(spriteBatch3);
        this->mGameLayer->addChild(spriteBatch4);
        this->mGameLayer->addChild(spriteBatch5);
        this->mMenuLayer->addChild(spriteBatch8);

        this->mBackground = Entity::create("temp_level_bg@2x.png", spriteBatch6);
        this->mTimeIcon = Clock::create(this->mEventLayer);
        this->mStars = EntityManager::create(1000, StarParticle::create(), spriteBatch2);
        
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
        
        this->mGamePanel = Entity::create("game_panel@2x.png", spriteBatch8);
        this->mTextAreas[0] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextAreas[1] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextAreas[2] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextAreas[3] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
        this->mTextIcons[0] = Entity::create("game_panel_counter@2x.png", spriteBatch8);
        this->mTextIcons[1] = Entity::create("game_panel_counter_best@2x.png", spriteBatch8);
        this->mTextIcons[2] = Entity::create("game_panel_goldlife@2x.png", spriteBatch8);
        this->mTextIcons[3] = Entity::create("game_panel_goldlife@2x.png", spriteBatch8);
        this->mGoldLifeButton = Button::create((EntityStructure) {"game_panel_plus@2x.png", 1, 1, 0, 0, 78, 72}, spriteBatch8, Options::BUTTONS_ID_GAME_PAUSE, onTouchButtonsCallback);
        
        this->mGamePanel->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextAreas[0]->create()->setCenterPosition(this->mTextAreas[0]->getWidth() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextAreas[1]->create()->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidth() + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextAreas[2]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidth() + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextAreas[3]->create()->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidth() + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->mTextIcons[0]->create()->setCenterPosition(this->mTextAreas[0]->getCenterX() - this->mTextAreas[0]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextIcons[1]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() - this->mTextAreas[1]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextIcons[2]->create()->setCenterPosition(this->mTextAreas[2]->getCenterX() - this->mTextAreas[2]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        this->mTextIcons[3]->create()->setCenterPosition(this->mTextAreas[3]->getCenterX() - this->mTextAreas[3]->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->mGoldLifeButton->create()->setCenterPosition(this->mTextAreas[3]->getCenterX() + this->mTextAreas[3]->getWidth() / 2 - this->mGoldLifeButton->getWidth() / 4, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);

        this->mCountText = Text::create((Textes) {"0", Options::FONT, 32, -1}, this);
        this->mBestCountText = Text::create(Options::TEXT_GAME_BEST, this);
        this->mTimeText = Text::create((Textes) {"0", Options::FONT, 32, -1}, this);

        this->mGameStartText = Text::create(Options::TEXT_GAME_START_STRING_1, this);
        
        this->mPauseButton = Button::create((EntityStructure) {"game_panel_pause@2x.png", 1, 1, 0, 0, 78, 72}, spriteBatch8, Options::BUTTONS_ID_GAME_PAUSE, onTouchButtonsCallback);
        
        this->mDust = EntityManager::create(100, Dust::create(), spriteBatch2);
        this->mMarks = EntityManager::create(300, Mark::create(), spriteBatch2);
        this->mFeathers = EntityManager::create(300, Feather::create(), spriteBatch2);
        this->mBirds = EntityManager::create(20, Bird::create(false), spriteBatch4);
        this->mSpecialBirds = EntityManager::create(10, SpecialBird::create(), spriteBatch5);
        this->mExplosions = EntityManager::create(10, Explosion::create(), spriteBatch2);
        this->mExplosionsBasic = EntityManager::create(10, ExplosionBasic::create(), spriteBatch2);
        this->mCoins = EntityManager::create(50, AnimatedCoin::create(0.7), spriteBatch2);
        this->mArrows = EntityManager::create(5, Entity::create("bomb_arrow.png"), spriteBatch2);
        this->mPredictionIcons = EntityManager::create(5, Entity::create("bomb_ico.png"), spriteBatch2);
        this->mRobotParts = EntityManager::create(8, RobotoPart::create(0), spriteBatch7);
        this->mGunLaser = Entity::create("gun_laser.png", 4, 1, spriteBatch7);
        this->mGun = RobotoGun::create(spriteBatch7);
        
        this->mGunLaser->setAnchorPoint(ccp(0.5, 1));
        this->mGunLaser->animate(0.04);

        this->mEventPanel = EventPanel::create(this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        ((Entity*) this->mEventPanel)->create()->setCenterPosition(Options::CAMERA_CENTER_X, -Utils::coord(100));
        
        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(32), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->e1 = Entity::create("freeze_bg.png", spriteBatch7);
        
        this->mRains = EntityManager::create(300, Rain::create(), spriteBatch7);
        this->mRainsCircles = EntityManager::create(300, RainCircle::create(), spriteBatch7);

        this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mTimeText->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidth() / 2 - this->mTimeText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);

        this->mPausePopup = ArcadePause::create(this);
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

    this->mTimeText->setString(((timer >= 10 ? "0:" : "0:0") + Utils::intToString(timer)).c_str());
    this->mTimeText->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidth() / 2 - this->mTimeText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mBestCountText->setString((Options::TEXT_GAME_BEST.string + Utils::intToString(BEST_COUNT)).c_str());
    this->mBestCountText->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidth() / 2 - this->mBestCountText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mCountText->setString(Utils::intToString(CURRENT_COUNT).c_str());
    this->mCountText->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidth() / 2 - this->mCountText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
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

    this->mTimeText->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidth() / 2 - this->mTimeText->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);

    BEST_COUNT = AppDelegate::getBestResult(1);

    this->mTimeIcon->start();
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

#endif