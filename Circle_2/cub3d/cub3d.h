/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:57:42 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/07 22:40:36 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# define _USE_MATH_DEFINES
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_W	1920
# define WIN_H	1080

# define MAP_X	10
# define MAP_Y	7
# define CUBE_SIZE	15

# define MOVE	0.3
# define FOV	60

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
# define KEY_ESC	53

# define EPSILON	0.000001

typedef struct		s_img
{
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}					t_img;

typedef struct		s_pla
{
	double	x;
	double	y;
	double	th;
}					t_pla;

typedef struct		s_game
{
	void	*mlx;
	void	*win;
	t_img	img1;
	t_img	img2;
	t_pla	player;
	int		map[MAP_X][MAP_Y];
}					t_game;

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

typedef enum		e_line
{
	VERT;
	HORZ;
}					t_line;

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

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

int					key_set(int keycode, t_game *game);
int					draw_minimap(t_game *game);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
double				cast_single_ray(int x, t_game *game, t_wall *wall);
double				get_dist(double x1, double y1, double x2, double y2);
double				deg_to_rad(double th);
void				check_steps(double th, int *xstep, int *ystep);

#endif
