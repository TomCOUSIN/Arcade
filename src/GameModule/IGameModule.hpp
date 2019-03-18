/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/
#ifndef OOP_ARCADE_2018_IGAMEMODULE_HPP
#define OOP_ARCADE_2018_IGAMEMODULE_HPP

#include <iostream>
#include <bits/shared_ptr.h>
#include "IDisplayModule.hpp"

namespace gameModule
{
    class IGameModule
    {
        public:
            virtual ~IGameModule() = default;
            virtual displayModule::e_event game() = 0;
            virtual bool initGame(std::shared_ptr<displayModule::IDisplayModule> asset) = 0;
            virtual bool setLib(std::shared_ptr<displayModule::IDisplayModule> asset) = 0;
    };
}

#endif //OOP_ARCADE_2018_IGAMEMODULE_HPP
