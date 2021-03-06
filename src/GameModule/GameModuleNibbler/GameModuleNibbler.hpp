/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/
#ifndef OOP_ARCADE_2018_GAMEMODULENIBBLER_HPP
#define OOP_ARCADE_2018_GAMEMODULENIBBLER_HPP

/**
 * @file GameModuleNibbler.hpp
 */

#include <../IGameModule.hpp>
#include <vector>
#include <unordered_map>

using namespace gameModule;

namespace gameModule
{
    class GameModuleNibbler : public IGameModule
    {
        public:
        //C_TOR
        GameModuleNibbler();

        //D_TOR
        ~GameModuleNibbler() final;

        displayModule::e_event game() final;
        bool initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset) final;
        bool setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset) final;
        void move_nibbler(int y, int x);
        void asset();
        displayModule::e_event catch_event();
        void random_apple();
        int moveNibblerCaseApple(int tmp_x, int tmp_y, int x, int y);
        bool setAsset();
        bool init_map_hard();
        bool init_map_easy();
        class PositionNibbler
        {
            public:
                PositionNibbler(int x, int y);
                ~PositionNibbler() = default;

                int _x;
                int _y;
        };

        private:
        displayModule::e_event gameLoop();
        displayModule::e_event menuLoop();
        displayModule::e_event setPlayerHighscoreLoop();
        char catchPlayercharacterName(const displayModule::e_event &event);
        void writePlayerNameInFile();
        void resetGame();
        std::vector<std::string> _map;
        std::vector<GameModuleNibbler::PositionNibbler> nibbler;
        int pos_x;
        int pos_y;
        int pos_apple_x;
        int pos_apple_y;
        size_t score;
        bool _isQuit = false;
        displayModule::e_event save_key = displayModule::e_event ::KEY_Q;
        std::shared_ptr<displayModule::IDisplayModule> display;
        int chooseMap = 0;
        std::string _playerName;
        bool _isInMenu;
        bool _isInGame;
    };
}

#endif //OOP_ARCADE_2018_GAMEMODULENIBBLER_HPP
