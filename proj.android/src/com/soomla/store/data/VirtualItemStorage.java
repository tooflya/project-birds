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

import com.soomla.billing.util.AESObfuscator;
import com.soomla.store.StoreUtils;
import com.soomla.store.domain.VirtualItem;

/**
 * This class is an abstract definition of a Virtual Item Storage.
 */
public abstract class VirtualItemStorage {

    /**
     * Fetch the balance of the given virtual item.
     * @param item is the required virtual item.
     * @return the balance of the required virtual item.
     */
    public int getBalance(VirtualItem item){
        StoreUtils.LogDebug(mTag, "trying to fetch balance for virtual item with itemId: " + item.getItemId());

        String itemId = item.getItemId();
        String key = keyBalance(itemId);
        key = StorageManager.getAESObfuscator().obfuscateString(key);
        String val = StorageManager.getDatabase().getKeyVal(key);

        int balance = 0;
        if (val != null) {
            try {
                balance = StorageManager.getAESObfuscator().unobfuscateToInt(val);
            } catch (AESObfuscator.ValidationException e) {
                StoreUtils.LogError(mTag, e.getMessage());
            }
        }

        StoreUtils.LogDebug(mTag, "the balance for " + item.getItemId() + " is " + balance);

        return balance;
    }

    /**
     * Set the balance of the given virtual item.
     * @param item is the required virtual item.
     * @return the balance of the required virtual item.
     */
    public int setBalance(VirtualItem item, int balance) {
        return setBalance(item, balance, true);
    }
    public int setBalance(VirtualItem item, int balance, boolean notify) {
        StoreUtils.LogDebug(mTag, "setting balance " + balance + " to " + item.getName() + ".");

        int oldBalance = getBalance(item);
        if (oldBalance == balance) {
            return balance;
        }

        String itemId = item.getItemId();

        String balanceStr = "" + balance;
        String key = keyBalance(itemId);
        balanceStr = StorageManager.getAESObfuscator().obfuscateString(balanceStr);
        key      = StorageManager.getAESObfuscator().obfuscateString(key);
        StorageManager.getDatabase().setKeyVal(key, balanceStr);

        if (notify) {
            postBalanceChangeEvent(item, balance, 0);
        }

        return balance;
    }

    /**
     * Adds the given amount of items to the storage.
     * @param item is the required virtual item.
     * @param amount is the amount of items to add.
     */
    public int add(VirtualItem item, int amount){
        return add(item, amount, true);
    }
    public int add(VirtualItem item, int amount, boolean notify){
        StoreUtils.LogDebug(mTag, "adding " + amount + " " + item.getName());

        String itemId = item.getItemId();
        int balance = getBalance(item);
        if (balance < 0) { /* in case the user "adds" a negative value */
            balance = 0;
            amount = 0;
        }
        String balanceStr = "" + (balance + amount);
        String key = keyBalance(itemId);
        balanceStr = StorageManager.getAESObfuscator().obfuscateString(balanceStr);
        key      = StorageManager.getAESObfuscator().obfuscateString(key);
        StorageManager.getDatabase().setKeyVal(key, balanceStr);

        if (notify) {
            postBalanceChangeEvent(item, balance+amount, amount);
        }

        return balance + amount;
    }

    /**
     * Removes the given amount from the given virtual item's balance.
     * @param item is the virtual item to remove the given amount from.
     * @param amount is the amount to remove.
     */
    public int remove(VirtualItem item, int amount){
        return remove(item, amount, true);
    }
    public int remove(VirtualItem item, int amount, boolean notify){
        StoreUtils.LogDebug(mTag, "removing " + amount + " " + item.getName() + ".");

        String itemId = item.getItemId();
        int balance = getBalance(item) - amount;
        if (balance < 0) {
            balance = 0;
            amount = 0;
        }
        String balanceStr = "" + balance;
        String key = keyBalance(itemId);
        balanceStr = StorageManager.getAESObfuscator().obfuscateString(balanceStr);
        key      = StorageManager.getAESObfuscator().obfuscateString(key);
        StorageManager.getDatabase().setKeyVal(key, balanceStr);

        if (notify) {
            postBalanceChangeEvent(item, balance, -1*amount);
        }

        return balance;
    }

    protected abstract String keyBalance(String itemId);
    protected abstract void postBalanceChangeEvent(VirtualItem item, int balance, int amountAdded);

    protected String mTag = "SOOMLA VirtualItemStorage";
}
