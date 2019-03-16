/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include "SDLDisplayModule.hpp"

bool SDLDisplayModule::createAsset(const std::string &path, const std::string &assetName)
{
    (void)path;
    (void)assetName;
    return false;
}

bool SDLDisplayModule::createText(const std::string &text, const std::string &assetName)
{
    (void)text;
    (void)assetName;
    return false;
}

bool SDLDisplayModule::drawAsset(const std::string &assetName, int x, int y)
{
    (void)assetName;
    (void)x;
    (void)y;
    return false;
}

bool SDLDisplayModule::drawText(const std::string &assetName, int x, int y)
{
    (void)assetName;
    (void)x;
    (void)y;
    return false;
}

void SDLDisplayModule::refreshWindow()
{}

displayModule::e_event SDLDisplayModule::catchEvent()
{
    return displayModule::e_event::NOTHING;
}

void SDLDisplayModule::start_sound()
{}

void SDLDisplayModule::stop_sound()
{}
