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

DLLoaderException::DLLoaderException(const std::string &message)
: _component("DLLoader"), _message(message)
{}

std::string const &DLLoaderException::getComponent() const
{
    return _component;
}

const char *DLLoaderException::what() const noexcept
{
    return _message.data();
}
