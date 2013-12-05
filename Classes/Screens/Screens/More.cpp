#ifndef CONST_MORE
#define CONST_MORE

#include "More.h"

#include "Settings.h"

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

More::More() :
	mBackground(0),
	mBackButton(0)
	{
		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas2");

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};

		this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
		this->mBackButton = Button::create(structure1, spriteBatch, Options::BUTTONS_ID_MORE_BACK, this);

		this->addChild(spriteBatch);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

		this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));

		if (AppDelegate::isGetWindeScreen())
		{
			this->mBackground->setScale(MAX(Options::CAMERA_HEIGHT / Options::designResolutionSize.height, Options::designResolutionSize.height / Options::CAMERA_HEIGHT));
		}
        
        AppDelegate::clearCache();
	}

More* More::create()
{
    More* screen = new More();
	screen->autorelease();

	#if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
	screen->retain();
	#endif
    
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

                    this->keyBackClicked(false);

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

void More::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);

	#if CC_PRELOAD_LEVEL > CC_PRELOAD_NOTHING
	AppDelegate::screens->set(Screen::SCREEN_SETTINGS);
	#else
	AppDelegate::screens->set(Settings::create());
	#endif
}

#endif