#ifndef CONST_MORE
#define CONST_MORE

#include "More.h"

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

More::~More()
{
    this->removeAllChildrenWithCleanup(true);
    
    delete this->mSpriteBatch;
    delete this->mBackground;
    delete this->mBackButton;
}

More::More() :
    mSpriteBatch(NULL),
	mBackground(NULL),
	mBackButton(NULL)
	{
		this->mSpriteBatch = SpriteBatch::create("TextureAtlas2");

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};

		this->mBackground = Entity::create("settings_bg@2x.png", this->mSpriteBatch);
		this->mBackButton = Button::create(structure1, this->mSpriteBatch, Options::BUTTONS_ID_MORE_BACK, this);

		this->addChild(this->mSpriteBatch);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

		this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
	}

More* More::create()
{
    More* screen = new More();
    /*screen->autorelease();
    screen->retain();*/
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void More::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MORE_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);

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

void More::onEnter()
{
    Screen::onEnter();
}

void More::onExit()
{
    Screen::onExit();
}

#endif