##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## infinity addition
##

SRC =	NCURSES.cpp	\

OBJ =   $(SRC:.cpp=.o)

NAME = ../../../lib/lib_arcade_ncurses.so

CFLAGS += -Wall -fpic -I include -lncurses

all:    $(NAME)

$(NAME):        $(OBJ)
	g++ $(CFLAGS) -shared $(SRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:     fclean all clean

.PHONY: clean fclean all
