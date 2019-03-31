/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** GameModulePacman
*/

/**
 * @file GameModulePacman.cpp
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

/**
 * Constructor of the position of the pacman asset.
 * @param x: horizontal coordinates of the pacman asset in the ncurses window.
 * @param y: vertical coordinates of the pacman asset in the ncurses window.
 */
GameModulePacman::PositionPacman::PositionPacman(int x, int y) : _x(x), _y(y)
{}

/**
 * Constructor of the position of the red gost asset.
 * @param x: horizontal coordinates of the red gost asset in the ncurses window.
 * @param y: vertical coordinates of the red gost asset in the ncurses window.
 */
GameModulePacman::PositionGostRed::PositionGostRed(int x, int y) : _x_red(x), _y_red(y)
{}

/**
 * Constructor of the position of the blue gost asset.
 * @param x: horizontal coordinates of the blue gost asset in the ncurses window.
 * @param y: vertical coordinates of the blue gost asset in the ncurses window.
 */
GameModulePacman::PositionGostBlue::PositionGostBlue(int x, int y) : _x_blue(x), _y_blue(y)
{}

/**
 * Constructor of the position of the yellow gost asset.
 * @param x: horizontal coordinates of the yellow gost asset in the ncurses window.
 * @param y: vertical coordinates of the yellow gost asset in the ncurses window.
 */
GameModulePacman::PositionGostYellow::PositionGostYellow(int x, int y) : _x_yellow(x), _y_yellow(y)
{}

/**
 * Constructor of the position of the pink gost asset.
 * @param x: horizontal coordinates of the pink gost asset in the ncurses window.
 * @param y: vertical coordinates of the pink gost asset in the ncurses window.
 */
GameModulePacman::PositionGostPink::PositionGostPink(int x, int y) : _x_pink(x), _y_pink(y)
{}

/**
 * Constructor of the pacman game.
 */
GameModulePacman::GameModulePacman() : _playerName("___")
{
    pacman.emplace_back(PositionPacman(17, 11));
    gost_red.emplace_back(PositionGostRed(1, 3));
    gost_blue.emplace_back(PositionGostBlue(5, 15));
    gost_yellow.emplace_back(PositionGostYellow(7, 11));
    gost_pink.emplace_back(PositionGostPink(21, 5));
    pos_x = 11;
    pos_y = 17;
    _gostRed_x = 3;
    _gostRed_y = 1;
    _gostBlue_x = 15;
    _gostBlue_y = 5;
    _gostYellow_x = 11;
    _gostYellow_y = 7;
    _gostPink_x = 5;
    _gostPink_y = 21;
    _isInMenu = true;
    _isInGame = false;
}

/**
 * Destructor of the pacman game.
 */
GameModulePacman::~GameModulePacman() {}

/**
 * Fucntion which move the pacman when he find an pacman.
 * @param tmp_x: copy of the horizontal position of one part of the pacman.
 * @param tmp_y: copy of the vertical position of one of the pacman.
 * @param x: horizontal position when we want to move the pacman.
 * @param y: vertical position when we want to move the pacman.
 * @return -1 when the pacman catch an pacball and add 10 on the score.
 */
int GameModulePacman::scoreUp(int tmp_x, int tmp_y, int x, int y)
{
    int tmp2_x = 0;
    int tmp2_y = 0;

    if (_map[y][x] == '@') {    
        for (auto &index : pacman) {
            tmp2_x = index._x;
            tmp2_y = index._y;
            index._x = tmp_x;
            index._y = tmp_y;
            tmp_x = tmp2_x;
            tmp_y = tmp2_y;
    }
        _map[y][x] = ' ';
        _save_position.clear();
        this->_save_position.push_back (y);
        this->_save_position.push_back (x);
        _position.push_back(this->_save_position);
        pos_x = x;
        pos_y = y;
        score += 10;
        return -1;
    }
    return 0;
}

