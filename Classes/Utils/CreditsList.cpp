#ifndef CONST_CREDITSLIST
#define CONST_CREDITSLIST

#include "CreditsList.h"

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

CreditsList::CreditsList(CCNode* pParent)
{
    this->scheduleUpdate();
    
    this->mMaxWidth = Utils::coord(750);
    
    this->mPostUpdate = false;
    
    this->mListSroll = new Entity("about_scroll_fill@2x.png", this);
    this->mListSroll->create()->setRepeatTexture(true);
    
    this->mText[0] = new Text(Options::TEXT_CREDITS_STRING_1, this);
    this->mText[1] = new Text(Options::TEXT_CREDITS_STRING_2, this);
    this->mText[2] = new Text(Options::TEXT_CREDITS_STRING_3, this);
    this->mText[3] = new Text(Options::TEXT_CREDITS_STRING_4, this);
    this->mText[4] = new Text(Options::TEXT_CREDITS_STRING_5, this);
    this->mText[5] = new Text(Options::TEXT_CREDITS_STRING_6, this);
    this->mText[6] = new Text(Options::TEXT_CREDITS_STRING_7, this);
    this->mText[7] = new Text(Options::TEXT_CREDITS_STRING_8, this);
    this->mText[8] = new Text(Options::TEXT_CREDITS_STRING_9, this);
    this->mText[9] = new Text(Options::TEXT_CREDITS_STRING_10, this);
    this->mText[10] = new Text(Options::TEXT_CREDITS_STRING_11, this);
    this->mText[11] = new Text(Options::TEXT_CREDITS_STRING_12, this);
    this->mText[12] = new Text(Options::TEXT_CREDITS_STRING_13, this);
    
    this->mText[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(450) - Utils::coord(500));
    this->mText[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(350) - Utils::coord(500));
    this->mText[2]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300) - Utils::coord(500));
    this->mText[3]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200) - Utils::coord(500));
    this->mText[4]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100) - Utils::coord(500));
    this->mText[5]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(50) - Utils::coord(500));
    this->mText[6]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50) - Utils::coord(500));
    this->mText[7]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(100) - Utils::coord(500));
    this->mText[8]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(200) - Utils::coord(500));
    this->mText[9]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(250) - Utils::coord(500));
    this->mText[10]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(300) - Utils::coord(500));
    this->mText[11]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(400) - Utils::coord(500));
    this->mText[12]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(450) - Utils::coord(500));
    
    pParent->addChild(this);
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void CreditsList::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
    
    this->mListSroll->setTextureRect(CCRectMake(0, this->getPosition().y, this->mListSroll->getTextureRect().size.width, Utils::coord(891)));
    
    this->mListSroll->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(50) - this->getPosition().y);
    
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

bool CreditsList::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    this->mPostUpdate = false;
    
    this->stopAllActions();
    
    this->mStartCoordinateY = touch->getLocation().y;
    this->mStartPositionCoordinateY = this->getPosition().y;
    
    return this->containsTouchLocation(touch);
}

void CreditsList::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    if(this->containsTouchLocation(touch))
    {
        float y = this->mStartPositionCoordinateY + touch->getLocation().y - this->mStartCoordinateY;
        
        this->setPosition(ccp(this->getPosition().x, y));
    }
}

void CreditsList::ccTouchEnded(CCTouch* touch, CCEvent* event)
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

bool CreditsList::containsTouchLocation(CCTouch* touch)
{
    float y = touch->getLocation().y;
    
    if(y > Utils::coord(200))
        return true;
    
    return false;
}

void CreditsList::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    CCLayer::onEnter();
}

void CreditsList::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    
    CCLayer::onExit();
}

void CreditsList::visit()
{
    glEnable(GL_SCISSOR_TEST);
    
    CCEGLView::sharedOpenGLView()->setScissorInPoints(0, Options::CAMERA_CENTER_Y - Utils::coord(395), Options::CAMERA_WIDTH, Options::CAMERA_CENTER_Y + Utils::coord(250));
    
    CCLayer::visit();
    
    glDisable(GL_SCISSOR_TEST);
}

#endif