COCOS2DX_PATH = /home/igor/Development/cocos2d-x-2.1.4/cocos2dx
COCOS_PATH = /home/igor/Development/cocos2d-x-2.1.4

EXECUTABLE = ProjectBirds

INCLUDES =  -I../ \
			-I../Classes \
			-I../Classes/Screens \
			-I../Classes/Screens/Screens \
			-I../Classes/Screens/Popups \
			-I../Classes/Managers \
			-I../Classes/Entities \
			-I../Classes/Utils \
			-I../Classes/Graphics \
			-I$(COCOS2DX_PATH) \
			-I$(COCOS2DX_PATH)/platform/third_party/linux \
			-I$(COCOS2DX_PATH)/cocoa \
			-I$(COCOS2DX_PATH)/include \
			-I$(COCOS2DX_PATH)/platform \
			-I$(COCOS2DX_PATH)/platform/linux \
			-I$(COCOS2DX_PATH)/kazmath/include \
			-I$(COCOS_PATH)/extensions/ \
			-I$(COCOS_PATH)/external/ \
			-I$(COCOS_PATH)/CocosDenshion/include

SOURCES = ./main.cpp \
			../Classes/Options.cpp \
			../Classes/AppDelegate.cpp \
			../Classes/Utils/Utils.cpp \
			../Classes/Utils/List.cpp \
			../Classes/Utils/Touchable.cpp \
			../Classes/Utils/CreditsList.cpp \
			../Classes/Utils/BuyItemList.cpp \
			../Classes/Utils/ModeHelpList.cpp \
			../Classes/Entities/Entity.cpp \
			../Classes/Entities/Button.cpp \
			../Classes/Entities/PlayButton.cpp \
			../Classes/Entities/Text.cpp \
			../Classes/Entities/Confetti.cpp \
			../Classes/Entities/Star.cpp \
			../Classes/Managers/EntityManager.cpp \
			../Classes/Managers/BatchEntityManager.cpp \
			../Classes/Managers/ConfettiManager.cpp \
			../Classes/Screens/Screen.cpp \
			../Classes/Screens/Screens/Menu.cpp \
			../Classes/Screens/Screens/Settings.cpp \
			../Classes/Screens/Screens/Shop.cpp \
			../Classes/Screens/Screens/Mode.cpp \
			../Classes/Screens/Screens/Levels.cpp \
			../Classes/Screens/Screens/Credits.cpp \
			../Classes/Screens/Screens/Loader.cpp \
			../Classes/Screens/Screens/Level.cpp \
			../Classes/Screens/Screens/End.cpp \
			../Classes/Screens/Screens/Splash.cpp \
			../Classes/Screens/Screens/Loading.cpp \
			../Classes/Screens/Screens/Progress.cpp \
			../Classes/Screens/Screens/Language.cpp \
			../Classes/Screens/Popup.cpp \
			../Classes/Screens/Popups/Exit.cpp \
			../Classes/Screens/Popups/BuyItem.cpp \
			../Classes/Screens/Popups/GetCoins.cpp \
			../Classes/Screens/Popups/PleaseRate.cpp \
			../Classes/Screens/Popups/ResetProgress.cpp \
			../Classes/Screens/Popups/ModeHelp.cpp \
			../Classes/Managers/ScreenManager.cpp \
			../Classes/Graphics/Texture.cpp \

COCOS_ROOT = ../../../..
include $(COCOS2DX_PATH)/proj.linux/cocos2dx.mk

SHAREDLIBS += -lcocos2d -lcocosdenshion
COCOS_LIBS = $(LIB_DIR)/libcocos2d.so \
			 $(LIB_DIR)/libcocosdenshion.so

$(TARGET): $(OBJECTS) $(STATICLIBS) $(COCOS_LIBS) $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_LINK)$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(SHAREDLIBS) $(STATICLIBS)

$(OBJ_DIR)/%.o: %.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@

$(OBJ_DIR)/%.o: ../%.cpp $(CORE_MAKEFILE_LIST)
	@mkdir -p $(@D)
	$(LOG_CXX)$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(VISIBILITY) -c $< -o $@
