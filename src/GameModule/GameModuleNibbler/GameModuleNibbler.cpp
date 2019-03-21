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
#include <cstdlib>
#include <memory>
#include <../../DisplayModule/DisplayModuleNcurses/DisplayModuleNcurses.hpp>
#include <chrono>
#include <thread>

GameModuleNibbler::PositionNibbler::PositionNibbler(int x, int y)
: _x(x), _y(y)
{}

GameModuleNibbler::GameModuleNibbler()
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

    if (key == ESCAPE)
        return ESCAPE;
    if (key == ARROW_RIGHT)
        return key;
    if (key == ARROW_LEFT)
        return key;
    if (key == KEY_Z) {
        move_nibbler(pos_y - 1, pos_x);
        save_key = key;
        return key;
    }
    if (key == KEY_D) {
        move_nibbler(pos_y, pos_x + 1);
        save_key = key;
        return key;
    }
    if (key == KEY_S) {
        move_nibbler(pos_y + 1, pos_x);
        save_key = key;
        return key;
    }
    if (key == KEY_Q) {
        move_nibbler(pos_y, pos_x - 1);
        save_key = key;
        return key;
    } else {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        if (save_key == KEY_Z)
            move_nibbler(pos_y - 1, pos_x);
        if (save_key == KEY_D)
            move_nibbler(pos_y, pos_x + 1);
        if (save_key == KEY_S)
            move_nibbler(pos_y + 1, pos_x);
        if (save_key == KEY_Q)
            move_nibbler(pos_y, pos_x - 1);
    }
    return key;
}

void GameModuleNibbler::asset()
{
    display->createText("x", "apple" + 0);
    display->drawText("apple" + 0, pos_apple_x, pos_apple_y);
    for (size_t i = 0; i < nibbler.size(); i++) {
        if (i == 0) {
            display->createText("O", "nibbler" + i);
        }
        else {
            display->createText("*", "nibbler" + i);
        }
        display->drawText("nibbler" + i, nibbler[i]._x, nibbler[i]._y);
    }
}

displayModule::e_event GameModuleNibbler::game()
{
    displayModule::e_event key_return = catch_event();

    while (!_isQuit) {
        display->drawAsset("map_nibbler", 0, 0);
        asset();
        if (key_return == ESCAPE || key_return == ARROW_LEFT || key_return == ARROW_RIGHT) {
            return key_return;
        }
        display->refreshWindow();
    }
    display->refreshWindow();
    return displayModule::e_event::NOTHING;
}

bool GameModuleNibbler::initGame(std::shared_ptr<displayModule::IDisplayModule> asset)
{
    std::fstream file("games/nibbler/asset/1d/map_nibbler.txt", std::fstream::in);
    std::string line;

    if (file.is_open()) {
        while (getline(file, line, '\n'))
        _map.push_back(line);
    } else {
        // TODO MESSAGE ERROR
        return false;
    }
    file.close();
    return setLib(asset);
}

bool GameModuleNibbler::setLib(const std::shared_ptr<displayModule::IDisplayModule> asset)
{
    display = asset;
    return setAsset();
}

bool GameModuleNibbler::setAsset()
{
    return display->createAsset("games/nibbler/asset/", "map_nibbler");
}