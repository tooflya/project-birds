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
}

Text::Text(const char* pString, float pSize, CCNode* pParent)
{
    this->initWithString(pString, Options::FONT, Utils::coord(pSize), CCSize(0, 0), kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
    this->enableShadow();
    
    this->mId = 0;
    
    pParent->addChild(this);
    
    TEXTES[ID] = this;
    
    ID++;
}

Text::Text(Textes pParams, CCNode* pParent)
{
    this->initWithString(pParams.string, pParams.font, Utils::coord(pParams.size), CCSize(0, 0), kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
    this->enableShadow();
    
    this->mId = pParams.identifier;
    
    pParent->addChild(this);
    
    TEXTES[ID] = this;
    
    ID++;
}

Text::Text(Textes pParams, const CCSize pDimensions, CCNode* pParent)
{
    this->initWithString(pParams.string, pParams.font, Utils::coord(pParams.size), pDimensions, kCCTextAlignmentCenter, kCCVerticalTextAlignmentTop);
    this->enableShadow();
    
    this->mId = pParams.identifier;
    
    pParent->addChild(this);
    
    TEXTES[ID] = this;
    
    ID++;
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
    if(Options::TEXTES_HOLDER[this->mId].size != 0 && this->mId != -1)
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

    CCLabelTTF::enableShadow(CCSize(Utils::coord(2), -Utils::coord(2)), 255.0, 0.0, true);

    #endif
}

void Text::disableShadow()
{
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

    CCLabelTTF::disableShadow();

    #endif
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
}

#endif