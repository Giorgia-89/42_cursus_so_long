# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 11:27:53 by gd-innoc          #+#    #+#              #
#    Updated: 2023/11/01 16:24:47 by gd-innoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
SRC = src/so_long src/map src/checks src/count src/check_map src/free_memory \
		src/play src/draw_count src/print_error src/check_path src/map_utils \
		src/check_path_utils src/get_next_line src/get_next_line_utils
SRC_BONUS = src_bonus/so_long src_bonus/map src_bonus/checks src_bonus/count \
		src_bonus/check_map src_bonus/free_memory src/map_utils\
		src_bonus/play src_bonus/draw_count src_bonus/print_error src_bonus/check_path \
		src_bonus/check_path_utils src_bonus/get_next_line src_bonus/get_next_line_utils

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
FT_PRINTF = ./printf/libftprintf.a
FT_PRINTF_PATH = ./printf

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

MLX_DIR = ./mlx
MLX_LIB =  $(MLX_DIR)/libmlx_$(UNAME).a
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/urs/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib /lXext -lx11 -framework OpenGL -framework Appkit
endif

all: $(MLX_LIB) $(NAME)

bonus: $(MLX_LIB) $(NAME_BONUS)


$(NAME): $(SRC:=.o)
	make -C $(LIBFT_PATH)
	make -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(SRC:=.o) $(LIBFT) $(FT_PRINTF) -o  $(NAME) $(MLX_FLAGS)

$(NAME_BONUS): $(SRC_BONUS:=.o)
	make -C $(LIBFT_PATH)
	make -C $(FT_PRINTF_PATH)
	$(CC) $(CFLAGS) $(SRC_BONUS:=.o) $(LIBFT) $(FT_PRINTF) -o  $(NAME_BONUS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make clean -C $(LIBFT_PATH)
	make clean -C $(FT_PRINTF_PATH)
	$(RM) $(SRC:=.o) $(SRC_BONUS:=.o)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(FT_PRINTF_PATH)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all bonus
