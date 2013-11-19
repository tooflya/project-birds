#ifndef CONST_OPTIONS
#define CONST_OPTIONS

#include "Options.h"

#include "Text.h"

#include "AppDelegate.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

bool Options::IS_BUILD_FOR_ABSOLUTIST = false;

const char* Options::GOOGLE_PLAY_BASE_64_KEY = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAnxTibzwKbgWhSfNuVJmKOWXmRmCAsxT8Z8+jf5DRTKcsIm6BTJOC27d2wKeuH9Uw/7i39KmRUgg+zwAFxT3X8TLpC/pM/mSLpUSfv85iN3yRE85zCrW4NQsxLbyHqjPNNxoMzC5bLBh3pqSB0qSp/2ZC+woOncQKs/J6i3O/vDFuAmnyuJVUaNDTRYYpmOPmcZiMU/hC0PLiVQAnWcM/WDFmWm6h5lBmhRvTYnRdU2Ha+cax8UpAliceS+URRmeFCM0kV2hBhHRLNCXycGa9L4vCErJnH2mcBwOztHV5x7ZIHxMFxq4Kx7h1EyI6gzorrF28m5gP9TBTihAUXaC0XQIDAQAB";
const char* Options::SOOMLA_BASE_64_KEY = "?";
const char* Options::SOOMLA_CUSTOM_BASE_64_KEY = "?";

#if COCOS2D_DEBUG >= 1
const char* Options::IN_APP_COINS_PACK_1_ID = "android.test.purchased";
const char* Options::IN_APP_COINS_PACK_2_ID = "android.test.purchased";
const char* Options::IN_APP_COINS_PACK_3_ID = "android.test.purchased";
const char* Options::IN_APP_COINS_PACK_4_ID = "android.test.purchased";
const char* Options::IN_APP_KEYS_PACK_1_ID = "android.test.purchased";
const char* Options::IN_APP_KEYS_PACK_2_ID = "android.test.purchased";
const char* Options::IN_APP_RESTORE_LIVES_ID = "android.test.purchased";
const char* Options::IN_APP_RESTORE_HITS_ID = "android.test.purchased";
#else
const char* Options::IN_APP_COINS_PACK_1_ID = "purchase_coins_pack_1";
const char* Options::IN_APP_COINS_PACK_2_ID = "purchase_coins_pack_2";
const char* Options::IN_APP_COINS_PACK_3_ID = "purchase_coins_pack_3";
const char* Options::IN_APP_COINS_PACK_4_ID = "purchase_coins_pack_4";
const char* Options::IN_APP_KEYS_PACK_1_ID = "purchase_keys_pack_1";
const char* Options::IN_APP_KEYS_PACK_2_ID = "purchase_keys_pack_2";
const char* Options::IN_APP_RESTORE_LIVES_ID = "restore_gold_lifes_full";
const char* Options::IN_APP_RESTORE_HITS_ID = "restore_level_hits_full";
#endif

CCObject* Options::PAYMENT_PROCEED_HANDLER = NULL;

int Options::CENTER_X = 0;
int Options::CENTER_Y = 0;

int Options::SCREEN_WIDTH = 0;
int Options::SCREEN_HEIGHT = 0;

int Options::SCREEN_CENTER_X = 0;
int Options::SCREEN_CENTER_Y = 0;

int Options::CAMERA_WIDTH = 0;
int Options::CAMERA_HEIGHT = 0;

int Options::CAMERA_CENTER_X = 0;
int Options::CAMERA_CENTER_Y = 0;

int Options::SELECTED_WEAPON_ID = 0;

int Options::DEVICE_TYPE = -1;

bool Options::TUTORIAL = true;

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT

const char* Options::TEXTURES_EXTENSION = ".png";

#else

const char* Options::TEXTURES_EXTENSION = ".pvr.ccz";

#endif

bool Options::MUSIC_ENABLE = true;
bool Options::SOUND_ENABLE = true;

const char* Options::VERSION = "0.8.7";
string Options::STRING_VERSION = "0.8.7";

int Options::BUILD = 8130;

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX

const char* Options::MUSIC_1 = "Music/music-1.ogg";
const char* Options::MUSIC_2 = "Music/music-2.ogg";

const char* Options::SOUND_TAP = "Sound/tap.ogg";
const char* Options::SOUND_UNLOCKED = "Sound/equip-unlock.ogg";
const char* Options::SOUND_EQUIP_SWORD = "Sound/equip-new-sword.ogg";
const char* Options::SOUND_BIRD_BLOW = "Sound/bird-blow.ogg";
const char* Options::SOUND_DANGER_EXPLOSION = "Sound/explosion.ogg";
const char* Options::SOUND_THROW = "Sound/throw-bird.ogg";
const char* Options::SOUND_THROW_BOMB = "Sound/throw-bomb.ogg";
const char* Options::SOUND_LOSE_LIFE = "Sound/lose_life.ogg";
const char* Options::SOUND_HIT = "Sound/hit.ogg";
const char* Options::SOUND_BONUS_GONG = "Sound/bonus-gong.ogg";
const char* Options::SOUND_BOMB_FUSE = "Sound/bomb-fuse.ogg";
const char* Options::SOUND_BONUS_TIME[3] = { "Sound/combo-blitz-backing-light.ogg", "Sound/combo-blitz-backing.ogg", "Sound/combo-blitz-backing-end.ogg" };
const char* Options::SOUND_SWOOSH = "Sound/swoosh.ogg";
const char* Options::SOUND_FREEZEE = "Sound/bonus-banana-freeze.ogg";
const char* Options::SOUND_PREDICTION = "Sound/pome-rampdown.ogg";
const char* Options::SOUND_COMBO[8] = {"Sound/combo-1.ogg", "Sound/combo-2.ogg", "Sound/combo-3.ogg", "Sound/combo-4.ogg", "Sound/combo-5.ogg", "Sound/combo-6.ogg", "Sound/combo-7.ogg", "Sound/combo-8.ogg"};
const char* Options::SOUND_POINTS[12] = { "Sound/popup-1.ogg", "Sound/popup-2.ogg", "Sound/popup-3.ogg", "Sound/popup-4.ogg", "Sound/popup-5.ogg", "Sound/popup-6.ogg", "Sound/popup-7.ogg", "Sound/popup-8.ogg", "Sound/popup-8.ogg", "Sound/popup-8.ogg", "Sound/popup-8.ogg", "Sound/popup-8.ogg" };
const char* Options::SOUND_PROGRESS = "Sound/progress-complete.ogg";
const char* Options::SOUND_LEVEL_UNLOCK = "Sound/upsell-whoosh.ogg";
const char* Options::SOUND_MISS = "Sound/miss.ogg";
const char* Options::SOUND_GEM[5] = { "Sound/gem1.ogg", "Sound/gem2.ogg", "Sound/gem3.ogg", "Sound/gem4.ogg", "Sound/gem5.ogg" };
const char* Options::SOUND_LEVEL_LOSE = "Sound/lose.ogg";
const char* Options::SOUND_LEVEL_STARS[3] = { "Sound/star1.ogg", "Sound/star2.ogg", "Sound/star3.ogg" };
const char* Options::SOUND_COINS[4] = { "Sound/berry_count_ind_a.ogg", "Sound/berry_count_ind_b.ogg", "Sound/berry_count_ind_c.ogg", "Sound/berry_count_ind_d.ogg" };

#elif CC_TARGET_PLATFORM == CC_PLATFORM_WINRT

const char* Options::MUSIC_1 = "Music/music-1.mp3";
const char* Options::MUSIC_2 = "Music/music-2.mp3";

const char* Options::SOUND_TAP = "Sound/tap.mp3";
const char* Options::SOUND_UNLOCKED = "Sound/equip-unlock.mp3";
const char* Options::SOUND_EQUIP_SWORD = "Sound/equip-new-sword.mp3";
const char* Options::SOUND_BIRD_BLOW = "Sound/bird-blow.mp3";
const char* Options::SOUND_DANGER_EXPLOSION = "Sound/explosion.mp3";
const char* Options::SOUND_THROW = "Sound/throw-bird.mp3";
const char* Options::SOUND_THROW_BOMB = "Sound/throw-bomb.mp3";
const char* Options::SOUND_LOSE_LIFE = "Sound/lose_life.mp3";
const char* Options::SOUND_HIT = "Sound/hit.mp3";
const char* Options::SOUND_BONUS_GONG = "Sound/bonus-gong.mp3";
const char* Options::SOUND_BOMB_FUSE = "Sound/bomb-fuse.mp3";
const char* Options::SOUND_BONUS_TIME[3] = { "Sound/combo-blitz-backing-light.mp3", "Sound/combo-blitz-backing.mp3", "Sound/combo-blitz-backing-end.mp3" };
const char* Options::SOUND_SWOOSH = "Sound/swoosh.mp3";
const char* Options::SOUND_FREEZEE = "Sound/bonus_banana_freeze.mp3";
const char* Options::SOUND_PREDICTION = "Sound/pome-rampdown.mp3";
const char* Options::SOUND_COMBO[8] = { "Sound/combo-1.mp3", "Sound/combo-2.mp3", "Sound/combo-3.mp3", "Sound/combo-4.mp3", "Sound/combo-5.mp3", "Sound/combo-6.mp3", "Sound/combo-7.mp3", "Sound/combo-8.mp3" };
const char* Options::SOUND_POINTS[12] = { "Sound/popup-1.mp3", "Sound/popup-2.mp3", "Sound/popup-3.mp3", "Sound/popup-4.mp3", "Sound/popup-5.mp3", "Sound/popup-6.mp3", "Sound/popup-7.mp3", "Sound/popup-8.mp3", "Sound/popup-8.mp3", "Sound/popup-8.mp3", "Sound/popup-8.mp3", "Sound/popup-8.mp3" };
const char* Options::SOUND_PROGRESS = "Sound/progress_complete.mp3";
const char* Options::SOUND_LEVEL_UNLOCK = "Sound/upsell_whoosh.mp3";
const char* Options::SOUND_MISS = "Sound/Soundmiss.wav";
const char* Options::SOUND_GEM[5] = { "gem1.wav", "gem2.mp3", "gem3.mp3", "gem4.mp3", "gem5.mp3" };
const char* Options::SOUND_LEVEL_LOSE = "Sound/lose.mp3";
const char* Options::SOUND_LEVEL_STARS[3] = { "Sound/Soundstar1.mp3", "Sound/Soundstar2.mp3", "Sound/Soundstar3.mp3" };
const char* Options::SOUND_COINS[4] = { "Sound/berry_count_ind_a.mp3", "Sound/berry_count_ind_b.mp3", "Sound/berry_count_ind_c.mp3", "Sound/berry_count_ind_d.mp3" };

#else

const char* Options::MUSIC_1 = "music-1.mp3";
const char* Options::MUSIC_2 = "music-2.mp3";

const char* Options::SOUND_TAP = "tap.wav";
const char* Options::SOUND_UNLOCKED = "equip-unlock.mp3";
const char* Options::SOUND_EQUIP_SWORD = "equip-new-sword.mp3";
const char* Options::SOUND_BIRD_BLOW = "bird-blow.mp3";
const char* Options::SOUND_DANGER_EXPLOSION = "explosion.mp3";
const char* Options::SOUND_THROW = "throw-bird.mp3";
const char* Options::SOUND_THROW_BOMB = "throw-bomb.mp3";
const char* Options::SOUND_LOSE_LIFE = "lose_life.mp3";
const char* Options::SOUND_HIT = "hit.mp3";
const char* Options::SOUND_BONUS_GONG = "bonus-gong.mp3";
const char* Options::SOUND_BOMB_FUSE = "bomb-fuse.mp3";
const char* Options::SOUND_BONUS_TIME[3] = { "combo-blitz-backing-light.mp3", "combo-blitz-backing.mp3", "combo-blitz-backing-end.mp3" };
const char* Options::SOUND_SWOOSH= "swoosh.mp3";
const char* Options::SOUND_FREEZEE = "bonus_banana_freeze.mp3";
const char* Options::SOUND_PREDICTION = "pome-rampdown.mp3";
const char* Options::SOUND_COMBO[8] = {"combo-1.mp3", "combo-2.mp3","combo-3.mp3","combo-4.mp3","combo-5.mp3","combo-6.mp3","combo-7.mp3","combo-8.mp3"};
const char* Options::SOUND_POINTS[12] = {"popup-1.mp3", "popup-2.mp3","popup-3.mp3","popup-4.mp3","popup-5.mp3","popup-6.mp3","popup-7.mp3","popup-8.mp3","popup-8.mp3","popup-8.mp3","popup-8.mp3","popup-8.mp3"};
const char* Options::SOUND_PROGRESS = "progress_complete.mp3";
const char* Options::SOUND_LEVEL_UNLOCK = "upsell_whoosh.mp3";
const char* Options::SOUND_MISS = "miss.wav";
const char* Options::SOUND_GEM[5] = { "gem1.wav", "gem2.mp3", "gem3.mp3", "gem4.mp3", "gem5.mp3" };
const char* Options::SOUND_LEVEL_LOSE = "lose.mp3";
const char* Options::SOUND_LEVEL_STARS[3] = { "star1.mp3", "star2.mp3", "star3.mp3" };
const char* Options::SOUND_COINS[4] = { "berry_count_ind_a.mp3", "berry_count_ind_b.mp3", "berry_count_ind_c.mp3", "berry_count_ind_d.mp3" };

#endif

CCTouchInformation Options::TOUCH_INFORMATION[10] =
{
    {
        false, 0, 0, ccp(-1000, -1000), ccp(-1000, -1000), ccp(-1000, -1000)
    },
    {
        false, 0, 0, ccp(-1000, -1000), ccp(-1000, -1000), ccp(-1000, -1000)
    },
    {
        false, 0, 0, ccp(-1000, -1000), ccp(-1000, -1000), ccp(-1000, -1000)
    },
    {
        false, 0, 0, ccp(-1000, -1000), ccp(-1000, -1000), ccp(-1000, -1000)
    },
    {
        false, 0, 0, ccp(-1000, -1000), ccp(-1000, -1000), ccp(-1000, -1000)
    },
    {
        false, 0, 0, ccp(-1000, -1000), ccp(-1000, -1000), ccp(-1000, -1000)
    },
    {
        false, 0, 0, ccp(-1000, -1000), ccp(-1000, -1000), ccp(-1000, -1000)
    },
    {
        false, 0, 0, ccp(-1000, -1000), ccp(-1000, -1000), ccp(-1000, -1000)
    },
    {
        false, 0, 0, ccp(-1000, -1000), ccp(-1000, -1000), ccp(-1000, -1000)
    },
    {
        false, 0, 0, ccp(-1000, -1000), ccp(-1000, -1000), ccp(-1000, -1000)
    }
};

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)

const char* Options::FONT = "Comic Sans MS";

#else

const char* Options::FONT = "Fonts/Comic Sans MS.ttf";

#endif

int Options::CURRENT_LANGUAGE = 0;

const char* Options::SAVE_DATA_COINS_ID[4] = { "p_gold_coins_count", "p_silver_coins_count", "p_lives_coins_count", "p_keys_coins_count" };
const char* Options::SAVE_DATA_BEST_RESULT[2] = { "p_best_result_classic", "p_best_result_arcade" };
const char* Options::SAVE_DATA_LANGUAGE_ID = "p_language_id";

int Options::SAVE_DATA_COINS_TYPE_GOLD = 0;
int Options::SAVE_DATA_COINS_TYPE_SILVER = 1;
int Options::SAVE_DATA_COINS_TYPE_LIVES = 2;
int Options::SAVE_DATA_COINS_TYPE_KEYS = 3;

