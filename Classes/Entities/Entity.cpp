#ifndef CONST_ENTITY
#define CONST_ENTITY

#include "Entity.h"

#include "EntityManager.h"
#include "BatchEntityManager.h"

void Entity::constructor(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, int pX, int pY, int pWidth, int pHeight, CCNode* pParent)
{
    CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(pszFileName);

    if(pFrame == NULL)
    {
        this->initWithFile(pszFileName);

        this->mTextureFileName = pszFileName;
    }
    else
    {
        this->initWithSpriteFrame(pFrame);

        this->mTextureFileName = pszFileName;
    }
    
    if(pParent)
    {
        pParent->addChild(this);
    }

    this->mWidth = pWidth >= 0 ? Utils::coord(pWidth) : (pFrame == NULL ? this->getTextureRect().size.width : pFrame->getRect().size.width);
    this->mHeight = pHeight >= 0 ? Utils::coord(pHeight) : (pFrame == NULL ? this->getTextureRect().size.height : pFrame->getRect().size.height);

    this->mPaddingX = (pFrame == NULL ? 0 : pFrame->getRect().origin.x) + Utils::coord(pX);
    this->mPaddingY = (pFrame == NULL ? 0 : pFrame->getRect().origin.y) + Utils::coord(pY);

    this->mFrameWidth = this->mWidth / pHorizontalFramesCount;
    this->mFrameHeight = this->mHeight / pVerticalFramesCount;

    this->mFramesCount = pHorizontalFramesCount * pVerticalFramesCount;

    this->mHorizontalFramesCount = pHorizontalFramesCount;
    this->mVerticalFramesCount   = pVerticalFramesCount;

    this->mWasTouched = false;

    this->setAnchorPoint(ccp(0.5f, 0.5f));

    this->mEntityManager = NULL;
    this->mBatchEntityManager = NULL;

    this->mAlphaParent = false;

    /**
     *
     * We must remember all coordinates of each frame
     * for quick get x and y of it.
     *
     */

    this->mFramesCoordinatesX = new float[this->mFramesCount];
    this->mFramesCoordinatesY = new float[this->mFramesCount];

    int counter = 0;

    for(int i = 0; i < this->mVerticalFramesCount; i++)
    {
        for(int j = 0; j < this->mHorizontalFramesCount; j++, counter++)
        {
            this->mFramesCoordinatesX[counter] = j * (this->mWidth / this->mHorizontalFramesCount) + this->mPaddingX;
            this->mFramesCoordinatesY[counter] = i * (this->mHeight / this->mVerticalFramesCount) + this->mPaddingY;
        }
    }

    this->mPercentage = 100;
    
    /**
     *
     * Setting zero frame
     *
     */

    this->setCurrentFrameIndex(0);

    /**
     *
     *
     * Take care about an animations
     *
     */

    this->mAnimationTime = 0;
    this->mAnimationTimeElapsed = 0;

    this->mAnimationStartTimeout = 0;

    this->mPauseBeforeNewAnimationCircleTime = 0;
    this->mPauseBeforeNewAnimationCircleTimeElapsed = 0;

    this->mAnimationRunning = false;

    this->mAnimationScaleDownTime = 0.2;
    this->mAnimationScaleUpTime = 0.2;

    this->mAnimationScaleDownFactor = 0.9;
    this->mAnimationScaleUpFactor = 1.0;

    this->mIsRegisterAsTouchable = false;

    this->mAnimationRepeatCount = -1;

    this->mAnimationStartFrame = -1;
    this->mAnimationFinishFrame = -1;

    this->mAnimationFramesElapsed = 0;

    this->mIsAnimationReverse = false;
    this->mIsAnimationReverseNeed = false;

    this->destroy();

    this->unscheduleUpdate();
    
    this->scheduleUpdate();
}

Entity::Entity()
{
}

Entity::Entity(const char* pszFileName)
{
    this->constructor(pszFileName, 1, 1, 0, 0, -1, -1, NULL);
}

Entity::Entity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount)
{
    this->constructor(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, -1, -1, -1, -1, NULL);
}

Entity::Entity(const char* pszFileName, CCNode* pParent)
{
    this->constructor(pszFileName, 1, 1, 0, 0, -1, -1, pParent);
}

