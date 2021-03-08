/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:01:29 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/08 23:04:01 by hyunjuyo         ###   ########.fr       */
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
		game->player.th -= ROT_SPEED;
	else if (keycode == KEY_D)
		game->player.th += ROT_SPEED;
	else if (keycode == KEY_ESC)
		exit(0);
	if (game->player.th > 360.0)
		game->player.th -= 360.0;
	if (game->player.th < 0.0)
		game->player.th += 360.0;
	printf("(%f, %f) %f deg\n", game->player.x, game->player.y,
			game->player.th);
	return (0);
}
