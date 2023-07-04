/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** effect
*/

#include "graphics.h"
#include "proportion.h"
#include <SFML/Graphics/RenderTexture.h>

void load_from_png(windowbuffer_t *window)
{
    sfTexture *texture = sfTexture_createFromFile("image.png", NULL);
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

void new_im(windowbuffer_t *window)
{
    sfRenderTexture_destroy(window->text->renderTexture);
    window->text->renderTexture = sfRenderTexture_create(
        window->width * PROPORTION_X, window->height * PROPORTION_Y, sfFalse);
    sfRenderTexture_clear(window->text->renderTexture, sfBlack);
}

void load_from_jpg(windowbuffer_t *window)
{
    sfTexture *texture = sfTexture_createFromFile("image.jpg", NULL);
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

void load_from_bmp(windowbuffer_t *window)
{
    sfTexture *texture = sfTexture_createFromFile("image.bmp", NULL);
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
