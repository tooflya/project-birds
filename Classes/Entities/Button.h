#ifndef CONST_BUTTON_H
#define CONST_BUTTON_H

#include "cocos2d.h"

#include "Entity.h"
#include "Text.h"

#include "ButtonReceiver.h"

using namespace cocos2d;

class Button : public Entity
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

        int mID;

        ButtonReceiver* mSender;
    
        Text* mText;
    
        bool mIsModal;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, ButtonReceiver* pSender);
        Button(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, const int pButtonID, ButtonReceiver* pSender);
        Button(const EntityStructure pEntityStructure, CCNode* pParent, const int pButtonID, ButtonReceiver* pSender);

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

        void constructor(const int pButtonID, ButtonReceiver* pSender);
        
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

        // ===========================================================
        // Fields
        // ===========================================================

        static Button* create(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, CCNode* pParent, const int pButtonID, ButtonReceiver* pSender);
        static Button* create(const char* pTextureFileName, int pHorizontalFramesCount, int mVerticalFramesCount, const int pButtonID, ButtonReceiver* pSender);
        static Button* create(const EntityStructure pEntityStructure, CCNode* pParent, const int pButtonID, ButtonReceiver* pSender);
       
        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================

        virtual void onTouch(CCTouch* touch, CCEvent* event);

        void setText(Textes pParams);
        void setString(const char* pString);
        void setModal(bool pIsModal);
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        void update(float pDeltTime);
    
        void onEnter();
        void onExit();
    
        Button* deepCopy();
    
        Entity* create();
};

#endif