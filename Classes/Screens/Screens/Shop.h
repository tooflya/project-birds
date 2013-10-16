#ifndef CONST_SHOP_H
#define CONST_SHOP_H

#include "Screen.h"

#include "BuyItem.h"
#include "GetCoins.h"
#include "GetLives.h"
#include "GetKeys.h"
#include "BoughtItem.h"
#include "PaymentProceed.h"
#include "KeyParticle.h"
#include "LiveParticle.h"

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

        // ===========================================================
        // Fields
        // ===========================================================

        int mPanelItems[4];
    
        SpriteBatch* mSpriteBatch1;
        SpriteBatch* mSpriteBatch2;
    
        Entity* mGamePanel;
        Entity* mBackgroundDecorations[2];
        Entity* mBackground;
        Entity* mIcons[4];
        Entity* mTextBackgrounds[4];
    
        Text* mTextText[4];
    
        Button* mTextPluses[4];
    
        EntityManager* mPurchaseCoins;
        EntityManager* mPurchaseSilverCoins;
        EntityManager* mPurchaseLives;
        EntityManager* mPurchaseKeys;
    
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
        Popup* mGetLivesPopup;
        Popup* mGetKeysPopup;
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
    
        void visit();
        void draw();
    
        void onEnterTransitionDidFinish();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
};

#endif