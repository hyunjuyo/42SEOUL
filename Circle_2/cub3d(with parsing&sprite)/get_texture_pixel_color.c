/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_pixel_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:09:41 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/22 18:25:21 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_pixel_color(int h, int line_len, double invisible, t_game *game,
		t_img *w_img)
{
	double	x_ratio;
	double	y_ratio;
	int		wx;
	int		wy;

	if (game->wall.dir == SOUTH)
		x_ratio = game->wall.x - floor(game->wall.x);
	else if (game->wall.dir == NORTH)
		x_ratio = 1.0 - (game->wall.x - floor(game->wall.x));
	else if (game->wall.dir == EAST)
		x_ratio = game->wall.y - floor(game->wall.y);
	else
		x_ratio = 1.0 - (game->wall.y - floor(game->wall.y));
	wx = (int)(w_img->width * x_ratio);
	y_ratio = (h + line_len * invisible / 2) / line_len;
	wy = (int)(w_img->height * y_ratio);
	return (w_img->data[wy * w_img->width + wx]);
}
