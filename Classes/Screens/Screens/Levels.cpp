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
    Text* mText;
    
    public:
    LevelButton() : Entity("choose_box_lvl_sprite@2x.png", 3, 5)
    {
        //this->setRegisterAsTouchable(true);
        
        this->mText = new Text((Textes) {"0", Options::FONT, 64, -1}, this);
    }
    
    void setId(int pId)
    {
        this->mId = pId;
        
        this->mText->setString(Utils::intToString(this->mId).c_str());
        this->mText->setCenterPosition(this->getWidth() / 2, this->getHeight() / 2);
        
        /*if(this->mId > 10)
        {
            this->setCurrentFrameIndex(12);
            
            this->mText->setVisible(false);
        }
        else
        {
            this->setCurrentFrameIndex(0);
            
            this->mText->setVisible(true);
        }*/
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

class MainList : public CCLayer
{
    public:

        CCLayer* mLayers[Levels::LEVEL_PACKS_COUNT];

        float mListInitialCenterX;
        float mListInitialCenterY;

        float mStartCoordinateY;
        float mStartCoordinateX;

        float mStartPositionCoordinateY;
        float mStartPositionCoordinateX;

        float mLastDistanceX;
        float mLastDistanceY;

        float mSpeedX;
        float mSpeedY;

        float mMinWidth;
        float mMinHeight;

        float mMaxWidth;
        float mMaxHeight;

        bool mPostUpdate;

        Levels* mParent;

        MainList(Levels* pParent)
        {
            this->mParent = pParent;

            for(int i = 0; i < Levels::LEVEL_PACKS_COUNT; i++)
            {
                this->mLayers[i] = CCLayer::create();

                this->mLayers[i]->setPosition(ccp(Options::CAMERA_WIDTH/1.2 * i, 0));

                this->addChild(this->mLayers[i]);
            }

            this->mMinWidth = Options::CAMERA_CENTER_X / 2;
            this->mMaxWidth = -Options::CAMERA_WIDTH * Levels::LEVEL_PACKS_COUNT + Options::CAMERA_WIDTH * 1.5;

            this->mPostUpdate = false;

            this->scheduleUpdate();
        }

    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        CCLayer::onEnter();
    }

    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        CCLayer::onExit();
    }

    bool containsTouchLocation(CCTouch* touch)
    {
        float x = touch->getLocation().x;
        float y = touch->getLocation().y;

        return y < Options::CAMERA_CENTER_Y + Utils::coord(400) && y > Options::CAMERA_CENTER_Y - Utils::coord(400);
    }

    bool ccTouchBegan(CCTouch* touch, CCEvent* event)
    {
        this->stopAllActions();

        this->mPostUpdate = false;
        
        this->mStartCoordinateX = touch->getLocation().x;
        this->mStartCoordinateY = touch->getLocation().y;

        this->mStartPositionCoordinateX = this->getPosition().x;
        this->mStartPositionCoordinateY = this->getPosition().y;

        return this->containsTouchLocation(touch);
    }

    void ccTouchMoved(CCTouch* touch, CCEvent* event)
    {
        if(this->containsTouchLocation(touch))
        {
            float x, y;
            
            x = this->mStartPositionCoordinateX + touch->getLocation().x - this->mStartCoordinateX;
            y = this->getPosition().y;

            if(x < this->mMinWidth && x > this->mMaxWidth)
            {
            }
            else
            {
                x = this->getPosition().x;
                y = this->getPosition().y;
            }
            
            this->setPosition(ccp(x, y));
        }
    }

    void ccTouchEnded(CCTouch* touch, CCEvent* event)
    {
        float x = this->getPosition().x;
        float y = this->getPosition().y;

        this->mLastDistanceX = this->mStartPositionCoordinateX - x;
        this->mLastDistanceY = this->mStartPositionCoordinateY - y;

        this->mSpeedX = abs(this->mLastDistanceX) / 1000.0;
        this->mSpeedY = abs(this->mLastDistanceY) / 1000.0;

        float n = x;

        while((int)n % (int)(Options::CAMERA_CENTER_X* 1.66) != 0)
        {
            n += this->mLastDistanceX > 0 ? -1 : 1;
        }

        this->mPostUpdate = true;
        
        mSpeedX = 0.5;


        if(n < this->mMinWidth)
         {
         }
        else
         {
            n = 0;
         }

        if(n > this->mMaxWidth)
         {
         }
        else
         {
            n = this->mMaxWidth + Options::CAMERA_CENTER_X * 0.7;
         }

        for(int i = 0; i < Levels::LEVEL_PACKS_COUNT; i++)
        {
            static_cast<Entity*>(this->mParent->mSlides->objectAtIndex(i))->setCurrentFrameIndex(0);
        }
        
        int index = abs((int)n / (int)(Options::CAMERA_CENTER_X* 1.66));

        static_cast<Entity*>(this->mParent->mSlides->objectAtIndex(index))->setCurrentFrameIndex(1);

        this->runAction(CCMoveTo::create(this->mSpeedX, ccp(n, 0)));
    }

    void update(float pDeltaTime)
    {
            for(int i = 0; i < Levels::LEVEL_PACKS_COUNT; i++)
            {
                float rotation = (this->getPosition().x + this->mLayers[i]->getPosition().x) / 10.0;
                float scale = 1.0 - abs(this->getPosition().x + this->mLayers[i]->getPosition().x) / 500.0;

                scale = scale > 1.0 ? 1.0 : scale;
                scale = scale < 0.0 ? 0.0 : scale;

                this->mLayers[i]->setScale(scale);
                this->mLayers[i]->setRotation(rotation);
            }

            if(this->mPostUpdate)
            {
                float x = this->getPosition().x;
                float y = this->getPosition().y;

                if(x < this->mMinWidth)
                {
                }
                else
                {
                    this->mPostUpdate = false;

                    this->stopAllActions();

                    this->runAction(CCMoveTo::create(0.5, ccp(0, 0)));
                }
            }
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
    this->mMainList = new MainList(this);

    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_LEVELS_BACK, onTouchButtonsCallback);
    this->mTablet = new Entity("shop_money_bg@2x.png", this);
    this->mStarsCountIcon = new Entity("end_lvl_star_sprite@2x.png", 3, 2, this->mTablet);
    this->mSlides = new BatchEntityManager(6, new Entity("choose_box_navi_sprite@2x.png", 1, 2), this);

    this->mStarsCountText = new Text((Textes) {"206", Options::FONT, 64, -1}, this->mTablet);

    this->addChild(this->mMainList);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackButton->create()->setCurrentFrameIndex(1);
    this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));
    this->mTablet->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(110));
    this->mStarsCountIcon->create()->setCenterPosition(this->mTablet->getWidth() / 2 - Utils::coord(100), this->mTablet->getHeight() / 2);
    this->mStarsCountText->setCenterPosition(this->mTablet->getWidth() / 2 + Utils::coord(10), this->mTablet->getHeight() / 2);

    this->mStarsCountIcon->setCurrentFrameIndex(1);
    this->mStarsCountIcon->setScale(0.5);
    
    /** Organization of level icons */

    float startX = Options::CAMERA_CENTER_X;
    float startY = Options::CAMERA_CENTER_Y + Utils::coord(150) * 2;

    float x = startX;
    float y = startY;
    
    int id = 0;
    
    for(int o = 0; o < LEVEL_PACKS_COUNT; o++)
    {
        this->mLevels[o] = new EntityManager(16, new LevelButton(), this->mMainList->mLayers[o]);

        for(int i = 0; i < 4; i++)
        {
            x = startX - Utils::coord(120) * 2;
            
            for(int j = 0; j < 4; j++)
            {
                LevelButton* item = (LevelButton*) this->mLevels[o]->create();
                
                item->create()->setCenterPosition(x, y);
                item->setId(++id);
                
                x += Utils::coord(160);
            }
            
            y -= Utils::coord(180);
        }

        x = startX;
        y = startY;
    }

    /** Organization of slider icons */

    x = Options::CAMERA_CENTER_X;
    y = Options::CAMERA_CENTER_Y - Utils::coord(400);

    for(int i = -LEVEL_PACKS_COUNT / 2; i < LEVEL_PACKS_COUNT / 2; i++)
    {
        x = Options::CAMERA_CENTER_X + Utils::coord(25) + Utils::coord(50) * i;

        this->mSlides->create()->setCenterPosition(x, y);
    }

    static_cast<Entity*>(this->mSlides->objectAtIndex(0))->setCurrentFrameIndex(1);

    /** Experiments */
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
    
    /*for(int i = 0; i < 20; i++)
    {
        LevelButton* item = (LevelButton*) this->mLevels->objectAtIndex(i);
        
        item->setScale(0.0);
        item->runAction(CCScaleTo::create(0.6, 1.0));
    }*/
}

void Levels::onExit()
{
    Screen::onExit();
}

#endif