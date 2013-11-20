#ifndef CONST_TOUCHTRAILLAYER
#define CONST_TOUCHTRAILLAYER

#include "TouchTrailLayer.h"

#include "CCBlade.h"
#include "Menu.h"
#include "Loader.h"

TouchTrailLayer::~TouchTrailLayer()
{
    CC_SAFE_RELEASE(this->mWeaponParticles);
}

TouchTrailLayer::TouchTrailLayer()
{
    setTouchEnabled(true);

    this->mTimeBeforeNextBladeSound = 0.15f;
    this->mTimeBeforeNextBladeSoundElapsed = 0;

    SpriteBatch* a = SpriteBatch::create("TextureAtlas7");
    this->addChild(a);
    this->mWeaponParticles = EntityManager::create(300, WeaponParticle::create(), a);
}

TouchTrailLayer* TouchTrailLayer::create()
{
    TouchTrailLayer *pRet = new TouchTrailLayer();
    pRet->autorelease();

    return pRet;
}

void TouchTrailLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    this->mTimeBeforeNextBladeSoundElapsed = this->mTimeBeforeNextBladeSound;

    for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
        CCTouch *touch = (CCTouch *)*it;
        CCBlade *blade = CCBlade::create(Loader::WEAPON_TEXTURE[Options::SELECTED_WEAPON_ID], 30, 12);
        _map[touch] = blade;
        addChild(blade);
        
        CCPoint point = convertTouchToNodeSpace(touch);
        blade->push(point);
        
        Options::TOUCH_INFORMATION[touch->getID()].last_sound_time = Utils::millisecondNow();
        Options::TOUCH_INFORMATION[touch->getID()].slice = true;
    }
}

void TouchTrailLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
        CCTouch *touch = (CCTouch *)*it;
        if (_map.find(touch) == _map.end()) continue;
        
        CCBlade *blade = _map[touch];
        CCPoint point = convertTouchToNodeSpace(touch);
        blade->push(point);
        
        if(abs(ccpDistance(point, Options::TOUCH_INFORMATION[touch->getID()].last_sound_position)) > Options::CAMERA_WIDTH / 15.0)
        {
            float dtime = 20.0;
            
            if(Utils::millisecondNow() - Options::TOUCH_INFORMATION[touch->getID()].last_sound_time < dtime && this->mTimeBeforeNextBladeSoundElapsed > 0.1)
            {
                if(Options::SOUND_ENABLE)
                {
                    SimpleAudioEngine::sharedEngine()->playEffect(Options::SOUND_SWOOSH);
                }
                
                this->mTimeBeforeNextBladeSoundElapsed = 0;
            }
            
            Options::TOUCH_INFORMATION[touch->getID()].last_sound_position = point;
            Options::TOUCH_INFORMATION[touch->getID()].last_sound_time = Utils::millisecondNow();
            
        }
        
        if(abs(ccpDistance(point, Options::TOUCH_INFORMATION[touch->getID()].last_slice_position)) > Options::CAMERA_WIDTH / 100.0)
        {
             float dtime = 200.0;
             
             if(Utils::millisecondNow() - Options::TOUCH_INFORMATION[touch->getID()].last_slice_time < dtime)
             {
                 Options::TOUCH_INFORMATION[touch->getID()].slice = true;
             }
             else
             {
                 Options::TOUCH_INFORMATION[touch->getID()].slice = false;
             }
             
             Options::TOUCH_INFORMATION[touch->getID()].last_slice_time = Utils::millisecondNow();
         }
        
        Options::TOUCH_INFORMATION[touch->getID()].last_slice_position = point;
        Options::TOUCH_INFORMATION[touch->getID()].position = point;

        for(int i = 0; i < 3; i++)
        {
            WeaponParticle* entity = static_cast<WeaponParticle*>(this->mWeaponParticles->create());

            entity->setCenterPosition(point.x, point.y);
            entity->setType(i);
        }
    }
}

void TouchTrailLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    int i = -1;
    for (CCSetIterator it = pTouches->begin(); it != pTouches->end(); it++) {
        i++;
        
        CCTouch *touch = (CCTouch *)*it;
        //if (_map.find(touch) == _map.end()) continue;
        
        CCBlade *blade = _map[touch];
        if(blade != NULL)
        blade->autoCleanup();
        _map.erase(touch);
        
        Options::TOUCH_INFORMATION[touch->getID()].slice = false;
        Options::TOUCH_INFORMATION[touch->getID()].position = ccp(-1000, -1000);
    }
}

void TouchTrailLayer::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);

    this->mTimeBeforeNextBladeSoundElapsed += pDeltaTime;
    
    for(int i = 0; i < 10; i++)
    {
        float dtime = 200.0;
        
        if(Utils::millisecondNow() - Options::TOUCH_INFORMATION[i].last_slice_time < dtime)
        {
            Options::TOUCH_INFORMATION[i].slice = true;
        }
        else
        {
            Options::TOUCH_INFORMATION[i].slice = false;
        }
    }
}

void TouchTrailLayer::onEnter()
{
    CCLayer::onEnter();
    
    this->scheduleUpdate();
}

void TouchTrailLayer::onExit()
{
    CCLayer::onExit();
    
    this->stopAllActions();
    this->unscheduleAllSelectors();
}

#endif