#ifndef CONST_MAPDESCRIPTION
#define CONST_MAPDESCRIPTION

#include "MapDescription.h"

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

MapDescription::~MapDescription()
{
    CC_SAFE_RELEASE(this->mList);
}

MapDescription::MapDescription(Screen* pScreen) :
    Popup(pScreen),
	mCloseButton(0),
	mListBorders(),
	mList(0)
    {
        this->mCloseButton = Button::create("popup_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        
        this->mListBorders[0] = Entity::create("about_scroll_border_small@2x.png", this->mSpriteBatch);
        this->mListBorders[1] = Entity::create("about_scroll_border_small@2x.png", this->mSpriteBatch);
        
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(460));
        this->mCloseButton->setText(Options::TEXT_MAPDESCRIPTION_CONTINUE);
        
        this->mListBorders[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(325));
        this->mListBorders[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(325));
        
        this->mListBorders[0]->setScaleY(1);
        this->mListBorders[1]->setScaleY(-1);
        
        this->mList = MapDescriptionList::create(this);
        
        this->mSquare->setZOrder(1001);
    }

MapDescription* MapDescription::create(Screen* pScreen)
{
    MapDescription* popup = new MapDescription(pScreen);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void MapDescription::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                this->hide();
                
            break;
        }
        break;
            
        case Options::BUTTONS_ACTION_ONBEGIN:
        break;
            
        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

void MapDescription::show()
{
    Popup::show();
    
    this->setZOrder(1002);
}

void MapDescription::onShow()
{
    Popup::onShow();
}

void MapDescription::onHide()
{
    static_cast<Menu*>(this->mParent)->mMapPopup->hide();
    
    Popup::onHide();
}

// ===========================================================
// Override Methods
// ===========================================================

#endif