##
## EPITECH PROJECT, 2022
## OOP_arcade_2018
## File description:
## Makefile created by tomcousin,
##

SHELL	=	bash

all:	nibbler pacman

nibbler:
		@make --no-print-directory -C GameModuleNibbler

pacman:
		@make --no-print-directory -C GameModulePacman

clean:
		@make --no-print-directory -C GameModuleNibbler clean
		@make --no-print-directory -C GameModulePacman clean

fclean:	clean
		@make --no-print-directory -C GameModuleNibbler fclean
		@make --no-print-directory -C GameModulePacman fclean

re:		fclean all

.PHONY:	clean fclean all re nibbler pacman
