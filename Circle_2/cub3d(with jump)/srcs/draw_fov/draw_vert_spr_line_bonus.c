/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vert_spr_line_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:38:13 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/01 17:16:52 by hyunjuyo         ###   ########.fr       */
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
	t_space	space;
	int		color;
	double	invisible_c;
	int		line_len;
	int		vh;

	line_len = game->spr[idx].length;
	space.line_len = line_len;
	vh = 0;
	if (game->player.view_h != 0.0)
		vh = line_len * game->player.view_h;
	invisible_c = 0.0;
	space.c = (game->conf.win_h - line_len) / 2 + vh;
	if (space.c < 0)
	{
		space.line_len += space.c;
		invisible_c = (double)abs(space.c) / (double)line_len;
		space.c = 0;
	}
	h = 0;
	while (h < space.line_len && space.c + h < game->conf.win_h)
	{
		color = get_sprite_pixel_color(idx, h + line_len * invisible_c, j,
				game, start_spot);
		if (check_color_area(color, BLUE, 0x87) != 111)
			game->img1.data[(space.c + h) * game->conf.win_w + j]
				= fade_color(color, game->spr[idx].dist, game, 1.5);
		h++;
	}
}
