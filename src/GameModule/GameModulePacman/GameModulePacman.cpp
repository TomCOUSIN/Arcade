/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** GameModulePacman
*/

#include "GameModulePacman.hpp"
#include <fstream>
#include <map>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory>
#include "IDisplayModule.hpp"
#include "GameModulePacmanException.hpp"
#include <chrono>
#include <thread>

GameModulePacman::PositionPacman::PositionPacman(int x, int y) : _x(x), _y(y)
{}

GameModulePacman::GameModulePacman() : _playerName("___")
{
    pos_pacball_one_x = 1;
    pos_pacball_one_y = 1;
    pos_pacball_two_x = 18;
    pos_pacball_two_y = 3;
    pos_pacball_three_x = 18;
    pos_pacball_three_y = 19;
    pos_pacball_four_x = 1;
    pos_pacball_four_y = 21;
    pacman.emplace_back(PositionPacman(17, 9));
    pos_x = 7;
    pos_y = 17;
    _isInMenu = true;
    _isInGame = false;
}

GameModulePacman::~GameModulePacman() {}

int GameModulePacman::scoreUp(int tmp_x, int tmp_y, int x, int y)
{
    int tmp2_x = 0;
    int tmp2_y = 0;

    if ((x == pos_pacball_one_x && y == pos_pacball_one_y) ||
        (x == pos_pacball_two_x && y == pos_pacball_two_y) ||
        (x == pos_pacball_three_x && y == pos_pacball_three_y) ||
        (x == pos_pacball_four_x && y == pos_pacball_four_y)) {
        for (auto &index : pacman) {
            tmp2_x = index._x;
            tmp2_y = index._y;
            index._x = tmp_x;
            index._y = tmp_y;
            tmp_x = tmp2_x;
            tmp_y = tmp2_y;
    }
        display->drawAsset("space", tmp_x, tmp_y);
        pacman.emplace_back(PositionPacman(tmp_x, tmp_y));
        score += 10;
        pos_x = x;
        pos_y = y;
        return -1;
    }
    return 0;
}

void GameModulePacman::move_pacman(int y, int x)
{
    int tmp_x = x;
    int tmp_y = y;
    int tmp2_x = 0;
    int tmp2_y = 0;

    if (scoreUp(tmp_x, tmp_y, x, y) == -1)
        return;
    if (_map[y][x] == '#')
        return;
    else if (_map[y][x] == '.') {
        for (auto &i : pacman) {
            tmp2_x = i._x;
            tmp2_y = i._y;
            i._x = tmp_x;
            i._y = tmp_y;
            tmp_x = tmp2_x;
            tmp_y = tmp2_y;
        }
        _map[y][x] = ' ';
        display->createAsset("games/pacman/assets/", "map_pacman");
        display->drawAsset("space", tmp_x, tmp_y);
        score += 1;
    }
    else if (_map[y][x] == ' ') {
        for (auto &i : pacman) {
            tmp2_x = i._x;
            tmp2_y = i._y;
            i._x = tmp_x;
            i._y = tmp_y;
            tmp_x = tmp2_x;
            tmp_y = tmp2_y;
        }
    }
    pos_x = x;
    pos_y = y;
    return;
}

displayModule::e_event GameModulePacman::catch_event()
{
    displayModule::e_event key = display->catchEvent();

    if (key == displayModule::ESCAPE || key == displayModule::ARROW_RIGHT
    || key == displayModule::ARROW_LEFT) {
        return key;
    }
    if (key == displayModule::KEY_Z) {
        move_pacman(pos_y - 1, pos_x);
        save_key = key;
        return key;
    }
    if (key == displayModule::KEY_D) {
        move_pacman(pos_y, pos_x + 1);
        save_key = key;
        return key;
    }
    if (key == displayModule::KEY_S) {
        move_pacman(pos_y + 1, pos_x);
        save_key = key;
        return key;
    }
    if (key == displayModule::KEY_Q) {
        move_pacman(pos_y, pos_x - 1);
        save_key = key;
        return key;
    }
    else {
        if (save_key == displayModule::KEY_Z) {
            move_pacman(pos_y - 1, pos_x);
            return displayModule::NOTHING;
        }
        if (save_key == displayModule::KEY_D) {
            move_pacman(pos_y, pos_x + 1);
            return displayModule::NOTHING;
        }
        if (save_key == displayModule::KEY_S) {
            move_pacman(pos_y + 1, pos_x);
            return displayModule::NOTHING;
        }
        if (save_key == displayModule::KEY_Q) {
            move_pacman(pos_y, pos_x - 1);
            return displayModule::NOTHING;
        }
    }
    return key;
}

