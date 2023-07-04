/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-mypaint-mikael.sourati
** File description:
** effect
*/

#include "graphics.h"
#include <SFML/Graphics/RenderTexture.h>

void save_to_jpg(windowbuffer_t *window)
{
    sfImage *image;
    const sfTexture *texture =
        sfRenderTexture_getTexture(window->text->renderTexture);
    sfVector2u size = sfTexture_getSize(texture);

    image = sfImage_create(size.x, size.y);
    image = sfTexture_copyToImage(texture);
    sfImage_saveToFile(image, "image.jpg");
    sfImage_destroy(image);
}

void save_to_png(windowbuffer_t *window)
{
    sfImage *image;
    const sfTexture *texture =
        sfRenderTexture_getTexture(window->text->renderTexture);
    sfVector2u size = sfTexture_getSize(texture);

    image = sfImage_create(size.x, size.y);
    image = sfTexture_copyToImage(texture);
    sfImage_saveToFile(image, "image.png");
    sfImage_destroy(image);
}

void save_to_bmp(windowbuffer_t *window)
{
    sfImage *image;
    const sfTexture *texture =
        sfRenderTexture_getTexture(window->text->renderTexture);
    sfVector2u size = sfTexture_getSize(texture);

    image = sfImage_create(size.x, size.y);
    image = sfTexture_copyToImage(texture);
    sfImage_saveToFile(image, "image.bmp");
    sfImage_destroy(image);
}
