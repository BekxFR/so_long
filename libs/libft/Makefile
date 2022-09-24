# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chillion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 13:40:15 by chillion          #+#    #+#              #
#    Updated: 2022/05/24 13:40:18 by chillion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all norm clean fclean re

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -I includes/
SRC_DIR = sources/
OBJ_DIR = objects/
AR = ar rc
RM = rm

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

SRCS = ft_isalpha.c	\
	ft_isdigit.c	\
	ft_isalnum.c	\
	ft_isascii.c	\
	ft_isprint.c	\
	ft_strlen.c	\
	ft_memset.c	\
	ft_bzero.c	\
	ft_memcpy.c	\
	ft_memmove.c	\
	ft_strlcpy.c	\
	ft_strlcat.c	\
	ft_toupper.c	\
	ft_tolower.c	\
	ft_strchr.c	\
	ft_strrchr.c	\
	ft_strncmp.c	\
	ft_memchr.c	\
	ft_memcmp.c	\
	ft_strnstr.c	\
	ft_atoi.c	\
	ft_calloc.c	\
	ft_strdup.c	\
	ft_substr.c	\
	ft_strjoin.c	\
	ft_strtrim.c	\
	ft_split.c	\
	ft_itoa.c	\
	ft_strmapi.c	\
	ft_striteri.c	\
	ft_putchar_fd.c	\
	ft_putstr_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	\
	ft_putchar.c	\
	ft_putnbr.c	\
	ft_putstr.c	ft_nb_size.c	ft_strdouble.c	ft_putnbr_base.c	ft_puthex_base.c	ft_basecheck.c	ft_hex_size.c	\
	ft_printf.c	ft_format_dixu.c	ft_format_scp.c	ft_long_strict_atoi.c	ft_strjoin_free.c	ft_strjoin_free.c	ft_zalloc.c	\
	ft_free.c	ft_trio_free.c	get_next_line.c	 ft_sqrt.c	ft_chr_on_str.c	ft_strdup_init.c	\

OBJS = $(SRCS:%.c=%.o)

SRC = $(addprefix $(SRC_DIR),$(SRCS))
OBJ = $(addprefix $(OBJ_DIR),$(OBJS))

OBJF = .cache_exists

all : ${NAME}

${NAME} : ${OBJ}
	@echo "${BLUE}###${NC}Update de l'archive ${NAME}${BLUE}###${MAGENTA}"
	${AR} ${NAME} ${OBJ}
	@echo "${NC}"

${OBJ_DIR}%.o : ${SRC_DIR}%.c | $(OBJF)
	@echo "${BLUE}###${NC}Creation du fichier ${@:%.c=%.o}${BLUE}###${ORANGE}"
	${CC} ${FLAGS} -c $< -o $@
	@echo "${NC}"

$(OBJF):
	@mkdir -p ${OBJ_DIR}

clean :
	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
	${RM} -rf ${OBJ_DIR}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : clean
	@echo "${RED}###${NC}Nettoyage de l'archive ${NAME}${RED}###"
	${RM} -f ${NAME}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

re: fclean all

norm:
	@norminette $(SRC_DIR) includes/ | grep -v OK! || true
