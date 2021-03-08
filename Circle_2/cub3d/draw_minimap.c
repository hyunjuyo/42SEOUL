/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:23:20 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/08 21:39:29 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_one_square(t_game *game, int x_start, int y_start)
{
	int	w;
	int	h;
	int	total_w;

	total_w = MAP_Y * CUBE_SIZE;
	h = 0;
	while (h < CUBE_SIZE)
	{
		w = 0;
		while (w < CUBE_SIZE)
		{
			game->img2.data[(y_start + h) * total_w + (x_start + w)] = WHITE;
			w++;
		}
		h++;
	}
}

void	draw_squares(t_game *game)
{
	int y;
	int x;

	y = MAP_Y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < MAP_X)
		{
			if (game->map[x][y] == 1)
				draw_one_square(game, x * CUBE_SIZE,
						(MAP_Y - 1 - y) * CUBE_SIZE);
			x++;
		}
		y--;
	}
}

void	draw_one_ray(int i, int px, int py, t_game *game, t_wall *wall)
{
	int	rx;
	int	ry;
	int	xstep;
	int	ystep;
	int	w;

	w = MAP_X * CUBE_SIZE;
	check_steps(game->player.ray_th, &xstep, &ystep);
	rx = px + xstep;
	while (xstep != 0 && rx != (int)(wall->x * CUBE_SIZE))
	{
		ry = tan(game->player.ray_th) * (rx - px) + py;
		game->img2.data[(MAP_Y * CUBE_SIZE - 1 - ry) * w + rx] = GREEN;
		rx += xstep;
	}
	ry = py;
	while (++ry < (int)(wall->y * CUBE_SIZE) && xstep == 0 &&
			sin(game->player.ray_th) > 0)
			game->img2.data[(MAP_Y * CUBE_SIZE - 1 - ry) * w + rx] = GREEN;
	while (--ry > (int)(wall->y * CUBE_SIZE) && xstep == 0 &&
			sin(game->player.ray_th) < 0)
			game->img2.data[(MAP_Y * CUBE_SIZE - 1 - ry) * w + rx] = GREEN;
/*
	if (xstep == 0 && sin(game->player.ray_th) > 0)
	{
		ry = py;
		while (++ry < (int)(wall->y * CUBE_SIZE))
			game->img2.data[(MAP_Y * CUBE_SIZE - 1 - ry) * w + rx] = GREEN;
	}
	if (xstep == 0 && sin(game->player.ray_th) < 0)
	{
		ry = py;
		while (--ry > (int)(wall->y * CUBE_SIZE))
			game->img2.data[(MAP_Y * CUBE_SIZE - 1 - ry) * w + rx] = GREEN;
	}
*/
}

void	draw_fov_rays(t_game *game, t_wall *wall)
{
	int		i;
	double	dist;
	int		px;
	int		py;
	int		total_w;

	total_w = MAP_X * CUBE_SIZE;
	px = (int)(game->player.x * CUBE_SIZE);
	py = (int)(game->player.y * CUBE_SIZE);
	game->img2.data[(MAP_Y * CUBE_SIZE - 1 - py) * total_w + px] = BLUE;
	i = 0;
	while (i < WIN_W)
	{
		dist = cast_single_ray(i, game, wall);
		draw_one_ray(i, px, py, game, wall);
		i++;
	}
}

int		draw_minimap(t_game *game)
{
	t_wall	wall;

	draw_squares(game);
	draw_fov_rays(game, &wall);
	mlx_put_image_to_window(game->mlx, game->win, game->img2.img, 10, 10);
	return (0);
}
