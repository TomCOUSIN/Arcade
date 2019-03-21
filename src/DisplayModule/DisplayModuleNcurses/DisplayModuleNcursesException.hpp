/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tronche,
*/
#ifndef OOP_ARCADE_2018_DISPLAYMODULENCURSESEXCEPTION_HPP
#define OOP_ARCADE_2018_DISPLAYMODULENCURSESEXCEPTION_HPP

#include <iostream>

class DisplayModuldeNcursesException : public std::exception
{
    public:
        //C_TOR
        explicit DisplayModuldeNcursesException(const std::string &message);
        //METHOD
        const char *what() const noexcept override;

    private:
        std::string _message;
};

#endif //OOP_ARCADE_2018_DISPLAYMODULENCURSESEXCEPTION_HPP
