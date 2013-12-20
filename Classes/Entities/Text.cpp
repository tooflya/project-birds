#ifndef CONST_TEXT
#define CONST_TEXT

#include "Text.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Text::ID = 0;

Text* Text::TEXTES[1024] = {};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Text::~Text()
{
    TEXTES[this->mId] = NULL;
    ID--;
}

Text::Text(const char* pString, float pSize, CCNode* pParent) :
	mId(0),
	mInitCenterX(0),
	mInitCenterY(0)
    {
		this->initWithString(pString, Options::FONT, Utils::coord(pSize), CCSize(0, 0), kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
		this->enableShadow();
    
		this->mId = 0;
    
		TEXTES[ID] = this;
    
		ID++;
        
		pParent->addChild(this);
        
        this->mType1AnimationRunning = false;
        this->mType2AnimationRunning = false;
        
        this->mIsAnyAnimationRunning = false;
	}

Text::Text(Textes pParams, CCNode* pParent) :
	mId(0),
	mInitCenterX(0),
    mInitCenterY(0)
    {
		this->initWithString(pParams.string, pParams.font, Utils::coord(pParams.size), CCSize(0, 0), kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
		this->enableShadow();
    
		this->mId = pParams.identifier;
    
		TEXTES[ID] = this;
    
		ID++;
        
		pParent->addChild(this);
        
        this->mType1AnimationRunning = false;
        this->mType2AnimationRunning = false;
        
        this->mIsAnyAnimationRunning = false;
	}

Text::Text(Textes pParams, const CCSize pDimensions, CCNode* pParent) :
	mId(0),
	mInitCenterX(0),
    mInitCenterY(0)
    {
		this->initWithString(pParams.string, pParams.font, Utils::coord(pParams.size), pDimensions, kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
		this->enableShadow();
    
		this->mId = pParams.identifier;
    
		TEXTES[ID] = this;
    
		ID++;
        
		pParent->addChild(this);
        
        this->mType1AnimationRunning = false;
        this->mType2AnimationRunning = false;
        
        this->mIsAnyAnimationRunning = false;
	}

Text* Text::create(const char* pString, float pSize, CCNode* pParent)
{
    Text* text = new Text(pString, pSize, pParent);
    text->autorelease();
    
    return text;
}

Text* Text::create(Textes pParams, CCNode* pParent)
{
    Text* text = new Text(pParams, pParent);
    text->autorelease();
    
    return text;
}

Text* Text::create(Textes pParams, const CCSize pDimensions, CCNode* pParent)
{
    Text* text = new Text(pParams, pDimensions, pParent);
    text->autorelease();
    
    return text;
}

// ===========================================================
// Methods
// ===========================================================

void Text::setCenterPosition(float pCenterX, float pCenterY)
{
    #if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    pCenterX -= 1.0;
    pCenterY += 4.0;
    #elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    pCenterX -= 2.0;
    #endif
    
    this->mInitCenterX = pCenterX;
    this->mInitCenterY = pCenterY;
    
    CCLabelTTF::setPosition(ccp(pCenterX, pCenterY));
}

void Text::setPosition(float pX, float pY)
{
    this->mInitCenterX = pX + this->getWidth() / 2;
    this->mInitCenterY = pY - this->getHeight() / 2;
    
    CCLabelTTF::setPosition(ccp(pX - this->getWidth() / 2, pY + this->getHeight() / 2));
}

void Text::changeLanguage()
{
    if(this->mId != -1 && this->mId >= 1 && this->getParent())
    {
        this->setString(Options::TEXTES_HOLDER[this->mId].string);
        this->setFontSize(Utils::coord(Options::TEXTES_HOLDER[this->mId].size));
        this->setFontName(Options::TEXTES_HOLDER[this->mId].font);
    }
}

float Text::getWidth()
{
    return this->getContentSize().width;
}

float Text::getHeight()
{
    return this->getContentSize().height;
}

float Text::getCenterX()
{
    return this->getPosition().x;
}

float Text::getCenterY()
{
    return this->getPosition().y;
}

void Text::setText(Textes pParams)
{
    this->setString(pParams.string);
    this->setFontSize(Utils::coord(pParams.size));
    this->setFontName(pParams.font);
}

void Text::enableShadow()
{
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    CCLabelTTF::enableShadow(CCSize(Utils::coord(2), -Utils::coord(2)), 255.0, 2.0, true);

    #endif
}

void Text::animate(int pType)
{
    if(this->mIsAnyAnimationRunning) return;
    
    this->mIsAnyAnimationRunning = true;
    
    switch(pType)
    {
        case 0:
            this->mType1AnimationRunning = true;
            
            this->mType1AnimationCount = 0;
            this->mType1AnimationTimeElapsed = 0;
            
            this->mType1AnimationTime = 0.2;
            this->runAction(CCScaleTo::create(this->mType1AnimationTime, 1.1));
            break;
        case 1:
            this->mType2AnimationCount = 0;
            this->mType2AnimationTimeElapsed = 0;
            
            this->mType2AnimationTime = 0.2;
            
            this->mType2AnimationRunning = true;
            this->runAction(CCScaleTo::create(this->mType2AnimationTime, 1.1));
            break;
    }
    
    this->scheduleUpdate();
}

// ===========================================================
// Override Methods
// ===========================================================

void Text::update(float pDeltaTime)
{
    CCLabelTTF::update(pDeltaTime);
    
    if(this->mType1AnimationRunning)
    {
        this->mType1AnimationTimeElapsed += pDeltaTime;
        
        if(this->mType1AnimationTimeElapsed >= this->mType1AnimationTime)
        {
            this->mType1AnimationTimeElapsed = 0;
            
            switch(this->mType1AnimationCount)
            {
                case 0:
                    this->mType1AnimationTime = 0.2;
                    this->runAction(CCScaleTo::create(this->mType1AnimationTime, 0.9, 0.8));
                    break;
                case 1:
                    this->mType1AnimationTime = 0.2;
                    this->runAction(CCScaleTo::create(this->mType1AnimationTime, 1.0, 1.0));
                    break;
                case 2:
                    this->mType1AnimationRunning = false;
                    
                    this->unscheduleUpdate();
                    this->unscheduleAllSelectors();
                    
                    this->mIsAnyAnimationRunning = false;
                    break;
            }
            
            this->mType1AnimationCount++;
        }
    }
    
    if(this->mType2AnimationRunning)
    {
        this->mType2AnimationTimeElapsed += pDeltaTime;
        
        if(this->mType2AnimationTimeElapsed >= this->mType2AnimationTime)
        {
            this->mType2AnimationTimeElapsed = 0;
            
            switch(this->mType2AnimationCount)
            {
                case 0:
                    this->mType2AnimationTime = 0.2;
                    this->runAction(CCScaleTo::create(this->mType2AnimationTime, 1.0));
                    break;
                case 1:
                    this->mType2AnimationRunning = false;
                    
                    this->unscheduleUpdate();
                    this->unscheduleAllSelectors();
                    
                    this->mIsAnyAnimationRunning = false;
                    break;
            }
            
            this->mType2AnimationCount++;
        }
    }
}

void Text::onEnter()
{
    CCLabelTTF::onEnter();
}

void Text::onExit()
{
    CCLabelTTF::onExit();
}

#endif