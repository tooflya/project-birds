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

Button::Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, void (*pOnTouchCallback)(int, int)) :
	Entity(pTextureFileName, pHorizontalFramesCount, mVerticalFramesCount, pParent)
	{
		this->mOnTouchCallback = pOnTouchCallback;

		this->mID = pButtonID;

    	this->setRegisterAsTouchable(true);
	}

// ===========================================================
// Methods
// ===========================================================
    
void Button::onTouch(CCTouch* touch, CCEvent* event)
{
	if(this->mOnTouchCallback != 0)
    {
        this->mOnTouchCallback(Options::BUTTONS_ACTION_ONTOUCH, this->mID);
    }
}

void Button::setText(const char* pString, int pSize)
{
	this->mText = CCLabelTTF::create(pString, "Apple casual", pSize);
	this->mText->setPosition(ccp(this->getWidth() / 2, this->getHeight() / 2));
	this->mText->enableShadow(CCSize(0, 1), 255.0, 0.0, true);
	this->addChild(this->mText);
}

void Button::setString(const char* pString)
{
	this->mText->setString(pString);
}

// ===========================================================
// Virtual Methods
// ===========================================================
    
void Button::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
    Entity::onEnter();
}
    
void Button::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
        
    Entity::onExit();
}

#endif