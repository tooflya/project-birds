#ifndef CONST_LEVELS
#define CONST_LEVELS

#include "Levels.h"

// ===========================================================
// Inner Classes
// ===========================================================

class LevelsBackButton : public Entity
{
public:
    LevelsBackButton(CCNode* pParent) :
    Entity("btn_sprite@2x.png", 2, 3, pParent)
    {
        this->create()->setCurrentFrameIndex(1);
        this->setCenterPosition(Utils::coord(100), Utils::coord(100));
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

class LevelButton : public Entity
{
    protected:
    int mId;
    CCLabelTTF* mText;
    
    public:
    LevelButton() : Entity("choose_box_lvl_sprite@2x.png", 3, 2)
    {
        this->setRegisterAsTouchable(true);
        
        this->mText = CCLabelTTF::create("0", "Apple Casual", Utils::coord(64));
        
        this->addChild(this->mText);
    }
    
    void setId(int pId)
    {
        this->mId = pId;
        
        this->mText->setString(("" + Utils::intToString(this->mId)).c_str());
        this->mText->setPosition(ccp(this->getWidth() / 2, this->getHeight() / 2));
        
        if(this->mId > 10)
        {
            this->setCurrentFrameIndex(3);
            
            this->mText->setVisible(false);
        }
        else
        {
            this->setCurrentFrameIndex(0);
            
            this->mText->setVisible(true);
        }
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
    
    LevelButton* deepCopy()
    {
        return new LevelButton();
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

Levels::Levels()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new LevelsBackButton(this);
    
    this->mLevels = new EntityManager(20, new LevelButton(), this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    float x = 0;
    float y = Options::CAMERA_CENTER_Y + Utils::coord(200) * 2;
    
    int id = 0;
    
    for(int i = 0; i < 5; i++)
    {
        x = Options::CAMERA_CENTER_X - Utils::coord(120) * 2;
        
        for(int j = 0; j < 4; j++)
        {
            LevelButton* item = (LevelButton*) this->mLevels->create();
            
            item->create()->setCenterPosition(x, y);
            item->setId(++id);
            
            x += Utils::coord(160);
        }
        
        y -= Utils::coord(180);
    }
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

void Levels::onEnter()
{
    Screen::onEnter();
    
    for(int i = 0; i < 20; i++)
    {
        Entity* item = (Entity*) this->mLevels->objectAtIndex(i);
        
        item->setScale(0.0);
        item->runAction(CCScaleTo::create(0.6, 1.0));
    }
}

void Levels::onExit()
{
    Screen::onExit();
}

#endif