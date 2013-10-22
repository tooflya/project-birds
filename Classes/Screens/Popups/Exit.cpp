#ifndef CONST_EXIT
#define CONST_EXIT

#include "Exit.h"

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

Exit::~Exit()
{
    CC_SAFE_RELEASE(this->mLight);
}

Exit::Exit(CCNode* pParent) :
    Popup(pParent),
	mLightsAnimationReverse(),
	mYesButton(0),
	mLight(0),
	mLights(0)
    {
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        this->mLight = Entity::create("popup_quit_picture_light_main@2x.png", this->mSpriteBatch);
        this->mLights = EntityManager::create(3, Entity::create("popup_quit_picture_light_2@2x.png"), this->mSpriteBatch);
        this->mIllustration = Entity::create("popup_quit_picture@2x.png", this->mSpriteBatch);
    
        this->mYesButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_EXIT_YES, this);
        
        this->mYesButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mYesButton->setText(Options::TEXT_EXIT_YES);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(70), Options::CAMERA_HEIGHT);
        this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(70), Options::CAMERA_HEIGHT);
        this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT);
        
        ((Entity*) this->mLights->objectAtIndex(0))->setOpacity(0.0);
        ((Entity*) this->mLights->objectAtIndex(1))->setOpacity(0.0);
        ((Entity*) this->mLights->objectAtIndex(2))->setOpacity(0.0);
        
        ((Entity*) this->mLights->objectAtIndex(0))->setAnchorPoint(ccp(0.5, 1.0));
        ((Entity*) this->mLights->objectAtIndex(1))->setAnchorPoint(ccp(0.5, 1.0));
        ((Entity*) this->mLights->objectAtIndex(2))->setAnchorPoint(ccp(0.5, 1.0));
        
        ((Entity*) this->mLights->objectAtIndex(0))->setRotation(-8.0);
        ((Entity*) this->mLights->objectAtIndex(1))->setRotation(+8.0);
        
        this->mLight->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(50));
        this->mLight->setOpacity(0.0);
        
        Text* text1 = Text::create(Options::TEXT_EXIT_STRING_1, ccp(Utils::coord(512), 0), this);
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(130));
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(340));
        
        for(int i = 0; i < 3; i++)
        {
            this->mLightsAnimationReverse[i] = Utils::probably(50);
        }
    }

// ===========================================================
// Methods
// ===========================================================

void Exit::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                this->hide();
                
                break;
            case Options::BUTTONS_ID_EXIT_YES:
                
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

void Exit::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    if(this->mBackground->getScaleX() == 1.0)
    {
        for(int i = 0; i < 3; i++)
        {
            Entity* light = (Entity*) this->mLights->objectAtIndex(i);
        
            float opacity = light->getOpacity();
            float o = 0;
            
            switch(i)
            {
                case 0:
                    o = 1.0;
                break;
                case 1:
                    o = 2.0;
                break;
                case 2:
                    o = 3.0;
                break;
            }
        
            opacity += this->mLightsAnimationReverse[i] ? o : -o;
        
            if(opacity <= 0.0)
            {
                opacity = 0.0;
            
                this->mLightsAnimationReverse[i] = !this->mLightsAnimationReverse[i];
            }
            else if(opacity >= 255.0)
            {
                opacity = 255.0;
            
                this->mLightsAnimationReverse[i] = !this->mLightsAnimationReverse[i];
            }
        
            light->setOpacity(opacity);
        }
    }
}

void Exit::hide()
{
    Popup::hide();
    
    this->mLight->runAction(CCFadeTo::create(0.3, 0.0));
    
    for(int i = 0; i < 3; i++)
    {
        Entity* light = (Entity*) this->mLights->objectAtIndex(i);
                         
        light->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

void Exit::show()
{
    Popup::show();
    
    for(int i = 0; i < 3; i++)
    {
        Entity* light = (Entity*) this->mLights->objectAtIndex(i);
        
        light->setOpacity(0.0);
    }
}

void Exit::onShow()
{
    Popup::onShow();

    this->mLight->runAction(CCFadeTo::create(0.3, 255.0));
    
    for(int i = 0; i < 3; i++)
    {
        Entity* light = (Entity*) this->mLights->objectAtIndex(i);
        
        light->runAction(CCFadeTo::create(0.3, 255.0));
    }
}

void Exit::onHide()
{
    Popup::onHide();
}

#endif