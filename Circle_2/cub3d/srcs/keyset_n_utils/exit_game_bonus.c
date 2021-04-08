/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:21:12 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/08 16:32:56 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	waitpid(game->pid, &game->pid_status, WNOHANG);
	if (game->pid_status == -1)
		system("killall afplay");
	exit(0);
	return (0);
}
