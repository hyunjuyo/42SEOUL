/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_set_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:01:29 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/01 18:20:17 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_check(t_game *game)
{
	if (game->player.th > M_PI * 2)
		game->player.th -= M_PI * 2;
	else if (game->player.th < 0.0)
		game->player.th += M_PI * 2;
	if (game->player.th < 0.000001
			|| game->player.th - M_PI * 1 / 2 < 0.000001
			|| game->player.th - M_PI < 0.000001
			|| game->player.th - M_PI * 3 / 2 < 0.000001)
		game->player.th += 0.000002;
}

int		hit_wall_check(t_game *game, int type)
{
	int	mapx;
	int	mapy;

	mapx = (int)game->player.x;
	mapy = (int)game->player.y;
	if (type == 0 && game->map[mapx][mapy] == '1')
		return (1);
	else if (type == 1 && (game->map[mapx][mapy] == '1'
				|| game->map[mapx][mapy] == '2'))
		return (1);
	return (0);
}

void	key_set_more_and_more(int keycode, t_game *game)
{
	if (keycode == KEY_LEFT)
		game->player.th += ROT_SPEED_RAD;
	else if (keycode == KEY_RIGHT)
		game->player.th -= ROT_SPEED_RAD;
	else if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_SHIFT && game->player.view_h == 0.0)
		game->player.view_h = -0.25;
	else if (keycode == KEY_SHIFT && game->player.view_h != 0.0)
		game->player.view_h = 0.0;
	if (game->player.jump != 0)
	{
		game->player.jump++;
		game->player.view_h = sin((M_PI / 9) * game->player.jump) * 0.3;
		if (game->player.jump == 9)
			game->player.jump = 0;
//		printf("[jump %d] view_h : %f\n", game->player.jump, game->player.view_h);
	}
	else if (keycode == KEY_SPACE)
	{
		game->player.jump = 3;
		game->player.view_h = sin((M_PI / 9) * game->player.jump) * 0.3;
//		printf("[jump %d] view_h : %f\n", game->player.jump, game->player.view_h);
	}
	rotate_check(game);
//	printf("(%f, %f) %f deg\n", game->player.x, game->player.y,
//			rad_to_deg(game->player.th));
}

void	key_set_more(int keycode, t_game *game)
{
	if (keycode == KEY_A)
	{
		game->player.x += MOVE_SPEED * cos(game->player.th + deg_to_rad(90, 0));
		game->player.y += MOVE_SPEED * sin(game->player.th + deg_to_rad(90, 0));
		if (hit_wall_check(game, 1) == 1)
		{
			game->player.x
				-= MOVE_SPEED * cos(game->player.th + deg_to_rad(90, 0));
			game->player.y
				-= MOVE_SPEED * sin(game->player.th + deg_to_rad(90, 0));
		}
	}
	else if (keycode == KEY_D)
	{
		game->player.x += MOVE_SPEED * cos(game->player.th - deg_to_rad(90, 0));
		game->player.y += MOVE_SPEED * sin(game->player.th - deg_to_rad(90, 0));
		if (hit_wall_check(game, 1) == 1)
		{
			game->player.x
				-= MOVE_SPEED * cos(game->player.th - deg_to_rad(90, 0));
			game->player.y
				-= MOVE_SPEED * sin(game->player.th - deg_to_rad(90, 0));
		}
	}
	key_set_more_and_more(keycode, game);
}

int		key_set(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->player.x += MOVE_SPEED * cos(game->player.th);
		game->player.y += MOVE_SPEED * sin(game->player.th);
		if (hit_wall_check(game, 1) == 1)
		{
			game->player.x -= MOVE_SPEED * cos(game->player.th);
			game->player.y -= MOVE_SPEED * sin(game->player.th);
		}
	}
	else if (keycode == KEY_S)
	{
		game->player.x -= MOVE_SPEED * cos(game->player.th);
		game->player.y -= MOVE_SPEED * sin(game->player.th);;
		if (hit_wall_check(game, 1) == 1)
		{
			game->player.x += MOVE_SPEED * cos(game->player.th);
			game->player.y += MOVE_SPEED * sin(game->player.th);;
		}
	}
	key_set_more(keycode, game);
	return (0);
}
