/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include "Asset.hpp"

void displayModule::Asset::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void displayModule::Asset::setAsset(void *asset)
{
    _asset = asset;
}

void *displayModule::Asset::getAsset()
{
    return _asset;
}

int displayModule::Asset::getXPosition()
{
    return _x;
}

int displayModule::Asset::getYPosition()
{
    return _y;
}
