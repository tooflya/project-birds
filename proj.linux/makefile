COCOS2DX_PATH = /home/igor/Development/cocos2d-x-2.1.4/cocos2dx
COCOS_PATH = /home/igor/Development/cocos2d-x-2.1.4

EXECUTABLE = ProjectBirds

INCLUDES =  -I../ \
			-I../Classes \
			-I../Classes/Screens \
			-I../Classes/Enemies \
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
			../Classes/Screens/Menu.cpp \
			../Classes/Screens/Settings.cpp \
			../Classes/Screens/Shop.cpp \
			../Classes/Screens/Mode.cpp \
			../Classes/Screens/Levels.cpp \
			../Classes/Screens/Credits.cpp \
			../Classes/Screens/Loader.cpp \
			../Classes/Screens/Level.cpp \
			../Classes/Screens/End.cpp \
			../Classes/Screens/Splash.cpp \
			../Classes/Screens/Loading.cpp \
			../Classes/Screens/Progress.cpp \
			../Classes/Screens/Language.cpp \
			../Classes/Screens/Popup.cpp \
			../Classes/Screens/Exit.cpp \
			../Classes/Screens/BuyItem.cpp \
			../Classes/Screens/GetCoins.cpp \
			../Classes/Screens/PleaseRate.cpp \
			../Classes/Screens/ResetProgress.cpp \
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
