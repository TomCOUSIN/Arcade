/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_LAUNCHER_HPP
#define OOP_ARCADE_2018_LAUNCHER_HPP

#include "IDisplayModule.hpp"

class launcher
{
    public:
        explicit launcher(displayModule::IDisplayModule *displayModule);
        ~launcher() = default;

    private:
};

#endif //OOP_ARCADE_2018_LAUNCHER_HPP
