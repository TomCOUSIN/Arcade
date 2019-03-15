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
#include "launcher.hpp"

namespace coreProgram
{
    enum e_returnValue {
        QUIT,
        ERROR,
        PREV_LIB,
        NEXT_LIB,
        LEAVE_GAME
    };

    class coreProgram {
        public:
            explicit coreProgram();
            ~coreProgram() = default;
            bool loadLib(const std::string &libPath);
            bool getInstanceFromGraphicLibrary();
            size_t playCoreProgramLoop();

        private:
            e_returnValue launcherLoop();
            e_returnValue gameLoop();
            std::shared_ptr<displayModule::IDisplayModule> _displayModule;
            dlloader::DLLoader<displayModule::IDisplayModule> _dlloaderDisplayModule;
            launcher _launcher;
            size_t _selectedGame;
    };
}

#endif //OOP_ARCADE_2018_COREPROGRAM_HPP
