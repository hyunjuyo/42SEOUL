/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:23:20 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/02 18:05:20 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_one_square(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < M_TILE_SIZE)
	{
		j = 0;
		while (j < M_TILE_SIZE)
		{
			game->img.data[(y + i) * MAP_W + (x + j)] = WHITE;
			j++;
		}
		i++;
	}
}

void	draw_squares(t_game *game)
{
	int row;
	int col;

	row = 0;
	while (row < M_ROW)
	{
		col = 0;
		while (col < M_COL)
		{
			if (game->map[row][col] == 1)
				draw_one_square(game, col * M_TILE_SIZE, row * M_TILE_SIZE);
			col++;
		}
		row++;
	}
}

int		draw_minimap(t_game *game)
{
	draw_squares(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 10, 10);
	return (0);
}
