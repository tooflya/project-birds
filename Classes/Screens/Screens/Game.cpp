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

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Game::Game()
{
    this->mBirdsTime = 0;
    this->mBirdsTimeElapsed = 0;

    this->addChild(TouchTrailLayer::create(), 10);
}

// ===========================================================
// Methods
// ===========================================================

void Game::startGame()
{
    CURRENT_COUNT = 0;

    this->mGameRunning = false;
    this->mGamePaused = false;

    this->mStartGameAnimationIndex = -2;
    
    this->mStartGameAnimation = 1.0;
    this->mStartGameAnimationElapsed = this->mStartGameAnimation;
    
    this->mGameStartText->setOpacity(0.0);
}

void Game::onGameStarted()
{

}

// ===========================================================
// Override Methods
// ===========================================================

void Game::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);

    if(this->mDust->getCount() < 30)
    {
        this->mDust->create();
    }

    if(this->mGameRunning && !this->mGamePaused)
    {
        this->mBirdsTimeElapsed += pDeltaTime;

        if(this->mBirdsTimeElapsed >= this->mBirdsTime)
        {
            this->mBirdsTimeElapsed = 0;

            if(this->mBirdsRemaning == 0)
            {
                this->mBirdsRemaning = Utils::random(1, 6);
            }

            this->mBirdsTime = Utils::randomf(0.0, 1.5);

            this->mBirds->create();

            this->mBirdsRemaning--;

            if(this->mBirdsRemaning == 0)
            {
                this->mBirdsTime = Utils::randomf(2.0, 7.0);
            }

            if(Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_THROW);
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

    this->startGame();
}

void Game::onExit()
{
    Screen::onExit();
}

#endif