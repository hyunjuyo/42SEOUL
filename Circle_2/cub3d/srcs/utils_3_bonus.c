/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:00:53 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/05 17:06:41 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_walking(t_game *game)
{
	if (game->player.walk < 0)
	{
		game->player.walk--;
		game->player.view_h = sin((M_PI / 6) * game->player.walk) * 0.035;
		if (game->player.walk == -6)
		{
			game->player.walk = 0;
			game->player.view_h = 0.0;
		}
	}
	if (game->player.walk >= 0)
	{
		game->player.walk++;
		game->player.view_h = sin((M_PI / 8) * game->player.walk) * 0.025;
		if (game->player.walk == 8)
		{
			game->player.walk = -1;
			game->player.view_h = 0.0;
		}
	}
}

void	player_jumping_check(t_game *game)
{
	if (game->player.jump < 0)
	{
		game->player.jump--;
		game->player.view_h = sin((M_PI / 5) * game->player.jump) * 0.15;
		if (game->player.jump == -5)
		{
			game->player.jump = 0;
			game->player.view_h = 0.0;
		}
	}
	if (game->player.jump >= 3)
	{
		game->player.jump++;
		game->player.view_h = sin((M_PI / 12) * game->player.jump) * 0.45;
		if (game->player.jump == 12)
		{
			game->player.jump = -1;
			game->player.view_h = 0.0;
		}
	}
}
