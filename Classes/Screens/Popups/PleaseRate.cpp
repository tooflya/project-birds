#ifndef CONST_PLEASERATE
#define CONST_PLEASERATE

#include "PleaseRate.h"

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

PleaseRate::~PleaseRate()
{
    CC_SAFE_RELEASE(this->mLights);
}

PleaseRate::PleaseRate(CCNode* pParent) :
    Popup(pParent),
	mRateButton(0),
	mLights()
    {
        this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), this->mSpriteBatch2, -1);
    
        this->mIllustration = Entity::create("popup_rate_picture@2x.png", this->mSpriteBatch);
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
    
        this->mRateButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_RATE_RATE, this);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        Text* text1 = Text::create(Options::TEXT_RATE_STRING_1, ccp(Utils::coord(512), 0), this);
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(130));
        
        this->mRateButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mRateButton->setText(Options::TEXT_RATE_NOW);
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(340));
    }

PleaseRate* PleaseRate::create(CCNode* pParent)
{
    PleaseRate* popup = new PleaseRate(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void PleaseRate::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                this->hide();
                
            break;
            case Options::BUTTONS_ID_RATE_RATE:
                
                AppDelegate::setRate();

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