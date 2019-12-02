/*
	Copyright (C) 2018 Apple Inc. All Rights Reserved. Not to be used or disclosed without permission from Apple.
 */

#include "AirTunesPTPClock.h"
#include "AirTunesClock.h"
#include "AirTunesClockPriv.h"

#include "DebugServices.h"

typedef struct
{
    struct AirTunesClockPrivate header; // An AirTunesClock always starts with this
    // $$$ TODO: Add any data needed by the PTP clock
} AirTunesPTPClock;

DEBUG_STATIC OSStatus AirTunesPTPClock_Finalize(AirTunesClockRef inClock);
DEBUG_STATIC Boolean AirTunesPTPClock_Adjust(AirTunesClockRef inClock, int64_t inOffsetNanoseconds, Boolean inReset);
DEBUG_STATIC void AirTunesPTPClock_GetNetworkTime(AirTunesClockRef inClock, AirTunesTime* outTime);
DEBUG_STATIC void AirTunesPTPClock_UpTicksToNetworkTime(AirTunesClockRef inClock, AirTunesTime* outTime, uint64_t inTicks);
DEBUG_STATIC OSStatus AirTunesPTPClock_ConvertNetworkTimeToUpTicks(AirTunesClockRef inClock, AirTunesTime inNetworkTime, uint64_t* outUpTicks);
DEBUG_STATIC OSStatus AirTunesPTPClock_AddPeer(AirTunesClockRef inClock, CFStringRef inInterfaceName, const void* inSockAddr);
DEBUG_STATIC OSStatus AirTunesPTPClock_RemovePeer(AirTunesClockRef ptp, CFStringRef inInterfaceName, const void* inSockAddr);

//===========================================================================================================================
//	AirTunesPTPClock_Create
//===========================================================================================================================

OSStatus AirTunesPTPClock_Create(AirTunesPTPClockSettings* ptpSettings, AirTunesClockRef* outRef)
{
    OSStatus err;
    AirTunesPTPClock* ptp;

    ptp = (AirTunesPTPClock*)calloc(1, sizeof(*ptp));
    require_action(ptp, exit, err = kNoMemoryErr);

    ptp->header.class = kAirTunesClockPTP;
    ptp->header.vtable.finalize = AirTunesPTPClock_Finalize;
    ptp->header.vtable.adjust = AirTunesPTPClock_Adjust;
    ptp->header.vtable.getNetworkTime = AirTunesPTPClock_GetNetworkTime;
    ptp->header.vtable.upTicksToNetworkTime = AirTunesPTPClock_UpTicksToNetworkTime;
    ptp->header.vtable.netTimeToUpTicks = AirTunesPTPClock_ConvertNetworkTimeToUpTicks;
    ptp->header.vtable.addPeer = AirTunesPTPClock_AddPeer;
    ptp->header.vtable.removePeer = AirTunesPTPClock_RemovePeer;
    ptp->ptpSettings = *ptpSettings;

    // $$$ TODO: Establish connection with PTP clock

    *outRef = &ptp->header;
    ptp = NULL;
    err = kNoErr;

exit:
    // Clean up on error
    if (ptp) {
        AirTunesClock_Finalize(&ptp->header);
        *outRef = NULL;
    }

    return (err);
}

//===========================================================================================================================
//	AirTunesPTPClock_Finalize
//===========================================================================================================================

DEBUG_STATIC OSStatus AirTunesPTPClock_Finalize(AirTunesClockRef inClock)
{
    if (inClock) {
        AirTunesPTPClock* ptp = (AirTunesPTPClock*)inClock;
        (void)ptp;
        // $$$ TODO: Delete the PTP clock and free any allocated data
        free(inClock);
    }
    return (kNoErr);
}

//===========================================================================================================================
//	AirTunesPTPClock_Adjust
//===========================================================================================================================

DEBUG_STATIC Boolean AirTunesPTPClock_Adjust(AirTunesClockRef inClock, int64_t inOffsetNanoseconds, Boolean inReset)
{
    // Can't adjust PTP clock.
    (void)inClock;
    (void)inOffsetNanoseconds;

    return (inReset);
}

//===========================================================================================================================
//	AirTunesNTPClock_GetSynchronizedTime
//===========================================================================================================================

DEBUG_STATIC void AirTunesPTPClock_GetNetworkTime(AirTunesClockRef inClock, AirTunesTime* outTime)
{
    AirTunesPTPClock* ptp = (AirTunesPTPClock*)inClock;
    (void)ptp;
    (void)outTime;
    // $$$ TODO: Get the time from the PTP clock

    // AirTunesTime_FromFP( outTime, ptpSeconds );
}

//===========================================================================================================================
//	AirTunesPTPClock_GetSynchronizedTimeNearUpTicks
//===========================================================================================================================

DEBUG_STATIC void AirTunesPTPClock_UpTicksToNetworkTime(AirTunesClockRef inClock, AirTunesTime* outTime, uint64_t inTicks)
{
    AirTunesPTPClock* ptp = (AirTunesPTPClock*)inClock;

    (void)inTicks;
    (void)ptp;
    (void)outTime;

    // $$$ TODO: Get the PTP time for the given ticks.

    // AirTunesTime_FromFP( outTime,  ptpSeconds ) );
}

//===========================================================================================================================
//    AirTunesPTPClock_ConvertNetworkTimeToUpTicks
//===========================================================================================================================
OSStatus AirTunesPTPClock_ConvertNetworkTimeToUpTicks(AirTunesClockRef inClock, AirTunesTime inNetworkTime, uint64_t* outUpTicks)
{
    (void)inClock;
    (void)inNetworkTime;
    (void)inNetworkTime;
    (void)outUpTicks;

    // $$$ TODO: Convert PTP time to local ticks

    return kUnsupportedErr;
}
//===========================================================================================================================
//    AirTunesPTPClock_RemovePeer
//===========================================================================================================================

OSStatus AirTunesPTPClock_RemovePeer(AirTunesClockRef inClock, CFStringRef inInterfaceName, const void* inSockAddr)
{
    (void)inClock;
    (void)inInterfaceName;
    (void)inSockAddr;

    // $$$ TODO: Tell PTP clock that is it should no longer listed to peer

    return kUnsupportedErr;
}

//===========================================================================================================================
//	AirTunesPTPClock_AddPeer
//===========================================================================================================================

DEBUG_STATIC OSStatus AirTunesPTPClock_AddPeer(AirTunesClockRef inClock, CFStringRef inInterfaceName, const void* inSockAddr)
{
    OSStatus err = kNoErr;
    const sockaddr_ip* const peerIP = (const sockaddr_ip*)inSockAddr;

    (void)inClock;
    (void)inInterfaceName;

    if (peerIP->sa.sa_family == AF_INET) {
        // $$$ TODO: Tell the PTP clock about this IPv4 peer.
    }
#ifdef AF_INET6
    else if (peerIP->sa.sa_family == AF_INET6) {
        // $$$ TODO: Tell the PTP clock about this IPv6 peer.
    }
#endif //AF_INET6
    else {
        err = kParamErr;
    }
    require_noerr(err, exit);

exit:
    return kUnsupportedErr;
}
