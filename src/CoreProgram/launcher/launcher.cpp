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
        _asset.insert(std::make_pair("Title", _displayModule->createText("Arcade")));
        for (const auto &game : _availableGames) {
            _asset.insert(std::make_pair(game, _displayModule->createText(game)));
        }
        _asset.insert(std::make_pair("Selector", _displayModule->createText("->")));
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
        _displayModule->setAssetPosition(_asset["selector"], _selectedGame, 0);
        _displayModule->drawAsset(_asset["Title"]);
        for (const auto &gameName : _availableGames) {
            _displayModule->drawAsset(_asset[gameName]);
        }
        _displayModule->refreshWindow();
        key_event = _displayModule->catchEvent();
    }
    return _selectedGame;
}