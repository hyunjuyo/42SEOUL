/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:42:10 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/04 16:31:50 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->conf.win_w, game->conf.win_h,
			"Cub3D 1st");
	game->img1.img = mlx_new_image(game->mlx, game->conf.win_w,
			game->conf.win_h);
	game->img1.data = (int *)mlx_get_data_addr(game->img1.img, &game->img1.bpp,
			&game->img1.size_l, &game->img1.endian);
	if (game->conf.win_w < 50 || game->conf.win_h < 50)
	{
		printf("Error\nwin_size is too small\n");
		exit(1);
	}
}

int		main(int argc, char *argv[])
{
	t_game	game;
	char	*map_file;

	if (argc < 2 || argc > 3)
	{
		printf("Error\ninvalid argc value : argc value is %d\n", argc);
		exit(1);
	}
	game.save_flag = argv[2];
	map_file = argv[1];
	ft_memset(&game.conf, 0, sizeof(t_conf));
	screen_size_check(&game);
	printf("display R : %d %d\n", game.conf.display_w, game.conf.display_h); // test
	ft_memset(&game.player, 0, sizeof(t_pla));
	map_parsing(map_file, &game);
	game_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L << 0, key_set, &game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 1L << 1, key_set2, &game);
	mlx_hook(game.win, X_EVENT_EXIT, 0, exit_game, &game);
	mlx_loop_hook(game.mlx, draw_player_fov, &game);
	mlx_loop(game.mlx);
	return (0);
}
