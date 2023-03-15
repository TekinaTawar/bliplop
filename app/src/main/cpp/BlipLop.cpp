#include "BlipLop.h"
#include "Log.h"
#include "archive/OboeSinePlayer.h"
#include "DuplexEngine.h"
//#include "FunctionList.h"

namespace bliplop {
    static DuplexEngine *enginePtr = nullptr;

    void BlipLop::play() {
        LOGD("BlipLop::play() called");
        _isPlaying = true;
        enginePtr = new DuplexEngine();
        setGain();
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

    template<typename Iter>
    void Gain(Iter begin, Iter end) {
        const float gain = 10.0f;
        for (auto it = begin; it != end; ++it) {
            *it *= gain;
        }
    }

//    std::function<void(iter_type, iter_type)> gainFunc = &Gain<iter_type>;

    void BlipLop::setGain() {
        LOGD("BlipLop::setGain() called");
        if (!enginePtr) return;
        std::visit([](auto &&stack) {
            using iter_type = decltype(stack.getType());
            std::function<void(iter_type, iter_type)> f = &Gain<iter_type>;
            stack.addEffect(f);
        }, enginePtr->functionList);
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