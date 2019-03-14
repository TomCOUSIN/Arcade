/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include "coreProgram.hpp"
#include <iostream>
#include <memory.h>
#include "IDisplayModule.hpp"
#include "DisplayModuleNcurses.hpp"

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
    coreProgram _coreProgram = coreProgram();

    if (!_coreProgram.loadLib(argv[1]) || !_coreProgram.getInstanceFromGraphicLibrary())
        return 84;
    return 0;
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
    char *string = strdup("Hello");

    if (argc != 2) {
        print_usage();
    }
<<<<<<< Updated upstream
    else {
        launch_arcade(argv);
    }
=======
    (void)argv;
    IDisplayModule *display = new DisplayModuleNcurses();
    while (1) {
        if (display->catchEvent() == ESCAPE)
            break;
        display->drawAsset(string, 10, 10);
        display->drawWindow();
    }
    display->drawWindow();
    delete display;
>>>>>>> Stashed changes
    return 0;
}
