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

int Game::STARS = 0;
int Game::GAME_TYPE = -1;

int** Game::MATRIX = NULL;
int Game::LEVEL_TYPE[80] = {
    0, 1, 2
};
int Game::LEVEL_SHOOT_COUNT[80] = {
    5, 1, 1, 1
};
int Game::LEVEL_HEIGHT[80] = {
    1, 1, 1, 1,
    1, 2, 2, 2,
    2, 3, 3, 3,
    3, 3, 4, 4
};
int Game::LEVEL_COLORS[80] = {
    1, 1, 2, 2,
    2, 2, 3, 3,
    3, 3, 3, 4,
    4, 4, 4, 4
};
int Game::LEVEL_HEALTH[80] = {
    12, 12, 12, 12,
    12, 12, 12, 24,
    24, 24, 24, 24,
    24, 36, 36, 36
};

int Game::MATRIX_SIZE_X = 0;
int Game::MATRIX_SIZE_Y = 0;

float Game::TIME_SLOW = 1;

bool Game::PREDICTION = false;
bool Game::LASERGUN = false;
bool Game::ZOMBIE_AREA = false;

int Game::CURRENT_COUNT = 0;
int Game::BEST_COUNT = 0;
int Game::LIFES = 0;
int Game::HEALTH = 0;
int Game::RECORD_BEATEAN = 0;
int Game::COMBO_COUNT = 0;
int Game::FLAYER_COUNT = 0;
int Game::CRITICAL_COUNT = 0;
int Game::EGGS_4_COUNT = 0;

