#ifndef CONST_PROGRESSES
#define CONST_PROGRESSES

#include "Progresses.h"

// ===========================================================
// Inner Classes
// ===========================================================

class Task : public CCObject
{
protected:
    int color;

public:
    Task(int pColor)
    {
        this->color = pColor;
    }

    int getTask()
    {
        return this->color;
    }
};

// ===========================================================
// Constants
// ===========================================================

Progresses* Progresses::m_Instance = NULL;

int Progresses::SIMLE_TASK[10][50] =
{
    {1, 1, 1, 1, 1, 2,  2, 3, 3, 3, 1, 1, 6, 6, 6, 5, 4, 4, 3, 3, 2, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, },
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, },
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, },
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, },
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, },
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, },
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, },
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, },
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, },
    {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, }
};

CCArray* Progresses::TASK[10] =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Progresses::~Progresses()
{
    this->mColors->release();
    this->mShelfes->release();
}

Progresses::Progresses() :
    Game()
    {
        this->mEventLayer = CCLayer::create();
        
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas3.plist");
        
        CCSpriteBatchNode* spriteBatch1 = CCSpriteBatchNode::create("TextureAtlas3.pvr.ccz");
        CCSpriteBatchNode* spriteBatch2 = CCSpriteBatchNode::create("TextureAtlas7.pvr.ccz");
        CCSpriteBatchNode* spriteBatch3 = CCSpriteBatchNode::create("TextureAtlas8.pvr.ccz");
        CCSpriteBatchNode* spriteBatch4 = CCSpriteBatchNode::create("TextureAtlas10.pvr.ccz");
        CCSpriteBatchNode* spriteBatch5 = CCSpriteBatchNode::create("TextureAtlas11.pvr.ccz");
        CCSpriteBatchNode* spriteBatch6 = CCSpriteBatchNode::create("TextureAtlas6.pvr.ccz");
        CCSpriteBatchNode* spriteBatch7 = CCSpriteBatchNode::create("TextureAtlas7.pvr.ccz");
        
        this->addChild(spriteBatch6);
        this->addChild(spriteBatch1);
        this->addChild(spriteBatch2);
        this->addChild(spriteBatch3);
        this->addChild(spriteBatch4);
        this->addChild(spriteBatch5);
        this->addChild(spriteBatch7);
        
        this->mBackground = Entity::create("temp_level_bg@2x.png", spriteBatch6);

        this->mGameStartText = Text::create(Options::TEXT_GAME_START_STRING_1, this);

        this->mPauseButton = Button::create((EntityStructure) {"game_gui_btn_sprite@2x.png", 1, 1, 116, 0, 116, 78}, spriteBatch2, Options::BUTTONS_ID_GAME_PAUSE, onTouchButtonsCallback);
        
        this->mDust = EntityManager::create(100, Dust::create(), spriteBatch2);
        this->mMarks = EntityManager::create(200, Mark::create(), spriteBatch2);
        this->mFeathers = EntityManager::create(100, Feather::create(), spriteBatch2);
        this->mBirds = EntityManager::create(20, Bird::create(false), spriteBatch4);
        this->mSpecialBirds = EntityManager::create(10, SpecialBird::create(), spriteBatch5);
        this->mExplosions = EntityManager::create(10, Explosion::create(), spriteBatch2);
        this->mExplosionsBasic = EntityManager::create(10, ExplosionBasic::create(), spriteBatch2);

        this->mEventPanel = EventPanel::create(this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        ((Entity*) this->mEventPanel)->create()->setCenterPosition(Options::CAMERA_CENTER_X, -Utils::coord(100));

        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(48));

        this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

        this->mShelfes = EntityManager::create(10, Entity::create("game_shelf@2x.png"), spriteBatch7);
        this->mColors = EntityManager::create(50, Color::create(), spriteBatch7);

        this->mPausePopup = ProgressPause::create(this);
        this->mEndScreen = ProgressEnd::create(Splash::TYPE_PROGRESS, this);

        this->mAlgorithmBirdsRemainig = 20;
        this->mAlgorithmBirdsTime = 0.5;

        this->mAlgorithmBirdsTime1 = 0.0;
        this->mAlgorithmBirdsTime2 = 1.5;

        this->addChild(this->mEventLayer);

        m_Instance = this;
    }

