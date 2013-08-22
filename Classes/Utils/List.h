#ifndef CONST_LIST_H
#define CONST_LIST_H

#include "cocos2d.h"

#include "Entity.h"

#include "Popup.h"

#include "Utils.h"

using namespace cocos2d;

class List : public CCLayer
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
    
        int mType;
        int mParentType;

        float mWidth;
        float mHeight;

        float mMaxWidth;
        float mMaxHeight;

        float mListInitialCenterX;
        float mListInitialCenterY;

        float mStartCoordinateY;
        float mStartCoordinateX;

        float mStartPositionCoordinateY;
        float mStartPositionCoordinateX;

        float mLastDistanceX;
        float mLastDistanceY;

        float mSpeedX;
        float mSpeedY;
    
        bool mPostUpdate;
    
        Entity* mListSroll;

        Entity* mParent;

        CCSpriteBatchNode* mSpriteBatch;

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================

        // ===========================================================
        // Override Methods
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

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================

    public:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static const int TYPE_HORIZONTAL = 0;
        static const int TYPE_VERTICAL = 1;
        static const int TYPE_BOTH = 2;

        static const int PARENT_TYPE_SIMPLE = 0;
        static const int PARENT_TYPE_POPUP = 1;

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        List(float pWidth, float pHeight, float pMaxWidth, float pMaxHeight, float pListInitialCenterX, float pListInitialCenterY, const char* pListTextureFileName, CCNode* pParent);
        ~List();

        // ===========================================================
        // Methods
        // ===========================================================

        void setListType(int pType);
        void setParentType(int pType);
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        virtual void onEnter();
        virtual void onExit();
    
        virtual void visit();
    
        virtual void update(float pDeltaTime);
    
        virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
        virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
        virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
    
        virtual bool containsTouchLocation(CCTouch* touch);

        virtual void draw();
};

#endif