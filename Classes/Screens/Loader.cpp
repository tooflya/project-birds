#ifndef CONST_LOADER
#define CONST_LOADER

#include "Loader.h"

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

Loader::Loader()
{
	this->mLoadingText = CCLabelTTF::create("Loading... 0%", "Apple Casual", Utils::coord(32));
    this->mLoadingText->setPosition(ccp(Options::CAMERA_WIDTH - Utils::coord(140), Utils::coord(50)));
    
    this->addChild(this->mLoadingText);
}

// ===========================================================
// Methods
// ===========================================================


// ===========================================================
// Virtual Methods
// ===========================================================

void Loader::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    this->mLoadingTime += pDeltaTime;
    
    if(this->mLoadingTime >= 0.02 && this->mLoadingPercentrage < 100)
    {
        this->mLoadingTime = 0;
        
        this->mLoadingText->setString(("Loading... " + Utils::intToString(++this->mLoadingPercentrage) + "%").c_str());
        
        if(this->mLoadingPercentrage >= 100)
        {
            AppDelegate::screens->set(0.5, Screen::SCREEN_LEVEL);
        }
    }
}

void Loader::onEnter()
{
    Screen::onEnter();
    
    this->mLoadingPercentrage = 0;
    this->mLoadingTime = 0;
}

#endif