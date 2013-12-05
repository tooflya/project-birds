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

cc.BLoader = cc.Screen.extend({
    init:function() {
        this.m_Background = cc.Entity.createWithFilename(s_PreloaderBackground, this);
        this.m_BackgroundDecoration = cc.Entity.createWithFilename(s_BackgroundDecoration4, this);

        this.m_Tip = cc.Text.createWithText(?);

        this.m_Background.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);
        this.m_BackgroundDecoration.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);
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

cc.BLoader.create = function() {
    var screen = new cc.BLoader();
    screen.init();
    
    return screen;
};