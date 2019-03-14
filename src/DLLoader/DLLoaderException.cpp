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
: ArcadeException(message, "DLLoader")
{}