##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CXX			=	g++ -std=c++11

SRC			=	Sfml_module.cpp

OBJ			=	$(SRC:.cpp=.o)

NAME		=	lib_arcade_sfml.so

CXXFLAGS	=	-I.
CXXFLAGS	+=	-I..
CXXFLAGS	+=	-Wall -Wextra

SFMLFLAGS 	= -lsfml-graphics -lsfml-window -lsfml-system

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CXX) -fPIC $(SRC) $(SFMLFLAGS) -shared -o $(NAME) $(CXXFLAGS)
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
