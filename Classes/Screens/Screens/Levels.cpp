#ifndef CONST_LEVELS
#define CONST_LEVELS

#include "Levels.h"

#include "Game.h"
#include "Episodes.h"

// ===========================================================
// Inner Classe
// ===========================================================

class Effect : public CCNodeRGBA
{
    public:
    Effect()
    {
        this->setColor(ccc3(0, 0, 0));
        this->setOpacity(50);
    }
    
    static Effect* create()
    {
        Effect* background = new Effect();
        background->autorelease();
        
        return background;
    }
    
    void draw()
    {
        if(this->getOpacity() <= 0) return;
       
		#if CC_TARGET_PLATFORM != CC_PLATFORM_WINRT
        glLineWidth(1);
		#endif
		CCPoint filledVertices[] = { ccp(0,0), ccp(0,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH, 0)};
        ccDrawSolidPoly(filledVertices, 4, ccc4f(this->getColor().r, this->getColor().g, this->getColor().b, this->getOpacity() / 255.0) );
    }
};

class UnlockPanel : public CCLayerColor
{
    public:
    CCNode* mParent;
    
    Entity* mStarsCountIcon;
    Text* mStarsCountText;
    
    float mStarsCountIconAnimationTime;
    
    bool mStarsCountIconAnimationReverse;
    
    bool mDownAnimation;
    
    int mDownAnimationStep;
    float mDownAnimationStepTimeElapsed;
    float mDownAnimationStepTime;
    
    bool mUpAnimation;
    
    int mUpAnimationStep;
    float mUpAnimationStepTimeElapsed;
    float mUpAnimationStepTime;
    
    UnlockPanel(CCNode* pParent)
    {
        this->mParent = pParent;
        
        this->initWithColor(ccc4(0, 0, 0, 200), Options::CAMERA_WIDTH, Options::CAMERA_HEIGHT / 4);
        this->ignoreAnchorPointForPosition(false);
        this->setAnchorPoint(ccp(0.5, 0.5));
        this->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
        
        this->mStarsCountIcon = Entity::create("end_lvl_star_sprite@2x.png", 3, 2, this);
        this->mStarsCountIcon->setScale(0.5);
        this->mStarsCountIcon->setCurrentFrameIndex(1);
        Text* text1 = Text::create(Options::TEXT_LEVELS_LOCKED, this);
        this->mStarsCountText = Text::create((Textes) {"36", Options::FONT, 36, -1}, this);
        this->mStarsCountIcon->create()->setCenterPosition(this->getContentSize().width / 2, this->getContentSize().height / 2 - Utils::coord(80));
        text1->setCenterPosition(this->getContentSize().width / 2, this->getContentSize().height / 2 + Utils::coord(50));
        this->mStarsCountText->setCenterPosition(this->getContentSize().width / 2, this->getContentSize().height / 2 - Utils::coord(80));
        
        this->mStarsCountIconAnimationTime = 2.0;
        this->mStarsCountIconAnimationReverse = false;
        
        this->mDownAnimation = false;
        this->mDownAnimationStepTime = 0;
        this->mDownAnimationStepTimeElapsed = 0;
        this->mDownAnimationStep = -1;
        
        this->mUpAnimation = false;
        this->mUpAnimationStepTime = 0;
        this->mUpAnimationStepTimeElapsed = 0;
        this->mUpAnimationStep = -1;
    }
    
    static UnlockPanel* create(CCNode* pParent)
    {
        UnlockPanel* background = new UnlockPanel(pParent);
        background->autorelease();
        background->retain();
        
        return background;
    }
    
    void up(int pIndex)
    {
        if(AppDelegate::getLevelStarsTotalCount() < Levels::STARS[pIndex])
        {
            if(this->mUpAnimation || this->getParent()) return;
            
            this->mParent->addChild(this, 1000);
            
            this->mUpAnimation = true;
            this->mUpAnimationStepTime = 0;
            this->mUpAnimationStepTimeElapsed = 0;
            this->mUpAnimationStep = -1;
            
            this->stopAllActions();
            
            this->setPosition(ccp(Options::CAMERA_CENTER_X, -Options::CAMERA_HEIGHT / 4));
        }
    }
    
