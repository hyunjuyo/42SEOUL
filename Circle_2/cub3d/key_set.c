/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:01:29 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/09 16:57:00 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_set(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.y += MOVE_SPEED;
	else if (keycode == KEY_S)
		game->player.y -= MOVE_SPEED;
	else if (keycode == KEY_A)
		game->player.x -= MOVE_SPEED;
	else if (keycode == KEY_D)
		game->player.x += MOVE_SPEED;
	else if (keycode == KEY_LEFT)
		game->player.th += ROT_SPEED_RAD;
	else if (keycode == KEY_RIGHT)
		game->player.th -= ROT_SPEED_RAD;
	else if (keycode == KEY_ESC)
		exit(0);
	if (game->player.th > M_PI * 2)
		game->player.th -= M_PI * 2;
	if (game->player.th < 0.0)
		game->player.th += M_PI * 2;
	printf("(%f, %f) %f deg\n", game->player.x, game->player.y,
			rad_to_deg(game->player.th));
	return (0);
}
