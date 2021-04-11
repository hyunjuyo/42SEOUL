/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_wall_check_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:56:58 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/11 16:25:22 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	forward_one_step(t_game *game)
{
	game->player.x += 1.0 * cos(game->player.th);
	game->player.y += 1.0 * sin(game->player.th);
}

void	back_one_step_n_rotate(t_game *game)
{
	game->player.x -= 1.0 * cos(game->player.th);
	game->player.y -= 1.0 * sin(game->player.th);
	game->player.th -= deg_to_rad(90.0, 0);
	if (game->player.th < 0)
		game->player.th += M_PI * 2;
}

void	go_start_point(t_game *game, double deg_th)
{
	game->player.x = floor(game->player.x);
	game->player.y = floor(game->player.y);
	game->player.th = deg_to_rad(deg_th, 0);
	while (hit_wall_check(game, 0) != 1)
	{
		forward_one_step(game);
		if (hit_wall_check(game, 0) != 1 && !(game->player.x >= 1.0
			&& game->player.y >= 1.0 && game->player.x < game->conf.map_x
			&& game->player.y < game->conf.map_y))
		{
			printf("Error\n");
			printf("Map parsing failed : The map must be closed by walls\n");
			exit(1);
		}
	}
	back_one_step_n_rotate(game);
}

void	left_side_wall_checking(t_game *game, t_pla *start_point)
{
	while (game->player.x > 0 && game->player.y > 0 && game->player.x
			< game->conf.map_x && game->player.y < game->conf.map_y)
	{
		game->player.th += deg_to_rad(90.0, 0);
		forward_one_step(game);
		if (hit_wall_check(game, 0) == 1)
			back_one_step_n_rotate(game);
		forward_one_step(game);
		if (hit_wall_check(game, 0) == 1)
			back_one_step_n_rotate(game);
		game->player.th += deg_to_rad(90.0, 0);
		forward_one_step(game);
		if (hit_wall_check(game, 0) == 1)
			back_one_step_n_rotate(game);
		if (game->map_check != 0 && fabs(game->player.x - start_point->x) <
				EPSILON && fabs(game->player.y - start_point->y) < EPSILON)
			break ;
		game->map_check++;
	}
	if (!(game->player.x > 0 && game->player.y > 0 && game->player.x
				< game->conf.map_x && game->player.y < game->conf.map_y))
	{
		printf("Error\nMap parsing failed : The map must be closed by walls\n");
		exit(1);
	}
}

void	map_parsing_wall_check(t_game *game)
{
	t_pla	start_point;
	double	temp_x;
	double	temp_y;

	temp_x = game->player.x;
	temp_y = game->player.y;
	go_start_point(game, 90.0);
	game->player.x = temp_x;
	game->player.y = temp_y;
	go_start_point(game, 0.0);
	game->player.x = temp_x;
	game->player.y = temp_y;
	go_start_point(game, 270.0);
	game->player.x = temp_x;
	game->player.y = temp_y;
	go_start_point(game, 180.0);
	start_point.x = game->player.x;
	start_point.y = game->player.y;
	game->map_check = 0;
	left_side_wall_checking(game, &start_point);
}
