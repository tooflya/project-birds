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

End* End::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

End::End(CCNode* pParent) :
    Splash(pParent)
    {
        this->mParts = new BatchEntityManager(2, new Entity("end_lvl_bg_sprite@2x.png", 2, 1), this);
        
        Entity* part;
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT + part->getHeight() / 2);
        part->setCurrentFrameIndex(0);
        
        part = (Entity*) this->mParts->create();
        part->setCenterPosition(Options::CAMERA_CENTER_X, -part->getHeight() / 2);
        part->setCurrentFrameIndex(1);
        
        this->mBackground = new Entity("end_lvl_bg_popup@2x.png", this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mBackground->setVisible(false);
        
        this->mMenuButton = new Button("end_lvl_btn_sprite@2x.png", 3, 1, this->mBackground, Options::BUTTONS_ID_END_MENU, onTouchButtonsCallback);
        this->mRestartButton = new Button("end_lvl_btn_sprite@2x.png", 3, 1, this->mBackground, Options::BUTTONS_ID_END_RESTART, onTouchButtonsCallback);
        this->mContinueButton = new Button("end_lvl_btn_sprite@2x.png", 3, 1, this->mBackground, Options::BUTTONS_ID_END_CONTINUE, onTouchButtonsCallback);

        this->mContinueButton->create()->setCurrentFrameIndex(2);
        this->mContinueButton->setCenterPosition(this->mBackground->getContentSize().width / 2 + Utils::coord(200), this->mBackground->getContentSize().height / 2 - Utils::coord(320));
            
        this->mRestartButton->create()->setCurrentFrameIndex(1);
        this->mRestartButton->setCenterPosition(this->mBackground->getContentSize().width / 2, this->mBackground->getContentSize().height / 2 - Utils::coord(340));

        this->mMenuButton->create()->setCurrentFrameIndex(0);
        this->mMenuButton->setCenterPosition(this->mBackground->getContentSize().width / 2 - Utils::coord(200), this->mBackground->getContentSize().height / 2 - Utils::coord(300));
        
        this->mConfetti = new ConfettiManager(100, new Confetti(), this->mBackground);
        this->mStars = new BatchEntityManager(3, new Star(), this->mBackground);
        
        for(int i = 0; i < 3; i++)
        {
            Entity* star = ((Entity*) this->mStars->create());
            
            star->setCurrentFrameIndex(i + 3);
            star->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(180) * (i - 1), this->mBackground->getHeight() - Utils::coord(100) - Utils::coord(40) * abs(i - 1));
        }
        
        this->setVisible(false);
        
        this->mIsAnimationRunning = false;
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void End::onTouchButtonsCallback(const int pAction, const int pID)
{
    End* pSender = (End*) End::m_Instance;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_END_MENU:
                    
                    Loader::ACTION = 3;

                    AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);

                break;
                case Options::BUTTONS_ID_END_RESTART:

                    pSender->hide();

                break;
                case Options::BUTTONS_ID_END_CONTINUE:
                    
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

void End::onShow()
{
    this->mIsAnimationRunning = true;
    
    this->mAnimationTime = 0.6;
    this->mAnimationtimeElapsed = 0;
    
    this->mAnimationCounter = 0;
}

void End::onHide()
{
    for(int i = 0; i < 3; i++)
    {
        Entity* star = ((Entity*) this->mStars->objectAtIndex(i));
        
        star->setCurrentFrameIndex(star->getCurrentFrameIndex() + 3);
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
            
            Star* star = (Star*) this->mStars->objectAtIndex(this->mAnimationCounter);
            
            star->setCurrentFrameIndex(star->getCurrentFrameIndex() - 3);
            star->animate();
            
            this->mConfetti->init(star->getCenterX(), star->getCenterY());
            
            if(this->mAnimationCounter == (3 - 1))
            {
                this->mIsAnimationRunning = false;
            }
            
            this->mAnimationCounter++;
        }
    }
}

#endif