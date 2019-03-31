/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/
#ifndef OOP_ARCADE_2018_GAMEMODULENIBBLEREXCEPTION_HPP
#define OOP_ARCADE_2018_GAMEMODULENIBBLEREXCEPTION_HPP

/**
 * @file GameModuleNibblerException.hpp
 */

#include <iostream>

class GameModuleNibblerException : public std::exception
{
    public:
        //C_TOR
        explicit GameModuleNibblerException(const std::string &message);
        //METHOD
        const char *what() const noexcept override;

    private:
        std::string _message;
};

#endif //OOP_ARCADE_2018_GAMEMODULENIBBLEREXCEPTION_HPP
