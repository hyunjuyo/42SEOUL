/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_draw_sprite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 11:38:37 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/04 18:43:43 by hyunjuyo         ###   ########.fr       */
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
	else if (spr_type == '3')
		spr_path = game->conf.sprite[1];
	else
		spr_path = game->conf.sprite[2];
	if (!(game->spr[i].img = mlx_xpm_file_to_image(game->mlx, spr_path,
					&game->spr[i].width, &game->spr[i].height)))
		printf("[sprite]mlx_xpm_file_to_image() failed\nError\n");
	game->spr[i].data = (int *)mlx_get_data_addr(game->spr[i].img,
			&game->spr[i].bpp, &game->spr[i].size_l, &game->spr[i].endian);
	game->spr[i].x = (double)x + 0.5;
	game->spr[i].y = (double)y + 0.5;
	delta_x = game->spr[i].x - game->player.x;
	delta_y = game->spr[i].y - game->player.y;
	if ((game->spr[i].th = atan2(delta_y, delta_x)) < 0.0)
		game->spr[i].th += M_PI * 2;
	game->spr[i].dist = get_dist(game->player.x, game->player.y,
			game->spr[i].x, game->spr[i].y);
	game->spr[i].dist *= cos(game->player.th - game->spr[i].th);
}

void	sort_sprites(t_game *game, int cnt)
{
	int			start;
	int			i;
	t_sprite	temp;

	start = 0;
	while (start + 1 < cnt)
	{
		i = 1;
		while (start + i < cnt)
		{
			if (game->spr[start].dist < game->spr[start + i].dist)
			{
				ft_memcpy(&temp, &game->spr[start], sizeof(t_sprite));
				ft_memcpy(&game->spr[start], &game->spr[start + i],
						sizeof(t_sprite));
				ft_memcpy(&game->spr[start + i], &temp, sizeof(t_sprite));
			}
			i++;
		}
		start++;
	}
}

void	draw_sprites_in_order(t_game *game, int cnt)
{
	int		i;
	int		spot;
	double	fov_h;
	double	th;
	int		j;

	fov_h = deg_to_rad(FOV, 0);
	i = -1;
	while (++i < cnt)
	{
		game->spr[i].length = get_vert_line_length(game->spr[i].dist, game);
		if ((th = (game->player.th + fov_h / 2) - game->spr[i].th) < 0.0)
			th += M_PI * 2.0;
		else if (th > M_PI * 2.0)
			th -= M_PI * 2.0;
		spot = (th / fov_h) * game->conf.win_w;
//		printf("game->player.th : %f\n", game->player.th);
//		printf("game->spr[%d].th : %f\n", i, game->spr[i].th);
//		printf("spot : %d, start_spot : %d\n", spot, spot - game->spr[i].length / 2);
		j = -1;
		while (++j < game->conf.win_w && spot > 0 - game->conf.win_w / 2
				&& spot < game->conf.win_w + game->conf.win_w / 2)
		{
			if (j >= spot - game->spr[i].length / 2 && j < spot + game->spr[i].\
					length / 2 && game->spr[i].dist < game->wall[j].dist)
				draw_vert_spr_line(game, i, j, spot - game->spr[i].length / 2);
		}
	}
}

void	ready_to_draw_sprite(t_game *game)
{
	int		i;
	int		x;
	int		y;
	char	spr_type;

	i = 0;
	x = -1;
	while (++x < game->conf.map_x)
	{
		y = -1;
		while (++y < game->conf.map_y)
		{
			spr_type = game->spr_in_fov[x * game->conf.map_y + y];
			if (spr_type == '2' || spr_type == '3' || spr_type == '4')
			{
				store_one_sprite_info(game, i, spr_type, x, y);
//				printf("game->spr[%d] (%f, %f)\n", i, game->spr[i].x, game->spr[i].y);
//				printf("gmae->spr[%d] dist : %f\n", i, game->spr[i].dist);
//				printf("gmae->spr[%d] length : %d\n", i, game->spr[i].length);
				i++;
			}
		}
	}
	sort_sprites(game, i);
	draw_sprites_in_order(game, i);
}


void	check_sprite_in_fov(t_game *game, t_chk_pnt *check)
{
	if (game->map[check->mapx][check->mapy] == '2')
		game->spr_in_fov[check->mapx * game->conf.map_y + check->mapy] = '2';
	else if (game->map[check->mapx][check->mapy] == '3')
		game->spr_in_fov[check->mapx * game->conf.map_y + check->mapy] = '3';
	else if (game->map[check->mapx][check->mapy] == '4')
		game->spr_in_fov[check->mapx * game->conf.map_y + check->mapy] = '4';
}
