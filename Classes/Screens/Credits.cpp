#ifndef CONST_CREDITS
#define CONST_CREDITS

#include "Credits.h"

// ===========================================================
// Inner Classes
// ===========================================================

class TouchLayera : public CCLayer
{
protected:
    float mStartCoordinateY;
    float mStartPositionCoordinateY;
    
    float mStartTime; // ?
    
    float mMaxWidth;
    
    float mPostUpdatePower;
    
    bool mPostUpdate;
    
    Entity* mListSroll;
    
public:
    TouchLayera()
    {
        this->scheduleUpdate();
        this->mMaxWidth = Utils::coord(500);
        this->mPostUpdate = false;
        
        this->mListSroll = new Entity("about_scroll_fill@2x.png", this);
        ccTexParams params = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
        this->mListSroll->getTexture()->setTexParameters(&params);
        
        this->mListSroll->create();
        
        Text* text = new Text(Options::TEXT_CREDITS_STRING_1, this->mListSroll);
        
        text->setCenterPosition(this->mListSroll->getWidth() / 2, this->mListSroll->getHeight() / 2 - Utils::coord(66));
    }
    
    bool ccTouchBegan(CCTouch* touch, CCEvent* event)
    {
        this->mPostUpdate = false;
        
        this->mStartCoordinateY = touch->getLocation().y;
        this->mStartPositionCoordinateY = this->getPosition().y;
        
        return this->containsTouchLocation(touch);
    }
    
    void ccTouchMoved(CCTouch* touch, CCEvent* event)
    {
        if(this->containsTouchLocation(touch))
        {
            float y = this->mStartPositionCoordinateY + touch->getLocation().y - this->mStartCoordinateY;
            
            this->setPosition(ccp(this->getPosition().x, y));
        }
    }
    
    void ccTouchEnded(CCTouch* touch, CCEvent* event)
    {
        float y = this->getPosition().y;
        
        if(y < 0)
        {
            this->runAction(CCMoveTo::create(0.3, ccp(this->getPosition().x, 0)));
        }
        else if(y > this->mMaxWidth)
        {
            this->runAction(CCMoveTo::create(0.3, ccp(this->getPosition().x, this->mMaxWidth)));
        }
        else
        {
            float distance = (this->mStartCoordinateY - touch->getLocation().y) / 10.0;
            
            if(abs(distance) < Utils::coord(10.0)) return;
            
            int t = distance > 0 ? 1 : -1;
            
            this->mPostUpdatePower = abs(floor(distance)) > Utils::coord(30.0) ? Utils::coord(30.0) * t : floor(distance);
            
            this->mPostUpdate = true;
        }
    }
    
    bool containsTouchLocation(CCTouch* touch)
    {
        float y = touch->getLocation().y;
        
        if(y > Utils::coord(200))
        return true;
        
        return false;
    }
    
    void update(float pDeltaTime)
    {
        CCLayer::update(pDeltaTime);
        
        this->mListSroll->setTextureRect(CCRectMake(0, this->getPosition().y, this->mListSroll->getTextureRect().size.width, Utils::coord(891)));
        
        this->mListSroll->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(50) - this->getPosition().y);
        
        if(this->mPostUpdate && false)
        {
            float x = this->getPosition().x - this->mPostUpdatePower;
            
            if(x >= 0) x = 0;
            //if(x <= -this->mMaxWidth) x = -this->mMaxWidth;
            
            this->setPosition(ccp(x, this->getPosition().y));
            
            this->mPostUpdatePower = this->mPostUpdatePower > 0 ? this->mPostUpdatePower - 1.0 : this->mPostUpdatePower + 1.0;
            
            if(abs(this->mPostUpdatePower) < Utils::coord(2.0))
            {
                int x = floor(this->getPosition().x);
                
                if(abs(x) % (int) floor(Utils::coord(230)) >= 1.0)
                {
                    this->mPostUpdatePower = this->mPostUpdatePower < 0 ? this->mPostUpdatePower - 1.0 : this->mPostUpdatePower + 1.0;
                }
                else
                {
                    this->mPostUpdatePower = 0;
                }
            }
            
            if(this->mPostUpdatePower == 0)
            {
                this->mPostUpdate = false;
            }
        }
        
        for(int i = 0; i < 1; i++)
        {
            Text* text = (Text*) this->mListSroll->getChildren()->objectAtIndex(i);
        
            text->setTextureRect(CCRectMake(0, this->getPosition().y, text->getTextureRect().size.width, Utils::coord(891)));
        }
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        CCLayer::onEnter();
    }
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        CCLayer::onExit();
    }
};

// ===========================================================
// Constants
// ===========================================================

Credits* Credits::m_Instance = NULL;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Credits::Credits()
{
    this->mBackground = new Entity("settings_bg@2x.png", this);
    this->mBackButton = new Button("btn_sprite@2x.png", 2, 3, this, Options::BUTTONS_ID_CREDITS_BACK, onTouchButtonsCallback);
    
    this->mListBorders = new BatchEntityManager(2, new Entity("about_scroll_border@2x.png"), this);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    
    this->mBackButton->create()->setCurrentFrameIndex(1);
    this->mBackButton->setCenterPosition(Utils::coord(100), Utils::coord(100));
    
    this->mListBorders->create();
    this->mListBorders->create();
    
    ((Entity*) this->mListBorders->objectAtIndex(0))->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(500));
    ((Entity*) this->mListBorders->objectAtIndex(1))->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(400));
    
    ((Entity*) this->mListBorders->objectAtIndex(0))->setScaleY(1);
    ((Entity*) this->mListBorders->objectAtIndex(1))->setScaleY(-1);
    
    TouchLayera* a = new TouchLayera();
    
    this->addChild(a);
    
    m_Instance = this;
}

// ===========================================================
// Methods
// ===========================================================

void Credits::onTouchButtonsCallback(const int pAction, const int pID)
{
    Credits* pSender = (Credits*) Credits::m_Instance;

    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_CREDITS_BACK:

                    AppDelegate::screens->set(0.5, Screen::SCREEN_SETTINGS);

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
// Virtual Methods
// ===========================================================

#endif