/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_LAUNCHEREXCEPTION_HPP
#define OOP_ARCADE_2018_LAUNCHEREXCEPTION_HPP

/**
 * @file LauncherException.hpp
 */

#include <iostream>

    class launcherException : public std::exception
{
    public:
        explicit launcherException(const std::string &message);
        std::string const &getComponent() const;
        const char *what() const noexcept override;

    private:
        std::string _component;
        std::string _message;
};

#endif //OOP_ARCADE_2018_LAUNCHEREXCEPTION_HPP
