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

        this->mIcon = new Entity("shop_item_icon@2x.png", 10, 10, this);
        this->mDescriptionText = new Text((Textes) {"", "Comic Sans MS", 24, -1}, ccp(Utils::coord(450), 0), this);

        this->mStars = new BatchEntityManager(2, new Entity("popup_item_rate_stars@2x.png", 1, 2), this);
        this->mStars->create()->setCenterPosition(this->mParent->getWidth() / 2 - Utils::coord(5) + static_cast<Entity*>(this->mStars->objectAtIndex(0))->getWidth() / 2, Options::CAMERA_CENTER_Y - Utils::coord(70));
        this->mStars->create()->setCenterPosition(this->mParent->getWidth() / 2 - Utils::coord(5) + static_cast<Entity*>(this->mStars->objectAtIndex(1))->getWidth() / 2, Options::CAMERA_CENTER_Y - Utils::coord(70));
        static_cast<Entity*>(this->mStars->objectAtIndex(0))->setCurrentFrameIndex(1);

        this->mCoinsIcon = new Entity("coins@2x.png", 5, 4, this);
        this->mCoinsIcon->create()->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(15), Options::CAMERA_CENTER_Y + Utils::coord(50));
        this->mCoinsIcon->setRotation(-45);
        this->mCoinsIcon->setScale(0.75);
        this->mCoinsIcon->animate(0.05);

        this->mPropertiesIcon = new Entity("icon_properties@2x.png", 1, 2, this);
        this->mPropertiesIcon->create()->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(15), Options::CAMERA_CENTER_Y - Utils::coord(8));

        this->mPriceText = new Text((Textes) {"0", "Comic Sans MS", 32, 0}, this);
        this->mPriceText->setColor(ccc3(255.0, 130.0, 0.0));

        this->mBoughtText = new Text(Options::TEXT_ITEM_ALREADY_BOUGHT, this);
        this->mBoughtText->setColor(ccc3(255.0, 130.0, 0.0));

        this->mPowerText = new Text((Textes) {"112", "Comic Sans MS", 32, 0}, this);
        this->mPowerText->setColor(ccc3(255.0, 130.0, 0.0));

        this->mNameText = new Text((Textes) {"", "Comic Sans MS", 40, 0}, this);
        this->mNameText->setCenterPosition(this->mParent->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(140));
        this->mNameText->setColor(ccc3(170.0, 82.0, 5.0));
        
        this->mDescriptionText->setColor(ccc3(204.0, 102.0, 51.0));

        this->mIcon->create()->setCenterPosition(this->mParent->getWidth() / 2 - Utils::coord(120), Options::CAMERA_CENTER_Y);
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
    this->mDescriptionText->setCenterPosition(this->mParent->getWidth() / 2, Options::CAMERA_CENTER_Y - Utils::coord(115) - this->mDescriptionText->getHeight() / 2);

    this->mNameText->setString(Options::TEXT_SHOP_ITEMS[Shop::CLICKED_ITEM_ID].string);

    this->mPriceText->setString(Utils::intToString(Options::SHOP_ITEMS_PRICES[Shop::CLICKED_ITEM_ID]).c_str());
    this->mPriceText->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(40) + this->mPriceText->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(50));

    this->mBoughtText->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(0) + this->mBoughtText->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(50));

    this->mPowerText->setString(Options::SHOP_ITEMS_PROPERTIES[Shop::CLICKED_ITEM_ID]);
    this->mPowerText->setCenterPosition(this->mParent->getWidth() / 2 + Utils::coord(40) + this->mPowerText->getWidth() / 2, Options::CAMERA_CENTER_Y - Utils::coord(10));

    Entity* pRating = static_cast<Entity*>(this->mStars->objectAtIndex(1));
    CCTexture2D* pTexture = pRating->getTexture();
    CCRect textureRectanle = CCRect(0, 0, pTexture->getContentSize().width / 100.0 * Options::SHOP_ITEMS_RATING_FACTOR[Shop::CLICKED_ITEM_ID], pTexture->getContentSize().height / 2);
    pRating->setTextureRect(textureRectanle);
    pRating->setCenterPosition(this->mParent->getWidth() / 2 - Utils::coord(5) + pRating->getWidth() / 2, Options::CAMERA_CENTER_Y - Utils::coord(70));

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