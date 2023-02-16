package com.tekinatawar.bliplop

import androidx.lifecycle.DefaultLifecycleObserver
import androidx.lifecycle.LifecycleOwner
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.withContext

class BlipLopNativeModel : BlipLopModel, DefaultLifecycleObserver {
    private var blipLopPointer: Long = 0
    private val synthesizerMutex = Object()

    private external fun create(): Long
    private external fun destroy(blipLopPointer: Long)
    private external fun nativePlay(blipLopPointer: Long)
    private external fun nativeStop(blipLopPointer: Long)
    private external fun nativeIsPlaying(blipLopPointer: Long): Boolean

    companion object {
        init {
            System.loadLibrary("bliplop")
        }
    }

    override fun onResume(owner: LifecycleOwner) {
        super.onResume(owner)
        synchronized(synthesizerMutex) {
            createNativeHandleIfNotExists()
        }
    }

    override fun onPause(owner: LifecycleOwner) {
        super.onPause(owner)
        synchronized(synthesizerMutex) {
            if (blipLopPointer == 0L) {
                return
            }
            destroy(blipLopPointer)
            blipLopPointer = 0L
        }
    }

    private fun createNativeHandleIfNotExists() {
        if (blipLopPointer != 0L) {
            return
        }
        blipLopPointer = create()
    }

    override suspend fun play() = withContext(Dispatchers.Default) {
        synchronized(synthesizerMutex) {
            createNativeHandleIfNotExists()
            nativePlay(blipLopPointer)
        }
    }

    override suspend fun stop() = withContext(Dispatchers.Default) {
        synchronized(synthesizerMutex) {
            createNativeHandleIfNotExists()
            nativeStop(blipLopPointer)
        }
    }

    override suspend fun isPlaying(): Boolean = withContext(Dispatchers.Default) {
        synchronized(synthesizerMutex) {
            createNativeHandleIfNotExists()
            return@withContext nativeIsPlaying(blipLopPointer)
        }
    }
}