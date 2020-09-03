// EMU
//  Essential Multi-platform Utilities

// Wayland Window
// src/way_window.c
#include <emu/emu_window.h>

#include <stdlib.h>
#include <stdio.h>

#include <wayland-client.h>

typedef struct emu_window
{
    const char* wTitle;
    long wWidth, wHeight;
    long wFlags;

    // Wayland
    struct wl_display* display;

}emu_window;

void wayland_setup(emu_window* _window)
{
    // Wayland connect to default display
    _window->display = wl_display_connect(NULL);

    // if display == null
    if (!_window->display)
    {
        fputs(stderr, "EMU [Wayland] Window: Can't connect to display");
        return;
    }
}

void wayland_shutdown(emu_window* _window)
{
    if (_window->display)
    {
        wl_display_disconnect(_window->display);
    }
}

void wayland_assemble_window(emu_window* _window)
{

}

emu_window* emu_create_window(const char* _title, long _width, long _height, long _flags)
{
    emu_window* eWindow = malloc(sizeof(emu_window));
    eWindow->wTitle = _title;
    eWindow->wWidth = _width;
    eWindow->wHeight = _height;
    eWindow->wFlags = _flags;

    wayland_setup(eWindow);
    wayland_assemble_window(eWindow);

    return eWindow;
}

void emu_destroy_window(emu_window* _window)
{
    wayland_shutdown(_window);
    
    // free emu_window*
    free(_window);
}