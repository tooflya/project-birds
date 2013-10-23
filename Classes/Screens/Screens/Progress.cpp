#ifndef CONST_PROGRESS
#define CONST_PROGRESS

#include "Progress.h"

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

Progress::~Progress()
{
    this->removeAllChildrenWithCleanup(true);
    
    delete this->text1;
    delete this->spriteBatch1;
    delete this->spriteBatch2;
    delete this->mBackground;
    delete this->mBackButton;
    delete this->mResetButton;
    //delete this->mResetPopup;
}

Progress::Progress() :
    spriteBatch1(0),
    spriteBatch2(0),
	mBackground(0),
	mBackButton(0),
	mResetButton(0),
	mResetPopup(0),
    text1(0)
	{
		spriteBatch1 = SpriteBatch::create("TextureAtlas2");
		spriteBatch2 = SpriteBatch::create("TextureAtlas2");
    
		ccBlendFunc function1 = {GL_ONE, GL_ZERO};
		ccBlendFunc function2 = {GL_ONE, GL_ONE_MINUS_SRC_ALPHA};

		spriteBatch1->setBlendFunc(function1);
		spriteBatch2->setBlendFunc(function2);
    
		this->addChild(spriteBatch1);
		this->addChild(spriteBatch2);

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};

		this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch1);
		this->mBackButton = Button::create(structure1, spriteBatch2, Options::BUTTONS_ID_PROGRESS_BACK, this);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
		this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
    
		this->mResetButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch2, Options::BUTTONS_ID_PROGRESS_RESET, this);
    
		this->mResetButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(200));
		this->mResetButton->setText(Options::TEXT_PROGRESS_RESET);
    
		text1 = Text::create(Options::TEXT_PROGRESS_STRING_1, CCSize(Utils::coord(700), 0), this);
    
		text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));
    
		//this->mResetPopup = ResetProgress::create(this);
	}

Progress* Progress::create()
{
    Progress* screen = new Progress();
    /*screen->autorelease();
    screen->retain();*/
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Progress::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_PROGRESS_BACK:
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
                
            break;
            case Options::BUTTONS_ID_PROGRESS_RESET:
                
                this->mResetPopup->show();
                
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

#endif