/**
 * Function which move the pacman when he doesn't find an obstacle, and stop the game when pacman touch a gost.
 * @param y: vertical position when we want to move the pacman.
 * @param x: horizontal position when we want to move the pacman.
 */
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
    if (_map[y][x] == '-')
        return;
    if ((x == _gostRed_x && y == _gostRed_y) || (x == _gostBlue_x && y == _gostBlue_y) || (x == _gostYellow_x && y == _gostYellow_y) || (x == _gostPink_x && y == _gostPink_y))
        _isQuit = true;
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
        _save_position.clear();
        this->_save_position.push_back (y);
        this->_save_position.push_back (x);
        _position.push_back(this->_save_position);
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

/**
 * Function which move the red gost
 * @param y: vertical position of the gost.
 * @param x: horizontal position of the gost.
 */
void GameModulePacman::move_gost_red(int y, int x)
{
    int tmp_x = x;
    int tmp_y = y;
    int tmp2_x = 0;
    int tmp2_y = 0;

    if (_map[y][x] == '#')
        return;
    if (_map[y][x] == '-')
        return;
    if ((_map[y][x] == 'B') || (_map[y][x] == 'C') || (_map[y][x] == 'D'))
        return;
    else if ((_map[y][x] == '.') || (_map[y][x] == ' ') || (_map[y][x] == '@')) {
        for (auto &i : gost_red) {
            tmp2_x = i._x_red;
            tmp2_y = i._y_red;
            i._x_red = tmp_x;
            i._y_red = tmp_y;
            tmp_x = tmp2_x;
            tmp_y = tmp2_y;
        }
    }
    _gostRed_x = x;
    _gostRed_y = y;
}

/**
 * Function which move the blue gost
 * @param y: vertical position of the gost.
 * @param x: horizontal position of the gost.
 */
void GameModulePacman::move_gost_blue(int y, int x)
{
    int tmp_x = x;
    int tmp_y = y;
    int tmp2_x = 0;
    int tmp2_y = 0;

    if (_map[y][x] == '#')
        return;
    if (_map[y][x] == '-')
        return;
    if ((_map[y][x] == 'A') || (_map[y][x] == 'C') || (_map[y][x] == 'D'))
        return;
    else if ((_map[y][x] == '.') || (_map[y][x] == ' ') || (_map[y][x] == '@')) {
        for (auto &i : gost_blue) {
            tmp2_x = i._x_blue;
            tmp2_y = i._y_blue;
            i._x_blue = tmp_x;
            i._y_blue = tmp_y;
            tmp_x = tmp2_x;
            tmp_y = tmp2_y;
        }
    }
    _gostBlue_x = x;
    _gostBlue_y = y;
}

/**
 * Function which move the yellow gost
 * @param y: vertical position of the gost.
 * @param x: horizontal position of the gost.
 */
void GameModulePacman::move_gost_yellow(int y, int x)
{
    int tmp_x = x;
    int tmp_y = y;
    int tmp2_x = 0;
    int tmp2_y = 0;

    if (_map[y][x] == '#')
        return;
    if (_map[y][x] == '-')
        return;
    if ((_map[y][x] == 'A') || (_map[y][x] == 'B') || (_map[y][x] == 'D'))
        return;
    else if ((_map[y][x] == '.') || (_map[y][x] == ' ') || (_map[y][x] == '@')) {
        for (auto &i : gost_yellow) {
            tmp2_x = i._x_yellow;
            tmp2_y = i._y_yellow;
            i._x_yellow = tmp_x;
            i._y_yellow = tmp_y;
            tmp_x = tmp2_x;
            tmp_y = tmp2_y;
        }
    }
    _gostYellow_x = x;
    _gostYellow_y = y;
}
/**
 * Function which move the pink gost
 * @param y: vertical position of the gost.
 * @param x: horizontal position of the gost.
 */
void GameModulePacman::move_gost_pink(int y, int x)
{
    int tmp_x = x;
    int tmp_y = y;
    int tmp2_x = 0;
    int tmp2_y = 0;

    if (_map[y][x] == '#')
        return;
    if (_map[y][x] == '-')
        return;
    if ((_map[y][x] == 'B') || (_map[y][x] == 'C') || (_map[y][x] == 'A'))
        return;
    else if ((_map[y][x] == '.') || (_map[y][x] == ' ') || (_map[y][x] == '@')) {
        for (auto &i : gost_pink) {
            tmp2_x = i._x_pink;
            tmp2_y = i._y_pink;
            i._x_pink = tmp_x;
            i._y_pink = tmp_y;
            tmp_x = tmp2_x;
            tmp_y = tmp2_y;
        }
    }
    _gostPink_x = x;
    _gostPink_y = y;
}

