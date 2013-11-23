#ifndef CONST_PROGRESSES
#define CONST_PROGRESSES

#include "Progresses.h"

#include "Loader.h"

// ===========================================================
// Inner Classes
// ===========================================================

class Task : public CCObject
{
protected:
    int color;

public:
    Task(int pColor)
    {
        this->color = pColor;
    }

    int getTask()
    {
        return this->color;
    }
};

class TaskPanel : public CCLayer
{
    public:
    CCNode* mParent;
    
    Entity* mStarsCountIcon[9];
    
    float mStarsCountIconAnimationTime;
    
    bool mStarsCountIconAnimationReverse;
    
    bool mDownAnimation;
    
    int mDownAnimationStep;
    float mDownAnimationStepTimeElapsed;
    float mDownAnimationStepTime;
    
    bool mUpAnimation;
    
    int mUpAnimationStep;
    float mUpAnimationStepTimeElapsed;
    float mUpAnimationStepTime;
    
    Text* mTaskText[6];
    
    TaskPanel(CCNode* pParent)
    {
        SpriteBatch* sb1 = SpriteBatch::create("TextureAtlas6");
        
        Entity* u = Entity::create("popup_cloud@2x.png", sb1);
        Entity* u2 = Entity::create("bg_detail_choose_bird@2x.png", sb1);
        u->create()->setCenterPosition(this->getContentSize().width / 2, this->getContentSize().height / 2 - Utils::coord(50));
        u2->create()->setCenterPosition(this->getContentSize().width / 2 + Utils::coord(200), u2->getHeight() / 2 - Options::CAMERA_CENTER_Y);
        u->setOpacity(200);
        this->addChild(sb1);
        
        this->mParent = pParent;
        
        this->ignoreAnchorPointForPosition(false);
        this->setAnchorPoint(ccp(0.5, 0.5));
        this->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
        
        int count = 0;
        int t_Count = 2;
        
        for(int j = 0; j < 3; j++)
        {
            for(int i = 0; i < 3; i++)
            {
                int frame = 0;
                
                if(j == 0) switch(i) { case 0: frame = 1; break; case 1: frame = 1; break; case 2: frame = 1; break; }
                if(j == 1) switch(i) { case 0: frame = 4; break; case 1: frame = 1; break; case 2: frame = 1; break; }
                if(j == 2) switch(i) { case 0: frame = 4; break; case 1: frame = 4; break; case 2: frame = 1; break; }
                
                this->mStarsCountIcon[count] = Entity::create("end_lvl_star_sprite@2x.png", 3, 2, this);
                this->mStarsCountIcon[count]->setScale(0.5);
                this->mStarsCountIcon[count]->setCurrentFrameIndex(frame);
                
                count++;
            }
            
            this->mTaskText[t_Count] = Text::create(Options::TEXT_LEVELS_TASKS[Game::LEVEL][t_Count - 2], this);
            this->mTaskText[t_Count]->setHorizontalAlignment(kCCTextAlignmentLeft);
            
            t_Count++;
        }
        
        this->mTaskText[0] = Text::create(Options::TEXT_PROGRESS_LEVEL_NUMBER, this);
        this->mTaskText[1] = Text::create(Options::TEXT_PROGRESS_LEVEL_TASK, this);
        this->mTaskText[0]->setCenterPosition(this->getContentSize().width / 2, this->getContentSize().height / 2 + Utils::coord(260));
        this->mTaskText[1]->setCenterPosition(this->getContentSize().width / 2, this->getContentSize().height / 2 + Utils::coord(170));
        
        count = 0;
        
        for(int j = 2; j >= 0; j--)
        {
            for(int i = 2; i >= 0; i--)
            {
                this->mStarsCountIcon[count]->create()->setCenterPosition(this->getContentSize().width / 2 - Utils::coord(250) + Utils::coord(40) * i, this->getContentSize().height / 2 - Utils::coord(100) * j + Utils::coord(40));
                
                count++;
            }
        }
        
        this->mTaskText[5] = Text::create(Options::TEXT_PROGRESS_TAP_TO_CONTINUE, this);
        this->mTaskText[5]->setCenterPosition(this->getContentSize().width / 2, this->getContentSize().height / 2 - Utils::coord(260));
        
        this->mStarsCountIconAnimationTime = 2.0;
        this->mStarsCountIconAnimationReverse = false;
        
        this->mDownAnimation = false;
        this->mDownAnimationStepTime = 0;
        this->mDownAnimationStepTimeElapsed = 0;
        this->mDownAnimationStep = -1;
        
        this->mUpAnimation = false;
        this->mUpAnimationStepTime = 0;
        this->mUpAnimationStepTimeElapsed = 0;
        this->mUpAnimationStep = -1;
        
        this->mTaskText[5]->runAction(CCRepeatForever::create(CCSequence::create(CCFadeTo::create(1.0, 0), CCFadeTo::create(1.0, 255.0), NULL)));
    }
    
    static TaskPanel* create(CCNode* pParent)
    {
        TaskPanel* background = new TaskPanel(pParent);
        background->autorelease();
        background->retain();
        
        return background;
    }
    
    void up()
    {
        this->mTaskText[0]->setString(ccsf(Options::TEXT_PROGRESS_LEVEL_NUMBER.string, (Game::LEVEL + 1)));
        
        for(int i = 0; i < 3; i++)
        {
            this->mTaskText[i + 2]->setString(Options::TEXT_LEVELS_TASKS[Game::LEVEL][i].string);
            this->mTaskText[i + 2]->setCenterPosition(this->getContentSize().width / 2 - Utils::coord(100) + this->mTaskText[i + 2]->getWidth() / 2, this->getContentSize().height / 2 - Utils::coord(100) * i + Utils::coord(40));
        }
        
        {
            if(this->mUpAnimation || this->getParent()) return;
            
            this->mParent->addChild(this, 1000);
            
            this->mUpAnimation = true;
            this->mUpAnimationStepTime = 0;
            this->mUpAnimationStepTimeElapsed = 0;
            this->mUpAnimationStep = -1;
            
            this->stopAllActions();
            
            this->setPosition(ccp(Options::CAMERA_CENTER_X, -Options::CAMERA_HEIGHT / 4));
        }
    }
    
    void down()
    {
        if(this->mDownAnimation || !this->getParent()) return;
        
        this->mDownAnimation = true;
        this->mDownAnimationStepTime = 0;
        this->mDownAnimationStepTimeElapsed = 0;
        this->mDownAnimationStep = -1;
        
        this->stopAllActions();
        
        this->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
    }
    
