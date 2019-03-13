/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_COREPROGRAM_HPP
#define OOP_ARCADE_2018_COREPROGRAM_HPP

#include <memory>
#include "DLLoader.hpp"
#include "IDisplayModule.hpp"

class coreProgram
{
    public:
        explicit coreProgram(const std::string &libPath);
        ~coreProgram() = default;

    private:
        std::shared_ptr<displayModule::IDisplayModule> _displayModule;
        dlloader::DLLoader<displayModule::IDisplayModule> _dlloaderDisplayModule;
};

#endif //OOP_ARCADE_2018_COREPROGRAM_HPP
