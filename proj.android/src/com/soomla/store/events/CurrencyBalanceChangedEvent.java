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
package com.soomla.store.events;

import com.soomla.store.domain.virtualCurrencies.VirtualCurrency;

/**
 * This event is fired when the balance of a specific VirtualCurrency has changed.
 */
public class CurrencyBalanceChangedEvent {

    private VirtualCurrency mCurrency;
    private int mBalance;
    private int mAmountAdded;

    public CurrencyBalanceChangedEvent(VirtualCurrency currency, int balance, int amountAdded) {
        mCurrency = currency;
        mBalance = balance;
        mAmountAdded = amountAdded;
    }

    public VirtualCurrency getCurrency() {
        return mCurrency;
    }

    public int getBalance() {
        return mBalance;
    }

    public int getAmountAdded() {
        return mAmountAdded;
    }
}
