/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_fov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:35:11 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/13 19:35:12 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_screen(t_game *game, int color)
{
	int	h;
	int	w;

	h = 0;
	while (h < WIN_H)
	{
		w = 0;
		while (w < WIN_W)
		{
			game->img1.data[h * WIN_W + w] = color;
			w++;
		}
		h++;
	}
}

int		get_vert_line_length(double wdist)
{
	double	fov_vert;
	double	h_ratio;
	int		length;

	fov_vert = deg_to_rad(FOV * WIN_H / WIN_W, 0);
	h_ratio = 1.0 / (wdist * tan(fov_vert / 2.0) * 2.0);
	length = (int)(WIN_H * h_ratio);
	return (length);
}

void	get_wall_texture_file(t_game *game, t_img *w_img)
{
	char	*img_path;

	if (game->wall.dir == NORTH)
		img_path = WALL_NO;
	else if (game->wall.dir == SOUTH)
		img_path = WALL_SO;
	else if (game->wall.dir == WEST)
		img_path = WALL_WE;
	else
		img_path = WALL_EA;
	w_img->img = mlx_xpm_file_to_image(game->mlx, img_path, &w_img->width,
			&w_img->height);
	w_img->data = (int *)mlx_get_data_addr(w_img->img, &w_img->bpp,
			&w_img->size_l, &w_img->endian);
}

void	draw_one_vert_line(int i, double wdist, t_game *game)
{
	int		line_len;
	int		space;
	int		h;
	t_img	w_img;
	double	invisible;

	get_wall_texture_file(game, &w_img);
	line_len = get_vert_line_length(wdist);
	invisible = 0.0;
	if ((space = (WIN_H - line_len) / 2) < 0)
	{
		invisible = (space * -1) / line_len;
		space = 0;
	}
	h = 0;
	while (h < line_len * (1.0 - invisible * 2.0) && h < WIN_H)
	{
		game->img1.data[(space + h) * WIN_W + i]
			= get_texture_pixel_color(h, line_len, invisible, game, &w_img);
		h++;
	}
}

int		draw_player_fov(t_game *game)
{
	int			i;
	double		wdist;

	clear_screen(game, BLACK);
	i = 0;
	while (i < WIN_W)
	{
		wdist = cast_single_ray(i, game, WIN_W);
		wdist *= cos(game->player.th - game->player.ray_th);
		draw_one_vert_line(i, wdist, game);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img1.img, 0, 0);
	return (0);
}
