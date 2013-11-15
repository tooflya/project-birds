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
package com.soomla.store.domain;

import com.soomla.store.StoreUtils;
import com.soomla.store.data.JSONConsts;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

/**
 * This class is a definition of a category. A single category can be associated with many virtual goods.
 * The purposes of virtual category are:
 * 1. You can use it to arrange virtual goods to their specific categories.
 * 2. SOOMLA's storefront uses this to show the goods in their categories on the UI (for supported themes only).
 */
public class VirtualCategory {

    /** Constructor
     *
     * @param name is the category's name.
     * @param goodsItemIds is the list of itemIds of the VirtualGoods in this category.
     */
    public VirtualCategory(String name, ArrayList<String> goodsItemIds) {
        mName = name;
        mGoodsItemIds = goodsItemIds;
    }

    /** Constructor
     *
     * Generates an instance of {@link VirtualCategory} from a JSONObject.
     * @param jsonObject is a JSONObject representation of the wanted {@link VirtualCategory}.
     * @throws JSONException
     */
    public VirtualCategory(JSONObject jsonObject) throws JSONException{
        mName = jsonObject.getString(JSONConsts.CATEGORY_NAME);

        JSONArray goodsArr = jsonObject.getJSONArray(JSONConsts.CATEGORY_GOODSITEMIDS);
        for(int i=0; i<goodsArr.length(); i++) {
            String goodItemId = goodsArr.getString(i);
            mGoodsItemIds.add(goodItemId);
        }
    }

    /**
     * Converts the current {@link VirtualCategory} to a JSONObject.
     * @return a JSONObject representation of the current {@link VirtualCategory}.
     */
    public JSONObject toJSONObject(){
        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(JSONConsts.CATEGORY_NAME, mName);

            JSONArray goodsArr = new JSONArray();
            for(String goodItemId : mGoodsItemIds) {
                goodsArr.put(goodItemId);
            }

            jsonObject.put(JSONConsts.CATEGORY_GOODSITEMIDS, goodsArr);
        } catch (JSONException e) {
            StoreUtils.LogError(TAG, "An error occurred while generating JSON object.");
        }

        return jsonObject;
    }

    /** Getters **/

    public String getName() {
        return mName;
    }

    public ArrayList<String> getGoodsItemIds() {
        return mGoodsItemIds;
    }

    /** Private members **/

    private static final String TAG = "SOOMLA VirtualCategory";

    private ArrayList<String> mGoodsItemIds = new ArrayList<String>();
    private String  mName;
}
