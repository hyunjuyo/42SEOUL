# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 10:49:12 by hyunjuyo          #+#    #+#              #
#    Updated: 2021/04/05 15:24:30 by hyunjuyo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3D

CFLAGS	= -Wall -Wextra -Werror
MLX_FLAGS	= -framework OpenGL -framework AppKit -L./mlx/ -lmlx
MLX_FLAGS2	= -framework Cocoa -framework Metal -framework MetalKit \
			  -framework QuartzCore -L./mlx_mms/ -lmlx
MATH_FLAGS	= -lm
LIBFT_FLAGS	= -L./Libft -lft
MLX_MMS_LIB	= ./libmlx.dylib

SRCS	= ./srcs/main.c ./srcs/utils_1.c ./srcs/utils_2.c \
		  ./srcs/key_set.c ./srcs/key_set2_bonus.c \
		  ./srcs/save_bmp_file.c \
		  ./srcs/screen_size_check.c \
		  ./srcs/parsing/map_parsing.c \
		  ./srcs/parsing/get_next_line.c \
		  ./srcs/parsing/map_parsing_config.c \
		  ./srcs/parsing/map_parsing_utils.c \
		  ./srcs/parsing/save_map_info.c \
		  ./srcs/parsing/map_parsing_wall_check.c \
		  ./srcs/draw_fov/draw_player_fov.c \
		  ./srcs/draw_fov/cast_single_ray.c \
		  ./srcs/draw_fov/get_texture_pixel_color.c \
		  ./srcs/draw_fov/check_n_draw_sprite.c \
		  ./srcs/draw_fov/draw_vert_spr_line.c \
		  ./srcs/exit_game.c
SRCS_B	= ./srcs/main_bonus.c ./srcs/utils_1.c ./srcs/utils_2.c \
		  ./srcs/key_set_bonus.c ./srcs/key_set2_bonus.c \
		  ./srcs/save_bmp_file.c \
		  ./srcs/screen_size_check.c \
		  ./srcs/parsing/map_parsing.c \
		  ./srcs/parsing/get_next_line.c \
		  ./srcs/parsing/map_parsing_config_bonus.c \
		  ./srcs/parsing/map_parsing_config2_bonus.c \
		  ./srcs/parsing/map_parsing_utils.c \
		  ./srcs/parsing/save_map_info_bonus.c \
		  ./srcs/parsing/map_parsing_wall_check.c \
		  ./srcs/draw_fov/draw_player_fov_bonus.c \
		  ./srcs/draw_fov/cast_single_ray.c \
		  ./srcs/draw_fov/get_texture_pixel_color.c \
		  ./srcs/draw_fov/texture_floor_bonus.c \
		  ./srcs/draw_fov/check_n_draw_sprite.c \
		  ./srcs/draw_fov/draw_vert_spr_line_bonus.c \
		  ./srcs/draw_fov/get_sky_color.c \
		  ./srcs/draw_fov/check_player_item_info_bonus.c \
		  ./srcs/draw_minimap/draw_minimap.c \
		  ./srcs/draw_minimap/draw_fov_rays_on_minimap.c \
		  ./srcs/exit_game.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@ -I./includes/ -I./mlx/ -I./Libft/

$(NAME) : $(OBJS)
	gcc $(MLX_FLAGS) $(MATH_FLAGS) $(LIBFT_FLAGS) $(OBJS) $(MLX_MMS_LIB) -o $(NAME)

all : $(NAME)

bonus : $(OBJS_B)
	gcc $(MLX_FLAGS) $(MATH_FLAGS) $(LIBFT_FLAGS) $(OBJS_B) $(MLX_MMS_LIB) -o $(NAME)

clean :
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

bonus_re : fclean bonus
