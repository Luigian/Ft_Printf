# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusanche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 18:24:34 by lusanche          #+#    #+#              #
#    Updated: 2019/11/25 16:20:48 by lusanche         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_PF = ft_printf_*.c
SRC_LB = libft/ft*.c
HEAD_PF = ft_printf.h
HEAD_LB = libft/libft.h
OBJECTS = *.o

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC_PF) $(SRC_LB) -I $(HEAD_PF) -I $(HEAD_LB)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	@echo "[INFO] $(NAME) created"

.PHONY: all, clean, fclean, re

all: $(NAME)

clean:
	rm -f $(OBJECTS)
	@echo "[INFO] Objects removed"

fclean: clean
	rm -f $(NAME)
	@echo "[INFO] $(NAME) removed"

re: fclean all
