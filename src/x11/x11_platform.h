// EMU
//  Essential Multi-platform Utilities

// src/x11/x11_platform.h
#ifndef _EMU_X11_PLATFORM_H_
#define _EMU_X11_PLATFORM_H_

#include <emu/emu_window.h>

#include <stdlib.h>
#include <stdio.h>

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>

// X11 emu_window
typedef struct emu_window
{
    const char* wTitle;
    long wX, wY;
    long wWidth, wHeight;
    emu_stack* wEventStack;
    long wFlags;

    // X11
    XEvent xEvent;
    Screen* xScreen;
    Display* xDisplay;
    Window xRoot;
    Window xWindow;
    int nScreen;

    // X11 Atoms
    Atom WMDeleteWindow;

}emu_window;

#endif