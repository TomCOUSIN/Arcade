##
## EPITECH PROJECT, 2022
## OOP_arcade_2018
## File description:
## Makefile created by tomcousin,
##

SHELL		=	bash

CXX			=	g++ -std=c++11

RM			=	rm -f

LAUNCHER	=	launcher.cpp			\
				launcherException.cpp

COREPROGRAM	=	$(addprefix launcher/, $(LAUNCHER))	\
				coreProgram.cpp

DLLOADER	=	DLLoaderException.cpp

EXCEPTION	=	ArcadeException.cpp

CORE_SRC	=	./src/main.cpp											\
				$(addprefix ./src/DLLoader/, $(DLLOADER))				\
				$(addprefix ./src/CoreProgram/, $(COREPROGRAM))			\
				$(addprefix ./src/Exception/, $(EXCEPTION))

CORE_OBJ	=	$(CORE_SRC:.cpp=.o)

CXXFLAGS	=	-I./src/DLLoader
CXXFLAGS	+=	-I./src/Exception
CXXFLAGS	+=	-I./src/CoreProgram
CXXFLAGS	+=	-I./src/MonitorDisplay
CXXFLAGS	+=	-I./src/MonitorDisplay/Asset
CXXFLAGS	+=	-I./src/CoreProgram/launcher
CXXFLAGS	+=	-Wall -Wextra -Werror

NAME		=	arcade

all:		core games graphicals

core:		$(CORE_OBJ)
			@$(CXX) -o $(NAME) $(CORE_OBJ) -ldl

games:
			@echo "Nothing to do"

graphicals:
			mkdir ./lib
			make -C src/MonitorDisplay/SDLDisplayModule

clean:
			make -C src/MonitorDisplay/SDLDisplayModule clean
			@$(RM)	$(OBJ)

fclean:		clean
			make -C src/MonitorDisplay/SDLDisplayModule fclean
			@$(RM)	$(NAME)

re:			fclean all

.cpp.o:
			@echo "compiling " $<
			@$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY:		fclean clean all re core games graphicals
