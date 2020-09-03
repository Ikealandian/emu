#include <emu/emu_window.h>

int main()
{
    emu_window* Window = emu_create_window("emu", 800L, 600L, 0L);

    if (!Window)
        return -1;

    while (1)
    {
        emu_poll_window(Window);
    }

    emu_destroy_window(Window);

    return 0;
}