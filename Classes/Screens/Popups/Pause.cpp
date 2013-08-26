#ifndef CONST_PAUSE
#define CONST_PAUSE

#include "Pause.h"

#include "Loader.h"
#include "Game.h"

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
    Popup(pParent, false)
    {
        this->mOnTouchCallback = pOnTouchCallback;

        this->mIllustrationAnimationTime = 0.5;
        this->mIllustrationAnimationTimeElapsed = 0;

        this->mBirdsIllustrations[1] = Entity::create((EntityStructure) {"pause_birds_sprite@2x.png", 1, 2, 0, 0, 200, 600}, this->mSpriteBatch);
        this->mBirdsIllustrations[2] = Entity::create((EntityStructure) {"pause_birds_sprite@2x.png", 1, 2, 200, 0, 200, 600}, this->mSpriteBatch);
        this->mBirdsIllustrations[3] = Entity::create((EntityStructure) {"pause_birds_sprite@2x.png", 1, 2, 400, 0, 200, 600}, this->mSpriteBatch);
        this->mBirdsIllustrations[0] = Entity::create((EntityStructure) {"pause_birds_sprite@2x.png", 1, 1, 0, 600, 600, 107}, this->mSpriteBatch);

        this->mBirdsIllustrations[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));
        this->mBirdsIllustrations[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(155), Options::CAMERA_CENTER_Y + Utils::coord(480));
        this->mBirdsIllustrations[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(0), Options::CAMERA_CENTER_Y + Utils::coord(480));
        this->mBirdsIllustrations[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(160), Options::CAMERA_CENTER_Y + Utils::coord(480));

        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this->mOnTouchCallback);
        this->mSoundButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_SOUND, this->mOnTouchCallback);
        this->mMusicButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_MUSIC, this->mOnTouchCallback);
        this->mLeaderBoardButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_LEADERBOARD, this->mOnTouchCallback);
        this->mAchievementsButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_ACHIEVEMENTS, this->mOnTouchCallback);
        this->mContinueButton = Button::create("pause_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_CONTINUE, this->mOnTouchCallback);
        this->mBackButton = Button::create("pause_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_MODE, this->mOnTouchCallback);
        this->mShopButton = Button::create("pause_btn_sprite@2x.png", 2, 1, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_SHOP, this->mOnTouchCallback);
        this->mMenuButton = Button::create("pause_btn_sprite@2x.png", 2, 1, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_MENU, this->mOnTouchCallback);

        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(290), Options::CAMERA_CENTER_Y + Utils::coord(450));
        this->mSoundButton->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(235), Options::CAMERA_CENTER_Y - Utils::coord(390));
        this->mMusicButton->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(130), Options::CAMERA_CENTER_Y - Utils::coord(390));
        this->mContinueButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(150));
        this->mBackButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(20));
        this->mShopButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(90), Options::CAMERA_CENTER_Y - Utils::coord(200));
        this->mMenuButton->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(90), Options::CAMERA_CENTER_Y - Utils::coord(200));
        this->mLeaderBoardButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(130), Options::CAMERA_CENTER_Y - Utils::coord(390));
        this->mAchievementsButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(235), Options::CAMERA_CENTER_Y - Utils::coord(390));

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
    
    Game* game = static_cast<Game*>(this->mParent);
    game->pause();
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
    
    Game* game = static_cast<Game*>(this->mParent);
    game->pause();
}

#endif