    void update(float pDeltaTime)
    {
        if(this->mUpAnimation)
        {
            this->mUpAnimationStepTimeElapsed += pDeltaTime;
            
            if(this->mUpAnimationStepTimeElapsed >= this->mUpAnimationStepTime)
            {
                this->mUpAnimationStepTimeElapsed = 0;
                
                switch(++this->mUpAnimationStep)
                {
                    case 0:
                        this->runAction(CCSequence::create(CCMoveTo::create(0.3, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200))), CCMoveTo::create(0.1, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y)), NULL));
                        this->mUpAnimationStepTime = 0.3;
                        break;
                    case 1:
                        //this->runAction(CCMoveTo::create(0.1, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y)));
                        this->mUpAnimationStepTime = 0.1;
                        break;
                    case 2:
                        this->mUpAnimation = false;
                        break;
                }
            }
        }
        
        if(this->mDownAnimation)
        {
            this->mDownAnimationStepTimeElapsed += pDeltaTime;
            
            if(this->mDownAnimationStepTimeElapsed >= this->mDownAnimationStepTime)
            {
                this->mDownAnimationStepTimeElapsed = 0;
                
                switch(++this->mDownAnimationStep)
                {
                    case 0:
                        this->runAction(CCSequence::create(CCMoveTo::create(0.1, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100))), CCMoveTo::create(0.3, ccp(Options::CAMERA_CENTER_X, -Options::CAMERA_HEIGHT / 4)), NULL));
                        this->mDownAnimationStepTime = 0.1;
                        break;
                    case 1:
                        this->mDownAnimationStepTime = 0.3;
                        break;
                    case 2:
                        this->mDownAnimation = false;
                        this->removeFromParentAndCleanup(false);
                        break;
                }
            }
        }
        
        this->mStarsCountIconAnimationTime += pDeltaTime;
        
        if(this->mStarsCountIconAnimationTime >= 2.0)
        {
            this->mStarsCountIconAnimationTime = 0;
            
            if(this->mStarsCountIconAnimationReverse)
            {
                for(int i = 0; i < 9; i++)
                {
                    this->mStarsCountIcon[i]->runAction(CCRotateTo::create(2.0, 15));
                }
            }
            else
            {
                for(int i = 0; i < 9; i++)
                {
                    this->mStarsCountIcon[i]->runAction(CCRotateTo::create(2.0, -15));
                }
            }
            
            this->mStarsCountIconAnimationReverse = !this->mStarsCountIconAnimationReverse;
        }
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        
        CCLayer::onEnter();
        
        this->scheduleUpdate();
    }
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        CCLayer::onExit();
        
        this->unscheduleAllSelectors();
        this->unscheduleUpdate();
    }
    
    bool ccTouchBegan(CCTouch* touch, CCEvent* event)
    {
        return true;
    }
    
    void ccTouchEnded(CCTouch* touch, CCEvent* event)
    {
        this->down();
        
        static_cast<Game*>(this->mParent)->mPause = false;
    }
};

// ===========================================================
// Constants
// ===========================================================

int Progresses::TASK[80][10] =
{
    {1, 1},
    {1, 3},
    {1, 3, 2, 3},
    {1, 3, 2, 3},
    {1, 10, 2, 10},
    {1, 20, 2, 20},
    {2, 30},
    {1, 10, 2, 10, 3, 5},
    {2, 40, 3, 5},
    {1, 5, 2, 10, 3, 15},
    {1, 10, 2, 10, 3, 10},
    {1, 20, 2, 10, 3, 10},
    {3, 100},
    {1, 10, 2, 20, 3, 30, 4, 40}
};

class Grid : public CCNode
{
public:
    
