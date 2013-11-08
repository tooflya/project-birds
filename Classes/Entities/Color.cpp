#ifndef CONST_COLOR
#define CONST_COLOR

#include "Color.h"

#include "Game.h"
#include "Progresses.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int Color::SOUND_INDEX = -1;

bool Color::ANIMATION_RUNNING = false;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Color::Color() :
    Entity("colors@2x.png", 7, 3),
	position(0),
	mType(0),
	mGoingToDestroy(0),
	d(0),
	mDestroyTime(0),
	mDestroyTimeElapsed(0),
	position_in_matrtix_x(0),
	position_in_matrtix_y(0),
	mPower(0),
	mc(0),
	mct(0),
	mcte(0),
	mBlinkTime(0),
	mBlinkTimeElapsed(0),
	mBlinking(0),
	mBlink(0),
	mPowerText(0),
    mIsSoftAnimationRunning(0)
    {
        this->mBlink = NULL;
        this->mPowerText = NULL;
        
        this->mIsSoftAnimationRunning = false;
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

int Color::getCurrentFrameIndex()
{
    int index = Entity::getCurrentFrameIndex();
    
    if(index > 6) return (index - 7);
    if(index > 13) return (index - 14);
    
    return index; // TODO: Some problems here!
}

int Color::getRealCurrentFrameIndex()
{
    return Entity::getCurrentFrameIndex();
}

void Color::setCenterPositionWithCorrection(float pCenterX, float pCenterY)
{
    int cpx = (pCenterX + Utils::coord(8)) / Utils::coord(64);
    int cpy = (pCenterY + Utils::coord(17)) / Utils::coord(81);
    
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
            Game::MATRIX[cpx][i] = this->mType;
            
            this->position = Utils::coord(81) * c;
            
            this->position_in_matrtix_x = cpx;
            this->position_in_matrtix_y = i;
            
            i = -1;
            
            break;
        }
        else if(Game::MATRIX[cpx][i] == -2)
        {
            int r = -1;
            for(int z = Game::MATRIX_SIZE_Y - 1; z >= 0; z--)
            {
                r++;
                
                if(Game::MATRIX[cpx][z] == this->mType)
                {
                    this->position = Utils::coord(81) * r;
                    
                    this->d = true;
                    
                    Game* game = static_cast<Game*>(this->getParent()->getParent()->getParent());
                    
                    for(int cs = 0; cs < game->mColors->getCount(); cs++)
                    {
                        Color* color = static_cast<Color*>(game->mColors->objectAtIndex(cs));

                        if(color->position_in_matrtix_x == cpx && color->position_in_matrtix_y == z)
                        {
                            color->mPower++;
                            color->mPowerText->setVisible(true);
                            color->mPowerText->setString(ccsf("+%d", color->mPower - 1));
                        }
                    }
                    
                    i = -1;
                    z = -1;
                    
                    break;
                }
            }
            
            c = -1;
            this->position = Utils::coord(64) * c;
            this->d = true;
            
            i = -1;
            
            break;
        }
        
        c++;
    }
    
    Entity::setCenterPosition((Utils::coord(64)) * cpx + Utils::coord(32) + Utils::coord(8), (Utils::coord(81)) * cpy + Utils::coord(40) + Utils::coord(17));
    
    this->runAction(CCMoveTo::create(0.5, ccp(this->getCenterX(), this->position + Utils::coord(40) + Utils::coord(17))));
}

