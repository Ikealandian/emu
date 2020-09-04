// EMU
//  Essential Multi-platform Utilities

// emu/emu_stack.h
#ifndef _EMU_STACK_H_
#define _EMU_STACK_H_

// emu_stack
typedef struct emu_stack emu_stack;

// Create emu_stack
emu_stack* emu_create_stack(long _capacity, long _resize_by, long _type_size);



// Pop front element off stack
void* emu_pop_stack(emu_stack* _stack);

// Push to front
void emu_push_stack(emu_stack* _stack, void* _data);

// Free stack data
// Destroy emu_stack
void emu_destroy_stack(emu_stack* _stack);

#endif