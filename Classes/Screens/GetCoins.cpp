#ifndef CONST_GETCOINS
#define CONST_GETCOINS

#include "GetCoins.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

GetCoins* GetCoins::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

GetCoins::GetCoins(Screen* pScreen) :
    Popup(pScreen)
    {
        this->mLights = new BatchEntityManager(2, new Entity("get_coins_light@2x.png"), this->mDarkness);
        
        this->mCloseButton = new Button("btn_sprite@2x.png", 2, 3, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        this->mIllustration = new Entity("popup_getcoins_picture@2x.png", this->mBackground);
        
        this->mGetCoinsButtons[0] = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_GETCOINS_1, onTouchButtonsCallback);
        this->mGetCoinsButtons[1] = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_GETCOINS_1, onTouchButtonsCallback);
        this->mGetCoinsButtons[2] = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_GETCOINS_1, onTouchButtonsCallback);
        this->mGetCoinsButtons[3] = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_GETCOINS_1, onTouchButtonsCallback);
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(this->mDarkness->getWidth() / 2, this->mDarkness->getHeight() - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        this->mCloseButton->create();
        this->mCloseButton->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mCloseButton->setCurrentFrameIndex(3);
        
        Text* text1 = new Text(Options::TEXT_GETCOINS_STRING_1, this->mBackground);
        Text* text2 = new Text(Options::TEXT_GETCOINS_STRING_2, this->mBackground);
        
        text1->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(100)));
        text2->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(20)));
        
        this->mGetCoinsButtons[0]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(150), this->mBackground->getHeight() / 2 - Utils::coord(130));
        this->mGetCoinsButtons[1]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(150), this->mBackground->getHeight() / 2 - Utils::coord(130));
        this->mGetCoinsButtons[2]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(150), this->mBackground->getHeight() / 2 - Utils::coord(300));
        this->mGetCoinsButtons[3]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(150), this->mBackground->getHeight() / 2 - Utils::coord(300));
        
        this->mGetCoinsButtons[0]->setText(Options::TEXT_GETCOINS_1);
        this->mGetCoinsButtons[1]->setText(Options::TEXT_GETCOINS_2);
        this->mGetCoinsButtons[2]->setText(Options::TEXT_GETCOINS_3);
        this->mGetCoinsButtons[3]->setText(Options::TEXT_GETCOINS_4);
        
        this->mIllustration->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() - Utils::coord(140));
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void GetCoins::onTouchButtonsCallback(const int pAction, const int pID)
{
    GetCoins* pSender = (GetCoins*) GetCoins::m_Instance;
    
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

void GetCoins::onShow()
{
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void GetCoins::onHide()
{
}

void GetCoins::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

void GetCoins::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }
}

#endif