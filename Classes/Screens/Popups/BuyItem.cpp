#ifndef CONST_BUYITEM
#define CONST_BUYITEM

#include "BuyItem.h"

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

BuyItem::~BuyItem()
{
    CC_SAFE_RELEASE_NULL(this->mList);
}

BuyItem::BuyItem(Screen* pScreen) :
    Popup(pScreen)
    {
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        
        this->mBuyButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_BUYITEM_BUY, this);
        
        this->mListBorders[0] = Entity::create("about_scroll_border_small@2x.png", this->mSpriteBatch);
        this->mListBorders[1] = Entity::create("about_scroll_border_small@2x.png", this->mSpriteBatch);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
        this->mBuyButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mBuyButton->setText(Options::TEXT_BUYITEM_BUY);
        
        this->mListBorders[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(325));
        this->mListBorders[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(325));
        
        this->mListBorders[0]->setScaleY(1);
        this->mListBorders[1]->setScaleY(-1);
        
        this->mList = BuyItemList::create(this);
        
        this->mYesPressed = false;
    }

BuyItem* BuyItem::create(Screen* pScreen)
{
    BuyItem* popup = new BuyItem(pScreen);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void BuyItem::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                this->hide();
                
            break;
            case Options::BUTTONS_ID_BUYITEM_BUY:

                this->mYesPressed = true;
                
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

void BuyItem::show()
{
    Popup::show();

    this->mBuyButton->setVisible(true);

    if(AppDelegate::isItemBought(Shop::CLICKED_ITEM_ID))
    {
        this->mBuyButton->setText(Options::TEXT_BUYITEM_CHOOSE);

        if(Shop::CLICKED_ITEM_ID >= 20)
        {
            this->mBuyButton->setVisible(false);
        }

        if(AppDelegate::isItemSelected(Shop::CLICKED_ITEM_ID))
        {
            this->mBuyButton->setVisible(false);
        }
    }
    else
    {
        this->mBuyButton->setText(Options::TEXT_BUYITEM_BUY);
    }
}

void BuyItem::onShow()
{
    Popup::onShow();
}

void BuyItem::onHide()
{
    Shop* shop = (Shop*) this->getParent();

    if(this->mYesPressed)
    {
        this->mYesPressed = false;

        if((AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_SILVER) >= Options::SHOP_ITEMS_PRICES[Shop::CLICKED_ITEM_ID] && AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_GOLD) >= Options::SHOP_ITEMS_PRICES_GOLD[Shop::CLICKED_ITEM_ID]) || AppDelegate::isItemBought(Shop::CLICKED_ITEM_ID))
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