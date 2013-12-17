#ifndef CONST_GOOGLEPLAYAUTHORIZE
#define CONST_GOOGLEPLAYAUTHORIZE

#include "GooglePlayAuthorize.h"

#include "Mode.h"

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

GooglePlayAuthorize::~GooglePlayAuthorize()
{
    CC_SAFE_RELEASE(this->mLights);
}

GooglePlayAuthorize::GooglePlayAuthorize(CCNode* pParent) :
    Popup(pParent),
    mResetButton(0),
    mAction(0),
    mLights(0)
    {
        SpriteBatch* sb = SpriteBatch::create("TextureAtlas18");
        this->addChild(sb);
    
        this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), this->mSpriteBatch2, -1);
    
        this->mIllustration = Entity::create("popup_social_picture@2x.png", sb);
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
    
        this->mResetButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_RESET_RESET, this);
    
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
    
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
    
        this->mTextes[0] = Text::create(Options::TEXT_GOOGLE_PLUS[0], ccp(Utils::coord(500), 0), this);
        this->mTextes[1] = Text::create(Options::TEXT_GOOGLE_PLUS[1], ccp(Utils::coord(500), 0), this);
    
        this->mTextes[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(100));
        this->mTextes[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(250));
    
        this->mResetButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mResetButton->setText(Options::TEXT_SING_IN);
    
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(280));
    
        this->mAction = false;
    }

GooglePlayAuthorize* GooglePlayAuthorize::create(CCNode* pParent)
{
    GooglePlayAuthorize* popup = new GooglePlayAuthorize(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void GooglePlayAuthorize::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                this->mAction = true;
                
                this->hide();
                
                break;
            case Options::BUTTONS_ID_RESET_RESET:
                
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

void GooglePlayAuthorize::onShow()
{
    Popup::onShow();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void GooglePlayAuthorize::onHide()
{
    Popup::onHide();
    
    if(this->mAction)
    {
        if(AppDelegate::screens->mCurrentScreenIndex == Screen::SCREEN_MENU)
        {
            #if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
            AppDelegate::screens->set(Screen::SCREEN_MODE);
            #else
            AppDelegate::screens->set(Mode::create());
            #endif
            
            #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
            if(!AppDelegate::isVideoShowed())
            {
                callStaticVoidMethod("intro");
                
                CCUserDefault::sharedUserDefault()->setBoolForKey("is_video_showed", true);
                CCUserDefault::sharedUserDefault()->flush();
            }
            #endif
        }
        else
        {
            static_cast<Mode*>(this->mParent)->onGooglePlayAuthorizeHide();
        }
    }
    else
    {
        #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        AppDelegate::mGameCenter->signIn();
        #endif
    }
    
    this->mAction = false;
}

void GooglePlayAuthorize::show()
{
    Popup::show();
}

void GooglePlayAuthorize::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
}

void GooglePlayAuthorize::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }
}

#endif