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

cc.SplashScreen = cc.Screen.extend({
    init:function() {
        this.m_LayerColor = cc.LayerColor.create(cc.c4(255.0, 255.0, 255.0, 255.0), cc.Options.camera.width, cc.Options.camera.height);
        this.m_Logo = cc.Entity.createWithFilename("splash_logo_tfl.png", this.m_LayerColor);

        this.m_Logo.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);
        this.m_Logo.setOpacity(0);

        this.m_Logo.runAction(cc.Sequence.create(cc.FadeIn.create(2.0), cc.FadeOut.create(1.0)));

        this.addChild(this.m_LayerColor);

        this.m_AnimationRunning = true;
    },

    onAnimationComplete:function() {
        cc.Preloader.preload(g_resources, function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Menu.create()));
        }, app);
    },

    update:function(dt) {
        if(this.m_AnimationRunning) {
            if(this.m_Logo.numberOfRunningActions() <= 0) {
                this.m_AnimationRunning = false;

                this.onAnimationComplete();
            }
        }
    },

    onEnter:function() {
        this._super();

    },
    onExit:function() {
        this._super();
    }
});

cc.SplashScreen.create = function() {
    var screen = new cc.SplashScreen();
    screen.init();
    
    return screen;
};