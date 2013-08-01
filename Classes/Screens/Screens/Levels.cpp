#ifndef CONST_LEVELS
#define CONST_LEVELS

#include "Levels.h"

// ===========================================================
// Inner Classes
// ===========================================================

class ListLayer : public CCLayer
{
    public:
    
        int mType;
        int mParentType;

        float mWidth;
        float mHeight;

        float mMaxWidth;
        float mMaxHeight;

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
    
        bool mPostUpdate;
        
        ListLayer()
        {

        }

        void visit()
        {
            kmGLPushMatrix();
            glEnable(GL_SCISSOR_TEST);

            CCEGLView::sharedOpenGLView()->setScissorInPoints(0, Options::CAMERA_CENTER_Y - Utils::coord(295), Options::CAMERA_WIDTH, Options::CAMERA_CENTER_Y - Utils::coord(20));

            CCNode::visit();
            glDisable(GL_SCISSOR_TEST);
            kmGLPopMatrix();
        }

        void onEnter()
        {
            CCDirector* pDirector = CCDirector::sharedDirector();
            pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
            
            CCLayer::onEnter();
        }

        void onExit()
        {
            CCDirector* pDirector = CCDirector::sharedDirector();
            pDirector->getTouchDispatcher()->removeDelegate(this);
            
            CCLayer::onExit();
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

                x = this->getPosition().x;
                y = this->mStartPositionCoordinateY + touch->getLocation().y - this->mStartCoordinateY;
                
                this->setPosition(ccp(x, y));
            }
        }

        void ccTouchEnded(CCTouch* touch, CCEvent* event)
        {
            float x = this->getPosition().x;
            float y = this->getPosition().y;

            bool kWillPostUpdate = true;

            if(y < 0)
            {
                //this->runAction(CCMoveTo::create(0.3, ccp(x, 0)));

                kWillPostUpdate = false;
            }
            else if(y > this->mMaxHeight)
            {
                //this->runAction(CCMoveTo::create(0.3, ccp(x, this->mMaxHeight)));

                kWillPostUpdate = false;
            }

            if(x > 0)
            {
                //this->runAction(CCMoveTo::create(0.3, ccp(0, y)));

                kWillPostUpdate = false;
            }
            else if(x < -this->mMaxWidth)
            {
                //this->runAction(CCMoveTo::create(0.3, ccp(this->mMaxWidth, y)));

                kWillPostUpdate = false;
            }

            this->mLastDistanceX = this->mStartPositionCoordinateX - x; // TODO: Check it!
            this->mLastDistanceY = this->mStartPositionCoordinateY - y;

            this->mPostUpdate = false;//kWillPostUpdate;

            this->mSpeedY = this->mLastDistanceY / 10.0;
        }

        bool containsTouchLocation(CCTouch* touch)
        {
            float x = touch->getLocation().x;
            float y = touch->getLocation().y;
            
            //return x > this->mListInitialCenterX - this->mWidth / 2 && x < this->mListInitialCenterX + this->mWidth / 2 && y < this->mListInitialCenterY + this->mHeight / 2 && y > this->mListInitialCenterY - this->mHeight / 2;
            
            return true;
        }
};

class LevelButton : public Entity
{
    protected:
    int mId;
    Text* mText;
    
    public:
    LevelButton() : Entity("choose_box_lvl_sprite@2x.png", 3, 5)
    {
        this->setRegisterAsTouchable(true);
        
        this->mText = new Text((Textes) {"0", Options::FONT, 64, -1}, this);
    }
    
