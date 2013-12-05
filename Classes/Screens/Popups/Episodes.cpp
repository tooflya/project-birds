#ifndef CONST_EPISODES
#define CONST_EPISODES

#include "Episodes.h"

#include "Menu.h"

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
	mSquare(0)
	{
		this->init();
    
		this->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
    
		this->ignoreAnchorPointForPosition(false);
		this->mSquare = Background1::create();
    
		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas13");
		SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas4");
		SpriteBatch* spriteBatch3 = SpriteBatch::create("TextureAtlas5");
    
		this->mBackground = BackgroundEntity::create("map.png", this);
    
		this->mScroll = Entity::create("map_sprite.png", 2, 2, spriteBatch);
    
		this->addChild(spriteBatch);
    
		this->addChild(spriteBatch2);
		this->mBackground->addChild(spriteBatch3);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
		this->mScroll->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT);
		this->mScroll->animate(0.04);
    
		this->mParent = pParent;
    
		this->mParent->addChild(this->mSquare, 500);
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

// ===========================================================
// Override Methods
// ===========================================================

void Episodes::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
    
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
}

void Episodes::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate((Touchable*) this);
    
    CCLayer::onExit();
    
    this->stopAllActions();
    this->unscheduleAllSelectors();
    
    static_cast<Menu*>(this->mParent)->onShow();
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