/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/

#include "DisplayModuleNcurses.hpp"
#include "DisplayModuleNcursesException.hpp"
#include <fstream>
#include <memory>
#include <map>

/**
 * Constructor : open the ncurses window
 */
DisplayModuleNcurses::DisplayModuleNcurses()
{
    initscr();
    noecho();
    nodelay(stdscr, true);
    set_escdelay(0);
    keypad(stdscr, true);
    curs_set(0);
}

/**
 * Destructor : close the ncurses window
 */
DisplayModuleNcurses::~DisplayModuleNcurses() { endwin(); }

/**
 * createAsset : function which create the asset in the unordered_map
 * @param path : path to the asset : toto/1d/map.txt
 * @param assetName : name of the asset
 * @return false if error
 * @return true if not
 */
bool DisplayModuleNcurses::createAsset(const std::string &path, const std::string &assetName)
{
    std::fstream file(std::string(path + "/1d/" + assetName + ".txt"), std::fstream::in);
    std::string asset;

    try {
        if (file.is_open()) {
            getline(file, asset, '\0');
        } else {
            throw DisplayModuldeNcursesException("Can't open the file pass in parameter.");
        }
        file.close();
        umap_curses_asset.insert(make_pair(assetName, asset));
    }
    catch (const DisplayModuldeNcursesException &exception) {
        std::cerr << exception.what() << std::endl;
        return false;
    }
    return true;
}

/**
 * drawAsset : function which draw the asset in the ncurses window
 * @param assetName : name of the asset
 * @param x : horizontal coordinates of the asset in the ncurses window
 * @param y : vertical coordinates of the asset in the ncurses window
 * @return false if it's can't draw the asset
 * @return true if it's can draw the asset
 */
bool DisplayModuleNcurses::drawAsset(const std::string &assetName, int x, int y)
{
    std::string asset = umap_curses_asset[assetName];
    size_t index = 0;
    int tmp = x;
    char stock[2];

    try {
        if (!asset[0])
            throw DisplayModuldeNcursesException("Can't find the key to draw assets.");
        else {
            stock[1] = '\0';
            while (asset.data()[index]) {
                stock[0] = asset.data()[index];
                mvprintw(y, x, stock);
                x++;
                index++;
                if (asset.data()[index] == '\n') {
                    y++;
                    x = tmp;
                    index++;
                }
            }
        }
    }
    catch (const DisplayModuldeNcursesException &exception) {
        std::cerr << exception.what() << std::endl;
        return false;
    }
    return true;
}

/**
 * createText : function which create a text in an unordered_map
 * @param text : text to draw!!
 * @param assetName : key to find the text in the unordered_map
 * @return true because no error
 */
bool DisplayModuleNcurses::createText(const std::string &text, const std::string &assetName)
{
    umap_curses_asset.insert(make_pair(assetName, text));
    return true;
}

/**
 * drawText : function which draw the text in the ncurses window
 * @param textName : key of the text name
 * @param x : horizontal coordinates of the text in the ncurses window
 * @param y : vertical coordinates of the text in the ncurses window
 * @return true because no error
 */
bool DisplayModuleNcurses::drawText(const std::string &textName, int x, int y)
{
    mvprintw(y, x, umap_curses_asset.find(textName)->second.data());
    return true;
}

/**
 * refreshWindow : function which refresh the ncurses window
 */
void DisplayModuleNcurses::refreshWindow()
{
    refresh();
}

/**
 * catchEvent : function which catch the event of the keypad and return a enum e_event for the keypad
 * @return the pattern of the correct enum for the keypad event
 */
displayModule::e_event DisplayModuleNcurses::catchEvent()
{
    int save_getch = getch();

    switch (save_getch) {
        case 27 : return displayModule::e_event::ESCAPE;
        case KEY_RIGHT: return displayModule::e_event::ARROW_RIGHT;
        case KEY_LEFT: return displayModule::e_event::ARROW_LEFT;
        case KEY_DOWN: return displayModule::e_event::ARROW_DOWN;
        case KEY_UP: return displayModule::e_event::ARROW_UP;
        case 10: return displayModule::e_event::ENTER;
        case 'a': return displayModule::e_event::KEY_A;
        case 'b': return displayModule::e_event::KEY_B;
        case 'c': return displayModule::e_event::KEY_C;
        case 'd': return displayModule::e_event::KEY_D;
        case 'e': return displayModule::e_event::KEY_E;
        case 'f': return displayModule::e_event::KEY_F;
        case 'g': return displayModule::e_event::KEY_G;
        case 'h': return displayModule::e_event::KEY_H;
        case 'i': return displayModule::e_event::KEY_I;
        case 'j': return displayModule::e_event::KEY_J;
        case 'k': return displayModule::e_event::KEY_K;
        case 'l': return displayModule::e_event::KEY_L;
        case 'm': return displayModule::e_event::KEY_M;
        case 'n': return displayModule::e_event::KEY_N;
        case 'o': return displayModule::e_event::KEY_O;
        case 'p': return displayModule::e_event::KEY_P;
        case 'q': return displayModule::e_event::KEY_Q;
        case 'r': return displayModule::e_event::KEY_R;
        case 's': return displayModule::e_event::KEY_S;
        case 't': return displayModule::e_event::KEY_T;
        case 'u': return displayModule::e_event::KEY_U;
        case 'v': return displayModule::e_event::KEY_V;
        case 'w': return displayModule::e_event::KEY_W;
        case 'x': return displayModule::e_event::KEY_X;
        case 'y': return displayModule::e_event::KEY_Y;
        case 'z': return displayModule::e_event::KEY_Z;
        case ' ': return displayModule::e_event::SPACE;
        default:break;
    }
    return NOTHING;
}

void DisplayModuleNcurses::start_sound(){}

void DisplayModuleNcurses::stop_sound(){}
