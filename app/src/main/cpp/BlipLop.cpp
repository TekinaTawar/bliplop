#include "BlipLop.h"
#include "Log.h"

namespace bliplop {
//    BlipLop::BlipLop() {};

    void BlipLop::play() {
        LOGD("BlipLop::play() called");
        _isPlaying = true;
    }

    void BlipLop::stop() {
        LOGD("BlipLop::stop() called");
        _isPlaying = false;
    }

    bool BlipLop::isPlaying() const {
        LOGD("BlipLop::isPlaying() called");
        return _isPlaying;
    }

} // bliplop