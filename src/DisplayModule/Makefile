##
## EPITECH PROJECT, 2022
## OOP_arcade_2018
## File description:
## Makefile created by tomcousin,
##

SHELL	=	bash

all:	sfml sdl ncurses

sfml:
		@make -C SFMLDisplayModule

sdl:
		@make -C SDLDisplayModule

ncurses:
		@make -C DisplayModuleNcurses

clean:
		@make -C SFMLDisplayModule clean
		@make -C SDLDisplayModule clean
		@make -C DisplayModuleNcurses clean

fclean:	clean
		@make -C SFMLDisplayModule fclean
		@make -C SDLDisplayModule fclean
		@make -C DisplayModuleNcurses fclean

re:		fclean all

.PHONY:	clean fclean all re sfml sdl ncurses