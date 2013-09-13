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

(function () {
  var d = document;
  var c = {
    COCOS2D_DEBUG:2,
    box2d:false,
    chipmunk:false,
    showFPS:true,
    loadExtension:false,
    frameRate:60,
    tag:'canvas',
    engineDir:'Library/cocos2d/',
    appFiles:[
      'Sources/resource.js',
      'Sources/Screens/Screen.js',
      'Sources/Screens/Preloader.js',
      'Sources/Entity/Entity.js'
    ]
  };

  window.addEventListener('DOMContentLoaded', function () {
    this.removeEventListener('DOMContentLoaded', arguments.callee, false);

    var s = d.createElement('script');
    s.src = c.engineDir + 'platform/jsloader.js';

    d.body.appendChild(s);
    document.ccConfig = c;
  });
})();