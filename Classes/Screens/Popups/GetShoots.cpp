#ifndef CONST_GETSHOOTS
#define CONST_GETSHOOTS

#include "GetShoots.h"

#include "Shop.h"
#include "Mode.h"

#include "Loader.h"
#include "Progresses.h"

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

GetShoots::~GetShoots()
{
    CC_SAFE_RELEASE(this->mLights);
}

GetShoots::GetShoots(CCNode* pParent) :
    Popup(pParent, false),
	mCoinsButton(0),
	mLights(0)
    {
        SpriteBatch* spriteBatch19 = SpriteBatch::create("TextureAtlas19");
        this->addChild(spriteBatch19);

        SpriteBatch* spriteBatch11 = SpriteBatch::create("TextureAtlas9");
        this->addChild(spriteBatch11, -1);
        
        this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), spriteBatch11, -1);
        
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        this->mIllustration = Entity::create("popup_gshoot_pic@2x.png", spriteBatch19);
        
		EntityStructure structure1 = {"popup_gshoot_btn@2x.png", 1, 1, 0, 0, 290, 211};

        this->mCoinsButton = Button::create(structure1, spriteBatch19, Options::BUTTONS_ID_GETCOINS_1, this);
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        Text* text1 = Text::create(Options::TEXT_GETSHOOTS_STRING_1, this);
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(220));
        
        this->mCoinsButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(430));
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(190));
    }

GetShoots* GetShoots::create(CCNode* pParent)
{
    GetShoots* popup = new GetShoots(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void GetShoots::onTouchButtonsCallback(const int pAction, const int pID)
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

                this->mDoAction = true;
                
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

void GetShoots::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }
}

void GetShoots::onShow()
{
    Popup::onShow();

    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void GetShoots::onHide()
{
    Popup::onHide();
    
    if(this->mDoAction)
    {
        static_cast<Progresses*>(this->mParent)->mShootCount += Game::LEVEL_SHOOT_COUNT[Game::LEVEL];
        static_cast<Progresses*>(this->mParent)->onBirBlow(-1, 0, 0, 0);
    }
    else if(static_cast<Progresses*>(this->mParent)->mShootCount <= 0)
    {
        static_cast<Progresses*>(this->mParent)->onGameEnd();
    }
    
    static_cast<Progresses*>(this->mParent)->pause();
    
    this->mDoAction = false;
}

void GetShoots::show()
{
    Popup::show();
    
    this->mDoAction = false;
    
    Progresses* game = static_cast<Progresses*>(this->mParent);
    game->pause();
}

void GetShoots::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

#endif