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

Pause* Pause::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Pause::Pause(CCNode* pParent) :
    Popup(pParent)
    {
        this->mIllustrationAnimationTime = 0.5;
        this->mIllustrationAnimationTimeElapsed = 0;

        this->mBirdsIllustrationsBatch = CCSpriteBatchNode::create("pause_birds_sprite@2x.png");
        this->mBirdsIllustrations[1] = new Entity((EntityStructure) {"pause_birds_sprite@2x.png", 1, 2, 0, 0, 200, 600}, this->mBirdsIllustrationsBatch);
        this->mBirdsIllustrations[2] = new Entity((EntityStructure) {"pause_birds_sprite@2x.png", 1, 2, 200, 0, 200, 600}, this->mBirdsIllustrationsBatch);
        this->mBirdsIllustrations[3] = new Entity((EntityStructure) {"pause_birds_sprite@2x.png", 1, 2, 400, 0, 200, 600}, this->mBirdsIllustrationsBatch);
        this->mBirdsIllustrations[0] = new Entity((EntityStructure) {"pause_birds_sprite@2x.png", 1, 1, 0, 600, 600, 107}, this->mBirdsIllustrationsBatch);

        this->mBackground->addChild(this->mBirdsIllustrationsBatch);

        this->mBirdsIllustrations[0]->create()->setCenterPosition(this->mBackground->getWidth() / 2, this->mBackground->getHeight() / 2 + Utils::coord(300));
        this->mBirdsIllustrations[1]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(155), this->mBackground->getHeight() / 2 + Utils::coord(480));
        this->mBirdsIllustrations[2]->create()->setCenterPosition(this->mBackground->getWidth() / 2 - Utils::coord(0), this->mBackground->getHeight() / 2 + Utils::coord(480));
        this->mBirdsIllustrations[3]->create()->setCenterPosition(this->mBackground->getWidth() / 2 + Utils::coord(160), this->mBackground->getHeight() / 2 + Utils::coord(480));

        this->mCloseButton = new Button((EntityStructure) {"btn_sprite@2x.png", 1, 1, 162, 162, 162, 162}, this->mBackground, Options::BUTTONS_ID_POPUP_CLOSE, onTouchButtonsCallback);
        this->mSoundButton = new Button("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mBackground, Options::BUTTONS_ID_SETTINGS_SOUND, onTouchButtonsCallback);
        this->mMusicButton = new Button("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mBackground, Options::BUTTONS_ID_SETTINGS_MUSIC, onTouchButtonsCallback);
        this->mLeaderBoardButton = new Button("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mBackground, Options::BUTTONS_ID_PAUSE_LEADERBOARD, onTouchButtonsCallback);
        this->mAchievementsButton = new Button("btn_sfx_mfx_ach_lead_sprite_pause@2x.png", 3, 2, this->mBackground, Options::BUTTONS_ID_PAUSE_ACHIEVEMENTS, onTouchButtonsCallback);
        this->mContinueButton = new Button("pause_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_CONTINUE, onTouchButtonsCallback);
        this->mBackButton = new Button("pause_btn@2x.png", 1, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_MODE, onTouchButtonsCallback);
        this->mShopButton = new Button("pause_btn_sprite@2x.png", 2, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_SHOP, onTouchButtonsCallback);
        this->mMenuButton = new Button("pause_btn_sprite@2x.png", 2, 1, this->mBackground, Options::BUTTONS_ID_PAUSE_MENU, onTouchButtonsCallback);

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
        this->mMenuButton ->setCurrentFrameIndex(0);
        
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void Pause::onTouchButtonsCallback(const int pAction, const int pID)
{
    Pause* pSender = static_cast<Pause*>(Pause::m_Instance);
    
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_POPUP_CLOSE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_PAUSE_MENU:
                
                pSender->hide();
                
                Loader::ACTION = 3;
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
                
                break;
            case Options::BUTTONS_ID_PAUSE_SHOP:
                
                pSender->hide();
                
                Loader::ACTION = 5;
                
                AppDelegate::screens->set(0.5, Screen::SCREEN_LOADER);
                
                break;
            case Options::BUTTONS_ID_PAUSE_RESTART:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_PAUSE_CONTINUE:
                
                pSender->hide();
                
            break;
            case Options::BUTTONS_ID_SETTINGS_MUSIC:

                Options::MUSIC_ENABLE = !Options::MUSIC_ENABLE;
                    
                if(Options::MUSIC_ENABLE)
                {
                    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();

                    pSender->mMusicButton->setCurrentFrameIndex(0);
                }
                else
                {
                    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();

                    pSender->mMusicButton->setCurrentFrameIndex(3);
                }

                AppDelegate::setMusicEnable(Options::MUSIC_ENABLE);

            break;
            case Options::BUTTONS_ID_SETTINGS_SOUND:
        
                Options::SOUND_ENABLE = !Options::SOUND_ENABLE;
                    
                if(Options::SOUND_ENABLE)
                {
                     pSender->mSoundButton->setCurrentFrameIndex(1);
                }
                else
                {
                    pSender->mSoundButton->setCurrentFrameIndex(4);
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
                
                pSender->hide();

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