#ifndef CONST_MODEHELPLIST
#define CONST_MODEHELPLIST

#include "ModeHelpList.h"

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

ModeHelpList::ModeHelpList(CCNode* pParent) :
    List(Utils::coord(512), Utils::coord(640), Utils::coord(512), Utils::coord(650), ((Entity*) pParent)->getWidth() / 2, ((Entity*) pParent)->getHeight() / 2 + Utils::coord(0), "about_scroll_fill_small@2x.png", pParent)
    {
        this->setListType(List::TYPE_VERTICAL);
        this->setParentType(List::PARENT_TYPE_POPUP);

        this->mText[0] = new Text(Options::TEXT_MODEHELP_HELP[0], this);
        this->mText[1] = new Text(Options::TEXT_MODEHELP_HELP[1], CCSize(Utils::coord(480), 2000), this);

        this->mText[0]->setCenterPosition(((Entity*) pParent)->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(100));
        this->mText[1]->setCenterPosition(((Entity*) pParent)->getWidth() / 2, Options::CAMERA_CENTER_Y - this->mText[1]->getContentSize().height / 2);
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

#endif