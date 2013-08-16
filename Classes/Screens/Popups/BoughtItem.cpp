#ifndef CONST_BOUGHTITEM
#define CONST_BOUGHTITEM

#include "BoughtItem.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

BoughtItem* BoughtItem::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

BoughtItem::~BoughtItem()
{
    this->removeAllChildrenWithCleanup(true);
}

BoughtItem::BoughtItem(CCNode* pParent)
{
    this->initWithColor(ccc4(0.0, 0.0, 0.0, 200.0));

    this->mParent = pParent;

    this->setCascadeOpacityEnabled(true);

    //this->mLights = new EntityManager(2, Entity::create("get_coins_light@2x.png"), this);
    this->mIcon = Entity::create("shop_item_icon@2x.png", 10, 6, this);

    this->mTextes[0] = new Text(Options::TEXT_SHOP_BOUGHT, this);
    this->mTextes[1] = new Text(Options::TEXT_SHOP_BOUGHT, this);

    this->mIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        
    for(int i = 0; i < 2; i++)
     {
        //this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        //static_cast<Entity*>(this->mLights->objectAtIndex(i))->setScale(3.0);
    }

    this->mTextes[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(300));
    this->mTextes[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(380));
    
    this->mHideAnimation = false;
    
    this->scheduleUpdate();
}

BoughtItem* BoughtItem::create(CCNode* pParent)
{
    BoughtItem* popup = new BoughtItem(pParent);
    popup->autorelease();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void BoughtItem::onTouchButtonsCallback(const int pAction, const int pID)
{
    BoughtItem* pSender = static_cast<BoughtItem*>(BoughtItem::m_Instance);
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            default:
                
                //pSender->hide();
                
            break;
        }
        break;
            
        case Options::BUTTONS_ACTION_ONBEGIN:
        break;
            
        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void BoughtItem::show(int pItemId)
{
    this->mParent->addChild(this, 100);

    this->mTextes[0]->setString(Options::TEXT_SHOP_ITEMS[pItemId].string);

    this->mTextes[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(300));
    this->mTextes[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(380));

    this->mIcon->setCurrentFrameIndex(pItemId);

    this->setOpacity(0.0);
    this->runAction(CCFadeTo::create(0.5, 230.0));
}

void BoughtItem::hide()
{
    this->runAction(CCFadeTo::create(0.5, 0.0));

    this->mHideAnimation = true;
    this->mHideAnimationTimeElapsed = 0;
}

void BoughtItem::onShow()
{

}

void BoughtItem::onHide()
{
    this->mHideAnimation = false;

    this->removeFromParentAndCleanup(false);
}

// ===========================================================
// Override Methods
// ===========================================================

void BoughtItem::update(float pDeltaTime)
{
    CCLayerColor::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        //Entity* light = static_cast<Entity*>(this->mLights->objectAtIndex(i));
            
        //light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }

    if(this->mHideAnimation)
    {
        this->mHideAnimationTimeElapsed += pDeltaTime;

        if(this->mHideAnimationTimeElapsed >= 0.5)
        {
            this->mHideAnimationTimeElapsed = 0;

            this->onHide();
        }
    }
}
    
void BoughtItem::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
       
    CCLayer::onEnter();
}
    
void BoughtItem::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
      
    CCLayer::onExit();
}
    
bool BoughtItem::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    return true;
}

#endif