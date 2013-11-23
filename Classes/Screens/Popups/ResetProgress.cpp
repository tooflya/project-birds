#ifndef CONST_RESETPROGRESS
#define CONST_RESETPROGRESS

#include "ResetProgress.h"

#include "Levels.h"
#include "Menu.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ResetProgress* ResetProgress::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

ResetProgress::~ResetProgress()
{
    CC_SAFE_RELEASE(this->mLights);
}

ResetProgress::ResetProgress(CCNode* pParent) :
    Popup(pParent),
	mResetButton(0),
	mAction(0),
	mLights(0)
    {
        this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), this->mSpriteBatch2, -1);
    
        this->mIllustration = Entity::create("popup_progress_picture@2x.png", this->mSpriteBatch);
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
    
        this->mResetButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_RESET_RESET, this);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        Text* text1 = Text::create(Options::TEXT_RESET_STRING_1, ccp(Utils::coord(512), 0), this);
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(130));
        
        this->mResetButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mResetButton->setText(Options::TEXT_RESET_RESET);
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(340));
        
        this->mAction = false;
        
        m_Instance = this;
    }

ResetProgress* ResetProgress::create(CCNode* pParent)
{
    ResetProgress* popup = new ResetProgress(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void ResetProgress::onTouchButtonsCallback(const int pAction, const int pID)
{
    ResetProgress* pSender = (ResetProgress*) ResetProgress::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_RESET_RESET:
                
                pSender->mAction = true;
                
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

void ResetProgress::onShow()
{
    Popup::onShow();

    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void ResetProgress::onHide()
{
    Popup::onHide();

    if(this->mAction)
    {
        AppDelegate::install(true);

		#if CC_TOTAL_PRELOAD == 0
        static_cast<Levels*>(AppDelegate::screens->mScreens[Screen::SCREEN_LEVELS])->updateIcons();
		#endif

		AppDelegate::screens->set(Menu::create());
    }
    
    this->mAction = false;
}

void ResetProgress::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

void ResetProgress::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }
}

#endif