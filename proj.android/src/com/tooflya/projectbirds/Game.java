package com.tooflya.projectbirds;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.os.Bundle;
import android.view.WindowManager;

import com.soomla.cocos2dx.store.StoreControllerBridge;
import com.soomla.store.SoomlaApp;

public class Game extends Cocos2dxActivity {

	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		this.getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
	}

	public Cocos2dxGLSurfaceView onCreateView() {
		Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);

		glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);

		StoreControllerBridge.setActivity(this);
		StoreControllerBridge.setGLView(glSurfaceView);
		
		SoomlaApp.setExternalContext(this.getApplicationContext());

		return glSurfaceView;
	}

	private native void showAds();
	private native void hideAds();

	static {
		System.loadLibrary("game");
	}
}
