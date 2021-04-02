/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:21:12 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/02 18:06:06 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bgm_control()
{
	exit (0);
}

int		exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
	return (0);
}