    void down()
    {
        if(this->mDownAnimation || !this->getParent()) return;
        
        this->mDownAnimation = true;
        this->mDownAnimationStepTime = 0;
        this->mDownAnimationStepTimeElapsed = 0;
        this->mDownAnimationStep = -1;
        
        this->stopAllActions();
        
        this->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
    }
    
    void update(float pDeltaTime)
    {
        if(this->mUpAnimation)
        {
            this->mUpAnimationStepTimeElapsed += pDeltaTime;
            
            if(this->mUpAnimationStepTimeElapsed >= this->mUpAnimationStepTime)
            {
                this->mUpAnimationStepTimeElapsed = 0;
                
                switch(++this->mUpAnimationStep)
                {
                    case 0:
                    this->runAction(CCSequence::create(CCMoveTo::create(0.3, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200))), CCMoveTo::create(0.1, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y)), NULL));
                    this->mUpAnimationStepTime = 0.3;
                    break;
                    case 1:
                    //this->runAction(CCMoveTo::create(0.1, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y)));
                    this->mUpAnimationStepTime = 0.1;
                    break;
                    case 2:
                    this->mUpAnimation = false;
                        
                    for(int i = 0 ; i < 80; i++)
                    {
                        static_cast<Levels*>(this->mParent)->mLevels[i]->setRegisterAsTouchable(false);
                    }
                    break;
                }
            }
        }
        
        if(this->mDownAnimation)
        {
            this->mDownAnimationStepTimeElapsed += pDeltaTime;
            
            if(this->mDownAnimationStepTimeElapsed >= this->mDownAnimationStepTime)
            {
                this->mDownAnimationStepTimeElapsed = 0;
                
                switch(++this->mDownAnimationStep)
                {
                    case 0:
                    this->runAction(CCSequence::create(CCMoveTo::create(0.1, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100))), CCMoveTo::create(0.3, ccp(Options::CAMERA_CENTER_X, -Options::CAMERA_HEIGHT / 4)), NULL));
                    this->mDownAnimationStepTime = 0.1;
                    break;
                    case 1:
                    this->mDownAnimationStepTime = 0.3;
                    break;
                    case 2:
                    this->mDownAnimation = false;
                    this->removeFromParentAndCleanup(false);
                        
                    for(int i = 0 ; i < 80; i++)
                    {
                        static_cast<Levels*>(this->mParent)->mLevels[i]->setRegisterAsTouchable(true);
                    }
                    break;
                }
            }
        }
        
        this->mStarsCountIconAnimationTime += pDeltaTime;
        
        if(this->mStarsCountIconAnimationTime >= 2.0)
        {
            this->mStarsCountIconAnimationTime = 0;
            
            if(this->mStarsCountIconAnimationReverse)
            {
                this->mStarsCountIcon->runAction(CCRotateTo::create(2.0, 15));
            }
            else
            {
                this->mStarsCountIcon->runAction(CCRotateTo::create(2.0, -15));
            }
            
            this->mStarsCountIconAnimationReverse = !this->mStarsCountIconAnimationReverse;
        }
    }
    
    void onEnter()
    {
        CCLayer::onEnter();
        
        this->scheduleUpdate();
    }
    
    void onExit()
    {
        CCLayer::onExit();
        
        this->unscheduleAllSelectors();
        this->unscheduleUpdate();
    }
};

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
            //float x = touch->getLocation().x;
            //float y = touch->getLocation().y;
            
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
    LevelButton() :
	Entity("choose_box_lvl_sprite@2x.png", 2, 5),
	mId(0),
	mText(0)
    {
        this->setRegisterAsTouchable(true);
        
		Textes textes = {"0", Options::FONT, 64, -1};

        this->mText = Text::create(textes, this);
    }
    
    static LevelButton* create(bool newest)
    {
        LevelButton* button = new LevelButton();
        button->autorelease();
        
        return button;
    }
    
    Entity* create()
    {
        return Entity::create();
    }
    
    void setId(int pId)
    {
        this->mId = pId;
        
        this->mText->setString(Utils::intToString(this->mId).c_str());
        this->mText->setCenterPosition(this->getWidth() / 2, this->getHeight() / 2);
        
        int stars = AppDelegate::getLevelStars(this->mId -1);

        if(stars == -1)
        {
            this->setCurrentFrameIndex(8);

            this->mText->setVisible(false);
        }
        else
        {
            this->setCurrentFrameIndex(stars * 2);
        }
        
        bool prize = false;
        
        for(int i = 0; i < 80; i++)
        {
            if(Levels::PRIZES[this->mId - 1] == 1)
            {
                prize = true;
            }
        }
        
        if(prize)
        {
            this->setCurrentFrameIndex(this->getCurrentFrameIndex() + 1);
        }
    }
    
    void onTouch(CCTouch* touch, CCEvent* event)
    {
        if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) <= 0)
        {
            static_cast<Levels*>(this->getParent()->getParent()->getParent())->mGetLivesPopup->show();
        }
        else
        {
            if(Levels::PRIZES[this->mId - 1] == 1)
            {
                Game::LEVEL = this->mId - 1;
                
                static_cast<Levels*>(this->getParent()->getParent()->getParent())->mSurpriseLevelPopup->show();
                
                Levels::SHOULD_START_AFTER_UNLOCK = true;
                
                goto sound;
            }
            
            if(this->getCurrentFrameIndex() == 8 || this->getCurrentFrameIndex() == 9)
            {
                Game::LEVEL = this->mId - 1;
                
                Levels::SHOULD_START_AFTER_UNLOCK = false;

                static_cast<Levels*>(this->getParent()->getParent()->getParent())->mUnlockLevelPopup->show();
            }
            else
            {
                Game::LEVEL = this->mId - 1;
            
                AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
            }
        }
        
        sound:
        if(Options::SOUND_ENABLE)
        {
            SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_TAP);
        }
    }
    
    void unlock()
    {
        if(this->getCurrentFrameIndex() == 8 || this->getCurrentFrameIndex() == 9)
        {
            if(this->getCurrentFrameIndex() == 8)
            {
                this->mText->setVisible(true);
            }
            
            this->setCurrentFrameIndex(this->getCurrentFrameIndex() == 8 ? 0 : 1);
            
            AppDelegate::removeCoins(Levels::PRICES[Game::LEVEL], Options::SAVE_DATA_COINS_TYPE_KEYS);
            AppDelegate::setLevelStars(Game::LEVEL, 0);
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
        return LevelButton::create(true);
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

        ~MainList()
        {
            this->removeAllChildrenWithCleanup(true);
        }

        MainList(Levels* pParent) :
		mLayers(),
		mListInitialCenterX(0),
		mListInitialCenterY(0),
		mStartCoordinateY(0),
		mStartCoordinateX(0),
		mStartPositionCoordinateY(0),
		mStartPositionCoordinateX(0),
		mLastDistanceX(0),
		mLastDistanceY(0),
		mSpeedX(0),
		mSpeedY(0),
		mMinWidth(0),
		mMinHeight(0),
		mMaxWidth(0),
		mMaxHeight(0),
		mPostUpdate(0),
		mParent(0),
		mListBorders(0),
		mElements(0)
        {
            this->mParent = pParent;

            this->mLayers[0] = CCLayer::create();
            
            //ListLayer* a = new ListLayer();

            for(int i = 1; i < Levels::LEVEL_PACKS_COUNT + 1; i++)
            {
                this->mLayers[i] = CCLayer::create();

                this->mLayers[i]->setPosition(ccp(Options::CAMERA_WIDTH/1.2 * (i-1), 0)); // TODO: Return * i

                this->addChild(this->mLayers[i]);
            }

            //this->mListBorders = new EntityManager(2, Entity::create("about_scroll_border@2x.png"), this->mLayers[0]);
            //this->mElements = new EntityManager(3, Entity::create("more_games_list@2x.png", 1, 3), a);
            
            //this->mLayers[0]->addChild(a);

            //this->mListBorders->create();
            //this->mListBorders->create();
            
            //((Entity*) this->mListBorders->objectAtIndex(0))->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(330));
            //((Entity*) this->mListBorders->objectAtIndex(1))->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(300));
            
            //((Entity*) this->mListBorders->objectAtIndex(0))->setScaleY(1);
            //((Entity*) this->mListBorders->objectAtIndex(1))->setScaleY(-1);

            //int f = 0;
            /*for(int i = 1; i > -2; i--)
            {
                Entity* element = static_cast<Entity*>(this->mElements->create());

                element->setCurrentFrameIndex(f++);
                element->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(220) * i);
            }*/

            //Text* text1 = new Text(Options::TEXT_MORE_GAMES, this->mLayers[0]);

            //text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(390));

            this->mMinWidth = Options::CAMERA_CENTER_X / 2;
            this->mMaxWidth = -Options::CAMERA_WIDTH * Levels::LEVEL_PACKS_COUNT + Options::CAMERA_WIDTH * 1.5 - Utils::coord(60) * (Levels::LEVEL_PACKS_COUNT + 1);

            this->mPostUpdate = false;
        }
    
    static MainList* create(Levels* pParent)
    {
        MainList* list = new MainList(pParent);
        list->autorelease();
        list->retain();
        
        return list;
    }

    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
        
        CCLayer::onEnter();
        
        this->scheduleUpdate();
    }

    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        CCLayer::onExit();
        
        this->stopAllActions();
        this->unscheduleAllSelectors();
    }

    bool containsTouchLocation(CCTouch* touch)
    {
        //float x = touch->getLocation().x;
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
            this->mParent->mDarkness->setOpacity(50);

            return true;
        }

        return false;
    }

    void ccTouchMoved(CCTouch* touch, CCEvent* event)
    {
        if(this->containsTouchLocation(touch))
        {
            if(this->mParent->mLevels[0]->isRegisteredAsTouchable())
            {
                for(int i = 0 ; i < 80; i++)
                {
                    this->mParent->mLevels[i]->setRegisterAsTouchable(false);
                }
            }

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
            
            this->mParent->mUnlockPanel->down();
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

        while((int)n % (int)(Options::CAMERA_CENTER_X * 1.66 + Utils::coord(60)) != 0)
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
            this->mParent->mSlides[i]->setCurrentFrameIndex(0);
        }
        
        int index = abs((int)n / (int)(Options::CAMERA_CENTER_X * 1.66));

        this->mParent->mSlides[index]->setCurrentFrameIndex(1);

        if(index == 0)
        {
            this->mParent->mSlidesArrows[0]->runAction(CCFadeTo::create(0.5, 0.0));
        }
        else
        {
            this->mParent->mSlidesArrows[0]->runAction(CCFadeTo::create(0.5, 255.0));
        }

        if(index == Levels::LEVEL_PACKS_COUNT - 1)
        {
            this->mParent->mSlidesArrows[1]->runAction(CCFadeTo::create(0.5, 0.0));
        }
        else
        {
            this->mParent->mSlidesArrows[1]->runAction(CCFadeTo::create(0.5, 255.0));
        }
        t = 0;
        this->runAction(CCMoveTo::create(this->mSpeedX, ccp(n, 0)));
        
        ci=index;
    }
    float t;
    int ci;
    
    void check()
    {
        float x = this->getPosition().x;
        float y = this->getPosition().y;
        
        this->mLastDistanceX = this->mStartPositionCoordinateX - x;
        this->mLastDistanceY = this->mStartPositionCoordinateY - y;
        
        this->mSpeedX = abs(this->mLastDistanceX) / 1000.0;
        this->mSpeedY = abs(this->mLastDistanceY) / 1000.0;
        
        float n = x;
        
        while((int)n % (int)(Options::CAMERA_CENTER_X * 1.66 + Utils::coord(60)) != 0)
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
            this->mParent->mSlides[i]->setCurrentFrameIndex(0);
        }
        
        int index = abs((int)n / (int)(Options::CAMERA_CENTER_X * 1.66));
        
        this->mParent->mSlides[index]->setCurrentFrameIndex(1);
        
        if(index == 0)
        {
            this->mParent->mSlidesArrows[0]->runAction(CCFadeTo::create(0.5, 0.0));
        }
        else
        {
            this->mParent->mSlidesArrows[0]->runAction(CCFadeTo::create(0.5, 255.0));
        }
        
        if(index == Levels::LEVEL_PACKS_COUNT - 1)
        {
            this->mParent->mSlidesArrows[1]->runAction(CCFadeTo::create(0.5, 0.0));
        }
        else
        {
            this->mParent->mSlidesArrows[1]->runAction(CCFadeTo::create(0.5, 255.0));
        }
        t = 0;
        this->runAction(CCMoveTo::create(this->mSpeedX, ccp(n, 0)));
        
        ci=index;
    }
    
    void update(float pDeltaTime)
    {
            for(int i = 0; i < Levels::LEVEL_PACKS_COUNT; i++)
            {
                float rotation = 0;//(this->getPosition().x + this->mLayers[i]->getPosition().x) / 10.0;
                float alpha = 255.0;// - abs(this->getPosition().x + this->mLayers[i]->getPosition().x) / 1.0;
                float scale = 1.0;// - abs(this->getPosition().x + this->mLayers[i]->getPosition().x) / 500.0;

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
                //float y = this->getPosition().y;

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
                    if(AppDelegate::getLevelStarsTotalCount() >= Levels::STARS[ci])
                    {
                        this->mParent->mBackgroundDecorations[2]->setCurrentFrameIndex(0);
                        this->mParent->mBackgroundDecorations[3]->setVisible(true);
                        this->mParent->mDarkness->setOpacity(0);
                    }

                    this->mPostUpdate = false;
                    
                    this->mParent->mUnlockPanel->mStarsCountText->setString(ccsf("%d", Levels::STARS[ci] - AppDelegate::getLevelStarsTotalCount()));
                    this->mParent->mUnlockPanel->up(ci);
                }
            }
    }
};

