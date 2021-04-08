/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_draw_sprite_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:17:20 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/08 16:18:43 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_spr_path(t_game *game, char spr_type)
{
	char	*spr_path;

	if (spr_type == '2')
		spr_path = game->conf.sprite[0];
	else if (spr_type == '3')
		spr_path = game->conf.sprite[1];
	else
		spr_path = game->conf.sprite[2];
    return (spr_path);
}
