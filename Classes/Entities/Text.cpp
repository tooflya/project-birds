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
    #if  CC_TARGET_PLATFORM == CC_PLATFORM_MAC
    pCenterX -= 1.0;
    pCenterY += 4.0;
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
    if(Options::TEXTES_HOLDER[this->mId].size != 0 && this->mId != -1 && this->mId >= 1)
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
    
    if(this->mShadow != NULL)
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

// ===========================================================
// Override Methods
// ===========================================================

void Text::onEnter()
{
    CCLabelTTF::onEnter();
    
    this->retain();
}

void Text::onExit()
{
    CCLabelTTF::onExit();
    
    /** Some leaks here */
    
    //TEXTES[this->mId] = NULL;
    
    //this->release();
    
    ID--;
}

void Text::draw()
{
    CCLabelTTF::draw();
}

#endif