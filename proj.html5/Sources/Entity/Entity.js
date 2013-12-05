/**
 * Tooflya Inc. Development
 *
 * @author Igor Mats from Tooflya Inc.
 * @copyright (c) 2013 by Igor Mats
 *
 * @license http://opensource.org/licenses/gpl-license.php GNU Public License v2
 * @all rights granted under this License are granted for the term of
 * copyright on the Program, and are irrevocable provided the stated
 * conditions are met. This License explicitly affirms your unlimited
 * permission to run the unmodified Program. The output from running a
 * covered work is covered by this License only if the output, given its
 * content, constitutes a covered work. This License acknowledges your
 * rights of fair use or other equivalent, as provided by copyright law.
 *
 * @version
 *
 */

cc.Entity = cc.Sprite.extend({
    init:function() {
        //this.m_TextureFileName = this.getTexture().getTextureName();

        this.m_Width = this.getContentSize().width;
        this.m_Height = this.getContentSize().height;

        this.m_FrameWidth = this.m_Width / this.m_HorizontalFramesCount;
        this.m_FrameHeight = this.m_Height / this.m_VerticalFramesCount;

        this.m_FramesCount = this.m_HorizontalFramesCount * this.m_VerticalFramesCount;

        /**
         *
         * We must remember all coordinates of each frame
         * for quick get x and y of it.
         *
         */

        this.m_FramesCoordinatesX = new Array();
        this.m_FramesCoordinatesY = new Array();

        var counter = 0;

        for(var i = 0; i < this.m_VerticalFramesCount; i++) {
            for(var j = 0; j < this.m_HorizontalFramesCount; j++, counter++) {
                this.m_FramesCoordinatesX[counter] = j * (this.m_Width / this.m_HorizontalFramesCount);
                this.m_FramesCoordinatesY[counter] = i * (this.m_Height / this.m_VerticalFramesCount);
            }
        }

        this.m_Percentage = 100;

        this.setCurrentFrameIndex(0);

        /**
         *
         *
         * Take care about an animations
         *
         */

        this.m_AnimationRunning = false;

        this.m_AnimationTime = 0;
        this.m_AnimationTimeElapsed = 0;

        this.m_AnimationStartTimeout = 0;

        this.m_PauseBeforeNewAnimationCircleTime = 0;
        this.m_PauseBeforeNewAnimationCircleTimeElapsed = 0;

        this.m_AnimationScaleDownTime = 0.2;
        this.m_AnimationScaleUpTime = 0.2;

        this.m_AnimationScaleDownFactor = 0.1;
        this.m_AnimationScaleUpFactor = 1.0;

        this.m_AnimationRepeatCount = -1;

        this.m_AnimationStartFrame = -1;
        this.m_AnimationFinishFrame = -1;

        this.m_AnimationFramesElapsed = 0;

        this.m_IsAnimationReverse = false;
        this.m_IsAnimationReverseNeed = false;

        this.m_TouchCallback = false;

        this.destroy();
    },
    initWithFilename:function(p_FileName, p_Parent) {
        this.initWithFile(p_FileName);

        this.m_HorizontalFramesCount = 1;
        this.m_VerticalFramesCount = 1;

        if(p_Parent) {
            p_Parent.addChild(this);
        }

        this.init();
    },
    initWithFrames:function(p_FileName, p_HorizontalFramesCount, p_VerticalFramesCount, p_Parent) {
        this.initWithFile(p_FileName);

        this.m_HorizontalFramesCount = p_HorizontalFramesCount;
        this.m_VerticalFramesCount = p_VerticalFramesCount;

        if(p_Parent) {
            p_Parent.addChild(this);
        }

        this.init();
    },

    create:function() {
        this.onCreate();

        return this;
    },
    destroy:function() {
        this.onDestroy();
    },

    onCreate:function() {
        this.setVisible(true);
    },
    onDestroy:function() {
        this.setVisible(false);
    },

    getSize:function() {
        return cc.Size(this.getWidth(), this.getHeight());
    },
    getSizeScaled:function() {
        return cc.Size(this.getWidthScaled(), this.getHeightScaled());
    },
    setSize:function(p_Width, p_Height) {
        this.setWidth(p_Width);
        this.setHeight(p_Height);
    },

    setWidth:function(p_Width) {
        this.m_Width = p_Width;
        this.m_FrameWidth = this.m_Width / this.m_HorizontalFramesCount;
    },
    setHeight:function(p_Height) {
        this.m_Height = p_Height;
        this.m_FrameHeight = this.m_Height / this.m_VerticalFramesCount;
    },
    getWidth:function() {
        return this.m_FrameWidth;
    },
    getHeight:function() {
        return this.m_FrameHeight;
    },
    getWidthScaled:function() {
        return this.m_FrameWidth * this.getScaleX();
    },
    getHeightScaled:function() {
        return this.m_FrameWidth * this.getScaleY();
    },

    getCurrentFrameIndex:function() {
        return this.m_CurrentFrameIndex;
    },
    setCurrentFrameIndex:function(p_Index) {
        cc.Utils.assert(this.m_FramesCount <= 1 && p_Index > 0, "Error in Entity class. Entity is using only one frame but want to switch their frame.");

        if(p_Index < this.m_HorizontalFramesCount * this.m_VerticalFramesCount && p_Index >= 0) {
            this.setTextureRect(cc.RectMake(this.m_FramesCoordinatesX[p_Index], this.m_FramesCoordinatesY[p_Index], (this.m_Width / this.m_HorizontalFramesCount) * this.m_Percentage / 100.0, this.m_Height / this.m_VerticalFramesCount));

            this.m_CurrentFrameIndex = p_Index;
        } else {
            this.setCurrentFrameIndex(0);
        }
    },

    previousFrameIndex:function() {
        var potencialNextFrame = this.getCurrentFrameIndex() - 1;

        this.setCurrentFrameIndex(potencialNextFrame > 0 ? potencialNextFrame : 0);
    },
    nextFrameIndex:function() {
        var potencialNextFrame = this.getCurrentFrameIndex() + 1;

        this.setCurrentFrameIndex(potencialNextFrame > this.mFramesCount ? 0 : potencialNextFrame);
    },

    getCenterX:function() {
        return this.getPosition().x;
    },
    getCenterY:function() {
        return this.getPosition().y;
    },
    setCenterPosition: function(pCenterX, pCenterY) {
        this.setPosition(cc.p(pCenterX, pCenterY));
    },

    showPercentage:function(p_Percentage) {
        this.m_Percentage = p_Percentage;
        
        this.setCurrentFrameIndex(this.getCurrentFrameIndex());
    },

    animate:function(p_AnimationTime, p_RepeatCount) {
        this.m_AnimationFramesElapsed = 0;
        this.m_AnimationRepeatCount = p_RepeatCount ? p_RepeatCount : -1;

        this.m_AnimationTimeElapsed = 0;
        this.m_AnimationTime = p_AnimationTime;

        this.m_AnimationRunning = true;

        this.onAnimationStart();
    },
    /*animate:function(p_AnimationTime, p_RepeatCount) {
        this.m_AnimationRepeatCount = p_RepeatCount;

        this.animate(pAnimationTime);
    },
    animate:function(p_AnimationTime, p_RepeatCount, p_ReverseNeed){
        this.m_IsAnimationReverseNeed = p_ReverseNeed;

        this.animate(p_AnimationTime, p_RepeatCount);
    },
    animate:function(p_AnimationTime, p_PauseBeforeNewAnimationCircleTime) {
        this.m_PauseBeforeNewAnimationCircleTime = p_PauseBeforeNewAnimationCircleTime;

        this.animate(p_AnimationTime);
    },
    animate:function(p_AnimationTime, p_RepeatCount, p_PauseBeforeNewAnimationCircleTime) {
        this.m_PauseBeforeNewAnimationCircleTime = p_PauseBeforeNewAnimationCircleTime;

        this.animate(p_AnimationTime, p_RepeatCount);
    },
    animate:function(p_AnimationTime, p_StartFrame, p_FinishFrame, p_RepeatCount) {
        this.animate(p_AnimationTime);

        this.m_AnimationStartFrame = p_StartFrame;
        this.m_AnimationFinishFrame = p_FinishFrame;

        this.m_AnimationRepeatCount = p_RepeatCount;

        this.setCurrentFrameIndex(p_StartFrame);
    },
    animate:function(p_AnimationTime, p_StartFrame, p_FinishFrame) {
        this.animate(p_AnimationTime, p_StartFrame, p_FinishFrame, -1);
    },
    animate:function(p_AnimationTime, p_StartFrame, p_FinishFrame, p_ReverseNeed) {
        this.animate(p_AnimationTime, p_StartFrame, p_FinishFrame, -1);

        this.m_IsAnimationReverseNeed = p_ReverseNeed;
        this.m_IsAnimationReverse = false;
    },*/

    onAnimationStart:function() {
    },
    onAnimationEnd:function() {
    },
    onAnimationCircleEnd:function() {
    },

    setAnimationStartTimeout:function(p_SecodsTimeout) {
        this.m_AnimationStartTimeout = p_SecodsTimeout;
    },

    setStartFrame:function(p_StartFrame) {
        this.m_AnimationFinishFrame = (this.m_AnimationFinishFrame - this.m_AnimationStartFrame) + p_StartFrame;
        this.m_AnimationStartFrame = p_StartFrame;
    },
    setFinishFrame:function(p_FinishFrame) {
        this.m_AnimationFinishFrame = p_FinishFrame;
    },

    isAnimationRunning:function() {
        return this.m_AnimationRunning;
    },

    stopAnimation:function() {
        this.setCurrentFrameIndex(0);

        this.m_AnimationRunning = false;
    },

    setRegisterAsTouchable:function(p_Touchable) {
        this.m_IsRegisterAsTouchable = p_Touchable;

        if(this.m_IsRegisterAsTouchable) {
            cc.Director.getInstance().getTouchDispatcher().addTargetedDelegate(this, 0, true); // TODO: Add modal view.
        } else {
            cc.Director.getInstance().getTouchDispatcher().removeDelegate(this);
        }
    },
    isRegisterAsTouchable:function() {
        return this.m_IsRegisterAsTouchable;
    },

    setTouchCallback:function(p_TouchCallback) {
        this.m_TouchCallback = p_TouchCallback;
    },

    containsTouchLocation:function(touch) {
        return cc.rectContainsPoint(cc.RectMake(this.getCenterX() - this.getWidth() / 2, this.getCenterY() - this.getHeight() / 2, this.getWidth(), this.getHeight()), touch.getLocation()) && this.isVisible();
    },

    onTouchBegan:function(touch, event) {
        if(this.containsTouchLocation(touch)) {
            this.stopAllActions();
            this.runAction(cc.ScaleTo.create(0.3, 0.9));

            this.touched = true;

            return true;
        }

        return false;
    },
    onTouchMoved:function(touch, event) {
        if(!this.containsTouchLocation(touch) && this.touched) {
            this.touched = false;

            this.stopAllActions();
            this.runAction(cc.ScaleTo.create(0.1, 1.0));
        }
    },
    onTouchEnded:function(touch, event) {
        if(this.containsTouchLocation(touch) && this.touched) {
            this.touched = false;

            this.stopAllActions();
            this.runAction(cc.ScaleTo.create(0.1, 1.0));

            this.m_TouchCallback();
        }
    },

    update:function(dt) {
        if(this.m_AnimationStartTimeout >= 0)
        {
            this.m_AnimationStartTimeout -= dt;
        }
        else
        {
            if(this.m_AnimationRunning && (this.m_AnimationRepeatCount > 0 || this.m_AnimationRepeatCount < 0))
            {
                this.m_AnimationTimeElapsed += dt;

                if(this.m_AnimationTimeElapsed >= this.m_AnimationTime)
                {
                    this.m_AnimationTimeElapsed = 0;

                    if(this.m_AnimationStartFrame == -1 && this.m_AnimationFinishFrame == -1)
                    {
                        if(this.m_IsAnimationReverse && this.getCurrentFrameIndex() == 0) // TODO: Add animation repeat counter.
                        {
                            this.m_AnimationRunning = false;
                            this.mIsAnimationReverse = false;

                            this.m_AnimationRunning = false;

                            this.onAnimationEnd();
                                
                            return;
                        }

                        if(this.m_AnimationRepeatCount > 0 && this.getCurrentFrameIndex() == this.m_FramesCount - 1)
                        {
                            this.m_AnimationRepeatCount--;

                            if(this.m_AnimationRepeatCount == 0)
                            {
                                if(this.m_IsAnimationReverseNeed)
                                {
                                    this.m_AnimationRepeatCount++;

                                    this.m_IsAnimationReverseNeed = false;
                                    this.m_IsAnimationReverse = true;
                            
                                    this.previousFrameIndex();

                                    return;
                                }
                                else
                                {
                                    this.m_AnimationRunning = false;

                                    this.onAnimationEnd();
                                }
                            }
                        }

                        if(this.getCurrentFrameIndex() == this.m_FramesCount - 1)
                        {
                            this.onAnimationCircleEnd();

                            if(this.m_PauseBeforeNewAnimationCircleTime > 0)
                            {
                                this.m_PauseBeforeNewAnimationCircleTimeElapsed += dt;

                                if(this.m_PauseBeforeNewAnimationCircleTimeElapsed < this.m_PauseBeforeNewAnimationCircleTime)
                                {
                                    return;
                                }
                                else
                                {
                                    this.m_PauseBeforeNewAnimationCircleTimeElapsed = 0;
                                }
                            }
                        }

                        if(this.m_IsAnimationReverse)
                        {
                            this.previousFrameIndex();
                        }
                        else
                        {
                            this.nextFrameIndex();
                        }
                    }
                    else
                    {
                        if(this.getCurrentFrameIndex() < this.m_AnimationFinishFrame && this.getCurrentFrameIndex() >= this.m_AnimationStartFrame)
                        {
                            this.setCurrentFrameIndex(this.mCurrentFrameIndex + (this.mIsAnimationReverse ? -1 : 1));

                            this.m_AnimationFramesElapsed += this.m_IsAnimationReverse ? -1 : 1;
                            
                            if(this.m_IsAnimationReverseNeed && (this.getCurrentFrameIndex() == this.m_AnimationFinishFrame || this.getCurrentFrameIndex() == this.m_AnimationStartFrame))
                            {
                                this.m_IsAnimationReverse = !this.m_IsAnimationReverse;
                            }
                        }
                        else
                        {
                            if(this.m_AnimationRepeatCount > 0)
                            {
                                this.m_AnimationRepeatCount--;

                                this.m_AnimationFramesElapsed = 0;

                                if(this.m_AnimationRepeatCount == 0)
                                {
                                    this.m_AnimationRunning = false;

                                    this.onAnimationEnd();
                                }
                            }
                            else
                            {
                                if(this.m_IsAnimationReverseNeed)
                                {
                                    this.m_IsAnimationReverse = !this.m_IsAnimationReverse;
                                    
                                    this.setCurrentFrameIndex(this.m_AnimationStartFrame + this.m_AnimationFramesElapsed + (this.m_IsAnimationReverse ? -1 : 1));
                                    
                                    this.m_AnimationFramesElapsed += this.m_IsAnimationReverse ? -1 : 1;
                                }
                                else
                                {
                                    this.setCurrentFrameIndex(this.m_AnimationStartFrame);

                                    this.m_AnimationFramesElapsed = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    },

    onEnter:function() {
        this.scheduleUpdate();

        this._super();

        if(this.m_TouchCallback) {
            this.setRegisterAsTouchable(true);
        }
    },
    onExit:function() {
        this.stopAllActions();
        this.unscheduleUpdate();

        this._super();

        if(this.m_TouchCallback) {
            this.setRegisterAsTouchable(false);
        }
    }
});

cc.Entity.createWithFilename = function(p_FileName, p_Parent) {
    var entity = new cc.Entity();
    entity.initWithFilename(p_FileName, p_Parent);

    return entity;
};

cc.Entity.createWithFrames = function(p_FileName, p_HorizontalFramesCount, p_VerticalFramesCount, p_Parent) {
    var entity = new cc.Entity();
    entity.initWithFrames(p_FileName, p_HorizontalFramesCount, p_VerticalFramesCount, p_Parent);

    return entity;
};