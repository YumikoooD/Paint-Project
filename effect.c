/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** effect
*/

#include "graphics.h"
#include <SFML/Graphics/RenderTexture.h>

void select_pen(windowbuffer_t *window)
{
    window->tool = PEN;
}

void select_eraser(windowbuffer_t *window)
{
    window->tool = ERASER;
}

void close_window(windowbuffer_t *window)
{
    sfRenderWindow_close(window->screen);
}
