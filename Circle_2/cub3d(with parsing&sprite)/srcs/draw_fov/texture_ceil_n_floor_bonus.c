/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ceil_n_floor_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:15:02 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/27 16:48:03 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_min_dist_in_fov(t_game *game)
{
	double	fov_vert;
	double	min_dist;
	double	half_wall_len;

	fov_vert = deg_to_rad(FOV * game->conf.win_h / game->conf.win_w, 0);
	half_wall_len = 0.5;
	min_dist = half_wall_len / tan(fov_vert / 2.0);
	return (min_dist);
}

int		get_ceil_n_floor_texture(int i, double t_dist, t_game *game, char type)
{
	double	tx_ratio;
	double	ty_ratio;
	double	dist_ratio;
	int		tx;
	int		ty;

	dist_ratio = t_dist / game->wall[i].dist;
	tx_ratio = (game->wall[i].x - game->player.x) * dist_ratio + game->player.x;
	tx_ratio -= floor(tx_ratio);
	ty_ratio = (game->wall[i].y - game->player.y) * dist_ratio + game->player.y;
	ty_ratio -= floor(ty_ratio);
	if (type == 'C')
	{
		tx = (int)(game->c_img.width * tx_ratio);
		ty = (int)(game->c_img.height * ty_ratio);
		return (game->c_img.data[ty * game->c_img.width + tx]);
	}
	else
	{
		tx = (int)(game->f_img.width * tx_ratio);
		ty = (int)(game->f_img.height * ty_ratio);
		return (game->f_img.data[ty * game->f_img.width + tx]);
	}
}

void	draw_vert_ceil_n_floor_line(int i, int wall_len, double min_dist, t_game *game)
{
	int		j;
	int		area_len;
	double	h;
	double	t_dist;

	area_len = (game->conf.win_h - wall_len) / 2;
	j = 0;
	while (j < area_len)
	{
		h = (double)j / (double)game->conf.win_h;
		t_dist = min_dist / (1 - 2 * h);
		game->img1.data[j * game->conf.win_w + i]
			= fade_color(get_ceil_n_floor_texture(i, t_dist, game, 'C'), t_dist, game);
		game->img1.data[(game->conf.win_h - 1 - j) * game->conf.win_w + i]
			= fade_color(get_ceil_n_floor_texture(i, t_dist, game, 'F'), t_dist, game);
		j++;
	}
}

void	texture_ceil_n_floor(t_game *game)
{
	int		i;
	int		wall_len;
	double	min_dist;

	if (!(game->c_img.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/ceil.xpm", &game->c_img.width, &game->c_img.height)))
		printf("[ceil]mlx_xpm_file_to_image() failed\nError\n");
	game->c_img.data = (int *)mlx_get_data_addr(game->c_img.img,
			&game->c_img.bpp, &game->c_img.size_l, &game->c_img.endian);
	if (!(game->f_img.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/floor.xpm", &game->f_img.width, &game->f_img.height)))
		printf("[floor]mlx_xpm_file_to_image() failed\nError\n");
	game->f_img.data = (int *)mlx_get_data_addr(game->f_img.img,
			&game->f_img.bpp, &game->f_img.size_l, &game->f_img.endian);
	min_dist = get_min_dist_in_fov(game);
	i = 0;
	while (i < game->conf.win_w)
	{
		wall_len = get_vert_line_length(game->wall[i].dist, game);
		draw_vert_ceil_n_floor_line(i, wall_len, min_dist, game);
		i++;
	}
}
