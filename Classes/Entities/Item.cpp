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

Item::Item(void (*pOnTouchCallback)(int, int)) :
    Button("shop_item_icon@2x.png", 10, 10, Options::BUTTONS_ID_SHOP_ITEM, pOnTouchCallback)
    {

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
    return new Item(this->mOnTouchCallback);
}

#endif