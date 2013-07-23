#ifndef CONST_OPTIONS_H
#define CONST_OPTIONS_H

#include "cocos2d.h"

using namespace cocos2d;

typedef struct tagCCTouchInformation {
    bool slice;
    long last_sound_time;
    long last_slice_time;
    CCPoint last_sound_position;
    CCPoint last_slice_position;
    CCPoint position;
} CCTouchInformation;

typedef struct Textes {
    const char* string;
    const char* font;
    int size;
    int identifier;
} Textes;

class Options
{
    protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================

        // ===========================================================
        // Override Methods
        // ===========================================================

    private:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================

    public:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static int CENTER_X;
        static int CENTER_Y;

        static int SCREEN_WIDTH;
        static int SCREEN_HEIGHT;

        static int SCREEN_CENTER_X;
        static int SCREEN_CENTER_Y;

        static int CAMERA_WIDTH;
        static int CAMERA_HEIGHT;

        static int CAMERA_CENTER_X;
        static int CAMERA_CENTER_Y;

        static bool MUSIC_ENABLE;
        static bool SOUND_ENABLE;

        static const char* FONT;

        static const char* SAVE_DATA_COINS_ID[2];
        static const char* SAVE_DATA_LANGUAGE_ID;

        static CCTouchInformation TOUCH_INFORMATION[10];
        
        static int SAVE_DATA_COINS_TYPE_GOLD;
        static int SAVE_DATA_COINS_TYPE_SILVER;
    
        static int CURRENT_LANGUAGE;
    
        static Textes TEXTES_HOLDER[200];

        static int SHOP_ITEMS_PRICES[100];
        static int SHOP_ITEMS_RATING_FACTOR[100];
        static const char* SHOP_ITEMS_PROPERTIES[100];

        static const int BUTTONS_ACTION_ONTOUCH = 0;
        static const int BUTTONS_ACTION_ONBEGIN = 1;
        static const int BUTTONS_ACTION_ONEND = 2;

        static const int BUTTONS_ID_SETTINGS_BACK  = 1001;
        static const int BUTTONS_ID_SETTINGS_RATE  = 1002;
        static const int BUTTONS_ID_SETTINGS_SOUND  = 1003;
        static const int BUTTONS_ID_SETTINGS_MUSIC  = 1004;
        static const int BUTTONS_ID_SETTINGS_CREDITS = 1005;
        static const int BUTTONS_ID_SETTINGS_LANGUAGE = 1006;
        static const int BUTTONS_ID_SETTINGS_MORE     = 1007;
        static const int BUTTONS_ID_CREDITS_BACK  = 2001;
        static const int BUTTONS_ID_MENU_PLAY  = 3001;
        static const int BUTTONS_ID_MENU_SHOP  = 3002;
        static const int BUTTONS_ID_MENU_TWITTER  = 3003;
        static const int BUTTONS_ID_MENU_FACEBOOK  = 3004;
        static const int BUTTONS_ID_MENU_SETTINGS  = 3005;
        static const int BUTTONS_ID_LEVELS_BACK  = 4001;
        static const int BUTTONS_ID_MODE_BACK  = 5001;
        static const int BUTTONS_ID_MODE_CLASSIC  = 5002;
        static const int BUTTONS_ID_MODE_ARCADE  = 5003;
        static const int BUTTONS_ID_MODE_PROGRESS  = 5004;
        static const int BUTTONS_ID_MODE_HELP  = 5005;
        static const int BUTTONS_ID_SHOP_BACK  = 6001;
        static const int BUTTONS_ID_SHOP_ITEM  = 6102;
        static const int BUTTONS_ID_SHOP_TABLET = 6103;
        static const int BUTTONS_ID_END_MENU  = 7001;
        static const int BUTTONS_ID_END_RESTART  = 7002;
        static const int BUTTONS_ID_END_CONTINUE  = 7003;
        static const int BUTTONS_ID_POPUP_CLOSE  = 8001;
        static const int BUTTONS_ID_BUYITEM_BUY  = 9001;
        static const int BUTTONS_ID_EXIT_YES  = 1101;
        static const int BUTTONS_ID_RATE_RATE  = 1201;
        static const int BUTTONS_ID_GETCOINS_1  = 1301;
        static const int BUTTONS_ID_GETCOINS_2  = 1302;
        static const int BUTTONS_ID_GETCOINS_3  = 1303;
        static const int BUTTONS_ID_GETCOINS_4  = 1304;
        static const int BUTTONS_ID_PROGRESS_BACK  = 1401;
        static const int BUTTONS_ID_PROGRESS_RESET  = 1402;
        static const int BUTTONS_ID_RESET_RESET  = 1501;
        static const int BUTTONS_ID_LANGUAGE_BACK  = 1601;
        static const int BUTTONS_ID_LANGUAGE_L_EN  = 1701;
        static const int BUTTONS_ID_LANGUAGE_L_RU  = 1702;
        static const int BUTTONS_ID_GAME_RESTART = 1801;
        static const int BUTTONS_ID_GAME_PAUSE = 1802;
        static const int BUTTONS_ID_PAUSE_MENU = 1901;
        static const int BUTTONS_ID_PAUSE_RESTART = 1902;
        static const int BUTTONS_ID_PAUSE_CONTINUE = 1903;
    
