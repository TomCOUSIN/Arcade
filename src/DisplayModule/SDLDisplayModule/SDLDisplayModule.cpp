/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <memory>
#include "SDLDisplayModule.hpp"

displayModule::SDLDisplayModule::SDLDisplayModule()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    _window = SDL_SetVideoMode(1920, 1080, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Arcade", NULL);
}

displayModule::SDLDisplayModule::~SDLDisplayModule()
{
    TTF_Quit();
    for (auto &sprite: _sprite) {
        SDL_FreeSurface(sprite.second);
    }
    for (auto &text: _text) {
        SDL_FreeSurface(text.second);
    }
    SDL_FreeSurface(_window);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    SDL_Quit();
}

bool displayModule::SDLDisplayModule::createAsset(const std::string &path, const std::string &assetKey)
{
    SDL_Surface *asset = IMG_Load(std::string(path + "/2d/" + assetKey + ".png").c_str());
    if (_sprite.find(assetKey) != _sprite.end()) {
        SDL_FreeSurface(_sprite[assetKey]);
        _sprite[assetKey] = asset;
    } else {
        _sprite.insert(std::make_pair(assetKey, asset));
    }
    return true;
}

bool displayModule::SDLDisplayModule::createText(const std::string &text, const std::string &textKey)
{
    TTF_Font *font = TTF_OpenFont("./.fonts/default.ttf", 20);
    SDL_Color color = {255, 255, 255, 0};
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, text.c_str(), color);
    if (_text.find(textKey) != _text.end()) {
        SDL_FreeSurface(_sprite[textKey]);
        _text[textKey] = textSurface;
    } else {
        _text.insert(std::make_pair(textKey, textSurface));
    }
    TTF_CloseFont(font);
    return true;
}

bool displayModule::SDLDisplayModule::drawAsset(const std::string &assetName, int x, int y)
{
    SDL_Rect position;
    position.x = x * 32;
    position.y = y * 32;
    if (_sprite.find(assetName) == _sprite.end())
        return false;
    SDL_BlitSurface(_sprite[assetName], NULL, _window, &position);
    return true;
}

bool displayModule::SDLDisplayModule::drawText(const std::string &textKey, int x, int y)
{
    SDL_Rect position;
    position.x = x * 16;
    position.y = y * 16;
    if (_text.find(textKey) == _sprite.end())
        return false;
    SDL_BlitSurface(_text[textKey], NULL, _window, &position);
    return true;
}

void displayModule::SDLDisplayModule::refreshWindow()
{
    SDL_Flip(_window);
    SDL_FillRect(_window, nullptr, 0);
}

displayModule::e_event displayModule::SDLDisplayModule::catchEvent()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_LEFT: return ARROW_LEFT;
            case SDLK_RIGHT: return ARROW_RIGHT;
            case SDLK_UP: return ARROW_UP;
            case SDLK_DOWN: return ARROW_DOWN;
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
            case SDLK_SPACE: return SPACE;
            case SDLK_RETURN: return ENTER;
            default: return NOTHING;
            }
        }
        if (event.type == SDL_QUIT) {
            return ESCAPE;
        }
    }
    return displayModule::e_event::NOTHING;
}

void displayModule::SDLDisplayModule::clearScreen()
{
    SDL_FillRect(_window, NULL, SDL_MapRGB(_window->format, 0, 0, 0));
}

void displayModule::SDLDisplayModule::startSound(const std::string &soundKey)
{ (void)soundKey; }

void displayModule::SDLDisplayModule::stopSound(const std::string &soundKey)
{ (void)soundKey; }

void displayModule::SDLDisplayModule::createSound(const std::string &path,
    const std::string &soundKey)
{ (void)path; (void)soundKey; }

extern "C"
{
    std::shared_ptr<displayModule::SDLDisplayModule> allocator()
    {
        return std::make_shared<displayModule::SDLDisplayModule>();
    }
}