/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/
#ifndef OOP_ARCADE_2018_IDISPLAYMODULE_HPP
#define OOP_ARCADE_2018_IDISPLAYMODULE_HPP

#include <iostream>

class IDisplayModule
{
    public:

    typedef enum e_type
    {
        UNKNOW = -1,
        ONE,
        TWO,
        THREE
    }e_type;

    /* Get type of lib
    0 -> nCurses, NDK++, aa-lib, libcaca
    1 -> Allegro, Xlib, GTK+, SFML, SDL
    2 -> OpenGL, Vulkan, Qt */

    typedef enum e_event
    {
        ERROR = - 1,
        NOTHING,
        ARROW_UP,
        ARROW_DOWN,
        ARROW_RIGHT,
        ARROW_LEFT,
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,
        SPACE,
        ENTER,
        ESCAPE
    }e_event;

    virtual e_type getType() const = 0;

    // Sprites
    virtual void *createAsset(std::string &path) = 0;
    virtual void drawAsset(void *sprite, int x, int y) = 0;
    virtual void destroyAsset(void *sprite) = 0;
    virtual void drawWindow() = 0;

    // Events
    virtual e_event catchEvent() = 0;

    // Sounds
    virtual void start_sound() = 0;
    virtual void stop_sound() = 0;
};

#endif //OOP_ARCADE_2018_IDISPLAYMODULE_HPP
