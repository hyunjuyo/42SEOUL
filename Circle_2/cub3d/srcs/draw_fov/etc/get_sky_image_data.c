/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sky_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:52:54 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/05 13:34:52 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_sky_color(t_game *game, int h, int w)
{
	int	color;
	int	x;
	int	y;
	int	th_x;
	int	img_w;

	img_w = game->c_img.width / 6;
	th_x = ((0.0 - game->player.th) / deg_to_rad(FOV, 0)) * img_w;
	x = ((double)w / (double)game->conf.win_w) * img_w + th_x;
	y = ((double)h / (double)(game->conf.win_h / 2)) * game->c_img.height;
	if (x > game->c_img.width)
		x -= game->c_img.width;
	if (x < 0)
		x += game->c_img.width;
	color = game->c_img.data[y * game->c_img.width + x];
	return (color);
}

void	get_sky_image_data(t_game *game)
{
	if (!(game->c_img.img = mlx_xpm_file_to_image(game->mlx,
			"./textures/sky.xpm", &game->c_img.width, &game->c_img.height)))
	{
		printf("Error\n[sky]mlx_xpm_file_to_image() failed\n");
		system("killall afplay");
		exit(1)
	}
	game->c_img.data = (int *)mlx_get_data_addr(game->c_img.img,
			&game->c_img.bpp, &game->c_img.size_l, &game->c_img.endian);
}
