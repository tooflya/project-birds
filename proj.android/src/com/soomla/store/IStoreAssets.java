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
package com.soomla.store;

import com.soomla.store.domain.NonConsumableItem;
import com.soomla.store.domain.VirtualCategory;
import com.soomla.store.domain.virtualCurrencies.VirtualCurrency;
import com.soomla.store.domain.virtualCurrencies.VirtualCurrencyPack;
import com.soomla.store.domain.virtualGoods.VirtualGood;

/**
 * This interface represents a single game's metadata.
 * Use this interface to create your assets class that will be transferred to StoreInfo
 * upon initialization.
 */
public interface IStoreAssets {
    /**
     * This value will determine if the saved data in the database will be deleted or not.
     * Bump the version every time you want to delete the old data in the DB.
     * If you don't bump this value, you won't be able to see changes you've made to the objects in this file.
     *
     * NOTE: You can NOT bump this value and just delete the app from your device to see changes. You can't do this after
     * you publish your application on the market.
     *
     * For example: If you previously created a VirtualGood with name "Hat" and you published your application,
     * the name "Hat will be saved in any of your users' databases. If you want to change the name to "Green Hat"
     * than you'll also have to bump the version (from 0 to 1). Now the new "Green Hat" name will replace the old one.
     * @return the version of your specific IStoreAssets.
     */
    int getVersion();

    /**
     * Your game's virtual currencies.
     */
    VirtualCurrency[] getCurrencies();

    /**
     * An array of all virtual goods served by your store (all kinds in one array). If you have UpgradeVGs, they must appear in the order of levels.
     */
    VirtualGood[] getGoods();

    /**
     * An array of all virtual currency packs served by your store.
     */
    VirtualCurrencyPack[] getCurrencyPacks();

    /**
     * An array of all virtual categories handled in your store.
     */
    VirtualCategory[] getCategories();

    /**
     * You can define non consumable items that you'd like to use for your needs.
     * CONSUMABLE (or UNMANAGED) items are usually just currency packs.
     * NON-CONSUMABLE (or MANAGED) items are usually used to let users purchase a "no-ads" token.
     * Make sure you set the type of the items you add here as Managed.MANAGED.
     * @return an array of all non-consumables served in your game.
     */
    NonConsumableItem[] getNonConsumableItems();
}
