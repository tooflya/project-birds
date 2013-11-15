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

import android.content.Context;
import android.content.SharedPreferences;
import com.soomla.billing.util.AESObfuscator;
import com.soomla.store.SoomlaApp;
import com.soomla.store.StoreConfig;
import com.soomla.store.StoreUtils;
import com.soomla.store.domain.VirtualItem;
import com.soomla.store.domain.virtualCurrencies.VirtualCurrency;
import com.soomla.store.domain.virtualGoods.VirtualGood;

/**
 * This is the place where all the relevant storage classes are created.
 * This class contains static methods for you to retrieve the various storages.
 *
 * s
 *
 */
public class StorageManager {

    /** Getters **/

    public static VirtualCurrencyStorage getVirtualCurrencyStorage(){
        return mVirtualCurrencyStorage;
    }

    public static VirtualGoodsStorage getVirtualGoodsStorage(){
        return mVirtualGoodsStorage;
    }

    public static AESObfuscator getAESObfuscator(){
        if (mObfuscator == null) {
            mObfuscator = new AESObfuscator(StoreConfig.obfuscationSalt, SoomlaApp.getAppContext().getPackageName(), StoreUtils.deviceId());
        }

        return mObfuscator;
    }

    public synchronized static KeyValDatabase getDatabase(){

        if (mKvDatabase == null) {
            mKvDatabase = new KeyValDatabase(SoomlaApp.getAppContext());

            SharedPreferences prefs = new ObscuredSharedPreferences(
                    SoomlaApp.getAppContext().getSharedPreferences(StoreConfig.PREFS_NAME, Context.MODE_PRIVATE));
            int mt_ver = prefs.getInt("MT_VER", 0);
            int sa_ver_old = prefs.getInt("SA_VER_OLD", -1);
            int sa_ver_new = prefs.getInt("SA_VER_NEW", 0);
            if (mt_ver < StoreConfig.METADATA_VERSION || sa_ver_old < sa_ver_new) {
                SharedPreferences.Editor edit = prefs.edit();
                edit.putInt("MT_VER", StoreConfig.METADATA_VERSION);
                edit.putInt("SA_VER_OLD", sa_ver_new);
                edit.commit();

                String keyStoreFront = mObfuscator.obfuscateString(KeyValDatabase.keyMetaStorefrontInfo());
                String keyStoreInfo = mObfuscator.obfuscateString(KeyValDatabase.keyMetaStoreInfo());
                mKvDatabase.deleteKeyVal(keyStoreFront);
                mKvDatabase.deleteKeyVal(keyStoreInfo);
            }
        }

        return mKvDatabase;
    }

    public static NonConsumableItemsStorage getNonConsumableItemsStorage() {
        return mNonConsumableItemsStorage;
    }

    public static KeyValueStorage getKeyValueStorage() {
        return mKeyValueStorage;
    }

    public static VirtualItemStorage getVirtualItemStorage(VirtualItem item) {
        VirtualItemStorage storage = null;


        if (item instanceof VirtualGood) {
            storage = getVirtualGoodsStorage();
        } else if (item instanceof VirtualCurrency) {
            storage = getVirtualCurrencyStorage();
        }
        return storage;
    }


    /** Private members **/
    private static final String TAG = "SOOMLA StorageManager";

    private static boolean mOldDataMigrated = false;

    private static VirtualGoodsStorage     mVirtualGoodsStorage         = new VirtualGoodsStorage();
    private static VirtualCurrencyStorage  mVirtualCurrencyStorage      = new VirtualCurrencyStorage();
    private static NonConsumableItemsStorage mNonConsumableItemsStorage = new NonConsumableItemsStorage();
    private static KeyValueStorage         mKeyValueStorage             = new KeyValueStorage();
    private static AESObfuscator           mObfuscator;
    private static KeyValDatabase          mKvDatabase;

}
