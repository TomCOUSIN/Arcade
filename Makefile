##
## EPITECH PROJECT, 2022
## OOP_arcade_2018
## File description:
## Makefile created by tomcousin,
##

SHELL		=	bash

CXX			=	g++ -std=c++11

RM			=	rm -f

COREPROGRAM	=	coreProgram.cpp

DLLOADER	=	DLLoaderException.cpp

EXCEPTION	=	ArcadeException.cpp

SRC			=	./src/main.cpp									\
				$(addprefix ./src/DLLoader/, $(DLLOADER))		\
				$(addprefix ./src/CoreProgram/, $(COREPROGRAM))	\
				$(addprefix ./src/Exception/, $(EXCEPTION))

OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	-I./src/CoreProgram
CXXFLAGS	+=	-I./src/DLLoader
CXXFLAGS	+=	-I./src/Exception
CXXFLAGS	+=	-I./src/MonitorDisplay
CXXFLAGS	+=	-Wall -Wextra -Werror

NAME		=	arcade

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CXX) -o $(NAME) $(OBJ) -ldl

clean:
			@$(RM)	$(OBJ)

fclean:		clean
			@$(RM)	$(NAME)

re:			fclean all

.cpp.o:
			@echo "compiling " $<
			@$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY:		fclean clean all re
