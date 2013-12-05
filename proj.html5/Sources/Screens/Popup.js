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

cc.Popup = cc.Layer.extend({
    init:function(p_Parent, p_EnableLights) {
        this._super();

        this.m_Parent = p_Parent;
        this.m_EnableLights = p_EnableLights;

        this.m_Darkness = cc.LayerColor.create(cc.c4(0, 0, 0, 255));
        this.m_Darkness.setOpacity(0);

        if(this.m_EnableLights) {
            this.m_Light1 = cc.Entity.createWithFilename(s_PopupLights, this);
            this.m_Light2 = cc.Entity.createWithFilename(s_PopupLights, this);

            this.m_Light1.setScale(3);
            this.m_Light2.setScale(3);

            this.m_Light1.setOpacity(0);
            this.m_Light2.setOpacity(0);

            this.m_Light1.setScale(3);
            this.m_Light2.setScale(3);
            this.m_Light1.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.height - 180);
            this.m_Light2.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.height - 180);
        }

        this.setPosition(cc.p(cc.Options.camera.center.x, cc.Options.camera.center.y));

        this.ignoreAnchorPointForPosition(false);
        this.setAnchorPoint(cc.p(0.5, 0.5));

        this.setScale(0);

        this.m_Show = false;

        this.m_ShowAnimation = false;
        this.m_HideAnimation = false;

        this.m_ShowAnimationTime = 0.6;
        this.m_ShowAnimationTimeElapsed = 0;

        this.m_HideAnimationTime = 0.6;
        this.m_HideAnimationTimeElapsed = 0;
    },

    show:function() {
        if(this.m_Show) return false;

        this.m_Parent.addChild(this, 1000);
        this.m_Parent.addChild(this.m_Darkness , 500);

        this.runAction(cc.Sequence.create(cc.ScaleTo.create(0.2, 1.2), cc.ScaleTo.create(0.2, 0.9, 0.8), cc.ScaleTo.create(0.2, 1.0, 1.0)));
        this.m_Darkness.runAction(cc.FadeTo.create(0.2, 200));

        if(this.m_EnableLights) {
            this.m_Light1.setOpacity(0);
            this.m_Light2.setOpacity(0);
        }

        this.m_ShowAnimationTimeElapsed = 0;
        this.m_ShowAnimation = true;
    },
    hide:function() {
        if(!this.m_Show) return false;

        this.runAction(cc.Sequence.create(cc.ScaleTo.create(0.1, 1.2), cc.ScaleTo.create(0.2, 0.0)));
        this.m_Darkness.runAction(cc.FadeTo.create(0.2, 0));

        if(this.m_EnableLights) {
            this.m_Light1.runAction(cc.FadeTo.create(0.3, 0));
            this.m_Light2.runAction(cc.FadeTo.create(0.3, 0));
        }

        this.m_HideAnimationTimeElapsed = 0;
        this.m_HideAnimation = true;
    },
    onShow:function() {
        this.m_ShowAnimation = false;

        if(this.m_EnableLights) {
            this.m_Light1.runAction(cc.FadeTo.create(1.0, 255));
            this.m_Light2.runAction(cc.FadeTo.create(1.0, 255));
        }

        this.m_Show = true;
    },
    onHide:function() {
        this.m_HideAnimation = false;

        this.removeFromParent();
        this.m_Darkness.removeFromParent();

        this.m_Show = false;
    },

    isShowed:function() {

    },

    onTouchBegan:function(touch, event) {
        return true;
    },
    onTouchMoved:function(touch, event) {
    },
    onTouchEnded:function(touch, event) {
    },

    update:function(dt) {
        if(this.m_ShowAnimation) {
            this.m_ShowAnimationTimeElapsed += dt;

            if(this.m_ShowAnimationTimeElapsed >= this.m_ShowAnimationTime) {
                this.onShow();
            }
        } else if(this.m_HideAnimation) {
            this.m_HideAnimationTimeElapsed += dt;

            if(this.m_HideAnimationTimeElapsed >= this.m_HideAnimationTime) {
                this.onHide();
            }
        }

        if(this.m_EnableLights) {
            this.m_Light1.setRotation(this.m_Light1.getRotation() - 0.1);
            this.m_Light2.setRotation(this.m_Light2.getRotation() + 0.1);
        }
    },

    draw:function() {
        this._super();
    },

    onEnter:function() {
        cc.Director.getInstance().getTouchDispatcher().addTargetedDelegate(this, 0, true);

        this.scheduleUpdate();

        this._super();
    },
    onExit:function() {
        cc.Director.getInstance().getTouchDispatcher().removeDelegate(this);

        this.stopAllActions();
        this.unscheduleUpdate();

        this._super();
    }
});