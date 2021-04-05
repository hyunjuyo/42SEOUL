/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:23:20 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/05 13:38:15 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_one_square(t_game *game, int x_start, int y_start, int color)
{
	int	w;
	int	h;
	int	total_w;

	total_w = game->conf.win_w;
	h = 0;
	while (h < game->cubsize)
	{
		w = 0;
		while (w < game->cubsize)
		{
			game->img1.data[(y_start + h) * total_w + (x_start + w)] = color;
			w++;
		}
		h++;
	}
}

void	draw_squares(t_game *game)
{
	int y;
	int x;

	y = game->conf.map_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < game->conf.map_x)
		{
			if (game->map[x][y] == '1')
				draw_one_square(game, x * game->cubsize,
						(game->conf.map_y - 1 - y) * game->cubsize, WHITE);
			else if (game->map[x][y] == '2')
				draw_one_square(game, x * game->cubsize,
						(game->conf.map_y - 1 - y) * game->cubsize, 0x509090);
			else if (game->map[x][y] == '3')
				draw_one_square(game, x * game->cubsize,
						(game->conf.map_y - 1 - y) * game->cubsize, 0x900090);
			else
				draw_one_square(game, x * game->cubsize,
						(game->conf.map_y - 1 - y) * game->cubsize, 0x202020);
			x++;
		}
		y--;
	}
}

int		draw_minimap(t_game *game)
{
	game->cubsize = CUBE_SIZE;
	if (game->conf.map_x * game->cubsize > game->conf.win_w / 3
			|| game->conf.map_y * game->cubsize > game->conf.win_h / 3)
		game->cubsize = CUBE_SIZE * 0.6;
	if (game->conf.map_x * game->cubsize > game->conf.win_w / 2
			|| game->conf.map_y * game->cubsize > game->conf.win_h / 2)
	{
		printf("Error\nwin_size is too small for the minimap\n");
		exit(1);
	}
	draw_squares(game);
	draw_fov_rays_on_minimap(game);
	return (0);
}
