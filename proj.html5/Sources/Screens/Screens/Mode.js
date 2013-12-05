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

cc.Mode = cc.Screen.extend({
    init:function() {
        this.m_Background = cc.Entity.createWithFilename(s_ScreensBackground, this);
        this.m_BackgroundDecoration1 = cc.Entity.createWithFilename(s_BackgroundDecoration1, this);
        this.m_BackgroundDecoration2 = cc.Entity.createWithFilename(s_BackgroundDecoration3, this);
        this.m_BackButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);
        this.m_ProgressMode = cc.Entity.createWithFilename(s_LongButton, this);
        this.m_ClassicMode = cc.Entity.createWithFilename(s_LongButton, this);
        this.m_ArcadeMode = cc.Entity.createWithFilename(s_LongButton, this);
        this.m_RatingButton = cc.Entity.createWithFrames(s_SfxButtonsSprite, 3, 2, this);
        this.m_ArhievementsButton = cc.Entity.createWithFrames(s_SfxButtonsSprite, 3, 2, this);
        this.m_ShopButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);
        this.m_HelpButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);
        this.m_Panel = cc.Entity.createWithFilename(s_ShopPanel, this);

        this.m_ProgressModeText = cc.Text.createWithText(cc.Languages.text_progressmode_button, this.m_ProgressMode);
        this.m_ClassicModeText = cc.Text.createWithText(cc.Languages.text_classicmode_button, this.m_ClassicMode);
        this.m_ArcadeModeText = cc.Text.createWithText(cc.Languages.text_arcademode_button, this.m_ArcadeMode);

        this.m_ProgressModeText.setCenterPosition(this.m_ProgressMode.getWidth() / 2, this.m_ProgressMode.getHeight() / 2);
        this.m_ClassicModeText.setCenterPosition(this.m_ClassicMode.getWidth() / 2, this.m_ClassicMode.getHeight() / 2);
        this.m_ArcadeModeText.setCenterPosition(this.m_ArcadeMode.getWidth() / 2, this.m_ArcadeMode.getHeight() / 2);

        this.m_Background.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);
        this.m_BackgroundDecoration1.create().setCenterPosition(this.m_BackgroundDecoration1.getWidth() / 2, cc.Options.camera.height - this.m_BackgroundDecoration1.getHeight() / 2 - 70);
        this.m_BackgroundDecoration2.create().setCenterPosition(cc.Options.camera.width - this.m_BackgroundDecoration2.getWidth() / 2, this.m_BackgroundDecoration2.getHeight() / 2);
        this.m_ProgressMode.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y + 300);
        this.m_ClassicMode.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y + 100);
        this.m_ArcadeMode.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 100);
        this.m_RatingButton.create().setCenterPosition(cc.Options.camera.center.x - 110, cc.Options.camera.center.y - 320);
        this.m_ArhievementsButton.create().setCenterPosition(cc.Options.camera.center.x + 110, cc.Options.camera.center.y - 320);
        this.m_ShopButton.create().setCenterPosition(cc.Options.camera.width - 200, cc.Options.camera.height - 150);
        this.m_HelpButton.create().setCenterPosition(cc.Options.camera.width - 80, cc.Options.camera.height - 150);
        this.m_Panel.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.height - this.m_Panel.getHeight() / 2);
        this.m_BackButton.create().setCenterPosition(100, 100);
        this.m_BackButton.setCurrentFrameIndex(1);
        this.m_RatingButton.setCurrentFrameIndex(5);
        this.m_ArhievementsButton.setCurrentFrameIndex(2);
        this.m_ShopButton.setCurrentFrameIndex(8);
        this.m_HelpButton.setCurrentFrameIndex(7);

        this.m_ShopButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Shop.create()));
        });

        this.m_HelpButton.setTouchCallback(function() {
            this.getParent().m_HelpPopup.show();
        });

        this.m_ProgressMode.setTouchCallback(function() {
            //
        });

        this.m_ClassicMode.setTouchCallback(function() {
            //
        });

        this.m_ArcadeMode.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.BLoader.create()));
        });

        this.m_RatingButton.setTouchCallback(function() {
            this.getParent().m_LeaderboardPopup.show();
        });

        this.m_ArhievementsButton.setTouchCallback(function() {
            this.getParent().m_AchievementsPopup.show();
        });

        this.m_BackButton.setTouchCallback(function() {
            cc.Director.getInstance().replaceScene(cc.TransitionFade.create(0.3, cc.Menu.create()));
        });

        this.m_HelpPopup = cc.Help.create(this);
        this.m_AchievementsPopup = cc.Achievements.create(this);
        this.m_LeaderboardPopup = cc.Leaderboard.create(this);
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

cc.Mode.create = function() {
    var screen = new cc.Mode();
    screen.init();
    
    return screen;
};