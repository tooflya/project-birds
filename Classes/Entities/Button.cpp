#ifndef CONST_BUTTON
#define CONST_BUTTON

#include "Button.h"

USING_NS_CC;

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

void Button::constructor(const int pButtonID, ButtonReceiver* pSender)
{
    this->mSender = pSender;

    this->mID = pButtonID;

    this->mText = NULL;
    this->mIsModal = false;

    this->setRegisterAsTouchable(true);
}

Button::Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, ButtonReceiver* pSender) :
    Entity(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount, pParent),
	mID(0),
	mSender(0),
	mText(0),
	mIsModal(0)
    {
        this->constructor(pButtonID, pSender);
    }

Button::Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, const int pButtonID, ButtonReceiver* pSender) :
    Entity(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount),
	mID(0),
	mSender(0),
	mText(0),
	mIsModal(0)
    {
        this->constructor(pButtonID, pSender);
    }

Button::Button(const EntityStructure pEntityStructure, CCNode* pParent, const int pButtonID, ButtonReceiver* pSender) :
    Entity(pEntityStructure, pParent),
	mID(0),
	mSender(0),
	mText(0),
	mIsModal(0)
    {
        this->constructor(pButtonID, pSender);
    }



Button* Button::create(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, ButtonReceiver* pSender)
{
    Button* button = new Button(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount, pParent, pButtonID, pSender);
    button->autorelease();
    
    return button;
}

Button* Button::create(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, const int pButtonID, ButtonReceiver* pSender)
{
    Button* button = new Button(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount, pButtonID, pSender);
    button->autorelease();
    
    return button;
}

Button* Button::create(const EntityStructure pEntityStructure, CCNode* pParent, const int pButtonID, ButtonReceiver* pSender)
{
    Button* button = new Button(pEntityStructure, pParent, pButtonID, pSender);
    button->autorelease();
    
    return button;
}

// ===========================================================
// Methods
// ===========================================================
    
void Button::onTouch(CCTouch* touch, CCEvent* event)
{
    if(true)
    {
        if(Options::SOUND_ENABLE)
        {
            SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_TAP);
        }
        
        this->mSender->onTouchButtonsCallback(Options::BUTTONS_ACTION_ONTOUCH, this->mID);
    }
}

void Button::setText(Textes pParams)
{
    if(this->mText != NULL)
    {
        this->mText->removeFromParent();
    }

    CCNode* parent;
    
    if(this->getParent()->getParent())
    {
        parent = this->getParent()->getParent();
    }
    else
    {
        parent = this->getParent();
    }
    
    this->mText = Text::create(pParams, parent);
    this->mText->setCenterPosition(this->getCenterX(), this->getCenterY());
}

void Button::setString(const char* pString)
{
    this->mText->setString(pString);
}

void Button::setModal(bool pIsModal)
{
    this->mIsModal = pIsModal;
}

// ===========================================================
// Override Methods
// ===========================================================

void Button::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);

    if(this->mText)
    {
        this->mText->setScale(this->getScaleX());
        this->mText->setVisible(this->isVisible());
    }
}
void Button::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, this->mIsModal);

    Entity::onEnter();
}
    
void Button::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    
    Entity::onExit();
}

Entity* Button::create()
{
    return Entity::create();
}

Button* Button::deepCopy()
{
    return new Button(this->mTextureFileName, this->mHorizontalFramesCount, this->mVerticalFramesCount, this->mID, this->mSender);
}

#endif