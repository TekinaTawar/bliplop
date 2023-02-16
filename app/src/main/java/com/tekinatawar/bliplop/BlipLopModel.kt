package com.tekinatawar.bliplop

interface BlipLopModel {
    suspend fun play();
    suspend fun stop();
    suspend fun isPlaying(): Boolean;
}