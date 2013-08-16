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

Progresses::Progresses() :
    Game()
    {
       /* this->mEventLayer = CCLayer::create();

        this->mBackground = Entity::create("game_gui_bg_summer@2x.png", this);

        this->mGameStartText = new Text(Options::TEXT_GAME_START_STRING_1, this);

        this->mPauseButton = Button::create((EntityStructure) {"game_gui_btn_sprite@2x.png", 1, 1, 116, 0, 116, 78}, this, Options::BUTTONS_ID_GAME_PAUSE, onTouchButtonsCallback);

        this->mDust = new BatchEntityManager(100, new Dust(), this);
        this->mMarks = new BatchEntityManager(500, new Mark(), this);
        this->mFeathers = new BatchEntityManager(100, new Feather(), this);
        this->mBirds = new BatchEntityManager(20, new Bird(), this);
        this->mSpecialBirds = new BatchEntityManager(10, new SpecialBird(), this);
        this->mExplosions = new BatchEntityManager(10, new Explosion(), this);
        this->mExplosionsBasic = new BatchEntityManager(10, new ExplosionBasic(), this);

        this->mEventPanel = new EventPanel(this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mEventPanel->create()->setCenterPosition(Options::CAMERA_CENTER_X, -Utils::coord(100));

        this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Options::CAMERA_HEIGHT - Utils::coord(48));

        this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

        this->mShelfes = new BatchEntityManager(10, Entity::create("game_shelf@2x.png"), this->mEventLayer);
        this->mColors = new BatchEntityManager(50, new Color(), this->mEventLayer);

        this->mPausePopup = new ProgressPause(this);
        this->mEndScreen = new ProgressEnd(Splash::TYPE_PROGRESS, this);

        this->mAlgorithmBirdsRemainig = 20;
        this->mAlgorithmBirdsTime = 0.5;

        this->mAlgorithmBirdsTime1 = 0.0;
        this->mAlgorithmBirdsTime2 = 1.5;

        this->addChild(this->mEventLayer);

        m_Instance = this;*/
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

                this->mColors->stopAllActions();
                this->mShelfes->stopAllActions();

                this->mColors->runAction(CCMoveTo::create(0.2, ccp(-entity->getCenterX() + Utils::coord(64), this->mColors->getPosition().y)));
                this->mShelfes->runAction(CCMoveTo::create(0.2, ccp(-entity->getCenterX() + Utils::coord(64), this->mShelfes->getPosition().y)));

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

                this->mColors->stopAllActions();
                this->mShelfes->stopAllActions();
                
                this->mColors->runAction(CCMoveTo::create(0.2, ccp(-entity->getCenterX() + Utils::coord(64), this->mColors->getPosition().y)));
                this->mShelfes->runAction(CCMoveTo::create(0.2, ccp(-entity->getCenterX() + Utils::coord(64), this->mShelfes->getPosition().y)));
            }
        }
    }
}

void Progresses::onEnter()
{
    Game::onEnter();

    this->mColors->clear();
    this->mColors->setPosition(ccp(0, 0));
}

void Progresses::onExit()
{
    Game::onExit();
}

#endif