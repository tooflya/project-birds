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
        
        this->mListBorders = new BatchEntityManager(2, new Entity("about_scroll_border_small@2x.png"), this->mBackground);
        
        this->mCloseButton->create();
        this->mCloseButton->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mCloseButton->setCurrentFrameIndex(3);
        
        this->mBuyButton->create()->setCenterPosition(this->mBackground->getWidth() / 2, Utils::coord(40));
        this->mBuyButton->setText(Options::TEXT_BUYITEM_BUY);
        
        this->mListBorders->create();
        this->mListBorders->create();
        
        ((Entity*) this->mListBorders->objectAtIndex(0))->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(325));
        ((Entity*) this->mListBorders->objectAtIndex(1))->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 - Utils::coord(325));
        
        ((Entity*) this->mListBorders->objectAtIndex(0))->setScaleY(1);
        ((Entity*) this->mListBorders->objectAtIndex(1))->setScaleY(-1);
        
        this->mList = new BuyItemList(this->mBackground);
        
        this->mYesPressed = false;
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void BuyItem::onTouchButtonsCallback(const int pAction, const int pID)
{
    BuyItem* pSender = static_cast<BuyItem*>(BuyItem::m_Instance);
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_BUYITEM_BUY:

                pSender->mYesPressed = true;
                
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

void BuyItem::onHide()
{
    Shop* shop = (Shop*) this->getParent();

    if(this->mYesPressed)
    {
        this->mYesPressed = false;

        if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_GOLD) >= Options::SHOP_ITEMS_PRICES[Shop::CLICKED_ITEM_ID])
        {
            shop->onItemBought(Shop::CLICKED_ITEM_ID);
        }
        else
        {
            shop->mGetCoinsPopup->show();
        }
    }
    
    Popup::onHide();
}

// ===========================================================
// Override Methods
// ===========================================================

#endif