        static Textes TEXT_SETTINGS_CREDITS;
        static Textes TEXT_SETTINGS_PROGRESS;
        static Textes TEXT_SETTINGS_MORE;
        static Textes TEXT_SETTINGS_LANGUAGE;
        static Textes TEXT_BUYITEM_BUY;
        static Textes TEXT_EXIT_YES;
        static Textes TEXT_EXIT_STRING_1;
        static Textes TEXT_EXIT_STRING_2;
        static Textes TEXT_RATE_NOW;
        static Textes TEXT_RATE_STRING_1;
        static Textes TEXT_RATE_STRING_2;
        static Textes TEXT_RATE_STRING_3;
        static Textes TEXT_RATE_STRING_4;
        static Textes TEXT_GETCOINS_STRING_1;
        static Textes TEXT_GETCOINS_STRING_2;
        static Textes TEXT_GETCOINS_STRING_3;
        static Textes TEXT_GETCOINS_STRING_4;
        static Textes TEXT_GETCOINS_1;
        static Textes TEXT_GETCOINS_2;
        static Textes TEXT_GETCOINS_3;
        static Textes TEXT_GETCOINS_4;
        static Textes TEXT_LOADING_1;
        static Textes TEXT_LOADING_2;
        static Textes TEXT_PROGRESS_STRING_1;
        static Textes TEXT_PROGRESS_RESET;
        static Textes TEXT_RESET_STRING_1;
        static Textes TEXT_RESET_STRING_2;
        static Textes TEXT_RESET_STRING_3;
        static Textes TEXT_RESET_STRING_4;
        static Textes TEXT_RESET_RESET;
        static Textes TEXT_CREDITS_STRING_1;
        static Textes TEXT_CREDITS_STRING_2;
        static Textes TEXT_CREDITS_STRING_3;
        static Textes TEXT_CREDITS_STRING_4;
        static Textes TEXT_CREDITS_STRING_5;
        static Textes TEXT_CREDITS_STRING_6;
        static Textes TEXT_CREDITS_STRING_7;
        static Textes TEXT_CREDITS_STRING_8;
        static Textes TEXT_CREDITS_STRING_9;
        static Textes TEXT_CREDITS_STRING_10;
        static Textes TEXT_CREDITS_STRING_11;
        static Textes TEXT_CREDITS_STRING_12;
        static Textes TEXT_CREDITS_STRING_13;
        static Textes TEXT_SHOP_DESCRIPTION[3];
        static Textes TEXT_MODE_CLASSIC;
        static Textes TEXT_MODE_ARCADE;
        static Textes TEXT_MODE_PROGRESS;
        static Textes TEXT_MODEHELP_OK;
        static Textes TEXT_MODEHELP_HELP[2];
        static Textes TEXT_SHOP_ITEMS[64];
        static Textes TEXT_SHOP_ITEMS_DESCRIPTIONS[64];
        static Textes TEXT_SHOP_BOUGHT;
        static Textes TEXT_TAP_TO_CONTINUE;
        static Textes TEXT_TIP[10];

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Options();

        // ===========================================================
        // Methods
        // ===========================================================
    
        static void changeLanguage();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
};

#endif