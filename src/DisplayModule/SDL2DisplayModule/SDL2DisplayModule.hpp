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
#include <SDL2/SDL.h>
#include "IDisplayModule.hpp"

namespace displayModule {

    class SDL2DisplayModule : public displayModule::IDisplayModule {
        public:
        explicit SDL2DisplayModule();
        ~SDL2DisplayModule() final;
        bool createAsset(const std::string &path, const std::string &assetKey) final;
        bool createText(const std::string &text, const std::string &textKey) final;
        bool drawAsset(const std::string &assetKey, int x, int y) final;
        bool drawText(const std::string &textKey, int x, int y) final;
        void refreshWindow() final;
        void clearScreen() final;
        displayModule::e_event catchEvent() final;
        void createSound(const std::string &path, const std::string &soundKey) final;
        void startSound(const std::string &soundKey) final;
        void stopSound(const std::string &soundKey) final;

        private:
        std::unordered_map<std::string, SDL_Texture *> _sprite;
        std::unordered_map<std::string, SDL_Texture *> _text;
        SDL_Surface *_windowSurface;
        SDL_Renderer *_renderer;
        SDL_Window *_window;
    };
}

extern "C"
{
    displayModule::SDL2DisplayModule *allocator()
    {
        return new displayModule::SDL2DisplayModule();
    }
    void deleter(displayModule::SDL2DisplayModule *ptr)
    {
        delete ptr;
    }
}

#endif //OOP_ARCADE_2018_SDLDISPLAYMODULE_HPP
