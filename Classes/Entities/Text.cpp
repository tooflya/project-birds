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

Text* Text::TEXTES[512] =
{
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Text::~Text()
{
    if(this->mShadow != NULL)
    {
        this->mShadow->removeFromParentAndCleanup(true);
        
        this->mShadow = NULL;
    }

    TEXTES[this->mId] = NULL;
    ID--;
    
    CCLog(ccsf("DEALLOCING OF TEXT with string: %s", this->getString()));
}

Text::Text(const char* pString, float pSize, CCNode* pParent) :
	mId(0),
	mInitCenterX(0),
	mInitCenterY(0)
    {
        this->mShadow = NULL;
    
		this->initWithString(pString, Options::FONT, Utils::coord(pSize), CCSize(0, 0), kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
		this->enableShadow();
    
		this->mId = 0;
    
		TEXTES[ID] = this;
    
		ID++;
        
        this->mShadow = CCLabelTTF::create(pString, Options::FONT, Utils::coord(pSize), CCSize(0, 0), kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
        this->mShadow->setColor(ccc3(0, 0, 0));
        pParent->addChild(this->mShadow);
        
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
        this->mShadow = NULL;
    
		this->initWithString(pParams.string, pParams.font, Utils::coord(pParams.size), CCSize(0, 0), kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
		this->enableShadow();
    
		this->mId = pParams.identifier;
    
		TEXTES[ID] = this;
    
		ID++;
        
        this->mShadow = CCLabelTTF::create(pParams.string, pParams.font, Utils::coord(pParams.size), CCSize(0, 0), kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
        this->mShadow->setColor(ccc3(0, 0, 0));
        pParent->addChild(this->mShadow);
        
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
        this->mShadow = NULL;
    
		this->initWithString(pParams.string, pParams.font, Utils::coord(pParams.size), pDimensions, kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
		this->enableShadow();
    
		this->mId = pParams.identifier;
    
		TEXTES[ID] = this;
    
		ID++;
        
        this->mShadow = CCLabelTTF::create(pParams.string, pParams.font, Utils::coord(pParams.size), pDimensions, kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
        this->mShadow->setColor(ccc3(0, 0, 0));
        pParent->addChild(this->mShadow);
        
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
    
    if(this->mShadow != NULL)
    {
        this->mShadow->setPosition(ccp(pCenterX + Utils::coord(1), pCenterY - Utils::coord(1)));
    }
}

void Text::setPosition(float pX, float pY)
{
    this->mInitCenterX = pX + this->getWidth() / 2;
    this->mInitCenterY = pY - this->getHeight() / 2;
    
    CCLabelTTF::setPosition(ccp(pX - this->getWidth() / 2, pY + this->getHeight() / 2));
    
    if(this->mShadow != NULL)
    {
        this->mShadow->setPosition(ccp(pX - this->getWidth() / 2 + Utils::coord(1), pY + this->getHeight() / 2 - Utils::coord(1)));
    }
}

void Text::changeLanguage()
{
    if(Options::TEXTES_HOLDER[this->mId].size != 0 && this->mId != -1 && this->mId >= 1 && this->getParent())
    {
        this->setString(Options::TEXTES_HOLDER[this->mId].string);
        this->setFontSize(Utils::coord(Options::TEXTES_HOLDER[this->mId].size));
        this->setFontName(Options::TEXTES_HOLDER[this->mId].font);

        if(this->mShadow != NULL)
        {
            this->mShadow->setString(Options::TEXTES_HOLDER[this->mId].string);
            this->mShadow->setFontSize(Utils::coord(Options::TEXTES_HOLDER[this->mId].size));
            this->mShadow->setFontName(Options::TEXTES_HOLDER[this->mId].font);
        }
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
    
    this->mShadow->setString(pParams.string);
    this->mShadow->setFontSize(Utils::coord(pParams.size));
    this->mShadow->setFontName(pParams.font);
}

void Text::setString(const char* str)
{
    CCLabelTTF::setString(str);
    
    if(this->mShadow != NULL && this->mShadow)
    {
        this->mShadow->setString(str);
        this->mShadow->setFontSize(this->getFontSize());
        this->mShadow->setFontName(this->getFontName());
        
        this->mShadow->setVisible(this->isVisible());
    }
}

void Text::setVisible(bool pVisible)
{
    CCLabelTTF::setVisible(pVisible);
    
    if(this->mShadow != NULL)
    {
        this->mShadow->setVisible(pVisible);
    }
}

void Text::setScale(float pScale)
{
    CCLabelTTF::setScale(pScale);
    
    if(this->mShadow != NULL)
    {
        this->mShadow->setScale(pScale);
    }
}

void Text::setOpacity(GLubyte pOpaquee)
{
    CCLabelTTF::setOpacity(pOpaquee);
    
    if(this->mShadow != NULL)
    {
        this->mShadow->setOpacity(pOpaquee);
    }
}

void Text::runAction(CCAction* pAction)
{
    CCLabelTTF::runAction(pAction);
    
    if(this->mShadow != NULL)
    {
        this->mShadow->runAction(static_cast<CCAction*>(pAction->copy()));
    }
}

void Text::enableShadow()
{
    /*#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS

    CCLabelTTF::enableShadow(CCSize(Utils::coord(2), -Utils::coord(2)), 255.0, 0.0, true);

    #endif*/
}

void Text::disableShadow()
{
    if(this->mShadow != NULL)
    {
        this->mShadow->removeFromParentAndCleanup(true);
        
        this->mShadow = NULL;
    }
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
            this->mShadow->runAction(CCScaleTo::create(this->mType1AnimationTime, 1.1));
            break;
        case 1:
            this->mType2AnimationCount = 0;
            this->mType2AnimationTimeElapsed = 0;
            
            this->mType2AnimationTime = 0.2;
            
            this->mType2AnimationRunning = true;
            this->runAction(CCScaleTo::create(this->mType2AnimationTime, 1.1));
            this->mShadow->runAction(CCScaleTo::create(this->mType2AnimationTime, 1.1));
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
                    this->mShadow->runAction(CCScaleTo::create(this->mType1AnimationTime, 0.9, 0.8));
                    break;
                case 1:
                    this->mType1AnimationTime = 0.2;
                    this->runAction(CCScaleTo::create(this->mType1AnimationTime, 1.0, 1.0));
                    this->mShadow->runAction(CCScaleTo::create(this->mType1AnimationTime, 1.0, 1.0));
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
                    this->mShadow->runAction(CCScaleTo::create(this->mType2AnimationTime, 1.0));
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
    
    //this->retain();
}

void Text::onExit()
{
    CCLabelTTF::onExit();
    
    /** Some leaks here */
    
    //TEXTES[this->mId] = NULL;
    
    //this->release();
    
    //ID--;
}

void Text::draw()
{
    CCLabelTTF::draw();
}

#endif