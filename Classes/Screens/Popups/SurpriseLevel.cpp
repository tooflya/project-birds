#ifndef CONST_SURPRISELEVEL
#define CONST_SURPRISELEVEL

#include "SurpriseLevel.h"

#include "Shop.h"
#include "Levels.h"
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

SurpriseLevel::~SurpriseLevel()
{
    CC_SAFE_RELEASE_NULL(this->mLights);
}

SurpriseLevel::SurpriseLevel(CCNode* pParent) :
    Popup(pParent)
    {
        CCSpriteBatchNode* spriteBatch3 = SpriteBatch::create("TextureAtlas9");
        CCSpriteBatchNode* spriteBatch15 = SpriteBatch::create("TextureAtlas15");
        
        this->addChild(spriteBatch3);
        this->addChild(spriteBatch15);
        
        this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), spriteBatch3, 0);
    
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        this->mUnlockButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_BUYITEM_BUY, this);
        this->mIllustration = Entity::create("popup_key_pic_wander@2x.png", spriteBatch15);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        this->mUnlockButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mUnlockButton->setText(Options::TEXT_SURPRISE_OK);
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(2.5);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        Text* text1 = Text::create(Options::TEXT_SURPRISE, this);
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(220));
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));
    }

SurpriseLevel* SurpriseLevel::create(CCNode* pParent)
{
    SurpriseLevel* popup = new SurpriseLevel(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void SurpriseLevel::onTouchButtonsCallback(const int pAction, const int pID)
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

void SurpriseLevel::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.1, 0.3) : Utils::randomf(-0.3, -0.1)));
    }
}

void SurpriseLevel::onShow()
{
    Popup::onShow();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void SurpriseLevel::onHide()
{
    if(this->action)
    {
        this->action = false;
        
        int index = static_cast<Entity*>(static_cast<Levels*>(this->getParent())->mLevels[Game::LEVEL])->getCurrentFrameIndex();
        
        if(index == 8 || index == 9)
        {
            static_cast<Levels*>(this->getParent())->mUnlockLevelPopup->show();
        }
        else
        {
            AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
        }
    }
    
    Popup::onHide();
}

void SurpriseLevel::show()
{
    Popup::show();
    
    this->action = false;
}

void SurpriseLevel::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

#endif