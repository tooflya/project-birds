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

cc.Progress = cc.Screen.extend({
    init:function() {
        this.m_Background = cc.Entity.createWithFilename(s_ScreensBackground, this);
        this.m_BackButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);
        this.m_ResetButton = cc.Entity.createWithFilename(s_LongButton, this);

        var text = cc.Text.createWithText(cc.Languages.text_progress_reset, this);
        var text1 = cc.Text.createWithText(cc.Languages.text_progress_resetbutton, this.m_ResetButton);

        text.setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y + 200);
        text1.setCenterPosition(this.m_ResetButton.getWidth() / 2, this.m_ResetButton.getHeight() / 2);

        this.m_Background.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);
        this.m_ResetButton.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 300);
        this.m_BackButton.create().setCenterPosition(100, 100);
        this.m_BackButton.setCurrentFrameIndex(1);

        this.m_BackButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Settings.create()));
        });

        this.m_ResetButton.setTouchCallback(function() {
            this.getParent().m_ResetPopup.show();
        });

        this.m_ResetPopup = cc.Reset.create(this);
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

cc.Progress.create = function() {
    var screen = new cc.Progress();
    screen.init();
    
    return screen;
};