// EMU
//  Essential Multi-platform Utilities

// Wayland Window
// src/way_window.c
#include <emu/emu_window.h>

#include <stdlib.h>
#include <stdio.h>

typedef struct emu_window
{
    const char* wTitle;
    long wWidth, wHeight;
    long wFlags;
}emu_window;

emu_window* emu_create_window(const char* _title, long _width, long _height, long _flags)
{
    emu_window* eWindow = malloc(sizeof(emu_window));
    eWindow->wTitle = _title;
    eWindow->wWidth = _width;
    eWindow->wHeight = _height;
    eWindow->wFlags = _flags;

    return eWindow;
}

void emu_destroy_window(emu_window* _window)
{
    printf("Title: %s\n", _window->wTitle);
    free(_window);
}