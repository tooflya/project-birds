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

cc.List = cc.Node.extend({
    init:function(p_Width, p_Height, p_MaxWidth, p_MaxHeight, p_ListInitialCenterX, p_ListInitialCenterY, pParent) {
        this.m_ParentType = 0;
        this.m_Type = 2;

        this.m_Width = p_Width;
        this.m_Height = p_Height;

        this.m_MaxWidth = p_MaxWidth;
        this.m_MaxHeight = p_MaxHeight;

        this.m_ListInitialCenterX = p_ListInitialCenterX;
        this.m_ListInitialCenterY = p_ListInitialCenterY;

        this.m_Background = cc.Entity.createWithFilename(s_ListBackground, this);
        this.m_Background.getTexture().setTexParameters({
            minFilter: gl.LINEAR,
            magFilter: gl.LINEAR,
            wrapS: gl.REPEAT,
            wrapT: gl.REPEAT
        });

        this.m_Background.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);

        var clipper = cc.ClippingNode.create();
        var stencil = cc.DrawNode.create();

        clipper.setStencil(stencil);
        clipper.addChild(this);

        stencil.setContentSize(cc.size(200, 200));

        if(pParent) {
            pParent.addChild(clipper);
        }
    },

    draw:function(ctx) {
        var gl = ctx || cc.renderContext;

        gl.enable(gl.STENCIL_TEST);

        cc.kmGLPushMatrix();
        this.transform();

        cc.kmGLPopMatrix();

        gl.disable(gl.STENCIL_TEST);
    },
    
    update:function(dt) {
        if(this.m_PostUpdate)
        {
            var x = this.getPosition().x;
            var y = this.getPosition().y;

            this.setPosition(cc.p(x, y - this.m_SpeedY));

            this.m_SpeedY -= this.m_LastDistanceY > 0 ? 0.5 : -0.5;

            if(y < 0) {
                this.runAction(cc.MoveTo.create(0.3, cc.p(x, 0)));

                this.m_PostUpdate = false;
            } else if(y > this.m_MaxHeight) {
                this.runAction(cc.MoveTo.create(0.3, cc.p(x, this.m_MaxHeight)));
            
                this.m_PostUpdate = false;
            }

            if(x > 0) {
                this.runAction(cc.MoveTo.create(0.3, cc.p(0, y)));
            
                this.m_PostUpdate = false;
            } else if(x < -this.m_MaxWidth) {
                this.runAction(cc.MoveTo.create(0.3, cc.p(this.m_MaxWidth, y)));
            
                this.m_PostUpdate = false;
            }

            if(this.m_LastDistanceY > 0 ? this.m_SpeedY <= 0.0 : this.m_SpeedY >= 0.0) {
                this.m_PostUpdate = false;
            }
        }

        this.m_Background.setTextureRect(cc.RectMake(0, this.getPosition().y, this.m_Background.getTextureRect().size.width, this.m_Height));
        this.m_Background.setCenterPosition(this.m_ListInitialCenterX + this.getPosition().x, this.m_ListInitialCenterY - this.getPosition().y);
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

    containsTouchLocation:function(touch) {
        var x = touch.getLocation().x;
        var y = touch.getLocation().y;

        if(this.m_ParentType == 0) {
            return x > this.m_ListInitialCenterX - this.m_Width / 2 && x < this.m_ListInitialCenterX + this.m_Width / 2 && y < this.m_ListInitialCenterY + this.m_Height / 2 && y > this.m_ListInitialCenterY - this.m_Height / 2;
        } else if(this.m_ParentType == 1) {
            return x > cc.Options.camera.center.x- this.m_Width / 2 && x < cc.Options.camera.center.x + this.m_Width / 2 && y < cc.Options.camera.center.y + this.m_Height / 2 && y > cc.Options.camera.center.y - this.m_Height / 2/* && ((Popup*) this->getParent())->isShowed()*/;
        }
        
        return true;
    },

    onTouchBegan:function(touch, event) {
        this.stopAllActions();

        this.m_PostUpdate = false;
        
        this.m_StartCoordinateX = touch.getLocation().x;
        this.m_StartCoordinateY = touch.getLocation().y;

        this.m_StartPositionCoordinateX = this.getPosition().x;
        this.m_StartPositionCoordinateY = this.getPosition().y;
        
        return this.containsTouchLocation(touch);
    },
    onTouchMoved:function(touch, event) {
        if(this.containsTouchLocation(touch)) {
            var x, y;

            if(this.m_Type == 0) {
                x = this.m_StartPositionCoordinateX + touch.getLocation().x - this.m_StartCoordinateX;
                y = this.m_StartPositionCoordinateY + touch.getLocation().y - this.m_StartCoordinateY;
            } else if(this.m_Type == 1) {
                x = this.m_StartPositionCoordinateX + touch.getLocation().x - this.m_StartCoordinateX;
                y = this.getPosition().y;
            } else if(this.m_Type == 2) {
                x = this.getPosition().x;
                y = this.m_StartPositionCoordinateY + touch.getLocation().y - this.m_StartCoordinateY;
            }
            
            this.setPosition(cc.p(x, y));
        }
    },
    onTouchEnded:function(touch, event) {
        var x = this.getPosition().x;
        var y = this.getPosition().y;

        var willPostUpdate = true;

        if(y < 0) {
            this.runAction(cc.MoveTo.create(0.3, cc.p(x, 0)));

            willPostUpdate = false;
        } else if(y > this.m_MaxHeight) {
            this.runAction(cc.MoveTo.create(0.3, cc.p(x, this.m_MaxHeight)));

            willPostUpdate = false;
        }

        if(x > 0) {
            this.runAction(cc.MoveTo.create(0.3, cc.p(0, y)));

            willPostUpdate = false;
        } else if(x < -this.m_MaxWidth) {
            this.runAction(cc.MoveTo.create(0.3, cc.p(this.m_MaxWidth, y)));

            willPostUpdate = false;
        }

        this.m_LastDistanceX = this.m_StartPositionCoordinateX - x; // TODO: Check it!
        this.m_LastDistanceY = this.m_StartPositionCoordinateY - y;

        this.m_PostUpdate = willPostUpdate;

        this.m_SpeedY = this.m_LastDistanceY / 10.0;
    },

    onEnter:function() {
        this.scheduleUpdate();

        this._super();

        this.setRegisterAsTouchable(true);

        this.m_PostUpdate = false;
        this.stopAllActions();
    },
    onExit:function() {
        this.stopAllActions();
        this.unscheduleUpdate();

        this._super();

        this.setRegisterAsTouchable(false);
        this.setPosition(cc.p(this.getPosition().x, 0)); // TODO: Check it for horizontal list.
    }
});

cc.List.create = function(p_Width, p_Height, p_MaxWidth, p_MaxHeight, p_ListInitialCenterX, p_ListInitialCenterY, pParent) {
    var screen = new cc.List();
    screen.init(p_Width, p_Height, p_MaxWidth, p_MaxHeight, p_ListInitialCenterX, p_ListInitialCenterY, pParent);
    
    return screen;
};