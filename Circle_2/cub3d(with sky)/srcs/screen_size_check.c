/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_size_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:28:58 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/29 22:14:25 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx_mms/mlx.h"
#include "cub3d.h"

void	screen_size_check(t_game *game)
{
	mlx_get_screen_size(game->mlx, &game->conf.display_w,
			&game->conf.display_h);
}
