/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** help
*/

#include "graphics.h"

static sfBool do_event_help(windowbuffer_t *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window->help_window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_setVisible(window->help_window, sfFalse);
            sfRenderWindow_setActive(window->help_window, sfFalse);
            sfRenderWindow_setActive(window->screen, sfTrue);
            return sfTrue;
        }
    }
    return sfFalse;
}

void show_help(windowbuffer_t *window)
{
    if (window->help_window == NULL)
        return;
    sfRenderWindow_setMouseCursorVisible(window->screen, sfTrue);
    sfRenderWindow_setActive(window->screen, sfFalse);
    sfRenderWindow_setActive(window->help_window, sfTrue);
    sfRenderWindow_setVisible(window->help_window, sfTrue);
    sfRenderWindow_setFramerateLimit(window->help_window, 60);
    for (;;) {
        sfRenderWindow_display(window->help_window);
        if (do_event_help(window))
            break;
    }
}