void Color::runDestroy()
{
    this->mGoingToDestroy = true;
    this->mDestroyTime = 0;
    this->mDestroyTimeElapsed = 0;
    
    for(int i = 0; i < 50; i++)
    {
        Entity* particle = static_cast<Progresses*>(this->getParent()->getParent()->getParent())->mColorsParticles->create();
        
        if(particle != NULL)
        {
            particle->setCenterPosition(this->getCenterX(), this->getCenterY());
            particle->setColor(Bird::COLORS[this->getCurrentFrameIndex()]);
        }
    }
    
    if(Options::SOUND_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_GEM[SOUND_INDEX]);
    }
    
    // Special
    
    if(Entity::getCurrentFrameIndex() > 6 && Entity::getCurrentFrameIndex() < 14)
    {
        static_cast<Progresses*>(this->getParent()->getParent()->getParent())->mColorEffectClearVertical->clear();
        
        Entity* line = static_cast<Progresses*>(this->getParent()->getParent()->getParent())->mColorEffectClearVertical->create();
        
        line->setCenterPosition(this->getCenterX(), this->getCenterY());
        line->runAction(CCScaleTo::create(0.8, 1, 100));
        line->runAction(CCFadeOut::create(0.8));
        
        for(int i = 0; i < static_cast<Progresses*>(this->getParent()->getParent()->getParent())->mColors->getCount(); i++)
        {
            Color* color = static_cast<Color*>(static_cast<Progresses*>(this->getParent()->getParent()->getParent())->mColors->objectAtIndex(i));
            
            if(color->position_in_matrtix_x == this->position_in_matrtix_x && (color->position_in_matrtix_y != this->position_in_matrtix_y) && !color->mGoingToDestroy)
            {
                color->runDestroy();

                Game::BURNED[color->getCurrentFrameIndex()] += color->mPower;
            }
        }

        if(Options::SOUND_ENABLE)
        {
            SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LEVEL_UNLOCK);
        }
    }
    else if(Entity::getCurrentFrameIndex() > 13)
    {
        static_cast<Progresses*>(this->getParent()->getParent()->getParent())->mColorEffectClearHorizontal->clear();
        
        Entity* line = static_cast<Progresses*>(this->getParent()->getParent()->getParent())->mColorEffectClearHorizontal->create();
        
        line->setCenterPosition(this->getCenterX(), this->getCenterY());
        line->runAction(CCScaleTo::create(0.8, 100, 1));
        line->runAction(CCFadeOut::create(0.8));
        
        for(int i = 0; i < static_cast<Progresses*>(this->getParent()->getParent()->getParent())->mColors->getCount(); i++)
        {
            Color* color = static_cast<Color*>(static_cast<Progresses*>(this->getParent()->getParent()->getParent())->mColors->objectAtIndex(i));
            
            if(color->position_in_matrtix_y == this->position_in_matrtix_y && (color->position_in_matrtix_x != this->position_in_matrtix_x) && !color->mGoingToDestroy)
            {
                color->runDestroy();
                
                Game::BURNED[color->getCurrentFrameIndex()] += color->mPower;
            }
        }
        
        if(Options::SOUND_ENABLE)
        {
            SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_LEVEL_UNLOCK);
        }
    }
}

void Color::down()
{
    this->runAction(CCMoveTo::create(0.1, ccp(this->getCenterX(), this->getCenterY() - Utils::coord(81))));
    
    Game::MATRIX[this->position_in_matrtix_x][this->position_in_matrtix_y] = -1;
    this->position_in_matrtix_y++;
    Game::MATRIX[this->position_in_matrtix_x][this->position_in_matrtix_y] = this->mType;
    
    static_cast<Game*>(this->getParent()->getParent()->getParent())->deepFind(this->position_in_matrtix_x, this->position_in_matrtix_y, this->mType, true, this);
    
    ANIMATION_RUNNING = true;
}

// ===========================================================
// Override Methods
// ===========================================================

