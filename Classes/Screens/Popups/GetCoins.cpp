#ifndef CONST_GETCOINS
#define CONST_GETCOINS

#include "GetCoins.h"

#include "Shop.h"

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

GetCoins::~GetCoins()
{
    CC_SAFE_RELEASE(this->mLights);
}

GetCoins::GetCoins(CCNode* pParent) :
    Popup(pParent),
	mPurchaseId(0),
	mGetCoinsButtons(),
	mLights(0)
    {
        this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), this->mSpriteBatch2, -1);
        
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        this->mIllustration = Entity::create("popup_getcoins_picture@2x.png", this->mSpriteBatch);
        
		EntityStructure st1 = { "popup_buy_coins_btn_sprite@2x.png", 1, 1, 14, 36, 282, 207 };
		EntityStructure st2 = { "popup_buy_coins_btn_sprite@2x.png", 1, 1, 296, 25, 279, 201 };
		EntityStructure st3 = { "popup_buy_coins_btn_sprite@2x.png", 1, 1, 14, 243, 285, 225 };
		EntityStructure st4 = { "popup_buy_coins_btn_sprite@2x.png", 1, 1, 296, 226, 279, 242 };

        this->mGetCoinsButtons[0] = Button::create(st1, this->mSpriteBatch, Options::BUTTONS_ID_GETCOINS_1, this);
        this->mGetCoinsButtons[1] = Button::create(st2, this->mSpriteBatch, Options::BUTTONS_ID_GETCOINS_2, this);
        this->mGetCoinsButtons[2] = Button::create(st3, this->mSpriteBatch, Options::BUTTONS_ID_GETCOINS_3, this);
        this->mGetCoinsButtons[3] = Button::create(st4, this->mSpriteBatch, Options::BUTTONS_ID_GETCOINS_4, this);
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        Text* text1 = Text::create(Options::TEXT_GETCOINS_STRING_1, this);
        Text* text2 = Text::create(Options::TEXT_GETCOINS_STRING_2, this);
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(190));
        text2->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(50));
        
        this->mGetCoinsButtons[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(140), Options::CAMERA_CENTER_Y - Utils::coord(155));
        this->mGetCoinsButtons[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(140), Options::CAMERA_CENTER_Y - Utils::coord(140));
        this->mGetCoinsButtons[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(140), Options::CAMERA_CENTER_Y - Utils::coord(350));
        this->mGetCoinsButtons[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(140), Options::CAMERA_CENTER_Y - Utils::coord(345));
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(450));

        this->mPurchaseId = -1;
    }

GetCoins* GetCoins::create(CCNode* pParent)
{
    GetCoins* popup = new GetCoins(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void GetCoins::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                this->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_1:

                this->mPurchaseId = 0;

                this->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_2:

                this->mPurchaseId = 1;
                
                this->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_3:

                this->mPurchaseId = 2;
                
                this->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_4:

                this->mPurchaseId = 3;
                
                this->hide();
                
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

    Shop* shop = static_cast<Shop*>(this->mParent);

    switch(this->mPurchaseId)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            shop->mPaymentProceed->show();
        break;
    }

    Shop::PURCHASE_ID = this->mPurchaseId;

    this->mPurchaseId = -1;
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