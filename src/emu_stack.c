// EMU
//  Essential Multi-platform Utilities

// Stack
// src/emu_stack.c
#include <emu/emu_stack.h>

typedef struct emu_stack
{
    void** sData;
    long sTypeSize;
    long sSize, sCapacity, sResize;
}emu_stack;