void Color::onCreate()
{
    Entity::onCreate();

    this->mIsSoftAnimationTime = 0.0; // TODO: Time?
    this->mIsSoftAnimationTimeElapsed = 0.1; // TODO: Do something with it!
    
    this->mIsSoftAnimationRunning = false;

    this->mIsSoftAnimationCounter = 0;

    this->d = false;
    this->mBlinking = false;

    this->mPower = 1;

    this->mBlinkTime = Utils::randomf(1.0, 6.0);
    this->mBlinkTimeElapsed = 0;

    this->setScale(0.1);
    this->mGoingToDestroy = false;

    this->mct = 0.5;
    this->mcte = 0;
    this->mc = false;

    this->position = 0;

    this->mBlink = static_cast<Game*>(this->getParent()->getParent()->getParent())->mColorsBlink->create();
    this->mBlink->animate(0.1);
    this->mBlink->setOpacity(0);

    if(this->mPowerText == NULL)
    {
		Textes textes1 = {"+", Options::FONT, 20, -1};

        this->mPowerText = Text::create(textes1, this->getParent()->getParent()->getParent());
        this->mPowerText->setColor(ccc3(0, 255, 0));
    }

    this->mPowerText->setVisible(false);

    this->runAction(CCScaleTo::create(0.5, 1));
}

void Color::onDestroy()
{
    this->stopAllActions();
    
    if(this->mBlink != NULL)
    {
        this->mBlink->destroy();
        this->mPowerText->setVisible(false);
    }
    
    Entity::onDestroy();
    
    Game::MATRIX[this->position_in_matrtix_x][this->position_in_matrtix_y] = -1;
}

void Color::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(this->mIsSoftAnimationRunning)
    {
        this->mIsSoftAnimationTimeElapsed += pDeltaTime;
        
        if(this->mIsSoftAnimationTimeElapsed >= this->mIsSoftAnimationTime)
        {
            this->mIsSoftAnimationTimeElapsed = 0;
            
            switch(++this->mIsSoftAnimationCounter)
            {
                case 1:
                this->runAction(CCScaleTo::create(this->mIsSoftAnimationTime, 1.0, 0.9));
                break;
                case 2:
                this->runAction(CCScaleTo::create(this->mIsSoftAnimationTime, 1.0, 1.0));
                    
                this->mIsSoftAnimationRunning = false;
                break;
            }
        }
    }
    
    if(this->mBlinking)
    {
        this->mBlinkTimeElapsed += pDeltaTime;
        
        if(this->mBlinkTimeElapsed >= this->mBlinkTime)
        {
            this->mBlink->runAction(CCFadeOut::create(1.0));
            
            this->mBlinking = !this->mBlinking;
            this->mBlinkTimeElapsed = 0;
        }
    }
    else
    {
        this->mBlinkTimeElapsed += pDeltaTime;
        
        if(this->mBlinkTimeElapsed >= this->mBlinkTime)
        {
            this->mBlink->runAction(CCFadeIn::create(1.0));
            
            this->mBlinking = !this->mBlinking;
            this->mBlinkTimeElapsed = 0;
        }
    }
    
    if(!this->mc)
    {
        this->mcte += pDeltaTime;
        
        if(this->mcte >= this->mct)
        {
            this->mc = true;
            
            static_cast<Game*>(this->getParent()->getParent()->getParent())->deepFind(this->position_in_matrtix_x, this->position_in_matrtix_y, this->mType, true, this);
            
            ANIMATION_RUNNING = true;
            
            if(this->d)
            {
                this->destroy();
                
                SOUND_INDEX = -1;
            }
            
            if(Options::SOUND_ENABLE)
            {
                SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_MISS);
            }
            
            this->mIsSoftAnimationRunning = true;
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
    
    if(this->position_in_matrtix_y < Game::MATRIX_SIZE_Y - 1 && !this->mGoingToDestroy && this->mc && this->numberOfRunningActions() == 0 && !this->d)
    {
        if(Game::MATRIX[this->position_in_matrtix_x][this->position_in_matrtix_y + 1] == -1)
        {
            this->down();
        }
    }
    
    this->mBlink->setCenterPosition(this->getCenterX(), this->getCenterY());
    this->mPowerText->setCenterPosition(this->getCenterX() + Utils::coord(20), this->getCenterY() - Utils::coord(26));
}

Color* Color::deepCopy()
{
    return Color::create();
}

#endif