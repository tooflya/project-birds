#import "RootViewController.h"

@implementation RootViewController

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    return UIInterfaceOrientationIsLandscape( interfaceOrientation );
}

- (NSUInteger) supportedInterfaceOrientations{
    #ifdef __IPHONE_6_0
    return UIInterfaceOrientationMaskAllButUpsideDown;
    #endif
}

- (BOOL) shouldAutorotate {
    return YES;
}

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)viewDidUnload {
    [super viewDidUnload];
}

- (void)dealloc {
    [super dealloc];
}

- (void)achievementViewControllerDidFinish:(GKAchievementViewController *)viewController {
    [self dismissModalViewControllerAnimated:YES];
}

- (void)leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController {
    [self dismissModalViewControllerAnimated:YES];
}

@end
