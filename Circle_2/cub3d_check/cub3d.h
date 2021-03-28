/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:57:42 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/15 12:04:28 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# define _USE_MATH_DEFINES
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "libft.h"

# define WIN_W	1280
# define WIN_H	720

# define MAP_X	20
# define MAP_Y	12
# define CUBE_SIZE	20
# define MINIMAP_RAY_NUM	7

# define MOVE_SPEED	0.7
# define ROT_SPEED_RAD	0.07
# define FOV	60

# define WALL_NO	"./textures/wall_n.xpm"
# define WALL_SO	"./textures/wall_s.xpm"
# define WALL_WE	"./textures/wall_w.xpm"
# define WALL_EA	"./textures/wall_e.xpm"

# define WHITE	0xFFFFFF
# define BLACK	0x000000
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define YELLOW	0xFFFF00
# define CYAN	0x00FFFF
# define MAGENTA	0xFF00FF

# define X_EVENT_KEY_PRESS	2
# define KEY_A		0
# define KEY_D		2
# define KEY_S		1
# define KEY_W		13
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_ESC	53

# define EPSILON	0.000001

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_conf
{
	int		win_w;
	int		win_h;
	int		map_x;
	int		map_y;
	char	*wall_no;
	char	*wall_so;
	char	*wall_we;
	char	*wall_ea;
	char	*wall_sp;
	int		ceil;
	int		floor;
	t_bool	map_start;
}					t_conf;

typedef struct		s_img
{
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_l;
	int		endian;
}					t_img;

typedef struct		s_pla
{
	double	x;
	double	y;
	double	th;
	double	ray_th;
}					t_pla;

typedef enum		e_dir
{
	EAST,
	WEST,
	SOUTH,
	NORTH
}					t_dir;

typedef struct		s_wall
{
	double	x;
	double	y;
	t_dir	dir;
}					t_wall;

typedef struct		s_game
{
	void	*mlx;
	void	*win;
	t_img	img1;
	t_img	img2;
	t_pla	player;
	t_wall	wall;
	t_conf	conf;
	int		map[MAP_X][MAP_Y];
}					t_game;

typedef enum		e_line
{
	VERT,
	HORZ
}					t_line;

typedef struct		s_chk_pnt
{
	double	px;
	double	py;
	double	nx;
	double	ny;
	double	f_nx;
	double	g_ny;
	t_line	line;
	int		mapx;
	int		mapy;
	int		xstep;
	int		ystep;
	t_bool	hit_wall;

}					t_chk_pnt;

typedef struct		s_ray
{
	int		rx;
	int		ry;
	int		xstep;
	int		ystep;
	int		w;
	int		h;
}					t_ray;

int					key_set(int keycode, t_game *game);
int					draw_minimap(t_game *game);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
double				cast_single_ray(int x, t_game *game, int n);
double				get_dist(double x1, double y1, double x2, double y2);
double				deg_to_rad(double th, int type);
double				rad_to_deg(double th);
void				check_steps(double th, int *xstep, int *ystep);
void				draw_fov_rays_on_minimap(t_game *game);
int					draw_player_fov(t_game *game);
int					get_texture_pixel_color(int i, int pixels, double invisible,
		t_game *game, t_img *w_img);

#endif
