// EMU
//  Essential Multi-platform Utilities

// emu/emu_stack.h
#ifndef _EMU_STACK_H_
#define _EMU_STACK_H_

// emu_stack
typedef struct emu_stack emu_stack;



// Initialize stack data
void emu_alloc_stack(emu_stack* _stack);

// Pop front element off stack
void* emu_pop_stack(emu_stack* _stack);

// Push to front
void emu_push_stack(emu_stack* _stack, void* _data);

// Free stack data
void emu_free_stack(emu_stack* _stack);

#endif