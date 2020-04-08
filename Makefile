##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## No description
##

SRC_CORE	= 	src/main.cpp \
				src/Core/Core.cpp \
				src/Core/Loader/DlLoader.cpp \

OBJ_CORE =	$(SRC_CORE:.cpp=.o)

CCX =	g++

RM =	rm -rf


NAME_CORE =	arcade

OUTPUT = -o

LIB_DYNAMIC = -ldl

CPPFLAGS = -I./src/

debug:          CPPFLAGS += -g3
debug:          re

all: 	core graphicals game

core:	$(OBJ_CORE)
		$(CCX) $(OUTPUT) $(NAME_CORE) $(OBJ_CORE) $(LIB_DYNAMIC)

game:
		@make -C ./src/Games

graphicals:
		@make -C ./src/Graphicals

clean:
		$(RM) $(NAME_CORE)
		$(RM) $(OBJ_CORE)
		@make clean -C ./src/Graphicals
		@make clean -C ./src/Games

fclean:	clean
		@make fclean -C ./src/Graphicals
		@make fclean -C ./src/Games

re:		fclean all

.PHONY:			all clean fclean re