// ===========================================================
// Constants
// ===========================================================

bool Levels::SHOULD_START_AFTER_UNLOCK = false;

int Levels::PRICES[80] =
{
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80
};

int Levels::PRIZES[80] =
{
    0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
    0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0
};

int Levels::STARS[5] =
{
    0, 24, 57, 123, 251
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Levels::~Levels()
{
    CC_SAFE_RELEASE(this->mMainList);
    CC_SAFE_RELEASE(this->mGetLivesPopup);
    CC_SAFE_RELEASE(this->mUnlockLevelPopup);
    CC_SAFE_RELEASE(this->mSurpriseLevelPopup);

    CC_SAFE_RELEASE(spriteBatch2);
    
    CC_SAFE_RELEASE(this->mUnlockPanel);

	this->removeAllChildrenWithCleanup(true);
}

Levels::Levels() :
	mIsUnlockAnimationRunning(0),
	mIsUnlockAnimationSound(0),
	mUnlockAnimationTime(0),
	mUnlockAnimationTimeElapsed(0),
	mBackground(0),
	mTablet(0),
	mLigts(),
	mStarsCountIcon(0),
	mBackButton(0),
	mShopButton(0),
	mStarsCountText(0),
	mMainList(0),
	spriteBatch2(0)
	{
		this->mMainList = MainList::create(this);

		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas2");
		spriteBatch2 = SpriteBatch::create("TextureAtlas9");
		spriteBatch2->retain();

		this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
		this->mBackgroundDecorations[0] = Entity::create("bg_detail_stripe@2x.png", spriteBatch);
		this->mBackgroundDecorations[1] = Entity::create("bg_detail_choose_bird@2x.png", spriteBatch);

		this->addChild(spriteBatch);

		this->mLigts[0] = Entity::create("get_coins_light@2x.png", spriteBatch2);
		this->mLigts[1] = Entity::create("get_coins_light@2x.png", spriteBatch2);

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};
		EntityStructure structure2 = {"btn_sprite@2x.png", 1, 1, 324, 324, 162, 162};

		this->mBackButton = Button::create(structure1, spriteBatch, Options::BUTTONS_ID_LEVELS_BACK, this);
		this->mShopButton = Button::create(structure2, spriteBatch, Options::BUTTONS_ID_MENU_SHOP, this);
		this->mTablet = Entity::create("shop_money_bg@2x.png", this);
		this->mStarsCountIcon = Entity::create("end_lvl_star_sprite@2x.png", 3, 2, this->mTablet);

		for(int i = 0; i < 6; i++)
		{
			this->mSlides[i] = Entity::create("choose_box_navi_sprite@2x.png", 1, 2, spriteBatch);
		}

		Textes textes1 = {"0", Options::FONT, 64, -1};

		this->mStarsCountText = Text::create(textes1, this->mTablet);

		this->addChild(this->mMainList->mLayers[0]);
		this->addChild(this->mMainList);
    
		EntityStructure structure3 = {"btn_sprite@2x.png", 1, 1, 324, 162, 162, 162};

		this->mSlidesArrows[0] = Entity::create(structure3, this);
		this->mSlidesArrows[1] = Entity::create(structure3, this);
    
		this->mBackgroundDecorations[2] = Entity::create("bg_detail_lamp@2x.png", 1, 2, spriteBatch);
		this->mBackgroundDecorations[3] = Entity::create("bg_detail_dark@2x.png", this);
    
		this->mDarkness = Effect::create();
    
		this->addChild(this->mDarkness);
    
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

		this->mBackgroundDecorations[3]->setOpacity(50);
    
		/** Organization of level icons */

		float startX = Options::CAMERA_CENTER_X;
		float startY = Options::CAMERA_CENTER_Y + Utils::coord(150) * 2;

		float x = startX;
		float y = startY;
    
		int id = 0;
    
		int t = -1;
        int yu = 0;
		for(int o = 1; o < LEVEL_PACKS_COUNT + 1; o++)
		{
			for(int i = 0; i < 4; i++)
			{
				x = startX - Utils::coord(116) * 2;
            
				for(int j = 0; j < 4; j++)
				{
                    if(j == 0 && i == 0)
                    {
                        tt[yu] = Text::create(Options::TEXT_LEVELS_EPISODE, this->mMainList->mLayers[o]);
                        tt[yu]->setCenterPosition(x + tt[yu]->getWidth() / 2 - Utils::coord(60), y + Utils::coord(130));
                        
                        yu++;
                    }
                    
					t++;
                
					this->mLevels[t] = LevelButton::create(true);
					this->mMainList->mLayers[o]->addChild(this->mLevels[t]);
                
					this->mLevels[t]->create()->setCenterPosition(x, y);
					static_cast<LevelButton*>(this->mLevels[t])->setId(++id);
                
					x += Utils::coord(150);
				}
            
				y -= Utils::coord(180);
			}

            startX += Utils::coord(60);
            
			x = startX;
			y = startY;
		}

		/** Organization of slider icons */

		x = Options::CAMERA_CENTER_X;
		y = Options::CAMERA_CENTER_Y - Utils::coord(400);

		t = 0;
		for(int i = -LEVEL_PACKS_COUNT / 2; i < LEVEL_PACKS_COUNT / 2 + 1; i++)
		{
			x = Options::CAMERA_CENTER_X + Utils::coord(25) + Utils::coord(60) * i;

			this->mSlides[t++]->create()->setCenterPosition(x, y);
		}

		this->mSlides[0]->setCurrentFrameIndex(1);

		this->mSlidesArrows[0]->create()->setCenterPosition(Utils::coord(48), Options::CAMERA_CENTER_Y);
		this->mSlidesArrows[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(48), Options::CAMERA_CENTER_Y);

		this->mSlidesArrows[1]->setScaleX(-1);
    
		this->mIsUnlockAnimationRunning = false;
    
		this->mGetLivesPopup = GetLives::create(this, true);
		this->mUnlockLevelPopup = UnlockLevel::create(this);
		this->mSurpriseLevelPopup = SurpriseLevel::create(this);

		/** Experiments */
        
        this->mUnlockPanel = UnlockPanel::create(this);
	}

