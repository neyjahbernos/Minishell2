##
## EPITECH PROJECT, 2024
## make_file
## File description:
## Make_file
##

SRC =	lib/my_putchar.c 			\
		lib/my_putstr.c  			\
		lib/my_strcat.c 			\
		lib/my_strcmp.c 			\
		lib/my_strlen.c 			\
		lib/buflen.c 				\
		lib/str_to_words_array.c 	\
		lib/reverse_string.c 		\
		lib/my_itoa.c 				\
		lib/my_strncmp.c			\
		lib/str_clean.c 			\
		lib/my_strdup.c				\
		cd.c 						\
		setenv.c                    \
		mysh.c 						\

OBJ = 	$(SRC:.c=.o)

NAME = mysh

all: $(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(OBJ) -g


clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: clean fclean all
