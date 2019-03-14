/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/
#ifndef OOP_ARCADE_2018_IDISPLAYMODULE_HPP
#define OOP_ARCADE_2018_IDISPLAYMODULE_HPP

/**
 * @file IDisplayModule.hpp
 */

#include <iostream>
#include "Asset.hpp"

namespace displayModule
{
    enum e_event {
        ERROR = -1,
        NOTHING,
        ARROW_UP,
        ARROW_DOWN,
        ARROW_RIGHT,
        ARROW_LEFT,
        KEY_A,
        KEY_B,
        KEY_C,
        KEY_D,
        KEY_E,
        KEY_F,
        KEY_G,
        KEY_H,
        KEY_I,
        KEY_J,
        KEY_K,
        KEY_L,
        KEY_M,
        KEY_N,
        KEY_O,
        KEY_P,
        KEY_Q,
        KEY_R,
        KEY_S,
        KEY_T,
        KEY_U,
        KEY_V,
        KEY_W,
        KEY_X,
        KEY_Y,
        KEY_Z,
        SPACE,
        ENTER,
        ESCAPE
    };

    class IDisplayModule
    {
        public:
        virtual ~IDisplayModule() = default;
        virtual displayModule::Asset createAsset(const std::string &path) = 0;
        virtual displayModule::Asset createText(const std::string &text) = 0;
        virtual void setAssetPosition(displayModule::Asset &asset, int x, int y) = 0;
        virtual void drawAsset(const displayModule::Asset &asset) = 0;
        virtual void refreshWindow() = 0;
        virtual void destroyAsset(displayModule::Asset &asset) = 0;
        virtual e_event catchEvent() = 0;
        virtual void start_sound() = 0;
        virtual void stop_sound() = 0;
    };
}

#endif //OOP_ARCADE_2018_IDISPLAYMODULE_HPP
