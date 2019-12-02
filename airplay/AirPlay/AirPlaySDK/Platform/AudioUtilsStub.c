/*
 Copyright (C) 2012-2019 Apple Inc. All Rights Reserved. Not to be used or disclosed without permission from Apple.
 */

#include "AudioUtils.h"

#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

#include "CommonServices.h"
#include "PrintFUtils.h"
#include "ThreadUtils.h"
#include "TickUtils.h"

#include CF_HEADER
#include LIBDISPATCH_HEADER

#include CF_RUNTIME_HEADER

//===========================================================================================================================
//	AudioStream
//===========================================================================================================================

typedef struct AudioStreamPrivate* AudioStreamImpRef;
struct AudioStreamPrivate {
    CFRuntimeBase base; // CF type info. Must be first.
    Boolean prepared; // True if AudioStreamPrepare has been called (and stop hasn't yet).
    Boolean keepRunning; // True if the Audiothread is to keep running.

    pthread_t audioThread;
    pthread_t* audioThreadPtr;
    int threadPriority; // Priority to run threads.

    void* delegateContext; // Context for the session delegate
    AudioStreamOutputCallback_f outputCallbackPtr; // Function to call to read audio to output.
    void* outputCallbackCtx; // Context to pass to audio output callback function.
    AudioStreamBasicDescription format; // Format of the audio data.
    uint32_t preferredLatencyMics; // Max latency the app can tolerate.
    uint32_t streamType; // AirPlay Stream type (e.g. main, alt).
};

#define _AudioStreamGetImp(STREAM) (STREAM)

static void _AudioStreamGetTypeID(void* inContext);
static void _AudioStreamFinalize(CFTypeRef inCF);
static void* _AudioThreadFn(void* inArg);

static dispatch_once_t gAudioStreamInitOnce = 0;
static CFTypeID gAudioStreamTypeID = _kCFRuntimeNotATypeID;
static const CFRuntimeClass kAudioStreamClass = {
    0, // version
    "AudioStream", // className
    NULL, // init
    NULL, // copy
    _AudioStreamFinalize, // finalize
    NULL, // equal -- NULL means pointer equality.
    NULL, // hash  -- NULL means pointer hash.
    NULL, // copyFormattingDesc
    NULL, // copyDebugDesc
    NULL, // reclaim
    NULL // refcount
};

//===========================================================================================================================
//	Logging
//===========================================================================================================================

ulog_define(AudioStream, kLogLevelNotice, kLogFlags_Default, "AudioStream", NULL);
#define as_dlog(LEVEL, ...) dlogc(&log_category_from_name(AudioStream), (LEVEL), __VA_ARGS__)
#define as_ulog(LEVEL, ...) ulog(&log_category_from_name(AudioStream), (LEVEL), __VA_ARGS__)

//===========================================================================================================================
//	AudioStreamGetTypeID
//===========================================================================================================================

CFTypeID AudioStreamGetTypeID(void)
{
    dispatch_once_f(&gAudioStreamInitOnce, NULL, _AudioStreamGetTypeID);
    return (gAudioStreamTypeID);
}

static void _AudioStreamGetTypeID(void* inContext)
{
    (void)inContext;

    gAudioStreamTypeID = _CFRuntimeRegisterClass(&kAudioStreamClass);
    check(gAudioStreamTypeID != _kCFRuntimeNotATypeID);
}

//===========================================================================================================================
//	AudioStreamCreate
//===========================================================================================================================

OSStatus AudioStreamCreate(AudioStreamRef* outStream)
{
    OSStatus err;
    AudioStreamRef me;
    size_t extraLen;

    extraLen = sizeof(*me) - sizeof(me->base);
    me = (AudioStreamRef)_CFRuntimeCreateInstance(NULL, AudioStreamGetTypeID(), (CFIndex)extraLen, NULL);
    require_action(me, exit, err = kNoMemoryErr);
    memset(((uint8_t*)me) + sizeof(me->base), 0, extraLen);

    // $$$ TODO: Other initialization goes here.
    // This function is only called when AudioUtils is compiled into the AirPlay library.

    *outStream = me;
    me = NULL;
    err = kNoErr;

exit:
    CFReleaseNullSafe(me);
    return (err);
}

//===========================================================================================================================
//	_AudioStreamFinalize
//===========================================================================================================================