Progresses* Progresses::create()
{
    Progresses* screen = new Progresses();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Progresses::onTouchButtonsCallback(const int pAction, const int pID)
{
    Progresses* pSender = static_cast<Progresses*>(Progresses::m_Instance);

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

// ===========================================================
// Override Methods
// ===========================================================

void Progresses::update(float pDeltaTime)
{
    Game::update(pDeltaTime);
}

void Progresses::onGameStarted()
{
    BEST_COUNT = AppDelegate::getBestResult(0);

    this->mColors->clear();
    this->mShelfes->clear();

    for(int i = -3; i < 7; i++)
    {
        Entity* entity = static_cast<Entity*>(this->mShelfes->create());

        entity->setCenterPosition(entity->getWidth() * i, entity->getHeight() / 4);
    }
    
    TASK[0] = new CCArray();
    TASK[0]->initWithCapacity(50);

    for(int i = 0; i < 50; i++)
    {
        int task = SIMLE_TASK[0][i];

        if(task < 0)
        {
            break;
        }

        TASK[0]->addObject(new Task(task));
    }

    for(int i = 0; i < TASK[0]->count(); i++)
    {
        int task = static_cast<Task*>(TASK[0]->objectAtIndex(i))->getTask();

        if(task >= 0)
        {
            Color* entity = static_cast<Color*>(this->mColors->create());

            entity->setCurrentFrameIndex(task);
            entity->setType(i);
            entity->setCenterPosition(Utils::coord(64) * (i + 1), Utils::coord(64));
        }
    }
}

void Progresses::onGameEnd()
{
    this->mGamePaused = true;

    this->mEndScreen->show();

    if(BEST_COUNT > AppDelegate::getBestResult(0))
    {
        AppDelegate::setBestResult(BEST_COUNT, 0);
    }
}

void Progresses::onBirBlow(int pType)
{
    if(this->mGameRunning)
    {
        if(pType == Bird::TYPE_DANGER)
        {

        }
        else
        {
            if(pType == static_cast<Task*>(TASK[0]->objectAtIndex(0))->getTask())
            {
                Color* entity = NULL;

                for(int i = 0; i < this->mColors->getCount(); i++)
                {
                    Color* en = static_cast<Color*>(this->mColors->objectAtIndex(i));

                    if(entity == NULL)
                    {
                        entity = en;
                    }
                    else
                    {
                        if(en->getCenterX() < entity->getCenterX())
                        {
                            entity = en;
                        }
                    }
                }

                entity->destroy();

                Game::onBirBlow(pType);

                entity = NULL;

                for(int i = 0; i < this->mColors->getCount(); i++)
                {
                    Color* en = static_cast<Color*>(this->mColors->objectAtIndex(i));

                    if(entity == NULL)
                    {
                        entity = en;
                    }
                    else
                    {
                        if(en->getCenterX() < entity->getCenterX())
                        {
                            entity = en;
                        }
                    }
                }

                this->mColors->getParent()->stopAllActions();
                this->mShelfes->getParent()->stopAllActions();

                this->mColors->getParent()->runAction(CCMoveTo::create(0.2, ccp(-entity->getCenterX() + Utils::coord(64), this->mColors->getParent()->getPosition().y)));
                this->mShelfes->getParent()->runAction(CCMoveTo::create(0.2, ccp(-entity->getCenterX() + Utils::coord(64), this->mShelfes->getParent()->getPosition().y)));

                TASK[0]->removeObjectAtIndex(0);
            }
            else
            {
                Color* entity1 = NULL;

                for(int i = 0; i < this->mColors->getCount(); i++)
                {
                    Color* en = static_cast<Color*>(this->mColors->objectAtIndex(i));

                    if(entity1 == NULL)
                    {
                        entity1 = en;
                    }
                    else
                    {
                        if(en->getCenterX() < entity1->getCenterX())
                        {
                            entity1 = en;
                        }
                    }
                }

                TASK[0]->insertObject(new Task(pType), 0);

                Color* entity = static_cast<Color*>(this->mColors->create());

                entity->setCurrentFrameIndex(pType);
                entity->setCenterPosition(entity1->getCenterX() - Utils::coord(64), Utils::coord(64));

                this->mColors->getParent()->stopAllActions();
                this->mShelfes->getParent()->stopAllActions();
                
                this->mColors->getParent()->runAction(CCMoveTo::create(0.2, ccp(-entity->getCenterX() + Utils::coord(64), this->mColors->getParent()->getPosition().y)));
                this->mShelfes->getParent()->runAction(CCMoveTo::create(0.2, ccp(-entity->getCenterX() + Utils::coord(64), this->mShelfes->getParent()->getPosition().y)));
            }
        }
    }
}

void Progresses::onEnter()
{
    Game::onEnter();

    this->mColors->clear();
    this->mColors->getParent()->setPosition(ccp(0, 0));
}

void Progresses::onExit()
{
    Game::onExit();
}

#endif