    void setId(int pId)
    {
        this->mId = pId;
        
        this->mText->setString(Utils::intToString(this->mId).c_str());
        this->mText->setCenterPosition(this->getWidth() / 2, this->getHeight() / 2);
        
        int stars = AppDelegate::getLevelStars(this->mId);

        if(stars == -1)
        {
            this->setCurrentFrameIndex(12);

            this->mText->setVisible(false);
        }
        else
        {
            this->setCurrentFrameIndex(stars * 3);
        }
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        if(this->getCurrentFrameIndex() == 12)
        {
            
        }
        else
        {
            AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
        }
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
        
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

        EntityManager* mListBorders;
        EntityManager* mElements;

        MainList(Levels* pParent)
        {
            this->mParent = pParent;

            this->mLayers[0] = CCLayer::create();
            
            //ListLayer* a = new ListLayer();

            for(int i = 1; i < Levels::LEVEL_PACKS_COUNT; i++)
            {
                this->mLayers[i] = CCLayer::create();

                this->mLayers[i]->setPosition(ccp(Options::CAMERA_WIDTH/1.2 * (i-1), 0)); // TODO: Return * i

                this->addChild(this->mLayers[i]);
            }

            //this->mListBorders = new EntityManager(2, new Entity("about_scroll_border@2x.png"), this->mLayers[0]);
            //this->mElements = new EntityManager(3, new Entity("more_games_list@2x.png", 1, 3), a);
            
            //this->mLayers[0]->addChild(a);

            //this->mListBorders->create();
            //this->mListBorders->create();
            
            //((Entity*) this->mListBorders->objectAtIndex(0))->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(330));
            //((Entity*) this->mListBorders->objectAtIndex(1))->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(300));
            
            //((Entity*) this->mListBorders->objectAtIndex(0))->setScaleY(1);
            //((Entity*) this->mListBorders->objectAtIndex(1))->setScaleY(-1);

            int f = 0;
            /*for(int i = 1; i > -2; i--)
            {
                Entity* element = static_cast<Entity*>(this->mElements->create());

                element->setCurrentFrameIndex(f++);
                element->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(220) * i);
            }*/

            //Text* text1 = new Text(Options::TEXT_MORE_GAMES, this->mLayers[0]);

            //text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(390));

            this->mMinWidth = Options::CAMERA_CENTER_X / 2;
            this->mMaxWidth = -Options::CAMERA_WIDTH * Levels::LEVEL_PACKS_COUNT + Options::CAMERA_WIDTH * 1.5;

            this->mPostUpdate = false;

            this->scheduleUpdate();
        }

    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
        
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
        if(this->containsTouchLocation(touch))
        {
            this->stopAllActions();

            this->mPostUpdate = false;
            
            this->mStartCoordinateX = touch->getLocation().x;
            this->mStartCoordinateY = touch->getLocation().y;

            this->mStartPositionCoordinateX = this->getPosition().x;
            this->mStartPositionCoordinateY = this->getPosition().y;
        
            this->mParent->mBackgroundDecorations[2]->setCurrentFrameIndex(1);
            this->mParent->mBackgroundDecorations[3]->setVisible(false);
            this->mParent->mBackgroundDecorations[4]->setVisible(true);

            return true;
        }

        return false;
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

        if(index == 0)
        {
            static_cast<Entity*>(this->mParent->mSlidesArrows->objectAtIndex(0))->runAction(CCFadeTo::create(0.5, 0.0));
        }
        else
        {
            static_cast<Entity*>(this->mParent->mSlidesArrows->objectAtIndex(0))->runAction(CCFadeTo::create(0.5, 255.0));
        }

        if(index == Levels::LEVEL_PACKS_COUNT-1)
        {
            static_cast<Entity*>(this->mParent->mSlidesArrows->objectAtIndex(1))->runAction(CCFadeTo::create(0.5, 0.0));
        }
        else
        {
            static_cast<Entity*>(this->mParent->mSlidesArrows->objectAtIndex(1))->runAction(CCFadeTo::create(0.5, 255.0));
        }
        t= 0;
        this->runAction(CCMoveTo::create(this->mSpeedX, ccp(n, 0)));
    }
    float t;
    void update(float pDeltaTime)
    {
            for(int i = 0; i < Levels::LEVEL_PACKS_COUNT; i++)
            {
                float rotation = (this->getPosition().x + this->mLayers[i]->getPosition().x) / 10.0;
                float alpha = 255.0 - abs(this->getPosition().x + this->mLayers[i]->getPosition().x) / 1.0;
                float scale = 1.0 - abs(this->getPosition().x + this->mLayers[i]->getPosition().x) / 500.0;

                scale = scale > 1.0 ? 1.0 : scale;
                scale = scale < 0.0 ? 0.0 : scale;

                alpha = alpha > 255.0 ? 255.0 : alpha;
                alpha = alpha < 0.0 ? 0.0 : alpha;

                //if(i > 0)
                {
                    this->mLayers[i]->setScale(scale);
                    this->mLayers[i]->setRotation(rotation);
                }
                /*else
                {
                    for(int j = 0; j < static_cast<CCLayer*>(this->mLayers[i]->getChildren()->objectAtIndex(2))->getChildrenCount(); j++)
                    {
                        static_cast<Entity*>(static_cast<CCLayer*>(this->mLayers[i]->getChildren()->objectAtIndex(2))->getChildren()->objectAtIndex(j))->setOpacity(alpha);
                    }
                    
                    for(int j = 0; j < this->mLayers[i]->getChildrenCount(); j++)
                    {
                        static_cast<Entity*>(this->mLayers[i]->getChildren()->objectAtIndex(j))->setOpacity(alpha);
                    }
                }*/
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

                t += pDeltaTime;

                if(t >= 0.5)
                {
                    this->mParent->mBackgroundDecorations[2]->setCurrentFrameIndex(0);
                    this->mParent->mBackgroundDecorations[3]->setVisible(true);
                    this->mParent->mBackgroundDecorations[4]->setVisible(false);

                    this->mPostUpdate = false;
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
    this->mBackButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, this, Options::BUTTONS_ID_LEVELS_BACK, onTouchButtonsCallback);
    this->mShopButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 324, 324, 162, 162}, this, Options::BUTTONS_ID_MENU_SHOP, onTouchButtonsCallback);
    this->mTablet = new Entity("shop_money_bg@2x.png", this);
    this->mBackgroundDecorations[0] = new Entity("bg_detail_stripe@2x.png", this);
    this->mBackgroundDecorations[1] = new Entity("bg_detail_choose_bird@2x.png", this);
    this->mStarsCountIcon = new Entity("end_lvl_star_sprite@2x.png", 3, 2, this->mTablet);
    this->mSlides = new BatchEntityManager(6, new Entity("choose_box_navi_sprite@2x.png", 1, 2), this);