int Game::BURNED[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int Game::LEVEL = 0;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Game::~Game()
{
    CC_SAFE_RELEASE(this->spriteBatch99);
    CC_SAFE_RELEASE(this->mBirds);
    CC_SAFE_RELEASE(this->mSpecialBirds);
    CC_SAFE_RELEASE(this->mMarks);
    CC_SAFE_RELEASE(this->mFeathers);
    CC_SAFE_RELEASE(this->mExplosionsBasic);
    CC_SAFE_RELEASE(this->mExplosions);
    CC_SAFE_RELEASE(this->mZombieExplosions);
    CC_SAFE_RELEASE(this->mGeneralExplosions);
    CC_SAFE_RELEASE(this->mDust);
    CC_SAFE_RELEASE(this->mStars);
    CC_SAFE_RELEASE(this->mCoins);
    CC_SAFE_RELEASE(this->mSilverCoins);
    CC_SAFE_RELEASE(this->mArrows);
    CC_SAFE_RELEASE(this->mPredictionIcons);
    CC_SAFE_RELEASE(this->mRains);
    CC_SAFE_RELEASE(this->mRainsCircles);
    CC_SAFE_RELEASE(this->mRobotParts);
    CC_SAFE_RELEASE(this->mBonusCircles);
    CC_SAFE_RELEASE(this->mKeys);
    CC_SAFE_RELEASE(this->mKeysLights);
    
    CC_SAFE_RELEASE(this->mPausePopup);
    CC_SAFE_RELEASE(this->mEndScreen);
    CC_SAFE_RELEASE(this->mGetLivesPopup);
    
    CC_SAFE_RELEASE(this->array);
}

Game::Game() :
    Screen(),
	mBirdsRemaning(0),
	mStartGameAnimationIndex(0),
	mAlgorithmBirdsRemainig(0),
	mCoinsBirdsCount(0),
	mLastKillType(0),
	mLastKillCount(0),
	mBirdsTime(0),
	mBirdsTimeElapsed(0),
	mStartGameAnimation(0),
	mStartGameAnimationElapsed(0),
	mAlgorithmBirdsTime(0),
	mAlgorithmBirdsTime1(0),
	mAlgorithmBirdsTime2(0),
	mSpecialBirdsTime(0),
	mSpecialBirdsTimeElapsed(0),
	mCoinsBirdTime(0),
	mCoinsBirdTimeElapsed(0),
	mBonusAnimationTime(0),
	mBonusAnimationTimeElapsed(0),
	mBonusAnimationFrameTime(0),
	mBonusAnimationFrameTimeElapsed(0),
	mBonusSomeTimeUpdate(0),
	mBonusSomeTimeUpdateCount(0),
	mBonusSomeTime(0),
	mBonusSomeTimeElapsed(0),
	mGunLaserFrame(0),
	mGunLaserFrameTime(0),
	mGunLaserFrameTimeElapsed(0),
	mZombieAnimation(0),
	mZombieAnimationTime(0),
	mZombieAnimationTimeElapsed(0),
	mZombieAnimationX(0),
	mZombieAnimationY(0),
	mZombieAnimationCount(0),
	mLastKillTime(0),
	mIsBonusAnimationRunningCount(0),
	mBackgroundLightsAnimationsReverse(),
	mIsBonusAnimationRunning(0),
	mPirateBoxAnimation(0),
	mPirateBoxAnimationTime(0),
	mPirateBoxAnimationTimeElapsed(0),
	mMenuLayer(0),
	mGameLayer(0),
	mBackground(0),
	mGamePanel(0),
	mTextAreas(),
	mTextIcons(),
	mHearts(),
	mGoldLifeButton(0),
	e3(),
	e4(),
	mPirateBox(0),
	mBackgroundLights(),
	mBonusCircles(0),
	mEventPanel(0),
	mPauseButton(0),
	mGameStartText(0),
	mPausePopup(0),
	mGetLivesPopup(0),
	mEndScreen(0),
	mEventLayer(0),
	e2(0),
	mChalange(0),
	mTaskDone(0),
	mGameRunning(0),
	mGamePaused(0),
	mPause(0),
	mRunningBonusId(0),
	mTime(0),
	mStarTime(0),
	mBirds(0),
	mSpecialBirds(0),
	mMarks(0),
	mFeathers(0),
	mExplosionsBasic(0),
	mExplosions(0),
	mZombieExplosions(0),
	mGeneralExplosions(0),
	mDust(0),
	mStars(0),
	mCoins(0),
	mSilverCoins(0),
	mArrows(0),
	mPredictionIcons(0),
	mSchematicBig(0),
	mSchematicSmall(0),
	mColorsBlink(0),
	mKeys(0),
	mKeysLights(0),
	mColors(0),
	e1(0),
	mRains(0),
	mRainsCircles(0),
	mRobotParts(0),
	mGun(0),
    mGunLaser(0),
    array(0),
    marray(0),
    spriteBatch99(0),
    mColorsBurnAnimationTimeoutElapsed(0),
    mLastColorTimeBurn(0)
    {
        array = CCArray::create();
        array->retain();
        array->initWithCapacity(1000);
        
        marray = CCArray::create();
        marray->retain();
        
        int sx = (int) floor(Options::CAMERA_WIDTH / Utils::coord(64)); // I changed round to floor
        int sy = (int) floor(Options::CAMERA_HEIGHT / Utils::coord(64)); // I changed round to floor
        
        MATRIX_SIZE_X = sx;
        MATRIX_SIZE_Y = sy;
        
        MATRIX = new int*[sx];

        for(int i = 0; i < sx; i++)
        {
            MATRIX[i] = new int[sy];
        }
        
        this->mMenuLayer = CCLayer::create();
        this->mGameLayer = CCLayer::create();
        
        this->addChild(this->mGameLayer);
        this->addChild(this->mMenuLayer);
        
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
        this->mBonusSomeTimeUpdate = false;
        this->mPirateBoxAnimation = false;
        this->mZombieAnimation = false;
        
        this->mPause = false;
        
        this->mBackgroundLightsAnimationsReverse[0] = false;
        this->mBackgroundLightsAnimationsReverse[1] = false;
        this->mBackgroundLightsAnimationsReverse[2] = true;
        this->mBackgroundLightsAnimationsReverse[3] = false;
        this->mBackgroundLightsAnimationsReverse[4] = false;
        this->mBackgroundLightsAnimationsReverse[5] = true;
        this->mBackgroundLightsAnimationsReverse[6] = false;
        
        this->mIsBonusAnimationRunning = false;
        this->mAmigoAnimation = false;
        this->mPirateAnimation = false;
        
        this->mAmigoAnimationTime = 0.6;
        this->mAmigoAnimationTimeElapsed = 0;
        
        this->mPirateAnimationTime = 0.6;
        this->mPirateAnimationTimeElapsed = 0;
        
        this->mBonusAnimationTime = 0.0;
        this->mBonusAnimationTimeElapsed = 0;
        
        this->mBonusAnimationFrameTime = 0;
        this->mBonusAnimationFrameTimeElapsed = 0;

        this->mGameLayer->addChild(TouchTrailLayer::create(), 10);
        
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
    ZOMBIE_AREA = false;
    this->mZombieAnimation = false;
    
    this->e5->stopAllActions();
    this->e5->setOpacity(0);
    
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
    this->mKeys->clear();
    this->mKeysLights->clear();

    HEALTH = LEVEL_HEALTH[LEVEL];
    
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

void Game::onTaskComplete()
{
    
}

void Game::onBirBlow(int pType, float pX, float pY, bool pBonus)
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

void Game::startBoxAnimation()
{
    Game::TIME_SLOW = 0.1;
    
    this->mGameLayer->setAnchorPoint(ccp(this->mPirateBox->getCenterX() / Options::CAMERA_WIDTH, this->mPirateBox->getCenterY() / Options::CAMERA_HEIGHT));
    this->mGameLayer->runAction(CCScaleTo::create(0.2, 1.5));
    this->mGameLayer->runAction(CCRotateTo::create(0.2, Utils::randomf(-15, 15)));
    this->mGameLayer->runAction(CCFollow::create(this->mPirateBox, CCRectMake(-Options::CAMERA_WIDTH/4, -Options::CAMERA_HEIGHT/4, Options::CAMERA_WIDTH+Options::CAMERA_WIDTH/4, Options::CAMERA_HEIGHT+Options::CAMERA_HEIGHT/4)));
}

void Game::stopBoxAnimation()
{
    this->mGameLayer->stopAllActions();
    
    this->mGameLayer->runAction(CCScaleTo::create(0.2, 1.0));
    this->mGameLayer->runAction(CCRotateTo::create(0.2, 0.0));
    this->mGameLayer->runAction(CCMoveTo::create(0.2, ccp(0.0, 0.0)));
    
    this->mPirateBoxAnimation = true;
    this->mPirateBoxAnimationTime = 0.5;
    this->mPirateBoxAnimationTimeElapsed = 0;
    
    this->mPirateBox->runAction(CCFadeOut::create(0.5));
    this->mPirateBox->runAction(CCScaleTo::create(0.5, 5));
    
    this->mPirateAnimation = false;
}

void Game::onBonus(int pId, float pX, float pY)
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
            
            // Experiments
            
            //this->runAction(CCShaky3D::create(50, CCSizeMake(15,10), 1, true));
        break;
        case 1:
            PREDICTION = true;
            
            this->mEventPanel->setEvent(62)->show();
            
            this->mBonusAnimationTime = 10.0;
            
            this->e2->runAction(CCFadeTo::create(0.5, 100));
            
            if(Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PREDICTION);
            }
        break;
        case 2:
            LASERGUN = true;
            
            this->mEventPanel->setEvent(63)->show();
            
            this->mBonusAnimationTime = 10.0;
            
            this->e2->runAction(CCFadeTo::create(0.5, 150));
            
            this->mGun->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(100));
            this->mGunLaser->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(100));
            
            this->e4[0]->setScale(0);
            this->e4[1]->setScale(0);
            this->e4[2]->setScale(0);
            this->e4[3]->setScale(0);
            this->e4[4]->setScale(0);
            this->e4[5]->setScale(0);
            this->e4[6]->setScale(0);
            this->e4[7]->setScale(0);
            
            this->e3[0]->create()->setCenterPosition(-this->e3[0]->getWidth() / 2, -this->e3[0]->getHeight() / 2);
            this->e3[1]->create()->setCenterPosition(-this->e3[1]->getWidth() / 2, Options::CAMERA_HEIGHT + this->e3[1]->getHeight() / 2 - this->mGamePanel->getHeight());
            this->e3[2]->create()->setCenterPosition(Options::CAMERA_WIDTH + this->e3[2]->getWidth() / 2, Options::CAMERA_HEIGHT + this->e3[2]->getHeight() / 2 - this->mGamePanel->getHeight());
            this->e3[3]->create()->setCenterPosition(Options::CAMERA_WIDTH + this->e3[3]->getWidth() / 2, -this->e3[3]->getHeight() / 2);
            
            this->e4[0]->create()->setCenterPosition(Utils::coord(15), 0);
            this->e4[1]->create()->setCenterPosition(Utils::coord(30), Options::CAMERA_HEIGHT);
            this->e4[2]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(15), Options::CAMERA_HEIGHT);
            this->e4[3]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(30), 0);
            
            this->e4[4]->create()->setCenterPosition(Options::CAMERA_WIDTH, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() - Utils::coord(15));
            this->e4[5]->create()->setCenterPosition(0, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() - Utils::coord(30));
            this->e4[6]->create()->setCenterPosition(0, Utils::coord(15));
            this->e4[7]->create()->setCenterPosition(Options::CAMERA_WIDTH, Utils::coord(30));
            
            this->e3[0]->runAction(CCMoveTo::create(0.5, ccp(this->e3[0]->getWidth() / 2, this->e3[0]->getHeight() / 2)));
            this->e3[1]->runAction(CCMoveTo::create(0.5, ccp(this->e3[1]->getWidth() / 2, Options::CAMERA_HEIGHT - this->e3[1]->getHeight() / 2 - this->mGamePanel->getHeight())));
            this->e3[2]->runAction(CCMoveTo::create(0.5, ccp(Options::CAMERA_WIDTH - this->e3[2]->getWidth() / 2, Options::CAMERA_HEIGHT - this->e3[2]->getHeight() / 2 - this->mGamePanel->getHeight())));
            this->e3[3]->runAction(CCMoveTo::create(0.5, ccp(Options::CAMERA_WIDTH - this->e3[3]->getWidth() / 2, this->e3[3]->getHeight() / 2)));
            
            for(int i = 0; i < 8; i++)
            {
                this->mRobotParts->create()->setCenterPosition(pX, pY);
            }
            
            this->mBonusSomeTimeUpdate = true;
            this->mBonusSomeTime = 1.0;
            this->mBonusSomeTimeElapsed = 0;
            this->mBonusSomeTimeUpdateCount = 0;
        break;
        case 3:
            this->mPirateAnimation = true;
            
            this->mPirateBox->create()->setCenterPosition(pX, pY);
            
            this->mEventPanel->setEvent(64)->show();
        break;
        case 4:
            this->mAmigoAnimation = true;
            this->runChalange();
            
            this->mEventPanel->setEvent(65)->show();
            
            // Experiments
            
            //this->runAction(CCShaky3D::create(50, CCSizeMake(15, 10), 1, true));
        break;
        case 5:
        {
            this->mGeneralExplosions->create()->setCenterPosition(pX, pY);
            
            this->mEventPanel->setEvent(66)->show();
            
            if(this->e5->isVisible()) this->e5->destroy();
            
            this->e5->stopAllActions();
            this->e5->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
            this->e5->setOpacity(0);
            
            CCFadeTo *fadeIn = CCFadeTo::create(0.5, 127);
            CCFadeTo *fadeOut = CCFadeTo::create(0.5, 255);
            
            CCSequence *pulseSequence = CCSequence::create(fadeIn, fadeOut);
            CCRepeatForever *repeat = CCRepeatForever::create(pulseSequence);
            this->runAction(repeat);
        }
        break;
        case 6:
        {
            this->mZombieAnimation = true;
            
            this->mEventPanel->setEvent(67)->show();
            
            this->mZombieAnimationTime = 0.04;
            this->mZombieAnimationTimeElapsed = 0;
            
            this->mZombieAnimationCount = 0;
            
            this->mZombieAnimationX = pX;
            this->mZombieAnimationY = pY;
            
            ZOMBIE_AREA = true;
            
            if(this->e5->isVisible()) this->e5->destroy();
            
            this->e5->stopAllActions();
            this->e5->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
            this->e5->setOpacity(0);
            
            this->e5->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(0.5, 50), CCFadeTo::create(0.5, 150), NULL)));
            this->e5->setColor(ccc3(102, 220, 0));
        }
        break;
    }
    
    this->mRunningBonusId = pId;
    this->mIsBonusAnimationRunningCount = 0;
}

