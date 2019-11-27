# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 18:24:34 by lusanche          #+#    #+#              #
#    Updated: 2019/11/26 21:18:43 by lusanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PF_DIR = ./
PF_SRC = ft_printf_master.c \
		ft_printf_store.c \
		ft_printf_cspd.c \
		ft_printf_ouxf.c \
		ft_printf_flags.c \
		ft_printf_tools.c \
		ft_printf_itoa.c \
		ft_printf_float.c \
		ft_printf_round.c \
		ft_printf_exponent.c \
		ft_printf_bonus.c \
		ft_printf_time.c

LB_DIR = libft/
LB_SRC =  ft_atoi.c \
		ft_chrstr.c \
		ft_isdigit.c \
		ft_isspecial.c \
		ft_itoa.c \
		ft_memset.c \
		ft_nbrlen.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncpy.c \
		ft_strnew.c

LIBFT = $(addprefix $(LB_DIR), $(LB_SRC))
PRINTF = $(addprefix $(PF_DIR), $(PF_SRC))
PF_H = ft_printf.h
LB_H = libft/libft.h
OBJ = $(PF_SRC:.c=.o) $(LB_SRC:.c=.o)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(PRINTF) $(LIBFT) -I $(PF_H) -I $(LB_H)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "[INFO] $(NAME) created"

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	rm -f $(OBJ)
	@echo "[INFO] Objects removed"

fclean: clean
	rm -f $(NAME)
	@echo "[INFO] $(NAME) removed"

re: fclean all
