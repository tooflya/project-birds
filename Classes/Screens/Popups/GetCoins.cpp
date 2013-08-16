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
        //this->mLights = new EntityManager(2, new Entity("get_coins_light@2x.png"), this->mSpriteBatch, -1);
        
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        this->mIllustration = Entity::create("popup_getcoins_picture@2x.png", this->mSpriteBatch);
        
        this->mGetCoinsButtons[0] = Button::create((EntityStructure) {"popup_buy_coins_btn_sprite@2x.png", 1, 1, 14, 36, 282, 207}, this->mSpriteBatch, Options::BUTTONS_ID_GETCOINS_1, onTouchButtonsCallback);
        this->mGetCoinsButtons[1] = Button::create((EntityStructure) {"popup_buy_coins_btn_sprite@2x.png", 1, 1, 296, 25, 279, 201}, this->mSpriteBatch, Options::BUTTONS_ID_GETCOINS_2, onTouchButtonsCallback);
        this->mGetCoinsButtons[2] = Button::create((EntityStructure) {"popup_buy_coins_btn_sprite@2x.png", 1, 1, 14, 243, 285, 225}, this->mSpriteBatch, Options::BUTTONS_ID_GETCOINS_3, onTouchButtonsCallback);
        this->mGetCoinsButtons[3] = Button::create((EntityStructure) {"popup_buy_coins_btn_sprite@2x.png", 1, 1, 296, 226, 279, 242}, this->mSpriteBatch, Options::BUTTONS_ID_GETCOINS_4, onTouchButtonsCallback);
        
        /*for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }*/
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        Text* text1 = new Text(Options::TEXT_GETCOINS_STRING_1, this);
        Text* text2 = new Text(Options::TEXT_GETCOINS_STRING_2, this);
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(190));
        text2->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(50));
        
        this->mGetCoinsButtons[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(140), Options::CAMERA_CENTER_Y - Utils::coord(155));
        this->mGetCoinsButtons[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(140), Options::CAMERA_CENTER_Y - Utils::coord(140));
        this->mGetCoinsButtons[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(140), Options::CAMERA_CENTER_Y - Utils::coord(350));
        this->mGetCoinsButtons[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(140), Options::CAMERA_CENTER_Y - Utils::coord(345));
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        m_Instance = this;
    }

GetCoins* GetCoins::create(CCNode* pParent)
{
    GetCoins* popup = new GetCoins(pParent);
    popup->autorelease();
    
    return popup;
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
    
    /*for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }*/
}

void GetCoins::onShow()
{
    Popup::onShow();

    /*for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }*/
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
    
    /*for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }*/
}

#endif