    this->mStarsCountText = new Text((Textes) {"206", Options::FONT, 64, -1}, this->mTablet);

    this->addChild(this->mMainList->mLayers[0]);
    this->addChild(this->mMainList);

    this->mSlidesArrows = new BatchEntityManager(2, new Entity((EntityStructure) {"btn_sprite@2x.png", 1, 1, 324, 162, 162, 162}, NULL), this);
    
    this->mBackgroundDecorations[2] = new Entity("bg_detail_lamp@2x.png", 1, 2, this);
    this->mBackgroundDecorations[3] = new Entity("bg_detail_dark@2x.png", this);
    this->mBackgroundDecorations[4] = new Entity("popup_darkness@2x.png", this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
    //this->mShopButton->create()->setCenterPosition(Utils::coord(65), Options::CAMERA_HEIGHT - Utils::coord(65)); // TODO: Change icon coordinates.
    this->mTablet->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(170));
    this->mStarsCountIcon->create()->setCenterPosition(this->mTablet->getWidth() / 2 - Utils::coord(100), this->mTablet->getHeight() / 2);
    this->mStarsCountText->setCenterPosition(this->mTablet->getWidth() / 2 + Utils::coord(10), this->mTablet->getHeight() / 2);

    this->mStarsCountIcon->setCurrentFrameIndex(1);
    this->mStarsCountIcon->setScale(0.5);
    
    this->mBackgroundDecorations[0]->create()->setCenterPosition(Utils::coord(192), Options::CAMERA_HEIGHT - Utils::coord(103));
    this->mBackgroundDecorations[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(155), Utils::coord(138));
    this->mBackgroundDecorations[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(63));
    this->mBackgroundDecorations[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(192));
    this->mBackgroundDecorations[4]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

    this->mBackgroundDecorations[3]->setOpacity(50);
    this->mBackgroundDecorations[4]->setOpacity(50);
    
    /** Organization of level icons */

    float startX = Options::CAMERA_CENTER_X;
    float startY = Options::CAMERA_CENTER_Y + Utils::coord(150) * 2;

    float x = startX;
    float y = startY;
    
    int id = 0;
    
    for(int o = 1; o < LEVEL_PACKS_COUNT; o++)
    {
        this->mLevels[o] = new EntityManager(16, new LevelButton(), this->mMainList->mLayers[o]);

        for(int i = 0; i < 4; i++)
        {
            x = startX - Utils::coord(116) * 2;
            
            for(int j = 0; j < 4; j++)
            {
                LevelButton* item = (LevelButton*) this->mLevels[o]->create();
                
                item->create()->setCenterPosition(x, y);
                item->setId(++id);
                
                x += Utils::coord(150);
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

    this->mSlidesArrows->create()->setCenterPosition(Utils::coord(48), Options::CAMERA_CENTER_Y);
    this->mSlidesArrows->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(48), Options::CAMERA_CENTER_Y);

    static_cast<Entity*>(this->mSlidesArrows->objectAtIndex(1))->setScaleX(-1);

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

    this->mMainList->setPosition(ccp(0, 0)); // this->mMainList->setPosition(ccp(-Options::CAMERA_CENTER_X * 1.66, 0));

    for(int i = 0; i < LEVEL_PACKS_COUNT; i++)
    {
        static_cast<Entity*>(this->mSlides->objectAtIndex(i))->setCurrentFrameIndex(0);
    }
    
    static_cast<Entity*>(this->mSlides->objectAtIndex(0))->setCurrentFrameIndex(1); // TODO: Return index 1.

    static_cast<Entity*>(this->mSlidesArrows->objectAtIndex(0))->setOpacity(0.0); // TODO: Return full opacity.
    static_cast<Entity*>(this->mSlidesArrows->objectAtIndex(1))->setOpacity(255.0);
    
    this->mBackgroundDecorations[2]->setCurrentFrameIndex(0);
    this->mBackgroundDecorations[3]->setVisible(true);
    this->mBackgroundDecorations[4]->setVisible(false);
}

void Levels::onExit()
{
    Screen::onExit();
}

#endif