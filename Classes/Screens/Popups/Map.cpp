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

class BackgroundEntity : public Entity
{
public:
    float p = 0;
    BackgroundEntity(const char* pTextureFileName, CCNode* pParent) :
    Entity(pTextureFileName, pParent)
    {
        
    }
    
    Entity* create()
    {
        return Entity::create();
    }
    
    void visit()
    {
        kmGLPushMatrix();
        glEnable(GL_SCISSOR_TEST);
        
        CCEGLView::sharedOpenGLView()->setScissorInPoints(this->getCenterX() - Options::CAMERA_CENTER_X, this->getCenterY() + (this->mHeight / 2) - (this->mHeight * this->p / 100), Options::CAMERA_WIDTH, this->mHeight + Utils::coord(150));
        
        Entity::visit();
        glDisable(GL_SCISSOR_TEST);
        kmGLPopMatrix();
    }
    
    static BackgroundEntity* create(const char* pTextureFileName, CCNode* pParent)
    {
        BackgroundEntity* entity = new BackgroundEntity(pTextureFileName, pParent);
        entity->autorelease();
        
        return entity;
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
    this->mSquare = Background::create();
    
    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas13.png");
    CCSpriteBatchNode* spriteBatch2 = CCSpriteBatchNode::create("TextureAtlas4.png");
    CCSpriteBatchNode* spriteBatch3 = CCSpriteBatchNode::create("TextureAtlas5.png");
    
    this->mBackground = BackgroundEntity::create("map.png", this);
    
    this->mRipples = EntityManager::create(40, Ripple::create(), this->mBackground);
    
    this->mWays = EntityManager::create(13, Entity::create("way.png"), this->mBackground);
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(105) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(200));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(125) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(192));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(85) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(188));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(125) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(200));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(120) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(212));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(146) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(203));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(125) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(120));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(120) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(142));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(146) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(123));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(0) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(120));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(5) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(142));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(26) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(123));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(70) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(100));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(75) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(112));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(96) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(103));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(300) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(100));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(305) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(112));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(324) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(103));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(210) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(50));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(205) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(56));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(194) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(42));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(370) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(140));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(375) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(152));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(394) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(143));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(90) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(240));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(95) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(252));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(114) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(243));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(120) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(190));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(125) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(202));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(144) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(193));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(60) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(190));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(65) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(202));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(84) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(193));
    
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(130) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(240));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(135) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(252));
    this->mRipples->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(154) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(243));
    
    
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(300) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(210));
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(270) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(280));
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(210) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(330));
    
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(20) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(320));
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(60) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(260));
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(80) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(190));
    
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(70) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(60));
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(110) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(140));
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(140) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(220));
    
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(350) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(420));
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(300) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(480));
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(200) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(480));
    this->mWays->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(100) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(480));
    
    static_cast<Entity*>(this->mWays->objectAtIndex(0))->setRotation(-85);
    static_cast<Entity*>(this->mWays->objectAtIndex(1))->setRotation(-55);
    static_cast<Entity*>(this->mWays->objectAtIndex(2))->setRotation(-30);
    
    static_cast<Entity*>(this->mWays->objectAtIndex(3))->setRotation(-125);
    static_cast<Entity*>(this->mWays->objectAtIndex(4))->setRotation(-115);
    static_cast<Entity*>(this->mWays->objectAtIndex(5))->setRotation(-105);
    
    static_cast<Entity*>(this->mWays->objectAtIndex(6))->setRotation(-50);
    static_cast<Entity*>(this->mWays->objectAtIndex(7))->setRotation(-60);
    static_cast<Entity*>(this->mWays->objectAtIndex(8))->setRotation(-70);
    
    static_cast<Entity*>(this->mWays->objectAtIndex(9))->setRotation(-85);
    static_cast<Entity*>(this->mWays->objectAtIndex(10))->setRotation(20);
    static_cast<Entity*>(this->mWays->objectAtIndex(11))->setRotation(0);
    static_cast<Entity*>(this->mWays->objectAtIndex(12))->setRotation(0);
    
    static_cast<Entity*>(this->mWays->objectAtIndex(0))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(1))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(2))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(3))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(4))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(5))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(6))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(7))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(8))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(9))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(10))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(11))->setVisible(false);
    static_cast<Entity*>(this->mWays->objectAtIndex(12))->setVisible(false);
    
    this->mDay[0] = Entity::create("day1.png", this->mBackground);
    this->mDay[1] = Entity::create("day2.png", this->mBackground);
    this->mDay[2] = Entity::create("day3.png", this->mBackground);
    this->mDay[3] = Entity::create("day4.png", this->mBackground);
    this->mDay[4] = Entity::create("day5.png", this->mBackground);
    
    this->mDay[0]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(340) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(110));
    this->mDay[1]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(90) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(405) + Utils::coord(0));
    this->mDay[2]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(50) + Utils::coord(130), this->mBackground->getHeight() / 2 + Utils::coord(30));
    this->mDay[3]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(260) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(260));
    this->mDay[4]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(50) + Utils::coord(130), this->mBackground->getHeight() / 2 - Utils::coord(430));
    
    this->mName = Entity::create("map_name.png", this->mBackground);
    
    this->mName->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() - Utils::coord(30));
    
    Text::create(Options::TEXT_DAILY_MAP, this->mName)->setCenterPosition(this->mName->getWidth() / 2, this->mName->getHeight() / 2);
    
    this->mScroll = Entity::create("map_sprite.png", 2, 2, spriteBatch);
    
    this->addChild(spriteBatch);
    
    this->mBonusTextes[0] = Text::create(Options::TEXT_COINS_BONUS[0], this->mBackground);
    this->mBonusTextes[1] = Text::create(Options::TEXT_COINS_BONUS[1], this->mBackground);
    this->mBonusTextes[2] = Text::create(Options::TEXT_COINS_BONUS[2], this->mBackground);
    this->mBonusTextes[3] = Text::create(Options::TEXT_COINS_BONUS[3], this->mBackground);
    this->mBonusTextes[4] = Text::create(Options::TEXT_COINS_BONUS[4], this->mBackground);
    
    this->mBonusTextes[0]->setCenterPosition(this->mDay[0]->getCenterX(), this->mDay[0]->getCenterY() - Utils::coord(130));
    this->mBonusTextes[1]->setCenterPosition(this->mDay[1]->getCenterX(), this->mDay[1]->getCenterY() - Utils::coord(130));
    this->mBonusTextes[2]->setCenterPosition(this->mDay[2]->getCenterX(), this->mDay[2]->getCenterY() - Utils::coord(130));
    this->mBonusTextes[3]->setCenterPosition(this->mDay[3]->getCenterX(), this->mDay[3]->getCenterY() - Utils::coord(130));
    this->mBonusTextes[4]->setCenterPosition(this->mDay[4]->getCenterX(), this->mDay[4]->getCenterY() - Utils::coord(130));
    
    /*this->mBonusTextes[0]->setColor(ccc3(100, 100, 100));
    this->mBonusTextes[1]->setColor(ccc3(100, 100, 100));
    this->mBonusTextes[2]->setColor(ccc3(100, 100, 100));
    this->mBonusTextes[3]->setColor(ccc3(100, 100, 100));
    this->mBonusTextes[4]->setColor(ccc3(100, 100, 100));*/
    
    this->addChild(spriteBatch2);
    this->mBackground->addChild(spriteBatch3);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mScroll->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT);
    this->mScroll->animate(0.04);
    
    this->mParent = pParent;
    
    this->mShowed = false;
    this->mAnimation = false;
    
    this->mShowAnimationRunning = false;
    this->mHideAnimationRunning = false;
    
    this->mParent->addChild(this->mSquare);
    
    this->mStars = EntityManager::create(100, StarParticle2::create(), this->mBackground);
    this->mConfetti = EntityManager::create(300, Confetti::create(), spriteBatch2);
    this->mCoins = EntityManager::create(5, Entity::create("coins@2x.png", 5, 4), spriteBatch3);
    this->mAnimatedCoins = EntityManager::create(100, AnimatedCoin::create(1.5), spriteBatch3);
    
    this->mCoins->create()->setCenterPosition(this->mBonusTextes[0]->getCenterX() - this->mBonusTextes[0]->getWidth() / 2 - Utils::coord(30), this->mBonusTextes[0]->getCenterY());
    this->mCoins->create()->setCenterPosition(this->mBonusTextes[1]->getCenterX() - this->mBonusTextes[1]->getWidth() / 2 - Utils::coord(30), this->mBonusTextes[1]->getCenterY());
    this->mCoins->create()->setCenterPosition(this->mBonusTextes[2]->getCenterX() - this->mBonusTextes[2]->getWidth() / 2 - Utils::coord(30), this->mBonusTextes[2]->getCenterY());
    this->mCoins->create()->setCenterPosition(this->mBonusTextes[3]->getCenterX() - this->mBonusTextes[3]->getWidth() / 2 - Utils::coord(30), this->mBonusTextes[3]->getCenterY());
    this->mCoins->create()->setCenterPosition(this->mBonusTextes[4]->getCenterX() - this->mBonusTextes[4]->getWidth() / 2 - Utils::coord(30), this->mBonusTextes[4]->getCenterY());
    
    for(int i = 0; i < this->mCoins->getCount(); i++)
    {
        static_cast<Entity*>(this->mCoins->objectAtIndex(i))->setCurrentFrameIndex(Utils::random(0, 20));
        static_cast<Entity*>(this->mCoins->objectAtIndex(i))->setScale(0.7);
        static_cast<Entity*>(this->mCoins->objectAtIndex(i))->setRotation(-45);
        static_cast<Entity*>(this->mCoins->objectAtIndex(i))->animate(0.04);
    }
    
    this->mAnimatedCoinsAnimation = false;
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

