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

More::More()
{
    SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas2");

    this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
    this->mBackButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, spriteBatch, Options::BUTTONS_ID_MORE_BACK, this);

    this->addChild(spriteBatch);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

    this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
}

More* More::create()
{
    More* screen = new More();
    screen->autorelease();
    screen->retain();
    
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