  void draw()
    {
        glLineWidth(3.0);

        float x1 = Utils::coord(0);
        float x2 = Options::CAMERA_WIDTH;
        float y1 = Utils::coord(0);
        float y2 = Utils::coord(0);
        
        int xc = (Options::CAMERA_WIDTH / Utils::coord(64)) / 2;
        int yc = (Options::CAMERA_HEIGHT / Utils::coord(64)) / 2;
        
        ccDrawColor4F(1.0f, 0.0f, 0.0f, 1.0f);
        
        for(int i = -yc; i < yc + 1; i++)
        {
            y1 = Options::CAMERA_CENTER_Y + Utils::coord(64) * i;
            y2 = Options::CAMERA_CENTER_Y + Utils::coord(64) * i;
            
            ccDrawLine(ccp(x1, y1), ccp(x2, y2));
        }
        
        x1 = Utils::coord(0);
        x2 = Utils::coord(0);
        y1 = Utils::coord(0);
        y2 = Options::CAMERA_HEIGHT - Utils::coord(65);
        
        for(int i = -xc; i < xc + 1; i++)
        {
            x1 = Options::CAMERA_CENTER_X + Utils::coord(64) * i;
            x2 = Options::CAMERA_CENTER_X + Utils::coord(64) * i;
            
            ccDrawLine(ccp(x1, y1), ccp(x2, y2));
        }
        
        for(int i = Game::MATRIX_SIZE_X - 1; i >= 0; i--)
        {
            for(int j = Game::MATRIX_SIZE_Y - 1; j >= 0; j--)
            {
                if(Game::MATRIX[i][j] == -1)
                {
                    ccDrawColor4F(1.0f, 0.0f, 0.0f, 1.0f);
                    
                    ccDrawLine(ccp(Utils::coord(64) * i, Options::CAMERA_HEIGHT - Utils::coord(64) * j), ccp(Utils::coord(64) * (i + 1), Options::CAMERA_HEIGHT - Utils::coord(64) * (j + 1)));
                    ccDrawLine(ccp(Utils::coord(64) * i, Options::CAMERA_HEIGHT - Utils::coord(64) * (j + 1)), ccp(Utils::coord(64) * (i + 1), Options::CAMERA_HEIGHT - Utils::coord(64) * (j + 0)));
                }
                
                if(Game::MATRIX[i][j] == -2)
                {
                    ccDrawColor4F(0.0f, 0.0f, 0.0f, 1.0f);
                    
                    ccDrawLine(ccp(Utils::coord(64) * i, Options::CAMERA_HEIGHT - Utils::coord(64) * j), ccp(Utils::coord(64) * (i + 1), Options::CAMERA_HEIGHT - Utils::coord(64) * (j + 1)));
                    ccDrawLine(ccp(Utils::coord(64) * i, Options::CAMERA_HEIGHT - Utils::coord(64) * (j + 1)), ccp(Utils::coord(64) * (i + 1), Options::CAMERA_HEIGHT - Utils::coord(64) * (j + 0)));
                }
            }
        }
    }
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Progresses::~Progresses()
{
    CC_SAFE_RELEASE(this->mColors);
    CC_SAFE_RELEASE(this->mColorsParticles);
    CC_SAFE_RELEASE(this->mColorEffectClearVertical);
    CC_SAFE_RELEASE(this->mColorEffectClearHorizontal);
    CC_SAFE_RELEASE(this->mShootsDecorations);
    CC_SAFE_RELEASE(this->mGetShootsPopup);
}

Progresses::Progresses() :
	Game(),
	mPanelText2(0),
	mPanelText0(0),
	mPanelText1(0),
	mTaskText(),
    mColorsSmall(0),
    mColorEffectClearVertical(0),
    mColorEffectClearHorizontal(0),
	mTasksBackground(0),
    mGetShootsPopup(0)
    {
        this->mTaskPanel = TaskPanel::create(this);
        
        Loader::TYPE = 3;
        
		Textes textes1 = { "Incredible", Options::FONT, 42, -1 };

        this->mAwesomeText = Text::create(textes1, this);
        this->mAwesomeText->setZOrder(10);
        this->mAwesomeText->setScale(0);
        
		this->mEventLayer = CCLayer::create();
    
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("TextureAtlas3.plist");

		SpriteBatch* spriteBatch0 = SpriteBatch::create("TextureAtlas16");
		SpriteBatch* spriteBatch1 = SpriteBatch::create("TextureAtlas3");
		SpriteBatch* spriteBatch2 = SpriteBatch::create("TextureAtlas7");
		SpriteBatch* spriteBatch3 = SpriteBatch::create("TextureAtlas8");
		SpriteBatch* spriteBatch4 = SpriteBatch::create("TextureAtlas10");
		SpriteBatch* spriteBatch5 = SpriteBatch::create("TextureAtlas11");
		SpriteBatch* spriteBatch6 = SpriteBatch::create("TextureAtlas6");
		SpriteBatch* spriteBatch7 = SpriteBatch::create("TextureAtlas14");
		SpriteBatch* spriteBatch8 = SpriteBatch::create("TextureAtlas6");
        SpriteBatch* spriteBatch17 = SpriteBatch::create("TextureAtlas17");
		this->spriteBatch99 = SpriteBatch::create("TextureAtlas9");
		this->spriteBatch99->retain();

		this->mGameLayer->addChild(spriteBatch0);
		this->mGameLayer->addChild(spriteBatch6);
    
		this->e2 = Effect::create();
		this->mGameLayer->addChild(this->e2);

		this->mGameLayer->addChild(spriteBatch7);
		this->mGameLayer->addChild(spriteBatch1);
		this->mGameLayer->addChild(spriteBatch2);
		this->mGameLayer->addChild(spriteBatch3);
		this->mGameLayer->addChild(this->spriteBatch99);
		this->mGameLayer->addChild(spriteBatch4);
		this->mGameLayer->addChild(spriteBatch5);
		this->mMenuLayer->addChild(spriteBatch8);
        this->mMenuLayer->addChild(spriteBatch17);
        
        this->e5 = Entity::create("board_migalka@2x.png", spriteBatch17);
    
		this->mBackground = Entity::create("temp_level_bg@2x.png", spriteBatch0);
    
		#if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
		if(Options::DEVICE_TYPE != Options::DEVICE_TYPE_IPOD4)
		{
			this->mBackgroundLights[0] = Entity::create("bg_light_main@2x.png", spriteBatch6);
			this->mBackgroundLights[0]->setAnchorPoint(ccp(0.0, 0.5));
			for(int i = 1; i < 4; i++)
			{
				this->mBackgroundLights[i] = Entity::create("bg_light_1.png", spriteBatch6);
				this->mBackgroundLights[i]->setAnchorPoint(ccp(0.0, 0.5));
			}
				for(int i = 4; i < 7; i++)
			{
				this->mBackgroundLights[i] = Entity::create("bg_light_1.png", spriteBatch6);
				this->mBackgroundLights[i]->setAnchorPoint(ccp(0.0, 0.5));
			}
		}
		#endif
    
		this->mGamePanel = Entity::create("game_panel@2x.png", spriteBatch8);
		this->mTextAreas[0] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
		this->mTextAreas[1] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
		this->mTextAreas[2] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
		this->mTextAreas[3] = Entity::create("game_panel_textbox@2x.png", spriteBatch8);
		this->mTextIcons[0] = Icon8::create("game_panel_counter@2x.png", 7, 1, spriteBatch8);
		this->mTextIcons[1] = Icon8::create("game_panel_counter_best@2x.png", spriteBatch8);
		this->mTextIcons[2] = Icon8::create("game_panel_goldlife@2x.png", spriteBatch8);
        
        this->mTextAreas[0]->setScaleX(1.2);
        this->mTextAreas[1]->setScaleX(0.8);
        this->mTextAreas[2]->setScaleX(1.3);
        
		if(Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPHONE4 || Options::DEVICE_TYPE == Options::DEVICE_TYPE_IPOD4)
		{
			this->mTextAreas[0]->setScaleX(this->mTextAreas[0]->getScaleX() + 0.3);
			this->mTextAreas[1]->setScaleX(this->mTextAreas[1]->getScaleX() + 0.3);
			this->mTextAreas[2]->setScaleX(this->mTextAreas[2]->getScaleX() + 0.3);
		}
        
		EntityStructure structure1 = {"game_panel_plus@2x.png", 1, 1, 0, 0, 78, 72};
		this->mGoldLifeButton = Button::create(structure1, spriteBatch8, Options::BUTTONS_ID_GAME_GET_LIVES, this);
		this->mShootsButton = Button::create(structure1, spriteBatch8, Options::BUTTONS_ID_GAME_RESTART, this);

		this->mGamePanel->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextAreas[0]->create()->setCenterPosition(this->mTextAreas[0]->getWidthScaled() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextAreas[1]->create()->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidthScaled() + Utils::coord(10), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextAreas[2]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidthScaled() + Utils::coord(215), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);

		this->mTextIcons[0]->create()->setCenterPosition(this->mTextAreas[0]->getCenterX() - this->mTextAreas[0]->getWidthScaled() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextIcons[1]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() - this->mTextAreas[1]->getWidthScaled() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
		this->mTextIcons[2]->create()->setCenterPosition(this->mTextAreas[2]->getCenterX() - this->mTextAreas[2]->getWidthScaled() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
        
        this->mTextIcons[0]->setCenterPosition(this->mTextIcons[0]->getCenterX(), this->mTextIcons[0]->getCenterY() + Utils::coord(2));
        this->mTextIcons[1]->setCenterPosition(this->mTextIcons[1]->getCenterX(), this->mTextIcons[1]->getCenterY() + Utils::coord(2));
        this->mTextIcons[2]->setCenterPosition(this->mTextIcons[2]->getCenterX(), this->mTextIcons[2]->getCenterY() + Utils::coord(2));
        
        this->mPanelStars[0] = Entity::create("popup_stars@2x.png", 3, 2, spriteBatch8);
        this->mPanelStars[1] = Entity::create("popup_stars@2x.png", 3, 2, spriteBatch8);
        this->mPanelStars[2] = Entity::create("popup_stars@2x.png", 3, 2, spriteBatch8);
        
        this->mPanelStars[0]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidthScaled() / 2 + Utils::coord(35), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2 + Utils::coord(2));
        this->mPanelStars[1]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidthScaled() / 2 + Utils::coord(83), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2 + Utils::coord(2));
        this->mPanelStars[2]->create()->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidthScaled() / 2 + Utils::coord(131), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2 + Utils::coord(2));
        
        this->mPanelStars[0]->setCurrentFrameIndex(4);
        this->mPanelStars[1]->setCurrentFrameIndex(4);
        this->mPanelStars[2]->setCurrentFrameIndex(4);

