#ifndef CONST_GETKEYS
#define CONST_GETKEYS

#include "GetKeys.h"

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

GetKeys::~GetKeys()
{
    CC_SAFE_RELEASE_NULL(this->mLights);
}

GetKeys::GetKeys(CCNode* pParent) :
    Popup(pParent)
    {
        this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), this->mSpriteBatch2, -1);
        
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        this->mIllustration = Entity::create("popup_key_pic@2x.png", this->mSpriteBatch);
        
		EntityStructure st1 = {"popup_key_btn1@2x.png", 1, 1, 0, 0, 265, 231};
		EntityStructure st2 = {"popup_key_btn2@2x.png", 1, 1, 0, 0, 273, 232};

        this->mGetCoinsButtons[0] = Button::create(st1, this->mSpriteBatch, Options::BUTTONS_ID_GETCOINS_1, this);
		this->mGetCoinsButtons[1] = Button::create(st2, this->mSpriteBatch, Options::BUTTONS_ID_GETCOINS_2, this);
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        Text* text1 = Text::create(Options::TEXT_GETKEYS_STRING_1, this);
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(150));
        
        this->mGetCoinsButtons[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(140), Options::CAMERA_CENTER_Y - Utils::coord(350));
        this->mGetCoinsButtons[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(140), Options::CAMERA_CENTER_Y - Utils::coord(350));
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));

        this->mPurchaseId = -1;
    }

GetKeys* GetKeys::create(CCNode* pParent)
{
    GetKeys* popup = new GetKeys(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void GetKeys::onTouchButtonsCallback(const int pAction, const int pID)
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

                this->mPurchaseId = 6;

                this->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_2:

                this->mPurchaseId = 7;
                
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

void GetKeys::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }
}

void GetKeys::onShow()
{
    Popup::onShow();

    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void GetKeys::onHide()
{
    Popup::onHide();

    Shop* shop = static_cast<Shop*>(this->mParent);
    
    switch(this->mPurchaseId)
    {
        case 7:
        case 6:
            shop->mPaymentProceed->show();
        break;
    }

    Shop::PURCHASE_ID = this->mPurchaseId;

    this->mPurchaseId = -1;
}

void GetKeys::show()
{
    Popup::show();
}

void GetKeys::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

#endif