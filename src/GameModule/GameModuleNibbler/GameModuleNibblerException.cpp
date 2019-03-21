/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/
#include "GameModuleNibblerException.hpp"

/**
 * Constructor
 * @param message : variable which will be contained the message of the error in the GameModuleNibbler.cpp.
 */
GameModuleNibblerException::GameModuleNibblerException(const std::string &message)
: _message(message)
{}

/**
 * Function which return the message error
 * @return the message
 */
const char *GameModuleNibblerException::what() const noexcept
{
    return _message.data();
}