Entity::Entity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent)
{
    this->constructor(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, 0, 0, -1, -1, pParent);
}

Entity::Entity(EntityStructure pStructure, CCNode* pParent)
{
    this->constructor(pStructure.fileName, pStructure.horizontalFramesCount, pStructure.verticalFramesCount, pStructure.x, pStructure.y, pStructure.width, pStructure.height, pParent);
}

Entity* Entity::create(const char* pszFileName)
{
    Entity* entity = new Entity(pszFileName);
    entity->autorelease();
    
    return entity;
}

Entity* Entity::create(const char* pszFileName, CCNode* pParent)
{
    Entity* entity = new Entity(pszFileName, pParent);
    entity->autorelease();
    
    return entity;
}

Entity* Entity::create(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount)
{
    Entity* entity = new Entity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount);
    entity->autorelease();
    
    return entity;
}

Entity* Entity::create(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent)
{
    Entity* entity = new Entity(pszFileName, pHorizontalFramesCount, pVerticalFramesCount, pParent);
    entity->autorelease();
    
    return entity;
}

Entity* Entity::create(EntityStructure pStructure, CCNode* pParent)
{
    Entity* entity = new Entity(pStructure, pParent);
    entity->autorelease();
    
    return entity;
}

float Entity::getWidth()
{
    return this->getContentSize().width;
}

float Entity::getHeight()
{
    return this->getContentSize().height;
}

float Entity::getWidthScaled()
{
    return this->getContentSize().width * this->getScaleX();
}

float Entity::getHeightScaled()
{
    return this->getContentSize().height * this->getScaleY();
}

/**
 *
 * Take care about careful position
 *
 */

void Entity::setPosition(float pX, float pY)
{
    CCSprite::setPosition(ccp(pX - this->getWidth() / 2, pY + this->getHeight() / 2));
}

void Entity::setCenterPosition(float pX, float pY)
{
    CCSprite::setPosition(ccp(pX, pY));
}

void Entity::setX(float pX)
{
    // TODO: Write this method
}

void Entity::setY(float pY)
{
    // TODO: Write this method
}

float Entity::getCenterPosition()
{
    return 0; // TODO: Write this method
}

float Entity::getX()
{
    return this->getPosition().x - this->getWidth() / 2;
}

float Entity::getY()
{
    return this->getPosition().y + this->getHeight() / 2;
}

float Entity::getCenterX()
{
    return this->getPosition().x;
}

float Entity::getCenterY()
{
    return this->getPosition().y;
}

void Entity::setSpeed(float pSpeed)
{
    this->mSpeed = (pSpeed);
}

float Entity::getSpeed(float pDeltaTime)
{
    return this->mSpeed * pDeltaTime;
}

/**
 *
 * Take care about EntityManager
 *
 */

Entity* Entity::create()
{
    this->onCreate();

    return this;
}

bool Entity::destroy(bool pManage)
{
    this->onDestroy();

    if(pManage)
    {
        if(this->hasEntityManager() == 1)
        {
            this->mEntityManager->destroy(this->id);
        }
        else if(this->hasEntityManager() == 2)
        {
            this->mBatchEntityManager->destroy(this->id);
        }
    }

    return false;
}

bool Entity::destroy()
{
    return this->destroy(true);
}

EntityManager* Entity::getEntityManager()
{
    return this->mEntityManager;
}

BatchEntityManager* Entity::getBatchEntityManager()
{
    return this->mBatchEntityManager;
}

void Entity::setEntityManager(EntityManager* pEntityManager)
{
    this->mEntityManager = pEntityManager;
}

void Entity::setEntityManager(BatchEntityManager* pBatchEntityManager)
{
    this->mBatchEntityManager = pBatchEntityManager;
}

int Entity::hasEntityManager()
{
    if(this->mEntityManager == NULL && this->mBatchEntityManager == NULL)
    {
        return 0;
    }
    else if(this->mBatchEntityManager == NULL)
    {
        return 1;
    }
    else
    {
        return 2;
    }

    return 0;
}

void Entity::setEntityManagerId(int pId)
{
    this->id = pId;
}

int Entity::getEntityManagerId()
{
    return this->id;
}

void Entity::onCreate()
{
    this->setVisible(true);
}

void Entity::onDestroy()
{
    this->setVisible(false);
}