/**
 * Function which create the AI of each gost
 */
void GameModulePacman::gost_Ai()
{
    int stock = (std::rand() % 4);

    if (stock == 0) {
        move_gost_red(_gostRed_y - 1, _gostRed_x);
        move_gost_blue(_gostBlue_y - 1, _gostBlue_x);
        move_gost_yellow(_gostYellow_y - 1, _gostYellow_x);
        move_gost_pink(_gostPink_y - 1, _gostPink_x);
    }
    else if (stock == 1) {
        move_gost_red(_gostRed_y, _gostRed_x - 1);
        move_gost_blue(_gostBlue_y, _gostBlue_x - 1);
        move_gost_yellow(_gostYellow_y, _gostYellow_x - 1);
        move_gost_pink(_gostPink_y, _gostPink_x - 1);
    }
    else if (stock == 2) {
        move_gost_red(_gostRed_y + 1, _gostRed_x);
        move_gost_blue(_gostBlue_y + 1, _gostBlue_x);
        move_gost_yellow(_gostYellow_y + 1, _gostYellow_x);
        move_gost_pink(_gostPink_y + 1, _gostPink_x);
    }
    else if (stock == 3) {
        move_gost_red(_gostRed_y, _gostRed_x + 1);
        move_gost_blue(_gostBlue_y, _gostBlue_x + 1);
        move_gost_yellow(_gostYellow_y, _gostYellow_x + 1);
        move_gost_pink(_gostPink_y, _gostPink_x + 1);
    }
}

/**
 * Function which catch events of the keyboard.
 * @return an event when one of the keyboard touch is press.
 */