		this->mGoldLifeButton->create()->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidthScaled() / 2 - this->mGoldLifeButton->getWidth() / 4, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2 + Utils::coord(1));
        
		this->mShootsButton->create()->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidthScaled() / 2 - this->mShootsButton->getWidth() / 4, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2 + Utils::coord(1));

		Textes textes12 = {"0", Options::FONT, 32, -1};
		Textes textes3 = {"x?", Options::FONT, 32, -1};
		Textes textes4 = {"x??", Options::FONT, 32, -1};
		Textes textes5 = {"0/0", Options::FONT, 32, -1};
        
		this->mPanelText0 = Text::create(textes3, this);
		this->mPanelText1 = Text::create(textes4, this);
		this->mPanelText2 = Text::create(textes12, this);
        
		for(int i = 0; i < 5; i++)
		{
			this->mTaskText[i] = Text::create(textes5, this);
			this->mTaskText[i]->setVisible(false);
		}
    
		//this->mConfetti = EntityManager::create(300, Confetti::create(), spriteBatch2);
		this->mStars = EntityManager::create(1000, StarParticle::create(), spriteBatch2);
    
		this->mGameStartText = Text::create(Options::TEXT_GAME_START_STRING_1, this);
    
		EntityStructure structure2 = {"game_panel_pause@2x.png", 1, 1, 0, 0, 78, 72};

		this->mPauseButton = Button::create(structure2, spriteBatch8, Options::BUTTONS_ID_GAME_PAUSE, this);
        
		this->mSchematicBig = EntityManager::create(200, Entity::create("game_chess_bg@2x.png"), spriteBatch2);
		this->mSchematicSmall = EntityManager::create(200, Entity::create("game_chess@2x.png", 2, 1), spriteBatch2);
		this->mDust = EntityManager::create(100, Dust::create(), spriteBatch2);
		this->mMarks = EntityManager::create(300, Mark::create(), spriteBatch2);
		this->mFeathers = EntityManager::create(300, Feather::create(), spriteBatch2);
		this->mBirds = EntityManager::create(30, Bird::create(false), spriteBatch4);
		this->mSpecialBirds = EntityManager::create(10, SpecialBird::create(), spriteBatch5);
		this->mPirateBox = PirateBox::create(spriteBatch5);
		this->mExplosions = EntityManager::create(20, Explosion::create(), spriteBatch2);
		this->mExplosionsBasic = EntityManager::create(20, ExplosionBasic::create(), spriteBatch2);
		this->mCoins = EntityManager::create(50, AnimatedCoin::create("coins@2x.png", 0.7), spriteBatch2);
		this->mSilverCoins = EntityManager::create(50, AnimatedCoin::create("coins_silver@2x.png", 0.7), spriteBatch2);
		this->mArrows = EntityManager::create(5, Entity::create("bomb_arrow.png"), spriteBatch2);
		this->mPredictionIcons = EntityManager::create(5, Entity::create("bomb_ico.png"), spriteBatch2);
		this->mZombieExplosions = EntityManager::create(300, ZombieExplosion::create(), spriteBatch7);
		this->mColors = EntityManager::create(300, Color::create(), spriteBatch2); // TO MUCH NUMBER!!!
        this->mColorsParticles = EntityManager::create(3000, ColorParticle::create(), spriteBatch2); // TO MUCH NUMBER!!!
        this->mColorEffectClearVertical = EntityManager::create(3, Entity::create("colors_vertical_line@2x.png"), spriteBatch8);
        this->mColorEffectClearHorizontal = EntityManager::create(3, Entity::create("colors_horizontal_line@2x.png"), spriteBatch8);
		this->mColorsBlink = EntityManager::create(100, Entity::create("egg light.png", 9, 1), spriteBatch2);
		this->mTasksBackground = EntityManager::create(10, Entity::create("task-background@2x.png"), spriteBatch8);
		this->mColorsSmall = EntityManager::create(10, Entity::create("colors_small@2x.png", 7, 1), spriteBatch8);
		this->mKeys = EntityManager::create(5, KeyDisplay::create(), spriteBatch4);
		this->mKeysLights = EntityManager::create(10, Entity::create("get_coins_light@2x.png"), spriteBatch99);
		this->mShootsDecorations = EntityManager::create(10, Entity::create("move_circle@2x.png"), spriteBatch8, 10);
        
        this->mTaskTimeIcon = Entity::create("game_panel_time_star@2x.png", spriteBatch8);
        this->mTaskShootsIcon = Entity::create("game_panel_shoot_count@2x.png", spriteBatch8);

		//this->mLevelUpText = Text::create(Options::TEXT_GAME_CLASSIC_LEVEL_UP, this);
		//this->mBonusTimeText = Text::create(Options::TEXT_GAME_CLASSIC_BONUS_TIME, this);

		this->mEventPanel = EventPanel::create(this);

        this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

		#if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID && CC_TARGET_PLATFORM != CC_PLATFORM_MAC
		if(Options::DEVICE_TYPE != Options::DEVICE_TYPE_IPOD4)
		{
			this->mBackgroundLights[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(480), Options::CAMERA_CENTER_Y - Utils::coord(50));
			for(int i = 1; i < 4; i++)
			{
				this->mBackgroundLights[i]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(480), Options::CAMERA_CENTER_Y + Utils::coord(50) * (i - 1));
			}
			for(int i = 1; i < 4; i++)
			{
				this->mBackgroundLights[i + 3]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(480), Options::CAMERA_CENTER_Y + Utils::coord(50) * (i - 1));
			}
		}
		#endif

		((Entity*) this->mEventPanel)->create()->setCenterPosition(Options::CAMERA_CENTER_X, -Utils::coord(100));

		this->mPauseButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(32), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2 + Utils::coord(1));

		this->mGameStartText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
		//this->mLevelUpText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(400));
		//this->mLevelUpText->setOpacity(0);
		//this->mBonusTimeText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(400));
		//this->mBonusTimeText->setOpacity(0);

		this->e4[0] = Entity::create("box_laser_green@2x.png", spriteBatch7);
		this->e4[1] = Entity::create("box_laser_red@2x.png", spriteBatch7);
		this->e4[2] = Entity::create("box_laser_green@2x.png", spriteBatch7);
		this->e4[3] = Entity::create("box_laser_red@2x.png", spriteBatch7);
		this->e4[4] = Entity::create("box_laser_green@2x.png", spriteBatch7);
		this->e4[5] = Entity::create("box_laser_red@2x.png", spriteBatch7);
		this->e4[6] = Entity::create("box_laser_green@2x.png", spriteBatch7);
		this->e4[7] = Entity::create("box_laser_red@2x.png", spriteBatch7);
    
		this->e4[0]->setAnchorPoint(ccp(0.5, 0));
		this->e4[1]->setAnchorPoint(ccp(0.5, 1));
		this->e4[2]->setAnchorPoint(ccp(0.5, 1));
		this->e4[3]->setAnchorPoint(ccp(0.5, 0));
		this->e4[4]->setAnchorPoint(ccp(0.5, 0));
		this->e4[5]->setAnchorPoint(ccp(0.5, 1));
		this->e4[6]->setAnchorPoint(ccp(0.5, 1));
		this->e4[7]->setAnchorPoint(ccp(0.5, 0));
    
		this->e1 = Entity::create("freeze_bg.png", spriteBatch7);
		this->e3[0] = Entity::create("box@2x.png", spriteBatch7);
		this->e3[1] = Entity::create("box@2x.png", spriteBatch7);
		this->e3[2] = Entity::create("box@2x.png", spriteBatch7);
		this->e3[3] = Entity::create("box@2x.png", spriteBatch7);
    
		this->e4[4]->setRotation(-90);
		this->e4[5]->setRotation(-90);
		this->e4[6]->setRotation(-90);
		this->e4[7]->setRotation(-90);
    
		this->e3[1]->setScaleY(-1);
		this->e3[2]->setScaleX(-1);
		this->e3[2]->setScaleY(-1);
		this->e3[3]->setScaleX(-1);
    
		this->mRobotParts = EntityManager::create(8, RobotoPart::create(0), spriteBatch7);
		this->mGunLaser = Entity::create("gun_laser.png", 4, 1, spriteBatch7);
		this->mGun = RobotoGun::create(spriteBatch7);
    
		this->mGunLaser->setAnchorPoint(ccp(0.5, 1));
		this->mGunLaser->animate(0.04);
    
		this->mRains = EntityManager::create(300, Rain::create(), spriteBatch7);
		this->mRainsCircles = EntityManager::create(300, RainCircle::create(), spriteBatch7);
    
		this->mPausePopup = Pause::create(this);
		this->mEndScreen = End::create(Splash::TYPE_PROGRESS, this);
		this->mGetLivesPopup = GetLives::create(this, false);
		this->mGetShootsPopup = GetShoots::create(this);
    
		//this->mLevelUpTime = 30.0;
		//this->mLevelUpTimeElapsed = 0;
    
		//this->mLevelUpAnimationTime = 4.0;
		//this->mLevelUpAnimationTimeElapsed = 0;
    
		//this->mChalangeTime = 90.0 - 1.0;
		//this->mChalangeTimeElapsed = 0;
    
		this->mAlgorithmBirdsRemainig = 5;
		this->mAlgorithmBirdsTime = 1.5;
    
		this->mAlgorithmBirdsTime1 = 1.0;
		this->mAlgorithmBirdsTime2 = 1.0;
    
		//this->mIsLevelUpAnimation = false;
    
		this->addChild(this->mEventLayer);
		//this->addChild(new Grid());
        
        this->mAwesoneAnimation = false;
    
		//
    
		//mSpecialBirdsTime = 20000;
		//mCoinsBirdTime = 20000;
        
		this->mTime = 0;
		this->mStarTime = 0;
        
		if(AppDelegate::isGetWindeScreen())
        {
            this->mBackground->setScale(1.185);
        }

		AppDelegate::clearCache();
	}

