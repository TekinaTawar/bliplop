package com.tekinatawar.bliplop

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import kotlinx.coroutines.launch

class BlipLopViewModel : ViewModel() {
    private val model = BlipLopNativeModel()

    private val _playBackButtonLabel = MutableLiveData("Start Playback")
    val playBackButtonLabel: LiveData<String>
        get() {
            return _playBackButtonLabel
        }

    fun playBackClicked() {
        viewModelScope.launch {
            if (model.isPlaying()) {
                model.stop()
                _playBackButtonLabel.value = "Start Playback"
            } else {
                model.play()
                _playBackButtonLabel.value = "Stop Playback"
            }
        }

    }
}