void GameModulePacman::asset()
{
    size_t i = 0;
    display->drawAsset("pacball", pos_pacball_one_x, pos_pacball_one_y);
    display->drawAsset("pacball", pos_pacball_two_x, pos_pacball_two_y);
    display->drawAsset("pacball", pos_pacball_three_x, pos_pacball_three_y);
    display->drawAsset("pacball", pos_pacball_four_x, pos_pacball_four_y);
    display->drawAsset("head_pacman", pacman[i]._x, pacman[i]._y);
}

displayModule::e_event GameModulePacman::game()
{
    displayModule::e_event event;

    while (true) {
        if (_isInMenu) {
            display->clearScreen();
            event = menuLoop();
            switch (event)
            {
            case displayModule::e_event::ARROW_LEFT: return event;
            case displayModule::e_event::ARROW_RIGHT: return event;
            case displayModule::e_event::ARROW_UP: return event;
            case displayModule::e_event::ARROW_DOWN: return event;
            case displayModule::e_event::ESCAPE: return event;
            case displayModule::e_event::ERROR: return event;
            case displayModule::e_event::KEY_L: return event;
            default: _isInMenu = false; _isInGame = true; break;
            }
        }
        else if (_isInGame) {
            display->clearScreen();
            event = gameloop();
            switch (event)
            {
            case displayModule::e_event::ARROW_LEFT: return event;
            case displayModule::e_event::ARROW_RIGHT: return event;
            case displayModule::e_event::ESCAPE: return event;
            case displayModule::e_event::ERROR: return event;
            default: _isInGame = false; break;
            }
        }
        else {
            display->clearScreen();
            event = setPlayerHighscoreLoop();
            switch (event)
            {
            case displayModule::e_event::ARROW_LEFT: return event;
            case displayModule::e_event::ARROW_RIGHT: return event;
            case displayModule::e_event::ESCAPE: return event;
            case displayModule::e_event::ERROR: return event;
            default: _isInMenu = true; break;
            }
        }
    }  
}

displayModule::e_event GameModulePacman::gameloop()
{
    displayModule::e_event key_return = displayModule::e_event::NOTHING;

    while (!_isQuit) {
        if (choosemap == 1) {
            display->drawAsset("map_pacman", 0, 0);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        key_return = catch_event();
        if (key_return == displayModule::ESCAPE || key_return == displayModule::ARROW_LEFT
        || key_return == displayModule::ARROW_RIGHT) {
            return key_return;
        }
        asset();
        std::string _score = std::string("Score: ") + std::to_string(score);
        display->createText(_score, "score");
        display->drawText("score", 0, 40);
        display->refreshWindow();
    }
    display->refreshWindow();
    return displayModule::e_event::NOTHING;
}

bool GameModulePacman::initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
    return setLib(asset);
}

bool GameModulePacman::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
    display = asset;
    return setAsset();
}

bool GameModulePacman::init_map()
{
    std::fstream file("games/pacman/assets/1d/map_pacman.txt", std::fstream::in);
    std::string line;
    try {
        _map.clear();
        if (file.is_open()) {
            while (getline(file, line, '\n'))
                _map.push_back(line);
        } else {
            throw (GameModulePacmanException("Can't open the file."));
        }
        file.close();

    }
    catch (GameModulePacmanException &exception) {
        std::cerr << exception.what() << std::endl;
        return false;
    }
    return true;
}

bool GameModulePacman::setAsset()
{
    if (!display->createAsset("games/pacman/assets/", "map_pacman"))
        return false;
    if (!display->createText("Score: ", "playerScore"))
        return false;
    if (!display->createText("Enter your player name: ", "playerNameRequest"))
        return false;
    if (!display->createAsset("games/pacman/assets/", "title_pacman"))
        return false;
    if (!display->createText("How To Play:", "htp_pacman"))
        return false;
    if (!display->createText("-The aim of the pacman is to get all the pacball in the map.", "1rules_pacman"))
        return false;
    if (!display->createText("-If pacman touch one gost, the game is over.", "2rules_pacman"))
        return false;
    if (!display->createText("-Press E to play the game.", "start_game"))
        return false;
    if (!display->createAsset("games/pacman/assets/", "head_pacman"))
        return false;
    if (!display->createAsset("games/pacman/assets/", "space"))
        return false;    
    return display->createAsset("games/pacman/assets/", "pacball");
}

