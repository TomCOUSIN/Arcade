/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** GameModulePacman
*/

#ifndef GAMEMODULEPACMAN_HPP_
    #define GAMEMODULEPACMAN_HPP_

#include "../IGameModule.hpp"
#include <vector>
#include <unordered_map>

using namespace gameModule;

namespace gameModule
{
    class GameModulePacman : public IGameModule{
        public:
            //C_TOR
            GameModulePacman();
            
            //D_TOR
            ~GameModulePacman() final;
            displayModule::e_event game() final;
            bool initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset) final;
            bool setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset) final;
            int scoreUp(int tmp_x, int tmp_y, int x, int y);
            bool setAsset();
            void asset();
            void move_pacman(int y, int x);
            bool init_map();
            displayModule::e_event catch_event();
            class PositionPacman
            {
            public:
                PositionPacman(int x, int y);
                ~PositionPacman() = default;

                int _x;
                int _y;
            };

        protected:
        private:
            displayModule::e_event menuLoop();
            displayModule::e_event gameloop();
            displayModule::e_event setPlayerHighscoreLoop();
            char catchPlayercharacterName(const displayModule::e_event &event);
            void writePlayerNameInFile();
            void resetGame();
            displayModule::e_event save_key = displayModule::e_event ::KEY_Q;
            std::vector<std::string> _map;
            std::vector<GameModulePacman::PositionPacman> pacman;
            std::shared_ptr<displayModule::IDisplayModule> display;
            int pos_pacball_one_x;
            int pos_pacball_one_y;
            int pos_pacball_two_x;
            int pos_pacball_two_y;
            int pos_pacball_three_x;
            int pos_pacball_three_y;
            int pos_pacball_four_x;
            int pos_pacball_four_y;
            int pos_x;
            int pos_y;
            int choosemap = 0;
            size_t score;
            bool _isQuit = false;
            std::string _playerName;
            bool _isInMenu;
            bool _isInGame;
    };
}

extern "C"
{
    gameModule::GameModulePacman *allocator()
    {
        return new gameModule::GameModulePacman();
    }

    void deleter(gameModule::GameModulePacman *ptr)
    {
        delete ptr;
    }
}
#endif /* !GAMEMODULEPACMAN_HPP_ */
