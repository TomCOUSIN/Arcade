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
            virtual bool createAsset(const std::string &path, const std::string &assetKey) = 0;
            virtual bool createText(const std::string &text, const std::string &textKey) = 0;
            virtual bool drawAsset(const std::string &assetName, int x, int y) = 0;
            virtual bool drawText(const std::string &textName, int x, int y) = 0;
            virtual void refreshWindow() = 0;
            virtual void clearScreen() = 0;
            virtual e_event catchEvent() = 0;
            virtual void createSound(const std::string &path, const std::string &soundKey) = 0;
            virtual void startSound(const std::string &soundKey) = 0;
            virtual void stopSound(const std::string &soundKey) = 0;
    };
}

#endif //OOP_ARCADE_2018_IDISPLAYMODULE_HPP
