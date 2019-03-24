/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/

#include "GameModuleNibbler.hpp"
#include <fstream>
#include <map>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory>
#include "IDisplayModule.hpp"
#include "GameModuleNibblerException.hpp"
#include <chrono>
#include <thread>

GameModuleNibbler::PositionNibbler::PositionNibbler(int x, int y)
: _x(x), _y(y)
{}

GameModuleNibbler::GameModuleNibbler() : _playerName("___")
{
    pos_apple_y = 1;
    pos_apple_x = 6;
    nibbler.emplace_back(PositionNibbler(8, 9));
    nibbler.emplace_back(PositionNibbler(9, 9));
    nibbler.emplace_back(PositionNibbler(10, 9));
    nibbler.emplace_back(PositionNibbler(11, 9));
    pos_x = 8;
    pos_y = 9;
}

GameModuleNibbler::~GameModuleNibbler() {}


void GameModuleNibbler::random_apple()
{
    std::srand(std::time(0));

    while (1) {
        pos_apple_x = (std::rand() % 18);
        pos_apple_y = (std::rand() % 18);

        for (auto &i : nibbler) {
            if (pos_apple_x == i._x && pos_apple_y == i._y) {
                continue;
            }
        }
        if (_map[pos_apple_y][pos_apple_x] != '#') {
            return;
        }
    }
}

int GameModuleNibbler::moveNibblerCaseApple(int tmp_x, int tmp_y, int x, int y)
{
    int tmp2_x = 0;
    int tmp2_y = 0;

    if (x == pos_apple_x && y == pos_apple_y) {
        for (auto &index : nibbler) {
            tmp2_x = index._x;
            tmp2_y = index._y;
            index._x = tmp_x;
            index._y = tmp_y;
            tmp_x = tmp2_x;
            tmp_y = tmp2_y;
        }
        nibbler.emplace_back(PositionNibbler(tmp_x, tmp_y));
        random_apple();
        score += 10;
        pos_x = x;
        pos_y = y;
        return -1;
    }
    return 0;
}

void GameModuleNibbler::move_nibbler(int y, int x)
{
    int tmp_x = x;
    int tmp_y = y;
    int tmp2_x = 0;
    int tmp2_y = 0;

    if (moveNibblerCaseApple(tmp_x, tmp_y, x, y) == -1)
        return;
    for (auto &i : nibbler) {
        if (x == i._x && y == i._y) {
            _isQuit = true;
            return;
        }
    }
    if (_map[y][x] == '#')
        _isQuit = true;
    else if (_map[y][x] == ' ') {
        for (auto &i : nibbler) {
            tmp2_x = i._x;
            tmp2_y = i._y;
            i._x = tmp_x;
            i._y = tmp_y;
            tmp_x = tmp2_x;
            tmp_y = tmp2_y;
        }
        pos_x = x;
        pos_y = y;
        return;
    }
}

displayModule::e_event GameModuleNibbler::catch_event()
{
    displayModule::e_event key = display->catchEvent();

    if (key == displayModule::ESCAPE || key == displayModule::ARROW_RIGHT
    || key == displayModule::ARROW_LEFT) {
        return key;
    }
    if (key == displayModule::KEY_Z) {
        move_nibbler(pos_y - 1, pos_x);
        save_key = key;
        return key;
    }
    if (key == displayModule::KEY_D) {
        move_nibbler(pos_y, pos_x + 1);
        save_key = key;
        return key;
    }
    if (key == displayModule::KEY_S) {
        move_nibbler(pos_y + 1, pos_x);
        save_key = key;
        return key;
    }
    if (key == displayModule::KEY_Q) {
        move_nibbler(pos_y, pos_x - 1);
        save_key = key;
        return key;
    }
    else {
        if (save_key == displayModule::KEY_Z) {
            move_nibbler(pos_y - 1, pos_x);
            return displayModule::NOTHING;
        }
        if (save_key == displayModule::KEY_D) {
            move_nibbler(pos_y, pos_x + 1);
            return displayModule::NOTHING;
        }
        if (save_key == displayModule::KEY_S) {
            move_nibbler(pos_y + 1, pos_x);
            return displayModule::NOTHING;
        }
        if (save_key == displayModule::KEY_Q) {
            move_nibbler(pos_y, pos_x - 1);
            return displayModule::NOTHING;
        }
    }
    return key;
}

void GameModuleNibbler::asset()
{
    display->drawAsset("apple", pos_apple_x, pos_apple_y);
    for (size_t i = 0; i < nibbler.size(); i++) {
        if (i == 0) {
            display->drawAsset("head_nibbler", nibbler[i]._x, nibbler[i]._y);
        }
        else {
            display->drawAsset("body_nibbler", nibbler[i]._x, nibbler[i]._y);
        }
    }
}

displayModule::e_event GameModuleNibbler::game()
{
    displayModule::e_event key_return = displayModule::e_event::NOTHING;

    while (!_isQuit) {
        if (chooseMap == 1)
            display->drawAsset("map_nibbler_easy", 0, 0);
        else
            display->drawAsset("map_nibbler_hard", 0, 0);
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        key_return = catch_event();
        if (key_return == displayModule::ESCAPE || key_return == displayModule::ARROW_LEFT
        || key_return == displayModule::ARROW_RIGHT) {
            return key_return;
        }
        asset();
        display->refreshWindow();
    }
    display->refreshWindow();
    //TODO put score in file
    return displayModule::e_event::NOTHING;
}


