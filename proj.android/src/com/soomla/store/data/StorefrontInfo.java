/*
 * Copyright (C) 2012 Soomla Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.soomla.store.data;

import android.text.TextUtils;
import com.soomla.billing.util.AESObfuscator;
import com.soomla.store.SoomlaApp;
import com.soomla.store.StoreUtils;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * This class is used to retrieve the storefront JSON when it's needed.
 *
 * This class is relevant only to users who created a storefront using the SOOMLA designer.
 */
public class StorefrontInfo {

    public static StorefrontInfo getInstance(){
        if (sInstance == null){
            sInstance = new StorefrontInfo();
        }

        return sInstance;
    }

    /**
     * This function initializes StorefrontInfo. On first initialization, when the
     * database doesn't have any previous version of the store metadata (JSON), StorefrontInfo
     * saves the JSON from 'theme.json' to the DB. After the first initialization,
     * StorefrontInfo will load the JSON metadata when needed.
     * NOTE: If you want to override the current StorefrontInfo metadata JSON file, you'll have to bump the
     * database version (the old database will be destroyed but balances will be saved!!).
     */
    public void initialize(){
        if (!initializeFromDB()) {
            // if the json doesn't already exist in the database, we load it into the DB here.

            String storefrontJSON = fetchThemeJsonFromFile();
            if (TextUtils.isEmpty(storefrontJSON)){
                StoreUtils.LogError(TAG, "Couldn't find storefront in the DB AND the filesystem. Something is totally wrong !");
                return;
            }

            mStorefrontJSON = storefrontJSON;
            String key = KeyValDatabase.keyMetaStorefrontInfo();
            storefrontJSON = StorageManager.getAESObfuscator().obfuscateString(storefrontJSON);
            key = StorageManager.getAESObfuscator().obfuscateString(key);
            StorageManager.getDatabase().setKeyVal(key, storefrontJSON);

			try {
				JSONObject temp = new JSONObject(this.mStorefrontJSON);
				this.mOrientationLandscape = ((JSONObject)temp.get("template")).getString("orientation").equals("landscape");
			} catch (JSONException e) {
				StoreUtils.LogError(TAG, "There was a problem parsing the given storefront JSON.");
				return;
			}
			
            mInitialized = true;
        }
    }

    /**
     * Initializes StorefrontInfo from the database.
     * @return true on success and false on failure (probably when the database doesn't contain the JSON).
     */
    public boolean initializeFromDB() {

        String key = KeyValDatabase.keyMetaStorefrontInfo();
        key = StorageManager.getAESObfuscator().obfuscateString(key);

        String val = StorageManager.getDatabase().getKeyVal(key);

        if (val == null && TextUtils.isEmpty(val)){
            StoreUtils.LogDebug(TAG, "storefront json is not in DB yet ");
            return false;
        }

        try {
            mStorefrontJSON = StorageManager.getAESObfuscator().unobfuscateToString(val);
        } catch (AESObfuscator.ValidationException e) {
            StoreUtils.LogError(TAG, e.getMessage());
            return false;
        }

		try {
			JSONObject temp = new JSONObject(this.mStorefrontJSON);
			this.mOrientationLandscape = ((JSONObject)temp.get("template")).getString("orientation").equals("landscape");
		} catch (JSONException e) {
			StoreUtils.LogError(TAG, "There was a problem parsing the given storefront JSON.");
			return true;
		}

        StoreUtils.LogDebug(TAG, "the metadata-design json (from DB) is " + mStorefrontJSON);

        mInitialized = true;
        return true;

    }

    /**
     * Read 'theme.json' and return it.
     * @return theme.json's content as String.
     */
    public String fetchThemeJsonFromFile() {
        String storefrontJSON = "";
        try {
            InputStream in = SoomlaApp.getAppContext().getAssets().open("soomla/theme.json");

            byte[] buffer = new byte[in.available()];
            in.read(buffer);
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            out.write(buffer);
            out.close();
            in.close();

            storefrontJSON = out.toString();
        } catch (IOException e) {
            StoreUtils.LogError(TAG, "Can't read JSON storefront file. Please add theme.json to your 'assets' folder.");
        }

        return storefrontJSON;
    }

    /**
     * Singleton getter!
     */
    public String getStorefrontJSON() {
        if (!mInitialized) {
            if (!initializeFromDB()) {
                StoreUtils.LogError(TAG, "Couldn't initialize StoreFrontInfo. Can't fetch the JSON!");
                return "";
            }
        }
        return mStorefrontJSON;
    }

    public boolean isOrientationLandscape() {
        return mOrientationLandscape;
    }

    public void setOrientationLandscape(boolean orientationLandscape) {
        this.mOrientationLandscape = orientationLandscape;
    }

    /** Private functions **/

    private StorefrontInfo() { }

    /** Private members **/

    private static final String TAG             = "SOOMLA StorefrontInfo";
    private static StorefrontInfo sInstance     = null;
    private static boolean mInitialized         = false;
    private boolean mOrientationLandscape       = false;

    private String  mStorefrontJSON;
}
