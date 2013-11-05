#ifndef CONST_UNLOCKMODE
#define CONST_UNLOCKMODE

#include "UnlockMode.h"

#include "Shop.h"
#include "Mode.h"
#include "Game.h"

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

UnlockMode::~UnlockMode()
{
    CC_SAFE_RELEASE(this->mLights);
}

UnlockMode::UnlockMode(CCNode* pParent) :
    Popup(pParent),
	mKey(0),
	mUnlockButton(0),
	mPriceText(0),
	mLights(0),
	action(0)
    {
        CCSpriteBatchNode* spriteBatch3 = SpriteBatch::create("TextureAtlas9");
        this->addChild(spriteBatch3);
        
        this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), spriteBatch3, 0);
    
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        this->mUnlockButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_BUYITEM_BUY, this);
        this->mIllustration = Entity::create("popup_key_pic@2x.png", this->mSpriteBatch);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        this->mUnlockButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mUnlockButton->setText(Options::TEXT_UNLOCKLEVEL_OK);
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(310));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(0.7);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        this->mKey = Entity::create("popup_key_ico_fall_price@2x.png", spriteBatch3);
        
        Text* text1 = Text::create(Options::TEXT_UNLOCKMODE, this);

		Textes textes1 = {"", Options::FONT, 64, -1};

        this->mPriceText = Text::create(textes1, this);
        this->mPriceText->setColor(ccc3(255, 200, 15));
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(150));
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));
        
        this->mKey->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(20), Options::CAMERA_CENTER_Y - Utils::coord(310));
    }

UnlockMode* UnlockMode::create(CCNode* pParent)
{
    UnlockMode* popup = new UnlockMode(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void UnlockMode::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                this->hide();
                
            break;
            case Options::BUTTONS_ID_BUYITEM_BUY:
                
                this->action = true;
                
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

void UnlockMode::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.1, 0.3) : Utils::randomf(-0.3, -0.1)));
    }
}

void UnlockMode::onShow()
{
    Popup::onShow();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void UnlockMode::onHide()
{
    if(this->action)
    {
        this->action = false;
        
        if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_KEYS) >= Mode::PRICES[Mode::UNLOCK_ACTION])
        {
            static_cast<Mode*>(this->mParent)->unlock();
        }
        else
        {
            Shop::ACTION = 6;
            
            AppDelegate::screens->set(0.5, Screen::SCREEN_SHOP);
        }
    }
    
    Popup::onHide();
}

void UnlockMode::show()
{
    Popup::show();
    
    this->action = false;
    
    this->mPriceText->setString(ccsf("%d", Mode::PRICES[Mode::UNLOCK_ACTION]));
    
    if(Mode::PRICES[Mode::UNLOCK_ACTION] < 10)
    {
        this->mKey->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(20), Options::CAMERA_CENTER_Y - Utils::coord(310));
        this->mPriceText->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(20) + this->mPriceText->getWidth() / 2, Options::CAMERA_CENTER_Y - Utils::coord(310));
    }
    else
    {
        this->mKey->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(50), Options::CAMERA_CENTER_Y - Utils::coord(310));
        this->mPriceText->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(10) + this->mPriceText->getWidth() / 2, Options::CAMERA_CENTER_Y - Utils::coord(310));
    }
    
}

void UnlockMode::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

#endif