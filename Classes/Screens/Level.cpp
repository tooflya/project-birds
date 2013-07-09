#ifndef CONST_LEVEL
#define CONST_LEVEL

#include "Level.h"

// ===========================================================
// Inner Classes
// ===========================================================

class LevelPauseButton : public Entity
{
public:
    LevelPauseButton(CCNode* pParent) :
    Entity("game_gui_btn_sprite@2x.png", 2, 1, pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(70), Options::CAMERA_HEIGHT - Utils::coord(50));
        this->setRegisterAsTouchable(true);
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        ((Level*) this->getParent())->finish();SimpleAudioEngine::sharedEngine()->playBackgroundMusic("level-end.mp3");
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

class LevelResratButton : public Entity
{
public:
    LevelResratButton(CCNode* pParent) :
    Entity("game_gui_btn_sprite@2x.png", 2, 1, pParent)
    {
        this->create()->setCurrentFrameIndex(0);
        this->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(50));
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

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Level::Level()
{
    this->mFinishPopup = new End(this);
    
    this->mBackground = new Entity("game_gui_bg_summer@2x.png", this);
    
    this->mPauseButton = new LevelPauseButton(this);
    this->mRestartButton = new LevelResratButton(this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
}

// ===========================================================
// Methods
// ===========================================================

void Level::start()
{
    
}

void Level::finish()
{
    this->mFinishPopup->show();
}

// ===========================================================
// Virtual Methods
// ===========================================================

void Level::onEnter()
{
    Screen::onEnter();
}

void Level::onExit()
{
    Screen::onExit();
}

#endif