##
## EPITECH PROJECT, 2022
## OOP_arcade_2018
## File description:
## Makefile created by tomcousin,
##

SHELL		=	bash

CXX			=	g++ -std=c++11

RM			=	rm -f

SRC			=	src/main.cpp

OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	-I./include
CXXFLAGS	+=	-Wall -Wextra -Werror

NAME		=	arcade

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CXX) -o $(NAME) $(OBJ)

clean:
			@$(RM)	$(OBJ)

fclean:		clean
			@$(RM)	$(NAME)

re:			fclean all

.cpp.o:
			@echo "compiling " $<
			@$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY:		fclean clean all re