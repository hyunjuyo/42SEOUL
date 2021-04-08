/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_item_info2_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:59:36 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/08 16:34:48 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_gem_info_4(t_game *game, int info, t_img *gem)
{
	if (info == 3)
	{
		if (!(gem->img = mlx_xpm_file_to_image(game->mlx,
						"./textures/gem_3.xpm", &gem->width, &gem->height)))
		{
			printf("Error\n[gem]mlx_xpm_file_to_image() failed\n");
			waitpid(game->pid, &game->pid_status, WNOHANG);
			if (game->pid_status == -1)
				system("killall afplay");
			exit(1);
		}
	}
	gem->data = (int *)mlx_get_data_addr(gem->img, &gem->bpp, &gem->size_l,
			&gem->endian);
	draw_gem_info_last(game, gem);
}

void	draw_gem_info_3(t_game *game, int info, t_img *gem)
{
	if (info == 2)
	{
		if (!(gem->img = mlx_xpm_file_to_image(game->mlx,
						"./textures/gem_2.xpm", &gem->width, &gem->height)))
		{
			printf("Error\n[gem]mlx_xpm_file_to_image() failed\n");
			waitpid(game->pid, &game->pid_status, WNOHANG);
			if (game->pid_status == -1)
				system("killall afplay");
			exit(1);
		}
	}
	draw_gem_info_4(game, info, gem);
}

void	draw_gem_info_2(t_game *game, int info, t_img *gem)
{
	if (info == 1)
	{
		if (!(gem->img = mlx_xpm_file_to_image(game->mlx,
						"./textures/gem_1.xpm", &gem->width, &gem->height)))
		{
			printf("Error\n[gem]mlx_xpm_file_to_image() failed\n");
			waitpid(game->pid, &game->pid_status, WNOHANG);
			if (game->pid_status == -1)
				system("killall afplay");
			exit(1);
		}
	}
	draw_gem_info_3(game, info, gem);
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
			waitpid(game->pid, &game->pid_status, WNOHANG);
			if (game->pid_status == -1)
				system("killall afplay");
			exit(1);
		}
	}
	draw_gem_info_2(game, info, &gem);
}
