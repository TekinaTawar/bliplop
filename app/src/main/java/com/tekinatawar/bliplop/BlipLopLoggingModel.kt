package com.tekinatawar.bliplop

import android.util.Log

class BlipLopLoggingModel : BlipLopModel {
    val TAG = "BlipLopModel"
    var isPlaying = false;

    // let's assume that that the whole business logic of our bliplop app is to set isPlaying value rightly and logging it.
    override suspend fun play() {
        Log.d(TAG, "playing., is Playing was: ${isPlaying}")
        isPlaying = true;
    }

    override suspend fun stop() {
        isPlaying = false;
        Log.d(TAG, "stopped. is playing was: ${isPlaying}")
    }

    override suspend fun isPlaying(): Boolean {
        Log.d(TAG, "isPlaying() called")
        return isPlaying;
    }
}