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

 cc.Preloader = cc.Screen.extend({
    init:function() {
        this.m_Background = cc.Entity.createWithFilename(s_PreloadBackground, this);
        this.m_LoadingBarBackground = cc.Entity.createWithFilename(s_LoadingBarBackground, this);
        this.m_LoadingBar = cc.Entity.createWithFilename(s_LoadingBar, this);

        this.m_LoadingText = cc.Text.createWithText(cc.Languages.text_loading, this);

        this.m_Background.create().setCenterPosition(cc.Options.camera.center.x, cc.Options.camera.center.y);
        this.m_LoadingBar.create().setCenterPosition(cc.Options.camera.center.x, 100);
        this.m_LoadingBarBackground.create().setCenterPosition(cc.Options.camera.center.x, 100);
        this.m_LoadingText.setCenterPosition(cc.Options.camera.center.x, 100);

        this.m_LoadingBar.setSize(577, 38);
    },

    /**
     * init with resources
     * @param {Array} resources
     * @param {Function|String} selector
     * @param {Object} target
     */
    initWithResources:function (resources, selector, target) {
        this.resources = resources;
        this.selector = selector;
        this.target = target;
    },
    startLoading:function() {
        this.unschedule(this.startLoading);
        cc.Loader.preload(this.resources, this.selector, this.target);
        this.schedule(this.updatePercent);
    },
    updatePercent:function() {
        var percent = cc.Loader.getInstance().getPercentage();

        this.m_LoadingText.ccsf(percent + "%");
        this.m_LoadingBar.showPercentage(percent);
        this.m_LoadingBar.setCenterPosition(cc.Options.camera.center.x + this.m_LoadingBar.getTextureRect().width / 2 - this.m_LoadingBar.getWidth() / 2, this.m_LoadingBar.getCenterY());

        if(percent >= 100) {
            this.unschedule(this.updatePercent);
        }
    },

    onEnter:function() {
        cc.Node.prototype.onEnter.call(this);
        this.schedule(this.startLoading, 1.0);

        this.m_LoadingText.ccsf("0%");
        this.m_LoadingBar.showPercentage(0);
    },
    onExit:function() {
        cc.Node.prototype.onExit.call(this);
    },
});

cc.Preloader.create = function() {
    var screen = new cc.Preloader();
    screen.init();
    
    return screen;
};

cc.Preloader.preload = function(resources, selector, target) {
    if (!this.m_Instance) {
        this.m_Instance = new cc.Preloader();
        this.m_Instance.init();
    }

    this.m_Instance.initWithResources(resources, selector, target);

    var director = cc.Director.getInstance();
    if (director.getRunningScene()) {
        director.replaceScene(cc.TransitionFade.create(0.3, this.m_Instance));
    } else {
        director.runWithScene(this.m_Instance);
    }

    return this.m_Instance;
};