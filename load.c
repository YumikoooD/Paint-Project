/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** load
*/

#include "graphics.h"

void load_image(windowbuffer_t *window, char *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfVector2u size;
    sfSprite *sprite = sfSprite_create();

    if (texture != NULL && sprite != NULL) {
        size = sfTexture_getSize(texture);
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setPosition(sprite, (sfVector2f) {size.x / 2, size.y / 2});
        sfRenderTexture_destroy(window->text->renderTexture);
        window->text->renderTexture = sfRenderTexture_create(size.x, size.y,
            sfFalse);
        sfSprite_setOrigin(sprite, (sfVector2f) {size.x / 2.0, size.y / 2.0});
        sfSprite_setScale(sprite, (sfVector2f) {1, -1});
        sfRenderTexture_clear(window->text->renderTexture, sfBlack);
        sfRenderTexture_drawSprite(window->text->renderTexture, sprite, NULL);
    }
}
