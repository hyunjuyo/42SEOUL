/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one_vert_sprite_line.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:38:13 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/21 14:49:00 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_sprite_pixel_color()
{




}

void	draw_one_vert_sprite_line(t_game *game, int i, int j, int length)
{
	int	h;
	int	space;

	space = (game->conf.win_h - length) / 2;
	h = 0;
	while (h < length && h < game->conf.win_h)
	{
		game->img1.data[(space + h) * game->conf.win_w + j]
			= get_sprite_pixel_color(h, length, game);
		h++;
	}


}
