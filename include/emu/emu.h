// EMU
//  Essential Multi-platform Utilities

// emu/emu.h
#ifndef _EMU_H_
#define _EMU_H_

#include "emu_events.h"
#include "emu_input.h"
#include "emu_stack.h"
#include "emu_window.h"

// Initialize emu and platform
unsigned emu_init(emu_stack* _stack);

// Shutdown emu and platform
unsigned emu_shutdown(emu_stack* _stack);

#endif