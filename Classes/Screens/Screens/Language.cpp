#ifndef CONST_LANGUAGE
#define CONST_LANGUAGE

#include "Language.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Language* Language::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Language::Language()
{
    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas2.png");
    CCSpriteBatchNode* spriteBatch2 = CCSpriteBatchNode::create("TextureAtlas4.png");

    this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
    this->mBackgroundDecorations[0] = Entity::create("bg_detail_stripe@2x.png", spriteBatch);
    this->mBackgroundDecorations[1] = Entity::create("bg_detail_stripe@2x.png", spriteBatch);

    this->mBackButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, spriteBatch, Options::BUTTONS_ID_LANGUAGE_BACK, onTouchButtonsCallback);

    this->addChild(spriteBatch);
    this->addChild(spriteBatch2);
    
    this->mLanguages[0] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_EN, onTouchButtonsCallback);
    this->mLanguages[1] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_RU, onTouchButtonsCallback);
    this->mLanguages[2] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_DE, onTouchButtonsCallback);
    this->mLanguages[3] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_ES, onTouchButtonsCallback);
    this->mLanguages[4] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_FR, onTouchButtonsCallback);
    this->mLanguages[5] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_NL, onTouchButtonsCallback);
    this->mLanguages[6] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_IT, onTouchButtonsCallback);
    this->mLanguages[7] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_JP, onTouchButtonsCallback);
    this->mLanguages[8] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_KR, onTouchButtonsCallback);
    this->mLanguages[9] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_CN, onTouchButtonsCallback);
    
    this->mNotAvailableBackgrounds[0] = Entity::create("flag_not_avaliable_bg@2x.png", spriteBatch2);
    this->mNotAvailableBackgrounds[1] = Entity::create("flag_not_avaliable_bg@2x.png", spriteBatch2);
    this->mNotAvailableBackgrounds[2] = Entity::create("flag_not_avaliable_bg@2x.png", spriteBatch2);
    this->mNotAvailableBackgrounds[3] = Entity::create("flag_not_avaliable_bg@2x.png", spriteBatch2);
    this->mNotAvailableBackgrounds[4] = Entity::create("flag_not_avaliable_bg@2x.png", spriteBatch2);
    this->mNotAvailableBackgrounds[5] = Entity::create("flag_not_avaliable_bg@2x.png", spriteBatch2);
    this->mNotAvailableBackgrounds[6] = Entity::create("flag_not_avaliable_bg@2x.png", spriteBatch2);
    this->mNotAvailableBackgrounds[7] = Entity::create("flag_not_avaliable_bg@2x.png", spriteBatch2);
    
    this->mLanguageIndicator = Entity::create("settings_lang_check@2x.png", spriteBatch2);
    
    this->mLanguages[0]->setCurrentFrameIndex(0);
    this->mLanguages[1]->setCurrentFrameIndex(1);
    this->mLanguages[2]->setCurrentFrameIndex(2);
    this->mLanguages[3]->setCurrentFrameIndex(3);
    this->mLanguages[4]->setCurrentFrameIndex(4);
    this->mLanguages[5]->setCurrentFrameIndex(5);
    this->mLanguages[6]->setCurrentFrameIndex(6);
    this->mLanguages[7]->setCurrentFrameIndex(7);
    this->mLanguages[8]->setCurrentFrameIndex(8);
    this->mLanguages[9]->setCurrentFrameIndex(9);
    
    this->mLanguages[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(180), Options::CAMERA_CENTER_Y + Utils::coord(460));
    this->mLanguages[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(180), Options::CAMERA_CENTER_Y + Utils::coord(460));
    this->mLanguages[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(180), Options::CAMERA_CENTER_Y + Utils::coord(260));
    this->mLanguages[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(180), Options::CAMERA_CENTER_Y + Utils::coord(260));
    this->mLanguages[4]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(180), Options::CAMERA_CENTER_Y + Utils::coord(60));
    this->mLanguages[5]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(180), Options::CAMERA_CENTER_Y + Utils::coord(60));
    this->mLanguages[6]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(180), Options::CAMERA_CENTER_Y - Utils::coord(140));
    this->mLanguages[7]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(180), Options::CAMERA_CENTER_Y - Utils::coord(140));
    this->mLanguages[8]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(180), Options::CAMERA_CENTER_Y - Utils::coord(340));
    this->mLanguages[9]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(180), Options::CAMERA_CENTER_Y - Utils::coord(340));
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
    
    //this->mLanguageIndicator->setAnchorPoint(ccp(0.0, 0.0));
    this->mLanguageIndicator->create();
    
    this->mBackgroundDecorations[0]->create()->setCenterPosition(Utils::coord(192), Options::CAMERA_HEIGHT - Utils::coord(103));
    this->mBackgroundDecorations[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(192), Utils::coord(103));
    
    this->mBackgroundDecorations[1]->setScale(-1);

    for(int i = 2; i < 10; i++)
    {
        this->mNotAvailableBackgrounds[i - 2]->create()->setCenterPosition(this->mLanguages[i]->getCenterX(), this->mLanguages[i]->getCenterY() - this->mLanguages[i]->getHeight() / 2 + Utils::coord(50));

        this->mTextes[i - 2] = Text::create(Options::TEXT_LANGUAGE_NOT_AVAILABLE,  this);
        this->mTextes[i - 2]->setColor(ccc3(0.0, 0.0, 0.0));
        this->mTextes[i - 2]->disableShadow();
        this->mTextes[i - 2]->setCenterPosition(this->mNotAvailableBackgrounds[i - 2]->getCenterX(), this->mNotAvailableBackgrounds[i - 2]->getCenterY());
    }
    
    m_Instance = this;
}

