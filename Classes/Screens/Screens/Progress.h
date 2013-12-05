#ifndef CONST_PROGRESS_H
#define CONST_PROGRESS_H

#include "Screen.h"

#include "ResetProgress.h"

#include "AppDelegate.h"

class Progress : public Screen
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================
    
        class Dark : public CCNodeRGBA, public Touchable
        {
        public:
            Dark()
            {
                this->setColor(ccc3(0, 0, 0));
                this->setOpacity(50);
            }
        
            static Dark* create()
            {
                Dark* background = new Dark();
                background->autorelease();
            
                return background;
            }
        
            void draw()
            {
                if(this->getOpacity() <= 0) return;
            
                #if CC_TARGET_PLATFORM != CC_PLATFORM_WINRT
                glLineWidth(1);
                #endif
            
                CCPoint filledVertices[] = { ccp(0,0), ccp(0,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH, 0)};
                ccDrawSolidPoly(filledVertices, 4, ccc4f(this->getColor().r, this->getColor().g, this->getColor().b, this->getOpacity() / 255.0) );
            }
            
            void setOpacity(GLubyte opaquee)
            {
                CCNodeRGBA::setOpacity(opaquee);
                
                if(opaquee <= 0)
                {
                    CCDirector* pDirector = CCDirector::sharedDirector();
                    pDirector->getTouchDispatcher()->removeDelegate((Touchable*) this);
                    
                    this->setRegisterAsTouchable(false);
                }
                else
                {
                    if(!this->isRegisteredAsTouchable())
                    {
                        CCDirector* pDirector = CCDirector::sharedDirector();
                        pDirector->getTouchDispatcher()->addTargetedDelegate((Touchable*) this, 0, true);
                        
                        this->setRegisterAsTouchable(true);
                    }
                }
            }
        };

        // ===========================================================
        // Constants
        // ===========================================================
    
        // ===========================================================
        // Fields
        // ===========================================================
    
        Entity* mBackground;
        Entity* mBackButton;
    
        Button* mResetButton;
    
        Popup* mResetPopup;
    
        Dark* mDark;
    
        float mResetAnimationTimeElapsed;
    
        bool mResetAnimationRunning;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Progress();

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

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================

        static Progress* create();
        
        ~Progress();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void reset();
        void onReset();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        void keyBackClicked(bool pSound);
    
        void onEnter();
        void onExit();
};

#endif