int Options::SHOP_ITEMS_PRICES[100] =
{
      999, 1499, 2939, 3420, 3850, 4400, 5100, 6800, 1100, 20000,
      22199, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      10000, 15200, 18760, 21780, 33110, 37600, 40050, 44220, 50670, 60200,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int Options::SHOP_ITEMS_PRICES_GOLD[100] =
{
    1, 0, 5, 0, 0, 0, 10, 0, 0, 0,
    2, 0, 0, 50, 0, 0, 50, 0, 0, 0,
    20, 50, 40, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

int Options::SHOP_ITEMS_RATING_FACTOR[100] =
{
      10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
      100, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      90, 90, 90, 90, 90, 90, 90, 90, 90, 90,
      90, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

const char* Options::SHOP_ITEMS_PROPERTIES[100] =
{
    "12", "22", "31", "36", "42", "48", "52", "61", "68", "75",
    "88", "0", "0", "0", "0", "0", "0", "0", "0", "0",
    "0:10", "0:30", "0:00", "0:00", "0:23", "0:00", "0:45", "0:00", "0:20", "0",
    "0:02", "0:05", "0:12", "0:20", "0:00", "0:00", "0:00", "0:00", "0:00", "0:00",
    "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "00:00", "0:00", "0:00",
    "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "00:00", "0:00", "0:00",
    "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "00:00", "0:00", "0:00",
    "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "00:00", "0:00", "0:00",
    "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "00:00", "0:00", "0:00",
    "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "0:00", "00:00", "0:00", "0:00"
};

Textes Options::TEXTES_HOLDER[600] =
{
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

Textes Options::TEXT_LOADING_1 = { "", FONT, 0, 0 };
Textes Options::TEXT_LOADING_2 = { "", FONT, 0, 1 };
Textes Options::TEXT_SETTINGS_CREDITS = { "", FONT, 0, 2 };
Textes Options::TEXT_SETTINGS_PROGRESS = { "", FONT, 0, 3 };
Textes Options::TEXT_SETTINGS_MORE = { "", FONT, 0, 4 };
Textes Options::TEXT_SETTINGS_LANGUAGE = { "", FONT, 0, 5 };
Textes Options::TEXT_BUYITEM_BUY = { "", FONT, 0, 6 };
Textes Options::TEXT_EXIT_YES = { "", FONT, 0, 7 };
Textes Options::TEXT_EXIT_STRING_1 = { "", FONT, 0, 8 };
Textes Options::TEXT_EXIT_STRING_2 = { "", FONT, 0, 9 };
Textes Options::TEXT_RATE_NOW = { "", FONT, 0, 10 };
Textes Options::TEXT_RATE_STRING_1 = { "", FONT, 0, 11 };
Textes Options::TEXT_RATE_STRING_2 = { "", FONT, 0, 12 };
Textes Options::TEXT_RATE_STRING_3 = { "", FONT, 0, 13 };
Textes Options::TEXT_RATE_STRING_4 = { "", FONT, 0, 14 };
Textes Options::TEXT_GETCOINS_STRING_1 = { "", FONT, 0, 15 };
Textes Options::TEXT_GETCOINS_STRING_2 = { "", FONT, 0, 16 };
Textes Options::TEXT_GETCOINS_1 = { "", FONT, 0, 17 };
Textes Options::TEXT_GETCOINS_2 = { "", FONT, 0, 18 };
Textes Options::TEXT_GETCOINS_3 = { "", FONT, 0, 19 };
Textes Options::TEXT_GETCOINS_4 = { "", FONT, 0, 20 };
Textes Options::TEXT_PROGRESS_STRING_1 = { "", FONT, 0, 21 };
Textes Options::TEXT_PROGRESS_RESET = { "", FONT, 0, 24 };
Textes Options::TEXT_RESET_STRING_1 = { "", FONT, 0, 25 };
Textes Options::TEXT_RESET_STRING_2 = { "", FONT, 0, 26 };
Textes Options::TEXT_RESET_STRING_3 = { "", FONT, 0, 27 };
Textes Options::TEXT_RESET_STRING_4 = { "", FONT, 0, 28 };
Textes Options::TEXT_RESET_RESET = { "", FONT, 0, 29 };
Textes Options::TEXT_CREDITS_STRING_1 = { "", FONT, 0, 30 };
Textes Options::TEXT_CREDITS_STRING_2 = { "", FONT, 0, 31 };
Textes Options::TEXT_CREDITS_STRING_3 = { "", FONT, 0, 32 };
Textes Options::TEXT_CREDITS_STRING_4 = { "", FONT, 0, 33 };
Textes Options::TEXT_CREDITS_STRING_5 = { "", FONT, 0, 34 };
Textes Options::TEXT_CREDITS_STRING_6 = { "", FONT, 0, 35 };
Textes Options::TEXT_CREDITS_STRING_7 = { "", FONT, 0, 36 };
Textes Options::TEXT_CREDITS_STRING_8 = { "", FONT, 0, 37 };
Textes Options::TEXT_CREDITS_STRING_9 = { "", FONT, 0, 38 };
Textes Options::TEXT_CREDITS_STRING_10 = { "", FONT, 0, 39 };
Textes Options::TEXT_CREDITS_STRING_11 = { "", FONT, 0, 40 };
Textes Options::TEXT_CREDITS_STRING_12 = { "", FONT, 0, 41 };
Textes Options::TEXT_CREDITS_STRING_13 = { "", FONT, 0, 42 };
Textes Options::TEXT_SHOP_DESCRIPTION[3] = { { "", FONT, 0, 43 }, { "", FONT, 0, 44 }, { "", FONT, 0, 45 } };
Textes Options::TEXT_MODE_CLASSIC = { "", FONT, 0, 46 };
Textes Options::TEXT_MODE_ARCADE = { "", FONT, 0, 47 };
Textes Options::TEXT_MODE_PROGRESS = { "", FONT, 0, 48 };
Textes Options::TEXT_MODEHELP_OK = { "", FONT, 0, 49 };
Textes Options::TEXT_MODEHELP_HELP[2] = { { "", FONT, 0, 50 }, { "", FONT, 0, 51 } };
Textes Options::TEXT_GETCOINS_STRING_3 = { "", FONT, 0, 52 };
Textes Options::TEXT_GETCOINS_STRING_4 = { "", FONT, 0, 53 };
Textes Options::TEXT_SHOP_ITEMS[90] =
{
      { "", FONT, 0, 54 }, { "", FONT, 0, 55 }, { "", FONT, 0, 56 }, { "", FONT, 0, 58 }, { "", FONT, 0, 58 }, { "", FONT, 0, 59 }, { "", FONT, 0, 60 }, { "", FONT, 0, 61 }, { "", FONT, 0, 62 }, { "", FONT, 0, 63 },
      { "", FONT, 0, 64 }, { "", FONT, 0, 65 }, { "", FONT, 0, 66 }, { "", FONT, 0, 67 }, { "", FONT, 0, 68 }, { "", FONT, 0, 69 }, { "", FONT, 0, 70 }, { "", FONT, 0, 71 }, { "", FONT, 0, 72 }, { "", FONT, 0, 73 },
      { "", FONT, 0, 74 }, { "", FONT, 0, 75 }, { "", FONT, 0, 76 }, { "", FONT, 0, 77 }, { "", FONT, 0, 78 }, { "", FONT, 0, 79 }, { "", FONT, 0, 80 }, { "", FONT, 0, 81 }, { "", FONT, 0, 82 }, { "", FONT, 0, 83 },
      { "", FONT, 0, 84 }, { "", FONT, 0, 85 }, { "", FONT, 0, 86 }, { "", FONT, 0, 87 }, { "", FONT, 0, 88 }, { "", FONT, 0, 89 }, { "", FONT, 0, 90 }, { "", FONT, 0, 91 }, { "", FONT, 0, 92 }, { "", FONT, 0, 93 },
      { "", FONT, 0, 94 }, { "", FONT, 0, 95 }, { "", FONT, 0, 96 }, { "", FONT, 0, 97 }, { "", FONT, 0, 98 }, { "", FONT, 0, 99 }, { "", FONT, 0, 100 }, { "", FONT, 0, 101 }, { "", FONT, 0, 102 }, { "", FONT, 0, 103 },
      { "", FONT, 0, 104 }, { "", FONT, 0, 105 }, { "", FONT, 0, 106 }, { "", FONT, 0, 107 }, { "", FONT, 0, 108 }, { "", FONT, 0, 109 }, { "", FONT, 0, 110 }, { "", FONT, 0, 111 }, { "", FONT, 0, 112 }, { "", FONT, 0, 113 },
      { "", FONT, 0, 114 }, { "", FONT, 0, 115 }, { "", FONT, 0, 116 }, { "", FONT, 0, 117 }, { "", FONT, 0, 118 }, { "", FONT, 0, 119 }, { "", FONT, 0, 120 }, { "", FONT, 0, 121 }, { "", FONT, 0, 122 }, { "", FONT, 0, 123 },
      { "", FONT, 0, 124 }, { "", FONT, 0, 125 }, { "", FONT, 0, 126 }, { "", FONT, 0, 127 }, { "", FONT, 0, 128 }, { "", FONT, 0, 129 }, { "", FONT, 0, 130 }, { "", FONT, 0, 131 }, { "", FONT, 0, 132 }, { "", FONT, 0, 133 },
      { "", FONT, 0, 134 }, { "", FONT, 0, 135 }, { "", FONT, 0, 136 }, { "", FONT, 0, 137 }, { "", FONT, 0, 138 }, { "", FONT, 0, 139 }, { "", FONT, 0, 140 }, { "", FONT, 0, 141 }, { "", FONT, 0, 142 }, { "", FONT, 0, 143 }
};
Textes Options::TEXT_SHOP_BOUGHT =  { "", FONT, 0, 144 };
Textes Options::TEXT_TAP_TO_CONTINUE =  { "", FONT, 0, 145 };
Textes Options::TEXT_TIP[10] =
{
    { "", FONT, 36, 146 },
    { "", FONT, 36, 147 },
    { "", FONT, 36, 148 },
    { "", FONT, 36, 149 },
    { "", FONT, 36, 150 },
    { "", FONT, 36, 151 },
    { "", FONT, 36, 152 },
    { "", FONT, 36, 153 },
    { "", FONT, 36, 154 },
    { "", FONT, 36, 155 }
};
Textes Options::TEXT_SHOP_ITEMS_DESCRIPTIONS[90] =
{
      { "", FONT, 0, 156 }, { "", FONT, 0, 157 }, { "", FONT, 0, 158 }, { "", FONT, 0, 159 }, { "", FONT, 0, 160 }, { "", FONT, 0, 161 }, { "", FONT, 0, 162 }, { "", FONT, 0, 163 }, { "", FONT, 0, 164 }, { "", FONT, 0, 165 },
      { "", FONT, 0, 166 }, { "", FONT, 0, 167 }, { "", FONT, 0, 168 }, { "", FONT, 0, 169 }, { "", FONT, 0, 170 }, { "", FONT, 0, 171 }, { "", FONT, 0, 172 }, { "", FONT, 0, 173 }, { "", FONT, 0, 174 }, { "", FONT, 0, 175 },
      { "", FONT, 0, 176 }, { "", FONT, 0, 177 }, { "", FONT, 0, 178 }, { "", FONT, 0, 179 }, { "", FONT, 0, 180 }, { "", FONT, 0, 181 }, { "", FONT, 0, 182 }, { "", FONT, 0, 183 }, { "", FONT, 0, 184 }, { "", FONT, 0, 185 },
      { "", FONT, 0, 186 }, { "", FONT, 0, 187 }, { "", FONT, 0, 188 }, { "", FONT, 0, 189 }, { "", FONT, 0, 190 }, { "", FONT, 0, 191 }, { "", FONT, 0, 192 }, { "", FONT, 0, 193 }, { "", FONT, 0, 194 }, { "", FONT, 0, 195 },
      { "", FONT, 0, 196 }, { "", FONT, 0, 197 }, { "", FONT, 0, 198 }, { "", FONT, 0, 199 }, { "", FONT, 0, 200 }, { "", FONT, 0, 201 }, { "", FONT, 0, 202 }, { "", FONT, 0, 203 }, { "", FONT, 0, 204 }, { "", FONT, 0, 205 },
      { "", FONT, 0, 206 }, { "", FONT, 0, 207 }, { "", FONT, 0, 208 }, { "", FONT, 0, 209 }, { "", FONT, 0, 210 }, { "", FONT, 0, 211 }, { "", FONT, 0, 212 }, { "", FONT, 0, 213 }, { "", FONT, 0, 214 }, { "", FONT, 0, 215 },
      { "", FONT, 0, 216 }, { "", FONT, 0, 217 }, { "", FONT, 0, 218 }, { "", FONT, 0, 219 }, { "", FONT, 0, 220 }, { "", FONT, 0, 221 }, { "", FONT, 0, 222 }, { "", FONT, 0, 223 }, { "", FONT, 0, 224 }, { "", FONT, 0, 225 },
      { "", FONT, 0, 226 }, { "", FONT, 0, 227 }, { "", FONT, 0, 228 }, { "", FONT, 0, 229 }, { "", FONT, 0, 230 }, { "", FONT, 0, 231 }, { "", FONT, 0, 232 }, { "", FONT, 0, 233 }, { "", FONT, 0, 234 }, { "", FONT, 0, 235 },
      { "", FONT, 0, 236 }, { "", FONT, 0, 237 }, { "", FONT, 0, 238 }, { "", FONT, 0, 239 }, { "", FONT, 0, 240 }, { "", FONT, 0, 241 }, { "", FONT, 0, 242 }, { "", FONT, 0, 243 }, { "", FONT, 0, 244 }, { "", FONT, 0, 245 }
};
Textes Options::TEXT_MORE_GAMES = {"", FONT, 48, 246};
Textes Options::TEXT_PUBLISHER_STRING_1 = {"", FONT, 48, 247};
Textes Options::TEXT_PUBLISHER_STRING_2 = {"", FONT, 36, 248};
Textes Options::TEXT_PUBLISHER_STRING_3 = {"", FONT, 36, 249};
Textes Options::TEXT_BUYITEM_CHOOSE = {"", FONT, 0, 250};
Textes Options::TEXT_ITEM_ALREADY_BOUGHT = {"", FONT, 32, 251};
Textes Options::TEXT_PAUSE_BACK_TO_SELECT_MODE = {"", FONT, 42, 252};
Textes Options::TEXT_PAUSE_CONTINUE = {"", FONT, 42, 253};
Textes Options::TEXT_LANGUAGE_NOT_AVAILABLE = {"", Options::FONT, 24, 254};
Textes Options::TEXT_GAME_START_STRING_1 = {"", Options::FONT, 100, 255};
Textes Options::TEXT_GAME_START_STRING_2 = {"", Options::FONT, 100, 256};
Textes Options::TEXT_GAME_CLASSIC_LEVEL_UP = {"", Options::FONT, 72, 257};
Textes Options::TEXT_GAME_SOMETHING_WAS_UNLOCKED = {"", Options::FONT, 42, 258};
Textes Options::TEXT_GAME_BEST = {"", Options::FONT, 32, 259};
Textes Options::TEXT_GAME_ARCADE_TIME_REMAINING = {"", Options::FONT, 32, 260};
Textes Options::TEXT_EVENTS[90] =
{
      { "", FONT, 0, 261 }, { "", FONT, 0, 262 }, { "", FONT, 0, 263 }, { "", FONT, 0, 264 }, { "", FONT, 0, 265 }, { "", FONT, 0, 266 }, { "", FONT, 0, 267 }, { "", FONT, 0, 268 }, { "", FONT, 0, 269 }, { "", FONT, 0, 270 },
      { "", FONT, 0, 271 }, { "", FONT, 0, 272 }, { "", FONT, 0, 273 }, { "", FONT, 0, 274 }, { "", FONT, 0, 275 }, { "", FONT, 0, 276 }, { "", FONT, 0, 277 }, { "", FONT, 0, 278 }, { "", FONT, 0, 279 }, { "", FONT, 0, 280 },
      { "", FONT, 0, 281 }, { "", FONT, 0, 282 }, { "", FONT, 0, 283 }, { "", FONT, 0, 284 }, { "", FONT, 0, 285 }, { "", FONT, 0, 286 }, { "", FONT, 0, 287 }, { "", FONT, 0, 288 }, { "", FONT, 0, 289 }, { "", FONT, 0, 290 },
      { "", FONT, 0, 291 }, { "", FONT, 0, 292 }, { "", FONT, 0, 293 }, { "", FONT, 0, 294 }, { "", FONT, 0, 295 }, { "", FONT, 0, 296 }, { "", FONT, 0, 297 }, { "", FONT, 0, 298 }, { "", FONT, 0, 299 }, { "", FONT, 0, 300 },
      { "", FONT, 0, 301 }, { "", FONT, 0, 302 }, { "", FONT, 0, 303 }, { "", FONT, 0, 304 }, { "", FONT, 0, 305 }, { "", FONT, 0, 306 }, { "", FONT, 0, 307 }, { "", FONT, 0, 308 }, { "", FONT, 0, 309 }, { "", FONT, 0, 310 },
      { "", FONT, 0, 311 }, { "", FONT, 0, 312 }, { "", FONT, 0, 313 }, { "", FONT, 0, 314 }, { "", FONT, 0, 315 }, { "", FONT, 0, 316 }, { "", FONT, 0, 317 }, { "", FONT, 0, 318 }, { "", FONT, 0, 319 }, { "", FONT, 0, 320 },
      { "", FONT, 0, 321 }, { "", FONT, 0, 322 }, { "", FONT, 0, 323 }, { "", FONT, 0, 324 }, { "", FONT, 0, 325 }, { "", FONT, 0, 326 }, { "", FONT, 0, 327 }, { "", FONT, 0, 328 }, { "", FONT, 0, 329 }, { "", FONT, 0, 330 },
      { "", FONT, 0, 331 }, { "", FONT, 0, 332 }, { "", FONT, 0, 333 }, { "", FONT, 0, 334 }, { "", FONT, 0, 335 }, { "", FONT, 0, 336 }, { "", FONT, 0, 337 }, { "", FONT, 0, 338 }, { "", FONT, 0, 339 }, { "", FONT, 0, 340 },
      { "", FONT, 0, 341 }, { "", FONT, 0, 342 }, { "", FONT, 0, 343 }, { "", FONT, 0, 344 }, { "", FONT, 0, 345 }, { "", FONT, 0, 346 }, { "", FONT, 0, 347 }, { "", FONT, 0, 348 }, { "", FONT, 0, 349 }, { "", FONT, 0, 350 }
};
Textes Options::TEXT_GAME_CLASSIC_BONUS_TIME = { "", FONT, 72, 351 };
Textes Options::TEXT_PAYMENT_STRING[6] =
  {
    {"", FONT, 48, 352},
    {"", FONT, 36, 353}, 
    {"", FONT, 36, 354}, 
    {"", FONT, 36, 355}, 
    {"", FONT, 36, 356},
    {"", FONT, 46, 357}
  };
Textes Options::TEXT_END[7] =
{
    {"", FONT, 64, 358},
    {"", FONT, 42, 359},
    {"", FONT, 42, 360},
    {"", FONT, 42, 361},
    {"", FONT, 42, 362},
    {"", FONT, 42, 363},
    {"", FONT, 42, 364}
};
Textes Options::TEXT_DAILY_MAP = {"", Options::FONT, 42, 365};
Textes Options::TEXT_COINS_BONUS[10] =
{
    {"", FONT, 36, 366},
    {"", FONT, 36, 367},
    {"", FONT, 36, 368},
    {"", FONT, 36, 369},
    {"", FONT, 36, 370},
    {"", FONT, 36, 371},
    {"", FONT, 36, 372},
    {"", FONT, 36, 373},
    {"", FONT, 36, 374},
    {"", FONT, 36, 375}
};
Textes Options::TEXT_GETLIVES_STRING_1 = {"", Options::FONT, 0, 376};
Textes Options::TEXT_GETKEYS_STRING_1 = {"", Options::FONT, 0, 377};
Textes Options::TEXT_UNLOCKLEVEL = {"", Options::FONT, 0, 378};
Textes Options::TEXT_UNLOCKLEVEL_OK = {"", Options::FONT, 0, 379};
Textes Options::TEXT_SURPRISE_OK = {"", Options::FONT, 0, 380};
Textes Options::TEXT_SURPRISE = {"", Options::FONT, 0, 381};
Textes Options::TEXT_PUBLISHER_STRING_4 = {"", FONT, 36, 382};
Textes Options::TEXT_MAPDESCRIPTION_CONTINUE = {"", FONT, 46, 383};
Textes Options::TEXT_MAPDESCRIPTION_TOP = {"", FONT, 42, 384};
Textes Options::TEXT_MAPDESCRIPTION_BOTTOM = {"", FONT, 32, 385};
Textes Options::TEXT_MAPDESCRIPTION_MIDDLE = {"", FONT, 32, 386};
Textes Options::TEXT_UNLOCKMODE = {"", FONT, 0, 387};
Textes Options::TEXT_BONUS[12] =
{
    {"", FONT, 36, 388},
    {"", FONT, 36, 389},
    {"", FONT, 36, 390},
    {"", FONT, 36, 391},
    {"", FONT, 36, 392},
    {"", FONT, 36, 393},
    {"", FONT, 36, 394},
    {"", FONT, 36, 395},
    {"", FONT, 36, 396},
    {"", FONT, 36, 397},
    {"", FONT, 36, 398},
    {"", FONT, 36, 399}
};
Textes Options::TEXT_LEVELS_EPISODE = {"", FONT, 42, 400};
Textes Options::TEXT_LEVELS_LOCKED = {"", FONT, 32, 401};
Textes Options::TEXT_PROGRESS_TAP_TO_CONTINUE = {"", FONT, 24, 402};
Textes Options::TEXT_PROGRESS_LEVEL_NUMBER = {"", FONT, 32, 403};
Textes Options::TEXT_PROGRESS_LEVEL_TASK = {"", FONT, 32, 404};
Textes Options::TEXT_EPISODES_NAMES[6] =
{
    {"", FONT, 32, 405},
    {"", FONT, 32, 406},
    {"", FONT, 32, 407},
    {"", FONT, 32, 408},
    {"", FONT, 32, 409},
    {"", FONT, 52, 410}
};
Textes Options::TEXT_NEED_TO_UNLOCK = {"", FONT, 22, 411};
Textes Options::TEXT_GETSHOOTS_STRING_1 = {"", Options::FONT, 0, 412};

Textes Options::TEXT_LEVELS_TASKS[80][3] = {
    { {"", FONT, 32, 413}, {"", FONT, 32, 414}, {"", FONT, 32, 415} },
    { {"", FONT, 32, 416}, {"", FONT, 32, 417}, {"", FONT, 32, 418} },
    { {"", FONT, 32, 419}, {"", FONT, 32, 420}, {"", FONT, 32, 421} },
    { {"", FONT, 32, 422}, {"", FONT, 32, 423}, {"", FONT, 32, 424} },
    { {"", FONT, 32, 425}, {"", FONT, 32, 426}, {"", FONT, 32, 427} }
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Options::Options()
{
}

// ===========================================================
// Methods
// ===========================================================

void Options::init()
{
    Options::CURRENT_LANGUAGE = AppDelegate::getSelectedLanguage();
    
    if(CURRENT_LANGUAGE <= 0)
    {
        switch(CCApplication::sharedApplication()->getCurrentLanguage())
        {
            default:
                CURRENT_LANGUAGE = 0;
            break;
            case kLanguageRussian:
                CURRENT_LANGUAGE = 1;
            break;
        }
    }

    Options::MUSIC_ENABLE = AppDelegate::isMusicEnable();
    Options::SOUND_ENABLE = AppDelegate::isSoundEnable();

    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC

    CCDictionary* pConfInfo = CCDictionary::createWithContentsOfFile("Info.plist");
    pConfInfo->retain(); // It's really need?
    Options::BUILD = pConfInfo->valueForKey("CFBundleVersion")->intValue();

    #endif

    Options::changeLanguage();

	/** Some problem with sound */
	#if CC_TARGET_PLATFORM == CC_PLATFORM_WINRT

	Options::MUSIC_ENABLE = false;
	Options::SOUND_ENABLE = false;

	#endif
}

void Options::changeLanguage()
{
    AppDelegate::changeLanguage(CURRENT_LANGUAGE);

    switch(Options::CURRENT_LANGUAGE)
    {
        case 0:
            TEXT_LOADING_1.string = "Loading... 0%";
            TEXT_LOADING_1.size = 32;
            
            TEXT_LOADING_2.string = "Loading... ";
            TEXT_LOADING_2.size = 32;
            
            TEXT_SETTINGS_CREDITS.string = "About";
            TEXT_SETTINGS_CREDITS.size = 64;
            
            TEXT_SETTINGS_PROGRESS.string = "Progress";
            TEXT_SETTINGS_PROGRESS.size = 64;
            
            TEXT_SETTINGS_MORE.string = "More";
            TEXT_SETTINGS_MORE.size = 64;
            
            TEXT_SETTINGS_LANGUAGE.string = "Language";
            TEXT_SETTINGS_LANGUAGE.size = 64;
            
            TEXT_BUYITEM_BUY.string = "Buy";
            TEXT_BUYITEM_BUY.size = 46;
            
            TEXT_EXIT_YES.string = "Yes";
            TEXT_EXIT_YES.size = 64;
            
            TEXT_EXIT_STRING_1.string = "Are you sure you want to quit?\n \nWe will be very sad without you!";
            TEXT_EXIT_STRING_1.size = 48;
            
            TEXT_EXIT_STRING_2.string = "";
            TEXT_EXIT_STRING_2.size = 48;
            
            TEXT_RATE_NOW.string = "Rate";
            TEXT_RATE_NOW.size = 46;
            
            #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

            TEXT_RATE_STRING_1.string = "Do you like our awesome game?\n \nPlease rate it in the Google Play! Thanks!";
            TEXT_RATE_STRING_1.size = 48;

            #else

            TEXT_RATE_STRING_1.string = "Do you like our awesome game?\n \nPlease rate it in the Apple Store! Thanks!";
            TEXT_RATE_STRING_1.size = 48;

            #endif
            
            TEXT_RATE_STRING_2.string = "";
            TEXT_RATE_STRING_2.size = 48;
            
            TEXT_RATE_STRING_3.string = "";
            TEXT_RATE_STRING_3.size = 48;
            
            TEXT_RATE_STRING_4.string = "";
            TEXT_RATE_STRING_4.size = 48;
            
            TEXT_GETCOINS_STRING_1.string = "You need to buy\nsome coins!";
            TEXT_GETCOINS_STRING_1.size = 48;
            
            TEXT_GETLIVES_STRING_1.string = "You have run out of extra lives!\nRestore them or wait\nuntil they recover.";
            TEXT_GETLIVES_STRING_1.size = 32;
            
            TEXT_GETSHOOTS_STRING_1.string = "You have run out of moves!\nRestore them and compelete\nthis level or you lose!";
            TEXT_GETSHOOTS_STRING_1.size = 32;
            
            TEXT_GETKEYS_STRING_1.string = "You need to buy\nsome keys for unclock!";
            TEXT_GETKEYS_STRING_1.size = 48;
            
            TEXT_GETCOINS_STRING_2.string = "Any purchase will\nremove the ads!";
            TEXT_GETCOINS_STRING_2.size = 36;
            
            TEXT_GETCOINS_STRING_3.string = "";
            TEXT_GETCOINS_STRING_3.size = 0;
            
            TEXT_GETCOINS_STRING_4.string = "";
            TEXT_GETCOINS_STRING_4.size = 0;
            
            TEXT_GETCOINS_1.string = "$0.99";
            TEXT_GETCOINS_1.size = 64;
            
            TEXT_GETCOINS_2.string = "$1.99";
            TEXT_GETCOINS_2.size = 64;
            
            TEXT_GETCOINS_3.string = "$3.99";
            TEXT_GETCOINS_3.size = 64;
            
            TEXT_GETCOINS_4.string = "$9.99";
            TEXT_GETCOINS_4.size = 64;
            
            TEXT_PROGRESS_STRING_1.string = "If you want to start game again, you can reset progress.";
            TEXT_PROGRESS_STRING_1.size = 48;
            
            TEXT_PROGRESS_RESET.string = "Reset";
            TEXT_PROGRESS_RESET.size = 48;
            
            TEXT_RESET_STRING_1.string = "Are you sure that you want to reset your progress?\n \nYou will start game from the first level";
            TEXT_RESET_STRING_1.size = 48;
            
            TEXT_RESET_STRING_2.string = "";
            TEXT_RESET_STRING_2.size = 48;
            
            TEXT_RESET_STRING_3.string = "";
            TEXT_RESET_STRING_3.size = 48;
            
            TEXT_RESET_STRING_4.string = "";
            TEXT_RESET_STRING_4.size = 48;
            
            TEXT_RESET_RESET.string = "Reset";
            TEXT_RESET_RESET.size = 48;
            
            TEXT_CREDITS_STRING_1.string = "About";
            TEXT_CREDITS_STRING_1.size = 48;

            TEXT_CREDITS_STRING_2.string = ccsf("Version: %s", Options::VERSION);
            TEXT_CREDITS_STRING_2.size = 36;

            TEXT_CREDITS_STRING_3.string = ccsf("Build: %d", Options::BUILD);
            TEXT_CREDITS_STRING_3.size = 36;
            
            TEXT_CREDITS_STRING_4.string = "Created by:";
            TEXT_CREDITS_STRING_4.size = 42;
            
            TEXT_CREDITS_STRING_5.string = "Programming";
            TEXT_CREDITS_STRING_5.size = 36;
            
            TEXT_CREDITS_STRING_6.string = "Igor Mats";
            TEXT_CREDITS_STRING_6.size = 32;
            
            TEXT_CREDITS_STRING_7.string = "Designers";
            TEXT_CREDITS_STRING_7.size = 36;
            
            TEXT_CREDITS_STRING_8.string = "Dmitry Shane";
            TEXT_CREDITS_STRING_8.size = 32;
            
            TEXT_CREDITS_STRING_9.string = "Artists";
            TEXT_CREDITS_STRING_9.size = 36;
            
            TEXT_CREDITS_STRING_10.string = "Maksim Petrov";
            TEXT_CREDITS_STRING_10.size = 32;
            
            TEXT_CREDITS_STRING_11.string = "Vyacheslav Shevchenko";
            TEXT_CREDITS_STRING_11.size = 32;
            
            TEXT_CREDITS_STRING_12.string = "PR & Marketing";
            TEXT_CREDITS_STRING_12.size = 36;
            
            TEXT_CREDITS_STRING_13.string = "Aleksandr Lysenko";
            TEXT_CREDITS_STRING_13.size = 32;
            
            TEXT_SHOP_DESCRIPTION[0].string = "weapons";
            TEXT_SHOP_DESCRIPTION[0].size = 36;
            
            TEXT_SHOP_DESCRIPTION[1].string = "characters";
            TEXT_SHOP_DESCRIPTION[1].size = 36;
            
            TEXT_SHOP_DESCRIPTION[2].string = "bonuses";
            TEXT_SHOP_DESCRIPTION[2].size = 36;
            
            TEXT_MODE_CLASSIC.string = "Classic";
            TEXT_MODE_CLASSIC.size = 64;
            
            TEXT_MODE_ARCADE.string = "Arcade";
            TEXT_MODE_ARCADE.size = 64;
            
            TEXT_MODE_PROGRESS.string = "Progress";
            TEXT_MODE_PROGRESS.size = 64;
            
            TEXT_MODEHELP_OK.string = "Close";
            TEXT_MODEHELP_OK.size = 46;
            
            TEXT_MODEHELP_HELP[0].string = "About modes";
            TEXT_MODEHELP_HELP[0].size = 48;
            
            TEXT_MODEHELP_HELP[1].string = "Classic mode - the game in which you have to compete with other players to earn coins, to increase its global ranking and use the bonus earned.\n \nArcade mode - allow you to show what you can do in one minute! As the game progresses your skills increase and you are quite able to surpass its previous record!\n \nProgress mode - a special mode. Available to you 80 levels (update soon) with a variety of tasks. As you progress through levels you will unlock new opportunities that you can get to use in other game modes.";
            TEXT_MODEHELP_HELP[1].size = 24;
            
            TEXT_SHOP_ITEMS[0].string = "Bamboo truth";
            TEXT_SHOP_ITEMS[0].size = 48;
            
            TEXT_SHOP_ITEMS[1].string = "Slat";
            TEXT_SHOP_ITEMS[1].size = 48;
            
            TEXT_SHOP_ITEMS[2].string = "Dubin";
            TEXT_SHOP_ITEMS[2].size = 48;
            
            TEXT_SHOP_ITEMS[3].string = "Shovel";
            TEXT_SHOP_ITEMS[3].size = 48;
            
            TEXT_SHOP_ITEMS[4].string = "Hammer of truth";
            TEXT_SHOP_ITEMS[4].size = 48;
            
            TEXT_SHOP_ITEMS[5].string = "Axe of power";
            TEXT_SHOP_ITEMS[5].size = 48;
            
            TEXT_SHOP_ITEMS[6].string = "Magic Wand";
            TEXT_SHOP_ITEMS[6].size = 48;
            
            TEXT_SHOP_ITEMS[7].string = "Clown head baseball bat";
            TEXT_SHOP_ITEMS[7].size = 48;
            
            TEXT_SHOP_ITEMS[8].string = "Fish";
            TEXT_SHOP_ITEMS[8].size = 48;
            
            TEXT_SHOP_ITEMS[9].string = "The mechanical arm";
            TEXT_SHOP_ITEMS[9].size = 48;
            
            TEXT_SHOP_ITEMS[10].string = "Sword of Jedi";
            TEXT_SHOP_ITEMS[10].size = 48;
            
            TEXT_SHOP_ITEMS[20].string = "Freeze Bird";
            TEXT_SHOP_ITEMS[20].size = 48;
            
            TEXT_SHOP_ITEMS[21].string = "Comanche Bird";
            TEXT_SHOP_ITEMS[21].size = 48;
            
            TEXT_SHOP_ITEMS[22].string = "Robo Bird";
            TEXT_SHOP_ITEMS[22].size = 48;
            
            TEXT_SHOP_ITEMS[23].string = "Pirat Bird";
            TEXT_SHOP_ITEMS[23].size = 48;
            
            TEXT_SHOP_ITEMS[24].string = "Mexico Bird";
            TEXT_SHOP_ITEMS[24].size = 48;
            
            TEXT_SHOP_ITEMS[25].string = "Commandor";
            TEXT_SHOP_ITEMS[25].size = 48;
            
            TEXT_SHOP_ITEMS[26].string = "Zombie";
            TEXT_SHOP_ITEMS[26].size = 48;
            
            TEXT_SHOP_ITEMS[27].string = "Ninja";
            TEXT_SHOP_ITEMS[27].size = 48;
            
            TEXT_SHOP_ITEMS[28].string = "Information not found.";
            TEXT_SHOP_ITEMS[28].size = 48;
            
            TEXT_SHOP_ITEMS[40].string = "Information not found.";
            TEXT_SHOP_ITEMS[40].size = 48;
            
            TEXT_SHOP_ITEMS[41].string = "Information not found.";
            TEXT_SHOP_ITEMS[41].size = 48;
            
            TEXT_SHOP_ITEMS[42].string = "Information not found.";
            TEXT_SHOP_ITEMS[42].size = 48;
            
            TEXT_SHOP_ITEMS[43].string = "Information not found.";
            TEXT_SHOP_ITEMS[43].size = 48;
            
            TEXT_SHOP_ITEMS[44].string = "Information not found.";
            TEXT_SHOP_ITEMS[44].size = 48;
            
            TEXT_SHOP_ITEMS[45].string = "Information not found.";
            TEXT_SHOP_ITEMS[45].size = 48;
            
            TEXT_SHOP_BOUGHT.string = "was unlocked";
            TEXT_SHOP_BOUGHT.size = 48;
            
            TEXT_TAP_TO_CONTINUE.string = "Tap to continue";
            TEXT_TAP_TO_CONTINUE.size = 36;
            
            TEXT_TIP[0].string = "Some items in the shop can be very useful to you";
            TEXT_TIP[1].string = "Use the new weapons that you can buy at the store";
            TEXT_TIP[2].string = "Avoid the bombs hit the Birds";
            TEXT_TIP[3].string = "Some birds are special - look at what they can do";
            TEXT_TIP[4].string = "You will enjoy more than 20 different birds with unique abilities";
            
            TEXT_SHOP_ITEMS_DESCRIPTIONS[0].string = "This is ancient bamboo stick is a talisman and a symbol of truth in the house of old chinaman. Long ago was used as a strong and perhaps the only weapons the Royal Army. Now stick serves as an excellent means to combat flies.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[1].string = "Slat was tear off from favorite doghouse of angry bullterrier. While he was sleeping in the back yard. After finding out about it, he ran in search around of the entire quarter, but did not find her. Now, will be better for you, dont turn up on his way!";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[2].string = "Dubin - cunning raccoon broke the this dubin from branches of eternal tree , around which all forest animals were going on the quiet advice. According to legend, was broken dubin on the tenth night moon will give the his owner strength and longevity.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[3].string = "Shovel - old gardener's shovel Johnny. It not as simple as it seems at first glance. Only with it help you can get a great treasure of old Johnny, who are buried under the blue stone which is in the Green Valley.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[4].string = "Hammer - Stone Hammer of truth. With it, ancient people of the Lost World, builded huts and hunted for food. In crowd, they went on a hunt in search of a mammoth. When they are found his lair, were surrounded it and walked to mortal combat with the beast.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[5].string = "This two-sided ax was a symbol of the absolute power of an old Indian. Axe reminds to the Indian about pasts times, when he go on the greats reds dragons that once in 10 years, come from high dark mountains and burned the indian village.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[6].string = "Magic wand fairy godmother which was found in the hollow of a huge old oak tree which grows on the outskirts next to the dense forest. Be careful, rumored to live there unknown monsters. In all probability, they took the magic wand of fairy godmother and hid it. What's wrong with fairy nobody knows.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[7].string = "At Baseball bat portrayed the first clown of old circus. The audience has loved his performance with trained dinosaurs and flying elephants. As a result, good people decided to portrayed his look on this bat.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[8].string = "Dried fish, which fulfilled the wishes of the royal Family. Was found near the dark side of the fast river, of little gnomes. Be careful and cautious in their whishes, maybe your wish will come true right now!";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[9].string = "Iron mechanical arm, the result of years of secret developments the leading companies in the world in nanotechnologies. It was the beginning of creating a top-secret project - Steel bearings. Now the hand used as an industrial coffee machine.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[10].string = "The legendary Sword of the Jedi, which captured spacecrafts, that there spacecraft - the whole galaxy! His owner endowed unusual strength and abilities, but only until the charge battery is out.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[11].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[12].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[13].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[14].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[15].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[16].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[17].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[18].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[19].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[20].string = "Ice bird has a unique ability to freeze time. It will help you to react quickly at the right time and get as many coins as you can.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[21].string = "When this bird will break the spirit of an Indian will show you where these birds will fly.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[22].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[23].string = "By killing the bird appears chest full of coins or other valuable prize.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[24].string = "Break it and you will fall on the blessed rain of birds.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[25].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[26].string = "Infected birds rest, which leads to a decrease in their health.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[27].string = "This bird here, to slow down the time. You can easily straightened with a mass of other birds.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[28].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[29].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[30].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[31].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[32].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[33].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[34].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[35].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[36].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[37].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[38].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[39].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[40].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[41].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[42].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[43].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[44].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[45].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[46].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[47].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[48].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[49].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[50].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[51].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[52].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[53].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[54].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[55].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[56].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[57].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[58].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[59].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[60].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[61].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[62].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[63].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[64].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[65].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[66].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[67].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[68].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[69].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[70].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[71].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[72].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[73].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[74].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[75].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[76].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[77].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[78].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[79].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[80].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[81].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[82].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[83].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[84].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[85].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[86].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[87].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[88].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[89].string = "Information not found.";

            TEXT_MORE_GAMES.string = "More games";

            TEXT_PUBLISHER_STRING_1.string = "Information for Publisher";
            TEXT_PUBLISHER_STRING_2.string = "This button should open Game Center with the table of players rating. For iOS it's Apple Game Center and for Android it's Google Play Game Services.";
            TEXT_PUBLISHER_STRING_3.string = "This button should open Game Center with the table of players achievements. For iOS it's Apple Game Center and for Android it's Google Play Game Services.";
            TEXT_PUBLISHER_STRING_4.string = "Dear publishers! For your convenience, all in-game purchases are working in Debug mode! You can easily acquire all play good.";
            
            TEXT_BUYITEM_CHOOSE.string = "Select";
            TEXT_BUYITEM_CHOOSE.size = 46;

            TEXT_ITEM_ALREADY_BOUGHT.string = "Already bought";

            TEXT_PAUSE_BACK_TO_SELECT_MODE.string = "Mode choose";
            TEXT_PAUSE_CONTINUE.string = "Continue";

            TEXT_LANGUAGE_NOT_AVAILABLE.string = "Not available now";

            TEXT_GAME_START_STRING_1.string = "Ready?";
            TEXT_GAME_START_STRING_2.string = "Go!";

            TEXT_GAME_CLASSIC_LEVEL_UP.string = "Level up!";
            TEXT_GAME_SOMETHING_WAS_UNLOCKED.string = "Something was unclocked!";
            TEXT_GAME_BEST.string = "";
            TEXT_GAME_ARCADE_TIME_REMAINING.string = "Time remaining:";
            TEXT_GAME_CLASSIC_BONUS_TIME.string = "Bonus time";

            TEXT_EVENTS[0].string = "New record!";
            TEXT_EVENTS[0].size = 42;

            TEXT_EVENTS[30].string = "You have one minute!";
            TEXT_EVENTS[30].size = 42;
            
            TEXT_EVENTS[60].string = "Combo strike!";
            TEXT_EVENTS[60].size = 42;
            
            TEXT_EVENTS[61].string = "Freezee time";
            TEXT_EVENTS[61].size = 42;
            
            TEXT_EVENTS[62].string = "Prediction";
            TEXT_EVENTS[62].size = 42;

            TEXT_PAYMENT_STRING[0].string = "Request processing";
            
            TEXT_UNLOCKLEVEL.string = "You can unlock \n this level just for:";
            TEXT_UNLOCKLEVEL.size = 42;
            
            TEXT_UNLOCKMODE.string = "You can unlock \n this mode just for:";
            TEXT_UNLOCKMODE.size = 42;
            
            TEXT_UNLOCKLEVEL_OK.string = "Unlock";
            TEXT_UNLOCKLEVEL_OK.size = 46;
            
            TEXT_SURPRISE_OK.string = "Start";
            TEXT_SURPRISE_OK.size = 46;
            
            TEXT_SURPRISE.string = "Each gift level \n gives you a opportunity \n to capture a \n unique artifact!";
            TEXT_SURPRISE.size = 42;

            #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

            TEXT_PAYMENT_STRING[1].string = "Your request is being processed by Google Play payment system. This may take some time.";

            #else

            TEXT_PAYMENT_STRING[1].string = "Your request is being processed by Apple Store payment system. This may take some time.";

            #endif

            TEXT_PAYMENT_STRING[2].string = "Your request is \n being processed.";
            TEXT_PAYMENT_STRING[3].string = "Your request is \n being processed..";
            TEXT_PAYMENT_STRING[4].string = "Your request is \n being processed...";
            TEXT_PAYMENT_STRING[5].string = "Cancel";
            
            TEXT_END[0].string = "Excellent!";
            TEXT_END[1].string = "Birds kills: %d";
            TEXT_END[2].string = "Best record: %d";
            TEXT_END[3].string = "Flyers kills: %d";
            TEXT_END[4].string = "Combo hits: %d";
            TEXT_END[5].string = "Critical hits: %d";
            TEXT_END[6].string = "Total coins earned: %d";
            
            TEXT_DAILY_MAP.string = "Daily revenue";
            
            TEXT_COINS_BONUS[0].string = "500";
            TEXT_COINS_BONUS[1].string = "1 000";
            TEXT_COINS_BONUS[2].string = "4 000";
            TEXT_COINS_BONUS[3].string = "8 000";
            TEXT_COINS_BONUS[4].string = "10 000";
            TEXT_COINS_BONUS[5].string = "10";
            TEXT_COINS_BONUS[6].string = "25";
            TEXT_COINS_BONUS[7].string = "50";
            TEXT_COINS_BONUS[8].string = "100";
            TEXT_COINS_BONUS[9].string = "500";
            
            TEXT_MAPDESCRIPTION_CONTINUE.string = "Continue";
            TEXT_MAPDESCRIPTION_TOP.string = "Daily revenue";
            TEXT_MAPDESCRIPTION_BOTTOM.string = "Play everyday and\nget more bonuses\nand prizes, which marked\n on the map!";
            TEXT_MAPDESCRIPTION_MIDDLE.string = "Day - %d";
            
            TEXT_BONUS[0].string = "Good";
            TEXT_BONUS[1].string = "Cool";
            TEXT_BONUS[2].string = "Sweet";
            TEXT_BONUS[3].string = "Great";
            TEXT_BONUS[4].string = "Fantastic";
            TEXT_BONUS[5].string = "Super";
            TEXT_BONUS[6].string = "Awesome";
            TEXT_BONUS[7].string = "Crazy";
            TEXT_BONUS[8].string = "Wild";
            TEXT_BONUS[9].string = "Killer";
            TEXT_BONUS[10].string = "Unbelievable";
            TEXT_BONUS[11].string = "Amazing";
            
            TEXT_LEVELS_EPISODE.string = "Episode %d";
            TEXT_LEVELS_LOCKED.string = "This episode is locked!\nTo unclock this episode you must\ncollect some stars\nat the previous levels:";
            
            TEXT_PROGRESS_TAP_TO_CONTINUE.string = "Tap to continue";
            TEXT_PROGRESS_LEVEL_NUMBER.string = "-= Level - %d =-";
            TEXT_PROGRESS_LEVEL_TASK.string = "Complete the quest and collect\nas many stars to go to the next level.";
            
            TEXT_EPISODES_NAMES[0].string = "Home";
            TEXT_EPISODES_NAMES[1].string = "Robbed";
            TEXT_EPISODES_NAMES[2].string = "Packing";
            TEXT_EPISODES_NAMES[3].string = "Delivery";
            TEXT_EPISODES_NAMES[4].string = "Selling";
            TEXT_EPISODES_NAMES[5].string = "Coming soon";
            
            TEXT_NEED_TO_UNLOCK.string = "You need\n \nto unlock";
            
            TEXT_LEVELS_TASKS[0][0].string = "Gather all the eggs";
            TEXT_LEVELS_TASKS[0][1].string = "Have time to 20 seconds";
            TEXT_LEVELS_TASKS[0][2].string = "Use only one strike";
            
            TEXT_LEVELS_TASKS[1][0].string = "Gather all the eggs";
            TEXT_LEVELS_TASKS[1][1].string = "Collect 4 in a row";
            TEXT_LEVELS_TASKS[1][2].string = "Destroy all the eggs\nafter the previous tasks";
            
            TEXT_LEVELS_TASKS[2][0].string = "Gather all the eggs";
            TEXT_LEVELS_TASKS[2][1].string = "Collect 4 in a row";
            TEXT_LEVELS_TASKS[2][2].string = "Have time to 60 seconds";
            
            TEXT_LEVELS_TASKS[3][0].string = "Gather all the eggs";
            TEXT_LEVELS_TASKS[3][1].string = "Collect 4 in a row";
            TEXT_LEVELS_TASKS[3][2].string = "Have time to 60 seconds";
            
            TEXT_LEVELS_TASKS[4][0].string = "Save 3 stars";
            TEXT_LEVELS_TASKS[4][1].string = "Gather all the eggs";
            TEXT_LEVELS_TASKS[4][2].string = "Destroy all the eggs\nafter the previous tasks";
        break;
        case 1:
            TEXT_LOADING_1.string = "Загрузка... 0%";
            TEXT_LOADING_1.size = 32;
            
            TEXT_LOADING_2.string = "Загрузка... ";
            TEXT_LOADING_2.size = 32;
            
            TEXT_SETTINGS_CREDITS.string = "Об игре";
            TEXT_SETTINGS_CREDITS.size = 64;
            
            TEXT_SETTINGS_PROGRESS.string = "Прогресс";
            TEXT_SETTINGS_PROGRESS.size = 64;
            
            TEXT_SETTINGS_MORE.string = "Больше";
            TEXT_SETTINGS_MORE.size = 64;
            
            TEXT_SETTINGS_LANGUAGE.string = "Язык";
            TEXT_SETTINGS_LANGUAGE.size = 64;
            
            TEXT_BUYITEM_BUY.string = "Купить";
            TEXT_BUYITEM_BUY.size = 46;
            
            TEXT_EXIT_YES.string = "Да";
            TEXT_EXIT_YES.size = 64;
            
            TEXT_EXIT_STRING_1.string = "Вы действительно хотите выйти?\n \nНам будет очень грустно без вас!";
            TEXT_EXIT_STRING_1.size = 48;
            
            TEXT_EXIT_STRING_2.string = "";
            TEXT_EXIT_STRING_2.size = 48;
            
            TEXT_RATE_NOW.string = "Оценить";
            TEXT_RATE_NOW.size = 46;
            
            #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

            TEXT_RATE_STRING_1.string = "Вам понравилась наша игра?\n \nПожалуйста, проголосуйте за нее в Google Play!";
            TEXT_RATE_STRING_1.size = 48;

            #else

            TEXT_RATE_STRING_1.string = "Вам понравилась наша игра?\n \nПожалуйста, проголосуйте за нее в Apple Store!";
            TEXT_RATE_STRING_1.size = 48;

            #endif
            
            TEXT_RATE_STRING_2.string = "";
            TEXT_RATE_STRING_2.size = 48;
            
            TEXT_RATE_STRING_3.string = "";
            TEXT_RATE_STRING_3.size = 48;
            
            TEXT_RATE_STRING_4.string = "";
            TEXT_RATE_STRING_4.size = 48;
            
            TEXT_GETLIVES_STRING_1.string = "У вас закончились экстра жизни!\nВосстановите их или подождите\nпока они восстановятся.";
            TEXT_GETLIVES_STRING_1.size = 32;

            TEXT_GETSHOOTS_STRING_1.string = "У вас закончились удары!\nВосстановите их и получите\nвозможность закончить уровень!";
            TEXT_GETSHOOTS_STRING_1.size = 32;

            TEXT_GETCOINS_STRING_1.string = "Желаете купить\nнесколько монет?";
            TEXT_GETCOINS_STRING_1.size = 48;

            TEXT_GETKEYS_STRING_1.string = "Желаете купить\nнесколько ключей?";
            TEXT_GETKEYS_STRING_1.size = 48;

            TEXT_GETCOINS_STRING_2.string = "Любая покупка\nуберет рекламу!";
            TEXT_GETCOINS_STRING_2.size = 36;
            
            TEXT_GETCOINS_STRING_3.string = "";
            TEXT_GETCOINS_STRING_3.size = 0;
            
            TEXT_GETCOINS_STRING_4.string = "";
            TEXT_GETCOINS_STRING_4.size = 0;
            
            TEXT_GETCOINS_1.string = "$0.99";
            TEXT_GETCOINS_1.font = FONT;
            TEXT_GETCOINS_1.size = 64;
            
            TEXT_GETCOINS_2.string = "$1.99";
            TEXT_GETCOINS_2.font = FONT;
            TEXT_GETCOINS_2.size = 64;
            
            TEXT_GETCOINS_3.string = "$3.99";
            TEXT_GETCOINS_3.font = FONT;
            TEXT_GETCOINS_3.size = 64;
            
            TEXT_GETCOINS_4.string = "$9.99";
            TEXT_GETCOINS_4.size = 64;
            
            TEXT_PROGRESS_STRING_1.string = "Если Вы хотите пройти игру снова, Вы можете сбросить прогресс.";
            TEXT_PROGRESS_STRING_1.size = 48;
            
            TEXT_PROGRESS_RESET.string = "Сбросить";
            TEXT_PROGRESS_RESET.size = 48;
            
            TEXT_RESET_STRING_1.string = "Вы уверены что хотите сбросить прогресс?\n \nВы начнете игру с первого уровня!";
            TEXT_RESET_STRING_1.size = 48;
            
            TEXT_RESET_STRING_2.string = "";
            TEXT_RESET_STRING_2.size = 48;
            
            TEXT_RESET_STRING_3.string = "";
            TEXT_RESET_STRING_3.size = 48;
            
            TEXT_RESET_STRING_4.string = "";
            TEXT_RESET_STRING_4.size = 48;
            
            TEXT_RESET_RESET.string = "Сбросить";
            TEXT_RESET_RESET.size = 40;
            
            TEXT_CREDITS_STRING_1.string = "Об игре";
            TEXT_CREDITS_STRING_1.size = 48;
            
            TEXT_CREDITS_STRING_2.string = ccsf("Версия: %s", Options::VERSION);
            TEXT_CREDITS_STRING_2.size = 36;
            
            TEXT_CREDITS_STRING_3.string = ccsf("Сборка: %d", Options::BUILD);
            TEXT_CREDITS_STRING_3.size = 36;
            
            TEXT_CREDITS_STRING_4.string = "Над игрой работали:";
            TEXT_CREDITS_STRING_4.size = 36;
            
            TEXT_CREDITS_STRING_5.string = "Программисты";
            TEXT_CREDITS_STRING_5.size = 36;
            
            TEXT_CREDITS_STRING_6.string = "Игорь Мац";
            TEXT_CREDITS_STRING_6.size = 32;
            
            TEXT_CREDITS_STRING_7.string = "Дизайнеры";
            TEXT_CREDITS_STRING_7.size = 36;
            
            TEXT_CREDITS_STRING_8.string = "Дмитрий Шейн";
            TEXT_CREDITS_STRING_8.size = 32;
            
            TEXT_CREDITS_STRING_9.string = "Художники";
            TEXT_CREDITS_STRING_9.size = 36;
            
            TEXT_CREDITS_STRING_10.string = "Максим Петров";
            TEXT_CREDITS_STRING_10.size = 32;
            
            TEXT_CREDITS_STRING_11.string = "Вячеслав Шевченко";
            TEXT_CREDITS_STRING_11.size = 32;
            
            TEXT_CREDITS_STRING_12.string = "Маркетологи";
            TEXT_CREDITS_STRING_12.size = 36;
            
            TEXT_CREDITS_STRING_13.string = "Александр Лысенко";
            TEXT_CREDITS_STRING_13.size = 32;
            
            TEXT_SHOP_DESCRIPTION[0].string = "оружие";
            TEXT_SHOP_DESCRIPTION[0].size = 36;
            
            TEXT_SHOP_DESCRIPTION[1].string = "птицы";
            TEXT_SHOP_DESCRIPTION[1].size = 36;
            
            TEXT_SHOP_DESCRIPTION[2].string = "бонусы";
            TEXT_SHOP_DESCRIPTION[2].size = 36;
            
            TEXT_MODE_CLASSIC.string = "Классический";
            TEXT_MODE_CLASSIC.size = 48;
            
            TEXT_MODE_ARCADE.string = "Аркада";
            TEXT_MODE_ARCADE.size = 48;
            
            TEXT_MODE_PROGRESS.string = "Прохождение";
            TEXT_MODE_PROGRESS.size = 48;
            
            TEXT_MODEHELP_OK.string = "Закрыть";
            TEXT_MODEHELP_OK.size = 46;
            
            TEXT_MODEHELP_HELP[0].string = "О режимах";
            TEXT_MODEHELP_HELP[0].size = 48;
            
            TEXT_MODEHELP_HELP[1].string = "Классический режим - режим игры в котором вам предстоит соревноваться с другими игроками, зарабатывать монеты, увеличивать свой глобальный рейтинг и пользоваться заработанными бонусами.\n \nРежим аркады - позволит вам показать на что вы способны за одну минуту! По мере прохождения игры ваши навыки увеличиваются и вы вполне в силах превзойти свой предыдущий рекорд!\n \nПрохождение - это особый режим. Вам доступно 80 уровней (обновления совсем скоро) с различными заданиями. По мере прохождения уровней вам будут открываться новые возможности, которые вы можте использовать в других режимах игры.";
            TEXT_MODEHELP_HELP[1].size = 24;
            
            TEXT_SHOP_ITEMS[0].string = "Бамбуковая палка";
            TEXT_SHOP_ITEMS[0].size = 48;
            
            TEXT_SHOP_ITEMS[1].string = "Доска";
            TEXT_SHOP_ITEMS[1].size = 48;
            
            TEXT_SHOP_ITEMS[2].string = "Дубина";
            TEXT_SHOP_ITEMS[2].size = 48;
            
            TEXT_SHOP_ITEMS[3].string = "Лопата";
            TEXT_SHOP_ITEMS[3].size = 48;
            
            TEXT_SHOP_ITEMS[4].string = "Молот правды";
            TEXT_SHOP_ITEMS[4].size = 48;
            
            TEXT_SHOP_ITEMS[5].string = "Топор всевластия";
            TEXT_SHOP_ITEMS[5].size = 48;
            
            TEXT_SHOP_ITEMS[6].string = "Волшебная палочка";
            TEXT_SHOP_ITEMS[6].size = 48;
            
            TEXT_SHOP_ITEMS[7].string = "Бита клоуна";
            TEXT_SHOP_ITEMS[7].size = 48;
            
            TEXT_SHOP_ITEMS[8].string = "Рыба";
            TEXT_SHOP_ITEMS[8].size = 48;
            
            TEXT_SHOP_ITEMS[9].string = "Механическая рука";
            TEXT_SHOP_ITEMS[9].size = 48;
            
            TEXT_SHOP_ITEMS[10].string = "Меч Джедая";
            TEXT_SHOP_ITEMS[10].size = 48;
            
            TEXT_SHOP_ITEMS[20].string = "Ледяная птица";
            TEXT_SHOP_ITEMS[20].size = 48;
            
            TEXT_SHOP_ITEMS[21].string = "Птица команч";
            TEXT_SHOP_ITEMS[21].size = 48;
            
            TEXT_SHOP_ITEMS[22].string = "Птица робот";
            TEXT_SHOP_ITEMS[22].size = 48;
            
            TEXT_SHOP_ITEMS[23].string = "Птица пират";
            TEXT_SHOP_ITEMS[23].size = 48;
            
            TEXT_SHOP_ITEMS[24].string = "Птица мексиканец";
            TEXT_SHOP_ITEMS[24].size = 48;
            
            TEXT_SHOP_ITEMS[25].string = "Птица командор";
            TEXT_SHOP_ITEMS[25].size = 48;
            
            TEXT_SHOP_ITEMS[26].string = "Птица зомби";
            TEXT_SHOP_ITEMS[26].size = 48;
            
            TEXT_SHOP_ITEMS[27].string = "Ниндзя";
            TEXT_SHOP_ITEMS[27].size = 48;
            
            TEXT_SHOP_ITEMS[28].string = "Информации не найдено";
            TEXT_SHOP_ITEMS[28].size = 48;
            
            TEXT_SHOP_ITEMS[40].string = "Информации не найдено";
            TEXT_SHOP_ITEMS[40].size = 48;
            
            TEXT_SHOP_ITEMS[41].string = "Информации не найдено";
            TEXT_SHOP_ITEMS[41].size = 48;
            
            TEXT_SHOP_ITEMS[42].string = "Информации не найдено";
            TEXT_SHOP_ITEMS[42].size = 48;
            
            TEXT_SHOP_ITEMS[43].string = "Информации не найдено";
            TEXT_SHOP_ITEMS[43].size = 48;
            
            TEXT_SHOP_ITEMS[44].string = "Информации не найдено";
            TEXT_SHOP_ITEMS[44].size = 48;
            
            TEXT_SHOP_ITEMS[45].string = "Информации не найдено";
            TEXT_SHOP_ITEMS[45].size = 48;
            
            TEXT_SHOP_BOUGHT.string = "было куплено";
            TEXT_SHOP_BOUGHT.size = 48;
            
            TEXT_TAP_TO_CONTINUE.string = "Нажмите для продолжения";
            TEXT_TAP_TO_CONTINUE.size = 36;
            
            TEXT_TIP[0].string = "Некоторые элементы в магазине могут быть вам очень полезны";
            TEXT_TIP[1].string = "Используйте новое оружие, которое вы можете купить в магазине";
            TEXT_TIP[2].string = "Избегайте попаданий по птицам бомбочкам";
            TEXT_TIP[3].string = "Некоторые птицы являются особенными - посмотретите на что они способны";
            TEXT_TIP[4].string = "Вас ждет более 20-ти различных птиц  с уникальными способностями";

            TEXT_SHOP_ITEMS_DESCRIPTIONS[0].string = "Эта древняя бамбуковая палица является оберегом и символом правды в доме у старого китайца. Раньше была сильным и пожалуй единственным оружием царской армии. Сейчас же палица служит как отличное средство для борьбы с мухами.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[1].string = "Доска была оторвана от любимой будки злого бультерьера. Пока тот спал на заднем дворе. После обнаружения о пропаже он в поисках оббежал весь квартал, но так и не нашел её. Теперь вам лучше не попадаться ему на пути!";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[2].string = "Хитрый енот выломал её из ветки вечного дерева, возле которого собирались все звери на тихий совет. По поверью, выломанная дубина в ночь на десятую светлую луну придаст обладателю сил и долголетия.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[3].string = "Старая лопата садовника Джонни. Она не так проста, как кажется на первый взгляд. Только с её помощью можно получить огромные сокровища старика Джонни, которые зарыты под голубым камнем в Зеленой Долине.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[4].string = "Каменный молот правды. С его помощью древние жители забытой страны строили себе хижины и добывали еду. Собираясь толпой они ходили на охоту в поисках мамонта. Когда они находили его берлогу, окружали её и шли на смертный бой со зверем.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[5].string = "Этот двух сторонний топор был символом всевластия старого индейца. Топор напоминал индейцу о былых временах, когда он ходил с ним на великих красных драконов, которые раз в 10 лет прилетали со своих высоких темных гор и сжигали деревню индейца.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[6].string = "Ее нашли в дупле старого огромного дуба, вблизи густого дремучего леса. Будьте осторожны, по слухам там живут неведомые чудища. По всей вероятности они отобрали волшебную палочку у доброй феи и спрятали её. Что случилось с феей никому не известно.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[7].string = "На бите изображен первый клоун старого цирка. Зрителям очень нравились его выступления с дрессированными динозаврами и летающими слонами. В результате добрые люди решили увековечить его облик на этой бите.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[8].string = "Та самая рыба из сказки, что желания деда исполняла, когда тот неводом её вытянул. Была найдена у темного берега быстрой реки кучкой маленьких гномов. Будьте внимательны и осторожны в своих желаниях, возможно ваше исполнится прямо сейчас!";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[9].string = "Железная механическая рука, результат многолетних засекреченных разработок ведущих компаний мира в наноиндустрии. Она стала началом создания сверх секретного проекта - Стальной подшипник. Сейчас же руку используют как промышленную кофеварку.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[10].string = "Легендарный Меч Джедая, которым захватывались космические корабли, да что там корабли - целые галактики! Его владельца меч наделял необыкновенной силой и возможностями, но лишь до тех пор пока не сядут батарейки.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[11].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[12].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[13].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[14].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[15].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[16].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[17].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[18].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[19].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[20].string = "Ледяная птица обладает уникальной способностью заморажевать время. Она поможет вам быстро среагировать в нужный момент и получить как можно больше монет.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[21].string = "Когда разобьете эту птицу, дух индейца покажет вам откуда будут вылетать следующие птицы.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[22].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[23].string = "При убийстве этой птицы появляется сундук набитый монетами, либо другой ценный приз.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[24].string = "Разбейте её и на вас обрушится благословенный дождь из птиц.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[25].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[26].string = "Заражает остальных птиц, что приводит к уменьшению их здоровья.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[27].string = "Эта птица здесь, для того чтобы замедлить время. Вы с легкостью расправитесь с массой остальных птиц.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[28].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[29].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[30].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[31].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[32].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[33].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[34].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[35].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[36].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[37].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[38].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[39].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[40].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[41].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[42].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[43].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[44].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[45].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[46].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[47].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[48].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[49].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[50].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[51].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[52].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[53].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[54].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[55].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[56].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[57].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[58].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[59].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[60].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[61].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[62].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[63].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[64].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[65].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[66].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[67].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[68].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[69].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[70].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[71].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[72].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[73].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[74].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[75].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[76].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[77].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[78].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[79].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[80].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[81].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[82].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[83].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[84].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[85].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[86].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[87].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[88].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[89].string = "Информации не найдено.";

            TEXT_MORE_GAMES.string = "Другие игры";

            TEXT_PUBLISHER_STRING_1.string = "Информация для издателей";
            TEXT_PUBLISHER_STRING_2.string = "Данная кнопка должна открывать Game Center с таблицей рейтинга игроков. Для iOS это Apple Game Center, для Android это Google Play Game Services.";
            TEXT_PUBLISHER_STRING_3.string = "Данная кнопка должна открывать Game Center со списком достижений игроков. Для iOS это Apple Game Center, для Android это Google Play Game Services.";
            TEXT_PUBLISHER_STRING_4.string = "Уважаемые издатели! Для вашего удобства все внутриигровые покупки работают в Debug режиме! Вы легко можете приобретать все игровые блага.";
            
            TEXT_BUYITEM_CHOOSE.string = "Выбрать";
            TEXT_BUYITEM_CHOOSE.size = 46;

            TEXT_ITEM_ALREADY_BOUGHT.string = "Уже куплено";

            TEXT_PAUSE_BACK_TO_SELECT_MODE.string = "Выбор режима";
            TEXT_PAUSE_CONTINUE.string = "Продолжить";

            TEXT_LANGUAGE_NOT_AVAILABLE.string = "Не доступно";

            TEXT_GAME_START_STRING_1.string = "Готовы?";
            TEXT_GAME_START_STRING_2.string = "Вперед!";

            TEXT_GAME_CLASSIC_LEVEL_UP.string = "Уровень пройден!";
            TEXT_GAME_SOMETHING_WAS_UNLOCKED.string = "Что-то было открыто";
            TEXT_GAME_BEST.string = "";
            TEXT_GAME_ARCADE_TIME_REMAINING.string = "Времени осталось:";
            TEXT_GAME_CLASSIC_BONUS_TIME.string = "Бонусное время";

            TEXT_EVENTS[0].string = "Новый рекорд!";
            TEXT_EVENTS[0].size = 42;

            TEXT_EVENTS[30].string = "У вас есть минута!";
            TEXT_EVENTS[30].size = 42;
            
            TEXT_EVENTS[60].string = "Комбо удар!";
            TEXT_EVENTS[60].size = 42;
            
            TEXT_EVENTS[61].string = "Заморозка";
            TEXT_EVENTS[61].size = 42;
            
            TEXT_EVENTS[62].string = "Предсказание";
            TEXT_EVENTS[62].size = 42;
            
            TEXT_EVENTS[63].string = "Роботизация";
            TEXT_EVENTS[63].size = 42;

            TEXT_PAYMENT_STRING[0].string = "Обработка запроса";

            #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

            TEXT_PAYMENT_STRING[1].string = "Ваш запрос обрабатывается системой платежей Google Play. Это может занять некоторое время.";

            #else

            TEXT_PAYMENT_STRING[1].string = "Ваш запрос обрабатывается системой платежей Apple Store. Это может занять некоторое время.";

            #endif
            TEXT_PAYMENT_STRING[2].string = "Ваш запрос \n обрабатывается.";
            TEXT_PAYMENT_STRING[3].string = "Ваш запрос \n обрабатывается..";
            TEXT_PAYMENT_STRING[4].string = "Ваш запрос \n обрабатывается...";
            TEXT_PAYMENT_STRING[5].string = "Отмена";
            
            TEXT_END[0].string = "Результаты";
            TEXT_END[1].string = "Результат: %d";
            TEXT_END[2].string = "Рекорд: %d";
            TEXT_END[3].string = "Убито летчиков: %d";
            TEXT_END[4].string = "Комбо ударов: %d";
            TEXT_END[5].string = "Критических ударов: %d";
            TEXT_END[6].string = "Заработано монет: %d";
            
            TEXT_DAILY_MAP.string = "Вознаграждение";
            
            TEXT_COINS_BONUS[0].string = "500";
            TEXT_COINS_BONUS[1].string = "1 000";
            TEXT_COINS_BONUS[2].string = "4 000";
            TEXT_COINS_BONUS[3].string = "8 000";
            TEXT_COINS_BONUS[4].string = "10 000";
            TEXT_COINS_BONUS[5].string = "10";
            TEXT_COINS_BONUS[6].string = "25";
            TEXT_COINS_BONUS[7].string = "50";
            TEXT_COINS_BONUS[8].string = "100";
            TEXT_COINS_BONUS[9].string = "500";
            
            TEXT_UNLOCKLEVEL.string = "Вы можете открыть этот \n уровень всего лишь за \n несколько игровых ключей:";
            TEXT_UNLOCKLEVEL.size = 38;
            
            TEXT_UNLOCKMODE.string = "Вы можете открыть этот \n режим всего лишь за \n несколько игровых ключей:";
            TEXT_UNLOCKMODE.size = 38;
            
            TEXT_UNLOCKLEVEL_OK.string = "Открыть";
            TEXT_UNLOCKLEVEL_OK.size = 46;
            
            TEXT_SURPRISE_OK.string = "Начать";
            TEXT_SURPRISE_OK.size = 46;
            
            TEXT_SURPRISE.string = "Каждый подарочный \n уровень дает вам \n возможность завладеть \n уникальным артефактом!";
            TEXT_SURPRISE.size = 42;
            
            TEXT_MAPDESCRIPTION_CONTINUE.string = "Далее";
            TEXT_MAPDESCRIPTION_TOP.string = "Ежедневное\nвознаграждение";
            TEXT_MAPDESCRIPTION_BOTTOM.string = "Играйте каждый день и\nполучайте больше призов\nи подарков, отмеченых\nна карте!";
            TEXT_MAPDESCRIPTION_MIDDLE.string = "День - %d";
            
            TEXT_BONUS[0].string = "Хорошо";
            TEXT_BONUS[1].string = "Круто";
            TEXT_BONUS[2].string = "Мило";
            TEXT_BONUS[3].string = "Великолепно";
            TEXT_BONUS[4].string = "Фантастически";
            TEXT_BONUS[5].string = "Супер";
            TEXT_BONUS[6].string = "Превосходно";
            TEXT_BONUS[7].string = "Сумасшедше";
            TEXT_BONUS[8].string = "Дико";
            TEXT_BONUS[9].string = "Фантастика";
            TEXT_BONUS[10].string = "Невероятно";
            TEXT_BONUS[11].string = "Красота";
            
            TEXT_LEVELS_EPISODE.string = "Эпизод %d";
            TEXT_LEVELS_LOCKED.string = "Этот эпизод недоступен!\nЧтобы открыть доступ необходимо\nсобрать несколько звезд\nв предыдущих уровнях:";
            
            TEXT_PROGRESS_TAP_TO_CONTINUE.string = "Нажмите для продолжения";
            TEXT_PROGRESS_LEVEL_NUMBER.string = "-= Уровень - %d =-";
            TEXT_PROGRESS_LEVEL_TASK.string = "Выполните задание и соберите\nкак можно больше звезд\nчтобы пройти к следующему уровню.";
            
            TEXT_EPISODES_NAMES[0].string = "Дом";
            TEXT_EPISODES_NAMES[1].string = "Похищение";
            TEXT_EPISODES_NAMES[2].string = "Упаковка";
            TEXT_EPISODES_NAMES[3].string = "Доставка";
            TEXT_EPISODES_NAMES[4].string = "Продажа";
            TEXT_EPISODES_NAMES[5].string = "Новые эпизоды\nсовсем скоро!";
            
            TEXT_NEED_TO_UNLOCK.string = "Вам необоходимо\n \nдля доступа";
            
            TEXT_LEVELS_TASKS[0][0].string = "Соберите все яйца";
            TEXT_LEVELS_TASKS[0][1].string = "Успейте за 20 секунд";
            TEXT_LEVELS_TASKS[0][2].string = "Используйте только\nодин удар";
            
            TEXT_LEVELS_TASKS[1][0].string = "Соберите все яйца";
            TEXT_LEVELS_TASKS[1][1].string = "Соберите 4 в ряд";
            TEXT_LEVELS_TASKS[1][2].string = "Уничтожте все яйца\nпосле выполнения задания";
            
            TEXT_LEVELS_TASKS[2][0].string = "Соберите все яйца";
            TEXT_LEVELS_TASKS[2][1].string = "Соберите 4 в ряд";
            TEXT_LEVELS_TASKS[2][2].string = "Успейте за 60 секунд";
            
            TEXT_LEVELS_TASKS[3][0].string = "Соберите все яйца";
            TEXT_LEVELS_TASKS[3][1].string = "Соберите 4 в ряд";
            TEXT_LEVELS_TASKS[3][2].string = "Успейте за 60 секунд";
            
            TEXT_LEVELS_TASKS[4][0].string = "Спасите 3 звездочки";
            TEXT_LEVELS_TASKS[4][1].string = "Соберите все яйца";
            TEXT_LEVELS_TASKS[4][2].string = "Уничтожте все яйца\nпосле выполнения задания";
        break;
    }
    
    TEXTES_HOLDER[0] = TEXT_LOADING_1;
    TEXTES_HOLDER[1] = TEXT_LOADING_2;
    TEXTES_HOLDER[2] = TEXT_SETTINGS_CREDITS;
    TEXTES_HOLDER[3] = TEXT_SETTINGS_PROGRESS;
    TEXTES_HOLDER[4] = TEXT_SETTINGS_MORE;
    TEXTES_HOLDER[5] = TEXT_SETTINGS_LANGUAGE;
    TEXTES_HOLDER[6] = TEXT_BUYITEM_BUY;
    TEXTES_HOLDER[7] = TEXT_EXIT_YES;
    TEXTES_HOLDER[8] = TEXT_EXIT_STRING_1;
    TEXTES_HOLDER[9] = TEXT_EXIT_STRING_2;
    TEXTES_HOLDER[10] = TEXT_RATE_NOW;
    TEXTES_HOLDER[11] = TEXT_RATE_STRING_1;
    TEXTES_HOLDER[12] = TEXT_RATE_STRING_2;
    TEXTES_HOLDER[13] = TEXT_RATE_STRING_3;
    TEXTES_HOLDER[14] = TEXT_RATE_STRING_4;
    TEXTES_HOLDER[15] = TEXT_GETCOINS_STRING_1;
    TEXTES_HOLDER[16] = TEXT_GETCOINS_STRING_2;
    TEXTES_HOLDER[17] = TEXT_GETCOINS_1;
    TEXTES_HOLDER[18] = TEXT_GETCOINS_2;
    TEXTES_HOLDER[19] = TEXT_GETCOINS_3;
    TEXTES_HOLDER[20] = TEXT_GETCOINS_4;
    TEXTES_HOLDER[21] = TEXT_PROGRESS_STRING_1;
    TEXTES_HOLDER[24] = TEXT_PROGRESS_RESET;
    TEXTES_HOLDER[25] = TEXT_RESET_STRING_1;
    TEXTES_HOLDER[26] = TEXT_RESET_STRING_2;
    TEXTES_HOLDER[27] = TEXT_RESET_STRING_3;
    TEXTES_HOLDER[28] = TEXT_RESET_STRING_4;
    TEXTES_HOLDER[29] = TEXT_RESET_RESET;
    TEXTES_HOLDER[30] = TEXT_CREDITS_STRING_1;
    TEXTES_HOLDER[31] = TEXT_CREDITS_STRING_2;
    TEXTES_HOLDER[32] = TEXT_CREDITS_STRING_3;
    TEXTES_HOLDER[33] = TEXT_CREDITS_STRING_4;
    TEXTES_HOLDER[34] = TEXT_CREDITS_STRING_5;
    TEXTES_HOLDER[35] = TEXT_CREDITS_STRING_6;
    TEXTES_HOLDER[36] = TEXT_CREDITS_STRING_7;
    TEXTES_HOLDER[37] = TEXT_CREDITS_STRING_8;
    TEXTES_HOLDER[38] = TEXT_CREDITS_STRING_9;
    TEXTES_HOLDER[39] = TEXT_CREDITS_STRING_10;
    TEXTES_HOLDER[40] = TEXT_CREDITS_STRING_11;
    TEXTES_HOLDER[41] = TEXT_CREDITS_STRING_12;
    TEXTES_HOLDER[42] = TEXT_CREDITS_STRING_13;
    TEXTES_HOLDER[43] = TEXT_SHOP_DESCRIPTION[0];
    TEXTES_HOLDER[44] = TEXT_SHOP_DESCRIPTION[1];
    TEXTES_HOLDER[45] = TEXT_SHOP_DESCRIPTION[2];
    TEXTES_HOLDER[46] = TEXT_MODE_CLASSIC;
    TEXTES_HOLDER[47] = TEXT_MODE_ARCADE;
    TEXTES_HOLDER[48] = TEXT_MODE_PROGRESS;
    TEXTES_HOLDER[49] = TEXT_MODEHELP_OK;
    TEXTES_HOLDER[50] = TEXT_MODEHELP_HELP[0];
    TEXTES_HOLDER[51] = TEXT_MODEHELP_HELP[1];
    TEXTES_HOLDER[52] = TEXT_GETCOINS_STRING_3;
    TEXTES_HOLDER[53] = TEXT_GETCOINS_STRING_4;
    TEXTES_HOLDER[54] = TEXT_SHOP_ITEMS[0];
    TEXTES_HOLDER[55] = TEXT_SHOP_ITEMS[1];
    TEXTES_HOLDER[56] = TEXT_SHOP_ITEMS[2];
    TEXTES_HOLDER[57] = TEXT_SHOP_ITEMS[3];
    TEXTES_HOLDER[58] = TEXT_SHOP_ITEMS[4];
    TEXTES_HOLDER[59] = TEXT_SHOP_ITEMS[5];
    TEXTES_HOLDER[60] = TEXT_SHOP_ITEMS[6];
    TEXTES_HOLDER[61] = TEXT_SHOP_ITEMS[7];
    TEXTES_HOLDER[62] = TEXT_SHOP_ITEMS[8];
    TEXTES_HOLDER[63] = TEXT_SHOP_ITEMS[9];
    TEXTES_HOLDER[64] = TEXT_SHOP_ITEMS[10];
    TEXTES_HOLDER[65] = TEXT_SHOP_ITEMS[11];
    TEXTES_HOLDER[66] = TEXT_SHOP_ITEMS[12];
    TEXTES_HOLDER[67] = TEXT_SHOP_ITEMS[13];
    TEXTES_HOLDER[68] = TEXT_SHOP_ITEMS[14];
    TEXTES_HOLDER[69] = TEXT_SHOP_ITEMS[15];
    TEXTES_HOLDER[70] = TEXT_SHOP_ITEMS[16];
    TEXTES_HOLDER[71] = TEXT_SHOP_ITEMS[17];
    TEXTES_HOLDER[72] = TEXT_SHOP_ITEMS[18];
    TEXTES_HOLDER[73] = TEXT_SHOP_ITEMS[19];
    TEXTES_HOLDER[74] = TEXT_SHOP_ITEMS[20];
    TEXTES_HOLDER[75] = TEXT_SHOP_ITEMS[21];
    TEXTES_HOLDER[76] = TEXT_SHOP_ITEMS[22];
    TEXTES_HOLDER[77] = TEXT_SHOP_ITEMS[23];
    TEXTES_HOLDER[78] = TEXT_SHOP_ITEMS[24];
    TEXTES_HOLDER[79] = TEXT_SHOP_ITEMS[25];
    TEXTES_HOLDER[80] = TEXT_SHOP_ITEMS[26];
    TEXTES_HOLDER[81] = TEXT_SHOP_ITEMS[27];
    TEXTES_HOLDER[82] = TEXT_SHOP_ITEMS[28];
    TEXTES_HOLDER[83] = TEXT_SHOP_ITEMS[29];
    TEXTES_HOLDER[84] = TEXT_SHOP_ITEMS[30];
    TEXTES_HOLDER[85] = TEXT_SHOP_ITEMS[31];
    TEXTES_HOLDER[86] = TEXT_SHOP_ITEMS[32];
    TEXTES_HOLDER[87] = TEXT_SHOP_ITEMS[33];
    TEXTES_HOLDER[88] = TEXT_SHOP_ITEMS[34];
    TEXTES_HOLDER[89] = TEXT_SHOP_ITEMS[35];
    TEXTES_HOLDER[90] = TEXT_SHOP_ITEMS[36];
    TEXTES_HOLDER[91] = TEXT_SHOP_ITEMS[37];
    TEXTES_HOLDER[92] = TEXT_SHOP_ITEMS[38];
    TEXTES_HOLDER[93] = TEXT_SHOP_ITEMS[39];
    TEXTES_HOLDER[94] = TEXT_SHOP_ITEMS[40];
    TEXTES_HOLDER[95] = TEXT_SHOP_ITEMS[41];
    TEXTES_HOLDER[96] = TEXT_SHOP_ITEMS[42];
    TEXTES_HOLDER[97] = TEXT_SHOP_ITEMS[43];
    TEXTES_HOLDER[98] = TEXT_SHOP_ITEMS[44];
    TEXTES_HOLDER[99] = TEXT_SHOP_ITEMS[45];
    TEXTES_HOLDER[100] = TEXT_SHOP_ITEMS[46];
    TEXTES_HOLDER[101] = TEXT_SHOP_ITEMS[47];
    TEXTES_HOLDER[102] = TEXT_SHOP_ITEMS[48];
    TEXTES_HOLDER[103] = TEXT_SHOP_ITEMS[49];
    TEXTES_HOLDER[104] = TEXT_SHOP_ITEMS[50];
    TEXTES_HOLDER[105] = TEXT_SHOP_ITEMS[51];
    TEXTES_HOLDER[106] = TEXT_SHOP_ITEMS[52];
    TEXTES_HOLDER[107] = TEXT_SHOP_ITEMS[53];
    TEXTES_HOLDER[108] = TEXT_SHOP_ITEMS[54];
    TEXTES_HOLDER[109] = TEXT_SHOP_ITEMS[55];
    TEXTES_HOLDER[110] = TEXT_SHOP_ITEMS[56];
    TEXTES_HOLDER[111] = TEXT_SHOP_ITEMS[57];
    TEXTES_HOLDER[112] = TEXT_SHOP_ITEMS[58];
    TEXTES_HOLDER[113] = TEXT_SHOP_ITEMS[59];
    TEXTES_HOLDER[114] = TEXT_SHOP_ITEMS[60];
    TEXTES_HOLDER[115] = TEXT_SHOP_ITEMS[61];
    TEXTES_HOLDER[116] = TEXT_SHOP_ITEMS[62];
    TEXTES_HOLDER[117] = TEXT_SHOP_ITEMS[63];
    TEXTES_HOLDER[118] = TEXT_SHOP_ITEMS[64];
    TEXTES_HOLDER[119] = TEXT_SHOP_ITEMS[65];
    TEXTES_HOLDER[120] = TEXT_SHOP_ITEMS[66];
    TEXTES_HOLDER[121] = TEXT_SHOP_ITEMS[67];
    TEXTES_HOLDER[122] = TEXT_SHOP_ITEMS[68];
    TEXTES_HOLDER[123] = TEXT_SHOP_ITEMS[69];
    TEXTES_HOLDER[124] = TEXT_SHOP_ITEMS[70];
    TEXTES_HOLDER[125] = TEXT_SHOP_ITEMS[71];
    TEXTES_HOLDER[126] = TEXT_SHOP_ITEMS[72];
    TEXTES_HOLDER[127] = TEXT_SHOP_ITEMS[73];
    TEXTES_HOLDER[128] = TEXT_SHOP_ITEMS[74];
    TEXTES_HOLDER[129] = TEXT_SHOP_ITEMS[75];
    TEXTES_HOLDER[130] = TEXT_SHOP_ITEMS[76];
    TEXTES_HOLDER[131] = TEXT_SHOP_ITEMS[77];
    TEXTES_HOLDER[132] = TEXT_SHOP_ITEMS[78];
    TEXTES_HOLDER[133] = TEXT_SHOP_ITEMS[79];
    TEXTES_HOLDER[134] = TEXT_SHOP_ITEMS[80];
    TEXTES_HOLDER[135] = TEXT_SHOP_ITEMS[81];
    TEXTES_HOLDER[136] = TEXT_SHOP_ITEMS[82];
    TEXTES_HOLDER[137] = TEXT_SHOP_ITEMS[83];
    TEXTES_HOLDER[138] = TEXT_SHOP_ITEMS[84];
    TEXTES_HOLDER[139] = TEXT_SHOP_ITEMS[85];
    TEXTES_HOLDER[140] = TEXT_SHOP_ITEMS[86];
    TEXTES_HOLDER[141] = TEXT_SHOP_ITEMS[87];
    TEXTES_HOLDER[142] = TEXT_SHOP_ITEMS[88];
    TEXTES_HOLDER[143] = TEXT_SHOP_ITEMS[89];

    TEXTES_HOLDER[144] = TEXT_SHOP_BOUGHT;
    TEXTES_HOLDER[145] = TEXT_TAP_TO_CONTINUE;
    TEXTES_HOLDER[146] = TEXT_TIP[0];
    TEXTES_HOLDER[147] = TEXT_TIP[1];
    TEXTES_HOLDER[148] = TEXT_TIP[2];
    TEXTES_HOLDER[149] = TEXT_TIP[3];
    TEXTES_HOLDER[150] = TEXT_TIP[4];
    TEXTES_HOLDER[151] = TEXT_TIP[5];
    TEXTES_HOLDER[152] = TEXT_TIP[6];
    TEXTES_HOLDER[153] = TEXT_TIP[7];
    TEXTES_HOLDER[154] = TEXT_TIP[8];
    TEXTES_HOLDER[155] = TEXT_TIP[9];

    TEXTES_HOLDER[156] = TEXT_SHOP_ITEMS_DESCRIPTIONS[0];
    TEXTES_HOLDER[157] = TEXT_SHOP_ITEMS_DESCRIPTIONS[1];
    TEXTES_HOLDER[158] = TEXT_SHOP_ITEMS_DESCRIPTIONS[2];
    TEXTES_HOLDER[159] = TEXT_SHOP_ITEMS_DESCRIPTIONS[3];
    TEXTES_HOLDER[160] = TEXT_SHOP_ITEMS_DESCRIPTIONS[4];
    TEXTES_HOLDER[161] = TEXT_SHOP_ITEMS_DESCRIPTIONS[5];
    TEXTES_HOLDER[162] = TEXT_SHOP_ITEMS_DESCRIPTIONS[6];
    TEXTES_HOLDER[163] = TEXT_SHOP_ITEMS_DESCRIPTIONS[7];
    TEXTES_HOLDER[164] = TEXT_SHOP_ITEMS_DESCRIPTIONS[8];
    TEXTES_HOLDER[165] = TEXT_SHOP_ITEMS_DESCRIPTIONS[9];
    TEXTES_HOLDER[166] = TEXT_SHOP_ITEMS_DESCRIPTIONS[10];
    TEXTES_HOLDER[167] = TEXT_SHOP_ITEMS_DESCRIPTIONS[11];
    TEXTES_HOLDER[168] = TEXT_SHOP_ITEMS_DESCRIPTIONS[12];
    TEXTES_HOLDER[169] = TEXT_SHOP_ITEMS_DESCRIPTIONS[13];
    TEXTES_HOLDER[170] = TEXT_SHOP_ITEMS_DESCRIPTIONS[14];
    TEXTES_HOLDER[171] = TEXT_SHOP_ITEMS_DESCRIPTIONS[15];
    TEXTES_HOLDER[172] = TEXT_SHOP_ITEMS_DESCRIPTIONS[16];
    TEXTES_HOLDER[173] = TEXT_SHOP_ITEMS_DESCRIPTIONS[17];
    TEXTES_HOLDER[174] = TEXT_SHOP_ITEMS_DESCRIPTIONS[18];
    TEXTES_HOLDER[175] = TEXT_SHOP_ITEMS_DESCRIPTIONS[19];
    TEXTES_HOLDER[176] = TEXT_SHOP_ITEMS_DESCRIPTIONS[20];
    TEXTES_HOLDER[177] = TEXT_SHOP_ITEMS_DESCRIPTIONS[21];
    TEXTES_HOLDER[178] = TEXT_SHOP_ITEMS_DESCRIPTIONS[22];
    TEXTES_HOLDER[179] = TEXT_SHOP_ITEMS_DESCRIPTIONS[23];
    TEXTES_HOLDER[180] = TEXT_SHOP_ITEMS_DESCRIPTIONS[24];
    TEXTES_HOLDER[181] = TEXT_SHOP_ITEMS_DESCRIPTIONS[25];
    TEXTES_HOLDER[182] = TEXT_SHOP_ITEMS_DESCRIPTIONS[26];
    TEXTES_HOLDER[183] = TEXT_SHOP_ITEMS_DESCRIPTIONS[27];
    TEXTES_HOLDER[184] = TEXT_SHOP_ITEMS_DESCRIPTIONS[28];
    TEXTES_HOLDER[185] = TEXT_SHOP_ITEMS_DESCRIPTIONS[29];
    TEXTES_HOLDER[186] = TEXT_SHOP_ITEMS_DESCRIPTIONS[30];
    TEXTES_HOLDER[187] = TEXT_SHOP_ITEMS_DESCRIPTIONS[31];
    TEXTES_HOLDER[188] = TEXT_SHOP_ITEMS_DESCRIPTIONS[32];
    TEXTES_HOLDER[189] = TEXT_SHOP_ITEMS_DESCRIPTIONS[33];
    TEXTES_HOLDER[190] = TEXT_SHOP_ITEMS_DESCRIPTIONS[34];
    TEXTES_HOLDER[191] = TEXT_SHOP_ITEMS_DESCRIPTIONS[35];
    TEXTES_HOLDER[192] = TEXT_SHOP_ITEMS_DESCRIPTIONS[36];
    TEXTES_HOLDER[193] = TEXT_SHOP_ITEMS_DESCRIPTIONS[37];
    TEXTES_HOLDER[194] = TEXT_SHOP_ITEMS_DESCRIPTIONS[38];
    TEXTES_HOLDER[195] = TEXT_SHOP_ITEMS_DESCRIPTIONS[39];
    TEXTES_HOLDER[196] = TEXT_SHOP_ITEMS_DESCRIPTIONS[40];
    TEXTES_HOLDER[197] = TEXT_SHOP_ITEMS_DESCRIPTIONS[41];
    TEXTES_HOLDER[198] = TEXT_SHOP_ITEMS_DESCRIPTIONS[42];
    TEXTES_HOLDER[199] = TEXT_SHOP_ITEMS_DESCRIPTIONS[43];
    TEXTES_HOLDER[200] = TEXT_SHOP_ITEMS_DESCRIPTIONS[44];
    TEXTES_HOLDER[201] = TEXT_SHOP_ITEMS_DESCRIPTIONS[45];
    TEXTES_HOLDER[202] = TEXT_SHOP_ITEMS_DESCRIPTIONS[46];
    TEXTES_HOLDER[203] = TEXT_SHOP_ITEMS_DESCRIPTIONS[47];
    TEXTES_HOLDER[204] = TEXT_SHOP_ITEMS_DESCRIPTIONS[48];
    TEXTES_HOLDER[205] = TEXT_SHOP_ITEMS_DESCRIPTIONS[49];
    TEXTES_HOLDER[206] = TEXT_SHOP_ITEMS_DESCRIPTIONS[50];
    TEXTES_HOLDER[207] = TEXT_SHOP_ITEMS_DESCRIPTIONS[51];
    TEXTES_HOLDER[208] = TEXT_SHOP_ITEMS_DESCRIPTIONS[52];
    TEXTES_HOLDER[209] = TEXT_SHOP_ITEMS_DESCRIPTIONS[53];
    TEXTES_HOLDER[210] = TEXT_SHOP_ITEMS_DESCRIPTIONS[54];
    TEXTES_HOLDER[211] = TEXT_SHOP_ITEMS_DESCRIPTIONS[55];
    TEXTES_HOLDER[212] = TEXT_SHOP_ITEMS_DESCRIPTIONS[56];
    TEXTES_HOLDER[213] = TEXT_SHOP_ITEMS_DESCRIPTIONS[57];
    TEXTES_HOLDER[214] = TEXT_SHOP_ITEMS_DESCRIPTIONS[58];
    TEXTES_HOLDER[215] = TEXT_SHOP_ITEMS_DESCRIPTIONS[59];
    TEXTES_HOLDER[216] = TEXT_SHOP_ITEMS_DESCRIPTIONS[60];
    TEXTES_HOLDER[217] = TEXT_SHOP_ITEMS_DESCRIPTIONS[61];
    TEXTES_HOLDER[218] = TEXT_SHOP_ITEMS_DESCRIPTIONS[62];
    TEXTES_HOLDER[219] = TEXT_SHOP_ITEMS_DESCRIPTIONS[63];
    TEXTES_HOLDER[220] = TEXT_SHOP_ITEMS_DESCRIPTIONS[64];
    TEXTES_HOLDER[221] = TEXT_SHOP_ITEMS_DESCRIPTIONS[65];
    TEXTES_HOLDER[222] = TEXT_SHOP_ITEMS_DESCRIPTIONS[66];
    TEXTES_HOLDER[223] = TEXT_SHOP_ITEMS_DESCRIPTIONS[67];
    TEXTES_HOLDER[224] = TEXT_SHOP_ITEMS_DESCRIPTIONS[68];
    TEXTES_HOLDER[225] = TEXT_SHOP_ITEMS_DESCRIPTIONS[69];
    TEXTES_HOLDER[226] = TEXT_SHOP_ITEMS_DESCRIPTIONS[70];
    TEXTES_HOLDER[227] = TEXT_SHOP_ITEMS_DESCRIPTIONS[71];
    TEXTES_HOLDER[228] = TEXT_SHOP_ITEMS_DESCRIPTIONS[72];
    TEXTES_HOLDER[229] = TEXT_SHOP_ITEMS_DESCRIPTIONS[73];
    TEXTES_HOLDER[230] = TEXT_SHOP_ITEMS_DESCRIPTIONS[74];
    TEXTES_HOLDER[231] = TEXT_SHOP_ITEMS_DESCRIPTIONS[75];
    TEXTES_HOLDER[232] = TEXT_SHOP_ITEMS_DESCRIPTIONS[76];
    TEXTES_HOLDER[233] = TEXT_SHOP_ITEMS_DESCRIPTIONS[77];
    TEXTES_HOLDER[234] = TEXT_SHOP_ITEMS_DESCRIPTIONS[78];
    TEXTES_HOLDER[235] = TEXT_SHOP_ITEMS_DESCRIPTIONS[79];
    TEXTES_HOLDER[236] = TEXT_SHOP_ITEMS_DESCRIPTIONS[80];
    TEXTES_HOLDER[237] = TEXT_SHOP_ITEMS_DESCRIPTIONS[81];
    TEXTES_HOLDER[238] = TEXT_SHOP_ITEMS_DESCRIPTIONS[82];
    TEXTES_HOLDER[239] = TEXT_SHOP_ITEMS_DESCRIPTIONS[83];
    TEXTES_HOLDER[240] = TEXT_SHOP_ITEMS_DESCRIPTIONS[84];
    TEXTES_HOLDER[241] = TEXT_SHOP_ITEMS_DESCRIPTIONS[85];
    TEXTES_HOLDER[242] = TEXT_SHOP_ITEMS_DESCRIPTIONS[86];
    TEXTES_HOLDER[243] = TEXT_SHOP_ITEMS_DESCRIPTIONS[87];
    TEXTES_HOLDER[244] = TEXT_SHOP_ITEMS_DESCRIPTIONS[88];
    TEXTES_HOLDER[245] = TEXT_SHOP_ITEMS_DESCRIPTIONS[89];
    TEXTES_HOLDER[246] = TEXT_MORE_GAMES;
    TEXTES_HOLDER[247] = TEXT_PUBLISHER_STRING_1;
    TEXTES_HOLDER[248] = TEXT_PUBLISHER_STRING_2;
    TEXTES_HOLDER[249] = TEXT_PUBLISHER_STRING_3;
    TEXTES_HOLDER[250] = TEXT_BUYITEM_CHOOSE;
    TEXTES_HOLDER[251] = TEXT_ITEM_ALREADY_BOUGHT;
    TEXTES_HOLDER[252] = TEXT_PAUSE_BACK_TO_SELECT_MODE;
    TEXTES_HOLDER[253] = TEXT_PAUSE_CONTINUE;
    TEXTES_HOLDER[254] = TEXT_LANGUAGE_NOT_AVAILABLE;
    TEXTES_HOLDER[255] = TEXT_GAME_START_STRING_1;
    TEXTES_HOLDER[256] = TEXT_GAME_START_STRING_2;
    TEXTES_HOLDER[257] = TEXT_GAME_CLASSIC_LEVEL_UP;
    TEXTES_HOLDER[258] = TEXT_GAME_SOMETHING_WAS_UNLOCKED;
    TEXTES_HOLDER[259] = TEXT_GAME_BEST;
    TEXTES_HOLDER[260] = TEXT_GAME_ARCADE_TIME_REMAINING;
    TEXTES_HOLDER[261] = TEXT_EVENTS[0];
    TEXTES_HOLDER[262] = TEXT_EVENTS[1];
    TEXTES_HOLDER[263] = TEXT_EVENTS[2];
    TEXTES_HOLDER[264] = TEXT_EVENTS[3];
    TEXTES_HOLDER[265] = TEXT_EVENTS[4];
    TEXTES_HOLDER[266] = TEXT_EVENTS[5];
    TEXTES_HOLDER[267] = TEXT_EVENTS[6];
    TEXTES_HOLDER[268] = TEXT_EVENTS[7];
    TEXTES_HOLDER[269] = TEXT_EVENTS[8];
    TEXTES_HOLDER[270] = TEXT_EVENTS[9];
    TEXTES_HOLDER[271] = TEXT_EVENTS[10];
    TEXTES_HOLDER[272] = TEXT_EVENTS[11];
    TEXTES_HOLDER[273] = TEXT_EVENTS[12];
    TEXTES_HOLDER[274] = TEXT_EVENTS[13];
    TEXTES_HOLDER[275] = TEXT_EVENTS[14];
    TEXTES_HOLDER[276] = TEXT_EVENTS[15];
    TEXTES_HOLDER[277] = TEXT_EVENTS[16];
    TEXTES_HOLDER[278] = TEXT_EVENTS[17];
    TEXTES_HOLDER[279] = TEXT_EVENTS[18];
    TEXTES_HOLDER[280] = TEXT_EVENTS[19];
    TEXTES_HOLDER[281] = TEXT_EVENTS[20];
    TEXTES_HOLDER[282] = TEXT_EVENTS[21];
    TEXTES_HOLDER[283] = TEXT_EVENTS[22];
    TEXTES_HOLDER[284] = TEXT_EVENTS[23];
    TEXTES_HOLDER[285] = TEXT_EVENTS[24];
    TEXTES_HOLDER[286] = TEXT_EVENTS[25];
    TEXTES_HOLDER[287] = TEXT_EVENTS[26];
    TEXTES_HOLDER[288] = TEXT_EVENTS[27];
    TEXTES_HOLDER[289] = TEXT_EVENTS[28];
    TEXTES_HOLDER[290] = TEXT_EVENTS[29];
    TEXTES_HOLDER[291] = TEXT_EVENTS[30];
    TEXTES_HOLDER[292] = TEXT_EVENTS[31];
    TEXTES_HOLDER[293] = TEXT_EVENTS[32];
    TEXTES_HOLDER[294] = TEXT_EVENTS[33];
    TEXTES_HOLDER[295] = TEXT_EVENTS[34];
    TEXTES_HOLDER[296] = TEXT_EVENTS[35];
    TEXTES_HOLDER[297] = TEXT_EVENTS[36];
    TEXTES_HOLDER[298] = TEXT_EVENTS[37];
    TEXTES_HOLDER[299] = TEXT_EVENTS[38];
    TEXTES_HOLDER[300] = TEXT_EVENTS[39];
    TEXTES_HOLDER[301] = TEXT_EVENTS[40];
    TEXTES_HOLDER[302] = TEXT_EVENTS[41];
    TEXTES_HOLDER[303] = TEXT_EVENTS[42];
    TEXTES_HOLDER[304] = TEXT_EVENTS[43];
    TEXTES_HOLDER[305] = TEXT_EVENTS[44];
    TEXTES_HOLDER[306] = TEXT_EVENTS[45];
    TEXTES_HOLDER[307] = TEXT_EVENTS[46];
    TEXTES_HOLDER[308] = TEXT_EVENTS[47];
    TEXTES_HOLDER[309] = TEXT_EVENTS[48];
    TEXTES_HOLDER[310] = TEXT_EVENTS[49];
    TEXTES_HOLDER[311] = TEXT_EVENTS[50];
    TEXTES_HOLDER[312] = TEXT_EVENTS[51];
    TEXTES_HOLDER[313] = TEXT_EVENTS[52];
    TEXTES_HOLDER[314] = TEXT_EVENTS[53];
    TEXTES_HOLDER[315] = TEXT_EVENTS[54];
    TEXTES_HOLDER[316] = TEXT_EVENTS[55];
    TEXTES_HOLDER[317] = TEXT_EVENTS[56];
    TEXTES_HOLDER[318] = TEXT_EVENTS[57];
    TEXTES_HOLDER[319] = TEXT_EVENTS[58];
    TEXTES_HOLDER[320] = TEXT_EVENTS[59];
    TEXTES_HOLDER[321] = TEXT_EVENTS[60];
    TEXTES_HOLDER[322] = TEXT_EVENTS[61];
    TEXTES_HOLDER[323] = TEXT_EVENTS[62];
    TEXTES_HOLDER[324] = TEXT_EVENTS[63];
    TEXTES_HOLDER[325] = TEXT_EVENTS[64];
    TEXTES_HOLDER[326] = TEXT_EVENTS[65];
    TEXTES_HOLDER[327] = TEXT_EVENTS[66];
    TEXTES_HOLDER[328] = TEXT_EVENTS[67];
    TEXTES_HOLDER[329] = TEXT_EVENTS[68];
    TEXTES_HOLDER[330] = TEXT_EVENTS[69];
    TEXTES_HOLDER[331] = TEXT_EVENTS[70];
    TEXTES_HOLDER[332] = TEXT_EVENTS[71];
    TEXTES_HOLDER[333] = TEXT_EVENTS[72];
    TEXTES_HOLDER[334] = TEXT_EVENTS[73];
    TEXTES_HOLDER[335] = TEXT_EVENTS[74];
    TEXTES_HOLDER[336] = TEXT_EVENTS[75];
    TEXTES_HOLDER[337] = TEXT_EVENTS[76];
    TEXTES_HOLDER[338] = TEXT_EVENTS[77];
    TEXTES_HOLDER[339] = TEXT_EVENTS[78];
    TEXTES_HOLDER[340] = TEXT_EVENTS[79];
    TEXTES_HOLDER[341] = TEXT_EVENTS[80];
    TEXTES_HOLDER[342] = TEXT_EVENTS[81];
    TEXTES_HOLDER[343] = TEXT_EVENTS[82];
    TEXTES_HOLDER[344] = TEXT_EVENTS[83];
    TEXTES_HOLDER[345] = TEXT_EVENTS[84];
    TEXTES_HOLDER[346] = TEXT_EVENTS[85];
    TEXTES_HOLDER[347] = TEXT_EVENTS[86];
    TEXTES_HOLDER[348] = TEXT_EVENTS[87];
    TEXTES_HOLDER[349] = TEXT_EVENTS[88];
    TEXTES_HOLDER[350] = TEXT_EVENTS[89];
    TEXTES_HOLDER[351] = TEXT_GAME_CLASSIC_BONUS_TIME;
    TEXTES_HOLDER[352] = TEXT_PAYMENT_STRING[0];
    TEXTES_HOLDER[353] = TEXT_PAYMENT_STRING[1];
    TEXTES_HOLDER[354] = TEXT_PAYMENT_STRING[2];
    TEXTES_HOLDER[355] = TEXT_PAYMENT_STRING[3];
    TEXTES_HOLDER[356] = TEXT_PAYMENT_STRING[4];
    TEXTES_HOLDER[357] = TEXT_PAYMENT_STRING[5];
    TEXTES_HOLDER[358] = TEXT_END[0];
    TEXTES_HOLDER[359] = TEXT_END[1];
    TEXTES_HOLDER[360] = TEXT_END[2];
    TEXTES_HOLDER[361] = TEXT_END[3];
    TEXTES_HOLDER[362] = TEXT_END[4];
    TEXTES_HOLDER[363] = TEXT_END[5];
    TEXTES_HOLDER[364] = TEXT_END[6];
    TEXTES_HOLDER[365] = TEXT_DAILY_MAP;
    TEXTES_HOLDER[366] = TEXT_COINS_BONUS[0];
    TEXTES_HOLDER[367] = TEXT_COINS_BONUS[1];
    TEXTES_HOLDER[368] = TEXT_COINS_BONUS[2];
    TEXTES_HOLDER[369] = TEXT_COINS_BONUS[3];
    TEXTES_HOLDER[370] = TEXT_COINS_BONUS[4];
    TEXTES_HOLDER[371] = TEXT_COINS_BONUS[5];
    TEXTES_HOLDER[372] = TEXT_COINS_BONUS[6];
    TEXTES_HOLDER[373] = TEXT_COINS_BONUS[7];
    TEXTES_HOLDER[374] = TEXT_COINS_BONUS[8];
    TEXTES_HOLDER[375] = TEXT_COINS_BONUS[9];
    TEXTES_HOLDER[376] = TEXT_GETLIVES_STRING_1;
    TEXTES_HOLDER[377] = TEXT_GETKEYS_STRING_1;
    TEXTES_HOLDER[378] = TEXT_UNLOCKLEVEL;
    TEXTES_HOLDER[379] = TEXT_UNLOCKLEVEL_OK;
    TEXTES_HOLDER[380] = TEXT_SURPRISE_OK;
    TEXTES_HOLDER[381] = TEXT_SURPRISE;
    TEXTES_HOLDER[382] = TEXT_PUBLISHER_STRING_4;
    TEXTES_HOLDER[383] = TEXT_MAPDESCRIPTION_CONTINUE;
    TEXTES_HOLDER[384] = TEXT_MAPDESCRIPTION_TOP;
    TEXTES_HOLDER[385] = TEXT_MAPDESCRIPTION_BOTTOM;
    TEXTES_HOLDER[386] = TEXT_MAPDESCRIPTION_MIDDLE;
    TEXTES_HOLDER[387] = TEXT_UNLOCKMODE;
    TEXTES_HOLDER[388] = TEXT_BONUS[0];
    TEXTES_HOLDER[389] = TEXT_BONUS[1];
    TEXTES_HOLDER[390] = TEXT_BONUS[2];
    TEXTES_HOLDER[391] = TEXT_BONUS[3];
    TEXTES_HOLDER[392] = TEXT_BONUS[4];
    TEXTES_HOLDER[393] = TEXT_BONUS[5];
    TEXTES_HOLDER[394] = TEXT_BONUS[6];
    TEXTES_HOLDER[395] = TEXT_BONUS[7];
    TEXTES_HOLDER[396] = TEXT_BONUS[8];
    TEXTES_HOLDER[397] = TEXT_BONUS[9];
    TEXTES_HOLDER[398] = TEXT_BONUS[10];
    TEXTES_HOLDER[399] = TEXT_BONUS[11];
    TEXTES_HOLDER[400] = TEXT_LEVELS_EPISODE;
    TEXTES_HOLDER[401] = TEXT_LEVELS_LOCKED;
    TEXTES_HOLDER[402] = TEXT_PROGRESS_TAP_TO_CONTINUE;
    TEXTES_HOLDER[403] = TEXT_PROGRESS_LEVEL_NUMBER;
    TEXTES_HOLDER[404] = TEXT_PROGRESS_LEVEL_TASK;
    TEXTES_HOLDER[405] = TEXT_EPISODES_NAMES[0];
    TEXTES_HOLDER[406] = TEXT_EPISODES_NAMES[1];
    TEXTES_HOLDER[407] = TEXT_EPISODES_NAMES[2];
    TEXTES_HOLDER[408] = TEXT_EPISODES_NAMES[3];
    TEXTES_HOLDER[409] = TEXT_EPISODES_NAMES[4];
    TEXTES_HOLDER[410] = TEXT_EPISODES_NAMES[5];
    TEXTES_HOLDER[411] = TEXT_NEED_TO_UNLOCK;
    TEXTES_HOLDER[412] = TEXT_GETSHOOTS_STRING_1;
    TEXTES_HOLDER[413] = TEXT_LEVELS_TASKS[0][0];
    TEXTES_HOLDER[414] = TEXT_LEVELS_TASKS[0][1];
    TEXTES_HOLDER[415] = TEXT_LEVELS_TASKS[0][2];
    TEXTES_HOLDER[416] = TEXT_LEVELS_TASKS[1][0];
    TEXTES_HOLDER[417] = TEXT_LEVELS_TASKS[1][1];
    TEXTES_HOLDER[418] = TEXT_LEVELS_TASKS[1][2];
    TEXTES_HOLDER[419] = TEXT_LEVELS_TASKS[2][0];
    TEXTES_HOLDER[420] = TEXT_LEVELS_TASKS[2][1];
    TEXTES_HOLDER[421] = TEXT_LEVELS_TASKS[2][2];
    TEXTES_HOLDER[422] = TEXT_LEVELS_TASKS[3][0];
    TEXTES_HOLDER[423] = TEXT_LEVELS_TASKS[3][1];
    TEXTES_HOLDER[424] = TEXT_LEVELS_TASKS[3][2];
    TEXTES_HOLDER[425] = TEXT_LEVELS_TASKS[4][0];
    TEXTES_HOLDER[426] = TEXT_LEVELS_TASKS[4][1];
    TEXTES_HOLDER[427] = TEXT_LEVELS_TASKS[4][2];
    
    for(int i = 0; i <= 427; i++)
    {
        if(Text::TEXTES[i] != NULL)
        {
            Text::TEXTES[i]->changeLanguage();
        }
    }
}

// ===========================================================
// Override Methods
// ===========================================================

#endif