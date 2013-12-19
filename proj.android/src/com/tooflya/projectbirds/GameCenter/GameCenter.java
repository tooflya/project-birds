package com.tooflya.projectbirds.GameCenter;

import android.content.Intent;
import android.media.MediaPlayer;
import android.net.Uri;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnKeyListener;
import android.view.View.OnTouchListener;
import android.view.ViewGroup.LayoutParams;
import android.widget.RelativeLayout;
import android.widget.VideoView;

import com.google.android.gms.common.SignInButton;
import com.google.android.gms.games.GamesClient;
import com.tooflya.projectbirds.Game;
import com.tooflya.projectbirds.R;

public abstract class GameCenter {
	private static final String TAG = "GameCenter";

	public static Game activity;
	private final static int REQUEST_ACHIEVEMENTS = 9003;
	private final static int REQUEST_LEADERBOARD = 9004;

	private static SignInButton mSignInButton;

	/**
	 * 
	 * Interface used for C++
	 * 
	 */

	public static void login() {
		if (!isSignedIn()) {
			// signIn();
		}
	}

	public static void signIn() {
		activity.runOnUiThread(new Runnable() {
			public void run() {
				getGameHelper().beginUserInitiatedSignIn();
			}
		});
	}

	public static void signOut() {
		if (Game.mHelper == null) {
			return;
		}

		activity.runOnUiThread(new Runnable() {
			public void run() {
				getGameHelper().signOut();
			}
		});
	}

	public static boolean isSignedIn() {
		return (Game.mHelper != null && getGameHelper().isSignedIn());
	}

	public static boolean showAchievements() {
		if (!isSignedIn()) {
			return false;
		}

		activity.runOnUiThread(new Runnable() {
			public void run() {
				activity.startActivityForResult(getGameHelper()
						.getGamesClient().getAchievementsIntent(),
						REQUEST_ACHIEVEMENTS);
			}
		});
		return true;
	}

	public static void postAchievement(final String idName, int percentComplete) {
		if (!isSignedIn() || percentComplete < 100) {
			return;
		}

		activity.runOnUiThread(new Runnable() {
			public void run() {
				//int rId = getResourceId(idName);
				//if (rId > 0) {
					//String googleId = activity.getResources().getString(rId);
					getGameHelper().getGamesClient().unlockAchievement(idName);
				//}
			}
		});
	}

	public static void clearAllAchievements() {
		Log.v(TAG, "clearAllAchievements is not available on this platform");
	}

	public static boolean showScores() {
		if (!isSignedIn()) {
			return false;
		}

		activity.runOnUiThread(new Runnable() {
			public void run() {
				activity.startActivityForResult(getGameHelper()
						.getGamesClient().getAllLeaderboardsIntent(),
						REQUEST_LEADERBOARD);
			}
		});
		return true;
	}

	public static void postScore(final String idName, final int score) {
		if (!isSignedIn()) {
			return;
		}

		activity.runOnUiThread(new Runnable() {
			public void run() {
				//int rId = getResourceId(idName);
				//if (rId > 0) {
					//String googleId = activity.getResources().getString(rId);
					getGameHelper().getGamesClient().submitScore(idName,
							score);
				//}
			}
		});
	}

	public static void clearAllScores() {
		Log.v(TAG, "clearAllScores is not available on this platform");
	}

	/**
	 * 
	 * Public interface to integrate this into the main activity
	 * 
	 */

	public static void onStart() {
		getGameHelper().onStart(activity);
	}

	public static void onStop() {
		if (Game.mHelper == null) {
			return;
		}

		getGameHelper().onStop();
	}

	public static void onActivityResult(int requestCode, int resultCode,
			Intent data) {
		if (Game.mHelper == null) {
			return;
		}

		getGameHelper().onActivityResult(requestCode, resultCode, data);
	}

	/**
	 * 
	 * Private helper methods
	 * 
	 */

	private static int getResourceId(String idName) {
		int rId = activity.getResources().getIdentifier(idName, "string",
				activity.getPackageName());
		if (rId == 0) {
			Log.v(TAG, "Unable to find resource ID for string " + idName);
		}
		return rId;

	}

	public static GameHelper getGameHelper() {
		if (Game.mHelper == null) {
			Game.mHelper = new GameHelper(activity);
			Game.mHelper.enableDebugLog(true, TAG);

			activity.runOnUiThread(new Runnable() {
				public void run() {
					Game.mHelper.setup(new GameHelper.GameHelperListener() {
						@Override
						public void onSignInFailed() {
							Log.v(TAG, "onSignInFailed");
						}

						@Override
						public void onSignInSucceeded() {
							Log.v(TAG, "onSignInSucceeded");
						}
					}, GameHelper.CLIENT_GAMES);
				}
			});
		}

		return Game.mHelper;
	}

