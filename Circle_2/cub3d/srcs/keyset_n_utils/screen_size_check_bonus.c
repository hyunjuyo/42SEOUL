/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_size_check_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:28:58 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/11 16:34:32 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_mms/mlx.h"
#include "cub3d_bonus.h"

void	screen_size_check(t_game *game)
{
	mlx_get_screen_size(game->mlx, &game->conf.display_w,
			&game->conf.display_h);
}
