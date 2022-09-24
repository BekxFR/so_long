# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chillion <chillion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 12:07:22 by chillion          #+#    #+#              #
#    Updated: 2022/09/24 14:20:00 by chillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all test lldb bonus norm clean fclean re

NAME := so_long.a
#NAME_BONUS := checker.a
SOFT_NAME := so_long
#SOFT_BONUS := checker

CC := gcc
FLAGS := -g3 -Wall -Wextra -Werror -I includes/
SRC_DIR := sources/
OBJ_DIR := objects/
AR := ar rc
RM := rm
VAL := valgrind --leak-check=full --track-origins=yes
MLXFLAGS := -L libs/minilibx-linux/ -lmlx -lXext -lX11 -lz -lm

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

SRCS = so_long.c	\

#SRCS = ${wildcard *.c}

BONUS = checker.c	\
	checker_tools.c	\
	checker_tools_do.c	\
	push_swap_tools_sp.c	\
	push_swap_tools_r.c	\
	push_swap_tools_rr.c	\
	push_swap_tools.c	\
	push_swap_check.c	\
	push_swap_pos.c	\
	push_swap_pull.c	\
	push_swap_switch.c	\
	push_swap_cost.c	\

LIBFT := libs/libft/libft.a
MLX := libs/minilibx-linux/libmlx_Linux.a
FCLIB := ${MAKE} fclean -C libs/libft
CMLX := ${MAKE} clean -C libs/minilibx-linux

OBJS = $(SRCS:%.c=%.o)
BOBJS = $(BONUS:%.c=%.o)
NORM = $(wildcard *.c) $(wildcard *.h)

OBJ = $(addprefix $(OBJ_DIR),$(OBJS))
BOBJ = $(addprefix $(OBJ_DIR),$(BOBJS))

OBJF := .cache_exists

all : ${LIBFT} ${NAME} ${SOFT_NAME}

${LIBFT} :
	${MAKE} all -C libs/minilibx-linux
	${MAKE} all -C libs/libft
	cp ${LIBFT} ${NAME}

${NAME} : ${OBJ}
# 	/*** TEMPORAIRE ***/
	${RM} -f ${SOFT_NAME} 
# 	/*** TEMPORAIRE ***/
	@echo "${BLUE}###${NC}Update de l'archive ${NAME}${BLUE}###${MAGENTA}"
	${AR} ${NAME} ${MLX} ${OBJ}
	@echo "${NC}"

${OBJ_DIR}%.o : %.c | $(OBJF)
	@echo "${BLUE}###${NC}Creation du fichier ${@:%.c=%.o}${BLUE}###${ORANGE}"
	${CC} ${FLAGS} ${MLXFLAGS} -c $< -o $@
	@echo "${NC}"

${SOFT_NAME} :
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_NAME}${BLUE}###${ORANGE}"
	${CC} ${NAME} ${FLAGS} ${MLXFLAGS} -o ${SOFT_NAME}
	@echo "${NC}"

$(OBJF) :
	@mkdir -p ${OBJ_DIR}

bonus : ${FLIB} ${BOBJ} ${NAME_BONUS} ${SOFT_BONUS}

${NAME_BONUS} : ${BOBJ}
	@echo "${BLUE}###${NC}Update de l'archive ${NAME_BONUS}${BLUE}###${MAGENTA}"
	${AR} ${NAME_BONUS} ${BOBJ}
	@echo "${NC}"

${SOFT_BONUS} :
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_BONUS}${BLUE}###${ORANGE}"
	${CC} ${FLAGS} -g3 -o ${SOFT_BONUS} ${NAME_BONUS} ${FLIB}
	@echo "${NC}"

test : all
	${VAL} ./${SOFT_NAME} "basic.ber"

lldb :
	${CC} -g3 ${SRCS} ${LIBFT} ${MLXFLAGS} -o ${SOFT_NAME}
	lldb ./${SOFT_NAME} "basic.ber"

clean : 
	${FCLIB}
	${CMLX}
	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
	${RM} -rf ${OBJ_DIR}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : clean
	@echo "${RED}###${NC}Nettoyage d'archives et de Softs${RED}###"
	${RM} -f ${NAME} ${NAME_BONUS} ${SOFT_NAME} ${SOFT_BONUS}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

re : fclean all

norm :
	${MAKE} norm -C libs/libft
	@norminette $(NORM) | grep -v OK! || true
