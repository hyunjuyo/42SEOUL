/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:23:20 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/03 17:48:36 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_one_square(t_game *game, int x_start, int y_start)
{
	int	w;
	int	h;

	h = 0;
	while (h < M_TILE_SIZE)
	{
		w = 0;
		while (w < M_TILE_SIZE)
		{
			game->img.data[(y_start + h) * MINIMAP_W + (x_start + w)] = WHITE;
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
				draw_one_square(game, x * M_TILE_SIZE,
						(MAP_Y - 1 - y) * M_TILE_SIZE);
			x++;
		}
		y--;
	}
}
/*
void	draw_fov(t_game *game)
{
	int		i;
	double	dist;

	i = 0;
	while (i < WIN_W)
	{
		dist = cast_single_ray(i, game);
		i++;
	}
}
*/
int		draw_minimap(t_game *game)
{
	draw_squares(game);
//	draw_fov(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 10, 10);
	return (0);
}
