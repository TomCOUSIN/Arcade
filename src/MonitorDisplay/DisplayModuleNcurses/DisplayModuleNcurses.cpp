/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/

#include "DisplayModuleNcurses.hpp"
#include <fstream>
#include <memory>
#include <map>

DisplayModuleNcurses::DisplayModuleNcurses()
{
    initscr();
    noecho();
    nodelay(stdscr, true);
    set_escdelay(0);
    keypad(stdscr, true);
}

DisplayModuleNcurses::~DisplayModuleNcurses() { endwin(); }


bool DisplayModuleNcurses::createAsset(const std::string &path, const std::string &assetName)
{
    std::fstream file(path + "/1d/" + assetName, std::fstream::in);
    std::string asset;
    size_t pos = assetName.find('.');

    if (file.is_open()) {
        getline(file, asset, '\0');
    } else {
        // TODO MESSAGE ERROR
        return false;
    }
    file.close();
    if (pos == std::string::npos)
        umap_curses_asset.insert(make_pair(assetName, asset));
    else
        umap_curses_asset.insert(make_pair(assetName.substr(0, pos), asset));
    return true;
}

bool DisplayModuleNcurses::drawAsset(const std::string &assetName, int x, int y)
{
    auto it = umap_curses_asset.find(assetName);

    if (it == umap_curses_asset.end()) {
        return false;
    } else {
        mvprintw(y, x, umap_curses_asset.find(assetName)->second.data());
        return true;
    }
}

/**
 * @param text : text to draw!!
 * @param assetName : key to find the text in the unordered_map
 */
bool DisplayModuleNcurses::createText(const std::string &text, const std::string &assetName)
{
    umap_curses_asset.insert(make_pair(assetName, text));
    return true;
}

bool DisplayModuleNcurses::drawText(const std::string &textName, int x, int y)
{
    mvprintw(y, x, umap_curses_asset.find(textName)->second.data());
    return true;
}

void DisplayModuleNcurses::refreshWindow()
{
    refresh();
}

e_event DisplayModuleNcurses::catchEvent()
{
    int save_getch = getch();

    switch (save_getch) {
        case 27 : return e_event::ESCAPE;
        case KEY_RIGHT: return e_event::ARROW_RIGHT;
        case KEY_LEFT: return e_event::ARROW_LEFT;
        case KEY_DOWN: return e_event::ARROW_DOWN;
        case KEY_UP: return e_event::ARROW_UP;
        case KEY_ENTER: return e_event::ENTER;
        case KEY_BACKSPACE: return e_event::SPACE;
        case 'a': return e_event::KEY_A;
        case 'b': return e_event::KEY_B;
        case 'c': return e_event::KEY_C;
        case 'd': return e_event::KEY_D;
        case 'e': return e_event::KEY_E;
        case 'f': return e_event::KEY_F;
        case 'g': return e_event::KEY_G;
        case 'h': return e_event::KEY_H;
        case 'i': return e_event::KEY_I;
        case 'j': return e_event::KEY_J;
        case 'k': return e_event::KEY_K;
        case 'l': return e_event::KEY_L;
        case 'm': return e_event::KEY_M;
        case 'n': return e_event::KEY_N;
        case 'o': return e_event::KEY_O;
        case 'p': return e_event::KEY_P;
        case 'q': return e_event::KEY_Q;
        case 'r': return e_event::KEY_R;
        case 's': return e_event::KEY_S;
        case 't': return e_event::KEY_T;
        case 'u': return e_event::KEY_U;
        case 'v': return e_event::KEY_V;
        case 'w': return e_event::KEY_W;
        case 'x': return e_event::KEY_X;
        case 'y': return e_event::KEY_Y;
        case 'z': return e_event::KEY_Z;
        default:break;
    }
    return NOTHING;
}

extern "C"
{
    DisplayModuleNcurses *allocator()
    {
        return new DisplayModuleNcurses();
    }

    void deleter(DisplayModuleNcurses *ptr)
    {
        delete  ptr;
    }
}

void DisplayModuleNcurses::start_sound()
{}

void DisplayModuleNcurses::stop_sound()
{}
