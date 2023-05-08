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

SNAME	= minishell
FLAGS	= -Wall -Wextra -Werror -lreadline
CC		= gcc ${FLAGS}
RM		= rm -f
SRC		= minishell.c
OBJ		= ${SRC:.c=.o}

.o:.c
	${CC} -c ${OBJ} $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${OBJ} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
