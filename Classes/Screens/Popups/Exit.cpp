#ifndef CONST_EXIT
#define CONST_EXIT

#include "Exit.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Exit* Exit::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Exit::Exit(CCNode* pParent) :
    Popup(pParent)
    {
        this->mCloseButton = new Button("btn_sprite@2x.png", 2, 3, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        this->mLight = new Entity("popup_quit_picture_light_main@2x.png", this->mBackground);
        this->mLights = new BatchEntityManager(3, new Entity("popup_quit_picture_light_2@2x.png"), this->mBackground);
        this->mIllustration = new Entity("popup_quit_picture@2x.png", this->mBackground);
    
        this->mYesButton = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_EXIT_YES, onTouchButtonsCallback);
        
        this->mYesButton->create()->setCenterPosition(this->mBackground->getWidth() / 2, Utils::coord(40));
        this->mYesButton->setText(Options::TEXT_EXIT_YES);
        
        this->mCloseButton->create();
        this->mCloseButton->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mCloseButton->setCurrentFrameIndex(3);
        
        this->mLights->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(50), this->mBackground->getHeight() + (Options::CAMERA_HEIGHT - this->mBackground->getHeight()) / 2 + Utils::coord(30));
        this->mLights->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(50), this->mBackground->getHeight() + (Options::CAMERA_HEIGHT - this->mBackground->getHeight()) / 2 + Utils::coord(30));
        this->mLights->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() + (Options::CAMERA_HEIGHT - this->mBackground->getHeight()) / 2 + Utils::coord(30));
        
        ((Entity*) this->mLights->objectAtIndex(0))->setOpacity(0.0);
        ((Entity*) this->mLights->objectAtIndex(1))->setOpacity(0.0);
        ((Entity*) this->mLights->objectAtIndex(2))->setOpacity(0.0);
        
        ((Entity*) this->mLights->objectAtIndex(0))->setAnchorPoint(ccp(0.5, 1.0));
        ((Entity*) this->mLights->objectAtIndex(1))->setAnchorPoint(ccp(0.5, 1.0));
        ((Entity*) this->mLights->objectAtIndex(2))->setAnchorPoint(ccp(0.5, 1.0));
        
        ((Entity*) this->mLights->objectAtIndex(0))->setRotation(-8.0);
        ((Entity*) this->mLights->objectAtIndex(1))->setRotation(+8.0);
        
        this->mLight->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() - this->mLight->getHeight() / 2 + (Options::CAMERA_HEIGHT - this->mBackground->getHeight()) / 2);
        this->mLight->setOpacity(0.0);
        
        Text* text1 = new Text(Options::TEXT_EXIT_STRING_1, this->mBackground);
        Text* text2 = new Text(Options::TEXT_EXIT_STRING_2, this->mBackground);
        
        text1->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(50)));
        text2->setPosition(ccp(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(150)));
        
        this->mIllustration->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() - Utils::coord(140));
        
        for(int i = 0; i < 3; i++)
        {
            this->mLightsAnimationReverse[i] = Utils::probably(50);
        }
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void Exit::onTouchButtonsCallback(const int pAction, const int pID)
{
    Exit* pSender = (Exit*) Exit::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
                break;
            case Options::BUTTONS_ID_EXIT_YES:
                
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