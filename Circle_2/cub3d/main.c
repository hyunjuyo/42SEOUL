/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:42:10 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/02 18:19:55 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_set(t_game *game)
{
	int	map[M_ROW][M_COL] = {
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 1, 1, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1}
	};
	ft_memcpy(game->map, map, sizeof(int) * M_ROW * M_COL);
}

void	image_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, MAP_W, MAP_H);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.size_l, &game->img.endian);
}

int		main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIN_W, WIN_H, "cub3d 1st");
	map_set(&game);
	image_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, key_set, &game);
	mlx_loop_hook(game.mlx, draw_minimap, &game);
	mlx_loop(game.mlx);
	return (0);
}
