/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** color
*/

#include "graphics.h"
#include "color.h"

void choose_color(windowbuffer_t *window)
{
    window->color_enum += 1;
    if (window->color_enum >= (sizeof(COLOR) / sizeof(COLOR[0])))
        window->color_enum = 0;
    window->color = COLOR[window->color_enum];
}
