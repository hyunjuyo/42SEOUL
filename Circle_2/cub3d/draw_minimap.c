/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:23:20 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/10 11:16:17 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_one_square(t_game *game, int x_start, int y_start, int color)
{
	int	w;
	int	h;
	int	total_w;

	total_w = MAP_X * CUBE_SIZE;
	h = 0;
	while (h < CUBE_SIZE)
	{
		w = 0;
		while (w < CUBE_SIZE)
		{
			game->img2.data[(y_start + h) * total_w + (x_start + w)] = color;
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
						(MAP_Y - 1 - y) * CUBE_SIZE, WHITE);
			else
				draw_one_square(game, x * CUBE_SIZE,
						(MAP_Y - 1 - y) * CUBE_SIZE, BLACK);
			x++;
		}
		y--;
	}
}

int		draw_minimap(t_game *game)
{
	t_wall	wall;

	draw_squares(game);
	draw_fov_rays_on_minimap(game, &wall);
	mlx_put_image_to_window(game->mlx, game->win, game->img2.img, 10, 10);
	return (0);
}
