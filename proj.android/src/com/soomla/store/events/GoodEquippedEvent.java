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

import com.soomla.store.domain.virtualGoods.EquippableVG;

/**
 * This event is fired when the balance of a specific EquippableVG has been equipped.
 */
public class GoodEquippedEvent {

    private EquippableVG mGood;

    public GoodEquippedEvent(EquippableVG good) {
        mGood = good;
    }

    public EquippableVG getGood() {
        return mGood;
    }
}
