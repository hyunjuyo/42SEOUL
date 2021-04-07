/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_item_info_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:59:36 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/05 17:31:41 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		get_gem_color(t_game *game, int gw, int gh, t_img *gem)
{
	int color;
	int x;
	int y;

	x = ((double)gw / (double)(game->conf.win_w / 9)) * gem->width;
	y = ((double)gh / (double)(game->conf.win_h / 15)) * gem->height;
	color = gem->data[y * gem->width + x];
	return (color);
}

void	draw_gem_info_last(t_game *game, t_img *gem)
{
	int w;
	int h;
	int gw;
	int gh;
	int color;

	h = 0;
	while (h < game->conf.win_h)
	{
		w = 0;
		while (w < game->conf.win_w)
		{
			if (h > game->conf.win_h * 1 / 15 && h < game->conf.win_h * 2 / 15
				&& w > game->conf.win_w * 7 / 9 && w < game->conf.win_w * 8 / 9)
			{
				gh = h - game->conf.win_h * 1 / 15;
				gw = w - game->conf.win_w * 7 / 9;
				color = get_gem_color(game, gw, gh, gem);
				if (check_color_area(color, BLUE, 0x87) != 111)
					game->img1.data[h * game->conf.win_w + w] = color;
			}
			w++;
		}
		h++;
	}
}

void	draw_gem_info_more(t_game *game, int info, t_img *gem)
{
	if (info == 2)
	{
		if (!(gem.img = mlx_xpm_file_to_image(game->mlx,
						"./textures/gem_2.xpm", &gem.width, &gem.height)))
		{
			printf("Error\n[gem]mlx_xpm_file_to_image() failed\n");
			system("killall afplay");
			exit(1);
		}
	}
	else if (info == 3)
	{
		if (!(gem->img = mlx_xpm_file_to_image(game->mlx,
						"./textures/gem_3.xpm", &gem->width, &gem->height)))
		{
			printf("Error\n[gem]mlx_xpm_file_to_image() failed\n");
			system("killall afplay");
			exit(1);
		}
	}
	gem->data = (int *)mlx_get_data_addr(gem->img, &gem->bpp, &gem->size_l,
			&gem->endian);
	draw_gem_info_last(game, gem);
}

void	draw_gem_info(t_game *game, int info)
{
	t_img	gem;

	if (info == 0)
	{
		if (!(gem.img = mlx_xpm_file_to_image(game->mlx,
						"./textures/gem_0.xpm", &gem.width, &gem.height)))
		{
			printf("Error\n[gem]mlx_xpm_file_to_image() failed\n");
			system("killall afplay");
			exit(1);
		}
	}
	else if (info == 1)
	{
		if (!(gem.img = mlx_xpm_file_to_image(game->mlx,
						"./textures/gem_1.xpm", &gem.width, &gem.height)))
		{
			printf("Error\n[gem]mlx_xpm_file_to_image() failed\n");
			system("killall afplay");
			exit(1);
		}
	}
	draw_gem_info_more(game, info, &gem);
}

void	check_player_item_info(t_game *game)
{
	if (game->player.item[0] == 1)
		draw_minimap(game);
	if (game->player.item[1] == 0)
		draw_gem_info(game, 0);
	else if (game->player.item[1] == 1)
		draw_gem_info(game, 1);
	else if (game->player.item[1] == 2)
		draw_gem_info(game, 2);
	else
		draw_gem_info(game, 3);
}
