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
import com.soomla.store.StoreUtils;

import java.util.ArrayList;

/**
 * This class provides basic storage operations for a simple key-value store.
 */
public class KeyValueStorage {

    /** Constructor
     *
     */
    public KeyValueStorage() {
    }

    /**
     * Fetch the value for the given key.
     * @param key is the key in the key-val pair.
     * @return the value for the given key.
     */
    public String getValue(String key) {
        StoreUtils.LogDebug(TAG, "trying to fetch a value for key: " + key);

        key = StorageManager.getAESObfuscator().obfuscateString(key);

        String val = StorageManager.getDatabase().getKeyVal(key);

        if (val != null && !TextUtils.isEmpty(val)) {
            try {
                val = StorageManager.getAESObfuscator().unobfuscateToString(val);
            } catch (AESObfuscator.ValidationException e) {
                StoreUtils.LogError(TAG, e.getMessage());
                val = "";
            }

            StoreUtils.LogDebug(TAG, "the fetched value is " + val);
        }
        return val;
    }


    public void setNonEncryptedKeyValue(String key, String val) {
        StoreUtils.LogDebug(TAG, "setting " + val + " for key: " + key);

        val = StorageManager.getAESObfuscator().obfuscateString(val);

        StorageManager.getDatabase().setKeyVal(key, val);
    }


    public void deleteNonEncryptedKeyValue(String key) {
        StoreUtils.LogDebug(TAG, "deleting " + key);

        StorageManager.getDatabase().deleteKeyVal(key);
    }

    public String getNonEncryptedKeyValue(String key) {
        StoreUtils.LogDebug(TAG, "trying to fetch a value for key: " + key);

        String val = StorageManager.getDatabase().getKeyVal(key);

        if (val != null && !TextUtils.isEmpty(val)) {
            try {
                val = StorageManager.getAESObfuscator().unobfuscateToString(val);
            } catch (AESObfuscator.ValidationException e) {
                StoreUtils.LogError(TAG, e.getMessage());
                val = "";
            }

            StoreUtils.LogDebug(TAG, "the fetched value is " + val);
        }
        return val;
    }

    public ArrayList<String> getNonEncryptedQueryValues(String query) {
        StoreUtils.LogDebug(TAG, "trying to fetch a values for query: " + query);

        ArrayList<String> vals = StorageManager.getDatabase().getQueryVals(query);
        ArrayList<String> results = new ArrayList<String>();
        for(String val : vals) {
            if (val != null && !TextUtils.isEmpty(val)) {
                try {
                    val = StorageManager.getAESObfuscator().unobfuscateToString(val);
                    results.add(val);
                } catch (AESObfuscator.ValidationException e) {
                    StoreUtils.LogError(TAG, e.getMessage());
                }
            }
        }

        StoreUtils.LogDebug(TAG, "fetched " + results.size() + " results");

        return results;
    }

    /**
     * Sets the given value to the given key.
     * @param key is the key in the key-val pair.
     * @param val is the val in the key-val pair.
     */
    public void setValue(String key, String val) {
        StoreUtils.LogDebug(TAG, "setting " + val + " for key: " + key);

        key = StorageManager.getAESObfuscator().obfuscateString(key);
        val = StorageManager.getAESObfuscator().obfuscateString(val);

        StorageManager.getDatabase().setKeyVal(key, val);
    }

    /**
     * Deletes a key-val pair with the given key.
     * @param key is the key in the key-val pair.
     */
    public void deleteKeyValue(String key) {
        StoreUtils.LogDebug(TAG, "deleting " + key);

        key = StorageManager.getAESObfuscator().obfuscateString(key);

        StorageManager.getDatabase().deleteKeyVal(key);
    }


    /** Private Members **/

    private static final String TAG = "SOOMLA KeyValueStorage";
}
