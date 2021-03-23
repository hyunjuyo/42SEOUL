/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:30:27 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/23 13:34:18 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fade_setting(int *r, int *g, int *b, double dist, t_game *game)
{
	double	dark_dist;
	double	fade_dist;
	double	fade_ratio;

	dark_dist = get_dist(1.0, 1.0, game->conf.map_x - 1, game->conf.map_y - 1);
	fade_dist = dark_dist * 0.3;
	if (dist > fade_dist)
	{
		fade_ratio = 1.0 - ((dist - fade_dist) * 1.5 / (dark_dist - fade_dist));
		if (fade_ratio < 0.5)
			fade_ratio = 0.5;
		*r *= fade_ratio;
		*g *= fade_ratio;
		*b *= fade_ratio;
	}
}

int		fade_color(int color, double dist, t_game *game)
{
	int		r;
	int		g;
	int		b;
	int		fade_color;

	b = color % (0x10 * 0x10);
	color = color / (0x10 * 0x10);
	g = color % (0x10 * 0x10);
	color = color / (0x10 * 0x10);
	r = color % (0x10 * 0x10);
	fade_setting(&r, &g, &b, dist, game);
	fade_color = r * 0x10 * 0x10 * 0x10 * 0x10 + g * 0x10 * 0x10 + b;
	return (fade_color);
}

void	check_steps(double th, int *xstep, int *ystep)
{
	if (cos(th) > EPSILON)
		*xstep = 1;
	else if (cos(th) < -EPSILON)
		*xstep = -1;
	else
		*xstep = 0;
	if (sin(th) > EPSILON)
		*ystep = 1;
	else if (sin(th) < -EPSILON)
		*ystep = -1;
	else
		*ystep = 0;
}
