/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vert_spr_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:38:13 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/31 16:42:35 by hyunjuyo         ###   ########.fr       */
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

void	draw_vert_spr_line(t_game *game, int idx, int j, int start_spot)
{
	int		h;
	int		space;
	int		color;
	double	invisible;
	int		line_len;

	line_len = game->spr[idx].length;
	invisible = 0.0;
	space = (game->conf.win_h - line_len);
	if (game->conf.win_h - line_len < 0)
	{
		invisible = (double)abs(space) / (double)line_len;
		space = 0;
	}
	h = 0;
	while (h < line_len && h < game->conf.win_h)
	{
		color = get_sprite_pixel_color(idx, h + line_len * invisible / 2, j,
				game, start_spot);
		if (check_color_area(color, BLUE, 0x87) != 111)
			game->img1.data[(space / 2 + h) * game->conf.win_w + j] = color;
		h++;
	}
}
