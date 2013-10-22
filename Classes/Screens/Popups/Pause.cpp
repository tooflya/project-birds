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

Pause::~Pause()
{
}

Pause::Pause(CCNode* pParent) :
    Popup(pParent, false),
	mIllustrationAnimationTime(0),
	mIllustrationAnimationTimeElapsed(0),
	mContinueButton(0),
	mBackButton(0),
	mSoundButton(0),
	mMusicButton(0),
	mLeaderBoardButton(0),
	mAchievementsButton(0),
	mShopButton(0),
	mMenuButton(0),
	mBirdsIllustrations()
    {
        this->mIllustrationAnimationTime = 0.5;
        this->mIllustrationAnimationTimeElapsed = 0;

		EntityStructure structure1 = {"pause_birds_sprite@2x.png", 1, 2, 0, 0, 200, 600};
		EntityStructure structure2 = {"pause_birds_sprite@2x.png", 1, 2, 200, 0, 200, 600};
		EntityStructure structure3 = {"pause_birds_sprite@2x.png", 1, 2, 400, 0, 200, 600};
		EntityStructure structure4 = {"pause_birds_sprite@2x.png", 1, 1, 0, 600, 600, 107};

        this->mBirdsIllustrations[1] = Entity::create(structure1, this->mSpriteBatch);
        this->mBirdsIllustrations[2] = Entity::create(structure2, this->mSpriteBatch);
        this->mBirdsIllustrations[3] = Entity::create(structure3, this->mSpriteBatch);
        this->mBirdsIllustrations[0] = Entity::create(structure4, this->mSpriteBatch);

        this->mBirdsIllustrations[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300));
        this->mBirdsIllustrations[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(155), Options::CAMERA_CENTER_Y + Utils::coord(480));
        this->mBirdsIllustrations[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(0), Options::CAMERA_CENTER_Y + Utils::coord(480));
        this->mBirdsIllustrations[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(160), Options::CAMERA_CENTER_Y + Utils::coord(480));

        this->mCloseButton = Button::create("btn_sprite_close@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_POPUP_CLOSE, this);
        this->mSoundButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_SOUND, this);
        this->mMusicButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mSpriteBatch, Options::BUTTONS_ID_SETTINGS_MUSIC, this);
        this->mLeaderBoardButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_LEADERBOARD, this);
        this->mAchievementsButton = Button::create("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_ACHIEVEMENTS, this);
        this->mContinueButton = Button::create("pause_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_CONTINUE, this);
        this->mBackButton = Button::create("pause_btn@2x.png", 1, 1, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_MODE, this);
        this->mShopButton = Button::create("pause_btn_sprite@2x.png", 2, 1, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_SHOP, this);
        this->mMenuButton = Button::create("pause_btn_sprite@2x.png", 2, 1, this->mSpriteBatch, Options::BUTTONS_ID_PAUSE_MENU, this);

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

Pause* Pause::create(CCNode* pParent)
{
    Pause* pause = new Pause(pParent);
    pause->autorelease();
    pause->retain();
    
    return pause;
}

// ===========================================================
// Methods
// ===========================================================

void Pause::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                this->hide();
                
                break;
            case Options::BUTTONS_ID_PAUSE_MENU:
                
                this->hide();
                
                Loader::ACTION = 3;
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
                
                break;
            case Options::BUTTONS_ID_PAUSE_SHOP:
                
                this->hide();
                
                Loader::ACTION = 5;
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
                
                break;
            case Options::BUTTONS_ID_PAUSE_RESTART:
                
                this->hide();
                
                break;
            case Options::BUTTONS_ID_PAUSE_CONTINUE:
                
                this->hide();
                
                break;
            case Options::BUTTONS_ID_SETTINGS_MUSIC:
                
                Options::MUSIC_ENABLE = !Options::MUSIC_ENABLE;
                
                if(Options::MUSIC_ENABLE)
                {
                    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
                    
                    this->mMusicButton->setCurrentFrameIndex(0);
                }
                else
                {
                    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
                    
                    this->mMusicButton->setCurrentFrameIndex(3);
                }
                
                AppDelegate::setMusicEnable(Options::MUSIC_ENABLE);
                
                break;
            case Options::BUTTONS_ID_SETTINGS_SOUND:
                
                Options::SOUND_ENABLE = !Options::SOUND_ENABLE;
                
                if(Options::SOUND_ENABLE)
                {
                    this->mSoundButton->setCurrentFrameIndex(1);
                }
                else
                {
                    this->mSoundButton->setCurrentFrameIndex(4);
                }
                
                AppDelegate::setSoundEnable(Options::SOUND_ENABLE);
                
                break;
            case Options::BUTTONS_ID_PAUSE_LEADERBOARD:
                
                // TODO: Open leaderboard.
                
                break;
            case Options::BUTTONS_ID_PAUSE_ACHIEVEMENTS:
                
                // TODO: Open achievements.
                
                break;
            case Options::BUTTONS_ID_PAUSE_MODE:
                
                this->hide();
                
                Loader::ACTION = 4;
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
                
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