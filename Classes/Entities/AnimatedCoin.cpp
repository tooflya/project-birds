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

AnimatedCoin::AnimatedCoin() :
    ImpulseEntity("coins@2x.png", 5, 4)
    {
        this->animate(0.01);
    }

AnimatedCoin* AnimatedCoin::create()
{
    AnimatedCoin* coin = new AnimatedCoin();
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

    this->setScale(0);
    this->runAction(CCScaleTo::create(1.0, 1.6));

    if(Options::SOUND_ENABLE)
    {
        const char* a[] = {"berry_count_ind_a.mp3", "berry_count_ind_b.mp3", "berry_count_ind_c.mp3", "berry_count_ind_d.mp3"};
        SimpleAudioEngine::sharedEngine()->playEffect(a[Utils::random(0, 3)]);
    }
}

void AnimatedCoin::onDestroy()
{
    ImpulseEntity::onDestroy();
}

AnimatedCoin* AnimatedCoin::deepCopy()
{
    return AnimatedCoin::create();
}

#endif