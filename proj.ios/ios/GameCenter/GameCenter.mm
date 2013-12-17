#include "GameCenter.h"
#include "GameCenterIos.h"

#include "AppDelegate.h"

void GameCenter::login()
{
    [[GameCenterIos shared] login];
}
    
bool GameCenter::showAchievements()
{
    return [[GameCenterIos shared] showAchievements];
}
    
void GameCenter::postAchievement(const char* idName, int percentComplete)
{
    [[GameCenterIos shared] postAchievement:idName percent:[NSNumber numberWithInt:percentComplete]];
}
    
void GameCenter::clearAllAchievements()
{
    [[GameCenterIos shared] clearAllAchivements];
}
    
bool GameCenter::showScores()
{
    return [[GameCenterIos shared] showScores];
}
    
void GameCenter::postScore(const char* idName, int score)
{
    [[GameCenterIos shared] postScore:idName score:[NSNumber numberWithInt:score]];
}
    
void GameCenter::clearAllScores()
{
    [[GameCenterIos shared] clearAllScores];
}

void GameCenter::open(int target)
{
    [[GameCenterIos shared] open:target];
}

void GameCenter::playVideo(bool enableMusic)
{
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();

    [[GameCenterIos shared] playVideo:enableMusic];
}

void GameCenter::onVideoPlayback()
{
    if(AppDelegate::isMusicEnable())
    {
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    }
}

void onVideoPlayback()
{
    GameCenter::onVideoPlayback();
}