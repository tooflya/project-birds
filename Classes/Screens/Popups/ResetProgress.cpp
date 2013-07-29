#ifndef CONST_RESETPROGRESS
#define CONST_RESETPROGRESS

#include "ResetProgress.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ResetProgress* ResetProgress::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

ResetProgress::ResetProgress(CCNode* pParent) :
    Popup(pParent)
    {
        this->mLights = new BatchEntityManager(2, new Entity("get_coins_light@2x.png"), this->mDarkness);
    
        this->mIllustration = new Entity("popup_progress_picture@2x.png", this->mBackground);
        this->mCloseButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 162, 162, 162}, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
    
        this->mResetButton = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_RESET_RESET, onTouchButtonsCallback);
        
        this->mCloseButton->create()->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(this->mDarkness->getWidth() / 2, this->mDarkness->getHeight() - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        Text* text1 = new Text(Options::TEXT_RESET_STRING_1, ccp(Utils::coord(512), 0), this->mBackground);
        
        text1->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(100));
        
        this->mResetButton->create()->setCenterPosition(this->mBackground->getWidth() / 2, Utils::coord(40));
        this->mResetButton->setText(Options::TEXT_RESET_RESET);
        
        this->mIllustration->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() - Utils::coord(140));
        
        this->mAction = false;
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void ResetProgress::onTouchButtonsCallback(const int pAction, const int pID)
{
    ResetProgress* pSender = (ResetProgress*) ResetProgress::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_RESET_RESET:
                
                pSender->mAction = true;
                
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

// ===========================================================
// Override Methods
// ===========================================================

void ResetProgress::onShow()
{
    Popup::onShow();

    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void ResetProgress::onHide()
{
    Popup::onHide();

    if(this->mAction)
    {
        AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);
    }
    
    this->mAction = false;
}

void ResetProgress::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

void ResetProgress::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }
}

#endif