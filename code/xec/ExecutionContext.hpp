// Copyright (c) Borislav Stanimirov
// SPDX-License-Identifier: MIT
//
#pragma once
#include "API.h"

#include <chrono>

namespace xec {

class ExecutorBase;

class XEC_API ExecutionContext {
public:
    virtual ~ExecutionContext(); // defined in ExecutorBase.cpp, not here but in a cpp so as to export the vtable

    // signal that the executor needs to be updated
    virtual void wakeUpNow() = 0;

    // schedule a wake up
    // NOTE that if a wake up happens before the scheduled time (by wakeUpNow) the scheduled time is forgotten
    // NOTE that if two calls to schedule a wake up happen before a wake up, the second one will override the first
    virtual void scheduleNextWakeUp(std::chrono::milliseconds timeFromNow) = 0;
    virtual void unscheduleNextWakeUp() = 0;

    // called by the executor when it determines that it wants to be stopped
    virtual void stop() = 0;
};

}
