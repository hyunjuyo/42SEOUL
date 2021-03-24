/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuyo <hyunjuyo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:21:32 by hyunjuyo          #+#    #+#             */
/*   Updated: 2021/03/21 14:55:40 by hyunjuyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_conf_info(char *line, t_game *game)
{
	char	*l_ptr;
	char	*w_ptr;
    char    *temp;

	if (game->conf.map_lines > 0) // if map starts
    {
		save_map_info(line, game);
        return ;
    }
	l_ptr = ft_strtrim(line, " ");
    temp = l_ptr;
	if (ft_strlen(l_ptr) == 0)
	{
		free(temp);
		return ;
	}
	w_ptr = get_next_word(&l_ptr);
	check_conf_type_1(line, game, l_ptr, w_ptr);
	printf("conf.win_w : %d\n", game->conf.win_w); // test
	printf("conf.win_h : %d\n", game->conf.win_h); // test
	printf("conf.wall_no : %s\n", game->conf.wall_no); // test
	printf("conf.wall_so : %s\n", game->conf.wall_so); // test
	printf("conf.wall_we : %s\n", game->conf.wall_we); // test
	printf("conf.wall_ea : %s\n", game->conf.wall_ea); // test
	printf("conf.sprite1 : %s\n", game->conf.sprite[0]); // test
	printf("conf.sprite2 : %s\n", game->conf.sprite[1]); // test
	printf("conf.chk_complete : %d\n", game->conf.chk_complete); // test
	printf("conf.map_lines : %d\n", game->conf.map_lines); // test
	free(temp);
}

void	fill_with_spaces(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	while (i < game->conf.map_y)
	{
		len = ft_strlen(game->conf.temp_map_addr[i]);
		if (len < game->conf.map_x)
		{
			while (len < game->conf.map_x)
			{
				game->conf.temp_map_addr[i][len] = ' ';
				len++;
			}
			game->conf.temp_map_addr[i][len] = '\0';
		}
		i++;
	}
}

void	map_file_open_n_read(char *map_file, t_game *game)
{
	int	i;
	
	if ((fd = open(map_file, O_RDONLY)) == -1)
	{
		printf("open() failed\nError\n");
		exit(1);
	}
	ft_memset(&game->conf, 0, sizeof(t_conf));
	game->conf.ceil = -1;
	game->conf.floor = -1;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		printf("line : %s\n", line); // test
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
	fill_with_spaces(game);
}

void	store_rotated_map(t_game *game, t_pla *temp)
{
	int	i;
	int	j;

	ft_memset(game->map, 0, sizeof(char) * MAPX_MAX * MAPY_MAX);
	ft_memset(&game->player, -1, sizeof(t_pla));
	i = 0;
	while (i < game->conf.map_x)     // need to check NULL at the last index
	{
		j = 0;
		while (j < game->conf.map_y)     // need to check NULL at the last index
		{
			game->map[i][j]
				= game->conf.temp_map_addr[game->conf.map_y - 1 - j][i];
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
					|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
				save_player_info(game, temp, i, j, game->map[i][j]);
			j++;
		}
		i++;
	}
	i = -1; // test
	while (++i < game->conf.map_x) // test
		printf("%s\n", game->map[i]); // test
	i = -1;
	while (++i < game->conf.map_y)
		free(game->conf.temp_map_addr[i]);
}

void	map_parsing(char *map_file, t_game *game)
{
	int		fd;
	char	*line;
	t_pla	temp;
	t_pla	start;
	int		i;
//	char	test[MAPX_MAX][MAPY_MAX];

	map_file_open_n_read(map_file, game);
	store_rotated_map(game, &temp);
	game->player.th = deg_to_rad(180.0, 0);
	while (hit_wall_check(game, 0) != 1)
	{
		game->player.x += 1.0 * cos(game->player.th);
		game->player.y += 1.0 * sin(game->player.th);
		if (!(game->player.x >= 1.0 && game->player.y >= 1.0 && game->player.x <= game->conf.mapx - 1.0 && game->player.y <= game->conf.mapy - 1.0))
		{
			printf("Map parsing failed : The map must be closed\nError\n");
			exit(1);
		}
	}
	game->player.x -= 1.0 * cos(game->player.th);
	game->player.y -= 1.0 * sin(game->player.th);
	start.x = game->player.x;
	start.y = game->player.y;
	game->player.th -= deg_to_rad(90.0, 0)
	while (game->player.x >= 1.0 && game->player.y >= 1.0 && game->player.x <= game->conf.mapx - 1.0 && game->player.y <= game->conf.mapy - 1.0)
	{
		game->player.th += deg_to_rad(90.0, 0)
		game->player.x += 1.0 * cos(game->player.th);
		game->player.y += 1.0 * sin(game->player.th);
		if (hit_wall_check(game, 0) == 1)
		{
			game->player.x -= 1.0 * cos(game->player.th);
			game->player.y -= 1.0 * sin(game->player.th);
			game->player.th -= deg_to_rad(90.0, 0);
		}
		game->player.x += 1.0 * cos(game->player.th);
		game->player.y += 1.0 * sin(game->player.th);
		if (hit_wall_check(game, 0) == 1)
		{
			game->player.x -= 1.0 * cos(game->player.th);
			game->player.y -= 1.0 * sin(game->player.th);
			game->player.th -= deg_to_rad(90.0, 0);
		}
		game->player.th += deg_to_rad(90.0, 0)
		game->player.x += 1.0 * cos(game->player.th);
		game->player.y += 1.0 * sin(game->player.th);
		if (hit_wall_check(game, 0) == 1)
		{
			game->player.x -= 1.0 * cos(game->player.th);
			game->player.y -= 1.0 * sin(game->player.th);
			game->player.th -= deg_to_rad(90.0, 0);
		}
		if (game->player.x == start.x && game->player.y == start.y)
			break ;
	}
	if (!(game->player.x >= 1.0 && game->player.y >= 1.0 && game->player.x <= game->conf.mapx - 1.0 && game->player.y <= game->conf.mapy - 1.0))
	{
		printf("Map parsing failed : The map must be closed\nError\n");
		exit(1);
	}
	close(fd);
}
