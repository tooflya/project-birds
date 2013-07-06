#ifndef CONST_SETTINGS
#define CONST_SETTINGS

#include "Settings.h"

// ===========================================================
// Inner Classes
// ===========================================================

class BackButton : public Entity
{
    public:
    BackButton(CCNode* pParent) :
    Entity("btn_sprite@2x.png", 2, 3, pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Utils::coord(100), Utils::coord(100));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class CreditsButton : public Entity
{
    public:
    CCLabelTTF* mText;
    
    CreditsButton(CCNode* pParent) :
    Entity("settings_btn_big@2x.png", pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));
        this->setRegisterAsTouchable(true);
        
        this->mText = CCLabelTTF::create("credits", "Apple Casual", Utils::coord(100));
        this->mText->setPosition(ccp(this->getWidth() / 2, this->getHeight() / 2));
        
        this->addChild(this->mText);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class RateButton : public Entity
{
    public:
    CCLabelTTF* mText;
    
    RateButton(CCNode* pParent) :
    Entity("settings_btn_big@2x.png", pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->setRegisterAsTouchable(true);
        
        this->mText = CCLabelTTF::create("rate", "Apple Casual", Utils::coord(100));
        this->mText->setPosition(ccp(this->getWidth() / 2, this->getHeight() / 2));
        
        this->addChild(this->mText);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class SoundButton : public Entity
{
    public:
    SoundButton(CCNode* pParent) :
    Entity("btn_mfx_sprite@2x.png", 2, 2, pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(300));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        Options::SOUND_ENABLE = !Options::SOUND_ENABLE;
        
        if(Options::SOUND_ENABLE)
        {
            this->setCurrentFrameIndex(1);
        }
        else
        {
            this->setCurrentFrameIndex(3);
        }
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

class MusicButton : public Entity
{
    public:
    MusicButton(CCNode* pParent) :
    Entity("btn_mfx_sprite@2x.png", 2, 2, pParent)
    {
        this->create()->setCurrentFrameIndex(0);
        this->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(110), Options::CAMERA_CENTER_Y - Utils::coord(300));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        Options::MUSIC_ENABLE = !Options::MUSIC_ENABLE;
        
        if(Options::MUSIC_ENABLE)
        {
            this->setCurrentFrameIndex(0);
        }
        else
        {
            this->setCurrentFrameIndex(2);
        }
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
};

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Settings::Settings()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new BackButton(this);
    this->mRateButton = new RateButton(this);
    this->mCreditsButton = new CreditsButton(this);
    this->mSoundButton = new SoundButton(this);
    this->mMusicButton = new MusicButton(this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

#endif