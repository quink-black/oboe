/*
 * Copyright 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef OBOE_OUTPUT_MIXER_OPENSLES_H
#define OBOE_OUTPUT_MIXER_OPENSLES_H

#include <atomic>
#include <mutex>

#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>

namespace oboe {

/**
 * INTERNAL USE ONLY
 */

class OutputMixerOpenSL {
public:
    static OutputMixerOpenSL *getInstance();

    SLresult open();

    void close();

    SLresult createAudioPlayer(SLObjectItf *objectItf,
                               SLDataSource *audioSource);

private:
    std::mutex            mLock;
    std::atomic<int32_t>  mOpenCount{0};
    SLObjectItf           mOutputMixObject = 0;
};

} // namespace oboe

#endif //OBOE_OUTPUT_MIXER_OPENSLES_H