#ifndef CONST_BATCHENTITYMANAGER
#define CONST_BATCHENTITYMANAGER

#include "BatchEntityManager.h"

BatchEntityManager::BatchEntityManager(int pCreateCount, Entity* pEntity, CCNode* pScreen) :
    CCSpriteBatchNode(),
	mLastElementNumber(0),
	mCapacity(0),
	mInitCapacity(0)
    {
        this->initWithTexture(pEntity->getTexture(), 50);
        
        this->mInitCapacity = pCreateCount;

        this->mLastElementNumber = -1;
        this->mCapacity = pCreateCount; // TODO: increase to pMaxCount

        for(int i = 0; i < pCreateCount; i++)
        {Entity* currentEntity;
            if(i == 0)
                 currentEntity = pEntity;
                else
                 currentEntity = pEntity->deepCopy();

            currentEntity->setEntityManager(this);
            currentEntity->setEntityManagerId(i);

          
        
            currentEntity->destroy(false);


            if(dynamic_cast<CCSpriteBatchNode*>(pScreen) != NULL)
            {
                pScreen->addChild(currentEntity); 
            }
            else
            {
                  this->addChild(currentEntity);
            }
        
        }

        if(pScreen != NULL)
        {
            if(dynamic_cast<CCSpriteBatchNode*>(pScreen) == NULL)
            {
                pScreen->addChild(this, 0); 
            }
            else
            {
                pScreen->getParent()->addChild(this);
            }
        }

        this->autorelease();
    }

Entity* BatchEntityManager::create()
{
    if (++this->mLastElementNumber < this->mCapacity)
    {
        Entity* object = (Entity*) this->objectAtIndex(this->mLastElementNumber);
        object->create();

        return object;
    }

    // Create a new object if manager hasn't free object.

    Entity* object = ((Entity*) this->objectAtIndex(0))->deepCopy(); // TODO: Increase CCArray capacity? Really? I think it's works like a charm!

    object->setEntityManager(this);
    object->setEntityManagerId(this->mCapacity);

    this->addChild(object);

    this->mCapacity++;

    return object->create();
}

void BatchEntityManager::destroy(int pIndex)
{
    if(this->mLastElementNumber >= 0)
    {
        this->getChildren()->exchangeObjectAtIndex(pIndex, this->mLastElementNumber);

        ((Entity*) this->objectAtIndex(pIndex))->setEntityManagerId(pIndex);
        ((Entity*) this->objectAtIndex(this->mLastElementNumber))->setEntityManagerId(this->mLastElementNumber);

        this->mLastElementNumber--;
    }
}

void BatchEntityManager::clear() // Some problem in this method with elements which will change and their ID
{
    for(int i = 0; i < this->getCapacity(); i++)
    {
        ((Entity*) this->objectAtIndex(i))->destroy(true);
    }

    for(int i = 0; i < this->getCapacity(); i++)
    {
        ((Entity*) this->objectAtIndex(i))->destroy();
    }
}

int BatchEntityManager::getCount()
{
    return this->mLastElementNumber + 1;
}

int BatchEntityManager::getCapacity()
{
    return this->mCapacity;
}

CCObject* BatchEntityManager::objectAtIndex(int pIndex)
{
    return this->getChildren()->objectAtIndex(pIndex);
}

void BatchEntityManager::pauseSchedulerAndActions()
{
    for(int i = 0; i < this->getCapacity(); i++)
    {
        ((Entity*) this->objectAtIndex(i))->pauseSchedulerAndActions();
    }
}

void BatchEntityManager::resumeSchedulerAndActions()
{
    for(int i = 0; i < this->getCapacity(); i++)
    {
        ((Entity*) this->objectAtIndex(i))->resumeSchedulerAndActions();
    }
}

int BatchEntityManager::getInitCapacity()
{
    return this->mInitCapacity;
}

void BatchEntityManager::setOpacity(GLbyte pOpacity)
{
    for(int i = 0; i < this->getCapacity(); i++)
    {
        static_cast<Entity*>(this->objectAtIndex(i))->setOpacity(pOpacity);
    }
}

void BatchEntityManager::draw()
{
    //if(this->getCount() <= 0) return;
    
    CCSpriteBatchNode::draw();
}

void BatchEntityManager::update(float pDeltaTime)
{
    CCSpriteBatchNode::update(pDeltaTime);
}

#endif