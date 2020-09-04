// EMU
//  Essential Multi-platform Utilities

// Stack
// src/emu_stack.c
#include <emu/emu_stack.h>

#include <stdlib.h>


typedef struct emu_stack
{
    emu_event* sData;
    long sSize, sCapacity;
}emu_stack;

#define EMU_STACK_RESIZE        5
#define EMU_STACK_CAPACITY      24

int emu_stack_resize(emu_stack* _stack)
{
    // Increase capacity
    _stack->sCapacity += EMU_STACK_RESIZE;

    // Get new byte size
    long sNewSize = _stack->sCapacity * sizeof(emu_event);

    // Resize
    emu_event* sTmp = realloc(_stack->sData, sNewSize);

    // Check if resize was successful
    if (!sTmp)
    {
        free(_stack->sData);
        return 1;
    }

    // Set stack data to resized data
    _stack->sData = sTmp;

    return 0;
}

emu_stack* emu_stack_create()
{
    // Allocate emu_stack
    emu_stack* eStack = malloc(sizeof(emu_stack));

    // Set values
    eStack->sCapacity = EMU_STACK_CAPACITY;

    // Allocate data
    long sDataSize = eStack->sCapacity * sizeof(struct emu_event);
    eStack->sData = malloc(sDataSize);

    // Return the new stack
    return eStack;
}

void emu_stack_clear(emu_stack* _stack)
{
    // Reset stack size
    _stack->sSize = 0L;
}

long emu_stack_size(emu_stack* _stack)
{
    return _stack->sSize;
}

void emu_stack_push(emu_stack* _stack, emu_event _data)
{
    if (_stack->sSize++ >= _stack->sCapacity)
        emu_stack_resize(_stack);
    _stack->sData[_stack->sSize - 1] = _data;
}

emu_event emu_stack_pop(emu_stack* _stack)
{
    // set size back so it can be overwritten
    _stack->sSize--;
    return _stack->sData[_stack->sSize];
}

void emu_stack_destroy(emu_stack* _stack)
{
    // Free stack data
    free(_stack->sData);

    // Free stack
    free(_stack);

    _stack = NULL;
}