Levels* Levels::create()
{
    Levels* screen = new Levels();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Levels::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_LEVELS_BACK:

                    this->keyBackClicked(false);

                break;
            }
        break;

        case Options::BUTTONS_ACTION_ONBEGIN:
        break;

        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void Levels::updateIcons()
{
    for(int i = 0; i < 80; i++)
    {
        static_cast<LevelButton*>(this->mLevels[i])->setId(i + 1);
    }
}

void Levels::unlock()
{
    this->mLigts[0]->create()->setCenterPosition(this->mLevels[Game::LEVEL]->getCenterX(), this->mLevels[Game::LEVEL]->getCenterY());
    this->mLigts[1]->create()->setCenterPosition(this->mLevels[Game::LEVEL]->getCenterX(), this->mLevels[Game::LEVEL]->getCenterY());
    
    this->mLigts[0]->setZOrder(1);
    this->mLigts[1]->setZOrder(1);
    
    this->mLigts[0]->setScale(0);
    this->mLigts[1]->setScale(0);
    
    this->mLigts[0]->setRotation(0);
    this->mLigts[1]->setRotation(0);
    
    this->mLigts[0]->setOpacity(255);
    this->mLigts[1]->setOpacity(255);
    
    this->mLevels[Game::LEVEL]->setZOrder(2);
    
    static_cast<LevelButton*>(this->mLevels[Game::LEVEL])->unlock();
    
    this->mLevels[Game::LEVEL]->getParent()->addChild(spriteBatch2);
    
    this->mIsUnlockAnimationRunning = true;
    this->mIsUnlockAnimationSound = false;
    this->mUnlockAnimationTime = 2.0;
    this->mUnlockAnimationTimeElapsed = 0;
}