Progresses* Progresses::create()
{
    Progresses* screen = new Progresses();
    screen->autorelease();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Progresses::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_GAME_PAUSE:

                    this->mPausePopup->show();

                break;
                case Options::BUTTONS_ID_GAME_GET_LIVES:
                    
                    this->mGetLivesPopup->show();
                    
                break;
                case Options::BUTTONS_ID_GAME_RESTART:

                    this->mGetShootsPopup->show();

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

void Progresses::onMatch(int count, float a, float b)
{
    if(count >= 4) Game::EGGS_4_COUNT++;
    
    this->mAwesomeText->setString(Options::TEXT_BONUS[Utils::random(0, 11)].string);
    this->mAwesomeText->setScale(0);
    this->mAwesomeText->setColor(Confetti::CONFETTI_COLORS[Utils::random(0, 2)]);
    this->mAwesomeText->runAction(CCScaleTo::create(0.5, 1.0));
    this->mAwesomeText->setCenterPosition(a, b);
    
    this->mAwesomeText->runAction(CCRepeat::create(CCSequence::create(CCRotateTo::create(0.1, -5), CCRotateTo::create(0.1, 5), CCRotateTo::create(0.1, 0), NULL), 5));
    
    this->mAwesoneAnimation = true;
    this->mAwesoneAnimationTimeElapsed = 0;
}

void Progresses::onBonus(int pId, float pX, float pY)
{
    
}

void Progresses::onTaskComplete()
{
    if(this->mTaskDone) return;
    
    /*STARS++;
    
    if(this->mStarTime > 0)
    {
        STARS++;
    }*/
    
    this->mTaskDone = true;
}

void Progresses::draw()
{
    Game::draw();
}

void Progresses::update(float pDeltaTime)
{
    Game::update(pDeltaTime);
    
    if(Game::mShouldShowEndScreen)
    {
        if(this->mAwesomeText->getScaleX() <= 0)
        {
            Game::mShouldShowEndScreen = false;
            
            this->onGameEnd();
        }
    }
    
    this->mShootsCountAnimationTimeElapsed += pDeltaTime;
    
    if(this->mShootsCountAnimationTimeElapsed >= 1.0)
    {
        this->mShootsCountAnimationTimeElapsed = 0;
        
        Entity* circle = static_cast<Entity*>(this->mShootsDecorations->create());
        
        circle->setCenterPosition(this->mPanelText0->getCenterX(), this->mPanelText0->getCenterY());
        circle->setOpacity(255);
        circle->setScale(0);
        circle->setRotation(0);
        circle->runAction(CCScaleTo::create(2.0, 1.5));
        circle->runAction(CCFadeOut::create(2.0));
        circle->runAction(CCRotateTo::create(2.0, 720));
        
        for(int i = 0; i < this->mShootsDecorations->getCount(); i++)
        {
            Entity* entity = static_cast<Entity*>(this->mShootsDecorations->objectAtIndex(i));
            
            if(entity->getOpacity() <= 0)
            {
                entity->destroy();
            }
        }
    }
    
    if(this->mPause || this->mEndScreen->isShowed())
    {
        return;
    }
    
    if(this->mAwesoneAnimation)
    {
        this->mAwesoneAnimationTimeElapsed += pDeltaTime;
        
        if(this->mAwesoneAnimationTimeElapsed >= 1.0)
        {
            this->mAwesoneAnimation = false;
            
            this->mAwesomeText->runAction(CCScaleTo::create(0.5, 0));
        }
    }
    
    /*this->mNewColorsTimeElapsed += pDeltaTime;
    
    if(this->mNewColorsTimeElapsed >= 15.0)
    {
        this->mNewColorsTimeElapsed = 0;
        
        if(!this->mTaskDone)
        for(int i = Game::MATRIX_SIZE_X - 1; i >= 0; i--)
        {
         int y = 0;
         
         for(int j = Game::MATRIX_SIZE_Y - 1; j >= 0; j--)
         {
            if(MATRIX[i][j] == -1 && Utils::probably(50))
            {
             Color* color = static_cast<Color*>(this->mColors->create());
         
             color->setCurrentFrameIndex(Utils::random(0, LEVEL_COLORS[LEVEL] - 1));
             color->mType = color->getCurrentFrameIndex();

             color->setCenterPositionWithCorrection(Utils::coord(64) * i, Utils::coord(81) * y);
            }
         
             y++;
            }
         }
    }*/
    
    if(this->mGamePaused) // Is that is really need here?
    {
        if(!this->mEndScreen->isShowed())
        {
            this->onShow();

            this->startGame();
        }
    }
    if(this->mGameRunning && !this->mGamePaused)
    {
        this->mTime -= pDeltaTime;
        /*this->mStarTime -= pDeltaTime;
        
        if(this->mStarTime <= 0)
        {
            this->mStarTime = 0;
        }
    
        if(this->mTime <= 0 || (this->mColors->getCount() <= 0 && this->mTaskDone))
        {
            this->onGameEnd();
        }*/
        
        this->lookAtTheTasks();
        
        if(this->mShootCount <= 0 && !Color::ANIMATION_RUNNING)
        {
            this->mGetShootsPopup->show();
        }
        
        if(this->mMustShowTask)
        {
            this->onShow();
            
            this->startGame();
        }
    }
    
    /*int a;
    int b;
    
    const char* str = 0;
    
    a = (int)(this->mTime / 60);
    b = (int)(this->mTime - (int)(this->mTime / 60) * 60);
    
    if(a < 10) str = "0%d:%d";
    if(b < 10) str = "%d:0%d";
    if(a < 10 && b < 10) str = "0%d:0%d";
    if(a >= 10 && b >= 10) str = "%d:%d";
    
    this->mPanelText0->setString(ccsf(str, a, b));
    
    a = (int)(this->mStarTime / 60);
    b = (int)(this->mStarTime - (int)(this->mStarTime / 60) * 60);
    
    if(a < 10) str = "0%d:%d";
    if(b < 10) str = "%d:0%d";
    if(a < 10 && b < 10) str = "0%d:0%d";
    if(a >= 10 && b >= 10) str = "%d:%d";
    
    this->mPanelText1->setString(ccsf(str, a, b));
    
    this->mPanelText0->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidth() / 2 - this->mPanelText0->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    this->mPanelText1->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidth() / 2 - this->mPanelText1->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);*/
    
    int c = 0;
    bool complete = true;
    for(int i = 0; i < 10; i += 2)
    {
        if(TASK[Game::LEVEL][i] != 0)
        {
            Entity* background = static_cast<Entity*>(this->mTasksBackground->objectAtIndex(c));
            
            this->mTaskText[c]->setString(ccsf("%d/%d", BURNED[TASK[Game::LEVEL][i] - 1], TASK[Game::LEVEL][i + 1]));
            this->mTaskText[c]->setCenterPosition(background->getCenterX() + background->getWidth() / 2 - this->mTaskText[c]->getWidth() / 2 - Utils::coord(10), background->getCenterY());
            
            if(BURNED[TASK[Game::LEVEL][i] - 1] >= TASK[Game::LEVEL][i + 1])
            {
                this->mTaskText[c]->setColor(ccc3(0, 255, 0));
            }
            else
            {
                this->mTaskText[c]->setColor(ccc3(255, 255, 255));
                
                complete = false;
            }
            
            c++;
        }
    }
    
    if(complete)
    {
        this->onTaskComplete();
    }
}

void Progresses::onGameStarted()
{
    BEST_COUNT = AppDelegate::getBestResult(0);

    this->mColors->clear();
    
    //this->mTime = 60.0;
    //this->mStarTime = 60.0;
    
    /*for(int i = Game::MATRIX_SIZE_X - 1; i >= 0; i--)
    {
        int y = 0;
        
        for(int j = Game::MATRIX_SIZE_Y - 1; j >= 0; j--)
        {
            if(MATRIX[i][j] == -1 && Utils::probably(50))
            {
                Color* color = static_cast<Color*>(this->mColors->create());
                
                color->setCurrentFrameIndex(Utils::random(0, LEVEL_COLORS[LEVEL] - 1));
                color->mType = color->getCurrentFrameIndex();
                
                color->setCenterPositionWithCorrection(Utils::coord(64) * i, Utils::coord(81) * y);
            }
            
            y++;
        }
    }*/
    
    this->standStartEggs();
}

void Progresses::onGameEnd()
{
    if(this->mGetShootsPopup->getParent()) return;

    if(!this->mTaskDone)
    {
        STARS = 0;
    }
    else
    {
        if(this->mColors->getCount() <= 0)
        {
            //STARS++;
        }
    }
    
    this->mGamePaused = true;

    this->mEndScreen->show();

    if(BEST_COUNT > AppDelegate::getBestResult(0))
    {
        AppDelegate::setBestResult(BEST_COUNT, 0);
    }
    
    if(STARS <= 0)
    {
        AppDelegate::removeCoins(1, Options::SAVE_DATA_COINS_TYPE_LIVES);
    }
}

void Progresses::onBirBlow(int pType, float pX, float pY, bool pBonus)
{
    if(this->mGameRunning)
    {
        if(pType == Bird::TYPE_DANGER || pType == Bird::TYPE_FLAYER || pBonus || pType < 0)
        {
            
        }
        else
        {
            Color* color = static_cast<Color*>(this->mColors->create());
            
            color->setCurrentFrameIndex(pType);
            color->mType = pType;
            
            color->setCenterPositionWithCorrection(pX, pY);
            
            for(int i = 0; i < 30; i++)
            {
                Entity* particle = this->mColorsParticles->create();
                
                particle->setCenterPosition(color->getCenterX(), color->getCenterY());
                particle->setColor(Bird::COLORS[pType]);
            }
        }
        
        this->mShootMakeCount++;
        
        this->mPanelText0->setString(ccsf("%d", --this->mShootCount));
        this->mPanelText0->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidthScaled() / 2 - this->mPanelText0->getWidth() / 2 - Utils::coord(40), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    }
}

void Progresses::onEnter()
{
    Game::onEnter();
    
    this->onShow();
    
    GAME_TYPE = GAME_TYPE_PROGRESS;
}

void Progresses::onExit()
{
    Game::onExit();
}

void Progresses::onShow()
{
    STARS = 0;
    Game::EGGS_4_COUNT = 0;
    
    this->mAwesomeText->stopAllActions();
    this->mAwesomeText->setScale(0);

    this->mTime = 0;
    this->mStarTime = 0;

    this->mColors->clear();
    this->mSchematicBig->clear();
    this->mSchematicSmall->clear();
    this->mTasksBackground->clear();
    this->mColorsSmall->clear();

    this->mTaskDone = false;
    this->mMustShowTask = true;

    if(this->mTaskTimeIcon->isVisible()) this->mTaskTimeIcon->destroy();
    if(this->mTaskShootsIcon->isVisible()) this->mTaskShootsIcon->destroy();
    
    for(int i = 0; i < 10; i++)
    {
        BURNED[i] = 0;
    }

    for(int i = 0; i < 5; i++)
    {
        this->mTaskText[i]->setVisible(false);
    }
    
    this->setGamePanelTopLevelIcons();

    if(AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES) <= 0)
    {
        this->mGetLivesPopup->show();
        
        return;
    }

    this->mMustShowTask = false;
    
    this->mTaskPanel->up();

    for(int i = Game::MATRIX_SIZE_X - 1; i >= 0; i--)
    {
        int c = 0;
        
        for(int j = Game::MATRIX_SIZE_Y - 1; j >= 0; j--)
        {
            if(c < LEVEL_HEIGHT[LEVEL])
            {
                switch(LEVEL)
                {
                    default:
                        MATRIX[i][j] = -1;
                    break;
                    case 0:
                        MATRIX[i][j] = -1;
                        break;
                    case 1:
                        MATRIX[i][j] = -1;
                    break;
                    case 2:
                        MATRIX[i][j] = -1;
                        MATRIX[6][Game::MATRIX_SIZE_Y - 2] = -1;
                        MATRIX[7][Game::MATRIX_SIZE_Y - 2] = -1;
                        MATRIX[8][Game::MATRIX_SIZE_Y - 2] = -1;
                    break;
                    case 3:
                        MATRIX[i][j] = -1;
                    break;
                    case 4:
                        MATRIX[i][j] = -1;
                    break;
                    case 5:
                        if(c == LEVEL_HEIGHT[LEVEL] - 1)
                        {
                            if(i == 0 || i == MATRIX_SIZE_X - 1)
                            {
                                MATRIX[i][j] = -2;
                            }
                            else
                            {
                                MATRIX[i][j] = -1;
                            }
                        }
                        else
                        {
                            MATRIX[i][j] = -1;
                        }
                    break;
                }
            }
            else
            {
                MATRIX[i][j] = -2;
            }
            
            c++;
        }
    }
    
    int c2 = -1;
    int c = -1;

    for(int i = Game::MATRIX_SIZE_X - 1; i >= 0; i--)
    {
        int y = 0;

        c2++;
        c = c2;

        for(int j = Game::MATRIX_SIZE_Y - 1; j >= 0; j--)
        {
            if(MATRIX[i][j] >= -1)
            {
                Entity* big = this->mSchematicBig->create();
                big->setCenterPosition(Utils::coord(64) * i + Utils::coord(32) + Utils::coord(8), Utils::coord(81) * y + Utils::coord(40) + Utils::coord(15));
                
                Entity* small1 = this->mSchematicSmall->create();
				small1->setCenterPosition(Utils::coord(64) * i + Utils::coord(32) + Utils::coord(8), Utils::coord(81) * y + Utils::coord(40) + Utils::coord(15));
				small1->setCurrentFrameIndex(c);
            }

            y++;
            c++;
            
            if(c == 2) c = 0;
        }
        
        if(c2 == 1) c2 = -1;
    }
    
    this->mPause = true;
    
    this->setGamePanelTopLevelIcons();
    this->setGamePanelLeftLevelIcons();
}

