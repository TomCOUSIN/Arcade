/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

/**
 * @file DLLoaderException.cpp
 */

#include "DLLoaderException.hpp"

/**
 * Instantiate a DLLoaderException
 * @param const std::string &message, the message to throw
 */
DLLoaderException::DLLoaderException(const std::string &message)
: _component("DLLoader"), _message(message)
{}

/**
 * getter to know wich component is throwing an exception
 * @return std::string corresponding to the component's name
 */
std::string const &DLLoaderException::getComponent() const
{
    return _component;
}

/**
 * getter to know the error message
 * @return const char* corresponding to the message
 */
const char *DLLoaderException::what() const noexcept
{
    return _message.data();
}
