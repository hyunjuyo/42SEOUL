/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_pixel_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:09:41 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/01 15:39:59 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_pixel_color(int i, int h, int line_len, t_game *game,
		t_img *w_img)
{
	double	x_ratio;
	double	y_ratio;
	int		wx;
	int		wy;

	if (game->wall[i].dir == SOUTH)
		x_ratio = game->wall[i].x - floor(game->wall[i].x);
	else if (game->wall[i].dir == NORTH)
		x_ratio = 1.0 - (game->wall[i].x - floor(game->wall[i].x));
	else if (game->wall[i].dir == EAST)
		x_ratio = game->wall[i].y - floor(game->wall[i].y);
	else
		x_ratio = 1.0 - (game->wall[i].y - floor(game->wall[i].y));
	wx = (int)(w_img->width * x_ratio);
	y_ratio = (h + line_len * w_img->invisible_c) / line_len;
	wy = (int)(w_img->height * y_ratio);
	return (w_img->data[wy * w_img->width + wx]);
}
