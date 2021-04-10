/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:21:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/04/10 11:41:51 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_conf_info(char *line, t_game *game)
{
	char	*l_ptr;
	char	*w_ptr;
	char	*temp_ptr;

	if (game->conf.map_lines > 0)
	{
		save_map_info(line, game);
		return ;
	}
	l_ptr = ft_strtrim(line, " ");
	temp_ptr = l_ptr;
	if (ft_strlen(l_ptr) == 0)
	{
		free(temp_ptr);
		return ;
	}
	w_ptr = get_next_word(&l_ptr);
	check_conf_type_1(line, game, l_ptr, w_ptr);
	free(temp_ptr);
}

void	map_file_open_n_read(int *fd, char *map_file, t_game *game)
{
	char	*line;

	if ((*fd = open(map_file, O_RDONLY)) == -1)
	{
		printf("Error\n[map]open() failed\n");
		exit(1);
	}
	game->conf.ceil = -1;
	game->conf.floor = -1;
	while (get_next_line(*fd, &line) == 1)
	{
		save_conf_info(line, game);
		free(line);
	}
	if (ft_strlen(line) != 0)
	{
		save_conf_info(line, game);
		free(line);
	}
	else
		free(line);
}

void	store_rotated_map(t_game *game)
{
	int	i;
	int	j;
	int	rev_j;

	ft_memset(game->map, 0, MAPX_MAX * MAPY_MAX);
	i = -1;
	while (++i < game->conf.map_x)
	{
		j = -1;
		while (++j < game->conf.map_y)
		{
			rev_j = game->conf.map_y - 1 - j;
			if (i >= (int)ft_strlen(game->conf.temp_map_addr[rev_j]))
				continue;
			game->map[i][j] = game->conf.temp_map_addr[rev_j][i];
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
					|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
				save_player_info(game, i, j, game->map[i][j]);
		}
	}
	i = -1;
	while (++i < game->conf.map_y)
		free(game->conf.temp_map_addr[i]);
}

void	map_parsing(char *map_file, t_game *game)
{
	int			fd;
	double		temp_x;
	double		temp_y;
	double		temp_th;

	map_file_open_n_read(&fd, map_file, game);
	store_rotated_map(game);
	if (game->player.x == 0.0 || game->player.y == 0.0)
	{
		printf("Error\nMap parsing failed : no player's start position\n");
		exit(1);
	}
	temp_x = game->player.x;
	temp_y = game->player.y;
	temp_th = game->player.th;
	map_parsing_wall_check(game);
	game->player.x = temp_x;
	game->player.y = temp_y;
	game->player.th = temp_th;
	close(fd);
}
