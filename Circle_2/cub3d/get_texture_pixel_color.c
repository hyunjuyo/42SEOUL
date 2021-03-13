/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture_to_wall.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:09:41 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/13 18:50:00 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_pixel_color(int i, int pixels, double invisible, t_game *game,
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
	wx = (int)(w_img->width * x_ratio) - 1;
	y_ratio = (i + 1) / pixels;
	wy = (int)(w_img->height * y_ratio) - 1;
	wy += (int)(w_img->height * invisible);
	return (w_img->data[wy * w_img->width + wx]);
}
