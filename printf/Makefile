# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 15:09:05 by giorgia           #+#    #+#              #
#    Updated: 2023/10/27 17:53:52 by gd-innoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf  ft_pointer ft_base ft_strcmp \
ft_putnbr  \
ft_putchar \
ft_putstr  \


CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I.

$(VERBOSE).SILENT:

all:$(NAME)

$(NAME): $(SRC:=.o)
			ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM)	$(SRC:=.o) 
fclean: clean
		$(RM) $(NAME)
re: fclean all