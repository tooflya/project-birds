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

    this->mLights = new BatchEntityManager(2, Entity::create("get_coins_light@2x.png"), this);
    this->mIcon = Entity::create("shop_item_icon@2x.png", 10, 6, this);

  //  this->mTwitterButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 0, 0, 162, 162}, this, Options::BUTTONS_ID_MENU_TWITTER, onTouchButtonsCallback);
   // this->mFacebookButton = Button::create("share.png", 1, 1, this, Options::BUTTONS_ID_MENU_FACEBOOK, onTouchButtonsCallback);

    this->mTextes[0] = new Text(Options::TEXT_SHOP_BOUGHT, this);
    this->mTextes[1] = new Text(Options::TEXT_SHOP_BOUGHT, this);
    this->mTextes[2] = new Text(Options::TEXT_TAP_TO_CONTINUE, this);

    this->mIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

 //   this->mTwitterButton->create()->setCenterPosition(Utils::coord(270), Utils::coord(100));
    //this->mFacebookButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
        
    for(int i = 0; i < 2; i++)
     {
        this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        static_cast<Entity*>(this->mLights->objectAtIndex(i))->setScale(3.0);
    }

    this->mTextes[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(300));
    this->mTextes[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(380));
    this->mTextes[2]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(450));
    
    this->mTapToContinueAnimationReverse = false;
    this->mHideAnimation = false;
}

BoughtItem* BoughtItem::create(CCNode* pParent)
{
    BoughtItem* popup = new BoughtItem(pParent);
    popup->autorelease();
    popup->retain();
    
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
    this->mLights->setOpacity(0.0);
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
        Entity* light = static_cast<Entity*>(this->mLights->objectAtIndex(i));
            
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
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

    this->mLights->setOpacity(this->getOpacity());
    
    if(true)
    {
        if(this->mTapToContinueAnimationReverse)
        {
            this->mTextes[2]->setOpacity(this->mTextes[2]->getOpacity() - 5.0);
            
            if(this->mTextes[2]->getOpacity() <= 20.0)
            {
                this->mTapToContinueAnimationReverse = !this->mTapToContinueAnimationReverse;
            }
        }
        else
        {
            this->mTextes[2]->setOpacity(this->mTextes[2]->getOpacity() + 5.0);
            
            if(this->mTextes[2]->getOpacity() >= 245.0)
            {
                this->mTapToContinueAnimationReverse = !this->mTapToContinueAnimationReverse;
            }
        }
    }
}
    
void BoughtItem::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
       
    CCLayer::onEnter();
    
    this->scheduleUpdate();
}
    
void BoughtItem::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
      
    CCLayer::onExit();

    this->stopAllActions();
    this->unscheduleAllSelectors();
}
    
bool BoughtItem::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    return true;
}

#endif