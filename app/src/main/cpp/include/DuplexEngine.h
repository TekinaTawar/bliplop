#include <array>
#include <algorithm>
#include <variant>

#include <oboe/Oboe.h>
#include "FunctionList.h"
#include "DuplexCallback.h"


class DuplexEngine {
public:
    DuplexEngine();

    virtual ~DuplexEngine() = default;

    void beginStreams();

    oboe::Result startStreams();

    oboe::Result stopStreams();

    std::variant<FunctionList<int16_t *>, FunctionList<float *>> functionList{
            std::in_place_type<FunctionList<int16_t *>>};

private:

    void openInStream();

    template<class numeric>
    void createCallback();

    void openOutStream();

    oboe::ManagedStream inStream;
    std::unique_ptr<oboe::AudioStreamCallback> mCallback;
    oboe::ManagedStream outStream;

    static oboe::AudioStreamBuilder defaultBuilder();
};