#import <UIKit/UIKit.h>
#import <EziSocialSDK/EziSocialManager.h>
#import "AppController.h"
#import "cocos2d.h"
#import "EAGLView.h"
#import "AppDelegate.h"

#import "RootViewController.h"

@implementation AppController

@synthesize window;
@synthesize viewController;

#pragma mark -
#pragma mark Application lifecycle

static AppDelegate s_sharedApplication;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    EAGLView *__glView = [EAGLView viewWithFrame: [window bounds]
                                     pixelFormat: kEAGLColorFormatRGBA8
                                     depthFormat: GL_DEPTH_COMPONENT16
                              preserveBackbuffer: NO
                                      sharegroup: nil
                                   multiSampling: NO
                                 numberOfSamples: 0 ];
    
    UIApplication* app = [UIApplication sharedApplication];
    app.idleTimerDisabled = YES;
    
    viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    viewController.wantsFullScreenLayout = YES;
    viewController.view = __glView;
    
    if([[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        [window addSubview: viewController.view];
    }
    else
    {
        [window setRootViewController:viewController];
    }
    
    [window makeKeyAndVisible];
    
    [[UIApplication sharedApplication] setStatusBarHidden: YES];
    
    [__glView setMultipleTouchEnabled:YES];
    
    NSString* deviceType = machineName();
    NSRange match = [deviceType rangeOfString: @"iPod"];
    
    if(match.location != NSNotFound)
    {
        s_sharedApplication.IS_IPOD = true;
    }
    else
    {
        s_sharedApplication.IS_IPOD = false;
    }
    
    [[EziSocialManager sharedManager] setDebug: NO];
    
    cocos2d::CCApplication::sharedApplication()->run();
    
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    cocos2d::CCDirector::sharedDirector()->pause();
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    cocos2d::CCDirector::sharedDirector()->resume();
    
    [[UIApplication sharedApplication] cancelAllLocalNotifications];
    [UIApplication sharedApplication].applicationIconBadgeNumber = 0;
    
    [[EziSocialManager sharedManager] handleApplicationDidBecomeActive];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    cocos2d::CCApplication::sharedApplication()->applicationDidEnterBackground();
    
    UILocalNotification* notification1 = [[UILocalNotification alloc] init];
    UILocalNotification* notification2 = [[UILocalNotification alloc] init];
    UILocalNotification* notification3 = [[UILocalNotification alloc] init];

    notification1.fireDate = [NSDate dateWithTimeIntervalSinceNow:3600*10];
    notification2.fireDate = [NSDate dateWithTimeIntervalSinceNow:3600*24];
    notification3.fireDate = [NSDate dateWithTimeIntervalSinceNow:60*30];
    
    notification1.alertBody = NSLocalizedString(@"1", @"");
    notification2.alertBody = NSLocalizedString(@"2", @"");
    notification3.alertBody = NSLocalizedString(@"3", @"");

    notification1.timeZone = [NSTimeZone defaultTimeZone];
    notification2.timeZone = [NSTimeZone defaultTimeZone];
    notification3.timeZone = [NSTimeZone defaultTimeZone];
    
    notification1.applicationIconBadgeNumber = 1;
    notification2.applicationIconBadgeNumber = 1;
    notification3.applicationIconBadgeNumber = 1;
    
    notification1.soundName = UILocalNotificationDefaultSoundName;
    notification2.soundName = UILocalNotificationDefaultSoundName;
    notification3.soundName = UILocalNotificationDefaultSoundName;

    [[UIApplication sharedApplication] scheduleLocalNotification:notification1];
    [[UIApplication sharedApplication] scheduleLocalNotification:notification2];
    [[UIApplication sharedApplication] scheduleLocalNotification:notification3];
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    cocos2d::CCApplication::sharedApplication()->applicationWillEnterForeground();
}

- (void)applicationWillTerminate:(UIApplication *)application {
}


#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    cocos2d::CCDirector::sharedDirector()->purgeCachedData();
}


- (void)dealloc {
    [super dealloc];
}

#import <sys/utsname.h>

NSString* machineName()
{
    struct utsname systemInfo;
    uname(&systemInfo);
    
    return [NSString stringWithCString:systemInfo.machine encoding:NSUTF8StringEncoding];
}

- (BOOL)application: (UIApplication*) application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    if ([sourceApplication isEqualToString:@"com.apple.mobilesafari"] ||
        [sourceApplication isEqualToString:@"com.facebook.Facebook"])
    {
        return [[EziSocialManager sharedManager] handleURL:url];
    }
    else
    {
        return NO;
    }
}

@end

