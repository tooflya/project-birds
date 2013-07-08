#ifndef CONST_END
#define CONST_END

#include "End.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

End* End::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

End::End(CCNode* pParent) :
Splash(pParent)
{
    this->mParts = new BatchEntityManager(2, new Entity("end_lvl_bg_sprite@2x.png", 2, 1), this);
    
    Entity* part;
    
    part = (Entity*) this->mParts->create();
    part->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT + part->getHeight() / 2);
    part->setCurrentFrameIndex(0);
    
    part = (Entity*) this->mParts->create();
    part->setCenterPosition(Options::CAMERA_CENTER_X, -part->getHeight() / 2);
    part->setCurrentFrameIndex(1);
    
    this->mBackground = new Entity("end_lvl_bg_popup@2x.png", this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackground->setVisible(false);
    
    this->mMenuButton = new Button("end_lvl_btn_sprite@2x.png", 3, 1, this->mBackground, Options::BUTTONS_ID_END_MENU, onTouchButtonsCallback);
    this->mRestartButton = new Button("end_lvl_btn_sprite@2x.png", 3, 1, this->mBackground, Options::BUTTONS_ID_END_RESTART, onTouchButtonsCallback);
    this->mContinueButton = new Button("end_lvl_btn_sprite@2x.png", 3, 1, this->mBackground, Options::BUTTONS_ID_END_CONTINUE, onTouchButtonsCallback);

    this->mContinueButton->create()->setCurrentFrameIndex(2);
    this->mContinueButton->setCenterPosition(this->mBackground->getContentSize().width / 2 + Utils::coord(200), this->mBackground->getContentSize().height / 2 - Utils::coord(320));
        
    this->mRestartButton->create()->setCurrentFrameIndex(1);
    this->mRestartButton->setCenterPosition(this->mBackground->getContentSize().width / 2, this->mBackground->getContentSize().height / 2 - Utils::coord(340));

    this->mMenuButton->create()->setCurrentFrameIndex(0);
    this->mMenuButton->setCenterPosition(this->mBackground->getContentSize().width / 2 - Utils::coord(200), this->mBackground->getContentSize().height / 2 - Utils::coord(300));
    
    this->setVisible(false);
}

// ===========================================================
// Methods
// ===========================================================

void End::onTouchButtonsCallback(const int pAction, const int pID)
{
    End* pSender = (End*) End::m_Instance;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_END_MENU:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_MENU);

                break;
                case Options::BUTTONS_ID_END_RESTART:

                    //

                break;
                case Options::BUTTONS_ID_END_CONTINUE:

                    //

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
// Virtual Methods
// ===========================================================

#endif