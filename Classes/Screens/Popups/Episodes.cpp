#ifndef CONST_EPISODES
#define CONST_EPISODES

#include "Episodes.h"

#include "Menu.h"
#include "Levels.h"

// ===========================================================
// Inner Classes
// ===========================================================

class Background1 : public CCNodeRGBA
{
public:
    Background1()
    {
        this->setOpacity(0);
    }
    
    static Background1* create()
    {
        Background1* background = new Background1();
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
        ccDrawSolidPoly(filledVertices, 4, ccc4f(0.0f, 0.0f, 0, this->getOpacity() / 255.0) );
    }
};

class BackgroundEntity : public Entity
{
public:
    float p;
    BackgroundEntity(const char* pTextureFileName, CCNode* pParent) :
    Entity(pTextureFileName, pParent),
	p(0)
    {
        p = 0;
    }
    
    Entity* create()
    {
        return Entity::create();
    }
    
    void visit()
    {
        kmGLPushMatrix();
		#if CC_TARGET_PLATFORM != CC_PLATFORM_WINRT
        glEnable(GL_SCISSOR_TEST);
		#endif
        CCEGLView::sharedOpenGLView()->setScissorInPoints(this->getCenterX() - Options::CAMERA_CENTER_X, this->getCenterY() + (this->mHeight / 2) - (this->mHeight * this->p / 100), Options::CAMERA_WIDTH, this->mHeight + Utils::coord(150));
        
        Entity::visit();
		#if CC_TARGET_PLATFORM != CC_PLATFORM_WINRT
        glDisable(GL_SCISSOR_TEST);
		#endif
        kmGLPopMatrix();
    }
    
    static BackgroundEntity* create(const char* pTextureFileName, CCNode* pParent)
    {
        BackgroundEntity* entity = new BackgroundEntity(pTextureFileName, pParent);
        entity->autorelease();
        entity->retain();
        
        return entity;
    }
};

// ===========================================================
// Constants
// ===========================================================

int Episodes::ACTION = -1;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Episodes::~Episodes()
{
    CC_SAFE_RELEASE(this->mBackground);
    
    this->removeAllChildrenWithCleanup(true);
}

