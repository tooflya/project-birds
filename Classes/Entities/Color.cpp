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
    //this->setScale(0);

    //this->runAction(CCScaleTo::create(0.1 * pType, 1.0));
}

void Color::setCenterPositionWithCorrection(float pCenterX, float pCenterY)
{
    int cpx = pCenterX / Utils::coord(64);
    int cpy = pCenterY / Utils::coord(64);
    
    if(cpx < 0 || cpx >= Game::MATRIX_SIZE_X || cpy < 0 || cpy >= Game::MATRIX_SIZE_Y)
    {
        this->destroy();

        return;
    }
    
    int c = 0;
    for(int i = Game::MATRIX_SIZE_Y - 1; i >= 0; i--)
    {
        if(Game::MATRIX[cpx][i] == -1)
        {
            Game::MATRIX[cpx][i] = this->getCurrentFrameIndex();
            
            this->position = Utils::coord(64) * c;
            
            this->position_in_matrtix_x = cpx;
            this->position_in_matrtix_y = i;
            
            break;
        }
        
        c++;
    }
    
    Entity::setCenterPosition(Utils::coord(64) * cpx + Utils::coord(32), Utils::coord(64) * cpy + Utils::coord(32));
    
    this->runAction(CCMoveTo::create(0.5, ccp(this->getCenterX(), this->position + Utils::coord(32))));
}

void Color::runDestroy()
{
    this->mGoingToDestroy = true;
    this->mDestroyTime = 0;
    this->mDestroyTimeElapsed = 0;
}

void Color::down()
{
    this->runAction(CCMoveTo::create(0.2, ccp(this->getCenterX(), this->getCenterY() - Utils::coord(64))));
    
    Game::MATRIX[this->position_in_matrtix_x][this->position_in_matrtix_y] = -1;
    this->position_in_matrtix_y++;
    Game::MATRIX[this->position_in_matrtix_x][this->position_in_matrtix_y] = this->getCurrentFrameIndex();
    
    static_cast<Game*>(this->getParent()->getParent()->getParent())->deepFind(this->position_in_matrtix_x, this->position_in_matrtix_y, this->getCurrentFrameIndex(), true);
}

// ===========================================================
// Override Methods
// ===========================================================

void Color::onCreate()
{
    Entity::onCreate();
    
    this->setScale(1.0);
    this->mGoingToDestroy = false;
    
    this->mct = 0.5;
    this->mcte = 0;
    this->mc = false;
    
    this->position = 0;
}

void Color::onDestroy()
{
    this->stopAllActions();
    
    Entity::onDestroy();
}

void Color::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(!this->mc)
    {
        this->mcte += pDeltaTime;
        
        if(this->mcte >= this->mct)
        {
            this->mc = true;
            
            static_cast<Game*>(this->getParent()->getParent()->getParent())->deepFind(this->position_in_matrtix_x, this->position_in_matrtix_y, this->getCurrentFrameIndex(), true);
        }
    }
    if(this->mGoingToDestroy)
    {
        this->mDestroyTimeElapsed += pDeltaTime;
        
        if(this->mDestroyTimeElapsed >= this->mDestroyTime && this->numberOfRunningActions() == 0)
        {
            this->mDestroyTimeElapsed = 0;
            
            this->runAction(CCScaleTo::create(0.2, 0));
        }
    }
    if(this->getScaleX() <= 0)
    {
        this->destroy();
    }
    
    if(this->position_in_matrtix_y < Game::MATRIX_SIZE_Y - 1 && !this->mGoingToDestroy && this->mc && this->numberOfRunningActions() == 0)
    {
        if(Game::MATRIX[this->position_in_matrtix_x][this->position_in_matrtix_y + 1] == -1)
        {
            this->down();
        }
    }
}

Color* Color::deepCopy()
{
    return Color::create();
}

#endif