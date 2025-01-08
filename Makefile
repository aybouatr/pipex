My_PROG = pipex
My_PROG_B = pipex_bonus

SRC = srcs/pipex.c srcs/utils.c
B_SRC = srcs/pipex_bonus.c srcs/utils.c srcs/utils_bonus.c

O_JECT = $(SRC:.c=.o)
BO_JECT = $(B_SRC:.c=.o)

HEADER = -I./includes

CC = cc
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

all: $(O_JECT)
	@make -C ./Libft
	@$(CC) $(O_JECT) -LLibft -lft -o $(My_PROG)

bonus: $(BO_JECT)
	@make bonus -C ./Libft
	@$(CC) $(BO_JECT) -LLibft -lft -o $(My_PROG_B)

clean:
	@make clean -C ./Libft
	@rm -rf $(O_JECT)
	@rm -rf $(BO_JECT)

fclean: clean
	@make fclean -C ./Libft  
	@rm -rf $(My_PROG)
	@rm -rf $(My_PROG_B)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re re_bonus bonus