Episodes::Episodes(CCNode* pParent) :
	mParent(0),
	mDarkness(0),
	mBackground(0),
	mScroll(0),
	mSquare(0),
    mWays()
	{
		this->init();
    
		this->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
    
		this->ignoreAnchorPointForPosition(false);
		this->mSquare = Background1::create();
    
		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas13");
		SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas4");
		SpriteBatch* spriteBatch3 = SpriteBatch::create("TextureAtlas18");

		this->mBackground = BackgroundEntity::create("progress_map.png", this);
        this->mPointLight = Entity::create("progress_map_episode_light@2x.png", this->mBackground);
        this->mPointLight->create();
        
        this->mPoints[0] = Button::create("progress_map_episode_sprite@2x.png", 5, 2, spriteBatch3, Options::BUTTONS_EPISODE_5, this);
        this->mPoints[1] = Button::create("progress_map_episode_sprite@2x.png", 5, 2, spriteBatch3, Options::BUTTONS_EPISODE_4, this);
        this->mPoints[2] = Button::create("progress_map_episode_sprite@2x.png", 5, 2, spriteBatch3, Options::BUTTONS_EPISODE_3, this);
        this->mPoints[3] = Button::create("progress_map_episode_sprite@2x.png", 5, 2, spriteBatch3, Options::BUTTONS_EPISODE_2, this);
        this->mPoints[4] = Button::create("progress_map_episode_sprite@2x.png", 5, 2, spriteBatch3, Options::BUTTONS_EPISODE_1, this);
        
        for(int i = 0; i < 15; i++)
        {
            this->mWays[i] = Entity::create("way.png", this->mBackground);
        }
        
        this->mWays[0]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(80), this->mBackground->getHeight() / 2 + Utils::coord(260));
        this->mWays[1]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(30), this->mBackground->getHeight() / 2 + Utils::coord(190));
        this->mWays[2]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(50), this->mBackground->getHeight() / 2 + Utils::coord(150));
        
        this->mWays[3]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(180), this->mBackground->getHeight() / 2 + Utils::coord(20));
        this->mWays[4]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(110), this->mBackground->getHeight() / 2 - Utils::coord(30));
        this->mWays[5]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(30), this->mBackground->getHeight() / 2 - Utils::coord(20));
        this->mWays[6]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(50), this->mBackground->getHeight() / 2 + Utils::coord(10));
        
        this->mWays[7]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(200), this->mBackground->getHeight() / 2 - Utils::coord(110));
        this->mWays[8]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(190), this->mBackground->getHeight() / 2 - Utils::coord(190));
        this->mWays[9]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(140), this->mBackground->getHeight() / 2 - Utils::coord(250));
        this->mWays[10]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(70), this->mBackground->getHeight() / 2 - Utils::coord(270));
        this->mWays[11]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(10), this->mBackground->getHeight() / 2 - Utils::coord(270));
        
        this->mWays[12]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(110), this->mBackground->getHeight() / 2 - Utils::coord(400));
        this->mWays[13]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(60), this->mBackground->getHeight() / 2 - Utils::coord(480));
        this->mWays[14]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(30), this->mBackground->getHeight() / 2 - Utils::coord(490));
        
        this->mWays[0]->setRotation(-80);
        this->mWays[1]->setRotation(-40);
        this->mWays[2]->setRotation(-5);
        
        this->mWays[3]->setRotation(60);
        this->mWays[4]->setRotation(10);
        this->mWays[5]->setRotation(-20);
        this->mWays[6]->setRotation(-20);
        
        this->mWays[7]->setRotation(-90);
        this->mWays[8]->setRotation(-70);
        this->mWays[9]->setRotation(-40);
        this->mWays[10]->setRotation(-10);
        this->mWays[11]->setRotation(0);
        
        this->mWays[12]->setRotation(65);
        this->mWays[13]->setRotation(45);
        this->mWays[14]->setRotation(-15);

        this->mPoints[0]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(80), this->mBackground->getHeight() / 2 + Utils::coord(410));
        this->mPoints[1]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(180), this->mBackground->getHeight() / 2 + Utils::coord(160));
        this->mPoints[2]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(180), this->mBackground->getHeight() / 2 - Utils::coord(30));
        this->mPoints[3]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(150), this->mBackground->getHeight() / 2 - Utils::coord(260));
        this->mPoints[4]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(160), this->mBackground->getHeight() / 2 - Utils::coord(490));
        
        this->mTextes[0] = Text::create(Options::TEXT_EPISODES_NAMES[4], this->mBackground);
        this->mTextes[1] = Text::create(Options::TEXT_EPISODES_NAMES[3], this->mBackground);
        this->mTextes[2] = Text::create(Options::TEXT_EPISODES_NAMES[2], this->mBackground);
        this->mTextes[3] = Text::create(Options::TEXT_EPISODES_NAMES[1], this->mBackground);
        this->mTextes[4] = Text::create(Options::TEXT_EPISODES_NAMES[0], this->mBackground);
        
        this->mTextes[0]->setCenterPosition(this->mPoints[0]->getCenterX(), this->mPoints[0]->getCenterY() + Utils::coord(140));
        this->mTextes[1]->setCenterPosition(this->mPoints[1]->getCenterX(), this->mPoints[1]->getCenterY() + Utils::coord(120));
        this->mTextes[2]->setCenterPosition(this->mPoints[2]->getCenterX(), this->mPoints[2]->getCenterY() + Utils::coord(120));
        this->mTextes[3]->setCenterPosition(this->mPoints[3]->getCenterX(), this->mPoints[3]->getCenterY() + Utils::coord(120));
        this->mTextes[4]->setCenterPosition(this->mPoints[4]->getCenterX(), this->mPoints[4]->getCenterY() + Utils::coord(120));

        this->mLocks[0] = Entity::create("lock_1@2x.png", this->mPoints[0]);
        this->mLocks[1] = Entity::create("lock_1@2x.png", this->mPoints[1]);
        this->mLocks[2] = Entity::create("lock_1@2x.png", this->mPoints[2]);
        this->mLocks[3] = Entity::create("lock_1@2x.png", this->mPoints[3]);
        this->mLocks[4] = Entity::create("lock_1@2x.png", this->mPoints[4]);

        this->mLocks[0]->create()->setCenterPosition(this->mPoints[0]->getWidth() / 2, this->mPoints[0]->getHeight() / 2);
        this->mLocks[1]->create()->setCenterPosition(this->mPoints[1]->getWidth() / 2, this->mPoints[1]->getHeight() / 2);
        this->mLocks[2]->create()->setCenterPosition(this->mPoints[2]->getWidth() / 2, this->mPoints[2]->getHeight() / 2);
        this->mLocks[3]->create()->setCenterPosition(this->mPoints[3]->getWidth() / 2, this->mPoints[3]->getHeight() / 2);
        this->mLocks[4]->create()->setCenterPosition(this->mPoints[4]->getWidth() / 2, this->mPoints[4]->getHeight() / 2);

		this->mScroll = Entity::create("map_sprite.png", 2, 2, spriteBatch);
    
		this->addChild(spriteBatch);
    
		this->addChild(spriteBatch2);
		this->mBackground->addChild(spriteBatch3);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
		this->mScroll->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT);
		this->mScroll->animate(0.04);
    
		this->mParent = pParent;
    
		this->mParent->addChild(this->mSquare, 500);
        
        this->mHideAnimationRunning = false;
        this->mShowAnimationRunning = false;
        this->mShowed = false;
	}

