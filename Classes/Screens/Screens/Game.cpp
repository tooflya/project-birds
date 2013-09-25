#ifndef CONST_GAME
#define CONST_GAME

#include "Game.h"

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

float Game::TIME_SLOW = 1;
bool Game::PREDICTION = false;

int Game::CURRENT_COUNT = 0;
int Game::BEST_COUNT = 0;
int Game::LIFES = 0;
int Game::HEALTH = 0;
int Game::RECORD_BEATEAN = 0;
int Game::COMBO_COUNT = 0;
int Game::FLAYER_COUNT = 0;
int Game::CRITICAL_COUNT = 0;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Game::~Game()
{
    this->mEventPanel->release();
    this->mEndScreen->release();
    
    this->mBirds->release();
    this->mSpecialBirds->release();
    this->mMarks->release();
    this->mFeathers->release();
    this->mExplosionsBasic->release();
    this->mExplosions->release();
    this->mDust->release();
    
    this->mPausePopup->release();
}

Game::Game() :
    Screen()
    {
        this->mBirdsTime = 0;
        this->mBirdsTimeElapsed = 0;
        
        this->mSpecialBirdsTime = 20.0;
        this->mSpecialBirdsTimeElapsed = 0;
        
        this->mCoinsBirdTime = 15.0;
        this->mCoinsBirdTimeElapsed = 0;
        
        this->mCoinsBirdsCount = 1;
        
        this->mLastKillTime = 0;
    
        this->mChalange = false;
        this->mGameRunning = false;
        
        this->mPause = false;
        
        this->mBackgroundLightsAnimationsReverse[0] = false;
        this->mBackgroundLightsAnimationsReverse[1] = false;
        this->mBackgroundLightsAnimationsReverse[2] = true;
        this->mBackgroundLightsAnimationsReverse[3] = false;
        this->mBackgroundLightsAnimationsReverse[4] = false;
        this->mBackgroundLightsAnimationsReverse[5] = true;
        this->mBackgroundLightsAnimationsReverse[6] = false;
        
        this->mIsBonusAnimationRunning = false;
        
        this->mBonusAnimationTime = 0.0;
        this->mBonusAnimationTimeElapsed = 0;
        
        this->mBonusAnimationFrameTime = 0;
        this->mBonusAnimationFrameTimeElapsed = 0;

        this->addChild(TouchTrailLayer::create(), 10);
        
        SimpleAudioEngine::sharedEngine()->playBackgroundMusic(Options::MUSIC_2, true);
        
        if(!Options::MUSIC_ENABLE)
        {
            SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
        }
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
    
    this->mCoinsBirdsCount = 1;
    this->mLastKillType = -1;
    this->mLastKillCount = 0;
    
    this->mLastKillTime = Utils::millisecondNow();
    
    this->mStartGameAnimation = 1.0;
    this->mStartGameAnimationElapsed = this->mStartGameAnimation;
    
    this->mGameStartText->setOpacity(0.0);

    this->mBirds->clear();
    this->mSpecialBirds->clear();
    this->mFeathers->clear();
    this->mMarks->clear();
    this->mExplosions->clear();
    this->mExplosionsBasic->clear();

    HEALTH = 12;
    COMBO_COUNT = 0;
    FLAYER_COUNT = 0;
    CRITICAL_COUNT = 0;
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
            
            this->mLastKillTime = Utils::millisecondNow();
            
            if(this->mLastKillType == pType)
            {
                this->mLastKillCount++;
            }
            else
            {
                this->mLastKillCount = 1;
                this->mLastKillType = pType;
            }

            if(CURRENT_COUNT - 1 == BEST_COUNT && RECORD_BEATEAN == 0 && BEST_COUNT >= 10)
            {
                this->mEventPanel->setEvent(0)->show();

                RECORD_BEATEAN = 1;
            }

            if(CURRENT_COUNT > BEST_COUNT)
            {
                BEST_COUNT = CURRENT_COUNT;
            }
        }
    }
}

void Game::pause()
{
    if(this->mPause)
    {
        this->mBirds->resumeSchedulerAndActions();
        this->mSpecialBirds->resumeSchedulerAndActions();
        this->mFeathers->resumeSchedulerAndActions();
        this->mExplosions->resumeSchedulerAndActions();
        this->mExplosionsBasic->resumeSchedulerAndActions();
        this->mDust->resumeSchedulerAndActions();
        this->mMarks->resumeSchedulerAndActions();
    }
    else
    {
        this->mBirds->pauseSchedulerAndActions();
        this->mSpecialBirds->pauseSchedulerAndActions();
        this->mFeathers->pauseSchedulerAndActions();
        this->mExplosions->pauseSchedulerAndActions();
        this->mExplosionsBasic->pauseSchedulerAndActions();
        this->mDust->pauseSchedulerAndActions();
        this->mMarks->pauseSchedulerAndActions();
    }
    
    this->mPause = !this->mPause;
}

