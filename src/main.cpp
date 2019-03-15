/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include "coreProgram.hpp"
#include <iostream>

/**
 * Print the usage when arcade is launched with more or less than 1 argument
 * @param void
 * @return 0 if Success
 * @return 84 if Failure
 */
int print_usage()
{
    std::cout << "SYNOSPIS" << std::endl;
    std::cout << "  ./arcade    library" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "  library     the library containing the graphics libraries to use" << std::endl;
    return 0;
}

/**
 * Create and launch the Core Program to load libraries and play games
 * @param char **argv
 * @return 0 if no Error
 * @return 84 if Error
 */
int launch_arcade(char **argv)
{
    coreProgram::coreProgram _coreProgram = coreProgram::coreProgram();

    if (!_coreProgram.loadLib(argv[1]))
        return 84;
    return _coreProgram.playCoreProgramLoop();
}

/**
 * Arcade main function
 * @param int argc
 * @param char **argv
 * @return 0 if Success
 * @return 84 if Failure
 */
int main(int argc, char **argv)
{
    if (argc != 2) {
        return print_usage();
    }
    else {
        return launch_arcade(argv);
    }
}