displayModule::e_event GameModulePacman::menuLoop()
{
    displayModule::e_event key_return = displayModule::e_event::NOTHING;
    resetGame();
    while (true) {
        display->drawAsset("title_pacman", 0, 0);
        display->drawText("htp_pacman", 20, 13);
        display->drawText("1rules_pacman", 24, 16);
        display->drawText("2rules_pacman", 24, 18);
        display->drawText("start_game", 24, 26);
        key_return = display->catchEvent();
        if (key_return == displayModule::KEY_E) {
            if (!init_map())
                return displayModule::e_event::ERROR;
            choosemap = 1;
            _isQuit = false;
            save_key = displayModule::e_event::KEY_Q;
            return displayModule::e_event::ENTER;
        } else if (key_return == displayModule::ESCAPE || key_return == displayModule::ARROW_LEFT
            || key_return == displayModule::ARROW_RIGHT || key_return == displayModule::ARROW_UP
            || key_return == displayModule::ARROW_DOWN || key_return == displayModule::KEY_L)
            return key_return;
        display->refreshWindow();
    }
}

void GameModulePacman::resetGame()
{
    pacman.clear();
    pos_pacball_one_x = 1;
    pos_pacball_one_y = 1;
    pos_pacball_two_x = 18;
    pos_pacball_two_y = 3;
    pos_pacball_three_x = 18;
    pos_pacball_three_y = 19;
    pos_pacball_four_x = 1;
    pos_pacball_four_y = 21;
    pacman.emplace_back(PositionPacman(17, 9));
    pos_x = 11;
    pos_y = 17;
    score = 0;
    _isInMenu = true;
    _isInGame = false;
    _playerName.clear();
}

char GameModulePacman::catchPlayercharacterName(const displayModule::e_event &event)
{
    std::vector<char> characterVector = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
        'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
        'y', 'z'};
    std::vector<displayModule::e_event> displayModuleEventVector = {
        displayModule::e_event::KEY_A, displayModule::e_event::KEY_B, displayModule::e_event::KEY_C, displayModule::e_event::KEY_D,
        displayModule::e_event::KEY_E, displayModule::e_event::KEY_F, displayModule::e_event::KEY_G, displayModule::e_event::KEY_H,
        displayModule::e_event::KEY_I, displayModule::e_event::KEY_J, displayModule::e_event::KEY_K, displayModule::e_event::KEY_L,
        displayModule::e_event::KEY_M, displayModule::e_event::KEY_N, displayModule::e_event::KEY_O, displayModule::e_event::KEY_P,
        displayModule::e_event::KEY_Q, displayModule::e_event::KEY_R, displayModule::e_event::KEY_S, displayModule::e_event::KEY_T,
        displayModule::e_event::KEY_U, displayModule::e_event::KEY_V, displayModule::e_event::KEY_W, displayModule::e_event::KEY_X,
        displayModule::e_event::KEY_Y, displayModule::e_event::KEY_Z};

    for (size_t index = 0; index < characterVector.size(); ++index) {
        if (event == displayModuleEventVector[index])
            return characterVector[index];
    }
    return 0;
}

void GameModulePacman::writePlayerNameInFile()
{
    std::ofstream scorefile("./games/pacman/.score", std::ios::app);
    scorefile << _playerName << " " << score << "\n";
    scorefile.close();
}

displayModule::e_event GameModulePacman::setPlayerHighscoreLoop()
{
    displayModule::e_event event;

    if (!display->createText(std::to_string(score), "score"))
        return displayModule::e_event::ERROR;
    while (true) {
        if (!display->createText(_playerName, "playerName"))
            return displayModule::e_event::ERROR;
        display->drawAsset("title_pacman", 2, 2);
        display->drawText("playerScore", 10, 15);
        display->drawText("score", 20, 15);
        display->drawText("playerNameRequest", 10, 20);
        display->drawText("playerName", 35, 20);
        event = display->catchEvent();
        switch (event)
        {
        case displayModule::e_event::ARROW_LEFT: return event;
        case displayModule::e_event::ARROW_RIGHT: return event;
        case displayModule::e_event::ESCAPE: return event;
        case displayModule::e_event::ENTER: writePlayerNameInFile(); return event;
        default: _playerName = catchPlayercharacterName(event) != 0 ? _playerName += catchPlayercharacterName(event) : _playerName; break;
        }
        display->refreshWindow();
    }
}