/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

/**
 * @file coreProgramException.cpp
 */

#include "coreProgramException.hpp"

coreProgram::coreProgramException::coreProgramException(const std::string &message)
: _component("CoreProgram"), _message(message)
{}

std::string const &coreProgram::coreProgramException::getComponent() const
{
    return _component;
}

const char *coreProgram::coreProgramException::what() const noexcept
{
    return _message.data();
}
