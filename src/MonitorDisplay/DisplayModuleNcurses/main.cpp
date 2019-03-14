/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/

#include <memory.h>
#include "IDisplayModule.hpp"
#include "DisplayModuleNcurses/DisplayModuleNcurses.hpp"

int main(int ac, char **av)
{
    (void) ac;
    (void) av;

    IDisplayModule *display = new displayModule::DisplayModuleNcurses();

    display->createText("Hello", "HELLO");
    while (1) {
        if (display->catchEvent() == ESCAPE)
            break;
        display->drawText("HELLO", 12, 12);
        display->refreshWindow();
    }
    display->refreshWindow();
    delete display;
    return 0;
}