// EMU
//  Essential Multi-platform Utilities

// emu/emu_window.h
#ifndef _EMU_WINDOW_H_
#define _EMU_WINDOW_H_

// EMU Event Stack
#include <emu/emu_stack.h>

// EMU Window Flags
#define EMU_WINDOW_CENTERED     (1 << 0)
#define EMU_WINDOW_NORESIZE     (1 << 1)
#define EMU_WINDOW_MAXIMIZED    (1 << 2)
#define EMU_WINDOW_FULLSCREEN   (1 << 3)

// emu_window structure
typedef struct emu_window emu_window;

// emu_screen structure
typedef struct emu_screen
{
    unsigned long sIndex;
    long sWidth, sHeight;
}emu_screen;

// Create emu_window
emu_window* emu_window_create(
    const char* _title,
    long _width, long _height,
    emu_stack* _event_stack,
    long _flags
);

// Poll emu_window Events
void emu_window_poll(emu_window* _window);

// Destroy emu_window
void emu_window_destroy(emu_window* _window);

#endif