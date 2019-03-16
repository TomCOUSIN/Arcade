/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
}
*/

#include "SDLDisplayModule.hpp"

displayModule::SDLDisplayModule::SDLDisplayModule()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
}

displayModule::SDLDisplayModule::~SDLDisplayModule()
{
    SDL_DestroyWindow(_window);
}

bool displayModule::SDLDisplayModule::createAsset(const std::string &path, const std::string &assetName)
{
    (void)path;
    (void)assetName;
    return false;
}

bool displayModule::SDLDisplayModule::createText(const std::string &text, const std::string &assetName)
{
    (void)text;
    (void)assetName;
    return false;
}

bool displayModule::SDLDisplayModule::drawAsset(const std::string &assetName, int x, int y)
{
    (void)assetName;
    (void)x;
    (void)y;
    return false;
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
