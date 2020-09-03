// EMU
//  Essential Multi-platform Utilities

// emu/emu_events.h
#ifndef _EMU_EVENTS_H_
#define _EMU_EVENTS_H_

// EMU Events

// Window   0x0
#define EMU_WINDOW_OPENED   0x01
#define EMU_WINDOW_CLOSED   0x02

// Debug    0x1
#define EMU_DEBUG_MESSAGE   0x11

// emu_event structure
typedef struct emu_event
{
    long eType;

    union
    {
        struct
        {
            long Type;
            char* Message;
        }DebugMessage;
        
    };

}emu_event;

#endif