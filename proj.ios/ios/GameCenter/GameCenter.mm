#include "GameCenter.h"
#include "GameCenterIos.h"

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

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
void GameCenter::open(int target)
{
    [[GameCenterIos shared] open:target];
}
#endif