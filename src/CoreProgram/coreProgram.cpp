/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include "coreProgram.hpp"

coreProgram::coreProgram(const std::string &libPath)
{
    try {
        _dlloaderDisplayModule = dlloader::DLLoader<displayModule::IDisplayModule>();
        _dlloaderDisplayModule.loadLibrary(libPath);
        _displayModule = _dlloaderDisplayModule.getInstance();
        _dlloaderDisplayModule.closeLibrary();
    }
    catch (const ArcadeException &arcadeException) {
        std::cerr << arcadeException.getComponent() << ": " << arcadeException.what() << std::endl;
    }
}
