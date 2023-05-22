# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dfiliagg <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 10:46:16 by dfiliagg          #+#    #+#              #
#    Updated: 2023/05/22 11:33:07 by adi-fort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
FLAGS	=  -Wall -Wextra -Werror
CC		= gcc ${FLAGS}
RM		= rm -f
SRC		= minishell.c  free.c ${BLT} ${PIP} ${SIG}
BLT     = builtin/envp_utils.c builtin/pwd_utils.c builtin/exit_utils.c
PIP		= pipex/pipex_utils.c pipex/pipex.c pipex/error.c pipex/check_file.c
SIG		= signal/signal.c
OBJ		= ${SRC:.c=.o}
LFT		= libft/libft.a

RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
RESET	= \033[0;0m

all: ${NAME}

${LFT}:
		make -C libft
.o:.c
	${CC} ${OBJ} -c $< -o ${<:.c=.o}

SRC_COUNT_TOT = $(shell expr $(shell echo -n $(SRC) $(BLT) $(PIP) $(SIG) $(LFT) | wc -w))
SRC_COUNT = 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

${NAME}: ${OBJ} ${LFT}
	${CC} ${OBJ} ${LFT} -o ${NAME} -lreadline
	make clean
	@printf "$(BLUE)-------------------------------------------------------------------------\n$(RESET)"
	@printf "$(RED)███    ███ ██ ███    ██ ██$(RESET) $(YELLOW)██████$(RESET) $(RED)██   ██ ███████ ██      ██      \n"
	@printf "$(RED)████  ████ ██ ████   ██ ██$(RESET) $(YELLOW)██    $(RESET) $(RED)██   ██ ██      ██      ██      \n"
	@printf "$(RED)██ ████ ██ ██ ██ ██  ██ ██$(RESET) $(YELLOW)██████$(RESET) $(RED)███████ █████   ██      ██      \n"
	@printf "$(RED)██  ██  ██ ██ ██  ██ ██ ██$(RESET) $(YELLOW)    ██$(RESET) $(RED)██   ██ ██      ██      ██      \n"
	@printf "$(RED)██      ██ ██ ██   ████ ██$(RESET) $(YELLOW)██████$(RESET) $(RED)██   ██ ███████ ███████ ███████ \n"
	@printf "\n$(BLUE)-------------------------------------------------------------------------\n$(RESET)"
	@printf "$(YELLOW)                       AS PAINFULL AS HELL!\n$(RESET)"
	@printf "$(BLUE)-------------------------------------------------------------------------\n$(RESET)"


clean:
	${RM} ${OBJ}
	make clean -C libft

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
