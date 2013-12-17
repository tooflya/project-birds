#import <UIKit/UIKit.h>
#import <GameKit/GameKit.h>

@interface RootViewController : UIViewController<GKAchievementViewControllerDelegate, GKLeaderboardViewControllerDelegate> {

}
- (BOOL) prefersStatusBarHidden;

- (void)achievementViewControllerDidFinish:(GKAchievementViewController *)viewController;
- (void)leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController;
@end
