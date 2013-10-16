#ifndef CONST_PROGRESS
#define CONST_PROGRESS

#include "Progress.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Progress* Progress::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Progress::~Progress()
{
    CC_SAFE_RELEASE_NULL(this->mResetPopup);
}

Progress::Progress()
{
    SpriteBatch* spriteBatch1 = SpriteBatch::create("TextureAtlas2");
    SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas2");
    
    spriteBatch1->setBlendFunc((ccBlendFunc){GL_ONE, GL_ZERO});
    spriteBatch2->setBlendFunc((ccBlendFunc){GL_ONE, GL_ONE_MINUS_SRC_ALPHA});
    
    this->addChild(spriteBatch1);
    this->addChild(spriteBatch2);

    this->mBackground = Entity::create("settings_bg@2x.png", spriteBatch1);
    this->mBackButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 0, 162, 162}, spriteBatch2, Options::BUTTONS_ID_PROGRESS_BACK, this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mBackButton->create()->setCenterPosition(Utils::coord(100), Utils::coord(100));
    
    this->mResetButton = Button::create("settings_btn_big@2x.png", 1, 1, spriteBatch2, Options::BUTTONS_ID_PROGRESS_RESET, this);
    
    this->mResetButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(200));
    this->mResetButton->setText(Options::TEXT_PROGRESS_RESET);
    
    Text* text1 = Text::create(Options::TEXT_PROGRESS_STRING_1, CCSize(Utils::coord(700), 0), this);
    
    text1->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));
    
    this->mResetPopup = ResetProgress::create(this);
    
    m_Instance = this;
}

Progress* Progress::create()
{
    Progress* screen = new Progress();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Progress::onTouchButtonsCallback(const int pAction, const int pID)
{
    Progress* pSender = static_cast<Progress*>(Progress::m_Instance);
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_PROGRESS_BACK:
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);
                
            break;
            case Options::BUTTONS_ID_PROGRESS_RESET:
                
                pSender->mResetPopup->show();
                
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