##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## No description
##

SRC_PACMAN	= 	Pacman.cpp	\

OBJ_PACMAN =	$(SRC_PACMAN:.cpp=.o)

SRC_NIBBLER	= 	Nibbler.cpp	\

OBJ_NIBBLER =	$(SRC_NIBBLER:.cpp=.o)

CCX =	g++

RM =	rm -f

NIBBLER_LIB_GAMES = ../../games/lib_arcade_nibbler.so

PACMAN_LIB_GAMES = ../../games/lib_arcade_pacman.so

OUTPUT = -o

CXXFLAGS = -fPIC -shared -rdynamic

CPPFLAGS = -I../

all:  games

games:		$(OBJ_PACMAN) $(OBJ_NIBBLER)
			$(CCX) $(OUTPUT) $(PACMAN_LIB_GAMES) $(OBJ_PACMAN) $(CXXFLAGS) $(CPPFLAGS)
			$(CCX) $(OUTPUT) $(NIBBLER_LIB_GAMES) $(OBJ_NIBBLER) $(CXXFLAGS) $(CPPFLAGS)

clean:
		$(RM) $(OBJ_PACMAN)
		$(RM) $(OBJ_NIBBLER)

fclean:	clean
		$(RM) $(PACMAN_LIB_GAMES)
		$(RM) $(NIBBLER_LIB_GAMES)

re:		fclean all

.PHONY: all clean fclean re
