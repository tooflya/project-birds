#ifndef CONST_GAMECENTER
#define CONST_GAMECENTER

#include "GameCenter.h"
#include "AppDelegate.h"

#include "Menu.h"

#include <jni.h>
#include "cocos2d.h"
#include "platform/android/jni/JniHelper.h"

// ===========================================================
// C++ -> Java
// ===========================================================

const char* const CLASS_NAME = "com/tooflya/projectbirds/GameCenter/GameCenter";

void callStaticVoidMethod(const char* name)
{
    cocos2d::JniMethodInfo t;

    if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, name, "()V"))
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

bool callStaticBoolMethod(const char* name)
{
    cocos2d::JniMethodInfo t;

    if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, name, "()Z"))
    {
        bool result = (t.env->CallStaticBooleanMethod(t.classID, t.methodID) == JNI_TRUE);
        t.env->DeleteLocalRef(t.classID);
        return result;
    }
    else
    {
        return false;
    }
}

void callStaticVoidMethodWithString(const char* name, const char* idName)
{
    cocos2d::JniMethodInfo t;

    if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, name, "(Ljava/lang/String;)V"))
    {
        jstring jIdName = t.env->NewStringUTF(idName);
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jIdName);
        t.env->DeleteLocalRef(t.classID);
        t.env->DeleteLocalRef(jIdName);
    }
}

void callStaticVoidMethodWithStringAndInt(const char* name, const char* idName, const int score)
{
    cocos2d::JniMethodInfo t;

    if (cocos2d::JniHelper::getStaticMethodInfo(t, CLASS_NAME, name, "(Ljava/lang/String;I)V"))
    {
        jstring jIdName = t.env->NewStringUTF(idName);
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jIdName, (jint)score);
        t.env->DeleteLocalRef(t.classID);
        t.env->DeleteLocalRef(jIdName);
    }
}

//

void callStaticVoidMethod(const char* const className, const char* name)
{
    cocos2d::JniMethodInfo t;

    if (cocos2d::JniHelper::getStaticMethodInfo(t, className, name, "()V"))
    {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

void callStaticVoidMethodWithInt(const char* const className, const char* name, const int score)
{
    cocos2d::JniMethodInfo t;

    if (cocos2d::JniHelper::getStaticMethodInfo(t, className, name, "(Ljava/lang/String;I)V"))
    {
        jstring jIdName = t.env->NewStringUTF("");
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jIdName, (jint)score);
        t.env->DeleteLocalRef(t.classID);
        t.env->DeleteLocalRef(jIdName);
    }
}

extern "C"
{
    jint Java_com_tooflya_projectbirds_GameCenter_GameHelper_nativeOnGooglePlusSignInSucceeded(JNIEnv *env, jobject thiz)
    {
        AppDelegate::nativeOnGooglePlusSignInSucceeded();

        return 0;
    }

    jint Java_com_tooflya_projectbirds_GameCenter_GameCenter_nativeOnVideoPlayback(JNIEnv *env, jobject thiz)
    {
        GameCenter::onVideoPlayback();

        return 0;
    }
}

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

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Getters
// ===========================================================

// ===========================================================
// Setters
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

void GameCenter::login()
{
    callStaticVoidMethod("login");
}

bool GameCenter::showAchievements()
{
    return callStaticBoolMethod("showAchievements");
}

void GameCenter::postAchievement(const char* idName, int percentComplete)
{
    callStaticVoidMethodWithStringAndInt("postAchievement", idName, percentComplete);
}

void GameCenter::clearAllAchievements()
{
    callStaticVoidMethod("clearAllAchievements");
}

bool GameCenter::showScores()
{
    return callStaticBoolMethod("showScores");
}

void GameCenter::postScore(const char* idName, int score)
{
    callStaticVoidMethodWithStringAndInt("postScore", idName, score);
}

void GameCenter::clearAllScores()
{
    callStaticVoidMethod("clearAllScores");
}

void GameCenter::signIn()
{
    callStaticVoidMethod("signIn");
}

void GameCenter::signOut()
{
    callStaticVoidMethod("signOut");
}

bool GameCenter::isSignedIn()
{
    return callStaticBoolMethod("isSignedIn");
}

void GameCenter::playVideo(bool enableSound)
{
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();

    callStaticVoidMethod("intro");
}

void GameCenter::onVideoPlayback()
{
    if(AppDelegate::isMusicEnable())
    {
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    }
}

// ===========================================================
// Override Methods
// ===========================================================

#endif