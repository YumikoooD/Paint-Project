/*
** EPITECH PROJECT, 2023
** paint
** File description:
** paint
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Window.h>
#include "graphics.h"

void print_pen(windowbuffer_t *window, sfVertexArray *vertices,
    sfEvent *event, sfRenderTexture *renderTexture)
{
    sfVector2u text_size = sfRenderTexture_getSize(renderTexture);
    sfVector2i mousePos = {.x = event->mouseMove.x, .y = event->mouseMove.y};
    sfVector2f current_pos = {mousePos.x - 1, text_size.y -
        (event->mouseMove.y - 31)};
    sfVertex vertex_two = {.position = current_pos, .color = window->color};

    if ((sfMouse_isButtonPressed(sfMouseRight) && window->tool == ERASER) ||
        (sfMouse_isButtonPressed(sfMouseLeft) && window->tool == PEN)) {
        sfVertexArray_append(vertices, vertex_two);
        sfVertexArray_setPrimitiveType(vertices, sfTrianglesStrip);
        sfRenderTexture_drawVertexArray(renderTexture, vertices, NULL);
        vertex_two.position = (sfVector2f){current_pos.x + window->x,
            current_pos.y + window->x};
        sfVertexArray_append(vertices, vertex_two);
        sfVertexArray_setPrimitiveType(vertices, sfTrianglesStrip);
        sfRenderTexture_drawVertexArray(renderTexture, vertices, NULL);
    } else {
        sfRenderTexture_drawVertexArray(renderTexture, vertices, NULL);
        sfVertexArray_clear(vertices);
    }
}

void remove_pen(windowbuffer_t *window, sfSprite *sprite, sfEvent *event,
    sfRenderTexture *renderTexture)
{
    sfVector2u text_size = sfRenderTexture_getSize(renderTexture);
    sfVector2i mousePos = {.x = event->mouseMove.x - 1,
        .y = text_size.y - (event->mouseMove.y - 31)};
    sfVector2f size = {80, 80};

    sfSprite_setScale(sprite, size);
    if ((sfMouse_isButtonPressed(sfMouseRight) && window->tool == PEN) ||
        (sfMouse_isButtonPressed(sfMouseLeft) && window->tool == ERASER)) {
        sfSprite_setPosition(sprite, (sfVector2f) {mousePos.x, mousePos.y});
        sfRenderTexture_drawSprite(renderTexture, sprite, NULL);
    }
}
