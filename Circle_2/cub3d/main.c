/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:42:10 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/11 16:16:22 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_set(t_game *game)
{
	int	map[MAP_X][MAP_Y] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	ft_memcpy(game->map, map, sizeof(int) * MAP_X * MAP_Y);
}

void	map_parsing(char *map_file)
{
	int		fd;
	char	*line;
	int		i;

	if ((fd = open(map_file, O_RDONLY)) == -1)
	{
		printf("open() failed\n");
		printf("Error\n");
		exit(1);
	}
	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		save_map_info(line);
		free(line);
	}
}

void	game_init(t_game *game)
{
	game->img1.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->img1.data = (int *)mlx_get_data_addr(game->img1.img, &game->img1.bpp,
			&game->img1.size_l, &game->img1.endian);
	game->img2.img = mlx_new_image(game->mlx, MAP_X * CUBE_SIZE,
			MAP_Y * CUBE_SIZE);
	game->img2.data = (int *)mlx_get_data_addr(game->img2.img, &game->img2.bpp,
			&game->img2.size_l, &game->img2.endian);
	game->player.x = 1.5;
	game->player.y = 1.5;
	game->player.th = deg_to_rad(90.0, 1);
}

int		main(int argc, char *argv[])
{
	t_game	game;
	char	*map_file;

	map_file = argv[1];
//	map_parsing(map_file);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_W, WIN_H, "cub3d 1st");
	map_set(&game);
	game_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, key_set, &game);
	mlx_loop_hook(game.mlx, draw_player_fov, &game);
//	mlx_loop_hook(game.mlx, draw_minimap, &game);
	mlx_loop(game.mlx);
	return (0);
}
