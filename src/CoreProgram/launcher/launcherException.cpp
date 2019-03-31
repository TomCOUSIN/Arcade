/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

/**
 * @file LauncherException.cpp
 */

#include "launcherException.hpp"

launcherException::launcherException(const std::string &message)
: _component("Launcher"), _message(message)
{}

std::string const &launcherException::getComponent() const
{
    return _component;
}

const char *launcherException::what() const noexcept
{
    return _message.data();
}
