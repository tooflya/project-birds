#ifndef CONST_CLASSIC
#define CONST_CLASSIC

#include "Classic.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

Classic* Classic::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Classic::Classic() :
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

void Classic::onTouchButtonsCallback(const int pAction, const int pID)
{
    Classic* pSender = (Classic*) Classic::m_Instance;

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

void Classic::update(float pDeltaTime)
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

void Classic::onEnter()
{
    Screen::onEnter();
}

void Classic::onExit()
{
    Screen::onExit();
}

#endif