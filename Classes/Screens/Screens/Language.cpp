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
    CCSpriteBatchNode* spriteBatch = CCSpriteBatchNode::create("TextureAtlas2.pvr");
    CCSpriteBatchNode* spriteBatchLanguage = CCSpriteBatchNode::create("flag_sprite_big@2x.png");

    this->mBackground = new Entity("settings_bg@2x.png", spriteBatch);
    this->mBackgroundDecorations[0] = new Entity("bg_detail_stripe@2x.png", spriteBatch);
    this->mBackgroundDecorations[1] = new Entity("bg_detail_stripe@2x.png", spriteBatch);

    this->mBackButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, spriteBatch, Options::BUTTONS_ID_LANGUAGE_BACK, onTouchButtonsCallback);

    this->addChild(spriteBatch);
    this->addChild(spriteBatchLanguage);
    
    this->mLanguages[0] = new Button("flag_sprite_big@2x.png", 2, 5, spriteBatchLanguage, Options::BUTTONS_ID_LANGUAGE_L_EN, onTouchButtonsCallback);
    this->mLanguages[1] = new Button("flag_sprite_big@2x.png", 2, 5, spriteBatchLanguage, Options::BUTTONS_ID_LANGUAGE_L_RU, onTouchButtonsCallback);
    this->mLanguages[2] = new Button("flag_sprite_big@2x.png", 2, 5, spriteBatchLanguage, Options::BUTTONS_ID_LANGUAGE_L_DE, onTouchButtonsCallback);
    this->mLanguages[3] = new Button("flag_sprite_big@2x.png", 2, 5, spriteBatchLanguage, Options::BUTTONS_ID_LANGUAGE_L_ES, onTouchButtonsCallback);
    this->mLanguages[4] = new Button("flag_sprite_big@2x.png", 2, 5, spriteBatchLanguage, Options::BUTTONS_ID_LANGUAGE_L_FR, onTouchButtonsCallback);
    this->mLanguages[5] = new Button("flag_sprite_big@2x.png", 2, 5, spriteBatchLanguage, Options::BUTTONS_ID_LANGUAGE_L_NL, onTouchButtonsCallback);
    this->mLanguages[6] = new Button("flag_sprite_big@2x.png", 2, 5, spriteBatchLanguage, Options::BUTTONS_ID_LANGUAGE_L_IT, onTouchButtonsCallback);
    this->mLanguages[7] = new Button("flag_sprite_big@2x.png", 2, 5, spriteBatchLanguage, Options::BUTTONS_ID_LANGUAGE_L_JP, onTouchButtonsCallback);
    this->mLanguages[8] = new Button("flag_sprite_big@2x.png", 2, 5, spriteBatchLanguage, Options::BUTTONS_ID_LANGUAGE_L_KR, onTouchButtonsCallback);
    this->mLanguages[9] = new Button("flag_sprite_big@2x.png", 2, 5, spriteBatchLanguage, Options::BUTTONS_ID_LANGUAGE_L_CN, onTouchButtonsCallback);
    
    this->mLanguageIndicator = new Entity("settings_lang_check@2x.png", this);

    this->mNotAvailableBackgrounds = new EntityManager(8, new Entity("flag_not_avaliable_bg@2x.png"), this);
    
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
    
    this->mLanguageIndicator->create();
    
    this->mBackgroundDecorations[0]->create()->setCenterPosition(Utils::coord(192), Options::CAMERA_HEIGHT - Utils::coord(103));
    this->mBackgroundDecorations[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(192), Utils::coord(103));
    
    this->mBackgroundDecorations[1]->setScale(-1);

    for(int i = 2; i < 10; i++)
    {
        this->mNotAvailableBackgrounds->create()->setCenterPosition(this->mLanguages[i]->getCenterX(), this->mLanguages[i]->getCenterY() - this->mLanguages[i]->getHeight() / 2 + Utils::coord(50));

        Entity* el = static_cast<Entity*>(this->mNotAvailableBackgrounds->objectAtIndex(i - 2));

        Text* text = new Text(Options::TEXT_LANGUAGE_NOT_AVAILABLE,  el);
        text->setColor(ccc3(0.0, 0.0, 0.0));
        text->disableShadow();
        text->setCenterPosition(el->getWidth() / 2, el->getHeight() / 2 + Utils::coord(3));
    }
    
    m_Instance = this;
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

void Language::onEnter()
{
    Screen::onEnter();
    
    this->mLanguageIndicator->setCenterPosition(this->mLanguages[Options::CURRENT_LANGUAGE]->getCenterX() + this->mLanguages[Options::CURRENT_LANGUAGE]->getWidth() / 2 - Utils::coord(32), this->mLanguages[Options::CURRENT_LANGUAGE]->getCenterY() - this->mLanguages[Options::CURRENT_LANGUAGE]->getHeight() / 2 + Utils::coord(64));
}

void Language::onExit()
{
    Screen::onExit();
}

#endif