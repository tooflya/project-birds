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

cc.Menu = cc.Screen.extend({
    init:function() {
        this.m_PlayButtonDecorations = new Array();

        this.m_Background = cc.Entity.createWithFilename(s_MainMenuBackground, this);
        this.m_PlayButtonDecorations[0] = cc.Entity.createWithFilename(s_PlayButtonDecoration, this);
        this.m_PlayButtonDecorations[1] = cc.Entity.createWithFilename(s_PlayButtonDecoration, this);
        this.m_PlayButton = cc.PlayButton.create(this);
        this.m_SettingsButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);
        this.m_ShopButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);
        this.m_TwitterButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);
        this.m_VKButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);

        this.m_Background.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);
        this.m_PlayButtonDecorations[0].create().setCenterPosition(cc.Options.camera.center.x + 10, cc.Options.camera.center.y - 80);
        this.m_PlayButtonDecorations[1].create().setCenterPosition(cc.Options.camera.center.x + 10, cc.Options.camera.center.y - 80);
        this.m_PlayButton.create().setCenterPosition(cc.Options.camera.center.x + 20, cc.Options.camera.center.y - 80);
        this.m_SettingsButton.create().setCenterPosition(100, 100);
        this.m_ShopButton.create().setCenterPosition(100, 270);
        this.m_VKButton.create().setCenterPosition(cc.Options.camera.width - 100, 100);
        this.m_TwitterButton.create().setCenterPosition(cc.Options.camera.width - 270, 100);

        this.m_SettingsButton.setCurrentFrameIndex(6);
        this.m_ShopButton.setCurrentFrameIndex(2);
        this.m_VKButton.setCurrentFrameIndex(3);
        this.m_TwitterButton.setCurrentFrameIndex(0);

        this.m_PlayButtonDecorations[0].setColor(cc.c3(255.0, 0.0, 0.0));
        this.m_PlayButtonDecorations[1].setColor(cc.c3(255.0, 0.0, 0.0));

        this.m_PlayButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Mode.create()));
        });

        this.m_SettingsButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Settings.create()));
        });

        this.m_ShopButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Shop.create()));
        });

        this.m_VKButton.setTouchCallback(function() {
        });

        this.m_TwitterButton.setTouchCallback(function() {
        });

        this.m_RatePopup = cc.Rate.create(this);
    },

    update:function(dt) {
    },

    onEnter:function() {
        this.m_PlayButtonDecorations[0].runAction(cc.RepeatForever.create(cc.RotateTo.create(10.0, 720)));
        this.m_PlayButtonDecorations[1].runAction(cc.RepeatForever.create(cc.RotateTo.create(10.0, -720)));

        this._super();

        this.m_RatePopup.show();
    },
    onExit:function() {
        this._super();
    }
});

cc.Menu.create = function() {
    var screen = new cc.Menu();
    screen.init();
    
    return screen;
};