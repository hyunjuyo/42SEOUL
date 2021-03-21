/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_draw_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:38:37 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/21 14:37:56 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_one_sprite_info(t_game *game, int i, char spr_type,  int x, int y)
{
	char	*spr_path;
	double	delta_x;
	double	delta_y;

	if (spr_type == '2')
		spr_path = game->conf.sprite[0];
	else
		spr_path = game->conf.sprite[1];
	if (!(game->spr[i].img = mlx_xpm_file_to_image(game->mlx, spr_path,
					&game->spr[i].width, &game->spr[i].height)))
		printf("[sprite]mlx_xpm_file_to_image() failed\nError\n");
	game->spr[i].data = (int *)mlx_get_data_addr(game->spr[i].img,
			&game->spr[i].bpp, &game->spr[i].size_l, &game->spr[i].endian);
	game->spr[i].x = (double)x + 0.5;
	game->spr[i].y = (double)y + 0.5;
	delta_x = game->spr[i].x - game->player.x;
	delta_y = game->spr[i].y - game->player.y;
	game->spr[i].th = atan2(delta_y, delta_x);
	game->spr[i].dist = get_dist(game->player.x, game->player.y,
			game->spr[i].x, game->spr[i].y);
}

void	sort_sprites(t_game *game, int cnt)
{
	int			i;
	int			next;
	t_sprite	temp;

	i = 0;
	while (i < cnt - 1)
	{
		next = 1;
		while (i + next < cnt)
		{
			if (game->spr[i].dist < game->spr[i + next].dist)
			{
				ft_memcpy(&temp, &game->spr[i], sizeof(t_sprite));
				ft_memcpy(&game->spr[i], &game->spr[i + 1], sizeof(t_sprite));
				ft_memcpy(&game->spr[i + 1], &temp, sizeof(t_sprite));
			}
		next++;
		}
		i++;
	}
}

void	draw_sprites_in_order(t_game *game, cnt)
{
	int		i;
	int		spot;
	int		length;
	double	fov_h;
	int		j;

	fov_h = deg_to_rad(FOV, 0);
	i = 0;
	while (i < cnt)
	{
		length = get_vert_line_length(game->spr[i].dist);
		spot = (((game->player.th + fov_h / 2) - game->spr[i].th) / fov_h)
			* game->conf.win_w;
		j = 0;
		while (j < game->conf.win_w)
		{
			if (j >= spot - length / 2 && j < spot - length / 2 + length)
				draw_one_vert_sprite_line(game, i, j, length);
			j++;
		}
		i++;
	}
}

void	ready_to_draw_sprite(t_game *game)
{
	int		i;
	int		x;
	int		y;
	char	spr_type;

	i = 0;
	y = -1;
	while (++y < game->conf.map_y)
	{
		x = -1;
		while (++x < game->conf.map_x)
		{
			spr_type = game->spr_in_fov[x][y];
			if (spr_type == '2' || spr_type == '3')
			{
				store_one_sprite_info(game, i, spr_type, x, y);
				i++;
			}
		}
	}
	sort_sprites(game, cnt);
	draw_sprites_in_order(game, i);



}


void	check_sprite_in_fov(t_game *game)
{
		if (game->map[check.mapx][check.mapy] == '2')
			game->spr_in_fov[check.mapx][check.mapy] == '2';
		else if (game->map[check.mapx][check.mapy] == '3')
			game->spr_in_fov[check.mapx][check.mapy] == '3';
}