// ===========================================================
// Override Methods
// ===========================================================

void Levels::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    if(this->mIsUnlockAnimationRunning)
    {
        this->mUnlockAnimationTimeElapsed += pDeltaTime;
        
        this->mLigts[0]->setRotation(this->mLigts[0]->getRotation() + 1);
        this->mLigts[1]->setRotation(this->mLigts[1]->getRotation() - 1);
        
        this->mLigts[0]->setScale(this->mLigts[0]->getScaleX() + 0.02);
        this->mLigts[1]->setScale(this->mLigts[1]->getScaleX() + 0.02);
        
        if(this->mLigts[0]->getOpacity() > 0 && this->mUnlockAnimationTimeElapsed >= this->mUnlockAnimationTime / 2)
        {
            this->mLigts[0]->setOpacity(this->mLigts[0]->getOpacity() - 5);
            this->mLigts[1]->setOpacity(this->mLigts[1]->getOpacity() - 5);
            
            if(!this->mIsUnlockAnimationSound)
            {
                if(Options::SOUND_ENABLE)
                {
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LEVEL_UNLOCK);
                }
                
                this->mIsUnlockAnimationSound = true;
            }
        }
        
        if(this->mUnlockAnimationTimeElapsed >= this->mUnlockAnimationTime)
        {
            spriteBatch2->removeFromParentAndCleanup(false);
            
            this->mLigts[0]->destroy();
            this->mLigts[1]->destroy();
            
            this->mLevels[Game::LEVEL]->setZOrder(0);
            
            this->mIsUnlockAnimationRunning = false;
            
            if(SHOULD_START_AFTER_UNLOCK)
            {
                AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
            }
        }
    }
}

