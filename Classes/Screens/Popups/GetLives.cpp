#ifndef CONST_GETLIVES
#define CONST_GETLIVES

#include "GetLives.h"

#include "Shop.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

GetLives* GetLives::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

GetLives::~GetLives()
{
    this->mLights->release();
}

GetLives::GetLives(CCNode* pParent) :
    Popup(pParent)
    {
        CCSpriteBatchNode* spriteBatch3 = CCSpriteBatchNode::create("TextureAtlas3.png");
        this->addChild(spriteBatch3);
        
        this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), this->mSpriteBatch2, -1);
        
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        this->mIllustration = Entity::create("popup_glife_pic@2x.png", spriteBatch3);
        
        this->mGetCoinsButtons[0] = Button::create((EntityStructure) {"popup_glife_btn1@2x.png", 1, 1, 0, 0, 298, 230}, spriteBatch3, Options::BUTTONS_ID_GETCOINS_1, onTouchButtonsCallback);
        this->mGetCoinsButtons[1] = Button::create((EntityStructure) {"popup_glife_btn2@2x.png", 1, 1, 0, 0, 309, 247}, spriteBatch3, Options::BUTTONS_ID_GETCOINS_2, onTouchButtonsCallback);
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        Text* text1 = Text::create(Options::TEXT_GETLIVES_STRING_1, this);
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(160));
        
        this->mGetCoinsButtons[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(160), Options::CAMERA_CENTER_Y - Utils::coord(350));
        this->mGetCoinsButtons[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(120), Options::CAMERA_CENTER_Y - Utils::coord(338));
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(230));

        this->mPurchaseId = -1;
        
        m_Instance = this;
    }

GetLives* GetLives::create(CCNode* pParent)
{
    GetLives* popup = new GetLives(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void GetLives::onTouchButtonsCallback(const int pAction, const int pID)
{
    GetLives* pSender = static_cast<GetLives*>(GetLives::m_Instance);
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_1:

                pSender->mPurchaseId = 4;

                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_2:

                pSender->mPurchaseId = 5;
                
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

void GetLives::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }
}

void GetLives::onShow()
{
    Popup::onShow();

    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void GetLives::onHide()
{
    Popup::onHide();

    Shop* shop = static_cast<Shop*>(this->mParent);
    
    switch(this->mPurchaseId)
    {
        case 4:
        case 5:
        shop->mPaymentProceed->show();
        break;
    }

    Shop::PURCHASE_ID = this->mPurchaseId;

    this->mPurchaseId = -1;
}

void GetLives::show()
{
    Popup::show();
}

void GetLives::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

#endif