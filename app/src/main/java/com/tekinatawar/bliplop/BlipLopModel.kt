package com.tekinatawar.bliplop

import android.util.Log

class BlipLopModel {
    val TAG = "BlipLopModel"
    var isPlaying = false;

    // let's assume that that the whole business logic of our bliplop app is to set isPlaying value rightly and logging it.
    fun play() {
        isPlaying = true;
        Log.d(TAG, "playing...")
    }

    fun stop() {
        isPlaying = false;
        Log.d(TAG, "stopped.")
    }
}