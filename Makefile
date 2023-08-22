# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paescano <paescano@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 16:36:35 by paescano          #+#    #+#              #
#    Updated: 2023/08/17 12:41:56 by paescano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iinclude/

SOURCE := source/so_long.c source/utils/ft_bzero.c source/utils/ft_error.c \
	source/utils/ft_exit.c source/utils/ft_putnbr.c source/utils/ft_strncmp.c \
	source/utils/ft_replace_char.c source/utils/ft_putstr_error.c \
	source/controllers/game_controller.c source/controllers/get_map.c \
	source/controllers/loader_graphics.c source/controllers/loader_images.c \
	source/controllers/update_player.c source/checkers/check_args.c \
	source/checkers/check_characters.c source/checkers/check_map.c \
	source/checkers/check_routes.c source/checkers/check_walls.c \

GETNEXTLINE := get_next_line/get_next_line_utils.c get_next_line/get_next_line.c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all: $(NAME)

$(NAME):
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:
	make clean -C $(MINILIBX)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norminette:
	norminette $(SOURCE) $(GETNEXTLINE) include/*.h

.PHONY: all clean fclean re norminette