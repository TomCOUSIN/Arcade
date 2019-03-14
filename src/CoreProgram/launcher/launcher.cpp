/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include "ArcadeException.hpp"
#include "launcherException.hpp"
#include "launcher.hpp"
#include <dirent.h>

launcher::launcher(
    const std::shared_ptr<displayModule::IDisplayModule> &displayModule)
{
    try {
        _displayModule = displayModule;
        getAvailableGames();
    }
    catch (const ArcadeException &arcadeException) {
        std::cerr << arcadeException.getComponent() << ": " << arcadeException.what() << std::endl;
    }
}

bool launcher::changeLibrary(
    const std::shared_ptr<displayModule::IDisplayModule> &displayModule
)
{
    _displayModule = displayModule;
    return loadAsset();
}

bool launcher::loadAsset()
{
    try {
        _displayModule->createText("Arcade", "Title");
        for (const auto &game : _availableGames) {
            _displayModule->createText(game, game);
        }
        _displayModule->createText("->", "Selector");
    }
    catch (const ArcadeException &arcadeException) {
        std::cerr << arcadeException.getComponent() << ": " << arcadeException.what() << std::endl;
        return false;
    }
    return true;
}

void launcher::getAvailableGames()
{
    DIR *directory;
    struct dirent *directoryContent;

    directory = opendir("./Games");
    if (!directory)
        throw launcherException("Couldn't open 'Games' directory");
    directoryContent = readdir(directory);
    while (directoryContent) {
        if (directoryContent->d_name[0] != '.')
            _availableGames.emplace_back(directoryContent->d_name);
        directoryContent = readdir(directory);
    }
    closedir(directory);
}

size_t launcher::launchLauncher()
{
    displayModule::e_event key_event = displayModule::e_event::NOTHING;

    while (key_event != displayModule::e_event::ENTER) {
        if (key_event == displayModule::e_event::ARROW_LEFT) {
            _selectedGame = _selectedGame - 1;
        }
        else if (key_event == displayModule::e_event::ARROW_RIGHT) {
            _selectedGame = _selectedGame + 1 > _availableGames.size() ? _availableGames.size() : _selectedGame + 1;
        }
        _displayModule->drawAsset("Title", 0, 0);
        _displayModule->drawAsset("Selector", static_cast<int>(_selectedGame), 0);
        for (const auto &gameName : _availableGames) {
            _displayModule->drawAsset(gameName, 0, 0);
        }
        _displayModule->refreshWindow();
        key_event = _displayModule->catchEvent();
    }
    return _selectedGame;
}