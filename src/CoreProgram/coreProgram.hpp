/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_COREPROGRAM_HPP
#define OOP_ARCADE_2018_COREPROGRAM_HPP

/**
 * @file coreProgram.hpp
 */

#include <memory>
#include "DLLoader.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "launcher.hpp"

namespace coreProgram
{
    enum e_returnValue {
        QUIT,
        ERROR,
        PREV_LIB,
        NEXT_LIB,
        START_GAME,
        LEAVE_GAME,
        NOTHING
    };

    class coreProgram {
        public:
            explicit coreProgram();
            ~coreProgram() = default;
            bool loadLib(const std::string &libPath);
            size_t playCoreProgramLoop();

        private:
            bool getInstanceFromGraphicLibrary();
            bool getInstanceFromGameLibrary();
            void getAvailableLibrary();
            e_returnValue launcherLoop();
            e_returnValue gameLoop();
            std::shared_ptr<displayModule::IDisplayModule>_displayModule;
            std::shared_ptr<gameModule::IGameModule> _gameModule;
            dlloader::DLLoader<displayModule::IDisplayModule> _dlloaderDisplayModule;
            dlloader::DLLoader<gameModule::IGameModule> _dlloaderGameModule;
            std::vector<std::string> _availableLibrary;
            launcher _launcher;
            size_t _selectedLibrary;
    };
}

#endif //OOP_ARCADE_2018_COREPROGRAM_HPP
