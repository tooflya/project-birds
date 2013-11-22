#ifndef CONST_PAYMENTPROCEED
#define CONST_PAYMENTPROCEED

#include "PaymentProceed.h"

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

PaymentProceed::~PaymentProceed()
{
}

PaymentProceed::PaymentProceed(CCNode* pParent) :
    Popup(pParent),
	mUpdateTimes(0),
	mUpdateTime(0),
	mUpdateTimeElapsed(0),
	mUpdateTimeTotal(0),
	mWaitingPurchase(0),
	mCancelButton(0),
	mTextes()
    {
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        this->mCancelButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        this->mCancelButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mCancelButton->setText(Options::TEXT_PAYMENT_STRING[5]);

        this->mTextes[0] = Text::create(Options::TEXT_PAYMENT_STRING[0], ccp(Utils::coord(500), 0), this);
        this->mTextes[1] = Text::create(Options::TEXT_PAYMENT_STRING[1], ccp(Utils::coord(500), 0), this);
        this->mTextes[2] = Text::create(Options::TEXT_PAYMENT_STRING[4], ccp(Utils::coord(500), 0), this);

        this->mTextes[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(250));
        this->mTextes[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(0));
        this->mTextes[2]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(250));

        this->mUpdateTimes = 2;

        this->mUpdateTime = 0.5;
        this->mUpdateTimeElapsed = 0;

        this->mUpdateTimeTotal = 0;
        
        this->mPostShow = false;
        this->mPostShowTime = 1.5;
        this->mPostShowTimeElapsed = 0;
        
        Options::PAYMENT_PROCEED_HANDLER = this;
    }

PaymentProceed* PaymentProceed::create(CCNode* pParent)
{
    PaymentProceed* popup = new PaymentProceed(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void PaymentProceed::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
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

void PaymentProceed::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);

    this->mUpdateTimeElapsed += pDeltaTime;

    if(this->mUpdateTimeElapsed >= this->mUpdateTime)
    {
        this->mUpdateTimeElapsed = 0;

        this->mTextes[2]->setString(Options::TEXT_PAYMENT_STRING[this->mUpdateTimes++].string);

        if(this->mUpdateTimes >= 5)
        {
            this->mUpdateTimes = 2;
        }
    }

    if(this->mWaitingPurchase)
    {
        this->mUpdateTimeTotal += pDeltaTime;

        if(this->mUpdateTimeTotal >= 5.0)
        {
            this->mUpdateTimeTotal = 0;
            this->mWaitingPurchase = false;

            this->onItemPurchased();
        }
    }
    
    if(this->mPostShow)
    {
        this->mPostShowTimeElapsed += pDeltaTime;
        
        if(this->mPostShowTimeElapsed >= this->mPostShowTime)
        {
            this->mPostShow = false;
            
            this->onPostShow();
        }
    }
}

void PaymentProceed::onShow()
{
    Popup::onShow();

    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    this->mPostShow = true;
    this->mPostShowTimeElapsed = 0;
    #else
    this->mWaitingPurchase = true;
    #endif
}

void PaymentProceed::onPostShow()
{
    const char* id = "";
    
    switch(Shop::PURCHASE_ID)
    {
        case 0:
            id = Options::IN_APP_COINS_PACK_1_ID;
            break;
        case 1:
            id = Options::IN_APP_COINS_PACK_2_ID;
            break;
        case 2:
            id = Options::IN_APP_COINS_PACK_3_ID;
            break;
        case 3:
            id = Options::IN_APP_COINS_PACK_4_ID;
            break;
        case 4:
            id = Options::IN_APP_RESTORE_LIVES_ID;
            break;
        case 5:
            id = Options::IN_APP_RESTORE_LIVES_ID;
            break;
        case 6:
            id = Options::IN_APP_KEYS_PACK_1_ID;
            break;
        case 7:
            id = Options::IN_APP_KEYS_PACK_2_ID;
            break;
            
        default:
            return;
            break;
    }
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    soomla::CCSoomlaError *soomlaError = NULL;
    soomla::CCStoreInventory::sharedStoreInventory()->buyItem(id, &soomlaError);
    if (soomlaError)
    {
        soomla::CCStoreUtils::logException("In-App", soomlaError);
    }
    #endif
}

void PaymentProceed::onHide()
{
    Popup::onHide();
}

void PaymentProceed::show()
{
    Popup::show();
}

void PaymentProceed::hide()
{
    Popup::hide();
}

void PaymentProceed::onItemPurchased()
{
    this->hide();
    
    static_cast<Shop*>(this->mParent)->onPurchase(true);
}

#endif