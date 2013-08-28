#ifndef CONST_END
#define CONST_END

#include "End.h"

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

End::~End()
{
    this->mConfetti->release();
    //this->mStars->release();
}

End::End(int pType, Screen* pParent, void (*pOnTouchCallback)(int, int)) :
    Splash(pParent)
    {
        this->mType = pType;
        this->mOnTouchCallback = pOnTouchCallback;
        
        this->mScaleLayer = CCLayer::create();
        this->mScaleLayer->retain();
        
        CCSpriteBatchNode* spriteBatch1 = CCSpriteBatchNode::create("TextureAtlas8.pvr.ccz");
        CCSpriteBatchNode* spriteBatch2 = CCSpriteBatchNode::create("TextureAtlas7.pvr.ccz");
        CCSpriteBatchNode* spriteBatch3 = CCSpriteBatchNode::create("TextureAtlas8.pvr.ccz");
        CCSpriteBatchNode* spriteBatch4 = CCSpriteBatchNode::create("TextureAtlas7.pvr.ccz");
        
        this->addChild(spriteBatch1);
        this->mScaleLayer->addChild(spriteBatch3);
        this->mScaleLayer->addChild(spriteBatch2, 2);
        this->mScaleLayer->addChild(spriteBatch4, 3);
        
        this->addChild(this->mScaleLayer);
        this->mScaleLayer->setVisible(false);
        
        this->mCoinsCountText = Text::create((Textes) {"0", Options::FONT, 64, -1}, this->mScaleLayer);
        
        this->mParts = EntityManager::create(2, Entity::create("end_lvl_bg_sprite@2x.png", 2, 1), spriteBatch1);
        
        Entity* part;
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT + part->getHeight() / 2);
        part->setCurrentFrameIndex(0);
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(Options::CAMERA_CENTER_X, -part->getHeight() / 2);
        part->setCurrentFrameIndex(1);
        
        this->mBackground = Entity::create("end_lvl_bg_popup@2x.png", spriteBatch3);
        
        this->mCoinsPanel = Entity::create("shop_money_bg@2x.png", spriteBatch3);
        this->mCoin = Entity::create("coins@2x.png", 5, 4, spriteBatch4);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mCoinsPanel->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(90));
        
        this->mCoin->create()->setCenterPosition(this->mCoinsPanel->getCenterX() - Utils::coord(105), this->mCoinsPanel->getCenterY());
        this->mCoin->setRotation(-45);
        this->mCoin->setScale(1.3);
        this->mCoin->animate(0.05);
        
        this->mCoinsCountText->setCenterPosition(this->mCoinsPanel->getCenterX() - Utils::coord(70) + this->mCoinsCountText->getWidth() / 2, this->mCoinsPanel->getCenterY());
        
        this->mShopButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_SHOP, this->mOnTouchCallback);
        this->mMenuButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_MENU, this->mOnTouchCallback);
        this->mRestartButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_RESTART, this->mOnTouchCallback);
        this->mContinueButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, spriteBatch3, Options::BUTTONS_ID_END_CONTINUE, this->mOnTouchCallback);

        if(this->mType == TYPE_PROGRESS)
        {
            this->mContinueButton->create()->setCurrentFrameIndex(2);
            this->mContinueButton->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
                
            this->mRestartButton->create()->setCurrentFrameIndex(1);
            this->mRestartButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(340));

            this->mMenuButton->create()->setCurrentFrameIndex(0);
            this->mMenuButton->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
        }
        else
        {
            this->mShopButton->create()->setCurrentFrameIndex(3);
            this->mShopButton->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
                
            this->mMenuButton->create()->setCurrentFrameIndex(0);
            this->mMenuButton->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(340));

            this->mContinueButton->create()->setCurrentFrameIndex(2);
            this->mContinueButton->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(200), Options::CAMERA_CENTER_Y - Utils::coord(320));
        }

        if(this->mType == Splash::TYPE_PROGRESS)
        {
            this->mStars = EntityManager::create(3, Star::create(), spriteBatch1);
            
            for(int i = 0; i < 3; i++)
            {
                Entity* star = ((Entity*) this->mStars->create());
                
                star->setCurrentFrameIndex(i + 3);
                star->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(180) * (i - 1), this->mBackground->getHeight() - Utils::coord(100) - Utils::coord(40) * abs(i - 1));
            }
        }
        
        this->setVisible(false);
        
        this->mIsAnimationRunning = false;

        Text* text1 = Text::create((Textes) {"Результаты", Options::FONT, 64, -1}, this->mScaleLayer);
        Text* text2 = Text::create((Textes) {"Результат: 0", Options::FONT, 42, -1}, this->mScaleLayer);
        Text* text3 = Text::create((Textes) {"Рекорд: 0", Options::FONT, 42, -1}, this->mScaleLayer);
        Text* text4 = Text::create((Textes) {"Убито летчиков: 0", Options::FONT, 42, -1}, this->mScaleLayer);
        Text* text5 = Text::create((Textes) {"Комбо ударов: 0", Options::FONT, 42, -1}, this->mScaleLayer);
        Text* text6 = Text::create((Textes) {"Критических ударов: 0", Options::FONT, 42, -1}, this->mScaleLayer);
        Text* text7 = Text::create((Textes) {"Заработано монет: 0", Options::FONT, 42, -1}, this->mScaleLayer);

        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));
        text2->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));
        text3->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(150));
        text4->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100));
        text5->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(50));
        text6->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(0));
        text7->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50));
        
        this->mConfetti = EntityManager::create(300, Confetti::create(), spriteBatch2);
    }