bool Game::deepFind(int x, int y, int index, bool recursive, CCObject* pOptionalObject)
{
    if(Color::ANIMATION_RUNNING)
    {
        marray->addObject(pOptionalObject);
        
        return false;
    }
    
    if(x < 0 || y < 0 || x >= MATRIX_SIZE_X || y >= MATRIX_SIZE_Y) return false;
    if(MATRIX[x][y] != index) return false;
    
    bool a = false;
    for(int i = 0; i < this->mColors->getCount(); i++)
    {
        Color* color = static_cast<Color*>(this->mColors->objectAtIndex(i));
        
        if(color->position_in_matrtix_x == x && color->position_in_matrtix_y == y && color->mc && !color->mGoingToDestroy)
        {
            if(array->containsObject(color)) return false;
            
            array->addObject(color);
            a = true;
        }
    }
    
    if(!recursive)
    if(!a) return false;
    
	// Visit neighbours
	deepFind(x + 1, y, index, false, 0);
	deepFind(x - 1, y, index, false, 0);
	deepFind(x, y + 1, index, false, 0);
	deepFind(x, y - 1, index, false, 0);
    
    // Diagonal
    
	deepFind(x + 1, y + 1, index, false, 0);
	deepFind(x - 1, y - 1, index, false, 0);
	deepFind(x + 1, y - 1, index, false, 0);
	deepFind(x - 1, y + 1, index, false, 0);
    
    if(recursive)
    {
        if(array->count() >= 3)
        {
            this->onMatch(array->count(), static_cast<Color*>(array->objectAtIndex(0))->getCenterX(), static_cast<Color*>(array->objectAtIndex(0))->getCenterY());
            
            if(Color::SOUND_INDEX < 4)
            {
                Color::SOUND_INDEX++;
            }
            
            bool isHaveSpecial = false;
            
            for(int i = 0; i < array->count(); i++)
            {
                Color* color = static_cast<Color*>(array->objectAtIndex(i));

                if(color->getRealCurrentFrameIndex() > 6)
                {
                    isHaveSpecial = true;
                    
                    break;
                }
            }
            
            for(int i = 0; i < array->count(); i++)
            {
                Color* color = static_cast<Color*>(array->objectAtIndex(i));
                
                if(i == 0 && array->count() >= 4 && !isHaveSpecial)
                {
                    color->setCurrentFrameIndex(color->getCurrentFrameIndex() + (Utils::probably(50) ? 7 : 14));
                }
                else
                {
                    color->runDestroy();
                }
                
                Game::BURNED[color->getCurrentFrameIndex()] += color->mPower;
            }
            
            this->addTime(0.5 * array->count());
            
            array->removeAllObjects();
            
            this->mLastColorTimeBurn = 0;
            
            return true;
        }
        
        array->removeAllObjects();
    }
    
    return false;
}

