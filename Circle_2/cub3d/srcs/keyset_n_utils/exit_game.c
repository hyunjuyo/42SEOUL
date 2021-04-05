/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:21:12 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/04 15:56:33 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	system("killall afplay");
	exit(0);
	return (0);
}