End* End::create(int pType, Screen* pParent, void (*pOnTouchCallback)(int, int))
{
    End* screen = new End(pType, pParent, pOnTouchCallback);
    screen->autorelease();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void End::onShow()
{
    Splash::onShow();

    this->mIsAnimationRunning = true;
    
    this->mAnimationTime = 0.6;
    this->mAnimationtimeElapsed = 0;
    
    this->mAnimationCounter = 0;
}

void End::onHide()
{
    Splash::onHide();

    if(this->mType == Splash::TYPE_PROGRESS)
    {
        for(int i = 0; i < 3; i++)
        {
            Entity* star = ((Entity*) this->mStars->objectAtIndex(i));
            
            star->setCurrentFrameIndex(star->getCurrentFrameIndex() + 3);
        }
    }
}

void End::onStartShow()
{
    Splash::onStartShow();
    
    this->throwConfetti();
    
    int coins = AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_GOLD);
    
    this->mCoinsCountText->setString(Utils::intToString(coins).c_str());
    this->mCoinsCountText->setCenterPosition(this->mCoinsPanel->getCenterX() - Utils::coord(70) + this->mCoinsCountText->getWidth() / 2, this->mCoinsPanel->getCenterY());
}

void End::onStartHide()
{
    Splash::onStartHide();
}

void End::throwConfetti()
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
}

// ===========================================================
// Override Methods
// ===========================================================

void End::update(float pDeltaTime)
{
    Splash::update(pDeltaTime);
    
    if(this->mIsAnimationRunning)
    {
        this->mAnimationtimeElapsed += pDeltaTime;
        
        if(this->mAnimationtimeElapsed >= this->mAnimationTime)
        {
            this->mAnimationtimeElapsed = 0;

            if(this->mType == Splash::TYPE_PROGRESS)
            {
                Star* star = (Star*) this->mStars->objectAtIndex(this->mAnimationCounter);
                
                star->setCurrentFrameIndex(star->getCurrentFrameIndex() - 3);
                star->animate();
            }
            
            if(this->mAnimationCounter == (3 - 1))
            {
                this->mIsAnimationRunning = false;
            }
            
            this->mAnimationCounter++;
        }
    }
}

#endif