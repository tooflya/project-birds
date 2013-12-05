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
      'Sources/Resources.js',
      'Sources/Options.js',
      'Sources/Languages.js',
      'Sources/Utils/Utils.js',
      'Sources/Utils/List.js',
      'Sources/Screens/Screen.js',
      'Sources/Screens/Popup.js',
      'Sources/Screens/Screens/SplashScreen.js',
      'Sources/Screens/Screens/Preloader.js',
      'Sources/Screens/Screens/Menu.js',
      'Sources/Screens/Screens/Mode.js',
      'Sources/Screens/Screens/Settings.js',
      'Sources/Screens/Screens/Credits.js',
      'Sources/Screens/Screens/Progress.js',
      'Sources/Screens/Screens/More.js',
      'Sources/Screens/Screens/Language.js',
      'Sources/Screens/Screens/Shop.js',
      'Sources/Screens/Screens/Loader.js',
      'Sources/Screens/Popup/Rate.js',
      'Sources/Screens/Popup/Reset.js',
      'Sources/Screens/Popup/Help.js',
      'Sources/Screens/Popup/Achievements.js',
      'Sources/Screens/Popup/Leaderboard.js',
      'Sources/Entity/Entity.js',
      'Sources/Entity/Text.js',
      'Sources/Entity/PlayButton.js'
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