#ifndef CONST_BUYITEMLIST
#define CONST_BUYITEMLIST

#include "BuyItemList.h"

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

BuyItemList::BuyItemList(CCNode* pParent)
{
    this->scheduleUpdate();
    
    this->mMaxWidth = Utils::coord(750);
    
    this->mPostUpdate = false;
    
    this->mListSroll = new Entity("about_scroll_fill_small@2x.png", this);
    this->mListSroll->create()->setRepeatTexture(true);
    
    pParent->addChild(this);
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void BuyItemList::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
    
    this->mListSroll->setTextureRect(CCRectMake(0, this->getPosition().y, this->mListSroll->getTextureRect().size.width, Utils::coord(640)));
    
    this->mListSroll->setCenterPosition(((Entity*) this->getParent())->getWidth() / 2, ((Entity*) this->getParent())->getHeight() / 2 - this->getPosition().y + Utils::coord(25));
    
    if(this->mPostUpdate && false)
    {
        float x = this->getPosition().x - this->mPostUpdatePower;
        
        if(x >= 0) x = 0;
        //if(x <= -this->mMaxWidth) x = -this->mMaxWidth;
        
        this->setPosition(ccp(x, this->getPosition().y));
        
        this->mPostUpdatePower = this->mPostUpdatePower > 0 ? this->mPostUpdatePower - 1.0 : this->mPostUpdatePower + 1.0;
        
        if(abs(this->mPostUpdatePower) < Utils::coord(2.0))
        {
            int x = floor(this->getPosition().x);
            
            if(abs(x) % (int) floor(Utils::coord(230)) >= 1.0)
            {
                this->mPostUpdatePower = this->mPostUpdatePower < 0 ? this->mPostUpdatePower - 1.0 : this->mPostUpdatePower + 1.0;
            }
            else
            {
                this->mPostUpdatePower = 0;
            }
        }
        
        if(this->mPostUpdatePower == 0)
        {
            this->mPostUpdate = false;
        }
    }
}

bool BuyItemList::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    this->mPostUpdate = false;
    
    this->stopAllActions();
    
    this->mStartCoordinateY = touch->getLocation().y;
    this->mStartPositionCoordinateY = this->getPosition().y;
    
    return this->containsTouchLocation(touch);
}

void BuyItemList::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    if(this->containsTouchLocation(touch))
    {
        float y = this->mStartPositionCoordinateY + touch->getLocation().y - this->mStartCoordinateY;
        
        this->setPosition(ccp(this->getPosition().x, y));
    }
}

void BuyItemList::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
    float y = this->getPosition().y;
    
    if(y < 0)
    {
        this->runAction(CCMoveTo::create(0.3, ccp(this->getPosition().x, 0)));
    }
    else if(y > this->mMaxWidth)
    {
        this->runAction(CCMoveTo::create(0.3, ccp(this->getPosition().x, this->mMaxWidth)));
    }
    else
    {
        float distance = (this->mStartCoordinateY - touch->getLocation().y) / 10.0;
        
        if(abs(distance) < Utils::coord(10.0)) return;
        
        int t = distance > 0 ? 1 : -1;
        
        this->mPostUpdatePower = abs(floor(distance)) > Utils::coord(30.0) ? Utils::coord(30.0) * t : floor(distance);
        
        this->mPostUpdate = true;
    }
}

bool BuyItemList::containsTouchLocation(CCTouch* touch)
{
    float y = touch->getLocation().y;
    
    if(y > Utils::coord(200) && ((Popup*) this->getParent()->getParent())->mShowed)
        return true;
    
    return false;
}

void BuyItemList::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    CCLayer::onEnter();
}

void BuyItemList::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    
    CCLayer::onExit();
}

void BuyItemList::visit()
{
    /*glEnable(GL_SCISSOR_TEST);
    
    CCEGLView::sharedOpenGLView()->setScissorInPoints(0, Options::CAMERA_CENTER_Y - Utils::coord(295), Options::CAMERA_WIDTH, Utils::coord(640));
    
    CCLayer::visit();
    
    glDisable(GL_SCISSOR_TEST);*/
    
    CCLayer::visit();
}

#endif