# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chillion <chillion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 12:07:22 by chillion          #+#    #+#              #
#    Updated: 2022/10/04 15:32:56 by chillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all test lldb bonus norm clean fclean re

NAME := so_long.a
NAME_BONUS := so_long_bonus.a
SOFT_NAME := so_long
SOFT_BONUS := so_long_bonus

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
	so_long_attack.c	\
	so_long_close.c	\
	so_long_color.c	\
	so_long_draw.c	\
	so_long_draw_end.c	\
	so_long_init_data_move.c	\
	so_long_items_checker.c	\
	so_long_map_checker.c	\
	so_long_map_init.c	\
	so_long_move_checker.c	\
	so_long_path_checker.c	\

#SRCS = ${wildcard *.c}

BONUS = so_long_bonus.c	\
	so_long_attack_bonus.c	\
	so_long_close_bonus.c	\
	so_long_color_bonus.c	\
	so_long_draw_bonus.c	\
	so_long_draw_end_bonus.c	\
	so_long_init_data_move_bonus.c	\
	so_long_items_checker_bonus.c	\
	so_long_map_checker_bonus.c	\
	so_long_map_init_bonus.c	\
	so_long_move_checker_bonus.c	\
	so_long_path_checker_bonus.c	\

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
#	${RM} -f ${SOFT_NAME} 
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

bonus : ${LIBFT} ${BOBJ} ${NAME_BONUS} ${SOFT_BONUS}

${NAME_BONUS} : ${BOBJ}
# 	/*** TEMPORAIRE ***/
	${RM} -f ${SOFT_BONUS} 
# 	/*** TEMPORAIRE ***/
	@echo "${BLUE}###${NC}Update de l'archive ${NAME_BONUS}${BLUE}###${MAGENTA}"
	${AR} ${NAME_BONUS} ${MLX} ${BOBJ}
	@echo "${NC}"

${SOFT_BONUS} :
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_BONUS}${BLUE}###${ORANGE}"
	${CC} ${NAME_BONUS} ${LIBFT} ${FLAGS} ${MLXFLAGS} -o ${SOFT_BONUS} 
	@echo "${NC}"

test : all
	${VAL} ./${SOFT_NAME} "basic.ber"

lldb :
	${CC} -g3 ${SRCS} ${LIBFT} ${MLXFLAGS} -o ${SOFT_NAME}
	lldb ./${SOFT_NAME} "basic.ber"

lldbb :
	${CC} -g3 ${BONUS} ${LIBFT} ${MLXFLAGS} -o ${SOFT_BONUS}
	lldb ./${SOFT_BONUS} "basic.ber"

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
