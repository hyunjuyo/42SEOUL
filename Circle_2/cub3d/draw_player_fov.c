/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_fov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:35:11 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/11 18:41:55 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_screen(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < WIN_H)
	{
		w = 0;
		while (w < WIN_W)
		{
			game->img1.data[h * WIN_W + w] = BLACK;
			w++;
		}
		h++;
	}
}

int		get_wall_h_pixels(double wdist)
{
	double	fov_vert;
	double	h_ratio;
	int		wall_h;

	fov_vert = deg_to_rad(FOV * WIN_H / WIN_W, 0);
	h_ratio = 1.0 / (wdist * tan(fov_vert / 2.0) * 2.0);
	wall_h = (int)(WIN_H * h_ratio);
	return (wall_h);
}

void	get_wall_texture(t_game *game, t_img *w_img)
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
	int		wall_h;
	int		space;
	int		h;
//	t_img	w_img;
//	int		pixel_color;

//	get_wall_texture(game, &w_img);
	wall_h = get_wall_h_pixels(wdist);
	if ((space = (WIN_H - wall_h) / 2) < 0)
		space = 0;
	h = space + 1;
	while (h <= WIN_H - space)
	{
//		pixel_color = draw_texture_to_wall(h - (space + 1), h, WIN_H - space, game, &w_img);
		game->img1.data[h * WIN_W + i] = WHITE;
		h++;
	}
}

int		draw_player_fov(t_game *game)
{
	int			i;
	double		wdist;

	clear_screen(game);
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