void Entity::setAlphaParent(bool pIsAlphaParent)
{
    this->mAlphaParent = pIsAlphaParent;
}

/**
 *
 * Take care about animation
 *
 */

int Entity::getCurrentFrameIndex()
{
    return this->mCurrentFrameIndex;
}

void Entity::setCurrentFrameIndex(int pIndex)
{
    if(pIndex < this->mHorizontalFramesCount * this->mVerticalFramesCount && pIndex >= 0)
    {
        this->setTextureRect(CCRectMake(this->mFramesCoordinatesX[pIndex], this->mFramesCoordinatesY[pIndex], (this->mWidth / this->mHorizontalFramesCount) * this->mPercentage / 100.0, this->mHeight / this->mVerticalFramesCount));

        this->mCurrentFrameIndex = pIndex;
    }
    else
    {
        this->setCurrentFrameIndex(0);
    }
}

void Entity::previousFrameIndex()
{
    int potencialNextFrame = this->getCurrentFrameIndex() - 1;

    this->setCurrentFrameIndex(potencialNextFrame > 0 ? potencialNextFrame : 0);
}

void Entity::nextFrameIndex()
{
    int potencialNextFrame = this->getCurrentFrameIndex() + 1;

    this->setCurrentFrameIndex(potencialNextFrame > this->mFramesCount ? 0 : potencialNextFrame);
}

void Entity::changeTexture(Texture* pTexture)
{
    CCRect textureRectanle = CCRect(0, 0, pTexture->getTexture()->getContentSize().width, pTexture->getTexture()->getContentSize().height);

    this->setTexture(pTexture->getTexture());
    this->setTextureRect(textureRectanle);

    this->mWidth  = this->getTextureRect().size.width;
    this->mHeight = this->getTextureRect().size.height;

    this->mFrameWidth = this->mWidth / pTexture->getHorizontalFramesCount();
    this->mFrameHeight = this->mHeight / pTexture->getVerticalFramesCount(); 

    this->mFramesCount = pTexture->getHorizontalFramesCount() * pTexture->getVerticalFramesCount();

    this->mHorizontalFramesCount = pTexture->getHorizontalFramesCount();
    this->mVerticalFramesCount   = pTexture->getVerticalFramesCount();

    this->mTextureFileName = pTexture->getTextureFileName();

    int counter = 0;

    for(int i = 0; i < this->mVerticalFramesCount; i++)
    {
        for(int j = 0; j < this->mHorizontalFramesCount; j++, counter++)
        {
            this->mFramesCoordinatesX[counter] = j * (this->mWidth / this->mHorizontalFramesCount);
            this->mFramesCoordinatesY[counter] = i * (this->mHeight / this->mVerticalFramesCount);
        }
    }

    this->setCurrentFrameIndex(0);
}

const char* Entity::getTextureFileName()
{
    return this->mTextureFileName;
}

void Entity::setRepeatTexture(bool pRepeat)
{
    ccTexParams params = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
    
    this->getTexture()->setTexParameters(&params);
}

void Entity::showPercentage(int pPercentage)
{
    this->mPercentage = pPercentage;
    
    this->setCurrentFrameIndex(this->getCurrentFrameIndex());
}

void Entity::animate(float pAnimationTime)
{
    this->mAnimationFramesElapsed = 0;

    this->mAnimationTimeElapsed = 0;
    this->mAnimationTime = pAnimationTime;

    this->mAnimationRunning = true;

    this->onAnimationStart();
}

void Entity::animate(float pAnimationTime, int pRepeatCount)
{
    this->mAnimationRepeatCount = pRepeatCount;

    this->animate(pAnimationTime);
}

void Entity::animate(float pAnimationTime, int pRepeatCount, bool pReverseNeed)
{
    this->mIsAnimationReverseNeed = pReverseNeed;

    this->animate(pAnimationTime, pRepeatCount);
}

void Entity::animate(float pAnimationTime, float pPauseBeforeNewAnimationCircleTime)
{
    this->mPauseBeforeNewAnimationCircleTime = pPauseBeforeNewAnimationCircleTime;

    this->animate(pAnimationTime);
}

void Entity::animate(float pAnimationTime, int pRepeatCount, float pPauseBeforeNewAnimationCircleTime)
{
    this->mPauseBeforeNewAnimationCircleTime = pPauseBeforeNewAnimationCircleTime;

    this->animate(pAnimationTime, pRepeatCount);
}

