package com.soomla.store.exceptions;

public class NotEnoughGoodsException extends Exception{
    public NotEnoughGoodsException(String itemId) {
        super("You tried to equip virtual good with itemId: " + itemId + " but you don't have any of it.");
    }
}
