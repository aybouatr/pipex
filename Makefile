PROG	= pipex
PROG_B  = pipex_bonus

SRCS 	= srcs/pipex.c srcs/utils.c
OBJS 	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

SRCS_B	= srcs/pipex_bonus.c srcs/utils.c srcs/utils_bonus.c
OBJS_B	= ${SRCS_B:.c=.o}
MAIN_B	= srcs/pipex_bonus.c

HEADER	=  -I./includes

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror -g

%.o : %.c
		$(CC) ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all: 		${PROG}

${PROG}:	${OBJS}
					@make re -C ./Libft
					@$(CC) ${OBJS} -LLibft -lft -o ${PROG}


bonus:		${PROG_B}

${PROG_B}:	${OBJS_B}
					@make re -C ./Libft
					@$(CC) ${OBJS_B} -LLibft -lft -o ${PROG_B}

clean:
					@make clean -C ./Libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./Libft
					@rm -f $(NAME)
					@rm -f ${PROG}

re:			fclean all

re_bonus:	fclean bonus

.PHONY: all clean fclean re re_bonus bonus
