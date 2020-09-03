#include <emu/emu_window.h>

int main()
{
    emu_window* Window = emu_create_window("emu", 800L, 600L, 0L);
    emu_destroy_window(Window);
    
    return 0;
}