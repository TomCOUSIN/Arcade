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
            void move_gost_red(int y, int x);
            void move_gost_blue(int y, int x);
            void move_gost_yellow(int y, int x);
            void move_gost_pink(int y, int x);
            bool init_map();
            displayModule::e_event catch_event();
            void gost_Ai();
            class PositionPacman
            {
                public:
                    PositionPacman(int x, int y);
                    ~PositionPacman() = default;

                    int _x;
                    int _y;
            };
            class PositionGostRed
            {
                public:
                PositionGostRed(int x, int y);
                ~PositionGostRed() = default;

                int _x_red;
                int _y_red;
            };
            class PositionGostBlue
            {
            public:
                PositionGostBlue(int x, int y);
                ~PositionGostBlue() = default;

                int _x_blue;
                int _y_blue;
            };
            class PositionGostYellow
            {
            public:
                PositionGostYellow(int x, int y);
                ~PositionGostYellow() = default;

                int _x_yellow;
                int _y_yellow;
            };
            class PositionGostPink
            {
            public:
                PositionGostPink(int x, int y);
                ~PositionGostPink() = default;

                int _x_pink;
                int _y_pink;
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
            std::vector<std::vector <int> > _position;
            std::vector<int> _save_position;
            std::vector<GameModulePacman::PositionPacman> pacman;
            std::vector<GameModulePacman::PositionGostRed> gost_red;
            std::vector<GameModulePacman::PositionGostBlue> gost_blue;
            std::vector<GameModulePacman::PositionGostYellow> gost_yellow;
            std::vector<GameModulePacman::PositionGostPink> gost_pink;
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
            int _gostRed_x;
            int _gostRed_y;
            int _gostBlue_x;
            int _gostBlue_y;
            int _gostYellow_x;
            int _gostYellow_y;
            int _gostPink_x;
            int _gostPink_y;
            int choosemap = 0;
            size_t score;
            bool _isQuit = false;
            std::string _playerName;
            bool _isInMenu;
            bool _isInGame;
    };
}

#endif /* !GAMEMODULEPACMAN_HPP_ */
