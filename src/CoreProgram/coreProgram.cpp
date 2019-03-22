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
{}

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
    bool isInLauncher = true;

    if (!_launcher.initLauncher(_displayModule))
        return 84;
    while (true) {
        if (isInLauncher) {
            launcherReturnValue = launcherLoop();
            if (launcherReturnValue == e_returnValue::QUIT)
                return 0;
            isInLauncher = false;
            _displayModule->clearScreen();
            _dlloaderGameModule.loadLibrary(std::string("./games/") + _launcher.getSelectedGame() + std::string("/lib_arcade_") + _launcher.getSelectedGame() + std::string(".so"));
            getInstanceFromGameLibrary();
            _gameModule->initGame(_displayModule);
        }
        else {
            gameReturnValue = gameLoop();
            if (gameReturnValue == ERROR)
                return 84;
            else if (gameReturnValue == QUIT)
                return 0;
            else {
                isInLauncher = true;
                _displayModule->clearScreen();
                _launcher.changeLibrary(_displayModule);
            }
        }
    }
    return 0;
}

/**
 * Loop wich play launcher
 * @param void
 * @return e_returnValue::LEAVE_GAME if success
 * @return e_returnValue::ERROR if failure
 */
coreProgram::e_returnValue coreProgram::coreProgram::launcherLoop()
{
    while (true) {
        size_t returnValue = _launcher.launchLauncher();
        switch (returnValue) {
            case 0: return QUIT;
            case 1:
                if (_selectedLibrary > 0) {
                    _selectedLibrary -= 1;
                    if (!_dlloaderDisplayModule.loadLibrary(_availableLibrary[_selectedLibrary]) ||
                        !getInstanceFromGraphicLibrary() ||
                        !_launcher.changeLibrary(_displayModule)) {
                        _selectedLibrary += 1;
                        _launcher.changeLibrary(_displayModule);
                    }
                }
                break;
            case 2:
                if (_selectedLibrary < _availableLibrary.size() - 1) {
                    _selectedLibrary += 1;
                    if (!_dlloaderDisplayModule.loadLibrary(_availableLibrary[_selectedLibrary]) ||
                        !getInstanceFromGraphicLibrary() ||
                        !_launcher.changeLibrary(_displayModule)) {
                        _selectedLibrary -= 1;
                        _launcher.changeLibrary(_displayModule);
                    }
                }
                break;
            case 3: return START_GAME;
            default: break;
        }
    }
}

coreProgram::e_returnValue coreProgram::coreProgram::gameLoop()
{
    while (true) {
        switch (_gameModule->game())
        {
            case displayModule::e_event::ESCAPE: return QUIT;
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
