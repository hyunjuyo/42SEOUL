/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:01:29 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/05 13:28:15 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_set2(int keycode, t_game *game)
{
	if (keycode == KEY_SHIFT && game->player.view_h != 0.0)
		game->player.view_h = 0.0;
	return (0);
}
