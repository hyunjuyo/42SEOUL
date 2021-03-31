/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:24:36 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/31 16:01:06 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		during_down(int i, int line_len, t_game *game)
{
	int	j;

	j = i;
//	if (game->player.jh == 0.0)
//		return (0);
//	else
	{
//		game->player.jh_w = game->player.jh * (10000 - game->wall[i].dist)
//			/ 10000;
		game->player.jh_w = line_len * game->player.view_h;
//		*space = game->conf.win_h - line_len + game->player.jh_w * 2.0;
//		if (*space < 0)
//			*space = 0;
		return ((int)game->player.jh_w);
	}
}

void	do_jump(t_game *game)
{
	double	jump_speed;
	double	jump_height;
	double	i;

	jump_speed = M_PI / (double)50;
	jump_height = 0.45;
	i = 0.0;
	while (i < M_PI)
	{
//		game->player.jh = sin(i) * jump_height * game->conf.win_h;
		printf("game->player.view_h : %f\n", game->player.view_h);
//		draw_player_fov(game);
		i += jump_speed;
	}
	game->player.view_h = 0.0;
}
