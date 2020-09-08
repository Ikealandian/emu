// EMU
//  Essential Multi-platform Utilities

// X11 Events
// src/x11/x11_events.c
#include "x11_platform.h"

void x11_push_opened(emu_window* _window)
{
    emu_event OpenedEvent;
    OpenedEvent.Type = EMU_EVENT_WINDOW_OPENED;

    emu_stack_push(_window->wEventStack, OpenedEvent);
}

void x11_push_closed(emu_window* _window)
{
    emu_event ClosedEvent;
    ClosedEvent.Type = EMU_EVENT_WINDOW_CLOSED;
    
    emu_stack_push(_window->wEventStack, ClosedEvent);
}

void x11_push_moved(emu_window* _window, long _x, long _y)
{
    emu_event MovedEvent;
    MovedEvent.Type = EMU_EVENT_INPUT_MOVED;
    
    // TODO:
    //  Create uMoved in emu_event
    //  Set _X, _Y

    emu_stack_push(_window->wEventStack, MovedEvent);
}

void x11_push_button(emu_window* _window, long _x, long _y, long _button, long _action)
{
    emu_event ButtonEvent;
    ButtonEvent.Type = EMU_EVENT_INPUT_BUTTON;

    // Set Pointer position
    ButtonEvent.uButton.PointerX = _x;
    ButtonEvent.uButton.PointerY = _y;

    // Set action and keycode
    ButtonEvent.uButton.Button = _button;
    ButtonEvent.uButton.Action = _action;

    emu_stack_push(_window->wEventStack, ButtonEvent);
}

void x11_push_scroll(emu_window* _window, long _x, long _y, float _delta, int _axis)
{
    emu_event ScrolledEvent;
    ScrolledEvent.Type = EMU_EVENT_INPUT_SCROLL;
    
    // TODO:
    //  Create uScroll in emu_event
    //  Set _X, _Y and _delta, _axis

    emu_stack_push(_window->wEventStack, ScrolledEvent);
}

void x11_push_key(emu_window* _window, long _key, long _action, long _repeat)
{
    emu_event KeyEvent;
    KeyEvent.Type = EMU_EVENT_INPUT_KEY;
    
    // Set data
    KeyEvent.uKey.Key = _key;
    KeyEvent.uKey.Action = _action;
    KeyEvent.uKey.Repeat = _repeat;

    emu_stack_push(_window->wEventStack, KeyEvent);
}