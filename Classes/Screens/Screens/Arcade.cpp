#ifndef CONST_ARCADE
#define CONST_ARCADE

#include "Arcade.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Arcade* Arcade::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Arcade::Arcade() :
    Game()
    {
        this->mBackground = new Entity("game_gui_bg_summer@2x.png", this);

        this->mMarks = new BatchEntityManager(200, new Mark(), this);
        this->mFeathers = new BatchEntityManager(100, new Feather(), this);
        this->mBirds = new BatchEntityManager(10, new Bird(), this);
        this->mExplosions = new BatchEntityManager(10, new Explosion(), this);
        this->mDust = new BatchEntityManager(100, new Dust(), this);
        
        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

        m_Instance = this;
    }

// ===========================================================
// Methods
// ===========================================================

void Arcade::onTouchButtonsCallback(const int pAction, const int pID)
{
    Arcade* pSender = static_cast<Arcade*>(Arcade::m_Instance);

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_GAME_PAUSE:

                    //

                break;
                case Options::BUTTONS_ID_GAME_RESTART:

                    // TODO: Restart level.

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

void Arcade::update(float pDeltaTime)
{
    Game::update(pDeltaTime);

    if(true)
    {
        this->mBirdsTimeElapsed += pDeltaTime;

        if(this->mBirdsTimeElapsed >= this->mBirdsTime)
        {
            this->mBirdsTimeElapsed = 0;

            if(this->mBirdsRemaning == 0)
            {
                this->mBirdsRemaning = Utils::random(1, 6);
            }

            this->mBirdsTime = Utils::randomf(0.0, 1.5);

            this->mBirds->create();

            this->mBirdsRemaning--;

            if(this->mBirdsRemaning == 0)
            {
                this->mBirdsTime = Utils::randomf(2.0, 7.0);
            }
        }
    }
}

void Arcade::onEnter()
{
    Screen::onEnter();
}

void Arcade::onExit()
{
    Screen::onExit();
}

#endif