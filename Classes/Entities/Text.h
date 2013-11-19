#ifndef CONST_TEXT_H
#define CONST_TEXT_H

#include "cocos2d.h"

#include "Utils.h"

using namespace cocos2d;

class Text : public CCLabelTTF
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
    
        bool mType1AnimationRunning;
        bool mType2AnimationRunning;
    
        int mType1AnimationCount;
        int mType2AnimationCount;
    
        float mType1AnimationTime;
        float mType2AnimationTime;
    
        float mType1AnimationTimeElapsed;
        float mType2AnimationTimeElapsed;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Text(Textes pParams, const CCSize pDimensions, CCNode* pParent);
        Text(const char* pString, float pSize, CCNode* pParent);
        Text(Textes pParams, CCNode* pParent);

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
    
        static int ID;
    
        static Text* TEXTES[512];

        // ===========================================================
        // Fields
        // ===========================================================
    
        int mId;
    
        float mInitCenterX;
        float mInitCenterY;
    
        CCLabelTTF* mShadow;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Text* create(Textes pParams, const CCSize pDimensions, CCNode* pParent);
        static Text* create(const char* pString, float pSize, CCNode* pParent);
        static Text* create(Textes pParams, CCNode* pParent);
        ~Text();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void setPosition(float pX, float pY);
        void setCenterPosition(float pCenterX, float pCenterY);
    
        void changeLanguage();

        float getWidth();
        float getHeight();

        float getCenterX();
        float getCenterY();

        void setText(Textes pParams);

        void enableShadow();
        void disableShadow();
    
        void animate(int pType);
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void onEnter();
        void onExit();
    
        void update(float pDeltaTime);
    
        void draw();
    
        void setString(const char* str);
        void setVisible(bool pVisible);
        void setScale(float pScale);
        void setOpacity(GLubyte pOpaquee);
        void runAction(CCAction* pAction);
};

#endif