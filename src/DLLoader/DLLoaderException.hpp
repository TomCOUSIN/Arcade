/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_DLLOADEREXCEPTION_HPP
#define OOP_ARCADE_2018_DLLOADEREXCEPTION_HPP

/**
 * @file DLLoaderException.hpp
 */

#include "ArcadeException.hpp"

class DLLoaderException : public ArcadeException
{
    public:
        /*! Constructeur */
        explicit DLLoaderException(const std::string &message);
};

#endif //OOP_ARCADE_2018_DLLOADEREXCEPTION_HPP
