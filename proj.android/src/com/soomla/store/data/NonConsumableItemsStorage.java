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

import com.soomla.store.StoreUtils;
import com.soomla.store.domain.NonConsumableItem;

/**
 * This class provide basic storage operations on Google Play's MANAGED items.
 */
public class NonConsumableItemsStorage {

    /** Constructor
     *
     */
    public NonConsumableItemsStorage() {
    }

    /** Public functions **/

    /**
     * Figure out if the given non-consumable {@link NonConsumableItem} exists.
     * @param nonConsumableItem is the required non-consumable {@link NonConsumableItem}.
     * @return whether the given item exists or not.
     */
    public boolean nonConsumableItemExists(NonConsumableItem nonConsumableItem){

        StoreUtils.LogDebug(TAG, "trying to figure out if the given MANAGED item exists.");

        String itemId = nonConsumableItem.getItemId();
        String key = KeyValDatabase.keyNonConsExists(itemId);
        key = StorageManager.getAESObfuscator().obfuscateString(key);

        String val = StorageManager.getDatabase().getKeyVal(key);

        return val != null;
    }

    /**
     * Adds the given google non-consumable item to the storage.
     * @param nonConsumableItem is the required google non-consumable item.
     * @return true
     */
    public boolean add(NonConsumableItem nonConsumableItem){
        StoreUtils.LogDebug(TAG, "adding " + nonConsumableItem.getItemId());

        String itemId = nonConsumableItem.getItemId();
        String key = KeyValDatabase.keyNonConsExists(itemId);
        key = StorageManager.getAESObfuscator().obfuscateString(key);
        StorageManager.getDatabase().setKeyVal(key, "");

        return true;
    }

    /**
     * Removes the given google non-consumable item from the storage.
     * @param nonConsumableItem is the required google non-consumable item.
     * @return false
     */
    public boolean remove(NonConsumableItem nonConsumableItem){
        StoreUtils.LogDebug(TAG, "removing " + nonConsumableItem.getName());

        String itemId = nonConsumableItem.getItemId();
        String key = KeyValDatabase.keyNonConsExists(itemId);
        key = StorageManager.getAESObfuscator().obfuscateString(key);
        StorageManager.getDatabase().deleteKeyVal(key);

        return false;
    }

    /** Private members **/

    private static final String TAG = "SOOMLA NonConsumableItemsStorage";
}
