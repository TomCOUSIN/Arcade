/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
}
*/

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "SDL2DisplayModule.hpp"

displayModule::SDL2DisplayModule::SDL2DisplayModule()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
    _windowSurface = SDL_GetWindowSurface(_window);
}

displayModule::SDL2DisplayModule::~SDL2DisplayModule()
{
    TTF_Quit();
    IMG_Quit();
    SDL_FreeSurface(_windowSurface);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool displayModule::SDL2DisplayModule::createAsset(const std::string &path, const std::string &assetKey)
{
    SDL_Texture *asset = IMG_LoadTexture(_renderer, std::string(path + "/2d/" + assetKey + ".png").c_str());
    if (_sprite.find(assetKey) != _sprite.end())
        _sprite[assetKey] = asset;
    else
        _sprite.insert(std::make_pair(assetKey, asset));
    return true;
}

bool displayModule::SDL2DisplayModule::createText(const std::string &text, const std::string &textKey)
{
    TTF_Font *font = TTF_OpenFont("./.fonts/arial.ttf", 20);
    SDL_Color color = {255, 255, 255, 0};
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(_renderer, textSurface);
    if (_text.find(textKey) != _text.end())
        _text[textKey] = texture;
    else
        _text.insert(std::make_pair(textKey, texture));
    TTF_CloseFont(font);
    return true;
}

bool displayModule::SDL2DisplayModule::drawAsset(const std::string &assetName, int x, int y)
{
    SDL_Rect position;
    position.x = x * 32;
    position.y = y * 32;
    if (_sprite.find(assetName) == _sprite.end())
        return false;
    SDL_QueryTexture(_sprite[assetName], NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(_renderer, _sprite[assetName], NULL, &position);
    return true;
}

bool displayModule::SDL2DisplayModule::drawText(const std::string &textKey, int x, int y)
{
    SDL_Rect position;
    position.x = x * 16;
    position.y = y * 16;
    if (_text.find(textKey) == _text.end())
        return false;
    SDL_QueryTexture(_text[textKey], NULL, NULL, &position.w, &position.h);
    SDL_RenderCopy(_renderer, _text[textKey], NULL, &position);
    return true;
}

void displayModule::SDL2DisplayModule::refreshWindow()
{
    SDL_RenderPresent(_renderer);
    SDL_RenderClear(_renderer);
}

displayModule::e_event displayModule::SDL2DisplayModule::catchEvent()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                return ARROW_LEFT;
            case SDLK_RIGHT:
                return ARROW_RIGHT;
            case SDLK_UP:
                return ARROW_UP;
            case SDLK_DOWN:
                return ARROW_DOWN;
            case SDLK_a:
                return KEY_A;
            case SDLK_b:
                return KEY_B;
            case SDLK_c:
                return KEY_C;
            case SDLK_d:
                return KEY_D;
            case SDLK_e:
                return KEY_E;
            case SDLK_f:
                return KEY_F;
            case SDLK_g:
                return KEY_G;
            case SDLK_h:
                return KEY_H;
            case SDLK_i:
                return KEY_I;
            case SDLK_j:
                return KEY_J;
            case SDLK_k:
                return KEY_K;
            case SDLK_l:
                return KEY_L;
            case SDLK_m:
                return KEY_M;
            case SDLK_n:
                return KEY_N;
            case SDLK_o:
                return KEY_O;
            case SDLK_p:
                return KEY_P;
            case SDLK_q:
                return KEY_Q;
            case SDLK_r:
                return KEY_R;
            case SDLK_s:
                return KEY_S;
            case SDLK_t:
                return KEY_T;
            case SDLK_u:
                return KEY_U;
            case SDLK_v:
                return KEY_V;
            case SDLK_w:
                return KEY_W;
            case SDLK_x:
                return KEY_X;
            case SDLK_y:
                return KEY_Y;
            case SDLK_z:
                return KEY_Z;
            case SDLK_ESCAPE:
                return ESCAPE;
            case SDLK_RETURN:
                return ENTER;
            case SDLK_SPACE:
                return SPACE;
            default:
                return NOTHING;
            }
        }
        if (event.type == SDL_QUIT) {
            return ESCAPE;
        }
    }
    return displayModule::e_event::NOTHING;
}

void displayModule::SDL2DisplayModule::clearScreen()
{
    SDL_RenderClear(_renderer);
}

void displayModule::SDL2DisplayModule::start_sound(const std::string &path,
    const std::string &soundKey)
{ (void)path; (void)soundKey; }

void displayModule::SDL2DisplayModule::stop_sound(const std::string &soundKey)
{ (void)soundKey; }