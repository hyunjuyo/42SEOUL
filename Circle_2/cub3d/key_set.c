/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:01:29 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/03 15:16:17 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_set(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.y += MOVE;
	else if (keycode == KEY_S)
		game->player.y -= MOVE;
	else if (keycode == KEY_A)
		game->player.x -= MOVE;
	else if (keycode == KEY_D)
		game->player.x += MOVE;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("(%f, %f)\n", game->player.x, game->player.y);
	return (0);
}
