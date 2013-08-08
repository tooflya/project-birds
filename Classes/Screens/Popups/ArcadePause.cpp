#ifndef CONST_ARCADEPAUSE
#define CONST_ARCADEPAUSE

#include "ArcadePause.h"

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ArcadePause* ArcadePause::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

ArcadePause::ArcadePause(CCNode* pParent) :
    Pause(pParent, onTouchButtonsCallback)
    {
        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void ArcadePause::onTouchButtonsCallback(const int pAction, const int pID)
{
    ArcadePause* pSender = static_cast<ArcadePause*>(ArcadePause::m_Instance);
    
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

#endif