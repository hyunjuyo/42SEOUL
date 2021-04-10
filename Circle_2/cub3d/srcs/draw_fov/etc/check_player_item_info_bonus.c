/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_item_info_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:59:36 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/08 16:18:24 by hyunjuyo         ###   ########.fr       */
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

char	*get_ani_img_path(t_game *game)
{
	char	*img_path;
	char	*temp_idx;
	char	*temp_ptr;

	temp_idx = ft_itoa(game->player.get_map);
	temp_ptr = ft_strjoin("./textures/animation/map_ani_", temp_idx);
	free(temp_idx);
	img_path = ft_strjoin(temp_ptr, ".xpm");
	free(temp_ptr);
	return (img_path);
}

void	draw_one_animation_image(t_game *game)
{
	int		i;
	int		j;
	double	w_ratio;
	double	h_ratio;
	int		color;

	w_ratio = (double)game->player.ani.width / (double)game->conf_win_w;
	h_ratio = (double)game->player.ani.height / (double)game->conf.win_h;
	j = 0;
	while (j < game->conf.win_h)
	{
		i = 0;
		while (i < game->conf.win_w)
		{
			color = game->player.ani.data[j * h_ratio * game->player.ani.width
				+ i * w_ratio];
			if (check_color_area(color, BLUE, 0x87) != 111)
				game->img1.data[j * game->conf.win_w + i] = color;
			i++;
		}
		j++;
	}
}

void	item_animation(t_game *game)
{
	char	*img_path;

	img_path = get_ani_img_path(game);
	if (!(game->player.ani.img = mlx_xpm_file_to_image(game->mlx, img_path,
			&game->player.ani.width, &game->player.ani.height)))
	{
		printf("Error\n[map_ani]mlx_xpm_file_to_image() failed\n");
		waitid(game->pid, &game->pid_status, WNOHANG);
		if (game->pid_status == -1)
			system("killall afplay");
		exit(1);
	}
	game->player.ani.data = (int *)mlx_get_data_addr(game->player.ani.img,
			&game->player.ani.bpp, &game->player.ani.size_l,
			&game->player.ani.endian);
	draw_one_animation_image(game);
	game->player.get_map++;
	if (game->player.get_map == 28)
	{
		game->player.get_map = 0;
		game->player.item[0] = 1;
	}
}

void	check_player_item_info(t_game *game)
{
	if (game->player.get_map > 0)
		item_animation(game);
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
