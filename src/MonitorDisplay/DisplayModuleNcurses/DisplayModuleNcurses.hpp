/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/
#ifndef OOP_ARCADE_2018_DISPLAYMODULENCURSES_HPP
#define OOP_ARCADE_2018_DISPLAYMODULENCURSES_HPP

#include "../IDisplayModule.hpp"
#include <ncurses.h>

using namespace displayModule;

namespace displayModule
{
    class DisplayModuleNcurses : public IDisplayModule
    {
        public:

        //C_TOR
        DisplayModuleNcurses();
        //D_TOR
        ~DisplayModuleNcurses() final;

        //Type of the lib
        e_type getType() const final;

        //Sprites
        void *createAsset(const std::string &path) final;
        void drawAsset(void *sprite, int x, int y) final;
        void destroyAsset(void *sprite) final;
        void drawWindow() final;

        //Events
        e_event catchEvent() final;

        //Sounds
        void start_sound() final;
        void stop_sound() final;
    };
}

#endif //OOP_ARCADE_2018_MONITORDISPLAYNCURSES_HPP
