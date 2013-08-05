#ifndef CONST_BIRD
#define CONST_BIRD

#include "Bird.h"

#include "Game.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ccColor3B Bird::COLORS[COUNT] =
 {
    ccc3(246.0, 143.0, 41.0),
    ccc3(224.0, 0.0, 55.0),
    ccc3(204.0, 51.0, 204.0),
    ccc3(51.0, 102.0, 255.0),
    ccc3(145.0, 193.0, 236.0),
    ccc3(64.0, 70.0, 98.0),
    ccc3(172.0, 221.0, 43.0),
    ccc3(36.0, 200.0, 206.0),
    ccc3(223.0, 182.0, 60.0),
    ccc3(36.0, 178.0, 27.0),
    ccc3(196.0, 227.0, 238.0),
    ccc3(62.0, 49.0, 176.0)
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Bird::Bird() :
    ImpulseEntity("birds_sprite@2x.png", 14, 12)
    {
        this->mMarkTime = 0.02;
        this->mMarkTimeElapsed = 0;
        
        this->mLife = new CCProgressTimer();
        this->mLife->initWithSprite(CCSprite::create("birds_life@2x.png"));
        this->mLife->setType(kCCProgressTimerTypeRadial);
        this->mLife->setReverseProgress(true);
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void Bird::onCreate()
{
    ImpulseEntity::onCreate();

    this->mType = Utils::random(0, COUNT - 1);
    
    this->setCurrentFrameIndex(this->mType * this->mHorizontalFramesCount);

    this->animate(0.05, this->getCurrentFrameIndex() + 5, this->getCurrentFrameIndex() + 5 + 7, 1);

    this->setCenterPosition(Utils::randomf(0, Options::CAMERA_WIDTH), Utils::randomf(0.0, 0.0));

    this->mWeight = Utils::coord(2000.0f);
    this->mImpulsePower = Utils::coord(Utils::randomf(1200.0f, 2200.0f));
    this->mSideImpulse = Utils::coord(Utils::randomf(100.0f, 300.0f));
    this->mSideImpulse = this->getCenterX() < Options::CAMERA_CENTER_X ? -this->mSideImpulse : this->mSideImpulse;

    this->setScale(1.0);
    this->setScaleX(this->getCenterX() < Options::CAMERA_CENTER_X ? 1 : -1);

    this->mIsGoingToDestroy = false;
    this->mSpecialAnimation = false;

    this->mDestroyAnimationFrames = 0;

    this->mDestroyAnimationTime = 0.1;
    this->mDestroyAnimationTimeElapsed = 0;
    
    if(!this->mLife->getParent())
    {
        this->getParent()->getParent()->addChild(this->mLife);
    }
    
    this->mLife->setVisible(true);
    this->mLife->setPercentage(0);

    this->mInitLifeCount = 100.0;
    this->mLifeCount = this->mInitLifeCount;
}

void Bird::onAnimationEnd()
{
    Entity::onAnimationEnd();
    
    if(this->mSpecialAnimation)
    {
        this->mSpecialAnimation = false;
        
        this->animate(0.05, this->mType * this->mHorizontalFramesCount + 5, this->mType * this->mHorizontalFramesCount + 5 + 7, 1);
    }
    else
    {
        if(Utils::probably(50))
        {
            this->mSpecialAnimation = true;
            
            this->animate(0.05, this->mType * this->mHorizontalFramesCount, this->mType * this->mHorizontalFramesCount + 5 + 7, 1);
        }
        else
        {
            this->animate(0.05, this->mType * this->mHorizontalFramesCount + 5, this->mType * this->mHorizontalFramesCount + 5 + 7, 1);
        }
    }
}

void Bird::onDestroy()
{
    ImpulseEntity::onDestroy();

    this->mLife->setVisible(false);
}

void Bird::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime);
    
    if(!this->isVisible()) return;
    
    Game* game = (Game*) this->getParent()->getParent();

    this->mMarkTimeElapsed += pDeltaTime;
    
    if(this->mMarkTimeElapsed >= this->mMarkTime)
    {
        this->mMarkTimeElapsed = 0;
        
        Entity* entity = game->mMarks->create();
        
        entity->setCenterPosition(this->getCenterX(), this->getCenterY());
        entity->setColor(COLORS[this->mType]);
    }

    /** Collisions and destroy animation **/

    if(!this->mIsGoingToDestroy)
    {
        for(int i = 0; i < 10; i++)
        {
            if(this->isCollideWithPoint(Options::TOUCH_INFORMATION[i]))
            {
                this->mIsGoingToDestroy = true;
            }
        }
    }
    
    if(this->mIsGoingToDestroy)
    {
        this->mDestroyAnimationTimeElapsed += pDeltaTime;

        if(this->mDestroyAnimationTimeElapsed >= this->mDestroyAnimationTime)
        {
            this->mDestroyAnimationTimeElapsed = 0;

            if(this->mDestroyAnimationFrames == 0 && false)
            {
                this->runAction(CCScaleTo::create(this->mDestroyAnimationTime, 1.3 * this->getScaleX(), 1.3));

                this->mDestroyAnimationFrames++;
            }
            else
            {
                if(this->mLifeCount > 0)
                {
                    this->setScaleX(1.3 * (this->getScaleX() > 0 ? 1.0 : -1.0));
                    this->setScaleY(1.3);

                    this->runAction(CCScaleTo::create(this->mDestroyAnimationTime, this->getScaleX() > 0 ? 1.0 : -1.0, 1.0));

                    this->mIsGoingToDestroy = false;
                    this->mDestroyAnimationFrames = 0;

                    this->mLifeCount -= 33.0; // TODO: Adjust weapon power.

                    this->mLife->setPercentage((this->mLifeCount / this->mInitLifeCount * 100.0));
                }

                if(this->mLifeCount <= 0 || this->mType == TYPE_DANGER)
                {
                    Entity* explosionBasic = static_cast<Entity*>(game->mExplosionsBasic->create());
                    Entity* explosion = static_cast<Entity*>(game->mExplosions->create());

                    explosionBasic->create()->setCenterPosition(this->getCenterX(), this->getCenterY() - Utils::coord(15));

                    explosion->setCenterPosition(this->getCenterX(), this->getCenterY());
                    explosion->setColor(COLORS[this->mType]);

                    for(int i = 0; i < 10; i++)
                    {
                        Entity* feather = (Entity*) game->mFeathers->create();

                        feather->setCenterPosition(this->getCenterX(), this->getCenterY());
                        feather->setCurrentFrameIndex(this->mType);
                    }
                    
                    if(Options::SOUND_ENABLE)
                    {
                        if(this->mType == TYPE_DANGER)
                        {
                            SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_DANGER_EXPLOSION);
                        }
                        else
                        {
                            SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_BIRD_BLOW);
                        }
                    }

                    Game::CURRENT_COUNT++;

                    this->destroy();
                }
            }
        }
    }
    
    this->mLife->setPosition(ccp(this->getCenterX() + Utils::coord(5) * (this->getScaleX() > 0.0 ? 1.0 : - 1.0), this->getCenterY()));
}

Bird* Bird::deepCopy()
{
    return new Bird();
}

#endif