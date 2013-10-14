#include "AppDelegate.cpp"
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
#include "ImpulseEntity.cpp"
#include "Bird.cpp"
#include "Mark.cpp"
#include "Explosion.cpp"
#include "ExplosionBasic.cpp"
#include "GeneralExplosion.cpp"
#include "ZombieExplosion.cpp"
#include "PirateBox.cpp"
#include "UnlockLevel.cpp"
#include "Clock.cpp"
#include "Feather.cpp"
#include "Dust.cpp"
#include "Item.cpp"
#include "StarParticle.cpp"
#include "EventPanel.cpp"
#include "WeaponParticle.cpp"
#include "Color.cpp"
#include "EntityManager.cpp"
#include "BatchEntityManager.cpp"
#include "Screens/Screen.cpp"
#include "Menu.cpp"
#include "Settings.cpp"
#include "Shop.cpp"
#include "Mode.cpp"
#include "Levels.cpp"
#include "Credits.cpp"
#include "Loader.cpp"
#include "End.cpp"
#include "AnimatedCoin.cpp"
#include "PaymentProceed.cpp"
#include "Splash.cpp"
#include "Loading.cpp"
#include "Progress.cpp"
#include "Language.cpp"
#include "Game.cpp"
#include "Classic.cpp"
#include "Arcade.cpp"
#include "Progresses.cpp"
#include "More.cpp"
#include "Screens/Popup.cpp"
#include "Exit.cpp"
#include "BuyItem.cpp"
#include "Map.cpp"
#include "GetCoins.cpp"
#include "GetLives.cpp"
#include "GetKeys.cpp"
#include "PleaseRate.cpp"
#include "ResetProgress.cpp"
#include "ModeHelp.cpp"
#include "Pause.cpp"
#include "BoughtItem.cpp"
#include "TempPublisherRatingExplain.cpp"
#include "TempPublisherAchievementsExplain.cpp"
#include "ScreenManager.cpp"
#include "Texture.cpp"
#include "TouchTrailLayer.cpp"
#include "CCBlade.cpp"
#include "SpecialBird.cpp"
#include "StarParticle2.cpp"
#include "Ripple.cpp"
#include "Rain.cpp"
#include "RainCircle.cpp"
#include "RobotoPart.cpp"
#include "RobotoGun.cpp"
#include "ButtonReceiver.cpp"
#include "KeyParticle.cpp"
#include "LiveParticle.cpp"
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
