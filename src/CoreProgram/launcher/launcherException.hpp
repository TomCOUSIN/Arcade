/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_LAUNCHEREXCEPTION_HPP
#define OOP_ARCADE_2018_LAUNCHEREXCEPTION_HPP

#include "ArcadeException.hpp"

class launcherException : public ArcadeException
{
    public:
        explicit launcherException(const std::string &message);
};

#endif //OOP_ARCADE_2018_LAUNCHEREXCEPTION_HPP
