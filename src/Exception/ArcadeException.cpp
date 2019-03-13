/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

/**
 * @file ArcadeException.cpp
 */

#include "ArcadeException.hpp"

/**
 * Constructor for Arcade's exception
 * @param const std::string &message
 * @param const std::string &component
 */
ArcadeException::ArcadeException(const std::string &message,
    const std::string &component) : _message(message), _component(component)
{}

/**
 * Getter for compoenent member
 * @param void
 * @return std::string const &
 */
std::string const &ArcadeException::getComponent() const
{ return _component; }

/**
 * Getter for message member
 * @param void
 * @return const char *
 */
const char *ArcadeException::what() const noexcept
{ return _message.data(); }
