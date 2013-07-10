#ifndef CONST_BUYITEM
#define CONST_BUYITEM

#include "BuyItem.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

BuyItem* BuyItem::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

BuyItem::BuyItem(Screen* pScreen) :
    Popup(pScreen)
    {
        this->mCloseButton = new Button("btn_sprite@2x.png", 2, 3, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        
        this->mBuyButton = new Button("popup_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_BUYITEM_BUY, onTouchButtonsCallback);
        
        this->mCloseButton->create();
        this->mCloseButton->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mCloseButton->setCurrentFrameIndex(3);
        
        this->mBuyButton->create()->setCenterPosition(this->mBackground->getWidth() / 2, Utils::coord(40));
        this->mBuyButton->setText(Options::TEXT_BUYITEM_BUY);
        
        this->mShouldOpenGetCoins = false;
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void BuyItem::onTouchButtonsCallback(const int pAction, const int pID)
{
    BuyItem* pSender = (BuyItem*) BuyItem::m_Instance;
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_BUYITEM_BUY:
                
                pSender->hide();
                
                if(Utils::random(0, 1) == 1)
                {
                    pSender->mShouldOpenGetCoins = true;
                }
                
            break;
        }
        break;
            
        case Options::BUTTONS_ACTION_ONBEGIN:
        break;
            
        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void BuyItem::onHide()
{
    if(this->mShouldOpenGetCoins)
    {
        this->mShouldOpenGetCoins = false;
        
        Shop* shop = (Shop*) this->getParent();
        
        shop->mGetCoinsPopup->show();
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif