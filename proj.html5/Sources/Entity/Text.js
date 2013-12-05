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

cc.Text = cc.LabelTTF.extend({
    ctor:function() {
        this._super();

        this.setColor(cc.c3(255.0, 255.0, 255.0));
        this.enableShadow(new cc.Size(2.0, -2.0), 255.0, 0.0, true);
    },

    initWithText:function(p_Text, p_Parent) {
        this.m_TextStructure = p_Text[0];

        this.initWithString(this.m_TextStructure.string, this.m_TextStructure.font, this.m_TextStructure.size, cc.size(0, 0), cc.TEXT_ALIGNMENT_CENTER, cc.VERTICAL_TEXT_ALIGNMENT_TOP);

        if(p_Parent) {
            p_Parent.addChild(this);
        }
    },
    initWithInformation:function(p_String, p_FontName, p_Size, p_Parent) {
        this.initWithString(p_String, p_FontName, p_Size, cc.size(0, 0), cc.TEXT_ALIGNMENT_CENTER, cc.VERTICAL_TEXT_ALIGNMENT_TOP);

        if(p_Parent) {
            p_Parent.addChild(this);
        }
    },

    ccsf:function(p_AddedString) {
        cc.Utils.assert(!this.m_TextStructure, "Error in Text class. Using ccsf function but instance was instantinate without text structure.");

        this.setString(this.m_TextStructure.string + p_AddedString);
    },
    setText:function(p_Text) {
        this.m_TextStructure = p_Text[0];

        this.setString(this.m_TextStructure.string);
        this.setFontName(this.m_TextStructure.font);
        this.setFontSize(this.m_TextStructure.size);
    },
    setCenterPosition:function(pCenterX, pCenterY) {
        this.setPosition(cc.p(pCenterX, pCenterY));
    }
});

cc.Text.createWithText = function(p_Text, p_Parent) {
    var text = new cc.Text();
    text.initWithText(p_Text, p_Parent);

    return text;
};

cc.Text.createWithInformation = function(p_String, p_FontName, p_Size, p_Parent) {
    var text = new cc.Text();
    text.initWithInformation(p_String, p_FontName, p_Size, p_Parent);

    return text;
};