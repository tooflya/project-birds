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

ModeHelpList::~ModeHelpList()
{
    this->removeAllChildrenWithCleanup(true);
}

ModeHelpList::ModeHelpList(CCNode* pParent) :
    List(Utils::coord(512), Utils::coord(640), Utils::coord(512), Utils::coord(300), ((Entity*) pParent)->getWidth() / 2, ((Entity*) pParent)->getHeight() / 2 + Utils::coord(0), "about_scroll_fill_small@2x.png", pParent)
    {
        this->setListType(List::TYPE_VERTICAL);
        this->setParentType(List::PARENT_TYPE_POPUP);

        this->mText[0] = Text::create(Options::TEXT_MODEHELP_HELP[0], this);
        this->mText[1] = Text::create(Options::TEXT_MODEHELP_HELP[1], CCSize(Utils::coord(450), 0), this);

        this->mText[0]->setCenterPosition((static_cast<Entity*>(pParent))->getWidth() / 2, Options::CAMERA_CENTER_Y + Utils::coord(250));
        this->mText[1]->setCenterPosition((static_cast<Entity*>(pParent))->getWidth() / 2, Options::CAMERA_CENTER_Y - this->mText[1]->getContentSize().height / 2 + Utils::coord(180));

        this->mText[0]->setColor(ccc3(167.0, 65.0, 7.0));
        this->mText[1]->setColor(ccc3(167.0, 65.0, 7.0));
    }

ModeHelpList* ModeHelpList::create(CCNode* pParent)
{
    ModeHelpList* list = new ModeHelpList(pParent);
    list->autorelease();
    list->retain();
    
    return list;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void ModeHelpList::onEnter()
{
    List::onEnter();
    
    this->mText[1]->setCenterPosition((static_cast<Entity*>(this->mParent))->getWidth() / 2, Options::CAMERA_CENTER_Y - this->mText[1]->getContentSize().height / 2 + Utils::coord(180));
    
    if(Options::CURRENT_LANGUAGE == 1)
    {
        this->mMaxHeight = Utils::coord(300);
    }
    else
    {
        this->mMaxHeight = Utils::coord(150);
    }
}

#endif