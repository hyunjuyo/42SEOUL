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

void	save_conf_info(char *line, t_game *game)
{
	int		i;
	char	*l_ptr;
	char	*w_ptr;

	if (game->conf.map_start == TRUE)
		save_map_info(line, game); // need to make~ other info complete check!!
	l_ptr = ft_strtrim(line, " ");
	if (ft_strlen(l_ptr) == 0)
	{
		free(ptr);
		return ;
	}
	w_ptr = get_next_word(l_ptr); // need to make~
	if (ft_strncmp(w_ptr, "R ", 2) == 0)
	{
		game->conf.win_x = ft_atoi(get_next_word(l_ptr));
		game->conf.win_y = ft_atoi(get_next_word(l_ptr));
	}
	else if (ft_strncmp(w_ptr, "NO", 2) == 0)
		game->conf.wall_no = get_next_word(l_ptr);
	else if (ft_strncmp(w_ptr, "SO", 2) == 0)
		game->conf.wall_so = get_next_word(l_ptr);
	else if (ft_strncmp(w_ptr, "WE", 2) == 0)
		game->conf.wall_we = get_next_word(l_ptr);
	else if (ft_strncmp(w_ptr, "EA", 2) == 0)
		game->conf.wall_ea = get_next_word(l_ptr);


	free(w_ptr);
	i = 0;
	while (l_ptr[i] && (l_ptr[i] == '1' || l_ptr[i] == ' '))
		i++;
	if (i == ft_strlen(l_ptr))
		game->conf.map_start = TRUE;
	free(l_ptr);

}

void	map_parsing(char *map_file, t_game *game)
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
	game->conf.map_start = FALSE;
	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		save_conf_info(line, game);
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
//	map_parsing(map_file, &game);
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
