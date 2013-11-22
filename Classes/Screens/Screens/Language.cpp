#ifndef CONST_LANGUAGE
#define CONST_LANGUAGE

#include "Language.h"

#include "Settings.h"

// ===========================================================
// Inner Classes
// ===========================================================

class Dark : public CCNodeRGBA
{
    public:
    Dark()
    {
        this->setColor(ccc3(0, 0, 0));
        this->setOpacity(50);
    }
    
    static Dark* create()
    {
        Dark* background = new Dark();
        background->autorelease();
        
        return background;
    }

    void draw()
    {
        if(this->getOpacity() <= 0) return;

        #if CC_TARGET_PLATFORM != CC_PLATFORM_WINRT
        glLineWidth(1);
        #endif
		CCPoint filledVertices[] = { ccp(0,0), ccp(0,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH, 0)};
        ccDrawSolidPoly(filledVertices, 4, ccc4f(this->getColor().r, this->getColor().g, this->getColor().b, this->getOpacity() / 255.0) );
    }
};

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Language::Language() :
	mBackground(0),
	mBackButton(0),
	mLanguages(),
	mLanguageIndicator(0),
	mBackgroundDecorations(),
	mNotAvailableBackgrounds(),
	mTextes()
	{
		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas2");
		SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas4");

		this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
		this->mBackgroundDecorations[0] = Entity::create("bg_detail_stripe@2x.png", spriteBatch);
		this->mBackgroundDecorations[1] = Entity::create("bg_detail_stripe@2x.png", spriteBatch);

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};
		this->mBackButton = Button::create(structure1, spriteBatch, Options::BUTTONS_ID_LANGUAGE_BACK, this);

		this->addChild(spriteBatch);
		this->addChild(spriteBatch2);
    
		this->mLanguages[0] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_EN, this);
		this->mLanguages[1] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_RU, this);
		this->mLanguages[2] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_DE, this);
		this->mLanguages[3] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_ES, this);
		this->mLanguages[4] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_FR, this);
		this->mLanguages[5] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_NL, this);
		this->mLanguages[6] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_IT, this);
		this->mLanguages[7] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_JP, this);
		this->mLanguages[8] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_KR, this);
		this->mLanguages[9] = Button::create("flag_sprite_big@2x.png", 2, 5, spriteBatch2, Options::BUTTONS_ID_LANGUAGE_L_CN, this);
    
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
        
        if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPAD_RETINA)
        {
            this->mBackground->setScale(1.185);
        }
        
        AppDelegate::clearCache();
	}

Language* Language::create()
{
    Language* screen = new Language();
    screen->autorelease();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Language::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_LANGUAGE_BACK:
                
                this->keyBackClicked(false);
                
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
    Screen::onEnter();
}

void Language::onExit()
{
    Screen::onExit();
}

void Language::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    AppDelegate::screens->set(Settings::create());
}

#endif