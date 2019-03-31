/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#ifndef OOP_ARCADE_2018_COREPROGRAMEXCEPTION_HPP
#define OOP_ARCADE_2018_COREPROGRAMEXCEPTION_HPP

/**
 * @file coreProgramException.hpp
 */

#include <iostream>

namespace coreProgram
{
    class coreProgramException : public std::exception
    {
        public:
            explicit coreProgramException(const std::string &message);
            std::string const &getComponent() const;
            const char *what() const noexcept override;

        private:
            std::string _component;
            std::string _message;
    };
}

#endif //OOP_ARCADE_2018_COREPROGRAMEXCEPTION_HPP