void Entity::animate(float pAnimationTime, int pStartFrame, int pFinishFrame, int pRepeatCount)
{
    this->animate(pAnimationTime);

    this->mAnimationStartFrame = pStartFrame;
    this->mAnimationFinishFrame = pFinishFrame;

    this->mAnimationRepeatCount = pRepeatCount;

    this->setCurrentFrameIndex(pStartFrame);
}

void Entity::animate(float pAnimationTime, int pStartFrame, int pFinishFrame)
{
    this->animate(pAnimationTime, pStartFrame, pFinishFrame, -1);
}

void Entity::animate(float pAnimationTime, int pStartFrame, int pFinishFrame, bool pReverseNeed)
{
    this->animate(pAnimationTime, pStartFrame, pFinishFrame, -1);

    this->mIsAnimationReverseNeed = pReverseNeed;
    this->mIsAnimationReverse = false;
}

void Entity::onAnimationStart()
{
}

void Entity::onAnimationEnd()
{
}

void Entity::onAnimationCircleEnd()
{
}

void Entity::setAnimationStartTimeout(float pSecodsTimeout)
{
    this->mAnimationStartTimeout = pSecodsTimeout;
}

void Entity::setStartFrame(int pStartFrame)
{
    this->mAnimationFinishFrame = (this->mAnimationFinishFrame - this->mAnimationStartFrame) + pStartFrame;
    this->mAnimationStartFrame = pStartFrame;
}

void Entity::setFinishFrame(int pFinishFrame)
{
    this->mAnimationFinishFrame = pFinishFrame;
}

bool Entity::isAnimationRunning()
{
    return this->mAnimationRunning;
}

void Entity::stopAnimation()
{
    this->setCurrentFrameIndex(0);

    this->mAnimationRunning = false;
}

/**
 *
 * Checing for touch detector
 *
 */

void Entity::onEnter()
{
    CCSprite::onEnter();
}

void Entity::onExit()
{
    CCSprite::onExit();
}

void Entity::onTouch(CCTouch* touch, CCEvent* event)
{

}

bool Entity::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    this->mStartTouchPoint = touch->getLocation();
    
    if(!this->containsTouchLocation(touch) || !this->isVisible() || !this->getParent()->isVisible())
    {
        return false;
    }

    if(Touchable::ccTouchBegan(touch, event))
    {
        this->mWasTouched = true;

        this->runAction(CCScaleTo::create(this->mAnimationScaleDownTime, this->mAnimationScaleDownFactor));

        return true;
    }

    return false;
}

void Entity::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    if(!containsTouchLocation(touch) || abs(ccpDistance(touch->getLocation(), this->mStartTouchPoint)) >= Utils::coord(30))
    {
        if(this->mWasTouched)
        {
            if(this->getScale() < this->mAnimationScaleUpFactor)
            {
                this->runAction(CCScaleTo::create(this->mAnimationScaleUpTime, this->mAnimationScaleUpFactor));

                this->mWasTouched = false;
            }
        }
    }
}

void Entity::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    if(this->mWasTouched)
    {
        this->onTouch(touch, event);

        this->runAction(CCScaleTo::create(this->mAnimationScaleUpTime, this->mAnimationScaleUpFactor));
    }

    this->mWasTouched = false;
}

bool Entity::containsTouchLocation(CCTouch* touch)
{
    return CCRectMake(-this->mFrameWidth/ 2, -this->mFrameHeight / 2, this->mFrameWidth, this->mFrameHeight).containsPoint(this->convertTouchToNodeSpaceAR(touch));
}

/**
 *
 * Let's take care about object copy
 *
 */

Entity* Entity::deepCopy()
{
    return Entity::create((EntityStructure) {this->mTextureFileName, this->mHorizontalFramesCount, this->mVerticalFramesCount, 0, 0, -1, -1}, NULL);
}

