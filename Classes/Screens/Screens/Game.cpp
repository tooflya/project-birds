#ifndef CONST_GAME
#define CONST_GAME

#include "Game.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Game::CURRENT_COUNT = 0;
int Game::BEST_COUNT = 0;
int Game::LIFES = 0;
int Game::HEALTH = 0;
int Game::RECORD_BEATEAN = 0;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Game::~Game()
{
    
}

Game::Game() :
    Screen()
    {
        this->mBirdsTime = 0;
        this->mBirdsTimeElapsed = 0;
    
        this->mChalange = false;

        this->addChild(TouchTrailLayer::create(), 10);
    }

Game* Game::create()
{
    Game* screen = new Game();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Game::startGame()
{
    CURRENT_COUNT = 0;
    RECORD_BEATEAN = 0;

    this->mGameRunning = false;
    this->mGamePaused = false;

    this->mStartGameAnimationIndex = -2;
    
    this->mStartGameAnimation = 1.0;
    this->mStartGameAnimationElapsed = this->mStartGameAnimation;
    
    this->mGameStartText->setOpacity(0.0);

    //this->mBirds->clear();
    //this->mSpecialBirds->clear();
    //this->mFeathers->clear();
    //this->mMarks->clear();
    //this->mExplosions->clear();
    //this->mExplosionsBasic->clear();

    HEALTH = 12;
}

void Game::onGameStarted()
{

}

void Game::onGameEnd()
{

}

void Game::removeLife()
{
    if(Options::SOUND_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LOSE_LIFE);
    }
}

void Game::onBirBlow(int pType)
{
    if(this->mGameRunning)
    {
        if(pType != Bird::TYPE_DANGER)
        {
            CURRENT_COUNT++;

            if(CURRENT_COUNT - 1 == BEST_COUNT && RECORD_BEATEAN == 0 && BEST_COUNT >= 10)
            {
                this->mEventPanel->setEvent(0)->show();

                RECORD_BEATEAN = 1;

                for(int i = 0; i < 100; i++)
                {
                    static_cast<StarParticle*>(this->mStars->create())->setType(2)->onCreate();
                }
            }

            if(CURRENT_COUNT > BEST_COUNT)
            {
                BEST_COUNT = CURRENT_COUNT;
            }
        }
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Game::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    return;
    /*if(this->mDust->getCount() < 30)
    {
        this->mDust->create();
    }*/

    if(this->mGameRunning && !this->mGamePaused)
    {
        this->mBirdsTimeElapsed += pDeltaTime;

        if(this->mChalange)
        {
            if(this->mBirdsTimeElapsed >= 0.2)
            {
                this->mBirdsTimeElapsed = 0;
                
                /*Bird* bird = static_cast<Bird*>(this->mBirds->create());

                if(Options::SOUND_ENABLE)
                {
                    if(bird->getType() == Bird::TYPE_DANGER)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_THROW_BOMB);
                    }
                    else
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_THROW);
                    }
                }*/
            }
        }
        else
        {
            if(this->mBirdsTimeElapsed >= this->mBirdsTime)
            {
                this->mBirdsTimeElapsed = 0;

                if(this->mBirdsRemaning == 0)
                {
                    this->mBirdsRemaning = Utils::random(1, this->mAlgorithmBirdsRemainig);
                }

                this->mBirdsTime = Utils::randomf(0.0, this->mAlgorithmBirdsTime);

                this->mBirdsRemaning--;

                if(this->mBirdsRemaning == 0)
                {
                    this->mBirdsTime = Utils::randomf(this->mAlgorithmBirdsTime1, this->mAlgorithmBirdsTime2);
                }
                
                //Bird* bird = static_cast<Bird*>(this->mBirds->create());
                //SpecialBird* specialBird = static_cast<SpecialBird*>(this->mSpecialBirds->create());

                /*if(Options::SOUND_ENABLE)
                {
                    if(bird->getType() == Bird::TYPE_DANGER)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_THROW_BOMB);
                    }
                    else
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_THROW);
                    }
                }*/
            }
        }
    }
    else if(!this->mGamePaused)
    {
        this->mStartGameAnimationElapsed += pDeltaTime;

        if(this->mStartGameAnimationElapsed >= this->mStartGameAnimation)
        {
            this->mStartGameAnimationElapsed = 0;

            switch(++this->mStartGameAnimationIndex)
            {
                case -1:
                break;
                case 0:
                this->mGameStartText->setString(Options::TEXT_GAME_START_STRING_1.string);
                this->mGameStartText->setScale(1.0);
                this->mGameStartText->setOpacity(255.0);
                this->mGameStartText->runAction(CCScaleTo::create(this->mStartGameAnimation, 1.6));
                this->mGameStartText->runAction(CCFadeTo::create(this->mStartGameAnimation, 0.0));
                break;
                case 1:
                this->mGameStartText->setString(Options::TEXT_GAME_START_STRING_2.string);
                this->mGameStartText->setScale(1.0);
                this->mGameStartText->setOpacity(255.0);
                this->mGameStartText->runAction(CCScaleTo::create(this->mStartGameAnimation, 1.6));
                this->mGameStartText->runAction(CCFadeTo::create(this->mStartGameAnimation, 0.0));
                break;
                case 2:
                this->mStartGameAnimationIndex = -1;
                this->mGameRunning = true;

                this->onGameStarted();
                break;
            }
        }
    }

    if(this->mEventLayer)
    {
        this->mEventLayer->setPosition(ccp(0, this->mEventPanel->getCenterY() + Utils::coord(100)));
    }
}

void Game::onEnter()
{
    Screen::onEnter();

    //this->startGame();
}

void Game::onExit()
{
    Screen::onExit();
}

#endif