static void _AudioStreamFinalize(CFTypeRef inCF)
{
    AudioStreamRef const me = (AudioStreamRef)inCF;
    // $$$ TODO: Last chance to free any resources allocated by this object.
    // This function is called when AudioUtils is compiled into the AirPlay library, when the retain count of an AudioStream
    // object goes to zero.
    AudioStreamStop(me, false);
}

//===========================================================================================================================
//	AudioStreamSetInputCallback
//===========================================================================================================================

void AudioStreamSetInputCallback(AudioStreamRef inStream, AudioStreamInputCallback_f inFunc, void* inContext)
{
    (void)inStream;
    (void)inFunc;
    (void)inContext;
}

//===========================================================================================================================
//	AudioStreamSetOutputCallback
//===========================================================================================================================

void AudioStreamSetOutputCallback(AudioStreamRef inStream, AudioStreamOutputCallback_f inFunc, void* inContext)
{
    AudioStreamImpRef const me = _AudioStreamGetImp(inStream);

    me->outputCallbackPtr = inFunc;
    me->outputCallbackCtx = inContext;
}

//===========================================================================================================================
//	_AudioStreamCopyProperty
//===========================================================================================================================

CFTypeRef
_AudioStreamCopyProperty(
    CFTypeRef inObject,
    CFStringRef inProperty,
    OSStatus* outErr)
{
    AudioStreamImpRef const me = _AudioStreamGetImp((AudioStreamRef)inObject);
    OSStatus err;
    CFTypeRef value = NULL;

    if (0) {
    }

    // AudioType
    else if (CFEqual(inProperty, kAudioStreamProperty_AudioType)) {
        // $$$ TODO: Return the current audio type.
    }

    // Format

    else if (CFEqual(inProperty, kAudioStreamProperty_Format)) {
        value = CFDataCreate(NULL, (const uint8_t*)&me->format, sizeof(me->format));
        require_action(value, exit, err = kNoMemoryErr);
    }

    // Input

    else if (CFEqual(inProperty, kAudioStreamProperty_Input)) {
    }

    // PreferredLatency

    else if (CFEqual(inProperty, kAudioStreamProperty_PreferredLatency)) {
        value = CFNumberCreateInt64(me->preferredLatencyMics);
        require_action(value, exit, err = kNoMemoryErr);
    }

    // StreamType

    else if (CFEqual(inProperty, kAudioStreamProperty_StreamType)) {
        value = CFNumberCreateInt64(me->streamType);
        require_action(value, exit, err = kNoMemoryErr);
    }

    // ThreadName

    else if (CFEqual(inProperty, kAudioStreamProperty_ThreadName)) {
        // $$$ TODO: If your implementation uses a helper thread, return its name here.
    }

    // ThreadPriority

    else if (CFEqual(inProperty, kAudioStreamProperty_ThreadPriority)) {
        // $$$ TODO: If your implementation uses a helper thread, return its priority here.
    }

    // Other

    else {
        err = kNotHandledErr;
        goto exit;
    }
    err = kNoErr;

exit:
    if (outErr)
        *outErr = err;
    return (value);
}

//===========================================================================================================================
//	_AudioStreamSetProperty
//===========================================================================================================================

OSStatus
_AudioStreamSetProperty(
    CFTypeRef inObject,
    CFStringRef inProperty,
    CFTypeRef inValue)
{
    AudioStreamImpRef const me = _AudioStreamGetImp((AudioStreamRef)inObject);
    OSStatus err;

    if (0) {
    }

    // Volume

    else if (CFEqual(inProperty, kAudioStreamProperty_Volume)) {
        // $$$ TODO: Set the volume
    }

    // AudioType

    else if (CFEqual(inProperty, kAudioStreamProperty_AudioType)) {
        // $$$ TODO: Use the audio type to enable certain types of audio processing.
        // For example, if the audio type is "telephony", echo cancellation should be enabled;
        // if the audio type is "speech recognition", non-linear processing algorithms should be disabled.
    }

    // Format

    else if (CFEqual(inProperty, kAudioStreamProperty_Format)) {
        CFGetData(inValue, &me->format, sizeof(me->format), NULL, &err);
        require_noerr(err, exit);
    }
    // Input

    else if (CFEqual(inProperty, kAudioStreamProperty_Input)) {
    }
    // PreferredLatency

    else if (CFEqual(inProperty, kAudioStreamProperty_PreferredLatency)) {
        me->preferredLatencyMics = (uint32_t)CFGetInt64(inValue, &err);
        require_noerr(err, exit);
    }

    // StreamType

    else if (CFEqual(inProperty, kAudioStreamProperty_StreamType)) {
        me->streamType = (uint32_t)CFGetInt64(inValue, &err);
        require_noerr(err, exit);
    }

    // ThreadName

    else if (CFEqual(inProperty, kAudioStreamProperty_ThreadName)) {
        // $$$ TODO: If your implementation uses a helper thread, set the name of the thread to the string passed in
        // to this property.  See SetThreadName().
    }

    // ThreadPriority

    else if (CFEqual(inProperty, kAudioStreamProperty_ThreadPriority)) {
        // $$$ TODO: If your implementation uses a helper thread, set the priority of the thread to the string passed in
        // to this property.  See SetCurrentThreadPriority().
        me->threadPriority = (int)CFGetInt64(inValue, &err);
    }

    // Other

    else {
        as_ulog(kLogLevelNotice, "%s: Unhandled %@:%@\n", __PRETTY_FUNCTION__, inProperty, inValue);
        err = kNotHandledErr;
        goto exit;
    }
    err = kNoErr;

exit:
    return (err);
}

