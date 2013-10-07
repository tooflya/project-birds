#ifndef CONST_SHOP_H
#define CONST_SHOP_H

#include "Screen.h"

#include "BuyItem.h"
#include "GetCoins.h"
#include "BoughtItem.h"
#include "PaymentProceed.h"

#include "Item.h"
#include "AnimatedCoin.h"

#include "AppDelegate.h"

class TouchLayer;

class Shop : public Screen
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static Shop* m_Instance;

        // ===========================================================
        // Fields
        // ===========================================================

        int mCoins;
    
        Entity* mGamePanel;
        Entity* mBackgroundDecorations[2];
        Entity* mBackground;
        Entity* mIcons[3];
        Entity* mTextBackgrounds[3];
    
        Text* mTextText[3];
    
        Button* mTextPluses[3];
    

        EntityManager* mPurchaseCoins;
        
        Button* mBackButton;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Shop();

        // ===========================================================
        // Methods
        // ===========================================================

        // ===========================================================
        // Override Methods
        // ===========================================================

    private:
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

        // ===========================================================
        // Methods
        // ===========================================================

        static void onTouchButtonsCallback(const int pAction, const int pID);
        
        // ===========================================================
        // Override Methods
        // ===========================================================

    public:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static int CLICKED_ITEM_ID;
        static int ITEMS_COUNT[3];
        static int ACTION;
        static int PURCHASE_ID;

        // ===========================================================
        // Fields
        // ===========================================================
    
        Entity* mWheels[9];
        Entity* mItems[60];
        Entity* mShelfs[15];
        
        TouchLayer* mLayersA[4];
    
        Popup* mBuyItemPopup;
        Popup* mGetCoinsPopup;
        Popup* mPaymentProceed;
        
        BoughtItem* mBoughtItem;

        Entity* mWeaponChecker;

        float mAnimationOnItemBoughtTime;
        float mAnimationOnItemBoughtTimeElapsed;

        float mIsAnimationPurchaseTime;
        float mIsAnimationPurchaseTimeElapsed;

        float mIsAnimationPurchaseTimeEpisode;
        float mIsAnimationPurchaseTimeEpisodeElapsed;

        bool mIsAnimationOnItemBoughtRunning;
        bool mIsAnimationPurchaseRunning;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Shop* create();
    
        ~Shop();

        // ===========================================================
        // Methods
        // ===========================================================

        void onItemBought(int pItemId);
        void onPurchase(bool mProceed);
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);

        void onEnter();
        void onExit();
};

#endif