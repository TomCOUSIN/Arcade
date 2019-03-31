/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_LAUNCHER_HPP
#define OOP_ARCADE_2018_LAUNCHER_HPP

/**
 * @file launcher.hpp
 */

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
            bool initLauncher(const std::shared_ptr<displayModule::IDisplayModule> &displayModule, const std::vector<std::string> &graphicLibrariesNames);
            size_t launchLauncher();
            size_t getSelectedGame();
            void setSelectedLibrary(size_t selectedLibrary);

        private:
            void changeSelectedGame(bool lower);
            void changeSelectedLibrary(bool lower);
            bool getAvailableGames();
            void displayInfo();
            void displayAvailableGames();
            void displayAvailableGraphicLibraries();
            void displayHighScore();
            bool loadAsset();
            bool loadHighScoreAsset();
            bool loadInformationAsset();
            bool loadAvailableGameAsset();
            bool loadAvailableLibraryAsset();
            std::vector<std::string> retrieveHighscore(const std::string &path);
            std::vector<std::string> sortHighscore(const std::vector <std::string> &highscore);
            size_t findHigherScore(const std::vector<std::string> &highscore, size_t size);
            std::vector<std::string> splitString(const std::string &stringToParse, char delimiter);
            std::vector<std::string> _availableGames;
            std::vector<std::string> _availableLibrary;
            std::shared_ptr<displayModule::IDisplayModule> _displayModule;
            size_t _selectedLibrary;
            size_t _selectedGame;
    };

}

#endif //OOP_ARCADE_2018_LAUNCHER_HPP
