#include <emu/emu_window.h>
#include <emu/emu_stack.h>

#include <stdlib.h>
#include <stdio.h>

int main()
{
    emu_stack*  WindowEvents = emu_stack_create();
    emu_window* Window = emu_window_create("emu", 800L, 600L, WindowEvents, 0L);

    int Running = 1;

    while (Running)
    {
        // Clear events and poll for new ones
        emu_stack_clear(WindowEvents);
        emu_window_poll(Window);

        // Get Events
        while (emu_stack_size(WindowEvents))
        {
            // Get First Event
            emu_event Event = emu_stack_pop(WindowEvents);
            switch (Event.Type)
            {
            case EMU_EVENT_WINDOW_CLOSED:
            {
                Running = 0;
                puts("Window Closed");
                break;
            }
            default: break;
            }
        }
    }

    emu_window_destroy(Window);
    emu_stack_destroy(WindowEvents);
    return 0;
}