void Game::generateCoinsBirds()
{
    bool side = Utils::probably(50);
    int y = Utils::random(Utils::coord(250), Options::CAMERA_HEIGHT - Utils::coord(250));
    
    for(int i = 0; i < this->mCoinsBirdsCount; i++)
    {
        int params[3] = {i, side ? 1: 0, y};
        
        static_cast<Bird*>(this->mBirds->create())->init(3, params);
    }
    
    this->mCoinsBirdsCount += 2;
    
    if(this->mCoinsBirdsCount > 5)
    {
        this->mCoinsBirdsCount = 5;
    }
}

void Game::onBonus(int pId)
{
    if(!this->mGameRunning) return;
    
    this->mIsBonusAnimationRunning = true;
    
    this->mBonusAnimationTimeElapsed = 0;
    
    switch(pId)
    {
        case 0:
            Game::TIME_SLOW = 0.5;
            
            this->mEventPanel->setEvent(61)->show();
            
            this->e1->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
            
            this->e1->setScale(2);
            this->e1->setOpacity(0);
            this->e1->runAction(CCScaleTo::create(0.5, 1.0));
            this->e1->runAction(CCFadeTo::create(0.5, 255.0));
            
            this->mBonusAnimationTime = 6.0;
            
            if(Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_FREEZEE);
            }
        break;
        case 1:
            PREDICTION = true;
            
            this->mEventPanel->setEvent(62)->show();
            
            this->mBonusAnimationTime = 6.0;
            
            this->e2->runAction(CCFadeTo::create(0.5, 100));
            
            if(Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PREDICTION);
            }
        break;
    }
    
    this->mRunningBonusId = pId;
    this->mIsBonusAnimationRunningCount = 0;
}

// ===========================================================
// Override Methods
// ===========================================================

