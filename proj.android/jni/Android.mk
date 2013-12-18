LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
                    $(LOCAL_PATH)/../../../../extensions/cocos2dx-store/android/src \
                    $(LOCAL_PATH)/../../../../extensions/cocos2dx-store/submodules/android-store/SoomlaAndroidStore/src \
                    $(LOCAL_PATH)/../../Classes/Screens \
                    $(LOCAL_PATH)/../../Classes/Screens/Screens \
                    $(LOCAL_PATH)/../../Classes/Screens/Popups \
                    $(LOCAL_PATH)/../../Classes/Entities \
                    $(LOCAL_PATH)/../../Classes/Managers \
                    $(LOCAL_PATH)/../../Classes/Utils \
                    $(LOCAL_PATH)/../../Classes/Graphics \
                    $(LOCAL_PATH)/../../Classes/TEST \
                    $(LOCAL_PATH)/../../Classes/InApp \
                    $(LOCAL_PATH)/../../Classes/GameCenter \
                    $(LOCAL_PATH)/../../Classes/GameCenter/include \

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_store_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,extensions/cocos2dx-store/android/jni)