package com.tekinatawar.bliplop

import androidx.lifecycle.ViewModel

class BlipLopViewModel : ViewModel() {
    private val model = BlipLopModel()

    fun playBackClicked() {
        if (model.isPlaying) {
            model.stop()
        } else {
            model.play()
        }
    }
}