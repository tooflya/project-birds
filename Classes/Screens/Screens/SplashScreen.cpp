#ifndef CONST_SPLASHSCREEN
#define CONST_SPLASHSCREEN

#include "SplashScreen.h"
#include "Loading.h"

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

SplashScreen::~SplashScreen()
{
    CC_SAFE_RELEASE(this->mNextScreen);
}

SplashScreen::SplashScreen() :
mLogos()
{
    this->mAnimationCounter = 0;
    
    this->mAnimation = false;
    
    this->mAnimationTime = 1.0;
    this->mAnimationTimeElapsed = 0;
    
    CCLayerColor* layer = CCLayerColor::create(ccc4(255, 255, 255, 255));
    this->mLogos[0] = Entity::create("splash_logo_abs.png", layer);
    this->mLogos[1] = Entity::create("splash_logo_tfl.png", layer);
    
    this->addChild(layer);
    
    this->mNextScreen = Loading::create();
    this->mNextScreen->retain();
}

SplashScreen* SplashScreen::create()
{
    SplashScreen* screen = new SplashScreen();
    screen->autorelease();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void SplashScreen::onEnter()
{
    Screen::onEnter();
    
    this->mAnimation = true;
}

void SplashScreen::onExit()
{
    Screen::onExit();
}

void SplashScreen::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    if(this->mAnimation)
    {
        this->mAnimationTimeElapsed += pDeltaTime;
        
        if(this->mAnimationTimeElapsed >= this->mAnimationTime)
        {
            this->mAnimationTimeElapsed = 0;
            this->mAnimationCounter++;
            
            switch(this->mAnimationCounter)
            {
                case 1:
                    this->mLogos[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
                    this->mLogos[0]->setOpacity(0);
                    this->mLogos[0]->runAction(CCFadeIn::create(this->mAnimationTime));
                break;
                case 3:
                    this->mLogos[0]->runAction(CCFadeOut::create(this->mAnimationTime));
                    
                    this->mAnimationTime = 0.8;
                break;
                case 5:
                    this->mAnimationTime = 1.0;
                    
                    this->mLogos[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
                    this->mLogos[1]->setOpacity(0);
                    this->mLogos[1]->runAction(CCFadeIn::create(this->mAnimationTime));
                break;
                case 7:
                    this->mLogos[1]->runAction(CCFadeOut::create(this->mAnimationTime));
                break;
                case 8:
                    this->mAnimation = false;
                    
                    
                    float pAnimationTime = 0.5;
                    
                    CCTransitionScene* transition = CCTransitionFade::create(pAnimationTime, this->mNextScreen);
                    
                    CCDirector::sharedDirector()->pushScene(transition);
                break;
            }
        }
    }
}

#endif