/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:01:29 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/02 17:11:11 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_set(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.y++;
	else if (keycode == KEY_S)
		game->player.y--;
	else if (keycode == KEY_A)
		game->player.x--;
	else if (keycode == KEY_D)
		game->player.x++;
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
