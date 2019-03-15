/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_LAUNCHER_HPP
#define OOP_ARCADE_2018_LAUNCHER_HPP

#include <vector>
#include <memory>
#include <iostream>
#include <unordered_map>
#include "IDisplayModule.hpp"

namespace coreProgram
{

    class launcher {
        public:
            explicit launcher() = default;
            ~launcher() = default;
            bool changeLibrary(const std::shared_ptr<displayModule::IDisplayModule> &displayModule);
            bool initLauncher(const std::shared_ptr<displayModule::IDisplayModule> &displayModule);
            size_t launchLauncher();

        private:
            bool getAvailableGames();
            bool loadAsset();
            std::vector<std::string> _availableGames;
            std::shared_ptr<displayModule::IDisplayModule> _displayModule;
    };

}

#endif //OOP_ARCADE_2018_LAUNCHER_HPP
