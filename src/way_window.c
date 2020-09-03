// EMU
//  Essential Multi-platform Utilities

// Wayland Window
// src/way_window.c
#include <emu/emu_window.h>

#include <stdlib.h>
#include <stdio.h>

#include <wayland-client.h>

typedef struct emu_window
{
    const char* wTitle;
    long wWidth, wHeight;
    long wFlags;

    // Wayland
    struct wl_display* display;
    struct wl_registry* registry;
    struct wl_compositor* compositor;

}emu_window;

void wayland_registry_handler
(void* data, struct wl_registry* registry, uint32_t id, const char* interface, uint32_t version)
{
    emu_window* window = (emu_window*)data;

    if (strcmp(interface, "wl_compositor") == 0)
        window->compositor = wl_registry_bind(registry, id, &wl_compositor_interface, 1);
}

void wayland_registry_remover
(void* data, struct wl_registry* registry, uint32_t id)
{
}

void wayland_setup(emu_window* _window)
{
    // Wayland connect to default display
    _window->display = wl_display_connect(NULL);

    // if display == null
    if (!_window->display)
    {
        fputs("EMU [Wayland] Window: Can't connect to display\n", stderr);
        return;
    }

    // Wayland get registry from display
    _window->registry = wl_display_get_registry(_window->display);

    // Add registry listener
    const struct wl_registry_listener registry_listener =
    {
        wayland_registry_handler,
        wayland_registry_remover
    };

    wl_registry_add_listener(_window->registry, &registry_listener, _window);

    // Wayland dispatch
    wl_display_dispatch(_window->display);
    wl_display_roundtrip(_window->display);

    // if compositor == null
    if (!_window->compositor)
    {
        fputs("EMU [Wayland] Window: Compositor == NULL\n", stderr);
        return;
    }
}

void wayland_shutdown(emu_window* _window)
{
    if (_window->display)
    {
        wl_display_disconnect(_window->display);
    }
}

void wayland_assemble_window(emu_window* _window)
{

}

emu_window* emu_create_window(const char* _title, long _width, long _height, long _flags)
{
    emu_window* eWindow = malloc(sizeof(emu_window));
    eWindow->wTitle = _title;
    eWindow->wWidth = _width;
    eWindow->wHeight = _height;
    eWindow->wFlags = _flags;

    wayland_setup(eWindow);
    wayland_assemble_window(eWindow);

    return eWindow;
}

void emu_destroy_window(emu_window* _window)
{
    wayland_shutdown(_window);
    
    // free emu_window*
    free(_window);
}