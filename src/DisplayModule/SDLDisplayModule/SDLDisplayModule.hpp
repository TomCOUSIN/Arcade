/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_SDLDISPLAYMODULE_HPP
#define OOP_ARCADE_2018_SDLDISPLAYMODULE_HPP

#include <iostream>
#include <unordered_map>
#include </usr/local/include/SDL2/SDL.h>
#include "IDisplayModule.hpp"

class SDLDisplayModule : public displayModule::IDisplayModule
{
    public:
        explicit SDLDisplayModule() = default;
        ~SDLDisplayModule() final = default;
        bool createAsset(const std::string &path, const std::string &assetName) final;
        bool createText(const std::string &text, const std::string &textName) final;
        bool drawAsset(const std::string &assetName, int x, int y) final;
        bool drawText(const std::string &textName, int x, int y) final;
        void refreshWindow() final;
        displayModule::e_event catchEvent() final;
        void start_sound() final;
        void stop_sound() final;

    private:
        std::unordered_map<std::string, std::string> _sprite;
};

extern "C"
{
    SDLDisplayModule *allocator()
    {
        return new SDLDisplayModule();
    }
    void deleter(SDLDisplayModule *ptr)
    {
        delete ptr;
    }
}

#endif //OOP_ARCADE_2018_SDLDISPLAYMODULE_HPP
