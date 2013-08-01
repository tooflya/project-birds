#ifndef CONST_GAME
#define CONST_GAME

#include "Game.h"

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

Game::Game()
{
    this->mBirdsTime = 0;
    this->mBirdsTimeElapsed = 0;

    this->addChild(TouchTrailLayer::create(), 10);
}

// ===========================================================
// Methods
// ===========================================================

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

    if(this->mGameRunning)
    {

    }
    else
    {
        this->mStartGameAnimationElapsed += pDeltaTime;

        if(this->mStartGameAnimationElapsed >= this->mStartGameAnimation)
        {
            this->mStartGameAnimationElapsed = 0;

            switch(++this->mStartGameAnimationIndex)
            {
                case 0:
                this->mGameStartText->runAction(CCScaleTo::create(this->mStartGameAnimation, 2.0));
                this->mGameStartText->runAction(CCFadeTo::create(this->mStartGameAnimation, 0.0));
                break;
                case 1:
                this->mGameStartText->setString(Options::TEXT_GAME_START_STRING_2.string);
                this->mGameStartText->setScale(1.0);
                this->mGameStartText->setOpacity(255.0);
                this->mGameStartText->runAction(CCScaleTo::create(this->mStartGameAnimation, 2.0));
                this->mGameStartText->runAction(CCFadeTo::create(this->mStartGameAnimation, 0.0));
                break;
                case 2:
                this->mStartGameAnimationIndex = -1;
                this->mGameRunning = true;
                break;
            }
        }
    }
}

void Game::onEnter()
{
    Screen::onEnter();

    this->mGameRunning = false;

    this->mStartGameAnimationIndex = -1;
    
    this->mStartGameAnimation = 1.0;
    this->mStartGameAnimationElapsed = this->mStartGameAnimation;
                
    this->mGameStartText->setString(Options::TEXT_GAME_START_STRING_1.string);
    this->mGameStartText->setScale(1.0);
    this->mGameStartText->setOpacity(255.0);
}

void Game::onExit()
{
    Screen::onExit();
}

#endif