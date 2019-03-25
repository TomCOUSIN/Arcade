/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

/**
 * @file coreProgram.cpp
 */

#include <dirent.h>
#include "coreProgram.hpp"

/**
 * Construtor wich initialize dlloader and modules
 */
coreProgram::coreProgram::coreProgram()
: _dlloaderDisplayModule(dlloader::DLLoader<displayModule::IDisplayModule>()),
_dlloaderGameModule(dlloader::DLLoader<gameModule::IGameModule>()), _launcher(),
_selectedLibrary(0)
{
    getAvailableGames();
}

/**
 * Load the graphic library
 * @param const std::string &libPath
 * @return true if success
 * @return false if failure
 */
bool coreProgram::coreProgram::loadLib(const std::string &libPath)
{
    if (!_dlloaderDisplayModule.loadLibrary(libPath) || !getInstanceFromGraphicLibrary())
        return false;
    if (libPath[0] != '.')
        _availableLibrary.emplace_back(std::string("./") + libPath);
    else
        _availableLibrary.emplace_back(libPath);
    getAvailableLibrary();
    return true;
}

/**
 * Get an instance from the linked graphic library
 * @param void
 * @return true if success
 * @return false if failure
 */
bool coreProgram::coreProgram::getInstanceFromGraphicLibrary()
{
    _displayModule = _dlloaderDisplayModule.getInstance();
    return !(_displayModule == nullptr);
}

bool coreProgram::coreProgram::getInstanceFromGameLibrary()
{
    _gameModule = _dlloaderGameModule.getInstance();
    return !(_gameModule == nullptr);
}

/**
 * Main Loop wich play launcher and games
 * @param void
 * @return 0 if success
 * @return 84 if failure
 */
size_t coreProgram::coreProgram::playCoreProgramLoop()
{
    e_returnValue launcherReturnValue = NOTHING;
    e_returnValue gameReturnValue;

    while (true) {
        launcherReturnValue = launcherLoop();
        if (launcherReturnValue == e_returnValue::QUIT)
            return 0;
        else if (launcherReturnValue == e_returnValue::ERROR)
            return 84;
        else {
            _selectedGame = _launcher.getSelectedGame();
            _displayModule->clearScreen();
        }
        gameReturnValue = gameLoop();
        if (gameReturnValue == ERROR)
            return 84;
        else if (gameReturnValue == QUIT)
            return 0;
        else {
            _displayModule->clearScreen();
            _launcher.changeLibrary(_displayModule);
        }
    }
}

/**
 * Loop wich play launcher
 * @param void
 * @return e_returnValue::LEAVE_GAME if success
 * @return e_returnValue::ERROR if failure
 */
coreProgram::e_returnValue coreProgram::coreProgram::launcherLoop()
{
    if (!_launcher.initLauncher(_displayModule, _availableLibrary))
        return ERROR;
    while (true) {
        size_t returnValue = _launcher.launchLauncher();
        switch (returnValue) {
            case 0: return QUIT;
            case 1: changeGraphicLibrary(false); _launcher.changeLibrary(_displayModule); break;
            case 2: changeGraphicLibrary(true); _launcher.changeLibrary(_displayModule); break;
            case 3: return START_GAME;
            default: break;
        }
    }
}

coreProgram::e_returnValue coreProgram::coreProgram::gameLoop()
{
    std::string gameLibraryName = "./games/" + _availableGames[_selectedGame] + "/lib_arcade_" + _availableGames[_selectedGame] + ".so";

    if (!_dlloaderGameModule.loadLibrary(gameLibraryName) || !getInstanceFromGameLibrary() || !_gameModule->initGame(_displayModule))
        return ERROR;
    while (true) {
        _displayModule->clearScreen();
        switch (_gameModule->game())
        {
        case displayModule::e_event::ARROW_LEFT: changeGraphicLibrary(false); _gameModule->setLib(_displayModule); break;
        case displayModule::e_event::ARROW_RIGHT: changeGraphicLibrary(true); _gameModule->setLib(_displayModule); break;
        case displayModule::e_event::ARROW_UP: changeGameLibrary(false); break;
        case displayModule::e_event::ARROW_DOWN: changeGameLibrary(true); break;
        case displayModule::e_event::ESCAPE: return QUIT;
        case displayModule::e_event::ERROR: return ERROR;
        default: return LEAVE_GAME;
        }
    }
}

void coreProgram::coreProgram::getAvailableLibrary()
{
    DIR *directory;
    struct dirent *directoryContent;

    directory = opendir("./lib");
    if (!directory)
        return;
    directoryContent = readdir(directory);
    while (directoryContent) {
        if (directoryContent->d_name[0] != '.' && ((std::string("./lib/") + std::string(directoryContent->d_name)) != _availableLibrary[0]))
            _availableLibrary.emplace_back((std::string("./lib/") + std::string(directoryContent->d_name)));
        directoryContent = readdir(directory);
    }
    closedir(directory);
}

void coreProgram::coreProgram::getAvailableGames()
{
    DIR *directory;
    struct dirent *directoryContent;

    directory = opendir("./games");
    if (!directory)
        return;
    directoryContent = readdir(directory);
    while (directoryContent) {
        if (directoryContent->d_name[0] != '.')
            _availableGames.emplace_back(directoryContent->d_name);
        directoryContent = readdir(directory);
    }
    closedir(directory);
}

bool coreProgram::coreProgram::changeGraphicLibrary(bool next)
{
    if (next && _selectedLibrary < _availableLibrary.size() - 1) {
        _selectedLibrary += 1;
    } else if (!next && _selectedLibrary > 0) {
        _selectedLibrary -= 1;
    } else {
        return false;
    }
    if (!_dlloaderDisplayModule.loadLibrary(_availableLibrary[_selectedLibrary]) ||
        !getInstanceFromGraphicLibrary() ||
        !_launcher.changeLibrary(_displayModule)) {
        _selectedLibrary = next ? _selectedLibrary + 1 : _selectedLibrary - 1;
        return false;
    }
    return true;
}

bool coreProgram::coreProgram::changeGameLibrary(bool next)
{
    if (next && _selectedGame < _availableGames.size() - 1) {
        _selectedGame += 1;
    } else if (!next && _selectedGame > 0) {
        _selectedGame -= 1;
    } else {
        return false;
    }
    std::string gameLibraryName = "./games/" + _availableGames[_selectedGame] + "/lib_arcade_" + _availableGames[_selectedGame] + ".so";
    if (!_dlloaderGameModule.loadLibrary(gameLibraryName)
        || !getInstanceFromGameLibrary()
        || !_gameModule->initGame(_displayModule)) {
        _selectedGame = next ? _selectedGame - 1 : _selectedGame + 1;
        return false;
    }
    return true;
}

