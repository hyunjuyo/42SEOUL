/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vert_spr_line_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:38:13 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/05 17:31:53 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		get_sprite_pixel_color(t_info *info, int j, t_game *game)
{
	double	h_ratio;
	double	w_ratio;
	int		spr_w;
	int		spr_h;
	int		h;

	h = info->h + info->line_len * info->invisible;
	w_ratio = (double)(j - info->start) / (double)game->spr[info->idx].length;
	h_ratio = (double)h / (double)game->spr[info->idx].length;
	spr_w = game->spr[info->idx].width * w_ratio;
	spr_h = game->spr[info->idx].height * h_ratio;
	return (game->spr[info->idx].data[spr_h * game->spr[info->idx].width
			+ spr_w]);
}

void	do_draw_line(t_info *info, t_space *space, t_game *game, int j)
{
	int	color;

	info->h = 0;
	while (info->h < space->line_len && space->ceil + info->h
			< game->conf.win_h)
	{
		color = get_sprite_pixel_color(info, j, game);
		if (check_color_area(color, BLUE, 0x87) != 111)
			game->img1.data[(space->ceil + info->h) * game->conf.win_w + j] =
				fade_color(color, game->spr[info->idx].dist, game, 1.5);
		info->h++;
	}
}

void	draw_vert_spr_line(t_game *game, int idx, int j, int start_spot)
{
	t_info	info;
	t_space	space;

	info.line_len = game->spr[idx].length;
	space.line_len = info.line_len;
	space.vh = 0;
	if (game->player.view_h != 0.0)
		space.vh = info.line_len * game->player.view_h;
	info.invisible = 0.0;
	space.ceil = (game->conf.win_h - info.line_len) / 2 + space.vh;
	if (space.ceil < 0)
	{
		space.line_len += space.ceil;
		info.invisible = (double)abs(space.ceil) / (double)info.line_len;
		space.ceil = 0;
	}
	info.idx = idx;
	info.start = start_spot;
	do_draw_line(&info, &space, game, j);
}