displayModule::e_event GameModulePacman::catch_event()
{
    displayModule::e_event key = display->catchEvent();

    if (key == displayModule::ESCAPE || key == displayModule::ARROW_RIGHT
    || key == displayModule::ARROW_LEFT || key == displayModule::KEY_R
    || key == displayModule::KEY_L) {
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

/**
 * Function which draw the pacman asset and gost asset.
 */
void GameModulePacman::asset()
{
    size_t i = 0;
    size_t r = 0;
    size_t b = 0;
    size_t y = 0;
    size_t p = 0;

    display->drawAsset("head_pacman", pacman[i]._x, pacman[i]._y);
    display->drawAsset("gost_red", gost_red[r]._x_red, gost_red[r]._y_red);
    display->drawAsset("gost_blue", gost_blue[b]._x_blue, gost_blue[b]._y_blue);
    display->drawAsset("gost_yellow", gost_yellow[y]._x_yellow, gost_yellow[y]._y_yellow);
    display->drawAsset("gost_pink", gost_pink[p]._x_pink, gost_pink[p]._y_pink);
}

/**
 * Function which contain all the event of the pacman game.
 * @return an event of the keyboard.
 */
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
            case displayModule::e_event::KEY_R: _isInMenu = true; _isInGame = false; break;
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

/**
 * Function which contain all pacman game.
 * @return an keyboard event.
 */
displayModule::e_event GameModulePacman::gameloop()
{
    displayModule::e_event key_return = displayModule::e_event::NOTHING;

    while (!_isQuit) {
        if (choosemap == 1) {
            display->drawAsset("map_pacman", 0, 0);
            for (const auto &i: _position) {
                display->drawAsset("space", i[1], i[0]);
            }
        }
        if (score == 238)
            _isQuit = true;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        gost_Ai();
        key_return = catch_event();
        if (key_return == displayModule::ESCAPE || key_return == displayModule::ARROW_LEFT
        || key_return == displayModule::ARROW_RIGHT || key_return == displayModule::KEY_R) {
            return key_return;
        }
        asset();
        std::string _score = std::string("Score: ") + std::to_string(score);
        display->createText(_score, "score");
        display->drawText("score", 0, 60);
        display->refreshWindow();
    }
    display->refreshWindow();
    return displayModule::e_event::NOTHING;
}

/**
 * Function which call the function setLib
 * @param asset: asset of the lib call.
 * @return true it's working
 * @return false when it's find an exception
 */
bool GameModulePacman::initGame(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
    return setLib(asset);
}

/**
 * Function which set the lib.
 * @param asset: asset of the lib call.
 * @return true it's working
 * @return false when it's find an exception
 */
bool GameModulePacman::setLib(const std::shared_ptr<displayModule::IDisplayModule> &asset)
{
    display = asset;
    return setAsset();
}

/**
 * Function which init the easy map of the pacman.
 * @return true when the stockage of the map in an array works.
 * @return false when find an exception.
 */
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

/**
 * Function which set asset.
 * @return true it's working
 * @return false when it's find an exception
 */
bool GameModulePacman::setAsset()
{
    if (!display->createAsset("games/pacman/assets/", "map_pacman"))
        return false;
    if (!display->createAsset("games/pacman/assets/", "gost_red"))
        return false;
    if (!display->createAsset("games/pacman/assets/", "gost_blue"))
        return false;
    if (!display->createAsset("games/pacman/assets/", "gost_yellow"))
        return false;
    if (!display->createAsset("games/pacman/assets/", "gost_pink"))
        return false;
    if (!display->createText("Score: ", "playerScore"))
        return false;
    if (!display->createText("Enter your player name: ", "playerNameRequest"))
        return false;
    if (!display->createAsset("games/pacman/assets/", "title_pacman"))
        return false;
    if (!display->createText("How To Play:", "htp_pacman"))
        return false;
    if (!display->createText("-The aim of the pacman is to eat all the pacball and the ball in the map, but be carefull, four ghost want to kill you !.", "1rules_pacman"))
        return false;
    if (!display->createText("-If pacman touch one gost, the game is over.", "2rules_pacman"))
        return false;
    if (!display->createText("-Press E to play the game.", "start_game"))
        return false;
    if (!display->createText("-Press L to return to the lib menu.", "keyboard_L"))
        return false;
    if (!display->createText("-Press R to return the game menu.", "keyboard_R"))
        return false;
    if (!display->createAsset("games/pacman/assets/", "head_pacman"))
        return false;
    return (display->createAsset("games/pacman/assets/", "space"));
}

/**
 * Function which conatin all of the menu loop.
 * @return a keyboard event.
 */
displayModule::e_event GameModulePacman::menuLoop()
{
    displayModule::e_event key_return = displayModule::e_event::NOTHING;
    resetGame();
    while (true) {
        display->drawAsset("title_pacman", 0, 0);
        display->drawText("htp_pacman", 20, 13);
        display->drawText("1rules_pacman", 24, 16);
        display->drawText("2rules_pacman", 24, 18);
        display->drawText("keyboard_L", 24, 20);
        display->drawText("keyboard_R", 24, 32);
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

/**
 * Function which reset the nibbler game.
 */
void GameModulePacman::resetGame()
{
    _position.clear();
    pacman.clear();
    pacman.emplace_back(PositionPacman(17, 11));
    pos_x = 11;
    pos_y = 17;
    gost_red.emplace_back(PositionGostRed(1, 3));
    gost_blue.emplace_back(PositionGostBlue(5, 15));
    gost_yellow.emplace_back(PositionGostYellow(7, 11));
    gost_pink.emplace_back(PositionGostPink(21, 5));
    _gostRed_x = 3;
    _gostRed_y = 1;
    _gostBlue_x = 15;
    _gostBlue_y = 5;
    _gostYellow_x = 11;
    _gostYellow_y = 7;
    _gostPink_x = 5;
    _gostPink_y = 21;
    score = 0;
    _isInMenu = true;
    _isInGame = false;
    _playerName.clear();
}

/**
 * Function which catch the player name.
 * @param event: event of the keyboard.
 * @return a char of the letter press.
 */
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

/**
 * Function which write the name of the player in a file.
 */
void GameModulePacman::writePlayerNameInFile()
{
    std::ofstream scorefile("./games/pacman/.score", std::ios::app);
    scorefile << _playerName << " " << score << "\n";
    scorefile.close();
}

/**
 * Function which setr the player highScore
 * @return a keyboard event.
 */
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

extern "C"
{
    std::shared_ptr<gameModule::GameModulePacman> allocator()
    {
        return std::make_shared<gameModule::GameModulePacman>();
    }
}