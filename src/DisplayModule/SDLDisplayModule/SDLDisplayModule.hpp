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

    class SDLDisplayModule : public displayModule::IDisplayModule {
        public:
        explicit SDLDisplayModule();
        ~SDLDisplayModule() final;
        bool createAsset(const std::string &path, const std::string &assetKey) final;
        bool createText(const std::string &text, const std::string &textKey) final;
        bool drawAsset(const std::string &assetKey, int x, int y) final;
        bool drawText(const std::string &textKey, int x, int y) final;
        void refreshWindow() final;
        void clearScreen() final;
        displayModule::e_event catchEvent() final;
        void start_sound(const std::string &path, const std::string &soundKey) final;
        void stop_sound(const std::string &soundKey) final;

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
    displayModule::SDLDisplayModule *allocator()
    {
        return new displayModule::SDLDisplayModule();
    }
    void deleter(displayModule::SDLDisplayModule *ptr)
    {
        delete ptr;
    }
}

#endif //OOP_ARCADE_2018_SDLDISPLAYMODULE_HPP
