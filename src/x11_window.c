// EMU
//  Essential Multi-platform Utilities

// X11 Window
// src/x11_window.c
#include <emu/emu_window.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <X11/X.h>
#include <X11/Xlib.h>

typedef struct emu_window
{
    const char* wTitle;
    long wX, wY;
    long wWidth, wHeight;
    long wFlags;

    // X11
    Display* xDisplay;
    Window* xRoot;
    Window* xWindow;
    int nScreen;

}emu_window;

int x11_assemble_window(emu_window* _window)
{
    // xDisplay Open Display
    _window->xDisplay = XOpenDisplay(NULL);

    // if xDisplay == null
    if (!_window->xDisplay)
    {
        fputs("EMU [X11] Window: Could not open display\n", stderr);
        return 1;
    }

    // Get Default Screen and Root Window
    _window->nScreen = DefaultScreen(_window->xDisplay);
    _window->xRoot = RootWindow(_window->xDisplay, _window->nScreen);

    // Get primary screen
    Screen* xScreen = ScreenOfDisplay(_window->xDisplay, _window->nScreen);

    // Create Window
    _window->xWindow = XCreateSimpleWindow(
        _window->xDisplay, _window->xRoot,
        _window->wX, _window->wY,
        _window->wWidth, _window->wHeight,
        0, 0, 0x0
    );

    // if xWindow == null 
    if (!_window->xWindow)
    {
        fputs("EMU [X11] Window: XCreateSimpleWindow failed\n", stderr);
        return 2;
    }

    // Set Window Title
    XStoreName(_window->xDisplay, _window->xWindow, _window->wTitle);
    XSetIconName(_window->xDisplay, _window->xWindow, _window->wTitle);

    // Select Event Masks
    XSelectInput(
        _window->xDisplay, _window->xWindow,
        ExposureMask        |
        PropertyChangeMask  |
        StructureNotifyMask |
        KeyPressMask        |
        KeyReleaseMask      |
        PointerMotionMask   |
        LeaveWindowMask     |
        EnterWindowMask     |
        ButtonPressMask     |
        ButtonReleaseMask   |
        ButtonMotionMask
    );

    // Map Window
    XMapWindow(_window->xDisplay, _window->xWindow);

    // Success
    return 0;
}

emu_window* emu_create_window(const char* _title, long _width, long _height, long _flags)
{
    emu_window* eWindow = malloc(sizeof(emu_window));
    eWindow->wTitle = _title;
    eWindow->wWidth = _width;
    eWindow->wHeight = _height;
    eWindow->wFlags = _flags;

    if (x11_assemble_window(eWindow) != 0)
    {
        emu_destroy_window(eWindow);
        return NULL;
    }

    return eWindow;
}

void emu_destroy_window(emu_window* _window)
{    
    // Destroy Window and Close Display
    XDestroyWindow(_window->xDisplay, _window->xWindow);
    XCloseDisplay(_window->xDisplay);

    // free emu_window*
    free(_window);
}