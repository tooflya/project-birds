#ifndef CONST_GETLIVES
#define CONST_GETLIVES

#include "GetLives.h"

#include "Shop.h"
#include "Mode.h"

#include "Loader.h"
#include "Game.h"

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

GetLives::~GetLives()
{
    CC_SAFE_RELEASE(this->mLights);
}

GetLives::GetLives(CCNode* pParent, bool pFirst) :
    Popup(pParent, pFirst),
	mPurchaseId(0),
    mExpireTimeText(0),
	mGetCoinsButtons(),
	mLights(0)
    {
        SpriteBatch* spriteBatch3 = SpriteBatch::create("TextureAtlas3");
        this->addChild(spriteBatch3);

        SpriteBatch* spriteBatch11 = 0;

        if(!pFirst)
        {
            spriteBatch11 = SpriteBatch::create("TextureAtlas9");
            this->addChild(spriteBatch11, -1);
        }
        
        this->mLights = EntityManager::create(2, Entity::create("get_coins_light@2x.png"), pFirst ? this->mSpriteBatch2 : spriteBatch11, -1);
        
        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        this->mIllustration = Entity::create("popup_glife_pic@2x.png", spriteBatch3);
        
		EntityStructure structure1 = {"popup_glife_btn@2x.png", 1, 1, 0, 0, 305, 327};

        this->mGetCoinsButtons[0] = Button::create(structure1, spriteBatch3, Options::BUTTONS_ID_GETCOINS_1, this);
        
        for(int i = 0; i < 2; i++)
        {
            this->mLights->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - Utils::coord(340));
            ((Entity*) this->mLights->objectAtIndex(i))->setScale(3.0);
            ((Entity*) this->mLights->objectAtIndex(i))->setOpacity(0.0);
        }
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        
		Textes textes1 = { "", Options::FONT, 48, -1 };
        Text* text1 = Text::create(Options::TEXT_GETLIVES_STRING_1, this);
        this->mExpireTimeText = Text::create(textes1, this);
        
        text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(220));
        this->mExpireTimeText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(260));
        this->mExpireTimeText->setColor(ccc3(28, 84, 179));
        
        this->mGetCoinsButtons[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(430));
        
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(190));

        this->mPurchaseId = -1;
    }

GetLives* GetLives::create(CCNode* pParent, bool pFirst)
{
    GetLives* popup = new GetLives(pParent, pFirst);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void GetLives::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                this->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_1:

                this->mPurchaseId = 4;

                this->hide();
                
            break;
            case Options::BUTTONS_ID_GETCOINS_2:

                this->mPurchaseId = 5;
                
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

// ===========================================================
// Override Methods
// ===========================================================

void GetLives::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);
    
    for(int i = 0; i < 2; i++)
    {
        Entity* light = ((Entity*) this->mLights->objectAtIndex(i));
        
        light->setRotation(light->getRotation() + ((i == 0) ? Utils::randomf(0.0, 0.1) : Utils::randomf(-0.1, 0.0)));
    }
    
    if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) <= 0)
    {
        long time = (AppDelegate::getLiveNearestReleaseTime(0) + (30 * 60 * 1000) - Utils::millisecondNow());
        
        int minutes = floor((time / 1000) / 60);
        long seconds = (time / 1000) - (minutes * 60);
        
        char text[256];
        
        sprintf(text, "%d:%lu", minutes, seconds);
        
        if(minutes < 10)
        {
            sprintf(text, "0%d:%lu", minutes, seconds);
        }
        if(seconds < 10)
        {
            sprintf(text, "%d:0%lu", minutes, seconds);
        }
        if(minutes < 10 && seconds < 10)
        {
            sprintf(text, "0%d:0%lu", minutes, seconds);
        }
        
        if(minutes <= 0 && seconds <= 0)
        {
            this->mExpireTimeText->setString(ccsf("%d", AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES)));
        }
        else
        {
            this->mExpireTimeText->setString(text);
        }
    }
    else
    {
        this->mExpireTimeText->setString(ccsf("%d", AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES)));
    }
}

void GetLives::onShow()
{
    Popup::onShow();

    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(1.0, 255.0));
    }
}

void GetLives::onHide()
{
    Popup::onHide();
    
    switch(this->mPurchaseId)
    {
        case 4:
        case 5:
        {
        Shop* shop = dynamic_cast<Shop*>(this->mParent);
        
        Shop::PURCHASE_ID = this->mPurchaseId;
            
        if(shop != 0)
        {
            shop->mPaymentProceed->show();
        }
        else
        {
            Mode* mode = dynamic_cast<Mode*>(this->mParent);
            
            if(mode != 0)
            {
                Shop::ACTION = 3;
                
                #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
				AppDelegate::screens->set(Shop::create());
                #else
				AppDelegate::screens->set(Screen::SCREEN_SHOP);
                #endif
            }
            else
            {
                Game* game = dynamic_cast<Game*>(this->mParent);
                
                if(game != 0)
                {
                    Shop::ACTION = 5;
					Loader::ACTION = 5;
                    
                    #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
                    AppDelegate::screens->set(Loader::create());
                    #else
                    AppDelegate::screens->set(Screen::SCREEN_LOADER);
                    #endif
                }
                else
                {
					Shop::ACTION = 4;
                    
                    #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
                    AppDelegate::screens->set(Shop::create());
                    #else
                    AppDelegate::screens->set(Screen::SCREEN_SHOP);
                    #endif
                }
            }
        }
        }
        break;
        case -1:
        {
            if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) > 0) break;
            
            Game* game = dynamic_cast<Game*>(this->mParent);
            
            if(game != 0)
            {
                Shop::ACTION = 11;
				Loader::ACTION = 5;

                #if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
				AppDelegate::screens->set(Loader::create());
                #else
				AppDelegate::screens->set(Screen::SCREEN_LOADER);
                #endif
            }
        }
        break;
    }
    
    this->mPurchaseId = -1;
}

void GetLives::show()
{
    Popup::show();
    
    Game* game = dynamic_cast<Game*>(this->mParent);
    
    if(game != 0)
    {
        game->pause();
    }
    
    if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) > 0)
    {
        this->mExpireTimeText->setString(ccsf("%d", AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES)));
    }
    /*else
    {
        this->mExpireTimeText->setString(ccsf("%d", AppDelegate::getLiveNearestReleaseTime(0)));
    }*/
}

void GetLives::hide()
{
    Popup::hide();
    
    for(int i = 0; i < 2; i++)
    {
        ((Entity*) this->mLights->objectAtIndex(i))->stopAllActions();
        ((Entity*) this->mLights->objectAtIndex(i))->runAction(CCFadeTo::create(0.3, 0.0));
    }
    
    Game* game = dynamic_cast<Game*>(this->mParent);
    
    if(game != 0)
    {
        game->pause();
    }
}

#endif