#ifndef CONST_CREDITSLIST
#define CONST_CREDITSLIST

#include "CreditsList.h"

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

CreditsList::CreditsList(CCNode* pParent) :
    List(Utils::coord(600), Utils::coord(890), Utils::coord(750), Utils::coord(7500), Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(50), "about_scroll_fill@2x.png", pParent)
    {
        this->setListType(List::TYPE_VERTICAL);

        this->mText[0] = new Text(Options::TEXT_CREDITS_STRING_1, this);
        this->mText[1] = new Text(Options::TEXT_CREDITS_STRING_2, this);
        this->mText[2] = new Text(Options::TEXT_CREDITS_STRING_3, this);
        this->mText[3] = new Text(Options::TEXT_CREDITS_STRING_4, this);
        this->mText[4] = new Text(Options::TEXT_CREDITS_STRING_5, this);
        this->mText[5] = new Text(Options::TEXT_CREDITS_STRING_6, this);
        this->mText[6] = new Text(Options::TEXT_CREDITS_STRING_7, this);
        this->mText[7] = new Text(Options::TEXT_CREDITS_STRING_8, this);
        this->mText[8] = new Text(Options::TEXT_CREDITS_STRING_9, this);
        this->mText[9] = new Text(Options::TEXT_CREDITS_STRING_10, this);
        this->mText[10] = new Text(Options::TEXT_CREDITS_STRING_11, this);
        this->mText[11] = new Text(Options::TEXT_CREDITS_STRING_12, this);
        this->mText[12] = new Text(Options::TEXT_CREDITS_STRING_13, this);
        
        this->mText[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(450) - Utils::coord(500));
        this->mText[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(350) - Utils::coord(500));
        this->mText[2]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300) - Utils::coord(500));
        this->mText[3]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200) - Utils::coord(500));
        this->mText[4]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100) - Utils::coord(500));
        this->mText[5]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(50) - Utils::coord(500));
        this->mText[6]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50) - Utils::coord(500));
        this->mText[7]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(100) - Utils::coord(500));
        this->mText[8]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(200) - Utils::coord(500));
        this->mText[9]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(250) - Utils::coord(500));
        this->mText[10]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(300) - Utils::coord(500));
        this->mText[11]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(400) - Utils::coord(500));
        this->mText[12]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(450) - Utils::coord(500));
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

#endif