void Entity::update(float pDeltaTime)
{
    if(!this->isVisible()) return;

    if(this->mAnimationStartTimeout >= 0)
    {
        this->mAnimationStartTimeout -= pDeltaTime;
    }
    else
    {
        if(this->mAnimationRunning && (this->mAnimationRepeatCount > 0 || this->mAnimationRepeatCount < 0))
        {
            this->mAnimationTimeElapsed += pDeltaTime;

            if(this->mAnimationTimeElapsed >= this->mAnimationTime)
            {
                this->mAnimationTimeElapsed = 0;

                if(this->mAnimationStartFrame == -1 && this->mAnimationFinishFrame == -1)
                {
                    if(this->mIsAnimationReverse && this->getCurrentFrameIndex() == 0) // TODO: Add animation repeat counter.
                    {
                        this->mAnimationRunning = false;
                        this->mIsAnimationReverse = false;

                        this->mAnimationRunning = false;

                        this->onAnimationEnd();
                            
                        return;
                    }

                    if(this->mAnimationRepeatCount > 0 && this->getCurrentFrameIndex() == this->mFramesCount - 1)
                    {
                        this->mAnimationRepeatCount--;

                        if(this->mAnimationRepeatCount == 0)
                        {
                            if(this->mIsAnimationReverseNeed)
                            {
                                this->mAnimationRepeatCount++;

                                this->mIsAnimationReverseNeed = false;
                                this->mIsAnimationReverse = true;
                        
                                this->previousFrameIndex();

                                return;
                            }
                            else
                            {
                                this->mAnimationRunning = false;

                                this->onAnimationEnd();
                            }
                        }
                    }

                    if(this->getCurrentFrameIndex() == this->mFramesCount - 1)
                    {
                        this->onAnimationCircleEnd();

                        if(this->mPauseBeforeNewAnimationCircleTime > 0)
                        {
                            this->mPauseBeforeNewAnimationCircleTimeElapsed += pDeltaTime;

                            if(this->mPauseBeforeNewAnimationCircleTimeElapsed < this->mPauseBeforeNewAnimationCircleTime)
                            {
                                return;
                            }
                            else
                            {
                                this->mPauseBeforeNewAnimationCircleTimeElapsed = 0;
                            }
                        }
                    }

                    if(this->mIsAnimationReverse)
                    {
                        this->previousFrameIndex();
                    }
                    else
                    {
                        this->nextFrameIndex();
                    }
                }
                else
                {
                    if(this->getCurrentFrameIndex() < this->mAnimationFinishFrame && this->getCurrentFrameIndex() >= this->mAnimationStartFrame)
                    {
                        this->setCurrentFrameIndex(this->mCurrentFrameIndex + (this->mIsAnimationReverse ? -1 : 1));

                        this->mAnimationFramesElapsed += this->mIsAnimationReverse ? -1 : 1;
                        
                        if(this->mIsAnimationReverseNeed && (this->getCurrentFrameIndex() == this->mAnimationFinishFrame || this->getCurrentFrameIndex() == this->mAnimationStartFrame))
                        {
                            this->mIsAnimationReverse = !this->mIsAnimationReverse;
                        }
                    }
                    else
                    {
                        if(this->mAnimationRepeatCount > 0)
                        {
                            this->mAnimationRepeatCount--;

                            this->mAnimationFramesElapsed = 0;

                            if(this->mAnimationRepeatCount == 0)
                            {
                                this->mAnimationRunning = false;

                                this->onAnimationEnd();
                            }
                        }
                        else
                        {
                            if(this->mIsAnimationReverseNeed)
                            {
                                this->mIsAnimationReverse = !this->mIsAnimationReverse;
                                
                                this->setCurrentFrameIndex(this->mAnimationStartFrame + this->mAnimationFramesElapsed + (this->mIsAnimationReverse ? -1 : 1));
                                
                                this->mAnimationFramesElapsed += this->mIsAnimationReverse ? -1 : 1;
                            }
                            else
                            {
                                this->setCurrentFrameIndex(this->mAnimationStartFrame);

                                this->mAnimationFramesElapsed = 0;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Entity::draw()
{
    /*this->glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    this->glBlendEquation(GL_FUNC_ADD);*/

    CCSprite::draw();
}

void Entity::setOpacity(GLubyte pOpaquee)
{
    CCSprite::setOpacity(pOpaquee);

    if(this->mAlphaParent)
    {
        for(int i = 0; i < this->getChildrenCount(); i++)
        {
            Entity* child = (Entity*) this->getChildren()->objectAtIndex(i);

            child->setOpacity(pOpaquee);
        }
    }
}

#endif