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

int Options::CURRENT_LANGUAGE = 0;

Textes Options::TEXTES_HOLDER[32] =
{
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
};

Textes Options::TEXT_LOADING_1 = { "", "", 0, 0 };
Textes Options::TEXT_LOADING_2 = { "", "", 0, 1 };
Textes Options::TEXT_SETTINGS_CREDITS = { "", "", 0, 2 };
Textes Options::TEXT_SETTINGS_PROGRESS = { "", "", 0, 3 };
Textes Options::TEXT_SETTINGS_MORE = { "", "", 0, 4 };
Textes Options::TEXT_SETTINGS_LANGUAGE = { "", "", 0, 5 };
Textes Options::TEXT_BUYITEM_BUY = { "", "", 0, 6 };
Textes Options::TEXT_EXIT_YES = { "", "", 0, 7 };
Textes Options::TEXT_EXIT_STRING_1 = { "", "", 0, 8 };
Textes Options::TEXT_EXIT_STRING_2 = { "", "", 0, 9 };
Textes Options::TEXT_RATE_NOW = { "", "", 0, 10 };
Textes Options::TEXT_RATE_STRING_1 = { "", "", 0, 11 };
Textes Options::TEXT_RATE_STRING_2 = { "", "", 0, 12 };
Textes Options::TEXT_RATE_STRING_3 = { "", "", 0, 13 };
Textes Options::TEXT_RATE_STRING_4 = { "", "", 0, 14 };
Textes Options::TEXT_GETCOINS_STRING_1 = { "", "", 0, 15 };
Textes Options::TEXT_GETCOINS_STRING_2 = { "", "", 0, 16 };
Textes Options::TEXT_GETCOINS_1 = { "", "", 0, 17 };
Textes Options::TEXT_GETCOINS_2 = { "", "", 0, 18 };
Textes Options::TEXT_GETCOINS_3 = { "", "", 0, 19 };
Textes Options::TEXT_GETCOINS_4 = { "", "", 0, 20 };
Textes Options::TEXT_PROGRESS_STRING_1 = { "", "", 0, 21 };
Textes Options::TEXT_PROGRESS_STRING_2 = { "", "", 0, 22 };
Textes Options::TEXT_PROGRESS_STRING_3 = { "", "", 0, 23 };
Textes Options::TEXT_PROGRESS_RESET = { "", "", 0, 24 };
Textes Options::TEXT_RESET_STRING_1 = { "", "", 0, 25 };
Textes Options::TEXT_RESET_STRING_2 = { "", "", 0, 26 };
Textes Options::TEXT_RESET_STRING_3 = { "", "", 0, 27 };
Textes Options::TEXT_RESET_STRING_4 = { "", "", 0, 28 };
Textes Options::TEXT_RESET_RESET = { "", "", 0, 29 };
Textes Options::TEXT_CREDITS_STRING_1 = { "", "", 0, 30 };

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
            TEXT_LOADING_1.string =  "Loading... 0%";
            TEXT_LOADING_1.font =  "Comic Sans MS";
            TEXT_LOADING_1.size =  32;
            
            TEXT_LOADING_2.string =  "Loading... ";
            TEXT_LOADING_2.font =  "Comic Sans MS";
            TEXT_LOADING_2.size =  32;
            
            TEXT_SETTINGS_CREDITS.string =  "About";
            TEXT_SETTINGS_CREDITS.font =  "Comic Sans MS";
            TEXT_SETTINGS_CREDITS.size =  64;
            
            TEXT_SETTINGS_PROGRESS.string =  "Progress";
            TEXT_SETTINGS_PROGRESS.font =  "Comic Sans MS";
            TEXT_SETTINGS_PROGRESS.size =  64;
            
            TEXT_SETTINGS_MORE.string =  "More";
            TEXT_SETTINGS_MORE.font =  "Comic Sans MS";
            TEXT_SETTINGS_MORE.size =  64;
            
            TEXT_SETTINGS_LANGUAGE.string =  "Language";
            TEXT_SETTINGS_LANGUAGE.font =  "Comic Sans MS";
            TEXT_SETTINGS_LANGUAGE.size =  64;
            
            TEXT_BUYITEM_BUY.string =  "Buy";
            TEXT_BUYITEM_BUY.font =  "Comic Sans MS";
            TEXT_BUYITEM_BUY.size =  46;
            
            TEXT_EXIT_YES.string =  "Yes";
            TEXT_EXIT_YES.font =  "Comic Sans MS";
            TEXT_EXIT_YES.size =  64;
            
            TEXT_EXIT_STRING_1.string =  "Are you sure";
            TEXT_EXIT_STRING_1.font =  "Comic Sans MS";
            TEXT_EXIT_STRING_1.size =  48;
            
            TEXT_EXIT_STRING_2.string =  "you want to quit?";
            TEXT_EXIT_STRING_2.font =  "Comic Sans MS";
            TEXT_EXIT_STRING_2.size =  48;
            
            TEXT_RATE_NOW.string =  "Rate";
            TEXT_RATE_NOW.font =  "Comic Sans MS";
            TEXT_RATE_NOW.size =  46;
            
            TEXT_RATE_STRING_1.string =  "Do you like";
            TEXT_RATE_STRING_1.font =  "Comic Sans MS";
            TEXT_RATE_STRING_1.size =  48;
            
            TEXT_RATE_STRING_2.string =  "our game?";
            TEXT_RATE_STRING_2.font =  "Comic Sans MS";
            TEXT_RATE_STRING_2.size =  48;
            
            TEXT_RATE_STRING_3.string =  "Please";
            TEXT_RATE_STRING_3.font =  "Comic Sans MS";
            TEXT_RATE_STRING_3.size =  48;
            
            TEXT_RATE_STRING_4.string =  "rate it!";
            TEXT_RATE_STRING_4.font =  "Comic Sans MS";
            TEXT_RATE_STRING_4.size =  40;
            
            TEXT_GETCOINS_STRING_1.string =  "You need to buy";
            TEXT_GETCOINS_STRING_1.font =  "Comic Sans MS";
            TEXT_GETCOINS_STRING_1.size =  48;
            
            TEXT_GETCOINS_STRING_2.string =  "some coins!";
            TEXT_GETCOINS_STRING_2.font =  "Comic Sans MS";
            TEXT_GETCOINS_STRING_2.size =  48;
            
            TEXT_GETCOINS_1.string =  "$0.99";
            TEXT_GETCOINS_1.font =  "Comic Sans MS";
            TEXT_GETCOINS_1.size =  64;
            
            TEXT_GETCOINS_2.string =  "$1.99";
            TEXT_GETCOINS_2.font =  "Comic Sans MS";
            TEXT_GETCOINS_2.size =  64;
            
            TEXT_GETCOINS_3.string =  "$3.99";
            TEXT_GETCOINS_3.font =  "Comic Sans MS";
            TEXT_GETCOINS_3.size =  64;
            
            TEXT_GETCOINS_4.string =  "$9.99";
            TEXT_GETCOINS_4.font =  "Comic Sans MS";
            TEXT_GETCOINS_4.size =  64;
            
            TEXT_PROGRESS_STRING_1.string =  "If you want to";
            TEXT_PROGRESS_STRING_1.font =  "Comic Sans MS";
            TEXT_PROGRESS_STRING_1.size =  48;
            
            TEXT_PROGRESS_STRING_2.string =  "start game again, you can";
            TEXT_PROGRESS_STRING_2.font =  "Comic Sans MS";
            TEXT_PROGRESS_STRING_2.size =  48;
            
            TEXT_PROGRESS_STRING_3.string =  "reset progress.";
            TEXT_PROGRESS_STRING_3.font =  "Comic Sans MS";
            TEXT_PROGRESS_STRING_3.size =  48;
            
            TEXT_PROGRESS_RESET.string =  "Reset";
            TEXT_PROGRESS_RESET.font =  "Comic Sans MS";
            TEXT_PROGRESS_RESET.size =  48;
            
            TEXT_RESET_STRING_1.string =  "Are you sure that";
            TEXT_RESET_STRING_1.font =  "Comic Sans MS";
            TEXT_RESET_STRING_1.size =  48;
            
            TEXT_RESET_STRING_2.string =  "you want to reset your progress?";
            TEXT_RESET_STRING_2.font =  "Comic Sans MS";
            TEXT_RESET_STRING_2.size =  32;
            
            TEXT_RESET_STRING_3.string =  "You start game from";
            TEXT_RESET_STRING_3.font =  "Comic Sans MS";
            TEXT_RESET_STRING_3.size =  48;
            
            TEXT_RESET_STRING_4.string =  "first level!";
            TEXT_RESET_STRING_4.font =  "Comic Sans MS";
            TEXT_RESET_STRING_4.size =  48;
            
            TEXT_RESET_RESET.string =  "Reset";
            TEXT_RESET_RESET.font =  "Comic Sans MS";
            TEXT_RESET_RESET.size =  40;
            
            TEXT_CREDITS_STRING_1.string =  "";
            TEXT_CREDITS_STRING_1.font =  "Comic Sans MS";
            TEXT_CREDITS_STRING_1.size =  64;
        break;
        case 1:
            TEXT_LOADING_1.string =  "Загрузка... 0%";
            TEXT_LOADING_1.font =  "Comic Sans MS";
            TEXT_LOADING_1.size =  32;
            
            TEXT_LOADING_2.string =  "Загрузка... ";
            TEXT_LOADING_2.font =  "Comic Sans MS";
            TEXT_LOADING_2.size =  32;
            
            TEXT_SETTINGS_CREDITS.string =  "Об игре";
            TEXT_SETTINGS_CREDITS.font =  "Comic Sans MS";
            TEXT_SETTINGS_CREDITS.size =  64;
            
            TEXT_SETTINGS_PROGRESS.string =  "Прогресс";
            TEXT_SETTINGS_PROGRESS.font =  "Comic Sans MS";
            TEXT_SETTINGS_PROGRESS.size =  64;
            
            TEXT_SETTINGS_MORE.string =  "Больше";
            TEXT_SETTINGS_MORE.font =  "Comic Sans MS";
            TEXT_SETTINGS_MORE.size =  64;
            
            TEXT_SETTINGS_LANGUAGE.string =  "Язык";
            TEXT_SETTINGS_LANGUAGE.font =  "Comic Sans MS";
            TEXT_SETTINGS_LANGUAGE.size =  64;
            
            TEXT_BUYITEM_BUY.string =  "Купить";
            TEXT_BUYITEM_BUY.font =  "Comic Sans MS";
            TEXT_BUYITEM_BUY.size =  46;
            
            TEXT_EXIT_YES.string =  "Да";
            TEXT_EXIT_YES.font =  "Comic Sans MS";
            TEXT_EXIT_YES.size =  64;
            
            TEXT_EXIT_STRING_1.string =  "Вы действительно";
            TEXT_EXIT_STRING_1.font =  "Comic Sans MS";
            TEXT_EXIT_STRING_1.size =  48;
            
            TEXT_EXIT_STRING_2.string =  "хотите выйти?";
            TEXT_EXIT_STRING_2.font =  "Comic Sans MS";
            TEXT_EXIT_STRING_2.size =  48;
            
            TEXT_RATE_NOW.string =  "Оценить";
            TEXT_RATE_NOW.font =  "Comic Sans MS";
            TEXT_RATE_NOW.size =  46;
            
            TEXT_RATE_STRING_1.string =  "Вам понравилась";
            TEXT_RATE_STRING_1.font =  "Comic Sans MS";
            TEXT_RATE_STRING_1.size =  48;
            
            TEXT_RATE_STRING_2.string =  "наша игра?";
            TEXT_RATE_STRING_2.font =  "Comic Sans MS";
            TEXT_RATE_STRING_2.size =  48;
            
            TEXT_RATE_STRING_3.string =  "Пожалуйста";
            TEXT_RATE_STRING_3.font =  "Comic Sans MS";
            TEXT_RATE_STRING_3.size =  48;
            
            TEXT_RATE_STRING_4.string =  "проголосуйте за нее!";
            TEXT_RATE_STRING_4.font =  "Comic Sans MS";
            TEXT_RATE_STRING_4.size =  40;
            
            TEXT_GETCOINS_STRING_1.string =  "Желаете купить";
            TEXT_GETCOINS_STRING_1.font =  "Comic Sans MS";
            TEXT_GETCOINS_STRING_1.size =  48;
            
            TEXT_GETCOINS_STRING_2.string =  "несколько монет?";
            TEXT_GETCOINS_STRING_2.font =  "Comic Sans MS";
            TEXT_GETCOINS_STRING_2.size =  48;
            
            TEXT_GETCOINS_1.string =  "$0.99";
            TEXT_GETCOINS_1.font =  "Comic Sans MS";
            TEXT_GETCOINS_1.size =  64;
            
            TEXT_GETCOINS_2.string =  "$1.99";
            TEXT_GETCOINS_2.font =  "Comic Sans MS";
            TEXT_GETCOINS_2.size =  64;
            
            TEXT_GETCOINS_3.string =  "$3.99";
            TEXT_GETCOINS_3.font =  "Comic Sans MS";
            TEXT_GETCOINS_3.size =  64;
            
            TEXT_GETCOINS_4.string =  "$9.99";
            TEXT_GETCOINS_4.font =  "Comic Sans MS";
            TEXT_GETCOINS_4.size =  64;
            
            TEXT_PROGRESS_STRING_1.string =  "Если Вы хотите пройти";
            TEXT_PROGRESS_STRING_1.font =  "Comic Sans MS";
            TEXT_PROGRESS_STRING_1.size =  48;
            
            TEXT_PROGRESS_STRING_2.string =  "игру снова, Вы можете";
            TEXT_PROGRESS_STRING_2.font =  "Comic Sans MS";
            TEXT_PROGRESS_STRING_2.size =  48;
            
            TEXT_PROGRESS_STRING_3.string =  "сбросить прогресс.";
            TEXT_PROGRESS_STRING_3.font =  "Comic Sans MS";
            TEXT_PROGRESS_STRING_3.size =  48;
            
            TEXT_PROGRESS_RESET.string =  "Сбросить";
            TEXT_PROGRESS_RESET.font =  "Comic Sans MS";
            TEXT_PROGRESS_RESET.size =  48;
            
            TEXT_RESET_STRING_1.string =  "Вы уверены что";
            TEXT_RESET_STRING_1.font =  "Comic Sans MS";
            TEXT_RESET_STRING_1.size =  48;
            
            TEXT_RESET_STRING_2.string =  "хотите сбросить прогресс?";
            TEXT_RESET_STRING_2.font =  "Comic Sans MS";
            TEXT_RESET_STRING_2.size =  32;
            
            TEXT_RESET_STRING_3.string =  "Вы начнете игру";
            TEXT_RESET_STRING_3.font =  "Comic Sans MS";
            TEXT_RESET_STRING_3.size =  48;
            
            TEXT_RESET_STRING_4.string =  "с первого уровня!";
            TEXT_RESET_STRING_4.font =  "Comic Sans MS";
            TEXT_RESET_STRING_4.size =  48;
            
            TEXT_RESET_RESET.string =  "Сбросить";
            TEXT_RESET_RESET.font =  "Comic Sans MS";
            TEXT_RESET_RESET.size =  40;
            
            TEXT_CREDITS_STRING_1.string =  "О игре\nBubble Fun\nВерсия: 0.0.1\nСборка: 1190";
            TEXT_CREDITS_STRING_1.font =  "Comic Sans MS";
            TEXT_CREDITS_STRING_1.size =  48;
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
    TEXTES_HOLDER[22] = TEXT_PROGRESS_STRING_2;
    TEXTES_HOLDER[23] = TEXT_PROGRESS_STRING_3;
    TEXTES_HOLDER[24] = TEXT_PROGRESS_RESET;
    TEXTES_HOLDER[25] = TEXT_RESET_STRING_1;
    TEXTES_HOLDER[26] = TEXT_RESET_STRING_2;
    TEXTES_HOLDER[27] = TEXT_RESET_STRING_3;
    TEXTES_HOLDER[28] = TEXT_RESET_STRING_4;
    TEXTES_HOLDER[29] = TEXT_RESET_RESET;
    TEXTES_HOLDER[30] = TEXT_CREDITS_STRING_1;
    
    for(int i = 0; i < 32; i++)
    {
        if(Text::TEXTES[i] != NULL)
        {
            Text::TEXTES[i]->changeLanguage();
        }
    }
}

// ===========================================================
// Virtual Methods
// ===========================================================

#endif