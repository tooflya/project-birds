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

cc.Credits = cc.Screen.extend({
    init:function() {
        this.m_Background = cc.Entity.createWithFilename(s_ScreensBackground, this);
        this.m_BackButton = cc.Entity.createWithFrames(s_ButtonsSprite, 3, 3, this);

        this.m_ListBorder1 = cc.Entity.createWithFilename(s_ListBorder, this);
        this.m_ListBorder2 = cc.Entity.createWithFilename(s_ListBorder, this);

        this.m_List = cc.List.create(600, 894, 750, 800, cc.Options.camera.center.x, cc.Options.camera.center.y + 50, this);

        this.m_Illustration1 = cc.Entity.createWithFilename(s_AboutLogo, this.m_List);
        this.m_Illustration2 = cc.Entity.createWithFilename(s_AboutCompanyLogo, this.m_List);

        var textes = new Array();

        textes[0] = cc.Text.createWithText(cc.Languages.text_credits_1, this.m_List);
        textes[1] = cc.Text.createWithText(cc.Languages.text_credits_2, this.m_List);
        textes[2] = cc.Text.createWithText(cc.Languages.text_credits_3, this.m_List);
        textes[3] = cc.Text.createWithText(cc.Languages.text_credits_4, this.m_List);
        textes[4] = cc.Text.createWithText(cc.Languages.text_credits_5, this.m_List);
        textes[5] = cc.Text.createWithText(cc.Languages.text_credits_6, this.m_List);
        textes[6] = cc.Text.createWithText(cc.Languages.text_credits_7, this.m_List);
        textes[7] = cc.Text.createWithText(cc.Languages.text_credits_8, this.m_List);
        textes[8] = cc.Text.createWithText(cc.Languages.text_credits_9, this.m_List);
        textes[9] = cc.Text.createWithText(cc.Languages.text_credits_10, this.m_List);
        textes[10] = cc.Text.createWithText(cc.Languages.text_credits_11, this.m_List);
        textes[11] = cc.Text.createWithText(cc.Languages.text_credits_12, this.m_List);
        textes[12] = cc.Text.createWithText(cc.Languages.text_credits_13, this.m_List);
        
        textes[0].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 50);
        textes[1].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 150);
        textes[2].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 200);
        textes[3].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 300);
        textes[4].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 400);
        textes[5].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 450);
        textes[6].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 550);
        textes[7].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 600);
        textes[8].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y -700);
        textes[9].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 750);
        textes[10].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 800);
        textes[11].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 900);
        textes[12].setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 950);

        textes[0].setColor(cc.c3(167.0, 65.0, 7.0));

        textes[1].setColor(cc.c3(248.0, 163.0, 73.0));
        textes[2].setColor(cc.c3(248.0, 163.0, 73.0));

        textes[3].setColor(cc.c3(167.0, 65.0, 7.0));

        textes[4].setColor(cc.c3(167.0, 65.0, 7.0));
        textes[5].setColor(cc.c3(248.0, 163.0, 73.0));

        textes[6].setColor(cc.c3(167.0, 65.0, 7.0));
        textes[7].setColor(cc.c3(248.0, 163.0, 73.0));

        textes[8].setColor(cc.c3(167.0, 65.0, 7.0));
        textes[9].setColor(cc.c3(248.0, 163.0, 73.0));
        textes[10].setColor(cc.c3(248.0, 163.0, 73.0));

        textes[11].setColor(cc.c3(167.0, 65.0, 7.0));
        textes[12].setColor(cc.c3(248.0, 163.0, 73.0));

        this.m_Background.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);
        this.m_Illustration1.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y + 200);
        this.m_Illustration2.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 1100);
        this.m_ListBorder1.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y + 500);
        this.m_ListBorder2.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y - 400);
        this.m_BackButton.create().setCenterPosition(100, 100);
        this.m_BackButton.setCurrentFrameIndex(1);

        this.m_ListBorder2.setScaleY(-1);

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

cc.Credits.create = function() {
    var screen = new cc.Credits();
    screen.init();
    
    return screen;
};