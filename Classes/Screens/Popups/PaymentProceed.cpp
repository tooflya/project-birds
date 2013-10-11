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

PaymentProceed* PaymentProceed::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

PaymentProceed::PaymentProceed(CCNode* pParent) :
    Popup(pParent)
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

        m_Instance = this;
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
    PaymentProceed* pSender = static_cast<PaymentProceed*>(PaymentProceed::m_Instance);
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
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

            static_cast<Shop*>(this->mParent)->onPurchase(true);
        }
    }
}

void PaymentProceed::onShow()
{
    Popup::onShow();
    
    this->mWaitingPurchase = true;
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

#endif