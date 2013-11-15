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

package com.soomla.store.purchaseTypes;

import com.soomla.store.BusProvider;
import com.soomla.store.StoreUtils;
import com.soomla.store.data.StorageManager;
import com.soomla.store.data.StoreInfo;
import com.soomla.store.data.VirtualItemStorage;
import com.soomla.store.domain.VirtualItem;
import com.soomla.store.events.ItemPurchaseStartedEvent;
import com.soomla.store.events.ItemPurchasedEvent;
import com.soomla.store.exceptions.InsufficientFundsException;
import com.soomla.store.exceptions.VirtualItemNotFoundException;

/**
 * This type of Purchase allows users to purchase PurchasableVirtualItems with other VirtualItems.
 */
public class PurchaseWithVirtualItem extends PurchaseType {

    /** Constructor
     *
     * @param targetItemId is the itemId of the VirtualItem that is used to "pay" in order to make the purchase.
     * @param amount is the number of items to purchase.
     */
    public PurchaseWithVirtualItem(String targetItemId, int amount) {
        mTargetItemId = targetItemId;
        mAmount = amount;
    }

    /**
     * see parent
     */
    @Override
    public void buy() throws InsufficientFundsException{

        StoreUtils.LogDebug(TAG, "Trying to buy a " + getAssociatedItem().getName() + " with " + mAmount + " pieces of " + mTargetItemId);

        VirtualItem item = null;
        try {
            item = StoreInfo.getVirtualItem(mTargetItemId);
        } catch (VirtualItemNotFoundException e) {
            StoreUtils.LogError(TAG, "Target virtual item doesn't exist !");
            return;
        }

        BusProvider.getInstance().post(new ItemPurchaseStartedEvent(getAssociatedItem()));

        VirtualItemStorage storage = StorageManager.getVirtualItemStorage(item);

        assert storage != null;
        int balance = storage.getBalance(item);
        if (balance < mAmount){
            throw new InsufficientFundsException(mTargetItemId);
        }

        storage.remove(item, mAmount);

        getAssociatedItem().give(1);
        BusProvider.getInstance().post(new ItemPurchasedEvent(getAssociatedItem()));
    }

    public String getTargetItemId() {
        return mTargetItemId;
    }

    public int getAmount() {
        return mAmount;
    }

    private static final String TAG = "SOOMLA PurchaseWithVirtualItem";

    private String      mTargetItemId;
    private int         mAmount;
}
