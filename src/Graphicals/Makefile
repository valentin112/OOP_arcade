##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## No description
##

all: 	 graphicals

graphicals:
		@make --no-print-directory -C ./SFML
		@make --no-print-directory -C ./NCurses
		@make --no-print-directory -C ./SDL

clean:
		@make --no-print-directory clean -C ./SFML
		@make --no-print-directory clean -C ./NCurses
		@make --no-print-directory clean -C ./SDL

fclean:	clean
		@make --no-print-directory fclean -C ./SFML
		@make --no-print-directory fclean -C ./NCurses
		@make --no-print-directory fclean -C ./SDL

re:		fclean all

.PHONY:			all clean fclean re