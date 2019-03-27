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
#include <SDL/SDL.h>
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
        void createSound(const std::string &path, const std::string &soundKey) final;
        void startSound(const std::string &soundKey) final;
        void stopSound(const std::string &soundKey) final;

        private:
        std::unordered_map<std::string, SDL_Surface *> _sprite;
        std::unordered_map<std::string, SDL_Surface *> _text;
        SDL_Surface *_window;
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
