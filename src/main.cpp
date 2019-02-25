/*
** EPITECH PROJECT, 2022
** OOP_arcade_2018
** File description:
** Created by tomcousin,
*/

#include <iostream>

static int print_usage()
{
    std::cout << "SYNOSPIS" << std::endl;
    std::cout << "  ./arcade    library" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "  library     the library containing the graphics libraries to use" << std::endl;
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        print_usage();
    }
    (void)argv;
    return 0;
}