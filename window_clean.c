/*
** EPITECH PROJECT, 2022
** My paint
** File description:
** Remove window
*/

#include "graphics.h"
#include <stdlib.h>
#include <SFML/Window.h>

void window_cleanup(windowbuffer_t *window)
{
    if (sfRenderWindow_isOpen(window->screen) == sfTrue)
        sfRenderWindow_close(window->screen);
    sfView_destroy(window->view);
    sfRenderWindow_destroy(window->screen);
    destroy_drop_menu(window->menu);
    sfFont_destroy(window->constant[ARIAL]);
    free(window);
}
