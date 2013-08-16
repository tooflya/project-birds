#ifndef CONST_PAUSE
#define CONST_PAUSE

#include "Pause.h"

#include "Loader.h"

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

Pause::Pause(CCNode* pParent, void (*pOnTouchCallback)(int, int)) :
    Popup(pParent)
    {
        this->mOnTouchCallback = pOnTouchCallback;

        this->mIllustrationAnimationTime = 0.5;
        this->mIllustrationAnimationTimeElapsed = 0;

        this->mBirdsIllustrationsBatch = CCSpriteBatchNode::create("pause_birds_sprite@2x.png");
        this->mBirdsIllustrations[1] = Entity::create((EntityStructure) {"pause_birds_sprite@2x.png", 1, 2, 0, 0, 200, 600}, this->mBirdsIllustrationsBatch);
        this->mBirdsIllustrations[2] = Entity::create((EntityStructure) {"pause_birds_sprite@2x.png", 1, 2, 200, 0, 200, 600}, this->mBirdsIllustrationsBatch);
        this->mBirdsIllustrations[3] = Entity::create((EntityStructure) {"pause_birds_sprite@2x.png", 1, 2, 400, 0, 200, 600}, this->mBirdsIllustrationsBatch);
        this->mBirdsIllustrations[0] = Entity::create((EntityStructure) {"pause_birds_sprite@2x.png", 1, 1, 0, 600, 600, 107}, this->mBirdsIllustrationsBatch);

        this->mBackground->addChild(this->mBirdsIllustrationsBatch);

        this->mBirdsIllustrations[0]->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(300));
        this->mBirdsIllustrations[1]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(155), this->mBackground->getHeight() / 2 + Utils::coord(480));
        this->mBirdsIllustrations[2]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(0), this->mBackground->getHeight() / 2 + Utils::coord(480));
        this->mBirdsIllustrations[3]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(160), this->mBackground->getHeight() / 2 + Utils::coord(480));

        this->mCloseButton = Button::create((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 162, 162, 162}, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, this->mOnTouchCallback);
        this->mSoundButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mBackground, Options::BUTTONS_ID_SETTINGS_SOUND, this->mOnTouchCallback);
        this->mMusicButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mBackground, Options::BUTTONS_ID_SETTINGS_MUSIC, this->mOnTouchCallback);
        this->mLeaderBoardButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mBackground, Options::BUTTONS_ID_PAUSE_LEADERBOARD, this->mOnTouchCallback);
        this->mAchievementsButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mBackground, Options::BUTTONS_ID_PAUSE_ACHIEVEMENTS, this->mOnTouchCallback);
        this->mContinueButton = Button::create("pause_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_CONTINUE, this->mOnTouchCallback);
        this->mBackButton = Button::create("pause_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_MODE, this->mOnTouchCallback);
        this->mShopButton = Button::create("pause_btn_sprite@2x.png", 2, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_SHOP, this->mOnTouchCallback);
        this->mMenuButton = Button::create("pause_btn_sprite@2x.png", 2, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_MENU, this->mOnTouchCallback);

        this->mCloseButton->create()->setCenterPosition(this->mBackground->getWidth() - Utils::coord(40), this->mBackground->getHeight() - Utils::coord(40));
        this->mSoundButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2 - Utils::coord(235), this->mBackground->getHeight()  / 2 - Utils::coord(390));
        this->mMusicButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2 - Utils::coord(130), this->mBackground->getHeight()  / 2 - Utils::coord(390));
        this->mContinueButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2, this->mBackground->getHeight()  / 2 + Utils::coord(150));
        this->mBackButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2, this->mBackground->getHeight()  / 2 - Utils::coord(20));
        this->mShopButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2 + Utils::coord(90), this->mBackground->getHeight()  / 2 - Utils::coord(200));
        this->mMenuButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2 - Utils::coord(90), this->mBackground->getHeight()  / 2 - Utils::coord(200));
        this->mLeaderBoardButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2 + Utils::coord(130), this->mBackground->getHeight()  / 2 - Utils::coord(390));
        this->mAchievementsButton->create()->setCenterPosition(this->mBackground->getWidth()  / 2 + Utils::coord(235), this->mBackground->getHeight()  / 2 - Utils::coord(390));

        this->mContinueButton->setText(Options::TEXT_PAUSE_CONTINUE);
        this->mBackButton->setText(Options::TEXT_PAUSE_BACK_TO_SELECT_MODE);

        this->mAchievementsButton->setCurrentFrameIndex(2);
        this->mLeaderBoardButton->setCurrentFrameIndex(5);
        this->mShopButton->setCurrentFrameIndex(1);
        this->mMenuButton->setCurrentFrameIndex(0);
    }

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void Pause::update(float pDeltaTime)
{
    Popup::update(pDeltaTime);

    this->mIllustrationAnimationTimeElapsed += pDeltaTime;

    if(this->mIllustrationAnimationTimeElapsed >= this->mIllustrationAnimationTime)
    {
        this->mIllustrationAnimationTimeElapsed = 0;

        this->mBirdsIllustrations[Utils::random(1, 3)]->nextFrameIndex();
    }
}

void Pause::show()
{
    Popup::show();

    this->mSoundButton->setCurrentFrameIndex(Options::SOUND_ENABLE ? 1 : 4);
    this->mMusicButton->setCurrentFrameIndex(Options::MUSIC_ENABLE ? 0 : 3);
}

void Pause::hide()
{
    Popup::hide();
}

void Pause::onShow()
{
    Popup::onShow();
}

void Pause::onHide()
{
    Popup::onHide();
}

#endif