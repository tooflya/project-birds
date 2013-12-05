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

cc.Settings = cc.Screen.extend({
    init:function() {
        this.m_Background = cc.Entity.createWithFilename(s_ScreensBackground, this);
        this.m_BackButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);

        this.m_CreditsButton = cc.Entity.createWithFilename(s_LongButton, this);
        this.m_ProgressButton = cc.Entity.createWithFilename(s_LongButton, this);
        this.m_MoreButton = cc.Entity.createWithFilename(s_LongButton, this);
        this.m_LanguagesButton = cc.Entity.createWithFilename(s_LongButton, this);
        this.m_SoundButton = cc.Entity.createWithFrames(s_SfxButtonsSprite, 3, 2, this);
        this.m_MusicButton = cc.Entity.createWithFrames(s_SfxButtonsSprite, 3, 2, this);
        this.m_BackgroundDecoration1 = cc.Entity.createWithFilename(s_BackgroundDecoration1, this);
        this.m_BackgroundDecoration2 = cc.Entity.createWithFilename(s_BackgroundDecoration2, this);
        this.m_LanguageIndicator = cc.Entity.createWithFrames(s_SmallFlags, 2, 5, this.m_LanguagesButton);

        this.m_TextCredits = cc.Text.createWithText(cc.Languages.text_button_credits, this.m_CreditsButton);
        this.m_TextProgress = cc.Text.createWithText(cc.Languages.text_button_progress, this.m_ProgressButton);
        this.m_TextMore = cc.Text.createWithText(cc.Languages.text_button_more, this.m_MoreButton);
        this.m_TextLanguages = cc.Text.createWithText(cc.Languages.text_button_language, this.m_LanguagesButton);

        this.m_Background.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);

        this.m_CreditsButton.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y + 430);
        this.m_ProgressButton.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y + 230);
        this.m_MoreButton.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y  +30);
        this.m_LanguagesButton.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 170);
        this.m_SoundButton.create().setCenterPosition(cc.Options.camera.center.x - 110, cc.Options.camera.center.y - 380);
        this.m_MusicButton.create().setCenterPosition(cc.Options.camera.center.x + 110, cc.Options.camera.center.y - 380);
        this.m_BackgroundDecoration1.create().setCenterPosition(this.m_BackgroundDecoration1.getWidth() / 2, cc.Options.camera.height - this.m_BackgroundDecoration1.getHeight() / 2);
        this.m_BackgroundDecoration2.create().setCenterPosition(cc.Options.camera.width - this.m_BackgroundDecoration2.getWidth() / 2, this.m_BackgroundDecoration2.getHeight() / 2);
        this.m_LanguageIndicator.create().setCenterPosition(this.m_LanguagesButton.getWidth(), this.m_LanguagesButton.getHeight() / 2);
        this.m_BackButton.create().setCenterPosition(100, 100);
        this.m_BackButton.setCurrentFrameIndex(1);

        this.m_TextCredits.setCenterPosition(this.m_CreditsButton.getWidth() / 2, this.m_CreditsButton.getHeight() / 2);
        this.m_TextProgress.setCenterPosition(this.m_ProgressButton.getWidth() / 2, this.m_ProgressButton.getHeight() / 2);
        this.m_TextMore.setCenterPosition(this.m_MoreButton.getWidth() / 2, this.m_MoreButton.getHeight() / 2);
        this.m_TextLanguages.setCenterPosition(this.m_LanguagesButton.getWidth() / 2, this.m_LanguagesButton.getHeight() / 2);

        this.m_BackButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Menu.create()));
        });

        this.m_CreditsButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Credits.create()));
        });
        this.m_ProgressButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Progress.create()));
        });
        this.m_MoreButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.More.create()));
        });
        this.m_LanguagesButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Language.create()));
        });
        this.m_SoundButton.setTouchCallback(function() {
            cc.Options.sound = !cc.Options.sound;
            this.setCurrentFrameIndex(cc.Options.sound ? 1 : 4);
        });
        this.m_MusicButton.setTouchCallback(function() {
            cc.Options.music = !cc.Options.music;
            this.setCurrentFrameIndex(cc.Options.music ? 0 : 3);
        });
    },

    update:function(dt) {
    },

    onEnter:function() {
        this._super();

        this.m_LanguageIndicator.setCurrentFrameIndex(cc.Options.language_id);

        this.m_MusicButton.setCurrentFrameIndex(cc.Options.music ? 0 : 3);
        this.m_SoundButton.setCurrentFrameIndex(cc.Options.sound ? 1 : 4);
    },
    onExit:function() {
        this._super();
    }
});

cc.Settings.create = function() {
    var screen = new cc.Settings();
    screen.init();
    
    return screen;
};