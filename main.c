/*
** EPITECH PROJECT, 2022
** My paint
** File description:
** main file
*/

#include <unistd.h>
#include <stdlib.h>
#include "graphics.h"
#include "my.h"
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Types.h>
#include <SFML/System/Time.h>
#include "help.h"

int help(void)
{
    write(1, HELP, my_strlen(HELP));
    return 0;
}

static void show_image(windowbuffer_t *window)
{
    const sfTexture *texture =
        sfRenderTexture_getTexture(window->text->renderTexture);
    sfSprite *sprite = sfSprite_create();
    sfVector2f pos = sfRectangleShape_getPosition(
        window->menu->options->option->menu->button->rect);
    sfVector2f size = sfRectangleShape_getSize(
        window->menu->options->option->menu->button->rect);

    sfSprite_setTexture(sprite, texture, sfTrue);
    pos.y += size.y + 1;
    pos.x += 1;
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window->screen, sprite, NULL);
    sfSprite_destroy(sprite);
}

static void make_loop(windowbuffer_t *window, sfSprite *sprite)
{
    sfEvent event;
    sfVector2i mousePos;

    while (sfRenderWindow_isOpen(window->screen)) {
        sfRenderWindow_clear(window->screen, sfLightGray);
        while (sfRenderWindow_pollEvent(window->screen, &event))
            events_tests(&event, window);
        show_image(window);
        show_menu(window->screen, window->menu);
        if ((window->tool == PEN && !sfMouse_isButtonPressed(sfMouseRight)) ||
            (window->tool == ERASER && sfMouse_isButtonPressed(sfMouseRight))) {
            mousePos = sfMouse_getPositionRenderWindow(window->screen);
            sfSprite_setPosition(sprite, (sfVector2f){mousePos.x, mousePos.y});
            sfRenderWindow_setMouseCursorVisible(window->screen, sfFalse);
            sfRenderWindow_drawSprite(window->screen, sprite, NULL);
        } else
            sfRenderWindow_setMouseCursorVisible(window->screen, sfTrue);
        sfRenderWindow_display(window->screen);
    };
}

int main(int argv, char **argc)
{
    windowbuffer_t *window;
    sfVideoMode desktop = sfVideoMode_getDesktopMode();

    if (argv > 1 && !(my_strcmp(argc[1], "-h") && my_strcmp(argc[1], "--help")))
        return help();
    if (argv != 1 && argv != 2)
        return 84;
    window = make_window_size(desktop.width, desktop.height, "Paint");
    sfSprite *sprite = load_pen();
    if (window == NULL)
        return 84;
    if (argv == 2)
        load_image(window, argc[1]);
    make_loop(window, sprite);
    window_cleanup(window);
    return 0;
}

sfSprite *load_pen(void)
{
    sfTexture* texture = sfTexture_createFromFile("Files/pen.png", NULL);
    sfSprite* sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfVector2f scale = {0.1, 0.1};
    sfSprite_scale(sprite, scale);

    return sprite;
}
