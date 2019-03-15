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
coreProgram::coreProgram::coreProgram() : _dlloaderDisplayModule(dlloader::DLLoader<displayModule::IDisplayModule>()),
_launcher(), _selectedLibrary(0)
{}

/**
 * Load the graphic library
 * @param const std::string &libPath
 * @return true if success
 * @return false if failure
 */
bool coreProgram::coreProgram::loadLib(const std::string &libPath)
{
    try {
        if (!_dlloaderDisplayModule.loadLibrary(libPath) || !getInstanceFromGraphicLibrary())
            throw ArcadeException("Cannot load library", "coreProgram");
        _availableLibrary.emplace_back(libPath);
        getAvailableLibrary(libPath);
    }
    catch (const ArcadeException &arcadeException) {
        std::cerr << arcadeException.getComponent() << ": " << arcadeException.what() << std::endl;
        return false;
    }
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
    try {
        _displayModule = _dlloaderDisplayModule.getInstance();
    } catch (const ArcadeException &arcadeException) {
        std::cerr << arcadeException.getComponent() << ": "
            << arcadeException.what() << std::endl;
        return false;
    }
    return true;
}

/**
 * Main Loop wich play launcher and games
 * @param void
 * @return 0 if success
 * @return 84 if failure
 */
size_t coreProgram::coreProgram::playCoreProgramLoop()
{
    if (!_launcher.initLauncher(_displayModule))
        return 84;
    while (true) {
        if (launcherLoop() == e_returnValue::QUIT)
            break;
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
            case 1:
                _selectedLibrary -= 1;
                if (!_dlloaderDisplayModule.loadLibrary(std::string("./lib/") + _availableLibrary[_selectedLibrary]) || !getInstanceFromGraphicLibrary() || !_launcher.changeLibrary(_displayModule)) {
                    _selectedLibrary += 1;
                    _launcher.changeLibrary(_displayModule);
                }
                break;
            case 2:
                _selectedLibrary += 1;
                if (!_dlloaderDisplayModule.loadLibrary(std::string("./lib/") + _availableLibrary[_selectedLibrary]) || !getInstanceFromGraphicLibrary() || !_launcher.changeLibrary(_displayModule)) {
                _selectedLibrary -= 1;
                _launcher.changeLibrary(_displayModule);
            }
                break;
            case 0: return QUIT;
            default: break;
        }
    }
}

void coreProgram::coreProgram::getAvailableLibrary(const std::string &libPath)
{
    DIR *directory;
    struct dirent *directoryContent;

    directory = opendir("./lib");
    if (!directory)
        return;
    directoryContent = readdir(directory);
    while (directoryContent) {
        if (directoryContent->d_name[0] != '.' && ((std::string("./lib/") + std::string(directoryContent->d_name) != libPath)))
            _availableLibrary.emplace_back(directoryContent->d_name);
        directoryContent = readdir(directory);
    }
    closedir(directory);
}