Language* Language::create()
{
    Language* screen = new Language();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Language::onTouchButtonsCallback(const int pAction, const int pID)
{
    Language* pSender = static_cast<Language*>(Language::m_Instance);
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_LANGUAGE_BACK:
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_RU:
                
                Options::CURRENT_LANGUAGE = 1;
                
                Options::changeLanguage();
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_EN:
                
                Options::CURRENT_LANGUAGE = 0;

                Options::changeLanguage();
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_DE:

                // TODO: Change language;
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_ES:

                // TODO: Change language;
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_FR:

                // TODO: Change language;
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_NL:

                // TODO: Change language;
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_IT:

                // TODO: Change language;
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_JP:

                // TODO: Change language;
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_KR:

                // TODO: Change language;
                
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_CN:

                // TODO: Change language;
                
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

void Language::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);

    this->mLanguageIndicator->setScale(this->mLanguages[Options::CURRENT_LANGUAGE]->getScaleX());
    this->mLanguageIndicator->setCenterPosition(this->mLanguages[Options::CURRENT_LANGUAGE]->getCenterX() + this->mLanguages[Options::CURRENT_LANGUAGE]->getWidthScaled() / 2 - Utils::coord(32) * this->mLanguages[Options::CURRENT_LANGUAGE]->getScaleX(), this->mLanguages[Options::CURRENT_LANGUAGE]->getCenterY() - this->mLanguages[Options::CURRENT_LANGUAGE]->getHeightScaled() / 2 + Utils::coord(64) * this->mLanguages[Options::CURRENT_LANGUAGE]->getScaleY());

    for(int i = 0; i < 8; i++)
    {
        this->mNotAvailableBackgrounds[i]->setScale(this->mLanguages[i + 2]->getScaleX());
        this->mNotAvailableBackgrounds[i]->setCenterPosition(this->mLanguages[i + 2]->getCenterX(), this->mLanguages[i + 2]->getCenterY() - this->mLanguages[i + 2]->getHeightScaled() / 2 + Utils::coord(50) * this->mLanguages[i + 2]->getScaleY());
        
        this->mTextes[i]->setScale(this->mLanguages[i + 2]->getScaleX());
        this->mTextes[i]->setCenterPosition(this->mNotAvailableBackgrounds[i]->getCenterX(), this->mNotAvailableBackgrounds[i]->getCenterY());
    }
}

void Language::onEnter()
{
    Screen::onEnter();}

void Language::onExit()
{
    Screen::onExit();
}

#endif