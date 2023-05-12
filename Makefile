# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 10:46:16 by dfiliagg          #+#    #+#              #
#    Updated: 2023/02/20 10:46:19 by dfiliagg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
FLAGS	=  -Wall -Wextra -Werror
CC		= gcc ${FLAGS}
RM		= rm -f
SRC		= minishell.c  free.c ${BLT} ${PIP}
BLT     = builtin/envp_utils.c builtin/pwd_utils.c builtin/exit_utils.c
PIP		= pipex/error.c pipex/pipex_utils.c pipex/pipex.c pipex/print_file.c
OBJ		= ${SRC:.c=.o}
LFT		= libft/libft.a

all: ${NAME}

${LFT}:
		make -C libft
.o:.c
	${CC} ${OBJ} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} ${LFT}
	${CC} ${OBJ} ${LFT} -o ${NAME} -lreadline
	make clean

clean:
	${RM} ${OBJ}
	make clean -C libft

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re