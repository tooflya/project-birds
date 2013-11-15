/*
 * Copyright (C) 2010 The Android Open Source Project
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

package com.soomla.billing.util;

import android.content.Context;
import android.content.SharedPreferences;
import android.text.TextUtils;
import com.soomla.store.SoomlaApp;
import com.soomla.store.StoreConfig;
import com.soomla.store.StoreUtils;
import com.soomla.store.data.ObscuredSharedPreferences;

import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.PBEKeySpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.UnsupportedEncodingException;
import java.security.GeneralSecurityException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.security.spec.KeySpec;

/**
 * An Obfuscator that uses AES to encrypt data.
 */
public class AESObfuscator {
    private static final String UTF8 = "UTF-8";
    private static final String KEYGEN_ALGORITHM = "PBEWITHSHAAND256BITAES-CBC-BC";
    private static final String CIPHER_ALGORITHM = "AES/CBC/PKCS5Padding";
    private static final byte[] IV =
            { 16, 74, 71, -80, 32, 101, -47, 72, 117, -14, 0, -29, 70, 65, -12, 74 };
    private static final String header = "com.soomla.billing.util.AESObfuscator-1|";

    private Cipher mEncryptor;
    private Cipher mDecryptor;

    /**
     * @param salt an array of random bytes to use for each (un)obfuscation
     * @param applicationId application identifier, e.g. the package name
     * @param deviceId device identifier. Use as many sources as possible to
     *    create this unique identifier.
     */
    public AESObfuscator(byte[] salt, String applicationId, String deviceId) {
        SharedPreferences prefs = new ObscuredSharedPreferences(SoomlaApp.getAppContext().getSharedPreferences(StoreConfig.PREFS_NAME, Context.MODE_PRIVATE));
        byte[] passwordData = null;
        try {
            SecretKeyFactory factory = SecretKeyFactory.getInstance(KEYGEN_ALGORITHM);
            KeySpec keySpec =
                    new PBEKeySpec((applicationId + deviceId + prefs.getString(StoreConfig.CUSTOM_SEC, "SOOMLA_SEC")).toCharArray(), salt, 1024, 256);
            passwordData = factory.generateSecret(keySpec).getEncoded();
        } catch (GeneralSecurityException e) {
            StoreUtils.LogDebug("SOOMLA AESObfuscator", "probably an incompatible device. trying different approach.");

            MessageDigest digester = null;
            try {
                digester = MessageDigest.getInstance("MD5");

                char[] password = (applicationId + deviceId + prefs.getString(StoreConfig.CUSTOM_SEC, "SOOMLA_SEC")).toCharArray();
                for (int i = 0; i < password.length; i++) {
                    digester.update((byte) password[i]);
                }
                passwordData = digester.digest();
            } catch (NoSuchAlgorithmException e1) {
                // This can't happen on a compatible Android device.
                throw new RuntimeException("Invalid environment", e1);
            }
        }

        SecretKey secret = new SecretKeySpec(passwordData, "AES");
        try {
            mEncryptor = Cipher.getInstance(CIPHER_ALGORITHM);
            mEncryptor.init(Cipher.ENCRYPT_MODE, secret, new IvParameterSpec(IV));
            mDecryptor = Cipher.getInstance(CIPHER_ALGORITHM);
            mDecryptor.init(Cipher.DECRYPT_MODE, secret, new IvParameterSpec(IV));
        } catch (GeneralSecurityException e) {
            // This can't happen on a compatible Android device.
            throw new RuntimeException("Invalid environment 2", e);
        }
    }

    public String obfuscateInt(int original) {
        return obfuscateString("" + original);
    }

    public synchronized String obfuscateString(String original) {
        if (original == null) {
            return null;
        }
        try {
            // Header is appended as an integrity check
            return Base64.encode(mEncryptor.doFinal((header + original).getBytes(UTF8)));
        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException("Invalid environment", e);
        } catch (GeneralSecurityException e) {
            throw new RuntimeException("Invalid environment", e);
        }
    }

    public int unobfuscateToInt(String obfuscated) throws ValidationException {
        return Integer.parseInt(unobfuscateToString(obfuscated));
    }

    public synchronized String unobfuscateToString(String obfuscated) throws ValidationException {
        if (TextUtils.isEmpty(obfuscated)) {
            return null;
        }
        try {
            String result = new String(mDecryptor.doFinal(Base64.decode(obfuscated)), UTF8);
            // Check for presence of header. This serves as a final integrity check, for cases
            // where the block size is correct during decryption.
            int headerIndex = result.indexOf(header);
            if (headerIndex != 0) {
                throw new ValidationException("Header not found (invalid data or key)" + ":" +
                        obfuscated);
            }
            return result.substring(header.length(), result.length());
        } catch (Base64DecoderException e) {
            throw new ValidationException(e.getMessage() + ":" + obfuscated);
        } catch (IllegalBlockSizeException e) {
            throw new ValidationException(e.getMessage() + ":" + obfuscated);
        } catch (BadPaddingException e) {
            throw new ValidationException(e.getMessage() + ":" + obfuscated);
        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException("Invalid environment", e);
        }
    }

    /**
     * Indicates that an error occurred while validating the integrity of data managed by an
     * {@link AESObfuscator}.}
     */
    public class ValidationException extends Exception {
        public ValidationException() {
            super();
        }

        public ValidationException(String s) {
            super(s);
        }

        private static final long serialVersionUID = 1L;
    }
}