/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** GameModulePacmanException
*/

#ifndef GAMEMODULEPACMANEXCEPTION_HPP_
#define GAMEMODULEPACMANEXCEPTION_HPP_

/**
 * @file GameModulePacmanException.hpp
 */

#include <iostream>

class GameModulePacmanException : public std::exception
{
	public:
        //C_TOR
        explicit GameModulePacmanException(const std::string &message);
        //METHOD
        const char *what() const noexcept override;
	private:
        std::string _message;
};

#endif /* !GAMEMODULEPACMANEXCEPTION_HPP_ */