void Game::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    if(this->mPause)
    {
        return;
    }
    
    if(this->mDust->getCount() < 30)
    {
        this->mDust->create();
    }

    if(this->mGameRunning && !this->mGamePaused)
    {
        this->mBirdsTimeElapsed += pDeltaTime;
        this->mSpecialBirdsTimeElapsed += pDeltaTime;
        
        if(!this->mChalange)
        {
            this->mCoinsBirdTimeElapsed += pDeltaTime;
        }

        if(this->mChalange)
        {
            if(this->mBirdsTimeElapsed >= 0.2)
            {
                this->mBirdsTimeElapsed = 0;
                
                Bird* bird = static_cast<Bird*>(this->mBirds->create());
                bird->init(2, 0);

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
                }
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
                
                Bird* bird = static_cast<Bird*>(this->mBirds->create());

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
                }
            }
            
            if(this->mSpecialBirdsTimeElapsed >= this->mSpecialBirdsTime)
            {
                this->mSpecialBirdsTimeElapsed = 0;
                
                if(AppDelegate::isSomeBonusBirdBought())
                {
                    this->mSpecialBirds->create();
                }
            }
            
            if(this->mCoinsBirdTimeElapsed >= this->mCoinsBirdTime)
            {
                this->mCoinsBirdTimeElapsed = 0;
                
                this->generateCoinsBirds();
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

    if(Utils::millisecondNow() - this->mLastKillTime >= 1000)
    {
        if(this->mLastKillCount > 1)
        {
            this->mEventPanel->setEvent(60)->show();
            
            COMBO_COUNT++;
        }
        
        this->mLastKillType = -1;
        this->mLastKillCount = 0;
    }
    
    if(this->mEventLayer)
    {
        //this->mEventLayer->setPosition(ccp(0, this->mEventPanel->getCenterY() + Utils::coord(100)));
    }
    
    this->mBackgroundLights[0]->setOpacity(this->mBackgroundLights[0]->getOpacity() - (this->mBackgroundLightsAnimationsReverse[0] ? -0.5: 0.5));
    
    if(this->mBackgroundLightsAnimationsReverse[0])
    {
        if(this->mBackgroundLights[0]->getOpacity() >= 255)
        {
            this->mBackgroundLightsAnimationsReverse[0] = !this->mBackgroundLightsAnimationsReverse[0];
        }
    }
    else
    {
        if(this->mBackgroundLights[0]->getOpacity() <= 100)
        {
            this->mBackgroundLightsAnimationsReverse[0] = !this->mBackgroundLightsAnimationsReverse[0];
        }
    }
    
    for(int i = 0; i < 3; i++)
    {
        this->mBackgroundLights[i + 1]->setRotation(this->mBackgroundLights[i + 1]->getRotation() - (this->mBackgroundLightsAnimationsReverse[i + 1] ? -0.01: 0.01));
        
        if(this->mBackgroundLightsAnimationsReverse[i + 1])
        {
            if(this->mBackgroundLights[i + 1]->getRotation() >= 10)
            {
                this->mBackgroundLightsAnimationsReverse[i + 1] = !this->mBackgroundLightsAnimationsReverse[i + 1];
            }
        }
        else
        {
            if(this->mBackgroundLights[i + 1]->getRotation() < -10)
            {
                this->mBackgroundLightsAnimationsReverse[i + 1] = !this->mBackgroundLightsAnimationsReverse[i + 1];
            }
        }
    }
    
    for(int i = 4; i < 7; i++)
    {
        this->mBackgroundLights[i]->setOpacity(this->mBackgroundLights[i]->getOpacity() - (this->mBackgroundLightsAnimationsReverse[i] ? -0.5: 0.5));
        
        if(this->mBackgroundLightsAnimationsReverse[i])
        {
            if(this->mBackgroundLights[i]->getOpacity() >= 255)
            {
                this->mBackgroundLightsAnimationsReverse[i] = !this->mBackgroundLightsAnimationsReverse[i];
            }
        }
        else
        {
            if(this->mBackgroundLights[i]->getOpacity() <= 150)
            {
                this->mBackgroundLightsAnimationsReverse[i] = !this->mBackgroundLightsAnimationsReverse[i];
            }
        }
    }
    
    if(this->mIsBonusAnimationRunning && this->mGameRunning)
    {
        this->mBonusAnimationTimeElapsed += pDeltaTime;
        
        if(this->mBonusAnimationTimeElapsed >= this->mBonusAnimationTime)
        {
            this->mBonusAnimationTimeElapsed = 0;
            
            this->mBonusCircles->clear();
            
            switch(this->mRunningBonusId)
            {
                case 0:
                    if(this->mIsBonusAnimationRunningCount == 1)
                    {
                        this->e1->destroy();
                    }
                    else
                    {
                        this->e1->runAction(CCFadeTo::create(1.0, 0));
                        this->e1->runAction(CCScaleTo::create(1.0, 2.0));
                    
                        TIME_SLOW = 1;
                    }
                break;
                case 1:
                    if(this->mIsBonusAnimationRunningCount == 1)
                    {
                    }
                    else
                    {
                        this->e2->runAction(CCFadeTo::create(0.5, 0));
                        
                        PREDICTION = false;
                    }
                break;
            }
            
            if(this->mIsBonusAnimationRunningCount == 1)
            {
                this->mIsBonusAnimationRunning = false;
            }
            
            this->mIsBonusAnimationRunningCount++;
        }
        else
        {
            this->mBonusAnimationFrameTimeElapsed += pDeltaTime;
            
            if(this->mBonusAnimationFrameTimeElapsed >= this->mBonusAnimationFrameTime)
            {
                this->mBonusAnimationFrameTimeElapsed = 0;
                
                switch(this->mRunningBonusId)
                {
                    case 0:
                    break;
                    case 1:
                        this->mRains->create();
                        this->mRainsCircles->create();
                        
                        this->e2->setColor(ccc3(0, 0, 0));
                        
                        if(Utils::probably(2))
                        {
                            this->e2->setColor(ccc3(255, 255, 255));
                        }
                    break;
                }
                
                return;
                
                for(int i = 0; i < 4; i++)
                {
                    float x, y;
                    
                    switch(i)
                    {
                        case 0:
                            x = -100;
                            y = -100;
                            break;
                        case 1:
                            x = -100;
                            y = Options::CAMERA_HEIGHT + 100;
                            break;
                        case 2:
                            x = Options::CAMERA_WIDTH + 100;
                            y = Options::CAMERA_HEIGHT + 100;
                            break;
                        case 3:
                            x = Options::CAMERA_WIDTH + 100;
                            y = -100;
                            break;
                    }
                    Entity* circle = (Entity*) this->mBonusCircles->create();
                    circle->setCenterPosition(x, y);
                    circle->setRotation(0.0);
                    circle->setScale(0.0);
                    circle->setOpacity(255.0);
                    //circle->setColor(ccc3(Utils::randomf(0, 255.0), Utils::randomf(0, 255.0), Utils::randomf(0, 255.0)));
                }
            }
            
            for(int i = 0; i < this->mBonusCircles->getCount(); i++)
            {this->mBonusAnimationFrameTime=0.4;
                Entity* circle = static_cast<Entity*>(this->mBonusCircles->objectAtIndex(i));
                
                circle->setRotation(circle->getRotation() + 1.0 * 1.0);
                circle->setScale(circle->getScaleX() + 0.05);
                //circle->setOpacity(circle->getOpacity() - 1.2 * 1.0);
                
                if(circle->getScale() >= 2.0 && circle->numberOfRunningActions() == 0)
                {
                    circle->runAction(CCFadeOut::create(0.5));
                }
                else if(circle->numberOfRunningActions() > 0 && circle->getOpacity() < 10)
                {
                    circle->destroy();
                }
            }
        }
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