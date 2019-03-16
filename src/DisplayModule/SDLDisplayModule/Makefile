##
## EPITECH PROJECT, 2022
## OOP_arcade_2018
## File description:
## Makefile created by tomcousin,
##

SHELL		=	bash

CXX			=	g++	-std=c++11

RM			=	rm -f

SRC			=	./SDLDisplayModule.cpp

OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	-I.
CXXFLAGS	+=	-I..
CXXFLAGS	+=	-Wall -Wextra

LDFLAGS		=	-lSDL2

NAME		=	lib_arcade_sdl2.so

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CXX) -fPIC $(SRC) $(LDFLAGS) -shared -o $(NAME) $(CXXFLAGS)
			@mv $(NAME) ../../../lib/
clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(addprefix ../../../lib/, $(NAME))

re:			fclean all

.cpp.o:
			@echo "compiling " $<
			@$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY:		fclean clean all re