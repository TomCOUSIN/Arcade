/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_ARCADEEXCEPTION_HPP
#define OOP_ARCADE_2018_ARCADEEXCEPTION_HPP

/**
 * @file ArcadeException.hpp
 */

#include <iostream>

class ArcadeException : public std::exception
{
    public:
        ArcadeException(const std::string &message, const std::string &component);
        std::string const &getComponent() const;
        const char *what() const noexcept override;

    private:
        std::string _message;
        std::string _component;
};

#endif //OOP_ARCADE_2018_ARCADEEXCEPTION_HPP
