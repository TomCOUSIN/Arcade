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
    _displayModule = displayModule;
    return getAvailableGames() && loadAsset();
}

bool coreProgram::launcher::changeLibrary(const std::shared_ptr<displayModule::IDisplayModule> &displayModule)
{
    _displayModule = displayModule;
    return loadAsset();
}

bool coreProgram::launcher::loadAsset()
{
    if (!_displayModule->createText("Arcade", "Title"))
        return false;
    for (const auto &game : _availableGames) {
        if (!_displayModule->createText(game, game))
            return false;
    }
    return true;
}

bool coreProgram::launcher::getAvailableGames()
{
    DIR *directory;
    struct dirent *directoryContent;

    try {
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
    int x = 4;
    int y = 2;

    while (true) {
        switch(key_event)
        {
        case displayModule::e_event::KEY_Q: case displayModule::e_event::ESCAPE: return 0;
        case displayModule::e_event::ARROW_LEFT: return 1;
        case displayModule::e_event::ARROW_RIGHT: return 2;
        default:break;
        }
        _displayModule->drawText("Title", x, y);
        x += 10;
        y += 10;
        for (const auto &gameName : _availableGames) {
            _displayModule->drawText(gameName, x, y);
            x += 10;
        }
        _displayModule->refreshWindow();
        key_event = _displayModule->catchEvent();
        x = 4;
        y = 2;
    }
}

