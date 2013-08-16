#ifndef CONST_BUYITEMLIST
#define CONST_BUYITEMLIST

#include "BuyItemList.h"

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

BuyItemList::BuyItemList(CCNode* pParent) :
    List(Utils::coord(512), Utils::coord(640), Utils::coord(512), Utils::coord(/** 750 **/0), ((Entity*) pParent)->getWidth() / 2, ((Entity*) pParent)->getHeight() / 2 + Utils::coord(0), "about_scroll_fill_small@2x.png", pParent)
    {
        this->setListType(List::TYPE_VERTICAL);
        this->setParentType(List::PARENT_TYPE_POPUP);

        this->mSpriteBatch = CCSpriteBatchNode::create("TextureAtlas5.pvr.ccz");

        this->addChild(this->mSpriteBatch);

        this->mIcon = Entity::create("shop_item_icon@2x.png", 10, 6, this->mSpriteBatch);
        this->mDescriptionText = new Text((Textes) {"", "Comic Sans MS", 24, -1}, ccp(Utils::coord(450), 0), this);

        this->mStars[0] = Entity::create("popup_item_rate_stars@2x.png", 1, 2, this->mSpriteBatch);
        this->mStars[1] = Entity::create("popup_item_rate_stars@2x.png", 1, 2, this->mSpriteBatch);
        
        this->mStars[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(5) + this->mStars[0]->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(50));
        this->mStars[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(5) + this->mStars[0]->getWidth() / 2, Options::CAMERA_CENTER_Y -+Utils::coord(50));
        this->mStars[0]->setCurrentFrameIndex(1);

        this->mCoinsIcon = Entity::create("coins@2x.png", 5, 4, this->mSpriteBatch);
        this->mCoinsIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(15), Options::CAMERA_CENTER_Y + Utils::coord(170));
        this->mCoinsIcon->setRotation(-45);
        this->mCoinsIcon->setScale(0.75);
        this->mCoinsIcon->animate(0.05);

        this->mPropertiesIcon = Entity::create("icon_properties@2x.png", 1, 2, this->mSpriteBatch);
        this->mPropertiesIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(15), Options::CAMERA_CENTER_Y + Utils::coord(112));

        this->mPriceText = new Text((Textes) {"0", "Comic Sans MS", 32, 0}, this);
        this->mPriceText->setColor(ccc3(255.0, 130.0, 0.0));

        this->mBoughtText = new Text(Options::TEXT_ITEM_ALREADY_BOUGHT, this);
        this->mBoughtText->setColor(ccc3(255.0, 130.0, 0.0));

        this->mPowerText = new Text((Textes) {"112", "Comic Sans MS", 32, 0}, this);
        this->mPowerText->setColor(ccc3(255.0, 130.0, 0.0));

        this->mNameText = new Text((Textes) {"", "Comic Sans MS", 40, 0}, this);
        this->mNameText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(260));
        this->mNameText->setColor(ccc3(170.0, 82.0, 5.0));
        
        this->mDescriptionText->setColor(ccc3(204.0, 102.0, 51.0));

        this->mIcon->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(120), Options::CAMERA_CENTER_Y + Utils::coord(120));
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void BuyItemList::onEnter()
{
    List::onEnter();

    this->mIcon->setCurrentFrameIndex(Shop::CLICKED_ITEM_ID);

    this->mDescriptionText->setString(Options::TEXT_SHOP_ITEMS_DESCRIPTIONS[Shop::CLICKED_ITEM_ID].string);
    this->mDescriptionText->setCenterPosition(this->mParent->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(5) - this->mDescriptionText->getHeight() / 2);

    this->mNameText->setString(Options::TEXT_SHOP_ITEMS[Shop::CLICKED_ITEM_ID].string);

    this->mPriceText->setString(Utils::intToString(Options::SHOP_ITEMS_PRICES[Shop::CLICKED_ITEM_ID]).c_str());
    this->mPriceText->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(40) + this->mPriceText->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(170));

    this->mBoughtText->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(0) + this->mBoughtText->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(170));

    this->mPowerText->setString(Options::SHOP_ITEMS_PROPERTIES[Shop::CLICKED_ITEM_ID]);
    this->mPowerText->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(40) + this->mPowerText->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(110));

    this->mStars[1]->showPercentage(Options::SHOP_ITEMS_RATING_FACTOR[Shop::CLICKED_ITEM_ID]);
    this->mStars[1]->setCenterPosition(this->mParent->getWidth() / 2 - Utils::coord(5) + this->mStars[1]->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(50));

    if(Shop::CLICKED_ITEM_ID < Shop::ITEMS_COUNT[0])
    {
        this->mPropertiesIcon->setCurrentFrameIndex(1);
    }
    else
    {
        this->mPropertiesIcon->setCurrentFrameIndex(0);
    }

    if(AppDelegate::isItemBought(Shop::CLICKED_ITEM_ID))
    {
        this->mCoinsIcon->setVisible(false);
        this->mPriceText->setVisible(false);

        this->mBoughtText->setVisible(true);
    }
    else
    {
        this->mCoinsIcon->setVisible(true);
        this->mPriceText->setVisible(true);

        this->mBoughtText->setVisible(false);
    }
}

#endif