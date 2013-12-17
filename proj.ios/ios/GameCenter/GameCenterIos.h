@interface GameCenterIos : NSObject
{
}

+ (GameCenterIos*)shared;

- (void)login;

- (BOOL)showAchievements;
- (void)postAchievement:(const char*)idName percent:(NSNumber*)percentComplete;
- (void)clearAllAchivements;

- (BOOL)showScores;
- (void)postScore:(const char*)idName score:(NSNumber*)score;
- (void)clearAllScores;

- (void)open:(int)target;

- (void)playVideo:(BOOL)enableMusic;
- (void)onVideoPlayback;

@end

#ifdef __cplusplus
extern "C" {
#endif
    
void onVideoPlayback();
    
#ifdef __cplusplus
}
#endif