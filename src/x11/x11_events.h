// EMU
//  Essential Multi-platform Utilities

// src/x11/x11_events.h
#ifndef _EMU_X11_EVENTS_H_
#define _EMU_X11_EVENTS_H_

#include "x11_platform.h"

void x11_push_opened(emu_window* _window);
void x11_push_closed(emu_window* _window);

void x11_push_moved(emu_window* _window, long _x, long _y);
void x11_push_button(emu_window* _window, long _x, long _y, long _button, long _action);
void x11_push_scroll(emu_window* _window, long _x, long _y, float _delta, int _axis);

void x11_push_key(emu_window* _window, long _key, long _action, long _repeat);

#endif