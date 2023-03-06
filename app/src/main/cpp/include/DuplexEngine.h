#include <array>
#include <algorithm>
#include <variant>

#include <oboe/Oboe.h>
#include "FunctionList.h"
#include "DuplexCallback.h"


class DuplexEngine {
public:
    DuplexEngine();

    void beginStreams();

    virtual ~DuplexEngine() = default;

    oboe::Result startStreams();

    oboe::Result stopStreams();


    std::variant<FunctionList<int16_t *>, FunctionList<float *>> functionList{
            std::in_place_type<FunctionList<int16_t *>>};

private:

    void openInStream();

    void openOutStream();

    static oboe::AudioStreamBuilder defaultBuilder();

    template<class numeric>
    void createCallback();

    oboe::ManagedStream inStream;
    std::unique_ptr<oboe::AudioStreamCallback> mCallback;
    oboe::ManagedStream outStream;
};