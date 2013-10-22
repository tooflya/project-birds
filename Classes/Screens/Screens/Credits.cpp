#ifndef CONST_CREDITS
#define CONST_CREDITS

#include "Credits.h"

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

Credits::~Credits()
{
    CC_SAFE_RELEASE(this->mList);
}

Credits::Credits() :
	mBackground(0),
	mBackButton(0),
	mListBorders(),
	mList(0)
	{
		SpriteBatch* spriteBatch = SpriteBatch::create("TextureAtlas2");

		EntityStructure structure1 = {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162};

		this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch);
		this->mBackButton = Button::create(structure1, spriteBatch, Options::BUTTONS_ID_CREDITS_BACK, this);
    
		this->mListBorders[0] = Entity::create("about_scroll_border@2x.png", spriteBatch);
		this->mListBorders[1] = Entity::create("about_scroll_border@2x.png", spriteBatch);

		this->addChild(spriteBatch);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
		this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
    
		this->mListBorders[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(500));
		this->mListBorders[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(400));
    
		this->mListBorders[0]->setScaleY(1);
		this->mListBorders[1]->setScaleY(-1);
    
		this->mList = CreditsList::create(this);
	}

Credits* Credits::create()
{
    Credits* screen = new Credits();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Credits::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_CREDITS_BACK:

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

void Credits::onEnter()
{
    Screen::onEnter();
    
    this->mList->setPosition(ccp(0, 0));
    this->mList->runAction(CCMoveTo::create(10.0, ccp(this->mList->getPosition().x, this->mList->getPosition().y + Utils::coord(800))));
}

void Credits::onExit()
{
    Screen::onExit();
}

#endif