	public static void open(final String target) {
		if (target.endsWith("twitter")) {
			try {
				activity.getPackageManager().getPackageInfo(
						"com.twitter.android", 0);
				activity.startActivity(new Intent(Intent.ACTION_VIEW, Uri
						.parse("twitter://user?user_id=833231137")));
			} catch (Exception e) {
				activity.startActivity(new Intent(Intent.ACTION_VIEW, Uri
						.parse("https://www.twitter.com/tooflya")));
			}
		} else if (target.endsWith("facebook")) {
			try {
				activity.getPackageManager().getPackageInfo(
						"com.facebook.katana", 0);
				activity.startActivity(new Intent(Intent.ACTION_VIEW, Uri
						.parse("fb://profile/tooflya")));
			} catch (Exception e) {
				activity.startActivity(new Intent(Intent.ACTION_VIEW, Uri
						.parse("https://www.facebook.com/tooflya")));
			}
		} else if (target.endsWith("vk")) {
			try {
				activity.getPackageManager().getPackageInfo(
						"com.vkontakte.android", 0);
				activity.startActivity(new Intent(Intent.ACTION_VIEW, Uri
						.parse("vk://profile/tooflya")));
			} catch (Exception e) {
				activity.startActivity(new Intent(Intent.ACTION_VIEW, Uri
						.parse("https://www.vk.com/tooflya")));
			}
		} else if (target.endsWith("more")) {
			try {
				Intent intent = new Intent(Intent.ACTION_VIEW);
				intent.setData(Uri.parse("market://developer?id=Tooflya+Inc."));
				activity.startActivity(intent);
			} catch (Exception e) {
				activity.startActivity(new Intent(
						Intent.ACTION_VIEW,
						Uri.parse("http://play.google.com/store/apps/developer?id=Tooflya+Inc.")));
			}
		}
	}

	public static void showSignIn() {
		if (mSignInButton == null) {
			activity.runOnUiThread(new Runnable() {
				public void run() {
					RelativeLayout.LayoutParams options = new RelativeLayout.LayoutParams(
							RelativeLayout.LayoutParams.WRAP_CONTENT,
							RelativeLayout.LayoutParams.WRAP_CONTENT);

					options.addRule(RelativeLayout.CENTER_HORIZONTAL);
					options.addRule(RelativeLayout.CENTER_VERTICAL);

					mSignInButton = new SignInButton(activity);
					mSignInButton.setPadding(0, 430, 0, 0);
					mSignInButton.setOnClickListener(getGameHelper());
					Game.mContentView.addView(mSignInButton, options);
				}
			});
		} else {
			activity.runOnUiThread(new Runnable() {
				public void run() {
					mSignInButton.setVisibility(View.VISIBLE);
				}
			});
		}

	}

	public static void hideSignIn() {
		if (mSignInButton != null) {
			activity.runOnUiThread(new Runnable() {
				public void run() {
					mSignInButton.setVisibility(View.GONE);
				}
			});
		}
	}

	public static void setSignInScale(final int scale) {
		activity.runOnUiThread(new Runnable() {
			public void run() {
				mSignInButton.setScaleX(scale);
				mSignInButton.setScaleY(scale);
			}
		});
	}

	public static void intro() {
		activity.runOnUiThread(new Runnable() {
			public void run() {
				Game.mSurfaceView.setVisibility(View.GONE);
				final VideoView videoView = new VideoView(activity);
				videoView.setLayoutParams(new LayoutParams(LayoutParams.WRAP_CONTENT, LayoutParams.WRAP_CONTENT));
				videoView.setVideoURI(Uri.parse("android.resource://" + activity.getPackageName() + "/" + R.raw.intro));

				Game.mContentView.addView(videoView);

				DisplayMetrics metrics = new DisplayMetrics();
				activity.getWindowManager().getDefaultDisplay().getMetrics(metrics);
				android.widget.RelativeLayout.LayoutParams params = (android.widget.RelativeLayout.LayoutParams) videoView.getLayoutParams();
				params.width = metrics.widthPixels;
				params.height = metrics.heightPixels;
				params.leftMargin = 0;
				videoView.setLayoutParams(params);

				videoView.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
							@Override
							public void onCompletion(MediaPlayer mp) {
								Game.mSurfaceView.setVisibility(View.VISIBLE);
								Game.mContentView.removeView(videoView);

								nativeOnVideoPlayback();
							}
						});
			
				videoView.setOnTouchListener(new OnTouchListener() {
					@Override
					public boolean onTouch(View v, MotionEvent event) {
						Game.mSurfaceView.setVisibility(View.VISIBLE);
						Game.mContentView.removeView(videoView);

						nativeOnVideoPlayback();
						
						return true;
					}
					
				});
				
				videoView.setOnKeyListener(new OnKeyListener() {
					@Override
					public boolean onKey(View arg0, int arg1, KeyEvent arg2) {
						return true;
					}
				});

				videoView.setMediaController(null);
				videoView.requestFocus();
				videoView.start();
			}
		});
	}
	
	public static native void nativeOnVideoPlayback();
}