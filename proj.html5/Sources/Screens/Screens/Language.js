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

cc.Language = cc.Screen.extend({
    init:function() {
        this.m_Flags = new Array();
        this.mNotAvailableBackgrounds = new Array();

        this.m_Background = cc.Entity.createWithFilename(s_ScreensBackground, this);
        this.m_BackButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);
        this.m_BackgroundDecoration1 = cc.Entity.createWithFilename(s_BackgroundDecoration1, this);
        this.m_BackgroundDecoration2 = cc.Entity.createWithFilename(s_BackgroundDecoration1, this);

        for(var i = 0; i < 10; i++) {
            this.m_Flags[i] = cc.Entity.createWithFrames(s_Flags, 2, 5, this);
            this.m_Flags[i].setCurrentFrameIndex(i);

            this.mNotAvailableBackgrounds[i] = cc.Entity.createWithFilename(s_FlagsNotAvailable, this.m_Flags[i]);
        
            if(i >= 2) {
                var text = cc.Text.createWithText(cc.Languages.text_not_available, this.mNotAvailableBackgrounds[i]);
                text.setCenterPosition(this.mNotAvailableBackgrounds[i].getWidth() / 2, this.mNotAvailableBackgrounds[i].getHeight() / 2);
                text.disableShadow();
                text.setColor(cc.c3(0, 0, 0));

                this.mNotAvailableBackgrounds[i].create().setCenterPosition(this.m_Flags[i].getWidth() / 2, 50);
            } else {
                this.mNotAvailableBackgrounds[i].destroy();

                this.m_Flags[i].setTouchCallback(function() {
                    //
                });
            }
        }

        this.m_Flags[0].create().setCenterPosition(cc.Options.camera.center.x - 180, cc.Options.camera.center.y + 400);
        this.m_Flags[1].create().setCenterPosition(cc.Options.camera.center.x + 180, cc.Options.camera.center.y + 400);
        this.m_Flags[2].create().setCenterPosition(cc.Options.camera.center.x - 180, cc.Options.camera.center.y + 200);
        this.m_Flags[3].create().setCenterPosition(cc.Options.camera.center.x + 180, cc.Options.camera.center.y + 200);
        this.m_Flags[4].create().setCenterPosition(cc.Options.camera.center.x - 180, cc.Options.camera.center.y +0);
        this.m_Flags[5].create().setCenterPosition(cc.Options.camera.center.x + 180, cc.Options.camera.center.y + 0);
        this.m_Flags[6].create().setCenterPosition(cc.Options.camera.center.x - 180, cc.Options.camera.center.y - 200);
        this.m_Flags[7].create().setCenterPosition(cc.Options.camera.center.x + 180, cc.Options.camera.center.y - 200);
        this.m_Flags[8].create().setCenterPosition(cc.Options.camera.center.x - 180, cc.Options.camera.center.y - 400);
        this.m_Flags[9].create().setCenterPosition(cc.Options.camera.center.x + 180, cc.Options.camera.center.y - 400);

        this.m_Background.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);
        this.m_BackgroundDecoration1.create().setCenterPosition(this.m_BackgroundDecoration1.getWidth() / 2, cc.Options.camera.height - this.m_BackgroundDecoration1.getHeight() / 2);
        this.m_BackgroundDecoration2.create().setCenterPosition(cc.Options.camera.width - this.m_BackgroundDecoration2.getWidth() / 2, this.m_BackgroundDecoration2.getHeight() / 2);
        this.m_BackButton.create().setCenterPosition(100, 100);
        this.m_BackButton.setCurrentFrameIndex(1);

        this.m_BackgroundDecoration2.setScale(-1);

        this.m_BackButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Settings.create()));
        });
    },

    update:function(dt) {
    },

    onEnter:function() {
        this._super();
    },
    onExit:function() {
        this._super();
    }
});

cc.Language.create = function() {
    var screen = new cc.Language();
    screen.init();
    
    return screen;
};