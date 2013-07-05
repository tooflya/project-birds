#ifndef CONST_MENU
#define CONST_MENU

#include "Menu.h"

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

Menu::Menu()
{
    this->mBackgroundDecoration = new Entity("main_menu_bg_back@2x.png", this);
    this->mBackground = new Entity("main_menu_bg@2x.png", this);
    this->mPlayDecoration = new Entity("main_menu_btn_bg_play@2x.png", this);
    this->mPlayButton = new Entity("main_menu_btn_play@2x.png", this);
    
    this->mBackgroundDecoration->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50));
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mPlayDecoration->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(40), Options::CAMERA_CENTER_Y - Utils::coord(40));
    this->mPlayButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(40), Options::CAMERA_CENTER_Y - Utils::coord(40));
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Virtual Methods
// ===========================================================

#endif