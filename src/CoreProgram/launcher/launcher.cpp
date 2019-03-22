/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include <dirent.h>
#include <zconf.h>
#include "launcherException.hpp"
#include "launcher.hpp"
#include "coreProgram.hpp"

bool coreProgram::launcher::initLauncher(const std::shared_ptr<displayModule::IDisplayModule> &displayModule)
{
    _availableGames.clear();
    _displayModule = displayModule;
    _selectedGame = 0;
    return getAvailableGames() && loadAsset();
}

bool coreProgram::launcher::changeLibrary(const std::shared_ptr<displayModule::IDisplayModule> &displayModule)
{
    _displayModule = displayModule;
    return loadAsset();
}

bool coreProgram::launcher::loadAsset()
{
    try {
        if (!_displayModule->createAsset("./.launcher", "title"))
            return false;
        for (const auto &game : _availableGames) {
            if (!_displayModule->createText(game, game))
                return false;
        }
        if (!_displayModule->createText("==>", "selector") || !_displayModule->createText("   ", "hideSelector"))
                return false;
    }
    catch (const launcherException &exception) {
        std::cerr << exception.getComponent() << ": " << exception.what() << std::endl;
        return false;
    }
    return true;
}

bool coreProgram::launcher::getAvailableGames()
{
    DIR *directory;
    struct dirent *directoryContent;

    try {
        directory = opendir("./games");
        if (!directory)
            throw launcherException("Couldn't open 'games' directory");
        directoryContent = readdir(directory);
        while (directoryContent) {
            if (directoryContent->d_name[0] != '.')
                _availableGames.emplace_back(directoryContent->d_name);
            directoryContent = readdir(directory);
        }
        closedir(directory);
        if (_availableGames.empty())
           throw launcherException("No games available");
        return true;
    }
    catch(const launcherException &exception) {
        std::cerr << exception.getComponent() << ": " << exception.what() << std::endl;
        return false;
    }

}

size_t coreProgram::launcher::launchLauncher()
{
    displayModule::e_event key_event = displayModule::e_event::NOTHING;
    std::vector<int> position = {4, 2};
    size_t gameIndex = 0;

    while (true) {
        switch(key_event)
        {
        case displayModule::e_event::KEY_Q: return 0;
        case displayModule::e_event::ESCAPE: return 0;
        case displayModule::e_event::ARROW_LEFT: return 1;
        case displayModule::e_event::ARROW_RIGHT: return 2;
        case displayModule::e_event::ENTER: return 3;
        case displayModule::e_event::ARROW_UP:
            changeSelectedGame(true);
            break;
        case displayModule::e_event::ARROW_DOWN:
            changeSelectedGame(false);
            break;
        default:break;
        }
        _displayModule->drawAsset("title", position[0], position[1]);
        position[0] += 10;
        position[1] += 10;
        for (const auto &gameName : _availableGames) {
            if (gameIndex == _selectedGame)
                _displayModule->drawText("selector", position[0] - 5, position[1]);
            else
                _displayModule->drawText("hideSelector", position[0] - 5, position[1]);
            _displayModule->drawText(gameName, position[0], position[1]);
            position[1] += 5;
            ++gameIndex;
        }
        _displayModule->refreshWindow();
        key_event = _displayModule->catchEvent();
        position[0] = 4;
        position[1] = 2;
        gameIndex = 0;
    }
}

std::string coreProgram::launcher::getSelectedGame()
{
    return _availableGames[_selectedGame];
}

void coreProgram::launcher::changeSelectedGame(bool lower)
{
    if (lower) {
        if (_selectedGame > 0)
            _selectedGame -= 1;
    }
    else {
        if (_selectedGame < _availableGames.size() - 1)
            _selectedGame += 1;
    }
}

