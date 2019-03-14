##
## EPITECH PROJECT, 2022
## OOP_arcade_2018
## File description:
## Makefile created by tomcousin,
##

SHELL		=	bash

CXX			=	g++ -std=c++11

RM			=	rm -f

DISPLAYMODULENCURSES	=	DisplayModuleNcurses.cpp

MONITORDISPLAY	=	$(addprefix DisplayModuleNcurses/, $(DISPLAYMODULENCURSES))

SRC			=	./main.cpp											\
				$(addprefix ./../, $(MONITORDISPLAY))

OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	-I./../
CXXFLAGS	+=	-I./MonitorDisplay/DisplayModuleNcurses
CXXFLAGS	+=	-Wall -Wextra -Werror

NAME		=	lib_test

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CXX) -o $(NAME) $(OBJ) -lncurses
			mv $(NAME) ../../../lib

clean:
			@$(RM)	$(OBJ)

fclean:		clean
			@$(RM)	$(addprefix ../../../lib/, $(NAME))

re:			fclean all

.cpp.o:
			@echo "compiling " $<
			@$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY:		fclean clean all re
