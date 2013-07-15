#ifndef CONST_PLEASERATE
#define CONST_PLEASERATE

#include "PleaseRate.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

PleaseRate* PleaseRate::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

PleaseRate::PleaseRate(CCNode* pParent) :
    Popup(pParent)
    {
        this->mLights = new BatchEntityManager(2, new Entity("get_coins_light@2x.png"), this->mDarkness);
    
        this->mIllustration = new Entity("popup_rate_picture@2x.png", this->mBackground);
        this->mCloseButton = new Button("btn_sprite@2x.png", 2, 3, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
    
        this->mRateButton = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_RATE_RATE, onTouchButtonsCallback);
        
        this->mCloseButton->create();
        this->mCloseButton->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mCloseButton->setCurrentFrameIndex(3);
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(this->mDarkness->getWidth() / 2, this->mDarkness->getHeight() - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        Text* text1 = new Text(Options::TEXT_RATE_STRING_1, this->mBackground);
        Text* text2 = new Text(Options::TEXT_RATE_STRING_2, this->mBackground);
        Text* text3 = new Text(Options::TEXT_RATE_STRING_3, this->mBackground);
        Text* text4 = new Text(Options::TEXT_RATE_STRING_4, this->mBackground);
        
        text1->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(50)));
        text2->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(50)));
        text3->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(150)));
        text4->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(250)));
        
        this->mRateButton->create()->setCenterPosition(this->mBackground->getWidth() / 2, Utils::coord(40));
        this->mRateButton->setText(Options::TEXT_RATE_NOW);
        
        this->mIllustration->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() - Utils::coord(140));
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void PleaseRate::onTouchButtonsCallback(const int pAction, const int pID)
{
    PleaseRate* pSender = (PleaseRate*) PleaseRate::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_RATE_RATE:
                
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

void PleaseRate::onShow()
{
    Popup::onShow();

    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void PleaseRate::onHide()
{
    Popup::onHide();
}

void PleaseRate::show()
{
    Popup::show();
}

void PleaseRate::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void PleaseRate::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }
}

#endif