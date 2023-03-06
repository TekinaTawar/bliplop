#include "BlipLop.h"
#include "Log.h"
#include "OboeSinePlayer.h"
#include "DuplexEngine.h"

namespace bliplop {
    static DuplexEngine *enginePtr = nullptr;

    void BlipLop::play() {
        LOGD("BlipLop::play() called");
        _isPlaying = true;
        enginePtr = new DuplexEngine();

    }

    void BlipLop::stop() {
        LOGD("BlipLop::stop() called");
        _isPlaying = false;
        if (!enginePtr) return;
        delete enginePtr;
        enginePtr = nullptr;
    }

    bool BlipLop::isPlaying() const {
        LOGD("BlipLop::isPlaying() called");
        return _isPlaying;
    }

    //Todo: setSource
    //Todo: setSink
} // bliplop

// procedural
// 1. Set Source
// 2. Set Sink
// 3. Play
// 3.1. Start Source stream
//