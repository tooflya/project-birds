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

cc.Utils = {
    
};

cc.Utils.debug = function() {
    return cc.COCOS2D_DEBUG >= 1;
}

cc.Utils.assert = function(p_Condition, p_Description) {
    if(cc.Utils.debug()) {
        if(p_Condition) {
            alert(p_Description);
        }
    }
}

cc.Utils.random = function(p_From, p_To) {
    return Math.floor(Math.random() * (p_To - p_From + 1) + p_From);
}

cc.Utils.randomf = function(p_From, p_To) {
    return (Math.random() * (p_To - p_From + 1) + p_From);
}