Episodes* Episodes::create(CCNode* pParent)
{
    Episodes* popup = new Episodes(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void Episodes::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_EPISODE_1:
                
            ACTION = 1;
                
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Levels::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LEVELS);
            #endif
                
            break;
            case Options::BUTTONS_EPISODE_2:
                
            ACTION = 2;
                
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Levels::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LEVELS);
            #endif
                
            break;
            case Options::BUTTONS_EPISODE_3:
                
            ACTION = 3;
                
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Levels::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LEVELS);
            #endif
                
            break;
            case Options::BUTTONS_EPISODE_4:
                
            ACTION = 4;
                
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Levels::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LEVELS);
            #endif
                
            break;
            case Options::BUTTONS_EPISODE_5:
                
            ACTION = 5;
                
            #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Levels::create());
            #else
            AppDelegate::screens->set(Screen::SCREEN_LEVELS);
            #endif
                
            break;
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
            this->hide();
                
            break;
        }
        break;
            
        case Options::BUTTONS_ACTION_ONBEGIN:
        break;
            
        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void Episodes::show()
{
    if(this->mShowed) return;
    
    this->mParent->addChild(this, 1000);
    
    this->mShowAnimationRunning = true;
    
    this->mShowAnimationTimeElapsed = 0;
    this->mShowAnimationTime = 0;

    this->mSquare->runAction(CCFadeTo::create(1.0, 200));
}

void Episodes::hide()
{
    if(!this->mShowed) return;
    
    this->mHideAnimationRunning = true;
    
    this->mHideAnimationTimeElapsed = 0;
    this->mHideAnimationTime = 0;
    
    this->mSquare->runAction(CCFadeTo::create(1.0, 0));
}

bool Episodes::isShowed()
{
    return this->mShowed;
}

void Episodes::onShow()
{
    this->mShowed = true;

    AppDelegate::setLastVisitDaysCount(Utils::millisecondNow() / 1000 / 86400000);
}

void Episodes::onHide()
{
    this->removeFromParentAndCleanup(false);
    
    this->mShowed = false;
}

void Episodes::onAnimationEnd()
{
    static_cast<Menu*>(this->mParent)->mMapDescription->show();
}

void Episodes::fastHide()
{
    if(!this->mShowed) return;
    
    this->mScroll->setPosition(this->mScroll->getCenterX(), Options::CAMERA_HEIGHT + this->mScroll->getHeight() / 2);
    this->mBackground->p = 0;
    
    this->mSquare->setOpacity(0);
    
    this->onHide();
}

// ===========================================================
// Override Methods
// ===========================================================

