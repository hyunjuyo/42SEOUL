/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_fov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:35:11 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/31 13:59:19 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_screen(t_game *game, int ceil_color, int floor_color)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->conf.win_h)
	{
		w = 0;
		while (w < game->conf.win_w)
		{
			if (h < game->conf.win_h / 2)
				game->img1.data[h * game->conf.win_w + w] = ceil_color;
			else
				game->img1.data[h * game->conf.win_w + w] = floor_color;
			w++;
		}
		h++;
	}
}

int		get_vert_line_length(double wdist, t_game *game)
{
	double	fov_vert;
	double	h_ratio;
	int		length;

	fov_vert = deg_to_rad(FOV * game->conf.win_h / game->conf.win_w, 0);
	h_ratio = 1.0 / (wdist * tan(fov_vert / 2.0) * 2.0);
	length = (int)(game->conf.win_h * h_ratio);
	return (length);
}

void	get_wall_texture_file(int i, t_game *game, t_img *w_img)
{
	char	*img_path;

	if (game->wall[i].dir == NORTH)
		img_path = game->conf.wall_no;
	else if (game->wall[i].dir == SOUTH)
		img_path = game->conf.wall_so;
	else if (game->wall[i].dir == WEST)
		img_path = game->conf.wall_we;
	else
		img_path = game->conf.wall_ea;
	if (!(w_img->img = mlx_xpm_file_to_image(game->mlx, img_path, &w_img->width,
			&w_img->height)))
		printf("[wall]mlx_xpm_file_to_image() failed\nError\n");
	w_img->data = (int *)mlx_get_data_addr(w_img->img, &w_img->bpp,
			&w_img->size_l, &w_img->endian);
}

void	draw_one_vert_line(int i, double wdist, t_game *game)
{
	int		line_len;
	int		space;
	int		h;
	t_img	w_img;

	get_wall_texture_file(i, game, &w_img);
	line_len = get_vert_line_length(wdist, game);
	w_img.invisible = 0.0;
	space = game->conf.win_h - line_len;
	if (game->conf.win_h - line_len < 0)
	{
		w_img.invisible = (double)abs(space) / (double)line_len;
		space = 0;
	}
	h = 0;
	while (h < line_len && h < game->conf.win_h)
	{
		game->img1.data[(space / 2 + h) * game->conf.win_w + i]
			= get_texture_pixel_color(i, h, line_len, game, &w_img);
		h++;
	}
}

int		draw_player_fov(t_game *game)
{
	int			i;
	double		wdist;

	clear_screen(game, game->conf.ceil, game->conf.floor);
	game->spr_in_fov = (char *)ft_calloc(game->conf.map_x * game->conf.map_y,
			sizeof(char));
	game->wall = (t_wall *)ft_calloc(game->conf.win_w, sizeof(t_wall));
	i = 0;
	while (i < game->conf.win_w)
	{
		wdist = cast_single_ray(i, game, game->conf.win_w);
		wdist *= cos(game->player.th - game->player.ray_th);
		game->wall[i].dist = wdist;
		draw_one_vert_line(i, wdist, game);
		i++;
	}
	ready_to_draw_sprite(game);
	if (game->save_flag && ft_strncmp(game->save_flag, "--save", 7) == 0)
	{
		save_bmp_file(game);
		exit (1);
	}
	free(game->wall);
	free(game->spr_in_fov);
	mlx_put_image_to_window(game->mlx, game->win, game->img1.img, 0, 0);
	return (0);
}