void Levels::onEnter()
{
    Screen::onEnter();

    this->mMainList->setPosition(ccp(-Options::CAMERA_CENTER_X * 1.66 * (Episodes::ACTION - 1) - Utils::coord(60) * (Episodes::ACTION - 1), 0));

    for(int i = 0; i < LEVEL_PACKS_COUNT + 1; i++)
    {
        this->mSlides[i]->setCurrentFrameIndex(0);
    }
    
    this->mSlides[0]->setCurrentFrameIndex(1); // TODO: Return index 1.

    this->mSlidesArrows[0]->setOpacity(0.0); // TODO: Return full opacity.
    this->mSlidesArrows[1]->setOpacity(255.0);
    
    this->mBackgroundDecorations[2]->setCurrentFrameIndex(0);
    this->mBackgroundDecorations[3]->setVisible(true);
    this->mDarkness->setOpacity(0);
    
    this->mStarsCountText->setString(ccsf("%d", AppDelegate::getLevelStarsTotalCount()));
    
    for(int i = 0; i < 5; i++)
    {
        tt[i]->setString(ccsf(Options::TEXT_LEVELS_EPISODE.string, i+1));
    }
    
    this->mMainList->check();
}

void Levels::onExit()
{
    Screen::onExit();

    this->mUnlockPanel->removeFromParentAndCleanup(false);

    for(int i = 0 ; i < 80; i++)
    {
        mLevels[i]->setRegisterAsTouchable(true);
    }
}

void Levels::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    if(this->mGetLivesPopup->getParent())
    {
        this->mGetLivesPopup->hide();
    }
    else if(this->mUnlockLevelPopup->getParent())
    {
        this->mUnlockLevelPopup->hide();
    }
    else if(this->mSurpriseLevelPopup->getParent())
    {
        this->mSurpriseLevelPopup->hide();
    }
    else
    {
        AppDelegate::screens->set(0.5, Screen::SCREEN_MODE);
    }
}

#endif