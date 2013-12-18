package com.tooflya.projectbirds.notify;

import java.util.Timer;
import java.util.TimerTask;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.media.RingtoneManager;
import android.net.Uri;
import android.os.IBinder;
import android.support.v4.app.NotificationCompat;

import com.tooflya.projectbirds.Game;
import com.tooflya.projectbirds.R;
import com.tooflya.projectbirds.utils.Utils;

public class NotifyService extends Service {
	private static int mLastVisitDayCount = 0;
	private static long mLastLiveRestoreTime = 0;
	private static long mLastGameEnter = 0;

	private static boolean mIsFullLivesNotification = true;
	private static boolean mIsDailyRevenueShowed = false;
	private static boolean mIsPlayAgainShowed = true;

	private NotificationManager mNotificationManager;
	private Timer mTimer = new Timer();

	@Override
	public IBinder onBind(Intent intent) {
		return null;
	}

	@Override
	public void onCreate() {
		super.onCreate();

		this.launchCounter();
	}

	@Override
	public void onDestroy() {
		super.onDestroy();

		this.shutdownCounter();
	}

	private void showInviteNotification() {
		//this.showNotification(0, 0);
	}

	private void showRevenueNotification() {
		mIsDailyRevenueShowed = true;
		this.showNotification(R.string.daily_revenue_notification_title,
				R.string.daily_revenue_notification_content);
	}

	private void showGoldLivesNotification() {
		mIsFullLivesNotification = true;
		this.showNotification(R.string.full_lives_notification_title,
				R.string.full_lives_notification_content);
	}

	private void showNotification(int contentTitle, int contentText) {
		Uri sound = RingtoneManager
				.getDefaultUri(RingtoneManager.TYPE_NOTIFICATION);

		Intent notificationIntent = new Intent(this, Game.class);
		PendingIntent pendingIntent = PendingIntent.getActivity(this, 0,
				notificationIntent, 0);

		Notification notification = new NotificationCompat.Builder(this)
				.setContentIntent(pendingIntent).setSmallIcon(R.drawable.icon)
				.setContentTitle(getString(contentTitle))
				.setContentText(getString(contentText))
				.setVibrate(new long[] { 0, 100, 200, 300 }).setSound(sound)
				.setAutoCancel(true).setLights(Color.BLUE, 500, 500).build();

		this.mNotificationManager.notify(0, notification);
	}

	private void launchCounter() {
		this.mNotificationManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);

		this.mTimer.scheduleAtFixedRate(new TimerTask() {
			public void run() {
				// Revenue
				if (NotifyService.this.isDailyRevenueAvailable()) {
					NotifyService.this.showRevenueNotification();
				}

				// Lives

				if (NotifyService.this.isLivesRestored()) {
					NotifyService.this.showGoldLivesNotification();
				}

				// Play

				if (Utils.getHourOfDay() > 11 && System.currentTimeMillis() - mLastGameEnter > 0.2 * 60 * 60 * 1000) {//24 * 60 * 60 * 1000) {
					NotifyService.this.showInviteNotification();
				}
			}
		}, 0, 10000);
	}

	private void shutdownCounter() {
		if (this.mTimer != null) {
			this.mTimer.cancel();
		}
	}

	private boolean isDailyRevenueAvailable() {
		if (Utils.getHourOfDay() < 11) {
			return false;
		}

		return !mIsDailyRevenueShowed
				&& mLastVisitDayCount - Utils.getDayOfMonth() > 0;
	}

	private boolean isLivesRestored() {
		if (Utils.getHourOfDay() < 11) {
			return false;
		}

		return !mIsFullLivesNotification
				&& System.currentTimeMillis() >= mLastLiveRestoreTime;
	}

	public static void setLastVisitDaysCount(String a, int daysCount) {
		mIsDailyRevenueShowed = false;
		mLastVisitDayCount = daysCount;
	}

	public static void setLivesMustRestore() {
		mIsFullLivesNotification = false;
		mLastLiveRestoreTime = System.currentTimeMillis() + 30 * 1000 * 60;
	}

	public static void setLastGameEnter() {
		mIsPlayAgainShowed = false;
		mLastGameEnter = System.currentTimeMillis();
	}
}
