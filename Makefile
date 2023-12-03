NAME= philo
SRC= src/*.c
OBJ= $(SRC:src/%.c=obj/%.o)
CC=cc
CFLAGS=-Wall -Werror -Wextra -g3 -fsanitize=address -ggdb3
RM=rm -rf

LIBFT=libft/libft.a

all: lobi creat_directory $(NAME) $(OBJ)

lobi:
	@make -C libft

creat_directory:
	mkdir -p obj

obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@make -C libft clean
	$(RM) obj

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all