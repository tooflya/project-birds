#ifndef CONST_EVENTPANEL
#define CONST_EVENTPANEL

#include "EventPanel.h"

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

EventPanel::EventPanel(Screen* pParent) :
    Entity("event_panel@2x.png")
    {
        this->mParent = pParent;

        this->mShowed = false;
        this->mLive = false;
        this->mIsShowAnimationRunning = false;
        this->mIsHideAnimationRunning = false;

        this->mShowAnimationTime = 0.5;
        this->mHideAnimationTime = 0.5;

        this->mShowAnimationTimeElapsed = 0;
        this->mHideAnimationTimeElapsed = 0;

        this->mLiveTime = 2.0;
        this->mLiveTimeElapsed = 0;

        this->mIcon = Entity::create("info_panel_btn_sprite@2x.png", 3, 1, this);

        this->mText = Text::create(Options::TEXT_GAME_SOMETHING_WAS_UNLOCKED, this);

        this->mIcon->create()->setCenterPosition(Utils::coord(64), this->getHeight() / 2 + Utils::coord(32));

        this->mText->setCenterPosition(this->getWidth() / 2 + Utils::coord(16), this->getHeight() / 2);
    }

EventPanel* EventPanel::create(Screen *pParent)
{
    EventPanel* panel = new EventPanel(pParent);
    panel->autorelease();
    panel->retain();
    
    return panel;
}

// ===========================================================
// Methods
// ===========================================================

void EventPanel::show()
{
    if(this->mShowed) return;

    this->mShowed = true;

    this->mParent->addChild(this);
    this->runAction(CCMoveTo::create(this->mShowAnimationTime, ccp(this->getCenterX(), Utils::coord(60))));

    this->mIsShowAnimationRunning = true;
}

void EventPanel::hide()
{
    if(!this->mShowed) return;
    
    this->runAction(CCMoveTo::create(this->mShowAnimationTime, ccp(this->getCenterX(), -Utils::coord(100))));

    this->mIsHideAnimationRunning = true;
}

void EventPanel::onShow()
{
    this->mLive = true;
    this->mIsShowAnimationRunning = false;
}

void EventPanel::onHide()
{
    this->mShowed = false;
    this->mIsHideAnimationRunning = false;

    this->removeFromParentAndCleanup(false);
}

EventPanel* EventPanel::setEvent(int pEvent)
{
    if(pEvent < 30)
    {
        this->mIcon->setCurrentFrameIndex(0);
    }
    else if(pEvent < 60)
    {
        this->mIcon->setCurrentFrameIndex(1);
    }
    else
    {
        this->mIcon->setCurrentFrameIndex(2);
    }

    this->mText->setText(Options::TEXT_EVENTS[pEvent]);

    return this;
}

// ===========================================================
// Override Methods
// ===========================================================

void EventPanel::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);

    if(this->mIsShowAnimationRunning)
    {
        this->mShowAnimationTimeElapsed += pDeltaTime;

        if(this->mShowAnimationTimeElapsed >= this->mShowAnimationTime)
        {
            this->mShowAnimationTimeElapsed = 0;

            this->onShow();
        }
    }

    if(this->mIsHideAnimationRunning)
    {
        this->mHideAnimationTimeElapsed += pDeltaTime;

        if(this->mHideAnimationTimeElapsed >= this->mHideAnimationTime)
        {
            this->mHideAnimationTimeElapsed = 0;

            this->onHide();
        }
    }

    if(this->mLive)
    {
        this->mLiveTimeElapsed += pDeltaTime;

        if(this->mLiveTimeElapsed >= this->mLiveTime)
        {
            this->mLive = false;
            this->mLiveTimeElapsed = 0;

            this->hide();
        }
    }
}

#endif