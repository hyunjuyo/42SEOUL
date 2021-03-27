/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:42:10 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/27 18:50:49 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_game *game)
{
	game->img1.img = mlx_new_image(game->mlx, game->conf.win_w, game->conf.win_h);
	game->img1.data = (int *)mlx_get_data_addr(game->img1.img, &game->img1.bpp,
			&game->img1.size_l, &game->img1.endian);
	game->img2.img = mlx_new_image(game->mlx, MAP_X * CUBE_SIZE,
			MAP_Y * CUBE_SIZE);
	game->img2.data = (int *)mlx_get_data_addr(game->img2.img, &game->img2.bpp,
			&game->img2.size_l, &game->img2.endian);
//	game->player.x = 1.5;
//	game->player.y = 1.5;
//	game->player.th = deg_to_rad(90.0, 1);
}

int		main(int argc, char *argv[])
{
	t_game	game;
	char	*map_file;
	int		a;

	a = argc;
	map_file = argv[1];
	ft_memset(&game.conf, 0, sizeof(t_conf));
	screen_size_check(&game);
	printf("display R : %d %d\n", game.conf.display_w, game.conf.display_h); // test
	map_parsing(map_file, &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.conf.win_w, game.conf.win_h,
			"Cub3D 1st");
	game_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, key_set, &game);
	mlx_loop_hook(game.mlx, draw_player_fov, &game);
//	mlx_loop_hook(game.mlx, draw_minimap, &game);
	mlx_loop(game.mlx);
	return (0);
}
