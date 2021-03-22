/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one_vert_sprite_line.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:38:13 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/22 13:52:08 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_sprite_pixel_color(int idx, int h, int j, t_game *game, int start)
{
	double	h_ratio;
	double	w_ratio;
	int		spr_w;
	int		spr_h;

	w_ratio = (double)(j - start) / (double)game->spr[idx].length;
	h_ratio = (double)h / (double)game->spr[idx].length;
	spr_w = game->spr[idx].width * w_ratio;
	spr_h = game->spr[idx].height * h_ratio;
	return(game->spr[idx].data[spr_h * game->spr[idx].width + spr_w]);
}

void	draw_one_vert_sprite_line(t_game *game, int idx, int j, int start_spot)
{
	int	h;
	int	space;
	int	color;

	space = (game->conf.win_h - game->spr[idx].length) / 2;
	h = 0;
	while (h < game->spr[idx].length && h < game->conf.win_h)
	{
		color = get_sprite_pixel_color(idx, h, j, game, start_spot);
		if (color != WHITE)
			game->img1.data[(space + h) * game->conf.win_w + j] = color;
		h++;
	}
}
