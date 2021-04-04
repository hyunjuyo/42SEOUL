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

int		get_sprite_pixel_color(t_info *info, int j, t_game *game, int start)
{
	double	h_ratio;
	double	w_ratio;
	int		spr_w;
	int		spr_h;
	int		h;

	h = info->h + info->line_len * info->invisible / 2;
	w_ratio = (double)(j - start) / (double)game->spr[info->idx].length;
	h_ratio = (double)h / (double)game->spr[info->idx].length;
	spr_w = game->spr[info->idx].width * w_ratio;
	spr_h = game->spr[info->idx].height * h_ratio;
	return (game->spr[info->idx].data[spr_h * game->spr[info->idx].width
			+ spr_w]);
}

void	draw_vert_spr_line(t_game *game, int idx, int j, int start_spot)
{
	t_info	info;
	int		space;
	int		color;

	info.line_len = game->spr[idx].length;
	info.invisible = 0.0;
	space = (game->conf.win_h - info.line_len);
	if (space < 0)
	{
		info.invisible = (double)abs(space) / (double)info.line_len;
		space = 0;
	}
	info.h = 0;
	while (info.h < info.line_len && info.h < game->conf.win_h)
	{
		color = get_sprite_pixel_color(&info, j, game, start_spot);
		if (check_color_area(color, BLUE, 0x87) != 111)
			game->img1.data[(space / 2 + info.h) * game->conf.win_w + j] =
				color;
		info.h++;
	}
}