bool GameModuleNibbler::init_map_easy()
{
    std::fstream file("games/nibbler/assets/1d/map_nibbler_easy.txt", std::fstream::in);
    std::string line;

    try {
        _map.clear();
        if (file.is_open()) {
            while (getline(file, line, '\n'))
                _map.push_back(line);
        } else {
            throw (GameModuleNibblerException("Can't open the file."));
        }
        file.close();

    }
    catch (GameModuleNibblerException &exception) {
        std::cerr << exception.what() << std::endl;
        return false;
    }
    return true;
}

bool GameModuleNibbler::init_map_hard()
{
    std::fstream file("games/nibbler/assets/1d/map_nibbler_hard.txt", std::fstream::in);
    std::string line;

    try {
        _map.clear();
        if (file.is_open()) {
            while (getline(file, line, '\n'))
                _map.push_back(line);
        } else {
            throw (GameModuleNibblerException("Can't open the file."));
        }
        file.close();
    }
    catch (GameModuleNibblerException &exception) {
        std::cerr << exception.what() << std::endl;
        return false;
    }
    return true;
}

bool GameModuleNibbler::initGame(std::shared_ptr<displayModule::IDisplayModule> asset)
{
    return setLib(asset);
}

bool GameModuleNibbler::setLib(const std::shared_ptr<displayModule::IDisplayModule> asset)
{
    display = asset;
    return setAsset();
}

bool GameModuleNibbler::setAsset()
{
    if (!display->createAsset("games/nibbler/assets/", "map_nibbler_easy"))
        return false;
    if (!display->createText("Score: ", "playerScore"))
        return false;
    if (!display->createText("Enter your player name: ", "playerNameRequest"))
        return false;
    if (!display->createAsset("games/nibbler/assets/", "title_nibbler"))
        return false;
    if (!display->createText("How To Play:", "htp_nibbler"))
        return false;
    if (!display->createText("-The aim of the nibbler is to get the most apple in the map.", "1rules_nibbler"))
        return false;
    if (!display->createText("-If the nibbler touch one wall or one sections of his tails, the game is over.", "2rules_nibbler"))
        return false;
    if (!display->createText("-If the tail of the nibbler fill all the map. The game is over and you win.", "3rules_nibbler"))
        return false;
    if (!display->createText("Choose the map of the nibbler :", "choose_map_nibbler"))
        return false;
    if (!display->createText("-Press H to load and play with the hard map.", "map_hard_nibbler"))
        return false;
    if (!display->createText("-Press E to load and play with the easy map.", "map_easy_nibbler"))
        return false;
    if (!display->createAsset("games/nibbler/assets/", "map_nibbler_hard"))
        return false;
    if (!display->createAsset("games/nibbler/assets/", "head_nibbler"))
        return false;
    if (!display->createAsset("games/nibbler/assets/", "body_nibbler"))
        return false;
    return display->createAsset("games/nibbler/assets/", "apple");
}

displayModule::e_event GameModuleNibbler::menu()
{
    displayModule::e_event key_return = displayModule::e_event::NOTHING;

    resetGame();
    while (true)
    {
        display->drawAsset("title_nibbler", 0, 0);
        display->drawText("htp_nibbler", 20, 13);
        display->drawText("1rules_nibbler", 24, 16);
        display->drawText("2rules_nibbler", 24, 18);
        display->drawText("3rules_nibbler", 24, 20);
        display->drawText("choose_map_nibbler", 20, 22);
        display->drawText("map_easy_nibbler", 24, 26);
        display->drawText("map_hard_nibbler", 24, 28);
        key_return = display->catchEvent();
        if (key_return == displayModule::KEY_H) {
            if (!init_map_hard())
                return displayModule::e_event::ERROR;
            chooseMap = 2;
            _isQuit = false;
            save_key = displayModule::e_event::KEY_Q;
            return displayModule::e_event::ENTER;
        } else if (key_return == displayModule::KEY_E) {
            if (!init_map_easy())
                return displayModule::e_event::ERROR;
            chooseMap = 1;
            _isQuit = false;
            save_key = displayModule::e_event::KEY_Q;
            return displayModule::e_event::ENTER;
        } else if (key_return == displayModule::ESCAPE || key_return == displayModule::ARROW_LEFT
            || key_return == displayModule::ARROW_RIGHT)
            return key_return;
        display->refreshWindow();
    }
}

void GameModuleNibbler::resetGame()
{
    nibbler.clear();
    pos_apple_y = 1;
    pos_apple_x = 6;
    nibbler.emplace_back(PositionNibbler(8, 9));
    nibbler.emplace_back(PositionNibbler(9, 9));
    nibbler.emplace_back(PositionNibbler(10, 9));
    nibbler.emplace_back(PositionNibbler(11, 9));
    pos_x = 8;
    pos_y = 9;
    score = 0;
    _playerName.clear();
}

char GameModuleNibbler::catchPlayercharacterName(const displayModule::e_event &event)
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

void GameModuleNibbler::writePlayerNameInFile()
{
    std::ofstream scorefile;
    scorefile.open("./games/nibbler/.score", std::ios::app);
    scorefile << _playerName << " " << std::to_string(score) << "\n";
    scorefile.close();
}

displayModule::e_event GameModuleNibbler::setPlayerHighscore()
{
    displayModule::e_event event;

    if (!display->createText(std::to_string(score), "score"))
        return displayModule::e_event::ERROR;
    while (true) {
        if (!display->createText(_playerName, "playerName"))
            return displayModule::e_event::ERROR;
        display->drawAsset("title_nibbler", 2, 2);
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


