#ifndef CONST_MAP
#define CONST_MAP

#include "Map.h"

// ===========================================================
// Inner Classes
// ===========================================================

class Background : public CCNodeRGBA
{
public:
    Background()
    {
        this->setOpacity(0);
    }
    
    static Background* create()
    {
        Background* background = new Background();
        background->autorelease();
        
        return background;
    }
    
    void draw()
    {
        if(this->getOpacity() <= 0) return;
        
        glLineWidth(1);
        CCPoint filledVertices[] = { ccp(0,0), ccp(0,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH, 0)};
        ccDrawSolidPoly(filledVertices, 4, ccc4f(0.0f, 0.0f, 0, this->getOpacity() / 255.0) );
    }
};

// ===========================================================
// Constants
// ===========================================================

Map* Map::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Map::~Map()
{
}

Map::Map(CCNode* pParent)
{
    this->init();
    
    this->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
    
    this->ignoreAnchorPointForPosition(false);
    this->setScale(0.0);
    this->mSquare = Background::create();
    
    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas13.png");
    this->addChild(spriteBatch);
    
    this->mBackground = Entity::create("map.png", spriteBatch);
    this->mScroll = Entity::create("map_sprite.png", 2, 2, spriteBatch);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mRipples = EntityManager::create(10, Ripple::create(), spriteBatch);
    
    this->mScroll->create()->setCenterPosition(Options::CAMERA_CENTER_X, this->mBackground->getCenterY() - this->mBackground->getHeight() / 2 + Utils::coord(100));
    this->mScroll->animate(0.1);
    
        
    this->mParent = pParent;
    
    this->mShowed = false;
    
    this->mShowAnimationRunning = false;
    this->mHideAnimationRunning = false;
    
    this->mParent->addChild(this->mSquare);
}

Map* Map::create(CCNode* pParent)
{
    Map* popup = new Map(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void Map::onTouchButtonsCallback(const int pAction, const int pID)
{
    Map* pSender = static_cast<Map*>(Map::m_Instance);
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
        }
        break;
            
        case Options::BUTTONS_ACTION_ONBEGIN:
        break;
            
        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void Map::show()
{
    if(this->mShowed) return;
    
    this->mParent->addChild(this, 1000);
    
    this->mShowed = true;
    this->mShowAnimationRunning = true;
    
    this->mShowAnimationCount = 0;
    this->mShowAnimationTimeElapsed = 0;
    
    this->mShowAnimationTime = 0.3;
    this->runAction(CCScaleTo::create(this->mShowAnimationTime, 1.2));
    this->mSquare->runAction(CCFadeTo::create(0.5, 200));
}

void Map::hide()
{
    if(!this->mShowed) return;
    
    this->mHideAnimationRunning = true;
    
    this->mHideAnimationCount = 0;
    this->mHideAnimationTimeElapsed = 0;
    
    this->mHideAnimationTime = 0.1;
    this->runAction(CCScaleTo::create(this->mHideAnimationTime, 1.2));
}

bool Map::isShowed()
{
    return this->mShowed;
}

void Map::onShow()
{
}

void Map::onHide()
{
    this->removeFromParentAndCleanup(false);
    
    this->mShowed = false;
}

// ===========================================================
// Override Methods
// ===========================================================

void Map::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
    
    if(this->mShowAnimationRunning)
    {
        this->mShowAnimationTimeElapsed += pDeltaTime;
        
        if(this->mShowAnimationTimeElapsed >= this->mShowAnimationTime)
        {
            this->mShowAnimationTimeElapsed = 0;
            
            switch(this->mShowAnimationCount)
            {
                case 0:
                    this->mShowAnimationTime = 0.2;
                    this->runAction(CCScaleTo::create(this->mShowAnimationTime, 0.8));
                    break;
                case 1:
                    this->mShowAnimationTime = 0.2;
                    this->runAction(CCScaleTo::create(this->mShowAnimationTime, 1.0));
                    break;
                case 2:
                    this->mShowAnimationRunning = false;
                    
                    this->onShow();
                    break;
            }
            
            this->mShowAnimationCount++;
        }
    }
    
    if(this->mHideAnimationRunning)
    {
        this->mHideAnimationTimeElapsed += pDeltaTime;
        
        if(this->mHideAnimationTimeElapsed >= this->mHideAnimationTime)
        {
            this->mHideAnimationTimeElapsed = 0;
            
            switch(this->mHideAnimationCount)
            {
                case 0:
                    this->mHideAnimationTime = 0.2;
                    this->runAction(CCScaleTo::create(this->mHideAnimationTime, 0.0));
                    break;
                case 1:
                    this->mHideAnimationRunning = false;
                    
                    this->onHide();
                    break;
            }
            
            this->mHideAnimationCount++;
        }
    }
}

void Map::draw()
{
    CCLayer::draw();
}

void Map::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate((Touchable*) this, 0, true);
    
    CCLayer::onEnter();
    
    this->scheduleUpdate();
}

void Map::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate((Touchable*) this);
    
    CCLayer::onExit();
    
    this->stopAllActions();
    this->unscheduleAllSelectors();
}

bool Map::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    return this->mShowed;
}

#endif