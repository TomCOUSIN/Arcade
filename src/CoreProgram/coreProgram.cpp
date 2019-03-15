/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

/**
 * @file coreProgram.cpp
 */

#include "coreProgram.hpp"

/**
 * Construtor wich initialize dlloader and modules
 */
coreProgram::coreProgram::coreProgram() : _displayModule(nullptr),
_dlloaderDisplayModule(dlloader::DLLoader<displayModule::IDisplayModule>()),
_launcher(), _selectedGame(0)
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
        _dlloaderDisplayModule.loadLibrary(libPath);
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

coreProgram::e_returnValue coreProgram::coreProgram::launcherLoop()
{
    _launcher.launchLauncher();
    return ERROR;
}
