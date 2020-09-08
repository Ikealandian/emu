// EMU
//  Essential Multi-platform Utilities

// X11 Window
// src/x11/x11_window.c
#include "x11_platform.h"
#include "x11_input.h"

void x11_get_atoms(emu_window* _window)
{
    _window->WMDeleteWindow = XInternAtom(_window->xDisplay, "WM_DELETE_WINDOW", False);

    Atom WMProtocols[1] = 
    {
        _window->WMDeleteWindow
    };

    XSetWMProtocols(_window->xDisplay, _window->xWindow, WMProtocols, 1);
}

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
    _window->xScreen = ScreenOfDisplay(_window->xDisplay, _window->nScreen);

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

    // Get X11 Atoms
    x11_get_atoms(_window);

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

emu_window* emu_window_create(const char* _title, long _width, long _height, emu_stack* _event_stack, long _flags)
{
    emu_window* eWindow = malloc(sizeof(emu_window));
    eWindow->wTitle = _title;
    eWindow->wWidth = _width;
    eWindow->wHeight = _height;
    eWindow->wEventStack = _event_stack;
    eWindow->wFlags = _flags;

    if (x11_assemble_window(eWindow) != 0)
    {
        emu_window_destroy(eWindow);
        return NULL;
    }

    return eWindow;
}

void emu_window_poll(emu_window* _window)
{
    if (!_window->wEventStack)
    {
        fputs("EMU [X11] Window: Could not poll events (wEventStack == null)\n", stderr);
        return;
    }

    // uKeyEvent
    // uButtonEvent

    // x11_input    .h .c
    // x11_events   .h .c

    // TODO List:
    //  https://github.com/Ikealandian/emu/blob/master/README.md

    while (XPending(_window->xDisplay))
    {
        XNextEvent(_window->xDisplay, &_window->xEvent);

        XEvent* xEvent = &_window->xEvent;
        switch (xEvent->type)
        {
        // X11 Key Press/Released Events
        // EMU_EVENT_INPUT_KEY
        case KeyPress:
            x11_handle_char(_window);
            x11_handle_key_press(_window);
            break;
        case KeyRelease:
            x11_handle_key_release(_window);
            break;

        // X11 Button Press/Released Events
        // X11 Scroll
        // EMU_EVENT_INPUT_BUTTON
        // EMU_EVENT_INPUT_MOVED
        case ButtonPress:
            x11_handle_button_press(_window);
            x11_handle_scroll(_window);
            break;
        case ButtonRelease:
            x11_handle_button_release(_window);
            break;

        // X11 Pointer Moved
        // EMU_EVENT_INPUT_MOVED
        case MotionNotify:
            x11_handle_moved(_window);
            break;

        // X11 Client Message Event
        case ClientMessage:
        {
            XClientMessageEvent* Message = &_window->xEvent.xclient;

            // Is window closed event?
            if ((Atom)Message->data.l[0] == _window->WMDeleteWindow)
            {
                // Push message to stack
                emu_event emuEventWindowClosed;
                emuEventWindowClosed.Type = EMU_EVENT_WINDOW_CLOSED;
                emu_stack_push(_window->wEventStack, emuEventWindowClosed);
            }
            break;
        }

        // Unhandled Events
        default: break;
        }
    }
}

void emu_window_destroy(emu_window* _window)
{    
    // Destroy Window and Close Display
    XDestroyWindow(_window->xDisplay, _window->xWindow);
    XCloseDisplay(_window->xDisplay);

    // free emu_window*
    free(_window);
}