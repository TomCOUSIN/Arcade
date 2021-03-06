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

DLLOADER	=	DLLoaderException.cpp

COREPROGRAM	=	$(addprefix launcher/, $(LAUNCHER))	\
				$(addprefix DLLoader/, $(DLLOADER))	\
				coreProgram.cpp

CORE_SRC	=	./src/main.cpp											\
				$(addprefix ./src/CoreProgram/, $(COREPROGRAM))

CORE_OBJ	=	$(CORE_SRC:.cpp=.o)

CXXFLAGS	=	-I./src/CoreProgram
CXXFLAGS	+=	-I./src/DisplayModule
CXXFLAGS	+=	-I./src/GameModule
CXXFLAGS	+=	-I./src/CoreProgram/DLLoader
CXXFLAGS	+=	-I./src/CoreProgram/launcher
CXXFLAGS	+=	-Wall -Wextra -Werror

NAME		=	arcade

all:		core games graphicals

core:		$(CORE_OBJ)
			@$(CXX) -o $(NAME) $(CORE_OBJ) -ldl

games:
			@make --no-print-directory -C src/GameModule

graphicals:
			@rm -rf ./lib
			@mkdir ./lib
			@make --no-print-directory -C src/DisplayModule

clean:
			@make --no-print-directory -C src/DisplayModule clean
			@make --no-print-directory -C src/GameModule clean
			@$(RM)	$(CORE_OBJ)

fclean:		clean
			@make --no-print-directory -C src/DisplayModule fclean
			@make --no-print-directory -C src/GameModule fclean
			@rm -rf ./lib
			@$(RM)	$(NAME)

re:			fclean all

.cpp.o:
			@echo "compiling " $<
			@$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY:		fclean clean all re core games graphicals
