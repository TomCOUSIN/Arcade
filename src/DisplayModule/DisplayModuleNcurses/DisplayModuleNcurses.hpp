/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/
#ifndef OOP_ARCADE_2018_DISPLAYMODULENCURSES_HPP
#define OOP_ARCADE_2018_DISPLAYMODULENCURSES_HPP

#include "../IDisplayModule.hpp"
#include <ncurses.h>
#include <unordered_map>

using namespace displayModule;

namespace displayModule
{
    class DisplayModuleNcurses : public IDisplayModule
    {
        public:

        //C_TOR
        DisplayModuleNcurses();
        //D_TOR
        ~DisplayModuleNcurses() final;

        //Sprites
        bool createAsset(const std::string &path, const std::string &assetName) final;
        bool createText(const std::string &text, const std::string &assetName) final;
        bool drawAsset(const std::string &assetName, int x, int y) final;
        bool drawText(const std::string &textName, int x, int y) final;
        void refreshWindow() final;
        void clearScreen() final;

        //Events
        e_event catchEvent() final;

        //Sounds
        void createSound(const std::string &path, const std::string &soundKey) final;
        void startSound(const std::string &soundKey) final;
        void stopSound(const std::string &soundKey) final;

        private:
            std::unordered_map<std::string, std::string> umap_curses_asset;
    };

}

extern "C"
{
    displayModule::DisplayModuleNcurses *allocator()
    {
        return new displayModule::DisplayModuleNcurses();
    }

    void deleter(displayModule::DisplayModuleNcurses *ptr)
    {
        delete  ptr;
    }
}

#endif //OOP_ARCADE_2018_MONITORDISPLAYNCURSES_HPP
