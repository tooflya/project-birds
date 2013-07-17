#ifndef CONST_LEVELS
#define CONST_LEVELS

#include "Levels.h"

// ===========================================================
// Inner Classes
// ===========================================================

class LevelButton : public Entity
{
    protected:
    int mId;
    CCLabelTTF* mText;
    
    public:
    LevelButton() : Entity("choose_box_lvl_sprite@2x.png", 3, 5)
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
            this->setCurrentFrameIndex(12);
            
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
        AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
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

Levels* Levels::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Levels::Levels()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_LEVELS_BACK, onTouchButtonsCallback);
    this->mTablet = new Entity("shop_money_bg@2x.png", this);
    this->mStarsCountIcon = new Entity("end_lvl_star_sprite@2x.png", 3, 2, this->mTablet);

    this->mStarsCountText = new Text((Textes) {"206", Options::FONT, Utils::coord(64), -1}, this->mTablet);
    
    this->mLevels = new EntityManager(20, new LevelButton(), this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackButton->create()->setCurrentFrameIndex(1);
    this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));
    this->mTablet->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(110));
    this->mStarsCountIcon->create()->setCenterPosition(this->mTablet->getWidth() / 2 - Utils::coord(100), this->mTablet->getHeight() / 2);
    this->mStarsCountText->setCenterPosition(this->mTablet->getWidth() / 2 + Utils::coord(10), this->mTablet->getHeight() / 2);

    this->mStarsCountIcon->setCurrentFrameIndex(1);
    this->mStarsCountIcon->setScale(0.5);
    
    float x = 0;
    float y = Options::CAMERA_CENTER_Y + Utils::coord(180) * 2;
    
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

void Levels::onTouchButtonsCallback(const int pAction, const int pID)
{
    Levels* pSender = (Levels*) Levels::m_Instance;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_LEVELS_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MODE);

                break;
            }
        break;

        case Options::BUTTONS_ACTION_ONBEGIN:
        break;

        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Levels::onEnter()
{
    Screen::onEnter();
    
    for(int i = 0; i < 20; i++)
    {
        LevelButton* item = (LevelButton*) this->mLevels->objectAtIndex(i);
        
        item->setScale(0.0);
        item->runAction(CCScaleTo::create(0.6, 1.0));
    }
}

void Levels::onExit()
{
    Screen::onExit();
}

#endif