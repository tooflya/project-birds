#include "AppDelegate.cpp"
#include "Options.cpp"
#include "Options.cpp"
#include "AppDelegate.cpp"
#include "Utils.cpp"
#include "List.cpp"
#include "Touchable.cpp"
#include "CreditsList.cpp"
#include "BuyItemList.cpp"
#include "ModeHelpList.cpp"
#include "Entity.cpp"
#include "Button.cpp"
#include "PlayButton.cpp"
#include "Text.cpp"
#include "Confetti.cpp"
#include "Star.cpp"
#include "EntityManager.cpp"
#include "BatchEntityManager.cpp"
#include "ConfettiManager.cpp"
#include "Screen.cpp"
#include "Menu.cpp"
#include "Settings.cpp"
#include "Shop.cpp"
#include "Mode.cpp"
#include "Levels.cpp"
#include "Credits.cpp"
#include "Loader.cpp"
#include "Progresses.cpp"
#include "Arcade.cpp"
#include "ExplosionBasic.cpp"
#include "More.cpp"
#include "End.cpp"
#include "Splash.cpp"
#include "Loading.cpp"
#include "Progress.cpp"
#include "Language.cpp"
#include "Popup.cpp"
#include "Exit.cpp"
#include "BuyItem.cpp"
#include "GetCoins.cpp"
#include "PleaseRate.cpp"
#include "ResetProgress.cpp"
#include "ModeHelp.cpp"
#include "ScreenManager.cpp"
#include "Texture.cpp"
#include "ImpulseEntity.cpp"
#include "Bird.cpp"
#include "Clock.cpp"
#include "Pause.cpp"
#include "TempPublisherAchievementsExplain.cpp"
#include "TempPublisherRatingExplain.cpp"
#include "Classic.cpp"
#include "Game.cpp"
#include "Explosion.cpp"
#include "Feather.cpp"
#include "Dust.cpp"
#include "CCBlade.cpp"
#include "Mark.cpp"
#include "Item.cpp"
#include "TouchTrailLayer.cpp"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <platform/CCPlatformConfig.h>
#include <android/log.h>

#define  LOG_TAG    "main"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

using namespace cocos2d;

extern "C"
{

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JniHelper::setJavaVM(vm);

    return JNI_VERSION_1_4;
}

void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeInit(JNIEnv*  env, jobject thiz, jint w, jint h)
{
    if (!CCDirector::sharedDirector()->getOpenGLView())
    {
        CCEGLView *view = CCEGLView::sharedOpenGLView();
        view->setFrameSize(w, h);

        AppDelegate *pAppDelegate = new AppDelegate();
        CCApplication::sharedApplication()->run();
    }
    else
    {
        ccDrawInit();
        ccGLInvalidateStateCache();
        
        CCShaderCache::sharedShaderCache()->reloadDefaultShaders();
        CCTextureCache::reloadAllTextures();
        CCNotificationCenter::sharedNotificationCenter()->postNotification(EVNET_COME_TO_FOREGROUND, NULL);
        CCDirector::sharedDirector()->setGLDefaultValues(); 
    }
}

}
