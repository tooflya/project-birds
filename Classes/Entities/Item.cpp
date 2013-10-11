#ifndef CONST_ITEM
#define CONST_ITEM

#include "Item.h"

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

Item::Item(ButtonReceiver* pSender) :
    Button("shop_item_icon@2x.png", 10, 6, Options::BUTTONS_ID_SHOP_ITEM, pSender)
    {

    }

Item* Item::create(ButtonReceiver* pSender)
{
    Item* item = new Item(pSender);
    item->autorelease();
    
    return item;
}

// ===========================================================
// Methods
// ===========================================================
    
void Item::onTouch(CCTouch* touch, CCEvent* event)
{
    Shop::CLICKED_ITEM_ID = this->getCurrentFrameIndex();

    Button::onTouch(touch, event);
}

// ===========================================================
// Override Methods
// ===========================================================

Item* Item::deepCopy()
{
    return new Item(this->mSender);
}

#endif