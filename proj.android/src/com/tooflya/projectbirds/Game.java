package com.tooflya.projectbirds;

import java.util.Timer;
import java.util.TimerTask;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;
import org.cocos2dx.lib.Cocos2dxRenderer;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnSystemUiVisibilityChangeListener;
import android.view.WindowManager;
import android.widget.RelativeLayout;

import com.soomla.cocos2dx.store.StoreControllerBridge;
import com.soomla.store.SoomlaApp;
import com.tooflya.projectbirds.GameCenter.GameCenter;
import com.tooflya.projectbirds.GameCenter.GameHelper;
import com.tooflya.projectbirds.notify.NotifyService;

@SuppressLint("NewApi")
public class Game extends Cocos2dxActivity implements
		OnSystemUiVisibilityChangeListener {

	static {
		System.loadLibrary("game");
	}

	public static GameHelper mHelper;
	public static RelativeLayout mContentView;

	public static Cocos2dxGLSurfaceView mSurfaceView;

	public Game() {
		super();
	}

	@Override
	protected void onCreate(Bundle b) {
		super.onCreate(b);

		this.getWindow().addFlags(
				WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

		if (Build.VERSION.SDK_INT >= 11) {
			try {
				getWindow().getDecorView().setSystemUiVisibility(
						View.SYSTEM_UI_FLAG_LOW_PROFILE);
			} catch (Exception ex) {
			}
		}

		this.getWindow().getDecorView()
				.setOnSystemUiVisibilityChangeListener(this);

		startService(new Intent(Game.this, NotifyService.class));

		NotifyService.setLastGameEnter();
	}

	@Override
	protected void onStart() {
		super.onStart();

		GameCenter.onStart();
	}

	@Override
	protected void onStop() {
		super.onStop();

		GameCenter.onStop();
	}

	@Override
	protected void onActivityResult(int request, int response, Intent data) {
		super.onActivityResult(request, response, data);

		GameCenter.onActivityResult(request, response, data);
	}

	@Override
	public void init() {
		this.mGLSurfaceView = this.onCreateView();

		mContentView = new RelativeLayout(this);
		mSurfaceView = this.mGLSurfaceView;

		mContentView.addView(this.mGLSurfaceView);

		this.mGLSurfaceView.setCocos2dxRenderer(new Cocos2dxRenderer());

		setContentView(mContentView);

		GameCenter.activity = this;
	}

	@Override
	public Cocos2dxGLSurfaceView onCreateView() {
		super.onCreateView();

		Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);

		glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);

		StoreControllerBridge.setActivity(this);
		StoreControllerBridge.setGLView(glSurfaceView);

		SoomlaApp.setExternalContext(this.getApplicationContext());

		return glSurfaceView;
	}

	@Override
	public void onSystemUiVisibilityChange(int arg0) {
		Timer timer = new Timer();
		timer.schedule(new TimerTask() {
			@Override
			public void run() {
				Game.this.runOnUiThread(new Runnable() {
					@Override
					public void run() {
						Game.this
								.getWindow()
								.getDecorView()
								.setSystemUiVisibility(
										View.SYSTEM_UI_FLAG_LOW_PROFILE);
					}
				});
			}
		}, 1000);
	}
}
