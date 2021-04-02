/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:30:27 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/02 15:50:57 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_jumping_check(t_game *game)
{
	if (game->player.jump < 0)
	{
		game->player.jump--;
		game->player.view_h = sin((M_PI / 5) * game->player.jump) * 0.15;
		if (game->player.jump == -5)
		{
			game->player.jump = 0;
			game->player.view_h = 0.0;
		}

	}
	if (game->player.jump > 0)
	{
		game->player.jump++;
		game->player.view_h = sin((M_PI / 12) * game->player.jump) * 0.35;
		if (game->player.jump == 12)
		{
			game->player.jump = -1;
			game->player.view_h = 0.0;
		}
	}
}

int		check_color_area(int color, int refer_color, int area)
{
	int		r;
	int		g;
	int		b;
	int		temp;
	int		result;

	result = 0;
	b = color % (0x10 * 0x10);
	color = color / (0x10 * 0x10);
	g = color % (0x10 * 0x10);
	color = color / (0x10 * 0x10);
	r = color % (0x10 * 0x10);
	temp = refer_color % (0x10 * 0x10);
	if (b >= temp - area && b <= temp + area)
		result += 1;
	refer_color = refer_color / (0x10 * 0x10);
	temp = refer_color % (0x10 * 0x10);
	if (g >= temp - area && g <= temp + area)
		result += 10;
	refer_color = refer_color / (0x10 * 0x10);
	temp = refer_color % (0x10 * 0x10);
	if (r >= temp - area && r <= temp + area)
		result += 100;
	return (result);
}

void	fade_setting(t_color *rgb, double dist, t_game *game, double weight)
{
	double	dark_dist;
	double	fade_dist;
	double	fade_ratio;

	dark_dist = get_dist(1.0, 1.0, game->conf.map_x - 1, game->conf.map_y - 1);
	fade_dist = dark_dist * 0.3;
	if (dist > fade_dist)
	{
		fade_ratio = 1.0 - ((dist - fade_dist) / (dark_dist - fade_dist))
			* weight;
		if (fade_ratio < 0.39)
			fade_ratio = 0.39;
		rgb->r *= fade_ratio;
		rgb->g *= fade_ratio;
		rgb->b *= fade_ratio;
	}
}

int		fade_color(int color, double dist, t_game *game, double weight)
{
	t_color	rgb;
	int		fade_color;

	rgb.b = color % (0x10 * 0x10);
	color = color / (0x10 * 0x10);
	rgb.g = color % (0x10 * 0x10);
	color = color / (0x10 * 0x10);
	rgb.r = color % (0x10 * 0x10);
	fade_setting(&rgb, dist, game, weight);
	fade_color = rgb.r * 0x10 * 0x10 * 0x10 * 0x10 + rgb.g * 0x10 * 0x10
		+ rgb.b;
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
