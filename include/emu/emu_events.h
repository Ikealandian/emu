// EMU
//  Essential Multi-platform Utilities

// emu/emu_events.h
#ifndef _EMU_EVENTS_H_
#define _EMU_EVENTS_H_

// EMU Events

// Window   0x1
#define EMU_EVENT_WINDOW_OPENED     0x11
#define EMU_EVENT_WINDOW_CLOSED     0x12

// Input    0x2
#define EMU_EVENT_INPUT_KEY         0x21    // Key Event
#define EMU_EVENT_INPUT_BUTTON      0x21    // Mouse Button Event
#define EMU_EVENT_INPUT_SCROLL      0x21    // Scroll Wheel Event
#define EMU_EVENT_INPUT_MOVED       0x21    // Pointer Moved Event

// Debug    0x3
#define EMU_EVENT_DEBUG_MESSAGE     0x31

// emu_ekey
typedef struct emu_ekey
{
    long Button, Action;
    long Repeat;
}emu_ekey;

// emu_ebutton
typedef struct emu_ebutton
{
    long Button, Action;
    long PointerX, PointerY;
}emu_ebutton;

// emu_edbgmsg 
typedef struct emu_dbgmsg
{
    long Type;
    char* Message;
}emu_edbgmsg;

// emu_event structure
typedef struct emu_event
{
    long Type;

    union
    {    
        // EMU_EVENT_WINDOW_OPENED 
        // EMU_EVENT_WINDOW_CLOSED
        //  No Event Data

        // EMU_EVENT_INPUT_KEY
        // EMU_EVENT_INPUT_BUTTON
        emu_ekey        uKeyEvent;
        emu_ebutton     uButtonEvent;

        // EMU_EVENT_DEBUG_MESSAGE
        emu_edbgmsg     uDebugMessage;
    };

}emu_event;

#endif