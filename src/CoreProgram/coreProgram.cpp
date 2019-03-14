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
coreProgram::coreProgram() : _displayModule(nullptr),
_dlloaderDisplayModule(dlloader::DLLoader<displayModule::IDisplayModule>()),
_launcher(nullptr), _selectedGame(0)
{}

/**
 * Load the graphic library
 * @param const std::string &libPath
 * @return true if success
 * @return false if failure
 */
bool coreProgram::loadLib(const std::string &libPath)
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
bool coreProgram::getInstanceFromGraphicLibrary()
{
    try {
        _displayModule = _dlloaderDisplayModule.getInstance();
    }
    catch (const ArcadeException &arcadeException) {
        std::cerr << arcadeException.getComponent() << ": " << arcadeException.what() << std::endl;
        return false;
    }
    return true;
}

/**
 * Init the linked launcher with the linked library
 * @param void
 * @return true if success
 * @return false if failure
 */
bool coreProgram::initLauncher()
{
    try {
        _launcher = launcher(_displayModule);
    }
    catch (const ArcadeException &arcadeException) {
        std::cerr << arcadeException.getComponent() << ": " << arcadeException.what() << std::endl;
        return false;
    }
    return true;
}

/**
 * Launch the launcher and retrieve the selectedGame
 * @param void
 * @return true if success
 * @return false if failure
 */
bool coreProgram::launchLauncher()
{
    try {
        _selectedGame = _launcher.launchLauncher();
    }
    catch (const ArcadeException &arcadeException) {
        std::cerr << arcadeException.getComponent() << ": " << arcadeException.what() << std::endl;
        return false;
    }
    return true;
}
