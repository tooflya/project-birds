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

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Bird::Bird() :
    ImpulseEntity("birds_sprite@2x.png", 14, 8)
    {
        this->mMarkTime = 0.02;
        this->mMarkTimeElapsed = 0;
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

    this->mType = Utils::random(0, 8);
    
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
    }

    /** Collisions and destroy animation **/

    if(!this->mIsGoingToDestroy)
    {
        for(int i = 0; i < 10; i++)
        {
            if(this->isCollideWithPoint(Options::TOUCH_INFORMATION[i]))
            {
                this->mIsGoingToDestroy = true;

                // TODO: Play some sound.
            }
        }
    }
    else
    {
        this->mDestroyAnimationTimeElapsed += pDeltaTime;

        if(this->mDestroyAnimationTimeElapsed >= this->mDestroyAnimationTime)
        {
            this->mDestroyAnimationTimeElapsed = 0;

            if(this->mDestroyAnimationFrames == 0)
            {
                this->runAction(CCScaleTo::create(this->mDestroyAnimationTime, 1.3 * this->getScaleX(), 1.3));
            }
            /*else if(this->mDestroyAnimationFrames == 1)
            {
                this->runAction(CCScaleTo::create(this->mDestroyAnimationTime, 0.0, 0.0));
            }*/
            else
            {
                game->mExplosionsBasic->create()->setCenterPosition(this->getCenterX(), this->getCenterY());
                game->mExplosions->create()->setCenterPosition(this->getCenterX(), this->getCenterY());

                for(int i = 0; i < 10; i++)
                {
                    Entity* feather = (Entity*) game->mFeathers->create();

                    feather->setCenterPosition(this->getCenterX(), this->getCenterY());
                    feather->setCurrentFrameIndex(this->mType);
                }

                this->destroy();
            }

            this->mDestroyAnimationFrames++;
        }
    }
}

Bird* Bird::deepCopy()
{
    return new Bird();
}

#endif