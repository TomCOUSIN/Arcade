/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_LAUNCHER_HPP
#define OOP_ARCADE_2018_LAUNCHER_HPP

#include <vector>
#include <unordered_map>
#include <memory>
#include "IDisplayModule.hpp"

class launcher
{
    public:
        explicit launcher(const std::shared_ptr<displayModule::IDisplayModule> &displayModule);
        ~launcher() = default;
        bool changeLibrary(const std::shared_ptr<displayModule::IDisplayModule> &displayModule);
        bool loadAsset();
        size_t launchLauncher();

    private:
        void getAvailableGames();
        std::vector<std::string> _availableGames;
        std::shared_ptr<displayModule::IDisplayModule> _displayModule;
        size_t _selectedGame;
};

#endif //OOP_ARCADE_2018_LAUNCHER_HPP