void Game::onMatch(int count, float a, float b)
{
    
}

void Game::addTime(float pTime)
{
    this->mTime += pTime;
}

// ===========================================================
// Override Methods
// ===========================================================

void Game::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    if(this->mPause || this->mEndScreen->getParent())
    {
        return;
    }
    
    if(!Color::ANIMATION_RUNNING)
    {
        for(int i = 0; i < marray->count(); i++)
        {
            Color* color = static_cast<Color*>(marray->objectAtIndex(i));
            marray->removeObjectAtIndex(i);
            
            if(this->deepFind(color->position_in_matrtix_x, color->position_in_matrtix_y, color->mType, true, 0))
            {
                Color::ANIMATION_RUNNING = true;
            
                break;
            }
        }
    }
    else
    {
        this->mColorsBurnAnimationTimeoutElapsed += pDeltaTime;
        
        if(this->mColorsBurnAnimationTimeoutElapsed >= 1.0)
        {
            this->mColorsBurnAnimationTimeoutElapsed = 0;
            
            Color::ANIMATION_RUNNING = false;
        }
    }
    
    this->mLastColorTimeBurn += pDeltaTime;
    
    if(this->mLastColorTimeBurn >= 3.0)
    {
        this->mLastColorTimeBurn = 0;
        
        Color::SOUND_INDEX = -1;
    }
    
    if(this->mDust->getCount() < 30)
    {
        this->mDust->create();
    }
    
    if(this->mAmigoAnimation)
    {
        this->mAmigoAnimationTimeElapsed += pDeltaTime;
        
        if(this->mAmigoAnimationTimeElapsed >= this->mAmigoAnimationTime)
        {
            this->mAmigoAnimationTimeElapsed = 0;
            
            ImpulseEntity* entity = static_cast<ImpulseEntity*>(this->mMexicanoHats->create());
            
            entity->setCenterPosition(Utils::randomf(0.0, Options::CAMERA_WIDTH), 0.0);
            
            entity->mWeight = Utils::coord(1500.0);
            entity->mImpulsePower = Utils::coord(Utils::randomf(1200.0, 1900.0));
            entity->mRotateImpulse = Utils::coord(Utils::randomf(10.0, 100.0));
        }
    }
    
    if(this->mPirateAnimation)
    {
        this->mPirateAnimationTimeElapsed += pDeltaTime * Game::TIME_SLOW;
        
        if(this->mPirateAnimationTimeElapsed >= this->mPirateAnimationTime)
        {
            this->mPirateAnimationTimeElapsed = 0;
            
            ImpulseEntity* entity = static_cast<ImpulseEntity*>(this->mPirateHats->create());
            
            entity->setCenterPosition(Utils::randomf(0.0, Options::CAMERA_WIDTH), 0.0);
            
            entity->mWeight = Utils::coord(1500.0);
            entity->mImpulsePower = Utils::coord(Utils::randomf(1200.0, 1900.0));
            entity->mRotateImpulse = Utils::coord(Utils::randomf(10.0, 100.0));
        }
    }

    if(this->mZombieAnimation)
    {
        this->mZombieAnimationTimeElapsed += pDeltaTime;
        
        if(this->mZombieAnimationTimeElapsed >= this->mZombieAnimationTime)
        {
            this->mZombieAnimationTimeElapsed = 0;
            
            ZombieExplosion* explosion = static_cast<ZombieExplosion*>(this->mZombieExplosions->create());
            explosion->setScale(1);
            explosion->setCenterPosition(this->mZombieAnimationX + Utils::randomf(-Utils::coord(200), Utils::coord(200)), this->mZombieAnimationY + Utils::randomf(-Utils::coord(200), Utils::coord(200)));
            
            for(int i = 0; i < this->mBirds->getCount(); i++)
            {
                Entity* bird = static_cast<Entity*>(this->mBirds->objectAtIndex(i));
                
                explosion = static_cast<ZombieExplosion*>(this->mZombieExplosions->create());
                explosion->setFollowEntity(bird);
            }
            
            this->mZombieAnimationCount++;
            
            if(this->mZombieAnimationCount >= 200)
            {
                this->mZombieAnimation = false;
                
                ZOMBIE_AREA = false;
                
                this->e5->stopAllActions();
                this->e5->runAction(CCFadeTo::create(0.5, 0));
            }
        }
    }
    
    if(this->mPirateBoxAnimation)
    {
        this->mPirateBoxAnimationTimeElapsed += pDeltaTime;
        
        if(this->mPirateBoxAnimationTimeElapsed >= this->mPirateBoxAnimationTime)
        {
            this->mPirateBoxAnimationTimeElapsed = 0;
            
            Game::TIME_SLOW = 1;
            
            this->mPirateBoxAnimation = false;
            
            for(int i = 0; i < this->mBirds->getCount(); i++)
            {
                static_cast<Bird*>(this->mBirds->objectAtIndex(i))->mLifeCount = 0;
            }
            
            this->mPirateBox->destroy();
        }
    }
    
    if(this->mBonusSomeTimeUpdate)
    {
        this->mBonusSomeTimeElapsed += pDeltaTime;
        
        if(this->mBonusSomeTimeElapsed >= this->mBonusSomeTime)
        {
            this->mBonusSomeTimeElapsed = 0;
            
            switch(this->mRunningBonusId)
            {
                case 2:
                    switch(this->mBonusSomeTimeUpdateCount)
                    {
                        case 0:
                            for(int i = 0; i < 4; i++)
                            this->e4[i]->runAction(CCScaleTo::create(1.0, 1, Options::CAMERA_HEIGHT / Utils::coord(46)));
                            for(int i = 4; i < 8; i++)
                            this->e4[i]->runAction(CCScaleTo::create(1.0, 1, Options::CAMERA_WIDTH / Utils::coord(46)));
                        
                            this->mBonusSomeTimeUpdate = false;
                        break;
                        case 1:
                            this->e3[0]->runAction(CCMoveTo::create(1.0, ccp(-this->e3[0]->getWidth() / 2, -this->e3[0]->getHeight() / 2)));
                            this->e3[1]->runAction(CCMoveTo::create(1.0, ccp(-this->e3[1]->getWidth() / 2, Options::CAMERA_HEIGHT + this->e3[1]->getHeight() / 2 - this->mGamePanel->getHeight())));
                            this->e3[2]->runAction(CCMoveTo::create(1.0, ccp(Options::CAMERA_WIDTH + this->e3[2]->getWidth() / 2, Options::CAMERA_HEIGHT + this->e3[2]->getHeight() / 2 - this->mGamePanel->getHeight())));
                            this->e3[3]->runAction(CCMoveTo::create(1.0, ccp(Options::CAMERA_WIDTH + this->e3[3]->getWidth() / 2, -this->e3[3]->getHeight() / 2)));
                        break;
                    }
                break;
            }
            
            this->mBonusSomeTimeUpdateCount++;
        }
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
    
    //if(this->mEventLayer)
    {
        //this->mEventLayer->setPosition(ccp(0, this->mEventPanel->getCenterY() + Utils::coord(100)));
    }
    
    #if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
    if(Options::DEVICE_TYPE != Options::DEVICE_TYPE_IPOD4)
    {
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
    }
    #endif
    
    if(this->mIsBonusAnimationRunning && this->mGameRunning)
    {
        this->mBonusAnimationTimeElapsed += pDeltaTime;
        
        if(this->mBonusAnimationTimeElapsed >= this->mBonusAnimationTime)
        {
            this->mBonusAnimationTimeElapsed = 0;
            
            //this->mBonusCircles->clear();
            
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
                        
                        this->mIsBonusAnimationRunning = false;
                    }
                break;
                case 2:
                    if(this->mIsBonusAnimationRunningCount == 1)
                    {
                        this->mGun->destroy();
                        this->mGunLaser->destroy();
                        
                        LASERGUN = false;
                        
                        this->e2->runAction(CCFadeTo::create(0.5, 0));
                        
                        this->mIsBonusAnimationRunning = false;
                        
                        for(int i = 0; i < 4; i++)
                        {
                            this->e3[i]->destroy();
                        }
                        
                        for(int i = 0; i < 8; i++)
                        {
                            this->e4[i]->destroy();
                        }
                    }
                    else
                    {
                        for(int i = 0; i < 8; i++)
                        this->e4[i]->runAction(CCScaleTo::create(0.5, 1, 0));
                        
                        this->mBonusSomeTimeUpdate = true;
                        this->mBonusSomeTime = 1.0;
                        this->mBonusSomeTimeElapsed = 0;
                        this->mBonusSomeTimeUpdateCount = 1;
                        
                        this->mBonusAnimationTime = 2;
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
                    case 2:
                        Entity* bird = NULL;
                        
                        for(int i = 0; i < this->mBirds->getCount(); i++)
                        {
                            if(bird == NULL)
                            {
                                bird = static_cast<Entity*>(this->mBirds->objectAtIndex(i));
                            }
                            
                            if(bird == NULL)
                            {
                                break;
                            }
                            
                            if(Utils::distance(this->mGun->getCenterX(), this->mGun->getCenterY(), bird->getCenterX(), bird->getCenterY()) > Utils::distance(this->mGun->getCenterX(), this->mGun->getCenterY(), static_cast<Entity*>(this->mBirds->objectAtIndex(i))->getCenterX(), static_cast<Entity*>(this->mBirds->objectAtIndex(i))->getCenterY()))
                            {
                                bird = static_cast<Entity*>(this->mBirds->objectAtIndex(i));
                            }
                        }
                        
                        if(bird == NULL)
                        {
                            this->mGun->setCurrentFrameIndex(0);
                            this->mGunLaser->destroy();
                            
                            break;
                        }
                        
                        if(!this->mGunLaser->isVisible())
                        {
                            this->mGunLaserFrame = 0;
                            this->mGunLaser->create();
                            
                            this->mGunLaserFrameTime = 0.05;
                            this->mGunLaserFrameTimeElapsed = 0;
                        }
                        
                        this->mGunLaserFrameTimeElapsed += pDeltaTime;
                        
                        if(this->mGunLaserFrameTimeElapsed >= this->mGunLaserFrameTime)
                        {
                            this->mGunLaserFrameTimeElapsed = 0;
                            
                            if(this->mGunLaserFrame >= 4)
                            {
                                this->mGunLaserFrame = 1;
                            }
                            else
                            {
                                this->mGunLaserFrame++;
                            }
                        
                            this->mGun->setCurrentFrameIndex(this->mGunLaserFrame);
                        }
                        
                        float angle = atan2(this->mGun->getCenterY() - bird->getCenterY(), this->mGun->getCenterX() - bird->getCenterX());
                        
                        this->mGun->setRotation(-CC_RADIANS_TO_DEGREES(angle) + 90);
                        this->mGunLaser->setRotation(-CC_RADIANS_TO_DEGREES(angle) + 90);
                        this->mGunLaser->setScaleY(Utils::distance(this->mGun->getCenterX(), this->mGun->getCenterY(), bird->getCenterX(), bird->getCenterY()) / Utils::coord(32));
                        
                        static_cast<Bird*>(bird)->mLifeCount -= 1;
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

void Game::runChalange()
{
    
}

void Game::stopChalange()
{
    this->mAmigoAnimation = false;
}

#endif