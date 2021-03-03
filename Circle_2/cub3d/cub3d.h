/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:57:42 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/03 18:12:47 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WIN_W	1920
#define WIN_H	1080
#define FOV		60

/* Map Info */
#define MAP_X	10
#define MAP_Y	7

/* Minimap Info */
#define M_TILE_SIZE	15
#define MINIMAP_W	MAP_X * M_TILE_SIZE
#define MINIMAP_H	MAP_Y * M_TILE_SIZE

/* Player Info */
#define MOVE	0.3

#define WHITE	0xFFFFFF
#define BLACK	0x000000
#define RED		0xFF0000
#define GREEN	0x00FF00
#define BLUE	0x0000FF
#define YELLOW	0xFFFF00
#define CYAN	0x00FFFF
#define MAGENTA	0xFF00FF

#define X_EVENT_KEY_PRESS	2
#define KEY_A	0
#define KEY_D	2
#define KEY_S	1
#define KEY_W	13
#define KEY_ESC	53

static const double	fov_h = FOV * M_PI / 180.0;

typedef struct	s_img
{
    void	*img;
    int		*data;
    int		bpp;
    int		size_l;
    int		endian;
}				t_img;

typedef struct	s_pla
{
    double	x;
    double	y;
    double	th;
}				t_pla;

typedef struct	s_game
{
    void	*mlx;
    void	*win;
    t_img	img;
    t_pla	player;
    int		map[MAP_X][MAP_Y];
}				t_game;

typedef enum	{EA, WE, SO, NO}	dir_w;

typedef struct	s_wall
{
    double	x;
    double	y;
    dir_w	dir;
}				t_wall;

int		key_set(int keycode, t_game *game);
int		draw_minimap(t_game *game);
void	*ft_memcpy(void *dst, const void *src, size_t n);
double	cast_single_ray(int x, t_game *game);
double	get_dist(double x1, double y1, double x2, double y2);
double	deg_to_rad(double th);
