/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include "ArcadeException.hpp"

ArcadeException::ArcadeException(const std::string &message,
    const std::string &component) : _message(message), _component(component)
{}

std::string const &ArcadeException::getComponent() const
{ return _component; }

const char *ArcadeException::what() const noexcept
{ return _message.data(); }
