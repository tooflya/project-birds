#ifndef CONST_ENTITYMANAGER
#define CONST_ENTITYMANAGER

#include "EntityManager.h"

EntityManager::~EntityManager()
{
    
}

void EntityManager::init(int pCreateCount, int pMaxCount, Entity* pEntity, CCNode* pScreen, int pZOrder)
{
    this->initWithCapacity(pCreateCount);

    this->mZOrder = pZOrder;
    this->mParent = pScreen;
    this->mLastElementNumber = -1;
    this->mCapacity = pCreateCount; // TODO: increase to pMaxCount

    for(int i = 0; i < pCreateCount; i++)
    {
        Entity* currentEntity = pEntity->deepCopy();
        currentEntity->autorelease();
        currentEntity->retain();
        
        currentEntity->setEntityManager(this);
        currentEntity->setEntityManagerId(i);

        this->addObject(currentEntity);

        if(pScreen != NULL)
        {
            this->mParent->addChild(currentEntity, pZOrder);
        }
        
        currentEntity->destroy(false);
    }
}

EntityManager::EntityManager(int pCreateCount, Entity* pEntity)
{
    this->init(pCreateCount, -1, pEntity, NULL, 0);
}

EntityManager::EntityManager(int pCreateCount, Entity* pEntity, CCNode* pScreen)
{
    this->init(pCreateCount, -1, pEntity, pScreen, 0);
}

EntityManager::EntityManager(int pCreateCount, int pMaxCount, Entity* pEntity, CCNode* pScreen)
{
    this->init(pCreateCount, pMaxCount, pEntity, pScreen, 0);
}

EntityManager::EntityManager(int pCreateCount, Entity* pEntity, CCNode* pScreen, int pZOrder)
{
    this->init(pCreateCount, -1, pEntity, pScreen, pZOrder);
}

EntityManager::EntityManager()
{
}

EntityManager* EntityManager::create(int pCreateCount, Entity* pEntity)
{
    EntityManager* manager = new EntityManager(pCreateCount, pEntity);
    manager->autorelease();
    manager->retain();
    
    return manager;
}

EntityManager* EntityManager::create(int pCreateCount, Entity* pEntity, CCNode* pScreen)
{
    EntityManager* manager = new EntityManager(pCreateCount, pEntity, pScreen);
    manager->autorelease();
    manager->retain();
    
    return manager;
}

EntityManager* EntityManager::create(int pCreateCount, int pMaxCount, Entity* pEntity, CCNode* pScreen)
{
    EntityManager* manager = new EntityManager(pCreateCount, pMaxCount, pEntity, pScreen);
    manager->autorelease();
    manager->retain();
    
    return manager;
}

EntityManager* EntityManager::create(int pCreateCount, Entity* pEntity, CCNode* pScreen, int pZOrder)
{
    EntityManager* manager = new EntityManager(pCreateCount, pEntity, pScreen, pZOrder);
    manager->autorelease();
    manager->retain();
    
    return manager;
}

EntityManager* EntityManager::create(int a)
{
    EntityManager* manager = new EntityManager();
    manager->autorelease();
    manager->retain();
    
    return manager;
}

Entity* EntityManager::create()
{
    if (++this->mLastElementNumber < this->mCapacity)
    {
        Entity* object = (Entity*) this->objectAtIndex(this->mLastElementNumber);
        object->create();

        return object;
    }
    
    this->mLastElementNumber--;
    
    return NULL;
    // Create a new object if manager hasn't free object.

    Entity* object = ((Entity*) this->objectAtIndex(0))->deepCopy(); // TODO: Increase CCArray capacity? Really? I think it's works like a charm!

    object->setEntityManager(this);
    object->setEntityManagerId(this->mCapacity);

    this->mParent->addChild(object, this->mZOrder);

    this->addObject(object);

    this->mCapacity++;

    return object->create();
}

void EntityManager::destroy(int pIndex)
{
    if(this->mLastElementNumber >= 0)
    {
        this->exchangeObjectAtIndex(pIndex, this->mLastElementNumber);

        ((Entity*) this->objectAtIndex(pIndex))->setEntityManagerId(pIndex);
        ((Entity*) this->objectAtIndex(this->mLastElementNumber))->setEntityManagerId(this->mLastElementNumber);

        this->mLastElementNumber--;
    }
}

void EntityManager::changeTexture(Texture* pTexture)
{
    for(int i = 0; i < this->getCapacity(); i++)
    {
        ((Entity*) this->objectAtIndex(i))->changeTexture(pTexture);
    }
}

int EntityManager::getCount()
{
    return this->mLastElementNumber + 1;
}

int EntityManager::getCapacity()
{
    return this->mCapacity;
}

void EntityManager::clear() // Some problem in this method with elements which will change and their ID
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

void EntityManager::setParent(CCNode* pScreen, int pZOrder)
{
    this->mParent = pScreen;

    for(int i = 0; i < this->getCapacity(); i++)
    {
        this->mParent->addChild((Entity*) this->objectAtIndex(i), pZOrder);
    }
}

void EntityManager::setParent(CCNode* pScreen)
{
    this->mParent = pScreen;

    for(int i = 0; i < this->getCapacity(); i++)
    {
        this->mParent->addChild((Entity*) this->objectAtIndex(i));
    }
}

void EntityManager::update(float pDeltaTime)
{
}

void EntityManager::release()
{
    CCArray::release();
}

void EntityManager::setOpacity(GLubyte opacity)
{
    for(int i = 0; i < this->mParent->getChildrenCount(); i++)
    {
        static_cast<Entity*>(this->mParent->getChildren()->objectAtIndex(i))->setOpacity(opacity);
    }
}

CCNode* EntityManager::getParent()
{
    return this->mParent;
}

void EntityManager::pauseSchedulerAndActions()
{
    for(int i = 0; i < this->getCapacity(); i++)
    {
        ((Entity*) this->objectAtIndex(i))->retain();
        ((Entity*) this->objectAtIndex(i))->pauseSchedulerAndActions();
    }
}

void EntityManager::resumeSchedulerAndActions()
{
    for(int i = 0; i < this->getCapacity(); i++)
    {
        ((Entity*) this->objectAtIndex(i))->release();
        ((Entity*) this->objectAtIndex(i))->resumeSchedulerAndActions();
    }
}

#endif