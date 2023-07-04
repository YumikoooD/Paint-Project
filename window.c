/*
** EPITECH PROJECT, 2022
** My paint
** File description:
** Create window
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Time.h>
#include "my.h"
#include "text.h"
#include "color.h"
#include "proportion.h"
#include "graphics.h"

static text_t *load_text(unsigned int width, unsigned int height)
{
    sfUint8 pixels[] = {0, 0, 0, 255};
    text_t *text = malloc(sizeof(text_t));

    if (text == NULL)
        return NULL;
    text->texture = sfTexture_create(1, 1);
    text->sprite = sfSprite_create();
    sfSprite_setTexture(text->sprite, text->texture, sfTrue);
    text->vertices = sfVertexArray_create();
    text->texture2 = sfTexture_create(10, 10);
    text->sprite2 = sfSprite_create();
    sfSprite_setTexture(text->sprite2, text->texture2, sfTrue);
    text->vertices2 = sfVertexArray_create();
    sfTexture_updateFromPixels(text->texture2, pixels, 1, 1, 0, 0);
    text->renderTexture = sfRenderTexture_create(width, height, sfFalse);
    sfRenderTexture_clear(text->renderTexture, sfBlack);
    return text;
}

static void make_const_windows(windowbuffer_t *window)
{
    sfTexture *help_text = sfTexture_createFromFile("./Files/help.png",
        NULL);
    sfSprite *sprite = sfSprite_create();

    if (help_text == NULL || sprite == NULL) {
        window->help_window = NULL;
    } else {
        window->help_window = sfRenderWindow_create((sfVideoMode)
            {450, 450, 32}, "Help", sfClose | sfTitlebar, NULL);
        sfSprite_setPosition(sprite, (sfVector2f) {0, 0});
        sfSprite_setScale(sprite, (sfVector2f) {1.13, 1.13});
        sfSprite_setTexture(sprite, help_text, sfTrue);
        sfRenderWindow_drawSprite(window->help_window, sprite, NULL);
        sfRenderWindow_setActive(window->help_window, sfFalse);
        sfRenderWindow_setVisible(window->help_window, sfFalse);
    }
    sfTexture_destroy(help_text);
    sfSprite_destroy(sprite);
}

static void set_screen(windowbuffer_t *window, unsigned int width,
    unsigned int height, char *title)
{
    window->height = height;
    window->width = width;
    window->color_enum = 0;
    window->color = COLOR[0];
    window->screen = sfRenderWindow_create((sfVideoMode) {window->width,
        window->height, 32}, title, sfClose | sfResize | sfTitlebar, NULL);
    sfRenderWindow_display(window->screen);
    sfRenderWindow_setFramerateLimit(window->screen, 60);
    window->view = sfView_copy(sfRenderWindow_getDefaultView(window->screen));
    make_const_windows(window);
}

windowbuffer_t *make_window_size(unsigned int width,
    unsigned int height, char *title)
{
    windowbuffer_t *window = malloc(sizeof(windowbuffer_t) + 1);
    void *constant = malloc(sizeof(void *) * SIZE_CONSTANTS);

    if (window == NULL || constant == NULL) {
        free(constant);
        free(window);
        return NULL;
    }
    window->tool = PEN;
    window->text = load_text(width * PROPORTION_X, height * PROPORTION_Y);
    window->constant = constant;
    window->constant[ARIAL] = sfFont_createFromFile(ARIAL_FILE);
    set_screen(window, width, height, title);
    window->menu = generated_menu_bar(window->constant);
    window->menu->state = LOCKED_OPEN;
    window->x = 1;
    return window;
}
