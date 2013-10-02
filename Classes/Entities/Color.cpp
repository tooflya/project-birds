#ifndef CONST_COLOR
#define CONST_COLOR

#include "Color.h"

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

Color::Color() :
    Entity("colors@2x.png", 8, 1)
    {

    }

Color* Color::create()
{
    Color* entity = new Color();
    entity->autorelease();
    
    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void Color::setType(int pType)
{
    this->setScale(0);

    this->runAction(CCScaleTo::create(0.1 * pType, 1.0));
}

void Color::setCenterPositionWithCorrection(float pCenterX, float pCenterY)
{
    int cpx = pCenterX / Utils::coord(64) + 1;
    int cpy = pCenterY / Utils::coord(64);
    
    int c = 0;
    for(int i = Game::MATRIX_SIZE_Y; i >= 0; i--)
    {
        if(Game::MATRIX[cpx][i] == -1)
        {
            Game::MATRIX[cpx][i] = this->getCurrentFrameIndex();
            
            this->position = Utils::coord(64) * c;
            
            break;
        }
        
        c++;
    }
    
    Entity::setCenterPosition(Utils::coord(64) * cpx + Utils::coord(32), Utils::coord(64) * cpy + Utils::coord(32));
    
    this->runAction(CCMoveTo::create(1.0, ccp(this->getCenterX(), this->position + Utils::coord(32))));
}

// ===========================================================
// Override Methods
// ===========================================================

void Color::onCreate()
{
    Entity::onCreate();
    
    this->position = -1;
}

void Color::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    //this->setCenterPosition(this->getCenterX(), this->getCenterY() - 500.0 * pDeltaTime);
    
    {
        
    }
}

Color* Color::deepCopy()
{
    return Color::create();
}

#endif