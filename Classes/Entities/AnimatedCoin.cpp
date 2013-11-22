#ifndef CONST_ANIMATEDCOIN
#define CONST_ANIMATEDCOIN

#include "AnimatedCoin.h"

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

AnimatedCoin::AnimatedCoin(const char* pTextureFileName, float pScaleFactor) :
	mScaleFactor(0),
    ImpulseEntity(pTextureFileName, 5, 4)
    {
        this->mScaleFactor = pScaleFactor;
        
        this->animate(0.01);
    }

AnimatedCoin* AnimatedCoin::create(const char* pTextureFileName, float pScaleFactor)
{
    AnimatedCoin* coin = new AnimatedCoin(pTextureFileName, pScaleFactor);
    coin->autorelease();

    return coin;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void AnimatedCoin::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime);
}

void AnimatedCoin::onCreate()
{
    ImpulseEntity::onCreate();

    this->setCenterPosition(Utils::randomf(Options::CAMERA_WIDTH - Utils::coord(350), Options::CAMERA_WIDTH - Utils::coord(100)), Utils::randomf(Options::CAMERA_HEIGHT - Utils::coord(200), Options::CAMERA_HEIGHT - Utils::coord(100)));

    this->mWeight = Utils::coord(1500.0f);
    this->mImpulsePower = Utils::coord(Utils::randomf(200.0f, 800.0f));
    this->mSideImpulse = Utils::coord(Utils::randomf(-200.0f, 500.0f));
    this->mRotateImpulse = Utils::randomf(-160.0, 160.0);
    
    if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPAD_RETINA)
    {
        this->mSideImpulse *= 2.0;
    }

    this->setScale(0);
    this->runAction(CCScaleTo::create(1.0, this->mScaleFactor));

    if(Options::SOUND_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_COINS[Utils::random(0, 3)]);
    }
}

void AnimatedCoin::onDestroy()
{
    ImpulseEntity::onDestroy();
}

AnimatedCoin* AnimatedCoin::deepCopy()
{
    return AnimatedCoin::create(this->mTextureFileName, this->mScaleFactor);
}

#endif