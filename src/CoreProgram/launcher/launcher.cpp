/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include <dirent.h>
#include <zconf.h>
#include <vector>
#include "launcherException.hpp"
#include "launcher.hpp"
#include "coreProgram.hpp"

bool coreProgram::launcher::initLauncher(const std::shared_ptr<displayModule::IDisplayModule> &displayModule, const std::vector<std::string> &graphicLibrariesNames)
{
    _availableGames.clear();
    _availableLibrary.clear();
    _availableLibrary = graphicLibrariesNames;
    _displayModule = displayModule;
    _selectedGame = 0;
    _selectedLibrary = 0;
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
        loadInformationAsset();
        loadAvailableGameAsset();
        loadAvailableLibraryAsset();
        if (!_displayModule->createText("==>", "gameSelector") || !_displayModule->createText("==>", "librarySelector") || !_displayModule->createText("   ", "hideSelector"))
            return false;
    }
    catch (const launcherException &exception) {
        std::cerr << exception.getComponent() << ": " << exception.what() << std::endl;
        return false;
    }
    return true;
}

bool coreProgram::launcher::loadInformationAsset()
{
    if (!_displayModule->createText("Press 'ESCAPE' to leave the program.", "leaveInfo"))
        return false;
    if (!_displayModule->createText("Press '>' to change to the next graphical library.", "nextGraphicLibraryInfo"))
        return false;
    if (!_displayModule->createText("Press '<' to change to the previous graphical library.", "previousGraphicLibraryInfo"))
        return false;
    if (!_displayModule->createText("Press '/\\' to change to the previous game.", "previousGameInfo"))
        return false;
    return _displayModule->createText("Press '\\/' to change to the next game.", "nextGameInfo");
}

bool coreProgram::launcher::loadAvailableGameAsset()
{
    for (const auto &game : _availableGames) {
        if (!_displayModule->createText(game, game))
            return false;
    }
    return true;
}

bool coreProgram::launcher::loadAvailableLibraryAsset()
{
    for (const auto &graphicLibrary : _availableLibrary) {
        if (!_displayModule->createText(graphicLibrary, graphicLibrary))
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

    while (true) {
        key_event = _displayModule->catchEvent();
        switch(key_event)
        {
        case displayModule::e_event::KEY_Q: return 0;
        case displayModule::e_event::ESCAPE: return 0;
        case displayModule::e_event::ARROW_LEFT: changeSelectedLibrary(true); return 1;
        case displayModule::e_event::ARROW_RIGHT: changeSelectedLibrary(false); return 2;
        case displayModule::e_event::ENTER: return 3;
        case displayModule::e_event::ARROW_UP: changeSelectedGame(true); break;
        case displayModule::e_event::ARROW_DOWN: changeSelectedGame(false); break;
        default:break;
        }
        _displayModule->drawAsset("title", 4, 2);
        displayAvailableGames();
        displayAvailableGraphicLibraries();
        displayInfo();
        _displayModule->refreshWindow();
    }
}

size_t coreProgram::launcher::getSelectedGame()
{
    return _selectedGame;
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

void coreProgram::launcher::changeSelectedLibrary(bool lower)
{
    if (lower) {
        if (_selectedLibrary > 0)
            _selectedLibrary -= 1;
    }
    else {
        if (_selectedLibrary < _availableLibrary.size() - 1)
            _selectedLibrary += 1;
    }
}

void coreProgram::launcher::displayAvailableGames()
{
    std::vector<int> position = {14, 12};
    size_t gameIndex = 0;

    for (const auto &gameName : _availableGames) {
        if (gameIndex == _selectedGame) {
            _displayModule->drawText("gameSelector", position[0] - 5, position[1]);
        }
        else {
            _displayModule->drawText("hideSelector", position[0] - 5, position[1]);
        }
        _displayModule->drawText(gameName, position[0], position[1]);
        position[1] += 5;
        ++gameIndex;
    }
}

void coreProgram::launcher::displayAvailableGraphicLibraries()
{
    std::vector<int> position = {30, 12};
    size_t libraryIndex = 0;

    for (const auto &graphicLibraryName : _availableLibrary) {
        if (libraryIndex == _selectedLibrary) {
            _displayModule->drawText("librarySelector", position[0] - 5, position[1]);
        }
        else {
            _displayModule->drawText("hideSelector", position[0] - 5, position[1]);
        }
        _displayModule->drawText(graphicLibraryName, position[0], position[1]);
        position[1] += 5;
        ++libraryIndex;
    }
}

void coreProgram::launcher::displayInfo()
{
    _displayModule->drawText("nextGraphicLibraryInfo", 70, 12);
    _displayModule->drawText("previousGraphicLibraryInfo", 70, 14);
    _displayModule->drawText("previousGameInfo", 70, 16);
    _displayModule->drawText("nextGameInfo", 70, 18);
    _displayModule->drawText("leaveInfo", 70, 20);
}

