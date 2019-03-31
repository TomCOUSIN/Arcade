/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/

/**
 * @file DisplayModuleNcursesException.cpp
 */

#include "DisplayModuleNcursesException.hpp"

/**
 * Constructor of Exceptions
 * @param message : variable which will be contained the message of the error in the DisplayModuleNcurses.cpp.
 */
DisplayModuldeNcursesException::DisplayModuldeNcursesException(const std::string &message)
: _message(message)
{}

/**
 * Function which return the message error
 * @return the message
 */
const char *DisplayModuldeNcursesException::what() const noexcept
{
    return _message.data();
}