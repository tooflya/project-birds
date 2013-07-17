#ifndef CONST_OPTIONS
#define CONST_OPTIONS

#include "Options.h"

#include "Text.h"

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

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)

const char* Options::FONT = "Comic Sans MS";

#else

const char* Options::FONT = "Fonts/Comic Sans MS.ttf";

#endif

int Options::CURRENT_LANGUAGE = 0;

const char* Options::SAVE_DATA_COINS_ID[2] = { "p_gold_coins_count", "p_silver_coins_count" };
int Options::SAVE_DATA_COINS_TYPE_GOLD = 0;
int Options::SAVE_DATA_COINS_TYPE_SILVER = 1;

int Options::SHOP_ITEMS_PRICES[100] =
{
      999, 1499, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0
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

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Options::Options()
{
    Options::CURRENT_LANGUAGE = 0;
    
    Options::changeLanguage();
}

// ===========================================================
// Methods
// ===========================================================

void Options::changeLanguage()
{
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
            TEXT_CREDITS_STRING_4.size = 42;
            
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
            
            TEXT_MODEHELP_HELP[1].string = "Классический режим - режим игры в котором вам предстоит соревноваться с другими игроками, зарабатывать монеты, увеличивать свой глобальный рейтинг и пользоваться заработанными бонусами.\n\nРежим аркады - позволит вам показать на что вы способны за одну минуту! По мере прохождения игры ваши навыки увеличиваются и вы вполне в силах превзойти свой предыдущий рекорд!\n\nПрохождение - это особый режим. Вам доступно 75 уровней (обновления совсем скоро) с различными заданиями. По мере прохождения уровней вам будут открываться новые возможности, которые вы можте использовать в других режимах игры.";
            TEXT_MODEHELP_HELP[1].size = 24;
            
            TEXT_SHOP_ITEMS[0].string = "Какое-то оружие 1";
            TEXT_SHOP_ITEMS[0].size = 48;
            
            TEXT_SHOP_ITEMS[1].string = "Какое-то оружие 2";
            TEXT_SHOP_ITEMS[1].size = 48;
            
            TEXT_SHOP_ITEMS[2].string = "Какое-то оружие 3";
            TEXT_SHOP_ITEMS[2].size = 48;
            
            TEXT_SHOP_ITEMS[3].string = "Какое-то оружие 4";
            TEXT_SHOP_ITEMS[3].size = 48;
            
            TEXT_SHOP_ITEMS[4].string = "Какое-то оружие 5";
            TEXT_SHOP_ITEMS[4].size = 48;
            
            TEXT_SHOP_ITEMS[5].string = "Какое-то оружие 6";
            TEXT_SHOP_ITEMS[5].size = 48;
            
            TEXT_SHOP_ITEMS[6].string = "Какая-то птица 1";
            TEXT_SHOP_ITEMS[6].size = 48;
            
            TEXT_SHOP_ITEMS[7].string = "Какая-то птица 2";
            TEXT_SHOP_ITEMS[7].size = 48;
            
            TEXT_SHOP_ITEMS[8].string = "Какая-то птица 3";
            TEXT_SHOP_ITEMS[8].size = 48;
            
            TEXT_SHOP_ITEMS[9].string = "Какая-то птица 4";
            TEXT_SHOP_ITEMS[9].size = 48;
            
            TEXT_SHOP_ITEMS[10].string = "Какой-то бонус 1";
            TEXT_SHOP_ITEMS[10].size = 48;
            
            TEXT_SHOP_ITEMS[11].string = "Какой-то бонус 2";
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
    
    for(int i = 0; i < 119; i++)
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