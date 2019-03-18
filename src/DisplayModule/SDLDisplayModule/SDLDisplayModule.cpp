/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
}
*/

#include <SDL2/SDL_ttf.h>
#include "SDLDisplayModule.hpp"

displayModule::SDLDisplayModule::SDLDisplayModule()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

displayModule::SDLDisplayModule::~SDLDisplayModule()
{
    SDL_DestroyWindow(_window);
    TTF_Quit();
    SDL_Quit();
}

bool displayModule::SDLDisplayModule::createAsset(const std::string &path, const std::string &assetName)
{
    (void)path;
    (void)assetName;
    return false;
}

bool displayModule::SDLDisplayModule::createText(const std::string &text, const std::string &assetName)
{
    TTF_Font* textFont = TTF_OpenFont("./.fonts/arial.ttf", 24);
    SDL_Color textColor = { 255, 255, 255, 0 };
    SDL_Surface *textSurface = TTF_RenderText_Solid(textFont, text.c_str(), textColor);
    _text.insert(std::make_pair(assetName, textSurface));
    TTF_CloseFont(textFont);
    return true;
}

bool displayModule::SDLDisplayModule::drawAsset(const std::string &assetName, int x, int y)
{
    TTF_Font* textFont = TTF_OpenFont("./.fonts/arial.ttf", 24);
    SDL_Color textColor = { 255, 255, 255, 0 };
    SDL_Surface *textSurface = TTF_RenderText_Solid(textFont, "toto", textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(_renderer, textSurface);
    SDL_Rect textRect = { 20, 20, 100, 100 };
    SDL_RenderCopy(_renderer, textTexture, nullptr, &textRect);
    return true;
}

bool displayModule::SDLDisplayModule::drawText(const std::string &assetName, int x, int y)
{
    (void)assetName;
    (void)x;
    (void)y;
    return false;
}

void displayModule::SDLDisplayModule::refreshWindow()
{
    SDL_RenderPresent(_renderer);
    SDL_UpdateWindowSurface(_window);
}

displayModule::e_event displayModule::SDLDisplayModule::catchEvent()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym)
            {
                case SDLK_LEFT: return ARROW_LEFT;
                case SDLK_RIGHT: return ARROW_RIGHT;
                case SDLK_a: return KEY_A;
                case SDLK_b: return KEY_B;
                case SDLK_c: return KEY_C;
                case SDLK_d: return KEY_D;
                case SDLK_e: return KEY_E;
                case SDLK_f: return KEY_F;
                case SDLK_g: return KEY_G;
                case SDLK_h: return KEY_H;
                case SDLK_i: return KEY_I;
                case SDLK_j: return KEY_J;
                case SDLK_k: return KEY_K;
                case SDLK_l: return KEY_L;
                case SDLK_m: return KEY_M;
                case SDLK_n: return KEY_N;
                case SDLK_o: return KEY_O;
                case SDLK_p: return KEY_P;
                case SDLK_q: return KEY_Q;
                case SDLK_r: return KEY_R;
                case SDLK_s: return KEY_S;
                case SDLK_t: return KEY_T;
                case SDLK_u: return KEY_U;
                case SDLK_v: return KEY_V;
                case SDLK_w: return KEY_W;
                case SDLK_x: return KEY_X;
                case SDLK_y: return KEY_Y;
                case SDLK_z: return KEY_Z;
                case SDLK_ESCAPE: return ESCAPE;
                case SDLK_BACKSPACE: return ENTER;
                default: return NOTHING;
            }
        }
        if (event.type == SDL_QUIT) {
            return ESCAPE;
        }
    }
    return displayModule::e_event::NOTHING;
}

void displayModule::SDLDisplayModule::start_sound()
{}

void displayModule::SDLDisplayModule::stop_sound()
{}
