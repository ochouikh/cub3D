# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-mamo <hel-mamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 10:58:50 by hel-mamo          #+#    #+#              #
#    Updated: 2023/07/25 10:02:55 by hel-mamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
HEADER = ./includes/cub3d.h
CC = cc
Cflags = -Wall -Wextra -Werror -Ofast
MFLAGS = -lmlx -framework OpenGL -framework AppKit -Ofast 
SRCF = main.c ./parsing/get_next_line.c ./parsing/file_parser00.c ./parsing/parser_tools.c ./parsing/color_parser.c ./parsing/map_validation.c \
./parsing/texture_parser.c ./parsing/map_parser.c ./parsing/map_parser1.c ./parsing/file_parser01.c \
initialize.c start_drawing.c my_mlx_pixel_put.c draw_map.c get_sprites_tex_1.c  get_sprites_tex_2.c get_sprites_tex_3.c get_sprites_tex_4.c \
render_walls.c put_ennemis.c animate_ennemi.c get_textures.c keys_mouse_hooks.c math_utils.c mlx_draw_utils.c \
colision.c get_colors.c find_horiz_intersec.c find_vert_intersec.c draw_projected_wall.c \
mlx_draw_minimap.c init_sprite_door_info.c animate_ennemi_utils.c search_visible_ennemi.c

OBGF = $(SRCF:%.c=%.o)

all : libfta $(NAME)

$(NAME): $(OBGF)
	$(CC) $(Cflags) $(OBGF) ./Libft/libft.a $(MFLAGS) -o $@

libfta :
	make -C ./Libft

%.o:%.c $(HEADER)
	$(CC) $(Cflags) -c $< -o $@

clean :
	rm -rf $(OBGF)
	make fclean -C ./Libft

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all libfta clean fclean re