void Map::throwAnimation(float pX, float pY)
{
    this->mConfetti->clear();
    
    float x = 0;
    float y = Utils::coord(200);
    
    for(int i = 0; i < 10; i++)
    {
        for(int j = -10; j <= 10; j++)
        {
            x = Utils::coord(Utils::randomf(40.0, 40.0)) * j;
            
            this->mConfetti->create()->setCenterPosition(Options::CAMERA_CENTER_X + x, Options::CAMERA_HEIGHT + y);
        }
        
        y -= Utils::coord(Utils::randomf(5.0, 10.0));
    }
    
    for(int i = 0; i < 100; i++)
    {
        this->mStars->create()->setCenterPosition(pX, pY);
    }
    
    this->mAnimatedCoinsAnimation = true;
    
    this->mAnimatedCoinsAnimationTime = 2.0;
    this->mAnimatedCoinsAnimationTimeElpased = 0;
}

void Map::show()
{
    if(this->mShowed) return;
    
    this->mParent->addChild(this, 1000);
    
    this->mShowAnimationRunning = true;
    
    this->mShowAnimationCount = 0;
    this->mShowAnimationTimeElapsed = 0;
    
    this->mShowAnimationTime = 0;
    this->mSquare->runAction(CCFadeTo::create(1.0, 200));
}

