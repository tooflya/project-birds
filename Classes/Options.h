#ifndef CONST_OPTIONS_H
#define CONST_OPTIONS_H

#include "cocos2d.h"

using namespace cocos2d;

#define ccsf(...) CCString::createWithFormat(__VA_ARGS__)->getCString()

typedef struct tagCCTouchInformation {
    bool slice;
    long last_sound_time;
    long last_slice_time;
    CCPoint last_sound_position;
    CCPoint last_slice_position;
    CCPoint position;
} CCTouchInformation;

typedef struct tagTextes {
    const char* string;
    const char* font;
    int size;
    int identifier;
} Textes;

typedef struct tagTextureStructure {
    const char* texture;
    const char* frames;
} TextureStructure;

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
    
        static const char* TEXTURES_EXTENSION;
    
        static int SELECTED_WEAPON_ID;

        static const char* MUSIC_1;
        static const char* MUSIC_2;

        static const char* SOUND_TAP;
        static const char* SOUND_UNLOCKED;
        static const char* SOUND_BIRD_BLOW;
        static const char* SOUND_DANGER_EXPLOSION;
        static const char* SOUND_THROW;
        static const char* SOUND_THROW_BOMB;
        static const char* SOUND_LOSE_LIFE;
        static const char* SOUND_HIT;
        static const char* SOUND_BONUS_GONG;
        static const char* SOUND_BOMB_FUSE;
        static const char* SOUND_EQUIP_SWORD;
        static const char* SOUND_BONUS_TIME[3];
        static const char* SOUND_SWOOSH;
        static const char* SOUND_FREEZEE;
        static const char* SOUND_PREDICTION;
        static const char* SOUND_POINTS[12];
        static const char* SOUND_PROGRESS;
        static const char* SOUND_COMBO[8];
        static const char* SOUND_LEVEL_UNLOCK;

        static const char* VERSION;
        static std::string STRING_VERSION;
        static int BUILD;
    
        static int DEVICE_TYPE;
    
        static const int DEVICE_TYPE_IOS = 0;
        static const int DEVICE_TYPE_ANDROID = 1;
        static const int DEVICE_TYPE_WP = 2;
        static const int DEVICE_TYPE_MAC = 3;
        static const int DEVICE_TYPE_LINUX = 4;
        static const int DEVICE_TYPE_WINDOWS = 5;
    
        static const int DEVICE_TYPE_IPHONE5 = 10;
        static const int DEVICE_TYPE_IPHONE4 = 11;
        static const int DEVICE_TYPE_IPOD4 = 12;
        static const int DEVICE_TYPE_IPAD_RETINA = 13;
    
        static const int DEVICE_TYPE_NEXUS3 = 20;

        static const char* FONT;

        static const char* SAVE_DATA_COINS_ID[4];
        static const char* SAVE_DATA_BEST_RESULT[2];
        static const char* SAVE_DATA_LANGUAGE_ID;

        static CCTouchInformation TOUCH_INFORMATION[10];
        
        static int SAVE_DATA_COINS_TYPE_GOLD;
        static int SAVE_DATA_COINS_TYPE_SILVER;
        static int SAVE_DATA_COINS_TYPE_LIVES;
        static int SAVE_DATA_COINS_TYPE_KEYS;
    
        static int CURRENT_LANGUAGE;
    
        static Textes TEXTES_HOLDER[600];

        static int SHOP_ITEMS_PRICES[100];
        static int SHOP_ITEMS_PRICES_GOLD[100];
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
        static const int BUTTONS_ID_MENU_VK = 3005;
        static const int BUTTONS_ID_MENU_SETTINGS  = 3006;
        static const int BUTTONS_ID_LEVELS_BACK  = 4001;
        static const int BUTTONS_ID_MODE_BACK  = 5001;
        static const int BUTTONS_ID_MODE_CLASSIC  = 5002;
        static const int BUTTONS_ID_MODE_ARCADE  = 5003;
        static const int BUTTONS_ID_MODE_PROGRESS  = 5004;
        static const int BUTTONS_ID_MODE_LEADERBOARD = 5005;
        static const int BUTTONS_ID_MODE_ACHIEVEMENTS = 5006;
        static const int BUTTONS_ID_MODE_HELP  = 5007;
        static const int BUTTONS_ID_SHOP_BACK  = 6001;
        static const int BUTTONS_ID_SHOP_ITEM  = 6102;
        static const int BUTTONS_ID_SHOP_GET_SILVER_COINS = 6103;
        static const int BUTTONS_ID_SHOP_GET_GOLD_COINS = 6104;
        static const int BUTTONS_ID_SHOP_GET_LIVES = 6105;
        static const int BUTTONS_ID_SHOP_GET_KEYS = 6106;
        static const int BUTTONS_ID_END_MENU  = 7001;
        static const int BUTTONS_ID_END_RESTART  = 7002;
        static const int BUTTONS_ID_END_CONTINUE  = 7003;
        static const int BUTTONS_ID_END_SHOP  = 7004;
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
        static const int BUTTONS_ID_LANGUAGE_L_DE  = 1703;
        static const int BUTTONS_ID_LANGUAGE_L_ES  = 1704;
        static const int BUTTONS_ID_LANGUAGE_L_FR  = 1705;
        static const int BUTTONS_ID_LANGUAGE_L_NL  = 1706;
        static const int BUTTONS_ID_LANGUAGE_L_IT  = 1707;
        static const int BUTTONS_ID_LANGUAGE_L_JP  = 1708;
        static const int BUTTONS_ID_LANGUAGE_L_KR  = 1709;
        static const int BUTTONS_ID_LANGUAGE_L_CN  = 1710;
        static const int BUTTONS_ID_GAME_RESTART = 1801;
        static const int BUTTONS_ID_GAME_PAUSE = 1802;
        static const int BUTTONS_ID_GAME_GET_LIVES = 1803;
        static const int BUTTONS_ID_PAUSE_MENU = 1901;
        static const int BUTTONS_ID_PAUSE_RESTART = 1902;
        static const int BUTTONS_ID_PAUSE_CONTINUE = 1903;
        static const int BUTTONS_ID_PAUSE_SHOP = 1904;
        static const int BUTTONS_ID_PAUSE_ACHIEVEMENTS = 1905;
        static const int BUTTONS_ID_PAUSE_LEADERBOARD = 1906;
        static const int BUTTONS_ID_PAUSE_MODE = 1907;
        static const int BUTTONS_ID_MORE_BACK = 2001;
        static const int BUTTONS_ID_SHARE = 2101;
        static const int BUTTONS_ID_SHARE_TWITTER = 2102;
        static const int BUTTONS_ID_SHARE_FACEBOOK = 2103;
        static const int BUTTONS_ID_SHARE_VK = 2104;
    
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
        static Textes TEXT_GETLIVES_STRING_1;
        static Textes TEXT_GETKEYS_STRING_1;
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
        static Textes TEXT_SHOP_ITEMS[90];
        static Textes TEXT_SHOP_ITEMS_DESCRIPTIONS[90];
        static Textes TEXT_SHOP_BOUGHT;
        static Textes TEXT_TAP_TO_CONTINUE;
        static Textes TEXT_TIP[10];
        static Textes TEXT_MORE_GAMES;
        static Textes TEXT_PUBLISHER_STRING_1;
        static Textes TEXT_PUBLISHER_STRING_2;
        static Textes TEXT_PUBLISHER_STRING_3;
        static Textes TEXT_PUBLISHER_STRING_4;
        static Textes TEXT_BUYITEM_CHOOSE;
        static Textes TEXT_ITEM_ALREADY_BOUGHT;
        static Textes TEXT_PAUSE_CONTINUE;
        static Textes TEXT_PAUSE_BACK_TO_SELECT_MODE;
        static Textes TEXT_LANGUAGE_NOT_AVAILABLE;
        static Textes TEXT_GAME_START_STRING_1;
        static Textes TEXT_GAME_START_STRING_2;
        static Textes TEXT_GAME_CLASSIC_LEVEL_UP;
        static Textes TEXT_GAME_SOMETHING_WAS_UNLOCKED;
        static Textes TEXT_GAME_BEST;
        static Textes TEXT_GAME_ARCADE_TIME_REMAINING;
        static Textes TEXT_EVENTS[90];
        static Textes TEXT_GAME_CLASSIC_BONUS_TIME;
        static Textes TEXT_PAYMENT_STRING[6];
        static Textes TEXT_END[7];
        static Textes TEXT_DAILY_MAP;
        static Textes TEXT_COINS_BONUS[10];
        static Textes TEXT_UNLOCKLEVEL;
        static Textes TEXT_UNLOCKLEVEL_OK;
        static Textes TEXT_SURPRISE_OK;
        static Textes TEXT_SURPRISE;

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

        static void init();
    
        static void changeLanguage();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
};

#endif