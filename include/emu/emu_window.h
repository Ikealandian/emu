// EMU
//  Essential Multi-platform Utilities

// emu/emu_window.h
#ifndef _EMU_WINDOW_H_
#define _EMU_WINDOW_H_

// EMU Window Flags
#define EMU_WINDOW_CENTERED     (1 << 0)
#define EMU_WINDOW_NORESIZE     (1 << 1)
#define EMU_WINDOW_MAXIMIZED    (1 << 2)
#define EMU_WINDOW_FULLSCREEN   (1 << 3)

// emu_window structure
typedef struct emu_window emu_window;

// Create emu_window
emu_window* emu_create_window(
    const char* _title,
    long _width, long _height,
    long _flags
);

// Poll emu_window Events
void emu_poll_window(emu_window* _window);

// Destroy emu_window
void emu_destroy_window(emu_window* _window);

#endif