void Map::hide()
{
    if(!this->mShowed) return;
    
    this->mHideAnimationRunning = true;
    
    this->mHideAnimationCount = 0;
    this->mHideAnimationTimeElapsed = 0;
    
    this->mHideAnimationTime = 0;
    this->mSquare->runAction(CCFadeTo::create(1.0, 0));
    
    
    for(int i = 0; i < this->mConfetti->getCount(); i++)
    {
        static_cast<Entity*>(this->mConfetti->objectAtIndex(i))->runAction(CCFadeTo::create(0.5, 0));
    }
}

bool Map::isShowed()
{
    return this->mShowed;
}

void Map::onShow()
{
    this->mShowed = true;
    this->mAnimation = true;
    
    this->mAnimationTime = 0.2;
    this->mAnimationTimeElapsed = 0;
    
    this->mAnimationCount = 0;
    this->mAnimationCount2 = 0;
    
    AppDelegate::setLastVisitDaysCount(Utils::millisecondNow() / 1000 / 86400000);
}

void Map::onHide()
{
    this->removeFromParentAndCleanup(false);
    
    this->mShowed = false;
    
    for(int i = 0; i < 13; i++)
    {
        static_cast<Entity*>(this->mWays->objectAtIndex(i))->setVisible(false);
        static_cast<Entity*>(this->mWays->objectAtIndex(i))->setOpacity(255);
    }
    
    for(int i = 0; i < 5; i++)
    {
        this->mDay[i]->setColor(ccc3(255, 255, 255));
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Map::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
    
    if(this->mAnimatedCoinsAnimation)
    {
        this->mAnimatedCoinsAnimationTimeElpased += pDeltaTime;
        
        if(this->mAnimatedCoinsAnimationTimeElpased >= this->mAnimatedCoinsAnimationTime)
        {
            this->mAnimatedCoinsAnimationTimeElpased = 0;
            
            this->mAnimatedCoinsAnimation = false;
        }
        
        this->mAnimatedCoins->create()->setCenterPosition(this->mDay[this->day - 1]->getCenterX(), this->mDay[this->day - 1]->getCenterY());
    }
    
    if(this->mAnimation)
    {
        this->mAnimationTimeElapsed += pDeltaTime;
        
        if(this->mAnimationTimeElapsed >= this->mAnimationTime)
        {
            this->mAnimationTimeElapsed = 0;
            
            switch(this->mAnimationCount)
            {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount))->setVisible(true);
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount))->setScale(1.4);
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount))->runAction(CCScaleTo::create(0.2, 1));
                break;
                case 13:
                    this->mDay[4]->setScale(1.4);
                    this->mDay[4]->runAction(CCScaleTo::create(0.2, 1));
                break;
                case 14:
                    
                    for(int i = 0; i < 13; i++)
                    {
                        static_cast<Entity*>(this->mWays->objectAtIndex(i))->setOpacity(150);
                    }
                    
                    break;
                case 15:
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PREDICTION);
                    }
                    
                    this->mDay[0]->setScale(1.4);
                    this->mDay[0]->runAction(CCScaleTo::create(0.2, 1));
                    this->mDay[0]->setColor(ccc3(255, 255, 255));
                    
                    if(this->day == 1)
                    {
                        this->mAnimation = false;
                        
                        this->throwAnimation(this->mDay[0]->getCenterX(), this->mDay[0]->getCenterY());
                        
                        AppDelegate::addCoins(500, Options::SAVE_DATA_COINS_TYPE_GOLD);
                    }
                break;
                case 16:
                case 17:
                case 18:
                    
                static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->setScale(1.4);
                static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->runAction(CCScaleTo::create(0.2, 1));
                static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->runAction(CCFadeTo::create(0.2, 255));
                    
                if(Options::SOUND_ENABLE)
                {
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_POINTS[this->mAnimationCount2]);
                }
                    
                this->mAnimationCount2++;
                    
                break;
                case 19:
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PREDICTION);
                    }
                    
                    this->mDay[1]->setScale(1.4);
                    this->mDay[1]->runAction(CCScaleTo::create(0.2, 1));
                    this->mDay[1]->setColor(ccc3(255, 255, 255));
                    
                    if(this->day == 2)
                    {
                        this->mAnimation = false;
                        
                        this->throwAnimation(this->mDay[1]->getCenterX(), this->mDay[1]->getCenterY());
                        
                        AppDelegate::addCoins(1000, Options::SAVE_DATA_COINS_TYPE_GOLD);
                    }
                    break;
                case 20:
                case 21:
                case 22:
                    
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->setScale(1.4);
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->runAction(CCScaleTo::create(0.2, 1));
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->runAction(CCFadeTo::create(0.2, 255));
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_POINTS[this->mAnimationCount2]);
                    }
                    
                    this->mAnimationCount2++;
                    
                    break;
                case 23:
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PREDICTION);
                    }
                    
                    this->mDay[2]->setScale(1.4);
                    this->mDay[2]->runAction(CCScaleTo::create(0.2, 1));
                    this->mDay[2]->setColor(ccc3(255, 255, 255));
                    
                    if(this->day == 3)
                    {
                        this->mAnimation = false;
                        
                        this->throwAnimation(this->mDay[2]->getCenterX(), this->mDay[2]->getCenterY());
                        
                        AppDelegate::addCoins(4000, Options::SAVE_DATA_COINS_TYPE_GOLD);
                    }
                    break;
                case 24:
                case 25:
                case 26:
                    
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->setScale(1.4);
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->runAction(CCScaleTo::create(0.2, 1));
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->runAction(CCFadeTo::create(0.2, 255));
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_POINTS[this->mAnimationCount2]);
                    }
                    
                    this->mAnimationCount2++;
                    
                    break;
                case 27:
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PREDICTION);
                    }
                    
                    this->mDay[3]->setScale(1.4);
                    this->mDay[3]->runAction(CCScaleTo::create(0.2, 1));
                    this->mDay[3]->setColor(ccc3(255, 255, 255));
                    
                    if(this->day == 4)
                    {
                        this->mAnimation = false;
                        
                        this->throwAnimation(this->mDay[3]->getCenterX(), this->mDay[3]->getCenterY());
                        
                        AppDelegate::addCoins(8000, Options::SAVE_DATA_COINS_TYPE_GOLD);
                    }
                    break;
                case 28:
                case 29:
                case 30:
                case 31:
                    
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->setScale(1.4);
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->runAction(CCScaleTo::create(0.2, 1));
                    static_cast<Entity*>(this->mWays->objectAtIndex(this->mAnimationCount2))->runAction(CCFadeTo::create(0.2, 255));
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_POINTS[this->mAnimationCount2]);
                    }
                    
                    this->mAnimationCount2++;
                    
                    break;
                case 32:
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PREDICTION);
                    }
                    
                    this->mDay[4]->setScale(1.4);
                    this->mDay[4]->runAction(CCScaleTo::create(0.2, 1));
                    this->mDay[4]->setColor(ccc3(255, 255, 255));
                    
                    if(this->day == 5)
                    {
                        this->mAnimation = false;
                        
                        this->throwAnimation(this->mDay[4]->getCenterX(), this->mDay[4]->getCenterY());
                        
                        AppDelegate::addCoins(1000, Options::SAVE_DATA_COINS_TYPE_GOLD);
                    }
                    break;
            }
            
            if(this->mAnimationCount < 11 && Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_POINTS[this->mAnimationCount]);
            }
            
            switch(this->mAnimationCount)
            {
                case 0:
                    this->mDay[0]->setScale(1.4);
                    this->mDay[0]->runAction(CCScaleTo::create(0.2, 1));
                    this->mDay[0]->setColor(ccc3(100, 100, 100));
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PROGRESS);
                    }
                break;
                case 3:
                    this->mDay[1]->setScale(1.4);
                    this->mDay[1]->runAction(CCScaleTo::create(0.2, 1));
                    this->mDay[1]->setColor(ccc3(100, 100, 100));
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PROGRESS);
                    }
                break;
                case 6:
                    this->mDay[2]->setScale(1.4);
                    this->mDay[2]->runAction(CCScaleTo::create(0.2, 1));
                    this->mDay[2]->setColor(ccc3(100, 100, 100));
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PROGRESS);
                    }
                break;
                case 9:
                    this->mDay[3]->setScale(1.4);
                    this->mDay[3]->runAction(CCScaleTo::create(0.2, 1));
                    this->mDay[3]->setColor(ccc3(100, 100, 100));
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PROGRESS);
                    }
                break;
                case 13:
                    this->mDay[4]->setScale(1.4);
                    this->mDay[4]->runAction(CCScaleTo::create(0.2, 1));
                    this->mDay[4]->setColor(ccc3(100, 100, 100));
                    
                    if(Options::SOUND_ENABLE)
                    {
                        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_PROGRESS);
                    }
                break;
            }
            
            this->mAnimationCount++;
        }
    }
    
    if(this->mShowAnimationRunning)
    {
        this->mScroll->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(15), Options::CAMERA_HEIGHT - (this->mBackground->getHeight() * this->mBackground->p / 100));
        
        this->mShowAnimationTimeElapsed += pDeltaTime;
        
        if(this->mShowAnimationTimeElapsed >= this->mShowAnimationTime)
        {
            this->mShowAnimationTimeElapsed = 0;
            
            this->mBackground->p += 2;
            
            if(this->mBackground->p >= 100) {
                this->mShowAnimationRunning = false;
                
                this->onShow();
                
                this->mScroll->runAction(CCMoveTo::create(0.1, ccp(this->mScroll->getCenterX(), 0 - this->mScroll->getHeight() / 2)));
            }
            
            this->mShowAnimationCount++;
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
            
            this->mShowAnimationCount++;
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
    if(this->mShowed)
    {
        this->hide();
    }
    
    return this->mShowed;
}

#endif