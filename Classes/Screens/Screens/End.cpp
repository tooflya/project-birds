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

End::End(int pType, Screen* pParent, void (*pOnTouchCallback)(int, int)) :
    Splash(pParent)
    {
        this->mType = pType;
        this->mOnTouchCallback = pOnTouchCallback;

        this->mParts = new BatchEntityManager(2, Entity::create
("end_lvl_bg_sprite@2x.png", 2, 1), this);
        
        Entity* part;
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT + part->getHeight() / 2);
        part->setCurrentFrameIndex(0);
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(Options::CAMERA_CENTER_X, -part->getHeight() / 2);
        part->setCurrentFrameIndex(1);
        
        this->mBackground = Entity::create("end_lvl_bg_popup@2x.png", this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mBackground->setVisible(false);
        
        this->mShopButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, this->mBackground, Options::BUTTONS_ID_END_SHOP, this->mOnTouchCallback);
        this->mMenuButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, this->mBackground, Options::BUTTONS_ID_END_MENU, this->mOnTouchCallback);
        this->mRestartButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, this->mBackground, Options::BUTTONS_ID_END_RESTART, this->mOnTouchCallback);
        this->mContinueButton = Button::create("end_lvl_btn_sprite@2x.png", 4, 1, this->mBackground, Options::BUTTONS_ID_END_CONTINUE, this->mOnTouchCallback);

        if(this->mType == TYPE_PROGRESS)
        {
            this->mContinueButton->create()->setCurrentFrameIndex(2);
            this->mContinueButton->setCenterPosition(this->mBackground->getContentSize().width / 2 + Utils::coord(200), this->mBackground->getContentSize().height / 2 - Utils::coord(320));
                
            this->mRestartButton->create()->setCurrentFrameIndex(1);
            this->mRestartButton->setCenterPosition(this->mBackground->getContentSize().width / 2, this->mBackground->getContentSize().height / 2 - Utils::coord(340));

            this->mMenuButton->create()->setCurrentFrameIndex(0);
            this->mMenuButton->setCenterPosition(this->mBackground->getContentSize().width / 2 - Utils::coord(200), this->mBackground->getContentSize().height / 2 - Utils::coord(320));
        }
        else
        {
            this->mShopButton->create()->setCurrentFrameIndex(3);
            this->mShopButton->setCenterPosition(this->mBackground->getContentSize().width / 2 - Utils::coord(200), this->mBackground->getContentSize().height / 2 - Utils::coord(320));
                
            this->mMenuButton->create()->setCurrentFrameIndex(0);
            this->mMenuButton->setCenterPosition(this->mBackground->getContentSize().width / 2, this->mBackground->getContentSize().height / 2 - Utils::coord(340));

            this->mContinueButton->create()->setCurrentFrameIndex(2);
            this->mContinueButton->setCenterPosition(this->mBackground->getContentSize().width / 2 + Utils::coord(200), this->mBackground->getContentSize().height / 2 - Utils::coord(320));
        }

        if(this->mType == Splash::TYPE_PROGRESS)
        {
            this->mStars = new BatchEntityManager(3, new Star(), this->mBackground);
            
            for(int i = 0; i < 3; i++)
            {
                Entity* star = ((Entity*) this->mStars->create());
                
                star->setCurrentFrameIndex(i + 3);
                star->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(180) * (i - 1), this->mBackground->getHeight() - Utils::coord(100) - Utils::coord(40) * abs(i - 1));
            }
        }
        
        this->setVisible(false);
        
        this->mIsAnimationRunning = false;

        Text* text1 = Text::create((Textes) {"Результаты", Options::FONT, 64, -1}, this->mBackground);
        Text* text2 = Text::create((Textes) {"Результат: 114", Options::FONT, 42, -1}, this->mBackground);
        Text* text3 = Text::create((Textes) {"Рекорд: 114", Options::FONT, 42, -1}, this->mBackground);
        Text* text4 = Text::create((Textes) {"Комбо ударов: 5", Options::FONT, 42, -1}, this->mBackground);
        Text* text5 = Text::create((Textes) {"Заработано монет: 228", Options::FONT, 42, -1}, this->mBackground);

        text1->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(300));
        text2->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(200));
        text3->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(150));
        text4->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(100));
        text5->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(50));
        
        this->mConfetti = new BatchEntityManager(300, new Confetti(), this->mBackground);
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