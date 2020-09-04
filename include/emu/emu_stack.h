// EMU
//  Essential Multi-platform Utilities

// Stack for emu events
// emu/emu_stack.h
#ifndef _EMU_STACK_H_
#define _EMU_STACK_H_

#include <emu/emu_events.h>

// emu_stack
typedef struct emu_stack emu_stack;

// Create emu_stack
emu_stack* emu_stack_create();

// Clear stack
void emu_stack_clear(emu_stack* _stack);

// Stack size
long emu_stack_size(emu_stack* _stack);

// Push element to front
void emu_stack_push(emu_stack* _stack, emu_event _data);

// Pop front element
emu_event emu_stack_pop(emu_stack* _stack);

// Destroy emu_stack
void emu_stack_destroy(emu_stack* _stack);

#endif