//===========================================================================================================================
//	AudioStreamSetFormat
//===========================================================================================================================

void AudioStreamSetFormat(AudioStreamRef inStream, const AudioStreamBasicDescription* inFormat)
{
    AudioStreamImpRef const me = _AudioStreamGetImp(inStream);
    me->format = *inFormat;
}

//===========================================================================================================================
//	AudioStreamSetDelegateContext
//===========================================================================================================================

void AudioStreamSetDelegateContext(AudioStreamRef inStream, void* inContext)
{
    AudioStreamImpRef const me = _AudioStreamGetImp(inStream);
    me->delegateContext = inContext;
}

#if 0
#pragma mark -
#endif

//===========================================================================================================================
//	AudioStreamPrepare
//===========================================================================================================================

OSStatus AudioStreamPrepare(AudioStreamRef inStream)
{
    AudioStreamImpRef const me = _AudioStreamGetImp(inStream);
    OSStatus err;

    // $$$ TODO: This is where the audio processing chain should be set up based on the properties previously set on the
    // AudioStream object:
    //	me->format specifies the sample rate, channel count, and bit-depth.
    //	me->input specifies whether or not the processing chain should be set up to record audio from the accessory's
    //	          microphone(s).
    // Audio output should always be prepared.
    // If the audio processing chain is successfully set up, me->prepared should be set to true.

    if (me->prepared) {
        return kNoErr;
    }

    me->prepared = true;
    me->keepRunning = true;
    err = kNoErr;

    if (err)
        AudioStreamStop(inStream, false);
    return (err);
}

//===========================================================================================================================
//	AudioStreamStart
//===========================================================================================================================

OSStatus AudioStreamStart(AudioStreamRef inStream)
{
    AudioStreamImpRef const me = _AudioStreamGetImp(inStream);
    OSStatus err;

    if (!me->prepared) {
        err = AudioStreamPrepare(inStream);
        require_noerr(err, exit);
    }

    // $$$ TODO: This is where the audio processing chain should be started.
    //
    // me->outputCallbackPtr should be invoked periodically to retrieve a continuous stream of samples to be output.
    // When calling me->outputCallbackPtr(), a buffer is provided for the caller to write into.  Equally important
    // is the inSampleTime and inHostTime arguments.  It is important that accurate { inSampleTime, inHostTime } pairs
    // be provided to the caller.  inSampleTime should be a (reasonably) current running total of the number of samples
    // that have hit the speaker since AudioStreamStart() was called.  inHostTime is the system time, in units of ticks,
    // corresponding to inSampleTime (see TickUtils.h).  This information will be returned to the controller and is
    // a key piece in allowing the controller to derive the relationship between the controller's system clock and the
    // accessory's audio (DAC) clock for A/V sync.
    //
    // If input has been requested (me->input == true), then me->inputCallbackPtr should also be invoked periodically
    // to provide a continuous stream of samples from the accessory's microphone (possibly with some processing, depending
    // on the audio type, see kAudioStreamProperty_AudioType).  If no audio samples are available for whatever reason,
    // the me->inputCallbackPtr should be called with a buffer of zeroes.

    require_action(me->audioThreadPtr == NULL, exit, err = kAlreadyInitializedErr);
    err = pthread_create(&me->audioThread, NULL, _AudioThreadFn, inStream);
    require_noerr(err, exit);
    me->audioThreadPtr = &me->audioThread;
exit:
    if (err)
        AudioStreamStop(inStream, false);
    return (err);
}

