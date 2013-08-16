#ifndef CONST_BUTTON
#define CONST_BUTTON

#include "Button.h"

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

void Button::constructor(const int pButtonID, void (*pOnTouchCallback)(int, int))
{
        this->mOnTouchCallback = pOnTouchCallback;

        this->mID = pButtonID;

        this->mText = NULL;

        this->setRegisterAsTouchable(true);
}

Button::Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int)) :
    Entity(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount, pParent)
    {
        this->constructor(pButtonID, pOnTouchCallback);
    }

Button::Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, const int pButtonID, void (*pOnTouchCallback)(int, int)) :
    Entity(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount)
    {
        this->constructor(pButtonID, pOnTouchCallback);
    }

Button::Button(const EntityStructure pEntityStructure, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int)) :
    Entity(pEntityStructure, pParent)
    {
        this->constructor(pButtonID, pOnTouchCallback);
    }



Button* Button::create(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int))
{
    Button* button = new Button(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount, pParent, pButtonID, pOnTouchCallback);
    button->autorelease();
    
    return button;
}

Button* Button::create(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, const int pButtonID, void (*pOnTouchCallback)(int, int))
{
    Button* button = new Button(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount, pButtonID, pOnTouchCallback);
    button->autorelease();
    
    return button;
}

Button* Button::create(const EntityStructure pEntityStructure, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int))
{
    Button* button = new Button(pEntityStructure, pParent, pButtonID, pOnTouchCallback);
    button->autorelease();
    
    return button;
}

// ===========================================================
// Methods
// ===========================================================
    
void Button::onTouch(CCTouch* touch, CCEvent* event)
{
    if(this->mOnTouchCallback != 0)
    {
        if(Options::SOUND_ENABLE)
        {
            SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_TAP);
        }
        
        this->mOnTouchCallback(Options::BUTTONS_ACTION_ONTOUCH, this->mID);
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
    
    this->mText = new Text(pParams, parent);
    this->mText->setCenterPosition(this->getCenterX(), this->getCenterY());
}

void Button::setString(const char* pString)
{
    this->mText->setString(pString);
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
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);

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
    return new Button(this->mTextureFileName, this->mHorizontalFramesCount, this->mVerticalFramesCount, this->mID, this->mOnTouchCallback);
}

#endif