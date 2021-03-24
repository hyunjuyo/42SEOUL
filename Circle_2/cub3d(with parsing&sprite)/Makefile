

NAME	= Cub3D

CFLAGS	= -Wall -Wextra -Werror
MLX_FLAGS	= -framework OpenGL -framework AppKit -L./mlx/ -lmlx
MATH_FLAGS	= -lm
LIBFT_FLAGS	= -L./Libft -lft

SRCS	= ./srcs/main.c ./srcs/map_parsing.c ./srcs/map_parsing_utils_1.c \
		  ./srcs/map_parsing_utils_2.c ./srcs/save_map_info.c ./srcs/utils_1.c \
		  ./srcs/utils_2.c ./srcs/get_next_line.c ./srcs/draw_player_fov.c \
		  ./srcs/cast_single_ray.c ./srcs/get_texture_pixel_color.c \
		  ./srcs/check_n_draw_sprite.c ./srcs/draw_one_vert_sprite_line.c \
		  ./srcs/key_set.c
OBJS	= $(SRCS:.c=.o)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@ -I./includes/ -I./mlx/ -I./Libft/

$(NAME) : $(OBJS)
	gcc $(MLX_FLAGS) $(LIBFT_FLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
