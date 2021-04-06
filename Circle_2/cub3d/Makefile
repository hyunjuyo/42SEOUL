# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/25 10:49:12 by hyunjuyo          #+#    #+#              #
#    Updated: 2021/04/06 17:02:42 by hyunjuyo         ###   ########.fr        #
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

SRCS	= ./srcs/main.c \
		  ./srcs/keyset_n_utils/utils_1.c \
		  ./srcs/keyset_n_utils/utils_2.c \
		  ./srcs/keyset_n_utils/key_set.c \
		  ./srcs/keyset_n_utils/key_set2_bonus.c \
		  ./srcs/keyset_n_utils/save_bmp_file.c \
		  ./srcs/keyset_n_utils/screen_size_check.c \
		  ./srcs/parsing/map_parsing.c \
		  ./srcs/parsing/get_next_line.c \
		  ./srcs/parsing/map_parsing_config.c \
		  ./srcs/parsing/map_parsing_utils.c \
		  ./srcs/parsing/save_map_info.c \
		  ./srcs/parsing/map_parsing_wall_check.c \
		  ./srcs/draw_fov/draw_player_fov.c \
		  ./srcs/draw_fov/cast_single_ray.c \
		  ./srcs/draw_fov/get_texture_pixel_color.c \
		  ./srcs/draw_fov/sprite/check_n_draw_sprite.c \
		  ./srcs/draw_fov/sprite/draw_vert_spr_line.c \
		  ./srcs/keyset_n_utils/exit_game.c
SRCS_B	= ./srcs/main_bonus.c \
		  ./srcs/keyset_n_utils/utils_1.c \
		  ./srcs/keyset_n_utils/utils_2.c \
		  ./srcs/keyset_n_utils/key_set_bonus.c \
		  ./srcs/keyset_n_utils/key_set2_bonus.c \
		  ./srcs/keyset_n_utils/utils_3_bonus.c \
		  ./srcs/keyset_n_utils/save_bmp_file_bonus.c \
		  ./srcs/keyset_n_utils/screen_size_check.c \
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
		  ./srcs/draw_fov/etc/texture_floor_bonus.c \
		  ./srcs/draw_fov/sprite/check_n_draw_sprite.c \
		  ./srcs/draw_fov/sprite/draw_vert_spr_line_bonus.c \
		  ./srcs/draw_fov/etc/get_sky_color.c \
		  ./srcs/draw_fov/etc/check_player_item_info_bonus.c \
		  ./srcs/draw_minimap/draw_minimap.c \
		  ./srcs/draw_minimap/draw_fov_rays_on_minimap.c \
		  ./srcs/keyset_n_utils/exit_game_bonus.c

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@ -I./includes/ -I./mlx/ -I./Libft/

$(NAME) : $(OBJS)
	make bonus -C ./Libft/
	make -C ./mlx/
	make -C ./mlx_mms/
	cp ./mlx_mms/libmlx.dylib .
	gcc $(MLX_FLAGS) $(MATH_FLAGS) $(LIBFT_FLAGS) $(OBJS) $(MLX_MMS_LIB) -o $(NAME)

all : $(NAME)

bonus : $(OBJS_B)
	make bonus -C ./Libft/
	make -C ./mlx/
	make -C ./mlx_mms/
	cp ./mlx_mms/libmlx.dylib .
	gcc $(MLX_FLAGS) $(MATH_FLAGS) $(LIBFT_FLAGS) $(OBJS_B) $(MLX_MMS_LIB) -o $(NAME)

clean :
	rm -f $(OBJS) $(OBJS_B) $(MLX_MMS_LIB)
	make clean -C ./Libft/
	make clean -C ./mlx/
	make clean -C ./mlx_mms/

fclean : clean
	rm -f $(NAME)
	make fclean -C ./Libft/
	make clean -C ./mlx/
	make clean -C ./mlx_mms/

re : fclean all

bonus_re : fclean bonus
