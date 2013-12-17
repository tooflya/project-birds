package com.tooflya.projectbirds.notify;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

public class NotifyReceiver extends BroadcastReceiver {

	@Override
	public void onReceive(Context context, Intent intent) {
		Intent myIntent = new Intent(context, NotifyService.class);
		context.startService(myIntent);
	}
}