#ifndef CONST_MENU
#define CONST_MENU

#include "Menu.h"

// ===========================================================
// Inner Classes
// ===========================================================

class TwitterButton : public Entity
{
    public:
    TwitterButton(CCNode* pParent) :
    Entity("btn_sprite@2x.png", 2, 3, pParent)
    {
        this->create()->setCurrentFrameIndex(0);
        this->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(270), Utils::coord(100));
        this->setRegisterAsTouchable(true);
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
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        Entity::onExit();
    }
};

class FacebookButton : public Entity
{
    public:
    FacebookButton(CCNode* pParent) :
    Entity("btn_sprite@2x.png", 2, 3, pParent)
    {
        this->create()->setCurrentFrameIndex(2);
        this->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(100), Utils::coord(100));
        this->setRegisterAsTouchable(true);
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
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        Entity::onExit();
    }
};

class SettingsButton : public Entity
{
    public:
    SettingsButton(CCNode* pParent) :
    Entity("btn_sprite@2x.png", 2, 3, pParent)
    {
        this->create()->setCurrentFrameIndex(4);
        this->setCenterPosition(Utils::coord(100), Utils::coord(100));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        Entity::onExit();
    }
};

class PlayButton : public Entity
{
    public:
    PlayButton(CCNode* pParent) :
    Entity("main_menu_btn_play@2x.png", pParent)
    {
        this->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(40), Options::CAMERA_CENTER_Y - Utils::coord(40));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        AppDelegate::screens->set(0.5, Screen::SCREEN_BOXES);
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        Entity::onExit();
    }
};

class ShopButton : public Entity
{
    public:
    ShopButton(CCNode* pParent) :
    Entity("main_menu_btn_shop@2x.png", pParent)
    {
        this->create()->setCenterPosition(Utils::coord(170), Utils::coord(270));
        this->setRotation(10);
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        AppDelegate::screens->set(0.5, Screen::SCREEN_SHOP);
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        Entity::onEnter();
    }
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        Entity::onExit();
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

Menu::Menu()
{
    this->mBackgroundDecoration = new Entity("main_menu_bg_back@2x.png", this);
    this->mBackground = new Entity("main_menu_bg@2x.png", this);
    this->mPlayDecoration = new Entity("main_menu_btn_bg_play@2x.png", this);
    this->mPlayButton = new PlayButton(this);
    this->mShopButton = new ShopButton(this);
    this->mTwitterButton = new TwitterButton(this);
    this->mFacebookButton = new FacebookButton(this);
    this->mSettingsButton = new SettingsButton(this);
    
    this->mBackgroundDecoration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50));
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mPlayDecoration->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(40), Options::CAMERA_CENTER_Y - Utils::coord(40));
    this->mPlayButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(40), Options::CAMERA_CENTER_Y - Utils::coord(40));
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Menu::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    this->mPlayDecoration->setRotation(this->mPlayDecoration->getRotation() + 1.0);
}

#endif