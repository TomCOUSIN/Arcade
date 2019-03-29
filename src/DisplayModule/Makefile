##
## EPITECH PROJECT, 2022
## OOP_arcade_2018
## File description:
## Makefile created by tomcousin,
##

SHELL	=	bash

all:	sfml sdle ncurses

sfml:
		@make --no-print-directory -C SFMLDisplayModule

sdl:
		@make --no-print-directory -C SDLDisplayModule

ncurses:
		@make --no-print-directory -C DisplayModuleNcurses

clean:
		@make --no-print-directory -C SFMLDisplayModule clean
		@make --no-print-directory -C SDLDisplayModule clean
		@make --no-print-directory -C SDL2DisplayModule clean
		@make --no-print-directory -C DisplayModuleNcurses clean

fclean:	clean
		@make --no-print-directory -C SFMLDisplayModule fclean
		@make --no-print-directory -C SDLDisplayModule fclean
		@make --no-print-directory -C SDL2DisplayModule fclean
		@make --no-print-directory -C DisplayModuleNcurses fclean

re:		fclean all

.PHONY:	clean fclean all re sfml sdl ncurses