//===========================================================================================================================
//	AudioStreamStop
//===========================================================================================================================

void AudioStreamStop(AudioStreamRef inStream, Boolean inDrain)
{
    AudioStreamImpRef const me = _AudioStreamGetImp(inStream);

    // $$$ TODO: This is where the audio processing chain should be stopped, and the audio processing chain torn down.
    // When AudioStreamStop() returns, the object should return to the state similar to before AudioStreamPrepare()
    // was called, so this function is responsible for undoing any resource allocation performed in AudioStreamPrepare().
    (void)inDrain;

    if (me->audioThreadPtr) {
        me->prepared = false;
        me->keepRunning = false;

        pthread_join(me->audioThread, NULL);
        me->audioThreadPtr = NULL;
    }
}

#if 0
#pragma mark -
#endif

static void* _AudioThreadFn(void* inArg)
{
#define AudioBufferDuration 20 // 20 ms of data to read
#define AudioBufferPrefillMS 20 // 20 ms of prefill data
#define AudioBufferMaxAheadMS 100 // 100 ms of max amount of data

    /**
	 * $$$ TODO: This is where the audio data is obtained from the sdk and pushed to the platform's
	 * audio unit.
	 *
	 * NOTE: This is sample code for demonstration purposes only. It has a wrapping problem
	 *       that needs to be addressed.
	 * See Also: AudioUtils.h
	 */
    AudioStreamImpRef const me = _AudioStreamGetImp((AudioStreamRef)inArg);

    float const bytes_per_ms = (me->format.mSampleRate * 0.001 * me->format.mBytesPerFrame); // How many bytes per ms.
    size_t buffer_size = AudioBufferDuration * bytes_per_ms; // how many bytes of pcm data based on the desired duration
    size_t const number_of_samples_per_buffer = (buffer_size / me->format.mBytesPerFrame); // the number of samples in each buffer
    uint8_t* buffer; // buffer to hold the pcm data from the sdk
    uint32_t current_sample = 0; // sample number we are requesting when calling the sdk
    uint64_t total_ms = 0;

    buffer = (uint8_t*)calloc(1, buffer_size);
    require_action(buffer, exit, as_ulog(kLogLevelNotice, "Not enough memory\n"));

    SetThreadName("AudioStreamOutputThread");
    if (me->threadPriority > 0) {
        SetCurrentThreadPriority(me->threadPriority);
    }

    as_ulog(kLogLevelNotice, "bytes_per_ms:%f bufferSize:%d samples-per-buffer:%d\n", bytes_per_ms, (int)buffer_size, (int)number_of_samples_per_buffer);

    // Some audio units need some amount of data before playback starts
    // Prefill that buffer with some data.
    do {
        // $$$ TODO: Send data to audio unit to prime the audio pipe
        as_ulog(kLogLevelNotice, "Prefill:%.2H", buffer, 16, 16);
        total_ms += AudioBufferDuration;
    } while (total_ms < AudioBufferPrefillMS);

    uint64_t start = UpTicks();
    uint64_t now = start;
    do {
        uint64_t ms_buffer_remaining = total_ms - UpTicksToMilliseconds(now - start);

        // calculate how many millisecond of data was consumed while we were sleeping
        if (ms_buffer_remaining > AudioBufferMaxAheadMS) {
            // sleeping for 50ms
            usleep(50 * 1000);

            now = UpTicks();
            ms_buffer_remaining = total_ms - UpTicksToMilliseconds(now - start);
        }

        // calculate when the first of the pcm data we are about to get will play
        uint64_t out_sample_ticks = now + MillisecondsToUpTicks(ms_buffer_remaining);

        // Let the SDK fill our buffer with the PCM data starting at current_sample
        // that will play some time in the future out_sample_ticks
        me->outputCallbackPtr(current_sample,
            out_sample_ticks,
            buffer,
            buffer_size,
            me->outputCallbackCtx);

        // $$$ TODO: Send data to your audio unit
        if (total_ms % 100 == 0)
            as_ulog(kLogLevelNotice, "        %.2H", buffer, 16, 16);

        // Advance to the next sample number, total number of bytes written
        current_sample += number_of_samples_per_buffer;
        total_ms += AudioBufferDuration;
        now = UpTicks();
    } while (me->keepRunning);

    free(buffer);
exit:
    return (NULL);
}
