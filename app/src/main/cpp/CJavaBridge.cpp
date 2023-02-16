#include <jni.h>
#include <memory>
#include "BlipLop.h"
#include "Log.h"


extern "C" {
JNIEXPORT jlong JNICALL
Java_com_tekinatawar_bliplop_BlipLopNativeModel_create(JNIEnv *env, jobject thiz) {
    auto blipLop = std::make_unique<bliplop::BlipLop>();

    if (not blipLop) {
        LOGD(" Failed to create the blipLop.");
        blipLop.reset(nullptr);
    }

    return reinterpret_cast<jlong>(blipLop.release());
}

JNIEXPORT void JNICALL
Java_com_tekinatawar_bliplop_BlipLopNativeModel_destroy(JNIEnv *env, jobject thiz,
                                                        jlong blipLopPointer) {
    auto *blipLop = reinterpret_cast<bliplop::BlipLop *>(blipLopPointer);

    if (not blipLop) {
        LOGD("Attempt to destroy an uninitialized blipLop.");
        return;
    }

    delete blipLop;
}

JNIEXPORT void JNICALL
Java_com_tekinatawar_bliplop_BlipLopNativeModel_nativePlay(JNIEnv *env, jobject thiz,
                                                           jlong blipLopPointer) {
    auto *blipLop = reinterpret_cast<bliplop::BlipLop *>(blipLopPointer);

    if (blipLop) {
        blipLop->play();
    } else {
        LOGD("blipLop not created. Please create the blipLop first by calling create");
    }
}

JNIEXPORT void JNICALL
Java_com_tekinatawar_bliplop_BlipLopNativeModel_nativeStop(JNIEnv *env, jobject thiz,
                                                           jlong blipLopPointer) {
    auto *blipLop = reinterpret_cast<bliplop::BlipLop *>(blipLopPointer);

    if (blipLop) {
        blipLop->stop();
    } else {
        LOGD("blipLop not created. Please create the blipLop first by calling create");
    }
}
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_tekinatawar_bliplop_BlipLopNativeModel_nativeIsPlaying(JNIEnv *env, jobject thiz,
                                                                jlong blipLopPointer) {
    auto *blipLop = reinterpret_cast<bliplop::BlipLop *>(blipLopPointer);

    if (blipLop) {
        return blipLop->isPlaying();
    } else {
        LOGD("blipLop not created. Please create the blipLop first by calling create");
    }

    return false;
}