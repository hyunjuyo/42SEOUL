/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_fov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:35:11 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/10 19:15:40 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_wall_h_pixel(double wdist)
{
	int		fov_vert;
	double	h_ratio;
	int		wall_h;

	fov_vert = deg_to_rad(FOV * WIN_H / WIN_W, 0);
	h_ratio = 1.0 / wdist * tan(fov_vert / 2.0) * 2.0;
	wall_h = (int)(WIN_H * h_ratio);
	return (wall_h);
}

void	draw_one_vert_line(int i, double wdist, t_game *game)
{
	int	wall_h;
	int	w_top;
	int	w_bottom;
	int	w;
	int	h;

	wall_h = get_wall_h_pixel(wdist);
	printf("wall_h : %d\n", wall_h);
	w_top = (WIN_H - wall_h) / 2;
	w_bottom = w_top + wall_h;
	h = 0;
	while (h < WIN_H)
	{
		w = 0;
		while (w < WIN_W)
		{
			if (w == i && h >= w_top && h <= w_bottom)
				game->img1.data[h * WIN_W + w] = CYAN;
			w++;
		}
		h++;
	}
}

int		draw_player_fov(t_game *game)
{
	int		i;
	double	wdist;

	i = 0;
	while (i < WIN_W)
	{
		wdist = cast_single_ray(i, game, WIN_W);
		printf("wdist : %f\n", wdist);
		draw_one_vert_line(i, wdist, game);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img1.img, 1, 1);
	return (0);
}
