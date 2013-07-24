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

bool Options::MUSIC_ENABLE = true;
bool Options::SOUND_ENABLE = true;

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

const char* Options::SAVE_DATA_COINS_ID[2] = { "p_gold_coins_count", "p_silver_coins_count" };
const char* Options::SAVE_DATA_LANGUAGE_ID = "p_language_id";

int Options::SAVE_DATA_COINS_TYPE_GOLD = 0;
int Options::SAVE_DATA_COINS_TYPE_SILVER = 1;

int Options::SHOP_ITEMS_PRICES[100] =
{
      999, 1499, 2939, 3420, 3850, 4400, 5100, 6800, 1100, 20000,
      22199, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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
      100, 100, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
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
    "88", "91", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "", "", "",
    "", "", "", "", "", "", "", "", "", ""
};

Textes Options::TEXTES_HOLDER[200] =
{
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
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
Textes Options::TEXT_SHOP_ITEMS[64] =
{
      { "", FONT, 0, 54 }, { "", FONT, 0, 55 }, { "", FONT, 0, 56 }, { "", FONT, 0, 58 }, { "", FONT, 0, 58 }, { "", FONT, 0, 59 }, { "", FONT, 0, 60 }, { "", FONT, 0, 61 }, { "", FONT, 0, 62 }, { "", FONT, 0, 63 },
      { "", FONT, 0, 64 }, { "", FONT, 0, 65 }, { "", FONT, 0, 66 }, { "", FONT, 0, 67 }, { "", FONT, 0, 68 }, { "", FONT, 0, 69 }, { "", FONT, 0, 70 }, { "", FONT, 0, 71 }, { "", FONT, 0, 72 }, { "", FONT, 0, 73 },
      { "", FONT, 0, 74 }, { "", FONT, 0, 75 }, { "", FONT, 0, 76 }, { "", FONT, 0, 77 }, { "", FONT, 0, 78 }, { "", FONT, 0, 79 }, { "", FONT, 0, 80 }, { "", FONT, 0, 81 }, { "", FONT, 0, 82 }, { "", FONT, 0, 83 },
      { "", FONT, 0, 84 }, { "", FONT, 0, 85 }, { "", FONT, 0, 86 }, { "", FONT, 0, 87 }, { "", FONT, 0, 88 }, { "", FONT, 0, 89 }, { "", FONT, 0, 90 }, { "", FONT, 0, 91 }, { "", FONT, 0, 92 }, { "", FONT, 0, 93 },
      { "", FONT, 0, 94 }, { "", FONT, 0, 95 }, { "", FONT, 0, 96 }, { "", FONT, 0, 97 }, { "", FONT, 0, 98 }, { "", FONT, 0, 99 }, { "", FONT, 0, 100 }, { "", FONT, 0, 101 }, { "", FONT, 0, 102 }, { "", FONT, 0, 103 },
      { "", FONT, 0, 104 }, { "", FONT, 0, 105 }, { "", FONT, 0, 106 }, { "", FONT, 0, 107 }, { "", FONT, 0, 108 }, { "", FONT, 0, 109 }, { "", FONT, 0, 110 }, { "", FONT, 0, 111 }, { "", FONT, 0, 112 }, { "", FONT, 0, 113 },
      { "", FONT, 0, 114 }, { "", FONT, 0, 115 }, { "", FONT, 0, 116 }, { "", FONT, 0, 117 }
};
Textes Options::TEXT_SHOP_BOUGHT =  { "", FONT, 0, 118 };
Textes Options::TEXT_TAP_TO_CONTINUE =  { "", FONT, 0, 119 };
Textes Options::TEXT_TIP[10] =
{
    { "", FONT, 36, 120 },
    { "", FONT, 36, 121 },
    { "", FONT, 36, 122 },
    { "", FONT, 36, 123 },
    { "", FONT, 36, 124 },
    { "", FONT, 36, 125 },
    { "", FONT, 36, 126 },
    { "", FONT, 36, 127 },
    { "", FONT, 36, 128 },
    { "", FONT, 36, 129 }
};
Textes Options::TEXT_SHOP_ITEMS_DESCRIPTIONS[64] =
{
      { "", FONT, 0, 130 }, { "", FONT, 0, 131 }, { "", FONT, 0, 132 }, { "", FONT, 0, 133 }, { "", FONT, 0, 134 }, { "", FONT, 0, 135 }, { "", FONT, 0, 136 }, { "", FONT, 0, 137 }, { "", FONT, 0, 138 }, { "", FONT, 0, 139 },
      { "", FONT, 0, 140 }, { "", FONT, 0, 141 }, { "", FONT, 0, 142 }, { "", FONT, 0, 143 }, { "", FONT, 0, 144 }, { "", FONT, 0, 145 }, { "", FONT, 0, 146 }, { "", FONT, 0, 147 }, { "", FONT, 0, 148 }, { "", FONT, 0, 149 },
      { "", FONT, 0, 150 }, { "", FONT, 0, 151 }, { "", FONT, 0, 152 }, { "", FONT, 0, 153 }, { "", FONT, 0, 154 }, { "", FONT, 0, 155 }, { "", FONT, 0, 156 }, { "", FONT, 0, 157 }, { "", FONT, 0, 158 }, { "", FONT, 0, 159 },
      { "", FONT, 0, 160 }, { "", FONT, 0, 161 }, { "", FONT, 0, 162 }, { "", FONT, 0, 163 }, { "", FONT, 0, 164 }, { "", FONT, 0, 165 }, { "", FONT, 0, 166 }, { "", FONT, 0, 167 }, { "", FONT, 0, 168 }, { "", FONT, 0, 169 },
      { "", FONT, 0, 170 }, { "", FONT, 0, 171 }, { "", FONT, 0, 172 }, { "", FONT, 0, 173 }, { "", FONT, 0, 174 }, { "", FONT, 0, 175 }, { "", FONT, 0, 176 }, { "", FONT, 0, 177 }, { "", FONT, 0, 178 }, { "", FONT, 0, 179 },
      { "", FONT, 0, 180 }, { "", FONT, 0, 181 }, { "", FONT, 0, 182 }, { "", FONT, 0, 183 }, { "", FONT, 0, 184 }, { "", FONT, 0, 185 }, { "", FONT, 0, 186 }, { "", FONT, 0, 187 }, { "", FONT, 0, 188 }, { "", FONT, 0, 189 },
      { "", FONT, 0, 190 }, { "", FONT, 0, 191 }, { "", FONT, 0, 192 }, { "", FONT, 0, 193 }
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

    Options::changeLanguage();
}

void Options::changeLanguage()
{
    AppDelegate::changeLanguage(CURRENT_LANGUAGE);

    switch(Options::CURRENT_LANGUAGE)
    {
        case 0:
            TEXT_LOADING_1.string = "0%";
            TEXT_LOADING_1.size = 32;
            
            TEXT_LOADING_2.string = "";
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
            
            TEXT_EXIT_STRING_1.string = "Are you sure";
            TEXT_EXIT_STRING_1.size = 48;
            
            TEXT_EXIT_STRING_2.string = "you want to quit?";
            TEXT_EXIT_STRING_2.size = 48;
            
            TEXT_RATE_NOW.string = "Rate";
            TEXT_RATE_NOW.size = 46;
            
            TEXT_RATE_STRING_1.string = "Do you like";
            TEXT_RATE_STRING_1.size = 48;
            
            TEXT_RATE_STRING_2.string = "our game?";
            TEXT_RATE_STRING_2.size = 48;
            
            TEXT_RATE_STRING_3.string = "Please";
            TEXT_RATE_STRING_3.size = 48;
            
            TEXT_RATE_STRING_4.string = "rate it!";
            TEXT_RATE_STRING_4.size = 40;
            
            TEXT_GETCOINS_STRING_1.string = "You need to buy";
            TEXT_GETCOINS_STRING_1.size = 48;
            
            TEXT_GETCOINS_STRING_2.string = "some coins!";
            TEXT_GETCOINS_STRING_2.size = 48;
            
            TEXT_GETCOINS_STRING_3.string = "Any purchase will";
            TEXT_GETCOINS_STRING_3.size = 36;
            
            TEXT_GETCOINS_STRING_4.string = "remove the ads!";
            TEXT_GETCOINS_STRING_4.size = 36;
            
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
            
            TEXT_RESET_STRING_1.string = "Are you sure that";
            TEXT_RESET_STRING_1.size = 48;
            
            TEXT_RESET_STRING_2.string = "you want to reset your progress?";
            TEXT_RESET_STRING_2.size = 32;
            
            TEXT_RESET_STRING_3.string = "You start game from";
            TEXT_RESET_STRING_3.size = 48;
            
            TEXT_RESET_STRING_4.string = "first level!";
            TEXT_RESET_STRING_4.size = 48;
            
            TEXT_RESET_RESET.string = "Reset";
            TEXT_RESET_RESET.size = 40;
            
            TEXT_CREDITS_STRING_1.string = "About";
            TEXT_CREDITS_STRING_1.size = 48;
            
            TEXT_CREDITS_STRING_2.string = "Version: 0.0.1";
            TEXT_CREDITS_STRING_2.size = 36;
            
            TEXT_CREDITS_STRING_3.string = "Build: 613";
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
            
            TEXT_CREDITS_STRING_9.string = "Articsts";
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
            
            TEXT_MODEHELP_HELP[1].string = "Classic mode - the game in which you have to compete with other players to earn coins, to increase its global ranking and use the bonus earned.\n\nArcade mode - allow you to show what you can do in one minute! As the game progresses your skills increase and you are quite able to surpass its previous record!\n\nProgress mode - a special mode. Available to you 75 levels (update soon) with a variety of tasks. As you progress through levels you will unlock new opportunities that you can get to use in other game modes.";
            TEXT_MODEHELP_HELP[1].size = 24;
            
            TEXT_SHOP_ITEMS[0].string = "Some weapon 1";
            TEXT_SHOP_ITEMS[0].size = 48;
            
            TEXT_SHOP_ITEMS[1].string = "Some weapon 2";
            TEXT_SHOP_ITEMS[1].size = 48;
            
            TEXT_SHOP_ITEMS[2].string = "Some weapon 3";
            TEXT_SHOP_ITEMS[2].size = 48;
            
            TEXT_SHOP_ITEMS[3].string = "Some weapon 4";
            TEXT_SHOP_ITEMS[3].size = 48;
            
            TEXT_SHOP_ITEMS[4].string = "Some weapon 5";
            TEXT_SHOP_ITEMS[4].size = 48;
            
            TEXT_SHOP_ITEMS[5].string = "Some weapon 6";
            TEXT_SHOP_ITEMS[5].size = 48;
            
            TEXT_SHOP_ITEMS[6].string = "Some character 1";
            TEXT_SHOP_ITEMS[6].size = 48;
            
            TEXT_SHOP_ITEMS[7].string = "Some character  2";
            TEXT_SHOP_ITEMS[7].size = 48;
            
            TEXT_SHOP_ITEMS[8].string = "Some character  3";
            TEXT_SHOP_ITEMS[8].size = 48;
            
            TEXT_SHOP_ITEMS[9].string = "Some character  4";
            TEXT_SHOP_ITEMS[9].size = 48;
            
            TEXT_SHOP_ITEMS[10].string = "Some special bonus 1";
            TEXT_SHOP_ITEMS[10].size = 48;
            
            TEXT_SHOP_ITEMS[11].string = "Some special bonus 2";
            TEXT_SHOP_ITEMS[11].size = 48;
            
            TEXT_SHOP_ITEMS[12].string = "Some special bonus 3";
            TEXT_SHOP_ITEMS[12].size = 48;
            
            TEXT_SHOP_ITEMS[13].string = "Some special bonus 4";
            TEXT_SHOP_ITEMS[13].size = 48;
            
            TEXT_SHOP_ITEMS[14].string = "Some special bonus 5";
            TEXT_SHOP_ITEMS[14].size = 48;
            
            TEXT_SHOP_ITEMS[15].string = "Some special bonus 6";
            TEXT_SHOP_ITEMS[15].size = 48;
            
            TEXT_SHOP_ITEMS[16].string = "Some special bonus 7";
            TEXT_SHOP_ITEMS[16].size = 48;
            
            TEXT_SHOP_ITEMS[17].string = "Some special bonus 8";
            TEXT_SHOP_ITEMS[17].size = 48;
            
            TEXT_SHOP_BOUGHT.string = "was unlocked";
            TEXT_SHOP_BOUGHT.size = 48;
            
            TEXT_TAP_TO_CONTINUE.string = "Tap to continue";
            TEXT_TAP_TO_CONTINUE.size = 36;
            
            TEXT_TIP[0].string = "Some items in the shop can be very useful to you";
            TEXT_TIP[1].string = "Use the new weapons that you can buy at the store";
            TEXT_TIP[2].string = "Avoid the bombs hit the Birds";
            TEXT_TIP[3].string = "Some birds are special - look at what they can do";
            TEXT_TIP[4].string = "You will enjoy more than 20 different birds with unique abilities";
            
            TEXT_SHOP_ITEMS_DESCRIPTIONS[0].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[1].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[2].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[3].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[4].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[5].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[6].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[7].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[8].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[9].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[10].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[11].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[12].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[13].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[14].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[15].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[16].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[17].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[18].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[19].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[20].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[21].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[22].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[23].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[24].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[25].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[26].string = "Information not found.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[27].string = "Information not found.";
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
        break;
        case 1:
            TEXT_LOADING_1.string = "0%";
            TEXT_LOADING_1.size = 32;
            
            TEXT_LOADING_2.string = "";
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
            
            TEXT_EXIT_STRING_1.string = "Вы действительно";
            TEXT_EXIT_STRING_1.size = 48;
            
            TEXT_EXIT_STRING_2.string = "хотите выйти?";
            TEXT_EXIT_STRING_2.size = 48;
            
            TEXT_RATE_NOW.string = "Оценить";
            TEXT_RATE_NOW.size = 46;
            
            TEXT_RATE_STRING_1.string = "Вам понравилась";
            TEXT_RATE_STRING_1.size = 48;
            
            TEXT_RATE_STRING_2.string = "наша игра?";
            TEXT_RATE_STRING_2.size = 48;
            
            TEXT_RATE_STRING_3.string = "Пожалуйста";
            TEXT_RATE_STRING_3.size = 48;
            
            TEXT_RATE_STRING_4.string = "проголосуйте за нее!";
            TEXT_RATE_STRING_4.size = 40;
            
            TEXT_GETCOINS_STRING_1.string = "Желаете купить";
            TEXT_GETCOINS_STRING_1.size = 48;
            
            TEXT_GETCOINS_STRING_2.string = "несколько монет?";
            TEXT_GETCOINS_STRING_2.size = 48;
            
            TEXT_GETCOINS_STRING_3.string = "Любая покупка";
            TEXT_GETCOINS_STRING_3.size = 36;
            
            TEXT_GETCOINS_STRING_4.string = "уберет рекламу!";
            TEXT_GETCOINS_STRING_4.size = 36;
            
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
            
            TEXT_RESET_STRING_1.string = "Вы уверены что";
            TEXT_RESET_STRING_1.size = 48;
            
            TEXT_RESET_STRING_2.string = "хотите сбросить прогресс?";
            TEXT_RESET_STRING_2.size = 32;
            
            TEXT_RESET_STRING_3.string = "Вы начнете игру";
            TEXT_RESET_STRING_3.size = 48;
            
            TEXT_RESET_STRING_4.string = "с первого уровня!";
            TEXT_RESET_STRING_4.size = 48;
            
            TEXT_RESET_RESET.string = "Сбросить";
            TEXT_RESET_RESET.size = 40;
            
            TEXT_CREDITS_STRING_1.string = "Об игре";
            TEXT_CREDITS_STRING_1.size = 48;
            
            TEXT_CREDITS_STRING_2.string = "Версия: 0.0.1";
            TEXT_CREDITS_STRING_2.size = 36;
            
            TEXT_CREDITS_STRING_3.string = "Сборка: 613";
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
            TEXT_MODE_CLASSIC.size = 42;
            
            TEXT_MODE_ARCADE.string = "Аркада";
            TEXT_MODE_ARCADE.size = 42;
            
            TEXT_MODE_PROGRESS.string = "Прохождение";
            TEXT_MODE_PROGRESS.size = 42;
            
            TEXT_MODEHELP_OK.string = "Закрыть";
            TEXT_MODEHELP_OK.size = 46;
            
            TEXT_MODEHELP_HELP[0].string = "О режимах";
            TEXT_MODEHELP_HELP[0].size = 48;
            
            TEXT_MODEHELP_HELP[1].string = "Классический режим - режим игры в котором вам предстоит соревноваться с другими игроками, зарабатывать монеты, увеличивать свой глобальный рейтинг и пользоваться заработанными бонусами.\n\nРежим аркады - позволит вам показать на что вы способны за одну минуту! По мере прохождения игры ваши навыки увеличиваются и вы вполне в силах превзойти свой предыдущий рекорд!\n\nПрохождение - это особый режим. Вам доступно 75 уровней (обновления совсем скоро) с различными заданиями. По мере прохождения уровней вам будут открываться новые возможности, которые вы можте использовать в других режимах игры.";
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
            
            TEXT_SHOP_ITEMS[7].string = "Меч Джедая";
            TEXT_SHOP_ITEMS[7].size = 48;
            
            TEXT_SHOP_ITEMS[8].string = "Механическая рука";
            TEXT_SHOP_ITEMS[8].size = 48;
            
            TEXT_SHOP_ITEMS[9].string = "Рыба";
            TEXT_SHOP_ITEMS[9].size = 48;
            
            TEXT_SHOP_ITEMS[10].string = "Бита клоуна";
            TEXT_SHOP_ITEMS[10].size = 48;
            
            TEXT_SHOP_ITEMS[11].string = "Какая-то птица 1";
            TEXT_SHOP_ITEMS[11].size = 48;
            
            TEXT_SHOP_ITEMS[12].string = "Какой-то бонус 3";
            TEXT_SHOP_ITEMS[12].size = 48;
            
            TEXT_SHOP_ITEMS[13].string = "Какой-то бонус 4";
            TEXT_SHOP_ITEMS[13].size = 48;
            
            TEXT_SHOP_ITEMS[14].string = "Какой-то бонус 5";
            TEXT_SHOP_ITEMS[14].size = 48;
            
            TEXT_SHOP_ITEMS[15].string = "Какой-то бонус 6";
            TEXT_SHOP_ITEMS[15].size = 48;
            
            TEXT_SHOP_ITEMS[16].string = "Какой-то бонус 7";
            TEXT_SHOP_ITEMS[16].size = 48;
            
            TEXT_SHOP_ITEMS[17].string = "Какой-то бонус 8";
            TEXT_SHOP_ITEMS[17].size = 48;
            
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
            TEXT_SHOP_ITEMS_DESCRIPTIONS[7].string = "Легендарный Меч Джедая, которым захватывались космические корабли, да что там корабли - целые галактики! Его владельца меч наделял необыкновенной силой и возможностями, но лишь до тех пор пока не сядут батарейки.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[8].string = "Железная механическая рука, результат многолетних засекреченных разработок ведущих компаний мира в наноиндустрии. Она стала началом создания сверх секретного проекта - Стальной подшипник. Сейчас же руку используют как промышленную кофеварку.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[9].string = "Та самая рыба из сказки, что желания деда исполняла, когда тот неводом её вытянул. Была найдена у темного берега быстрой реки кучкой маленьких гномов. Будьте внимательны и осторожны в своих желаниях, возможно ваше исполнится прямо сейчас!";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[10].string = "На бите изображен первый клоун старого цирка. Зрителям очень нравились его выступления с дрессированными динозаврами и летающими слонами. В результате добрые люди решили увековечить его облик на этой бите.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[11].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[12].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[13].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[14].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[15].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[16].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[17].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[18].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[19].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[20].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[21].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[22].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[23].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[24].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[25].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[26].string = "Информации не найдено.";
            TEXT_SHOP_ITEMS_DESCRIPTIONS[27].string = "Информации не найдено.";
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
    TEXTES_HOLDER[94] = TEXT_SHOP_ITEMS[41];
    TEXTES_HOLDER[95] = TEXT_SHOP_ITEMS[42];
    TEXTES_HOLDER[96] = TEXT_SHOP_ITEMS[43];
    TEXTES_HOLDER[97] = TEXT_SHOP_ITEMS[44];
    TEXTES_HOLDER[98] = TEXT_SHOP_ITEMS[45];
    TEXTES_HOLDER[99] = TEXT_SHOP_ITEMS[46];
    TEXTES_HOLDER[100] = TEXT_SHOP_ITEMS[47];
    TEXTES_HOLDER[101] = TEXT_SHOP_ITEMS[48];
    TEXTES_HOLDER[102] = TEXT_SHOP_ITEMS[49];
    TEXTES_HOLDER[103] = TEXT_SHOP_ITEMS[50];
    TEXTES_HOLDER[104] = TEXT_SHOP_ITEMS[51];
    TEXTES_HOLDER[105] = TEXT_SHOP_ITEMS[52];
    TEXTES_HOLDER[106] = TEXT_SHOP_ITEMS[53];
    TEXTES_HOLDER[107] = TEXT_SHOP_ITEMS[54];
    TEXTES_HOLDER[108] = TEXT_SHOP_ITEMS[55];
    TEXTES_HOLDER[109] = TEXT_SHOP_ITEMS[56];
    TEXTES_HOLDER[110] = TEXT_SHOP_ITEMS[57];
    TEXTES_HOLDER[111] = TEXT_SHOP_ITEMS[58];
    TEXTES_HOLDER[112] = TEXT_SHOP_ITEMS[59];
    TEXTES_HOLDER[113] = TEXT_SHOP_ITEMS[60];
    TEXTES_HOLDER[114] = TEXT_SHOP_ITEMS[61];
    TEXTES_HOLDER[115] = TEXT_SHOP_ITEMS[62];
    TEXTES_HOLDER[116] = TEXT_SHOP_ITEMS[63];
    TEXTES_HOLDER[117] = TEXT_SHOP_ITEMS[64];
    TEXTES_HOLDER[118] = TEXT_SHOP_BOUGHT;
    TEXTES_HOLDER[119] = TEXT_TAP_TO_CONTINUE;
    TEXTES_HOLDER[120] = TEXT_TIP[0];
    TEXTES_HOLDER[121] = TEXT_TIP[1];
    TEXTES_HOLDER[122] = TEXT_TIP[2];
    TEXTES_HOLDER[123] = TEXT_TIP[3];
    TEXTES_HOLDER[124] = TEXT_TIP[4];
    TEXTES_HOLDER[125] = TEXT_TIP[5];
    TEXTES_HOLDER[126] = TEXT_TIP[6];
    TEXTES_HOLDER[127] = TEXT_TIP[7];
    TEXTES_HOLDER[128] = TEXT_TIP[8];
    TEXTES_HOLDER[129] = TEXT_TIP[9];

    TEXTES_HOLDER[130] = TEXT_SHOP_ITEMS_DESCRIPTIONS[0];
    TEXTES_HOLDER[131] = TEXT_SHOP_ITEMS_DESCRIPTIONS[1];
    TEXTES_HOLDER[132] = TEXT_SHOP_ITEMS_DESCRIPTIONS[2];
    TEXTES_HOLDER[133] = TEXT_SHOP_ITEMS_DESCRIPTIONS[3];
    TEXTES_HOLDER[134] = TEXT_SHOP_ITEMS_DESCRIPTIONS[4];
    TEXTES_HOLDER[135] = TEXT_SHOP_ITEMS_DESCRIPTIONS[5];
    TEXTES_HOLDER[136] = TEXT_SHOP_ITEMS_DESCRIPTIONS[6];
    TEXTES_HOLDER[137] = TEXT_SHOP_ITEMS_DESCRIPTIONS[7];
    TEXTES_HOLDER[138] = TEXT_SHOP_ITEMS_DESCRIPTIONS[8];
    TEXTES_HOLDER[139] = TEXT_SHOP_ITEMS_DESCRIPTIONS[9];
    TEXTES_HOLDER[140] = TEXT_SHOP_ITEMS_DESCRIPTIONS[10];
    TEXTES_HOLDER[141] = TEXT_SHOP_ITEMS_DESCRIPTIONS[11];
    TEXTES_HOLDER[142] = TEXT_SHOP_ITEMS_DESCRIPTIONS[12];
    TEXTES_HOLDER[143] = TEXT_SHOP_ITEMS_DESCRIPTIONS[13];
    TEXTES_HOLDER[144] = TEXT_SHOP_ITEMS_DESCRIPTIONS[14];
    TEXTES_HOLDER[145] = TEXT_SHOP_ITEMS_DESCRIPTIONS[15];
    TEXTES_HOLDER[146] = TEXT_SHOP_ITEMS_DESCRIPTIONS[16];
    TEXTES_HOLDER[147] = TEXT_SHOP_ITEMS_DESCRIPTIONS[17];
    TEXTES_HOLDER[148] = TEXT_SHOP_ITEMS_DESCRIPTIONS[18];
    TEXTES_HOLDER[149] = TEXT_SHOP_ITEMS_DESCRIPTIONS[19];
    TEXTES_HOLDER[150] = TEXT_SHOP_ITEMS_DESCRIPTIONS[20];
    TEXTES_HOLDER[151] = TEXT_SHOP_ITEMS_DESCRIPTIONS[21];
    TEXTES_HOLDER[152] = TEXT_SHOP_ITEMS_DESCRIPTIONS[22];
    TEXTES_HOLDER[153] = TEXT_SHOP_ITEMS_DESCRIPTIONS[23];
    TEXTES_HOLDER[154] = TEXT_SHOP_ITEMS_DESCRIPTIONS[24];
    TEXTES_HOLDER[155] = TEXT_SHOP_ITEMS_DESCRIPTIONS[25];
    TEXTES_HOLDER[156] = TEXT_SHOP_ITEMS_DESCRIPTIONS[26];
    TEXTES_HOLDER[157] = TEXT_SHOP_ITEMS_DESCRIPTIONS[27];
    TEXTES_HOLDER[158] = TEXT_SHOP_ITEMS_DESCRIPTIONS[28];
    TEXTES_HOLDER[159] = TEXT_SHOP_ITEMS_DESCRIPTIONS[29];
    TEXTES_HOLDER[160] = TEXT_SHOP_ITEMS_DESCRIPTIONS[30];
    TEXTES_HOLDER[161] = TEXT_SHOP_ITEMS_DESCRIPTIONS[31];
    TEXTES_HOLDER[162] = TEXT_SHOP_ITEMS_DESCRIPTIONS[32];
    TEXTES_HOLDER[163] = TEXT_SHOP_ITEMS_DESCRIPTIONS[33];
    TEXTES_HOLDER[164] = TEXT_SHOP_ITEMS_DESCRIPTIONS[34];
    TEXTES_HOLDER[165] = TEXT_SHOP_ITEMS_DESCRIPTIONS[35];
    TEXTES_HOLDER[166] = TEXT_SHOP_ITEMS_DESCRIPTIONS[36];
    TEXTES_HOLDER[167] = TEXT_SHOP_ITEMS_DESCRIPTIONS[37];
    TEXTES_HOLDER[168] = TEXT_SHOP_ITEMS_DESCRIPTIONS[38];
    TEXTES_HOLDER[169] = TEXT_SHOP_ITEMS_DESCRIPTIONS[39];
    TEXTES_HOLDER[170] = TEXT_SHOP_ITEMS_DESCRIPTIONS[41];
    TEXTES_HOLDER[171] = TEXT_SHOP_ITEMS_DESCRIPTIONS[42];
    TEXTES_HOLDER[172] = TEXT_SHOP_ITEMS_DESCRIPTIONS[43];
    TEXTES_HOLDER[173] = TEXT_SHOP_ITEMS_DESCRIPTIONS[44];
    TEXTES_HOLDER[174] = TEXT_SHOP_ITEMS_DESCRIPTIONS[45];
    TEXTES_HOLDER[175] = TEXT_SHOP_ITEMS_DESCRIPTIONS[46];
    TEXTES_HOLDER[176] = TEXT_SHOP_ITEMS_DESCRIPTIONS[47];
    TEXTES_HOLDER[177] = TEXT_SHOP_ITEMS_DESCRIPTIONS[48];
    TEXTES_HOLDER[178] = TEXT_SHOP_ITEMS_DESCRIPTIONS[49];
    TEXTES_HOLDER[179] = TEXT_SHOP_ITEMS_DESCRIPTIONS[50];
    TEXTES_HOLDER[180] = TEXT_SHOP_ITEMS_DESCRIPTIONS[51];
    TEXTES_HOLDER[181] = TEXT_SHOP_ITEMS_DESCRIPTIONS[52];
    TEXTES_HOLDER[182] = TEXT_SHOP_ITEMS_DESCRIPTIONS[53];
    TEXTES_HOLDER[183] = TEXT_SHOP_ITEMS_DESCRIPTIONS[54];
    TEXTES_HOLDER[184] = TEXT_SHOP_ITEMS_DESCRIPTIONS[55];
    TEXTES_HOLDER[185] = TEXT_SHOP_ITEMS_DESCRIPTIONS[56];
    TEXTES_HOLDER[186] = TEXT_SHOP_ITEMS_DESCRIPTIONS[57];
    TEXTES_HOLDER[187] = TEXT_SHOP_ITEMS_DESCRIPTIONS[58];
    TEXTES_HOLDER[188] = TEXT_SHOP_ITEMS_DESCRIPTIONS[59];
    TEXTES_HOLDER[189] = TEXT_SHOP_ITEMS_DESCRIPTIONS[60];
    TEXTES_HOLDER[190] = TEXT_SHOP_ITEMS_DESCRIPTIONS[61];
    TEXTES_HOLDER[191] = TEXT_SHOP_ITEMS_DESCRIPTIONS[62];
    TEXTES_HOLDER[192] = TEXT_SHOP_ITEMS_DESCRIPTIONS[63];
    
    for(int i = 0; i < 193; i++)
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