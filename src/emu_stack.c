// EMU
//  Essential Multi-platform Utilities

// Stack
// src/emu_stack.c
#include <emu/emu_stack.h>

#include <stdlib.h>

typedef struct emu_stack
{
    void** sData;
    long sTypeSize;
    long sSize, sCapacity, sResize;
}emu_stack;
int emu_resize_stack(emu_stack* _stack)
{
    // Increase capacity
    _stack->sCapacity += _stack->sResize;

    // Get new byte size
    long sNewSize = _stack->sCapacity * _stack->sTypeSize;

    // Resize
    void** sTmp = realloc(_stack->sData, sNewSize);

    // Check if resize was successful
    if (!sTmp)
        return 1;

    // Set stack data to resized data
    _stack->sData = sTmp;

    return 0;
}
