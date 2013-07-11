#ifndef CONST_ENTITY_H
#define CONST_ENTITY_H

#include "cocos2d.h"

#include "Texture.h"
#include "Touchable.h"
#include "Utils.h"
#include "Options.h"
#include "SimpleAudioEngine.h"

using namespace std;
using namespace cocos2d;
using namespace CocosDenshion;

class EntityManager;
class BatchEntityManager;

class Entity : public CCSprite, public Touchable
{
	protected:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		// ===========================================================
		// Fields
		// ===========================================================

		int mFramesCount;

		int mHorizontalFramesCount;
		int mVerticalFramesCount;

		int mCurrentFrameIndex;

		int mAnimationStartFrame;
		int mAnimationFinishFrame;
		int mAnimationFramesElapsed;

		int mAnimationRepeatCount;

		int id;

		float mWidth;
		float mHeight;

		float mFrameWidth;
		float mFrameHeight;

		float* mFramesCoordinatesX;
		float* mFramesCoordinatesY;

		float mSpeed;

		float mPauseBeforeNewAnimationCircleTime;
		float mPauseBeforeNewAnimationCircleTimeElapsed;

		float mAnimationTime;
		float mAnimationTimeElapsed;

		float mAnimationStartTimeout;

		float mAnimationScaleDownTime;
		float mAnimationScaleUpTime;

		float mAnimationScaleDownFactor;
		float mAnimationScaleUpFactor;

		bool mIsAnimationReverse;
		bool mIsAnimationReverseNeed;

		bool mAnimationRunning;

		bool mWasTouched;

		const char* mTextureFileName;

		// ===========================================================
		// Constructors
		// ===========================================================

		// ===========================================================
		// Methods
		// ===========================================================

		// ===========================================================
		// Virtual Methods
		// ===========================================================

	private:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		// ===========================================================
		// Fields
		// ===========================================================
		
		EntityManager* mEntityManager;

		BatchEntityManager* mBatchEntityManager;

		// ===========================================================
		// Constructors
		// ===========================================================
		
		void constructor(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent);

		// ===========================================================
		// Methods
		// ===========================================================
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================

	public:
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

		Entity();
		Entity(const char* pszFileName);
		Entity(const char* pszFileName, CCNode* pParent);
		Entity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount);
		Entity(const char* pszFileName, int pHorizontalFramesCount, int pVerticalFramesCount, CCNode* pParent);

		// ===========================================================
		// Methods
		// ===========================================================

		int getEntityManagerId();
		int hasEntityManager();

		int getCurrentFrameIndex();
		
		float getWidth();
		float getHeight();
		
		float getWidthScaled();
		float getHeightScaled();

		float getCenterPosition();
		float getX();
		float getY();
		float getCenterX();
		float getCenterY();

		float getSpeed(float pDeltaTime);

		void setPosition(float pX, float pY);
		void setCenterPosition(float pCenterX, float pCenterY);
		void setX(float pX);
		void setY(float pY);

		void setSpeed(float pSpeed);

		bool destroy();
		bool destroy(bool pManage);

		void setEntityManager(EntityManager* pEntityManager);
		void setEntityManager(BatchEntityManager* pBatchEntityManager);

        EntityManager* getEntityManager();
        BatchEntityManager* getBatchEntityManager();
    
		void setEntityManagerId(int pId);

		virtual void setCurrentFrameIndex(int pIndex);

		void previousFrameIndex();
		void nextFrameIndex();

		void changeTexture(Texture* pTexture);
    
        void setRepeatTexture(bool pRepeat);

		void animate(float pAnimationTime);
		void animate(float pAnimationTime, int pRepeatCount);
		void animate(float pAnimationTime, int pRepeatCount, bool pNeedReverse);
		void animate(float pAnimationTime, float pPauseBeforeNewAnimationCircleTime);
		void animate(float pAnimationTime, int pRepeatCount, float pPauseBeforeNewAnimationCircleTime);
		void animate(float pAnimationTime, int pStartFrame, int pFinishFrame, int pRepeatCount);
		void animate(float pAnimationTime, int pStartFrame, int pFinishFrame);

		void setStartFrame(int pStartFrame);
		void setFinishFrame(int pFinishFrame);

		void setAnimationStartTimeout(float pSecodsTimeout);

		void onAnimationStart();
		void onAnimationEnd();
		void onAnimationCircleEnd();

		void ccTouchMoved(CCTouch* touch, CCEvent* event);
		void ccTouchEnded(CCTouch* touch, CCEvent* event);

		void onTouch(CCTouch* touch, CCEvent* event);

		virtual void onCreate();
		virtual void onDestroy();

		bool isAnimationRunning();

		bool ccTouchBegan(CCTouch* touch, CCEvent* event);

		bool containsTouchLocation(CCTouch* touch);

		virtual Entity* deepCopy();

		Entity* create();

		const char* getTextureFileName();
		
		// ===========================================================
		// Virtual Methods
		// ===========================================================

		virtual void onEnter();
		virtual void onExit();

		virtual void update(float pDeltaTime);
		virtual void draw();
};

#endif