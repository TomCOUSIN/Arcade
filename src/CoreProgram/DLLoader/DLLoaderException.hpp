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

#include <iostream>

class DLLoaderException : public std::exception
{
    public:
        /*! Constructeur */
        explicit DLLoaderException(const std::string &message);
        std::string const &getComponent() const;
        const char *what() const noexcept override;

    private:
        std::string _component;
        std::string _message;
};

#endif //OOP_ARCADE_2018_DLLOADEREXCEPTION_HPP
