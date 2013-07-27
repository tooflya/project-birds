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

GetCoins::GetCoins(CCNode* pParent) :
    Popup(pParent)
    {
        this->mLights = new BatchEntityManager(2, new Entity("get_coins_light@2x.png"), this->mDarkness);
        
        this->mCloseButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 162, 162, 162}, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        this->mIllustration = new Entity("popup_getcoins_picture@2x.png", this->mBackground);
        
        this->mGetCoinsButtons[0] = new Button((EntityStructure) {"popup_buy_coins_btn_sprite@2x.png", 1, 1, 14, 36, 282, 207}, this->mBackground, Options::BUTTONS_ID_GETCOINS_1, onTouchButtonsCallback);
        this->mGetCoinsButtons[1] = new Button((EntityStructure) {"popup_buy_coins_btn_sprite@2x.png", 1, 1, 296, 25, 279, 201}, this->mBackground, Options::BUTTONS_ID_GETCOINS_2, onTouchButtonsCallback);
        this->mGetCoinsButtons[2] = new Button((EntityStructure) {"popup_buy_coins_btn_sprite@2x.png", 1, 1, 14, 243, 285, 225}, this->mBackground, Options::BUTTONS_ID_GETCOINS_3, onTouchButtonsCallback);
        this->mGetCoinsButtons[3] = new Button((EntityStructure) {"popup_buy_coins_btn_sprite@2x.png", 1, 1, 296, 226, 279, 242}, this->mBackground, Options::BUTTONS_ID_GETCOINS_4, onTouchButtonsCallback);
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(this->mDarkness->getWidth() / 2, this->mDarkness->getHeight() - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        this->mCloseButton->create()->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        
        Text* text1 = new Text(Options::TEXT_GETCOINS_STRING_1, this->mBackground);
        Text* text2 = new Text(Options::TEXT_GETCOINS_STRING_2, this->mBackground);
        Text* text3 = new Text(Options::TEXT_GETCOINS_STRING_3, this->mBackground);
        Text* text4 = new Text(Options::TEXT_GETCOINS_STRING_4, this->mBackground);
        
        text1->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(190)));
        text2->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(140)));
        text3->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(50)));
        text4->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(0)));
        
        this->mGetCoinsButtons[0]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(140), this->mBackground->getHeight() / 2 - Utils::coord(155));
        this->mGetCoinsButtons[1]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(140), this->mBackground->getHeight() / 2 - Utils::coord(140));
        this->mGetCoinsButtons[2]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(140), this->mBackground->getHeight() / 2 - Utils::coord(350));
        this->mGetCoinsButtons[3]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(140), this->mBackground->getHeight() / 2 - Utils::coord(345));
        
        this->mIllustration->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() - Utils::coord(70));
        
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
            case Options::BUTTONS_ID_GETCOINS_1:
                
                AppDelegate::addCoins(1000, Options::SAVE_DATA_COINS_TYPE_GOLD);

                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_2:
                
                AppDelegate::addCoins(5000, Options::SAVE_DATA_COINS_TYPE_GOLD);
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_3:
                
                AppDelegate::addCoins(15000, Options::SAVE_DATA_COINS_TYPE_GOLD);
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_4:
                
                AppDelegate::addCoins(50000, Options::SAVE_DATA_COINS_TYPE_GOLD);
                
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

void GetCoins::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }
}

void GetCoins::onShow()
{
    Popup::onShow();

    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void GetCoins::onHide()
{
    Popup::onHide();
}

void GetCoins::show()
{
    Popup::show();
}

void GetCoins::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

#endif