void Progresses::removeLife()
{
    
}

void Progresses::startGame()
{
    Game::startGame();
}

void Progresses::setGamePanelTopLevelIcons()
{
    this->mShootCount = Game::LEVEL_SHOOT_COUNT[Game::LEVEL];
    this->mShootMakeCount = 0;
    
    this->mPanelStars[0]->setColor(ccc3(255, 255, 255));
    this->mPanelStars[1]->setColor(ccc3(255, 255, 255));
    this->mPanelStars[2]->setColor(ccc3(255, 255, 255));
    
    this->mPanelText0->setString(ccsf("%d", this->mShootCount));
    this->mPanelText0->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidthScaled() / 2 - this->mPanelText0->getWidth() / 2 - Utils::coord(40), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mPanelText1->setString("0"); // O_o :)
    this->mPanelText1->setCenterPosition(this->mTextAreas[1]->getCenterX() + this->mTextAreas[1]->getWidthScaled() / 2 - this->mPanelText1->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mPanelText2->setString(ccsf("%d", AppDelegate::getCoins(Options::SAVE_DATA_COINS_TYPE_LIVES)));
    this->mPanelText2->setCenterPosition(this->mTextAreas[2]->getCenterX() + this->mTextAreas[2]->getWidthScaled() / 2 - this->mPanelText2->getWidth() / 2 - Utils::coord(40), Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
    
    this->mPanelStars[0]->setCurrentFrameIndex(3);
    this->mPanelStars[1]->setCurrentFrameIndex(4);
    this->mPanelStars[2]->setCurrentFrameIndex(5);
}

void Progresses::setGamePanelLeftLevelIcons()
{
    if(this->mTaskTimeIcon->isVisible()) this->mTaskTimeIcon->destroy();
    if(this->mTaskShootsIcon->isVisible()) this->mTaskShootsIcon->destroy();
    
    int c = 0;
    for(int i = 0; i < 10; i += 2)
    {
        if(TASK[Game::LEVEL][i] != 0)
        {
            Entity* background = this->mTasksBackground->create();
            Entity* color = this->mColorsSmall->create();
            
            background->setCenterPosition(background->getWidth() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);
            color->setCenterPosition(background->getCenterX() - background->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);
            color->setCurrentFrameIndex(TASK[Game::LEVEL][i] - 1);
            
            this->mTaskText[c]->setVisible(true);
            this->mTaskText[c]->setCenterPosition(background->getCenterX() + background->getWidth() / 2 - this->mTaskText[c]->getWidth() / 2 - Utils::coord(10), background->getCenterY());
            
            c++;
        }
    }
    
    switch(Game::LEVEL)
    {
        case 0:
        {
            Entity* background = this->mTasksBackground->create();
            background->setCenterPosition(background->getWidth() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);

            this->mTaskTimeIcon->create()->setCenterPosition(background->getCenterX() - background->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);

            this->mTime = 20;
            this->mTaskText[c]->setString("0:20");
            this->mTaskText[c]->setColor(ccc3(255, 255, 255));
            this->mTaskText[c]->setVisible(true);
            this->mTaskText[c]->setCenterPosition(background->getCenterX() + background->getWidth() / 2 - this->mTaskText[c]->getWidth() / 2 - Utils::coord(10), background->getCenterY());

            c++;

            background = this->mTasksBackground->create();
            background->setCenterPosition(background->getWidth() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);

            this->mTaskShootsIcon->create()->setCenterPosition(background->getCenterX() - background->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);
            this->mTaskShootsIcon->setScale(0.7);
            this->mTaskText[c]->setString("1");
            this->mTaskText[c]->setColor(ccc3(255, 255, 255));
            this->mTaskText[c]->setVisible(true);
            this->mTaskText[c]->setCenterPosition(background->getCenterX() + background->getWidth() / 2 - this->mTaskText[c]->getWidth() / 2 - Utils::coord(10), background->getCenterY());
        }
        break;
            
        case 1:
        {
            Entity* background = this->mTasksBackground->create();
            background->setCenterPosition(background->getWidth() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);
            
            //this->mTaskTimeIcon->create()->setCenterPosition(background->getCenterX() - background->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);
            
            this->mTaskText[c]->setString("0/1");
            this->mTaskText[c]->setColor(ccc3(255, 255, 255));
            this->mTaskText[c]->setVisible(true);
            this->mTaskText[c]->setCenterPosition(background->getCenterX() + background->getWidth() / 2 - this->mTaskText[c]->getWidth() / 2 - Utils::coord(10), background->getCenterY());
            
            c++;
            
            background = this->mTasksBackground->create();
            background->setCenterPosition(background->getWidth() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);
            
            //this->mTaskShootsIcon->create()->setCenterPosition(background->getCenterX() - background->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);
            //this->mTaskShootsIcon->setScale(0.7);
            this->mTaskText[c]->setString("0/1");
            this->mTaskText[c]->setColor(ccc3(255, 255, 255));
            this->mTaskText[c]->setVisible(true);
            this->mTaskText[c]->setCenterPosition(background->getCenterX() + background->getWidth() / 2 - this->mTaskText[c]->getWidth() / 2 - Utils::coord(10), background->getCenterY());
        }
            break;
            
        case 2:
        {
            Entity* background = this->mTasksBackground->create();
            background->setCenterPosition(background->getWidth() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);
            
            //this->mTaskTimeIcon->create()->setCenterPosition(background->getCenterX() - background->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);
            
            this->mTaskText[c]->setString("0/1");
            this->mTaskText[c]->setColor(ccc3(255, 255, 255));
            this->mTaskText[c]->setVisible(true);
            this->mTaskText[c]->setCenterPosition(background->getCenterX() + background->getWidth() / 2 - this->mTaskText[c]->getWidth() / 2 - Utils::coord(10), background->getCenterY());

            c++;

            background = this->mTasksBackground->create();
            background->setCenterPosition(background->getWidth() / 2 + Utils::coord(30), Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);

            this->mTaskTimeIcon->create()->setCenterPosition(background->getCenterX() - background->getWidth() / 2, Options::CAMERA_HEIGHT - Utils::coord(100) - Utils::coord(40) * c);
            
            this->mTime = 60;
            this->mTaskText[c]->setString("0:60");
            this->mTaskText[c]->setColor(ccc3(255, 255, 255));
            this->mTaskText[c]->setVisible(true);
            this->mTaskText[c]->setCenterPosition(background->getCenterX() + background->getWidth() / 2 - this->mTaskText[c]->getWidth() / 2 - Utils::coord(10), background->getCenterY());
        }
            break;
    }
}

void Progresses::checkStarsRuntime()
{
    
    switch(Game::LEVEL)
    {
        case 0:
            if(this->mTaskDone) {
                STARS++;
                if(this->mTime > 0) STARS++;
                if(this->mShootMakeCount <= 1) STARS++;
                
                Game::mShouldShowEndScreen = true;
            }
            if(this->mTaskDone) { this->mPanelStars[0]->setCurrentFrameIndex(0); if(this->mTime <= 0) { this->mPanelStars[1]->setCurrentFrameIndex(1); } }
            if(this->mTime <= 0) { this->mPanelStars[1]->setColor(ccc3(100, 100, 100)); this->mTaskText[1]->setColor(ccc3(255, 0, 0)); }
            if(this->mShootMakeCount > 1) { this->mPanelStars[2]->setColor(ccc3(100, 100, 100)); this->mTaskText[2]->setColor(ccc3(255, 0, 0)); }
            break;
        case 1:
            if(this->mTaskDone) {
                if(this->mShootCount <= 0 || (Game::EGGS_4_COUNT > 0 && this->mColors->getCount() <= 0))
                {
                    STARS++;
                    if(Game::EGGS_4_COUNT > 0) STARS++;
                    if(this->mColors->getCount() <= 0) STARS++;

                    Game::mShouldShowEndScreen = true;
                }
            }
            if(this->mTaskDone) { this->mPanelStars[0]->setCurrentFrameIndex(0); }
            if(Game::EGGS_4_COUNT > 0) { this->mPanelStars[1]->setCurrentFrameIndex(1); this->mTaskText[1]->setColor(ccc3(0, 255, 0)); }
            if(this->mTaskDone) if(this->mColors->getCount() <= 0) { this->mPanelStars[2]->setCurrentFrameIndex(2); this->mTaskText[2]->setColor(ccc3(0, 255, 0)); }
            break;
        case 2:
            if(this->mTaskDone && Game::EGGS_4_COUNT > 0) {
                STARS++;
                if(this->mTime > 0) STARS++;
                if(Game::EGGS_4_COUNT > 0) STARS++;
                
                Game::mShouldShowEndScreen = true;
            }
            if(this->mTaskDone) { this->mPanelStars[0]->setCurrentFrameIndex(0); if(this->mTime <= 0) { this->mPanelStars[1]->setCurrentFrameIndex(1); } }
            if(Game::EGGS_4_COUNT > 0) { this->mPanelStars[1]->setCurrentFrameIndex(1); this->mTaskText[2]->setColor(ccc3(0, 255, 0)); }
            if(this->mTime <= 0) { this->mPanelStars[2]->setColor(ccc3(100, 100, 100)); this->mTaskText[3]->setColor(ccc3(255, 0, 0)); }
            break;
    }
}

void Progresses::lookAtTheTasks()
{
    if(!Game::mShouldShowEndScreen) this->checkStarsRuntime();
    
    switch(Game::LEVEL)
    {
        case 0:
            if(this->mTime >= 0)
            {
             int a;
             int b;
             
             const char* str = 0;
             
             a = (int)(this->mTime / 60);
             b = (int)(this->mTime - (int)(this->mTime / 60) * 60);
             
             if(a < 10) str = "0%d:%d";
             if(b < 10) str = "%d:0%d";
             if(a < 10 && b < 10) str = "0%d:0%d";
             if(a >= 10 && b >= 10) str = "%d:%d";
             
             this->mTaskText[1]->setString(ccsf(str, a, b));
             //this->mTaskText[1]->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidth() / 2 - this->mPanelText0->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
            }
            break;
        case 1:
            break;
        case 2:
            if(this->mTime >= 0)
            {
                int a;
                int b;
                
                const char* str = 0;
                
                a = (int)(this->mTime / 60);
                b = (int)(this->mTime - (int)(this->mTime / 60) * 60);
                
                if(a < 10) str = "0%d:%d";
                if(b < 10) str = "%d:0%d";
                if(a < 10 && b < 10) str = "0%d:0%d";
                if(a >= 10 && b >= 10) str = "%d:%d";
                
                this->mTaskText[3]->setString(ccsf(str, a, b));
                //this->mTaskText[1]->setCenterPosition(this->mTextAreas[0]->getCenterX() + this->mTextAreas[0]->getWidth() / 2 - this->mPanelText0->getWidth() / 2, Options::CAMERA_HEIGHT - this->mGamePanel->getHeight() / 2);
            }
            break;
    }
}

void Progresses::standStartEggs()
{
    
    switch(Game::LEVEL)
    {
        case 0:
            Color* color;
            color = static_cast<Color*>(this->mColors->create());
            color->setCenterPositionWithCorrection(Options::CAMERA_CENTER_X - Utils::coord(64), Utils::coord(81));
            color = static_cast<Color*>(this->mColors->create());
            color->setCenterPositionWithCorrection(Options::CAMERA_CENTER_X + Utils::coord(64), Utils::coord(81));
            break;
    }
}

void Progresses::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    if(this->mGetShootsPopup->getParent())
    {
        this->mGetShootsPopup->hide();
    }
    if(this->mGetLivesPopup->getParent())
    {
        this->mGetLivesPopup->hide();
    }
    else
    {
        if(this->mPausePopup->getParent())
        {
            this->mPausePopup->hide();
        }
        else
        {
            this->mPausePopup->show();
        }
    }
}

#endif