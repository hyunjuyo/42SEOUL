/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:42:10 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/10 12:46:27 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_set(t_game *game)
{
	int	map[MAP_X][MAP_Y] = {
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1},
		{1, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1}
	};
	ft_memcpy(game->map, map, sizeof(int) * MAP_X * MAP_Y);
}

void	game_init(t_game *game)
{
	game->img2.img = mlx_new_image(game->mlx, MAP_X * CUBE_SIZE,
			MAP_Y * CUBE_SIZE);
	game->img2.data = (int *)mlx_get_data_addr(game->img2.img, &game->img2.bpp,
			&game->img2.size_l, &game->img2.endian);
	game->player.x = 1.5;
	game->player.y = 1.5;
	game->player.th = deg_to_rad(90.0);
}

int		main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_W, WIN_H, "cub3d 1st");
	map_set(&game);
	game_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, key_set, &game);
//	mlx_loop_hook(game.mlx, draw_player_fov, &game);
	mlx_loop_hook(game.mlx, draw_minimap, &game);
	mlx_loop(game.mlx);
	return (0);
}