void Episodes::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
    
    this->mPointLight->setRotation(this->mPointLight->getRotation() + 0.5);
    
    if(this->mShowAnimationRunning)
    {
        this->mScroll->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(15), Options::CAMERA_HEIGHT - (this->mBackground->getHeight() * this->mBackground->p / 100));
        
        this->mShowAnimationTimeElapsed += pDeltaTime;
        
        if(this->mShowAnimationTimeElapsed >= this->mShowAnimationTime)
        {
            this->mShowAnimationTimeElapsed = 0;
            
            this->mBackground->p += 2;
            
            if(this->mBackground->p >= 105)
            {
                this->mShowAnimationRunning = false;
                
                this->onShow();
                
                this->mScroll->runAction(CCMoveTo::create(0.1, ccp(this->mScroll->getCenterX(), 0 - this->mScroll->getHeight() / 2)));
            }
        }
    }
    
    if(this->mHideAnimationRunning)
    {
        this->mScroll->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(15), Options::CAMERA_HEIGHT - (this->mBackground->getHeight() * this->mBackground->p / 100));
        
        this->mHideAnimationTimeElapsed += pDeltaTime;
        
        if(this->mHideAnimationTimeElapsed >= this->mHideAnimationTime)
        {
            this->mHideAnimationTimeElapsed = 0;
            
            this->mBackground->p -= 2;
            
            if(this->mBackground->p <= 0) {
                this->mHideAnimationRunning = false;
                
                this->onHide();
                
                this->mScroll->runAction(CCMoveTo::create(0.1, ccp(this->mScroll->getCenterX(), Options::CAMERA_HEIGHT + this->mScroll->getHeight() / 2)));
            }
        }
    }
}

void Episodes::draw()
{
    CCLayer::draw();
}

void Episodes::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate((Touchable*) this, 0, true);
    
    CCLayer::onEnter();
    
    this->scheduleUpdate();

    int totalStars = AppDelegate::getLevelStarsTotalCount();

    if(true) { this->mPoints[4]->setCurrentFrameIndex(0); this->mLocks[4]->setVisible(false); }
    if(totalStars >= Levels::STARS[1]) { this->mPoints[3]->setCurrentFrameIndex(1); this->mLocks[3]->setVisible(false); } else { this->mPoints[3]->setCurrentFrameIndex(6); this->mLocks[3]->setVisible(true); }
    if(totalStars >= Levels::STARS[2]) { this->mPoints[2]->setCurrentFrameIndex(2); this->mLocks[2]->setVisible(false); } else { this->mPoints[2]->setCurrentFrameIndex(7); this->mLocks[2]->setVisible(true); }
    if(totalStars >= Levels::STARS[3]) { this->mPoints[1]->setCurrentFrameIndex(3); this->mLocks[1]->setVisible(false); } else { this->mPoints[1]->setCurrentFrameIndex(8); this->mLocks[1]->setVisible(true); }
    if(totalStars >= Levels::STARS[4]) { this->mPoints[0]->setCurrentFrameIndex(4); this->mLocks[0]->setVisible(false); } else { this->mPoints[0]->setCurrentFrameIndex(9); this->mLocks[0]->setVisible(true); }
    
    /*if(this->mStarsText[0]) this->mStarsText[0]->setString(ccsf("%d", Levels::STARS[0] - totalStars));
    if(this->mStarsText[1]) this->mStarsText[1]->setString(ccsf("%d", Levels::STARS[1] - totalStars));
    if(this->mStarsText[2]) this->mStarsText[2]->setString(ccsf("%d", Levels::STARS[2] - totalStars));
    if(this->mStarsText[3]) this->mStarsText[3]->setString(ccsf("%d", Levels::STARS[3] - totalStars));
    if(this->mStarsText[4]) this->mStarsText[4]->setString(ccsf("%d", Levels::STARS[4] - totalStars));*/ // TODO: If we need to show stars
    
    this->mPointLight->setCenterPosition(this->mPoints[4]->getCenterX(), this->mPoints[4]->getCenterY());
}

void Episodes::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate((Touchable*) this);
    
    CCLayer::onExit();
    
    this->stopAllActions();
    this->unscheduleAllSelectors();
}

bool Episodes::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    if(this->mShowed && !this->mShowAnimationRunning)
    {
        this->hide();
    }
    
    return this->mShowed;
}

#endif