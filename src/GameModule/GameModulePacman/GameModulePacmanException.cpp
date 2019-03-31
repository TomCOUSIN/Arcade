/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** GameModulePacmanException
*/

/**
 * @file GameModulePacmanException.cpp
 */

#include "GameModulePacmanException.hpp"

GameModulePacmanException::GameModulePacmanException(const std::string &message) : _message(message)
{}

const char *GameModulePacmanException::what() const noexcept
{
    return _message.data();
}