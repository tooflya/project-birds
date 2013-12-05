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

cc.PlayButton = cc.Entity.extend({
    initWithFrames:function(p_FileName, p_HorizontalFramesCount, p_VerticalFramesCount, p_Parent) {
        this._super(p_FileName, p_HorizontalFramesCount, p_VerticalFramesCount, p_Parent);

        this.m_AnimationEventTime = cc.Utils.randomf(1.5, 5.0);
        this.m_AnimationEventTimeElapsed = 0;
    },

    update:function(dt) {
        this._super(dt);

        this.m_AnimationEventTimeElapsed += dt;
            
        if(this.m_AnimationEventTimeElapsed >= this.m_AnimationEventTime) {
            this.m_AnimationEventTime = cc.Utils.randomf(1.5, 5.0);
            this.m_AnimationEventTimeElapsed = 0;
                
            this.animate(0.08, 1);
        }
    }
});

cc.PlayButton.create = function(p_Parent) {
    var entity = new cc.PlayButton();
    entity.initWithFrames(s_PlayButton, 6, 2, p_Parent);

    return entity;
};